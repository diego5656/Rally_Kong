#ifndef NEWGAME_SCENE_H
#define NEWGAME_SCENE_H

#include "cocos2d.h"

class NewGame : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    CREATE_FUNC(NewGame);
};

#endif // NEWGAME_SCENE_H
