#ifndef __RESTART_H__
#define __RESTART_H__

#include "cocos2d.h"

class restart : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene(); // Declaraci�n del m�todo createScene

	virtual bool init(); // M�todo de inicializaci�n
	CREATE_FUNC(restart); // Macro para crear la funci�n
};

#endif // __SETTINGS_SCENE_H__