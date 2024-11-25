#ifndef __CONTROLS_H__
#define __CONTROLS_H__

#include "cocos2d.h"

class Controls : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene(); // Declaración del método createScene

	virtual bool init(); // Método de inicialización
	CREATE_FUNC(Controls); // Macro para crear la función
	void onReturn(cocos2d::Ref* psender);
	void onExit(cocos2d::Ref* pSender);
};

#endif // __SETTINGS_SCENE_H__