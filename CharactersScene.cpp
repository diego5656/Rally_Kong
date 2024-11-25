#include "CharactersScene.h"
#include "NewGameScene.h"
#include "HelloWorldScene.h"

USING_NS_CC;

Scene* Characters::createScene()
{
    auto scene = Characters::create();
    return scene;
}

bool Characters::init()
{
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto titleLabel = Label::createWithSystemFont("Characters Menu", "Arial", 20);
    titleLabel->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2 + 150));
    this->addChild(titleLabel, 1);

    auto backButton = MenuItemImage::create("Back.png", "Back.png", CC_CALLBACK_1(Characters::onBack, this));
    backButton->setPosition(Point(visibleSize.width / 13, visibleSize.height / 6.3));
    backButton->setScale(0.9);

    auto exitButton = MenuItemImage::create("Exit.png", "Exit.png", CC_CALLBACK_1(Characters::onExit, this));
    exitButton->setPosition(Point(visibleSize.width / 1.12, visibleSize.height / 6.3));
    exitButton->setScale(1.1);

    // Configurar las flechas de navegación
    auto backArrowButton = MenuItemImage::create("BackArrow.png", "BackArrow.png", CC_CALLBACK_1(Characters::onBackArrow, this));
    backArrowButton->setPosition(Point(visibleSize.width / 19, visibleSize.height / 2 + 40));
    backArrowButton->setScale(0.3);

    auto nextArrowButton = MenuItemImage::create("NextArrow.png", "NextArrow.png", CC_CALLBACK_1(Characters::onNextArrow, this));
    nextArrowButton->setPosition(Point(visibleSize.width / 1.065, visibleSize.height / 2 + 40));
    nextArrowButton->setScale(0.3);

    auto menu = Menu::create(backButton, exitButton, nextArrowButton, backArrowButton, nullptr);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    // Inicializar el vector de imágenes de personajes 
    images = { "Rally Kong - Personaje.png", "Kiddy Kong.png", "Diddy Kong.png", "Cranky Kong.png", "Donkey Kong.png", "Dixie Kong.png" };
    currentImageIndex = 0;

    // Llamar a updateImage() para cargar la primera imagen
    updateImage();

    return true;
}

void Characters::onBack(Ref* sender)
{
    auto helloWorldScene = HelloWorld::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(1, helloWorldScene));
}

void Characters::onNext(Ref* sender)
{
    auto newGameScene = NewGame::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(1, newGameScene));
}                                     

void Characters::onExit(Ref* sender)
{
    Director::getInstance()->end();
}

void Characters::onBackArrow(Ref* sender)
{
    // Verifica si es la primera imagen
    if (currentImageIndex > 0)
    {
        currentImageIndex--;  // Decrementa el índice para la imagen anterior
    }
    else
    {
        currentImageIndex = images.size() - 1;  // Si estamos en la primera imagen, volvemos a la última
    }
    updateImage();  // Actualizar la imagen mostrada
}


void Characters::onNextArrow(Ref* sender)
{
    // Verifica si es la última imagen
    if (currentImageIndex < images.size() - 1)
    {
        currentImageIndex++;  // Aumenta el índice para la siguiente imagen
    }
    else
    {
        currentImageIndex = 0;  // Si estamos en la última imagen, volvemos a la primera
    }
    updateImage();  // Actualizar la imagen mostrada
}


void Characters::updateImage()
{
    // Eliminar la imagen anterior si existe
    if (imageSprite != nullptr)
    {
        imageSprite->removeFromParent();
    }

    // Crear y mostrar la nueva imagen
    imageSprite = Sprite::create(images[currentImageIndex]);

    // Verificar que la imagen se haya cargado correctamente antes de agregarla
    if (imageSprite != nullptr)
    {
        imageSprite->setPosition(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 2 + 40);
        imageSprite->setScale(1.5);
        this->addChild(imageSprite);

        // Agregar un EventListener para la imagen
        auto touchListener = EventListenerTouchOneByOne::create();
        touchListener->onTouchBegan = [=](Touch* touch, Event* event) {
            // Obtener el área de la imagen
            auto bounds = imageSprite->getBoundingBox();
            if (bounds.containsPoint(touch->getLocation()))
            {
                // Guardar el índice del personaje seleccionado
                UserDefault::getInstance()->setIntegerForKey("SelectedCharacterIndex", currentImageIndex);

                // Cambiar a la siguiente escena
                auto newGameScene = NewGame::createScene();
                Director::getInstance()->replaceScene(TransitionFade::create(1, newGameScene));
                return true; // Retornar true para capturar el evento
            }
            return false; // Retornar false para continuar pasando el evento
            };
        _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, imageSprite);
    }
}

