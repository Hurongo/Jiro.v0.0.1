
#include "cocos2d.h"
#include "SceneA.h"


USING_NS_CC;
using namespace ui;
using namespace std;

class SceneCinSold : public cocos2d::Scene
{
public:
    TextField* deletetext;
    TextField* textField;
    Button* buttonSave;
    Button* buttonDelete;
    static cocos2d::Scene* createScene(); // Returns a Scene instance pointer
    virtual bool init();                  // Initializes the class
    CREATE_FUNC(SceneCinSold);                  // Makes a create() method
    // Returns a pointer to an instance of itself
    void SceneCinSold::firstScene(float delta);
    void SceneCinSoldCin(float delta);

    void textFieldEvent(Ref* sender, TextField::EventType type);
    void lidv1();
    void deleteSoldir(string nomer);
    
};

