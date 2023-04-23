#pragma once

#include <iostream>
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include <string>


USING_NS_CC;
using namespace ui;

class SceneA : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene(); // Returns a Scene instance pointer
    virtual bool init();                  // Initializes the class
    CREATE_FUNC(SceneA);                  // Makes a create() method
    // Returns a pointer to an instance of itself
    void SceneA::firstScene(float delta);
};

