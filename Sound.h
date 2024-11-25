#ifndef __SOUND_H__
#define __SOUND_H__

#include "cocos2d.h"

class Sound : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene(); // Declaraci�n del m�todo createScene

	virtual bool init(); // M�todo de inicializaci�n
	CREATE_FUNC(Sound); // Macro para crear la funci�n
	void onRegresar(cocos2d::Ref* sender);
	void onSalir(cocos2d::Ref* sender);
};

#endif // __SETTINGS_SCENE_H__