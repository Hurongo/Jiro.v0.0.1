#include "SceneZapisNapozicion.h"

Scene* SceneA::createScene()
{
    return SceneA::create();
}
bool SceneA::init()
{
    if (!Scene::init())
    {
        return false;
    }

    auto button = Button::create("back.png", "back2.png");

    button->setTitleText("Button Text");

    button->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            break;
        case ui::Widget::TouchEventType::ENDED:
            scheduleOnce(SEL_SCHEDULE(&SceneA::firstScene), 0);
            std::cout << "Button 1 clicked" << std::endl;
            break;
        default:
            break;
        }
        });
    button->setPosition(Vec2(40, 40));
    button->setScale(0.2);

    auto buttonMenu = Button::create("menu2.jpg", "menu.jpg");
    buttonMenu->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type)
        {
            switch (type)
            {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:
                scheduleOnce(SEL_SCHEDULE(&SceneCinSold::SceneCinSoldCin), 0);
                break;
            default:
                break;
            }

        });
    buttonMenu->setPosition(Vec2(240, 280));
    buttonMenu->setScale(0.5);
    
    auto buttonMenu2 = Button::create("menu2.jpg", "menu.jpg");
    buttonMenu2->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type)
        {
            switch (type)
            {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:
                //std::cout << "Button 1 clicked" << std::endl;
                Director::getInstance()->replaceScene(ScenePinpozicion::createScene());
                break;
            default:
                break;
            }

        });
    buttonMenu2->setPosition(Vec2(240, 220));
    buttonMenu2->setScale(0.5);
    

    auto buttonMenu3 = Button::create("menu2.jpg", "menu.jpg");
    buttonMenu3->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type)
        {
            switch (type)
            {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:
                //std::cout << "Button 1 clicked" << std::endl;
                Director::getInstance()->replaceScene(SceneZapisNapozicion::createScene());
                break;
            default:
                break;
            }

        });
    buttonMenu3->setPosition(Vec2(240, 160));
    buttonMenu3->setScale(0.5);
    
    


    auto sprite = Sprite::create("HelloWorld.png");
    sprite->setPosition(200, 200);
    this->addChild(sprite);

    auto spriteWhite = Sprite::create("White.png");
    spriteWhite->setPosition(40, 40);
    spriteWhite->setScale(0.4);

    this->addChild(buttonMenu3);
    this->addChild(buttonMenu2);
    this->addChild(spriteWhite);
    this->addChild(button);
    this->addChild(buttonMenu);
    return true;
}

void SceneCinSold::SceneCinSoldCin(float delta)
{
    auto director = Director::getInstance();
    auto scene = SceneCinSold::createScene();
    director->replaceScene(scene);
}
