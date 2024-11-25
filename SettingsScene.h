#ifndef __SETTINGS_SCENE_H__
#define __SETTTINGS_SCENE_H__

#include "cocos2d.h"

class Settings : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene(); // Declaración del método createScene

	virtual bool init(); // Método de inicialización
	CREATE_FUNC(Settings); // Macro para crear la función

	// M�todos para los callbacks de los botones
	void onRestart(cocos2d::Ref* sender);
	void onContinue(cocos2d::Ref* sender);
	void onSave(cocos2d::Ref* sender);
	void onSound(cocos2d::Ref* sender);
	void onControls(cocos2d::Ref* sender);
	void onExit(cocos2d::Ref* sender);
	void onBack(cocos2d::Ref* sender);
};

#endif // __SETTINGS_SCENE_H__