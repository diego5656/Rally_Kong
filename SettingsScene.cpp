#include "SettingsScene.h"
#include "Restart.h"
#include "Sound.h"
#include "Continue.h"
#include "Save.h"
#include "Controls.h"
#include <HelloWorldScene.h>

USING_NS_CC;

Scene* Settings::createScene()
{
	auto scene = Settings::create();
	return scene;
}

bool Settings::init()
{
	if (!Scene::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// Crear un label con la descripci�n de las configuraciones
	auto restartLabel = Label::createWithSystemFont("Restart Game", "Arial", 10);
	auto restartItem = MenuItemLabel::create(restartLabel, CC_CALLBACK_1(Settings::onRestart, this));
	restartItem->setPosition(Point(visibleSize.width / 2, visibleSize.height * 0.8));

	auto soundLabel = Label::createWithSystemFont("Sound", "Arial", 10);
	auto soundItem = MenuItemLabel::create(soundLabel, CC_CALLBACK_1(Settings::onSound, this));
	soundItem->setPosition(Point(visibleSize.width / 2, visibleSize.height * 0.7));

	auto continueLabel = Label::createWithSystemFont("Continue Game", "Arial", 10);
	auto continueItem = MenuItemLabel::create(continueLabel, CC_CALLBACK_1(Settings::onContinue, this));
	continueItem->setPosition(Point(visibleSize.width / 2, visibleSize.height * 0.6));

	auto saveLabel = Label::createWithSystemFont("Save Game", "Arial", 10);
	auto saveItem = MenuItemLabel::create(saveLabel, CC_CALLBACK_1(Settings::onSave, this));
	saveItem->setPosition(Point(visibleSize.width / 2, visibleSize.height * 0.5));

	auto controlsLabel = Label::createWithSystemFont("Game Controls", "Arial", 10);
	auto controlsItem = MenuItemLabel::create(controlsLabel, CC_CALLBACK_1(Settings::onControls, this));
	controlsItem->setPosition(Point(visibleSize.width / 2, visibleSize.height * 0.4));

	auto exitLabel = Label::createWithSystemFont("Exit", "Arial", 10);
	auto exitItem = MenuItemLabel::create(exitLabel, CC_CALLBACK_1(Settings::onExit, this));
	exitItem->setPosition(Point(visibleSize.width / 2, visibleSize.height * 0.3));

	auto backButton = MenuItemImage::create("Back.png", "Back.png", CC_CALLBACK_1(Settings::onBack, this));
	backButton->setPosition(Point(visibleSize.width / 13, visibleSize.height / 6.3));
	backButton->setScale(0.9);

	auto menu = Menu::create(restartItem, soundItem, continueItem, saveItem, controlsItem, exitItem, backButton, nullptr);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);

	return true;

}

void Settings::onRestart(Ref* pSender)
{
	auto restartGame = restart::createScene();

	// Reemplazar la escena actual con la nueva y crear una transicion
	Director::getInstance()->replaceScene(TransitionFade::create(1, restartGame));
}

void Settings::onSound(Ref* pSender)
{
	auto soundGame = Sound::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1, soundGame));
}

void Settings::onContinue(Ref* pSender)
{
	auto continueGame = ContinueGame::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1, continueGame));
}

void Settings::onSave(Ref* pSender)
{
	auto saveGame = Save::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1, saveGame));
}

void Settings::onControls(Ref* pSender)
{
	auto controlsGame = Controls::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1, controlsGame));
}

void Settings::onBack(Ref* sender)
{
	auto settingsScene = HelloWorld::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1, settingsScene));
}

void Settings::onExit(Ref* pSender)
{
	Director::getInstance()->end();
}
