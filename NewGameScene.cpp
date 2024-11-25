#include "NewGameScene.h"
#include "CharactersScene.h"

using namespace std;
USING_NS_CC;

Scene* NewGame::createScene()
{
    auto scene = NewGame::create();
    return scene;
}                                   

bool NewGame::init()
{
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // Obtener el �ndice del personaje seleccionado
    int selectedCharacterIndex = UserDefault::getInstance()->getIntegerForKey("SelectedCharacterIndex", 0);

    // Mapear los sprites seg�n el personaje seleccionado
    vector<string> characterSprites;
    float runAnimationSpeed = 0.1f; // Velocidad de animaci�n para correr
    float jumpAnimationSpeed = 0.2f; // Velocidad de animaci�n para saltar
    float characterScale = 1.0f; // Escala por defecto

    switch (selectedCharacterIndex)
    {
    case 0:
        characterSprites = { "1-RallyRun.png", "2-RallyRun.png", "3-RallyRun.png", "4-RallyRun.png", "5-RallyRun.png",
                             "6-RallyRun.png", "7-RallyRun.png", "8-RallyRun.png", "1-RallyJump.png", "2-RallyJump.png",
                             "3-RallyJump.png", "4-RallyJump.png", "5-RallyJump.png", "6-RallyJump.png", "7-RallyJump.png",
                             "8-RallyJump.png" };
        runAnimationSpeed = 0.15f;
        jumpAnimationSpeed = 0.15f;
        characterScale = 3.5f;
        break;
    default:
        characterSprites = { "1-DonkeyRun.png" };
        runAnimationSpeed = 0.1f;
        jumpAnimationSpeed = 0.2f;
        characterScale = 3.0f;
    }

    // Crear el sprite animado
    auto animatedSprite = Sprite::create(characterSprites[0]);
    animatedSprite->setPosition(Point(visibleSize.width / 11, visibleSize.height / 2 + 45));
    animatedSprite->setScale(characterScale); // Asignar tama�o �nico
    this->addChild(animatedSprite);

    // Listener para teclas
    auto eventListener = EventListenerKeyboard::create();
    eventListener->onKeyPressed = [animatedSprite, characterSprites, runAnimationSpeed, jumpAnimationSpeed](EventKeyboard::KeyCode keyCode, Event* event) {
        if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) // Solo correr
        {
            // Iniciar animaci�n de correr si no est� ya corriendo
            if (!animatedSprite->getActionByTag(1))
            {
                Vector<SpriteFrame*> runFrames;
                for (int i = 0; i < 8; i++) {
                    auto texture = Director::getInstance()->getTextureCache()->addImage(characterSprites[i]);
                    if (texture)
                    {
                        auto frame = SpriteFrame::createWithTexture(texture, Rect(0, 0, texture->getContentSize().width, texture->getContentSize().height));
                        runFrames.pushBack(frame);
                    }
                }
                auto runAnimation = Animation::createWithSpriteFrames(runFrames, runAnimationSpeed);
                auto runAnimate = Animate::create(runAnimation);
                auto runForever = RepeatForever::create(runAnimate);
                runForever->setTag(1); // Etiqueta para identificar la acci�n
                animatedSprite->runAction(runForever);
            }

            // Movimiento hacia adelante
            if (!animatedSprite->getActionByTag(2))
            {
                auto moveRight = MoveBy::create(0.1f, Vec2(10, 0)); // Movimiento hacia adelante
                auto moveForever = RepeatForever::create(moveRight);
                moveForever->setTag(2);
                animatedSprite->runAction(moveForever);
            }
        }
        else if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW) // Correr y saltar
        {
            // Iniciar animaci�n de salto si no est� ya saltando
            if (!animatedSprite->getActionByTag(3))
            {
                Vector<SpriteFrame*> jumpFrames;
                for (int i = 8; i < 16; i++) {
                    auto texture = Director::getInstance()->getTextureCache()->addImage(characterSprites[i]);
                    if (texture)
                    {
                        auto frame = SpriteFrame::createWithTexture(texture, Rect(0, 0, texture->getContentSize().width, texture->getContentSize().height));
                        jumpFrames.pushBack(frame);
                    }
                }
                auto jumpAnimation = Animation::createWithSpriteFrames(jumpFrames, jumpAnimationSpeed);
                auto jumpAnimate = Animate::create(jumpAnimation);
                auto jumpForever = RepeatForever::create(jumpAnimate); // Repetir la animaci�n de salto infinitamente
                jumpForever->setTag(3); // Etiqueta para detenerla m�s tarde
                animatedSprite->runAction(jumpForever);
            }

            // Movimiento hacia arriba y hacia abajo para el salto
            if (!animatedSprite->getActionByTag(4))
            {
                auto jumpUp = MoveBy::create(0.2f, Vec2(0, 100)); // Saltar hacia arriba
                auto jumpDown = MoveBy::create(0.2f, Vec2(0, -100)); // Regresar al suelo
                auto jumpSequence = Sequence::create(jumpUp, jumpDown, nullptr);
                auto jumpForever = RepeatForever::create(jumpSequence); // Repetir el salto indefinidamente
                jumpForever->setTag(4); // Etiqueta para detener el salto
                animatedSprite->runAction(jumpForever);
            }

            // Movimiento hacia adelante mientras salta
            if (!animatedSprite->getActionByTag(2))
            {
                auto moveRight = MoveBy::create(0.1f, Vec2(10, 0)); // Movimiento hacia adelante
                auto moveForever = RepeatForever::create(moveRight);
                moveForever->setTag(2);
                animatedSprite->runAction(moveForever);
            }
        }
        };

    eventListener->onKeyReleased = [animatedSprite](EventKeyboard::KeyCode keyCode, Event* event) {
        if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) // Detener animaci�n de correr
        {
            animatedSprite->stopActionByTag(1); // Detener animaci�n de correr
            animatedSprite->stopActionByTag(2); // Detener movimiento
        }
        else if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW) // Detener animaci�n de salto
        {
            animatedSprite->stopActionByTag(3); // Detener animaci�n de salto
            animatedSprite->stopActionByTag(4); // Detener movimiento de salto
            animatedSprite->stopActionByTag(2); // Detener movimiento hacia adelante (opcional)
        }
        };

    // Registrar el listener de eventos
    _eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, this);

    return true;
}
