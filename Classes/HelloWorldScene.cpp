#include "HelloWorldScene.h"




Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png",
        CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

   auto menu = Menu::create(closeItem, NULL);
   auto myLabel = Label::createWithSystemFont("My Label Text", "Arial", 16);
  
   
   auto buttonMenu = Button::create("menu2.jpg", "menu.jpg");
   buttonMenu->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type)
       {
           switch (type)
           {
           case ui::Widget::TouchEventType::BEGAN:
               break;
           case ui::Widget::TouchEventType::ENDED:
               scheduleOnce(SEL_SCHEDULE(&HelloWorld::nextScene), 0);
               //std::cout << "Button 1 clicked" << std::endl;
               break;
           default:
               break;
           }

       });
   buttonMenu->setPosition(Vec2(240, 280));
   buttonMenu->setScale(0.5);
   this->addChild(buttonMenu);

   auto buttonMenu2 = Button::create("menu2.jpg", "menu.jpg");
   buttonMenu2->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type)
       {
           switch (type)
           {
           case ui::Widget::TouchEventType::BEGAN:
               break;
           case ui::Widget::TouchEventType::ENDED:
               //std::cout << "Button 1 clicked" << std::endl;
               break;
           default:
               break;
           }

       });
   buttonMenu2->setPosition(Vec2(240, 220));
   buttonMenu2->setScale(0.5);
   this->addChild(buttonMenu2);

   auto buttonMenu3 = Button::create("menu2.jpg", "menu.jpg");
   buttonMenu3->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type)
       {
           switch (type)
           {
           case ui::Widget::TouchEventType::BEGAN:
               break;
           case ui::Widget::TouchEventType::ENDED:
               //std::cout << "Button 1 clicked" << std::endl;
               break;
           default:
               break;
           }

       });
   buttonMenu3->setPosition(Vec2(240, 160));
   buttonMenu3->setScale(0.5);
   this->addChild(buttonMenu3);

   auto buttonMenu4 = Button::create("menu2.jpg", "menu.jpg");
   buttonMenu4->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type)
       {
           switch (type)
           {
           case ui::Widget::TouchEventType::BEGAN:
               break;
           case ui::Widget::TouchEventType::ENDED:
               //std::cout << "Button 1 clicked" << std::endl;
               break;
           default:
               break;
           }

       });
   buttonMenu4->setPosition(Vec2(240, 100));
   buttonMenu4->setScale(0.5);
   this->addChild(buttonMenu4);




   menu->setPosition(Vec2(460, 20));
   myLabel->setPosition(Vec2(300, 200));
   

   this->addChild(myLabel, 16);
   this->addChild(menu, 1);
   
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
void HelloWorld::addSprite()
{
    auto buttonMenu = Button::create("menu2.jpg", "menu.jpg");

    buttonMenu->setPosition(Vec2(250, 200));
    buttonMenu->setScale(0.3);
    buttonMenu->setScaleX(0.5);

    this->addChild(buttonMenu);
}

void HelloWorld::nextScene(float delta)
{
    auto director = Director::getInstance();
    auto scene = SceneA::createScene();
    director->replaceScene(scene);
}

void SceneA::firstScene(float delta)
{
    auto director = Director::getInstance();
    auto scene = HelloWorld::createScene();
    director->replaceScene(scene);
}

