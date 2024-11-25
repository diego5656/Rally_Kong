#ifndef __CONTINUE_SCENE_H__
#define __CONTINUE_SCENE_H__

#include "cocos2d.h"

class Continue : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(Continue);
};

#endif // __CONTINUE_SCENE_H__