#ifndef __RESTART_H__
#define __RESTART_H__

#include "cocos2d.h"

class restart : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene(); // Declaración del método createScene

	virtual bool init(); // Método de inicialización
	CREATE_FUNC(restart); // Macro para crear la función
};

#endif // __SETTINGS_SCENE_H__