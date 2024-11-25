#ifndef __CONTROLS_H__
#define __CONTROLS_H__

#include "cocos2d.h"

class Controls : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene(); // Declaraci�n del m�todo createScene

	virtual bool init(); // M�todo de inicializaci�n
	CREATE_FUNC(Controls); // Macro para crear la funci�n
	void onReturn(cocos2d::Ref* psender);
	void onExit(cocos2d::Ref* pSender);
};

#endif // __SETTINGS_SCENE_H__