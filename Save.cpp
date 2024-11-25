#include "Save.h"   

USING_NS_CC;

Scene* Save::createScene()
{
	auto scene = Save::create();
	return scene;
}

bool Save::init()
{
	if (!Scene::init())
	{
		return false;
	}
}