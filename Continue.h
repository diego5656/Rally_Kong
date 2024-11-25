#ifndef __CONTINUE_H__
#define __CONTINUE_H__

#include "cocos2d.h"

class ContinueGame : public cocos2d::Scene
{			  
public:
	static cocos2d::Scene* createScene(); // Declaración del método createScene

	virtual bool init(); // Método de inicialización
	CREATE_FUNC(ContinueGame); // Macro para crear la función
};

#endif // __SETTINGS_SCENE_H__