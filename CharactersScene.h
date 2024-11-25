#ifndef __CHARACTERS_SCENE_H__
#define __CHARACTERS_SCENE_H__

#include "cocos2d.h"

class Characters : public cocos2d::Scene
{
public:
    // Crear la escena
    static cocos2d::Scene* createScene();

    // Método init
    virtual bool init();

    // Callbacks de los botones
    void onBack(cocos2d::Ref* sender);
    void onNext(cocos2d::Ref* sender);
    void onExit(cocos2d::Ref* sender);
    void onBackArrow(cocos2d::Ref* sender);
    void onNextArrow(cocos2d::Ref* sender);

    // Actualizar la imagen del personaje
    void updateImage();

    // Macro de creación
    CREATE_FUNC(Characters);

private:
    // Vector con las imágenes de los personajes
    std::vector<std::string> images;

    // Índice de la imagen actual
    size_t currentImageIndex;

    // Sprite para mostrar la imagen actual
    cocos2d::Sprite* imageSprite = nullptr;
};

#endif // __CHARACTERS_SCENE_H__
