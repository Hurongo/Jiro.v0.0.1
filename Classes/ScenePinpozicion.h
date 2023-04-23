#pragma once
#include "SceneCinSold.h"


class ScenePinpozicion : public cocos2d::Scene
{
public:
    Button* buttonSave;
    Button* buttonDelete;
    TextField* textCinPoz;
    TextField* textCinSoldierneed;
    TextField* deletepoz;
    static cocos2d::Scene* createScene(); // Returns a Scene instance pointer
    virtual bool init();                  // Initializes the class
    CREATE_FUNC(ScenePinpozicion);                  // Makes a create() method
    // Returns a pointer to an instance of itself
    void save();
    void Vec(string blokc);
    void DeletePoz(string nomer);
};