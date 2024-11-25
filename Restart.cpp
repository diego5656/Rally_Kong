#include "Restart.h"

#include "HelloWorldScene.h"

USING_NS_CC;

Scene* restart::createScene()
{
	auto scene = restart::create();
	return scene;
}

bool restart::init()
{
	if (!Scene::init())
	{
		return false;
	}
}