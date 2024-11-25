#include "ContinueScene.h"

USING_NS_CC;

Scene* Continue::createScene()

{
	auto scene = Continue::create();
	return scene;
}

bool Continue::init()
{
	if (!Scene::init()) 
	{
		return false;
	}

}