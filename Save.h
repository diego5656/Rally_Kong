#ifndef __SAVE_H__
#define __SAVE_H__

#include "cocos2d.h"

class Save : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene(); // Declaración del método createScene

	virtual bool init(); // Método de inicialización
	CREATE_FUNC(Save); // Macro para crear la función
};

#endif // __SETTINGS_SCENE_H__