#include "Controls.h"   
#include "SettingsScene.h"

USING_NS_CC;

Scene* Controls::createScene()
{
	auto scene = Controls::create();
	return scene;
}

bool Controls::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto backButton = MenuItemImage::create("Back.png", "Back.png", CC_CALLBACK_1(Controls::onReturn, this));
	backButton->setPosition(Point(visibleSize.width / 13, visibleSize.height / 6.3));
	backButton->setScale(0.9);

	auto exitButton = MenuItemImage::create("Exit.png", "Exit.png", CC_CALLBACK_1(Controls::onReturn, this));
	exitButton->setPosition(Point(visibleSize.width / 1.1, visibleSize.height / 6.3));
	exitButton->setScale(0.9);


	auto menu = Menu::create(backButton, exitButton, nullptr);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	return true;
}

void Controls::onReturn(Ref* sender)
{
	auto controlsScene = Settings::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1, controlsScene));
}

void Controls::onExit(Ref* sender)
{
	Director::getInstance()->end();
}