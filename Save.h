#ifndef __SAVE_H__
#define __SAVE_H__

#include "cocos2d.h"

class Save : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene(); // Declaraci�n del m�todo createScene

	virtual bool init(); // M�todo de inicializaci�n
	CREATE_FUNC(Save); // Macro para crear la funci�n
};

#endif // __SETTINGS_SCENE_H__