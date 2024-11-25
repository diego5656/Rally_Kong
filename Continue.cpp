#include "Continue.h"   

USING_NS_CC;

Scene* ContinueGame::createScene()
{
	auto scene = ContinueGame::create();
	return scene;
}

bool ContinueGame::init()
{
	if (!Scene::init())
	{
		return false;
	}
}