#pragma once
#include "ScenePinpozicion.h"



class SceneZapisNapozicion : public cocos2d::Scene
{
public:
    Button* buttonList;
    Button* buttonSave;
    Button* buttonDelete;
    TextField* textCinPoz;
    TextField* textCinSoldierneed;
    TextField* deletepoz;

    static cocos2d::Scene* createScene(); // Returns a Scene instance pointer
    virtual bool init();                  // Initializes the class
    CREATE_FUNC(SceneZapisNapozicion);                  // Makes a create() method
    // Returns a pointer to an instance of itself
    void save();
    void Vec(string blokc);
    void DeletePoz(string nomer);
    string PleyZaPoz();
};


class SceneInfoPozicion : public cocos2d::Scene
{
public:
    Button* buttonSave;
    Button* buttonDelete;
    TextField* chas;
    TextField* Nomerposition;
    TextField* deletepoz;
    TextField* ZaNapoz;

    static cocos2d::Scene* createScene(); // Returns a Scene instance pointer
    virtual bool init();                  // Initializes the class
    CREATE_FUNC(SceneInfoPozicion);                  // Makes a create() method
    // Returns a pointer to an instance of itself
    void save();
    void Vec(string blokc);
    void DeletePoz(string nomer);
    void zapisNaPozi();
};