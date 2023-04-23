#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <regex>

#include "SceneZapisNapozicion.h"

#include "Soldier.h"
#include "Positions.h"
#include "ZapisNaPoz.h"




std::string v1;

Scene* SceneCinSold::createScene()
{
    return SceneCinSold::create();
}
bool SceneCinSold::init()
{
    if (!Scene::init())
    {
        return false;
    }
    

   textField = TextField::create("Clic this", "font.ttf", 20);
    textField->setMaxLength(10);
    textField->setMaxLengthEnabled(true);

    textField->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        std::cout << "editing a TextField" << std::endl;
        });

    textField->setPosition(Vec2(240, 260));

    this->addChild(textField);
    std::string enteredData = textField->getString();
    std::cout << enteredData << std::endl;
    
    
    buttonSave = Button::create("save.png", "save2.png");
    buttonSave->setTitleText("Button Text");
    buttonSave->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type)
        {
            auto path = FileUtils::getInstance()->getWritablePath();
            switch (type)
            {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:
                lidv1();
                
                break;
            default:
                break;
            }
        });

    buttonSave->setPosition(Vec2(420, 50));
    buttonSave->setScale(0.2);

    this->addChild(buttonSave);



    deletetext = cocos2d::ui::TextField::create("to delete :", "Arial", 20);
    deletetext->setTextHorizontalAlignment(cocos2d::TextHAlignment::CENTER);
    deletetext->setTextVerticalAlignment(cocos2d::TextVAlignment::CENTER);
    deletetext->setColor(Color3B(255, 0, 0));
    deletetext->setMaxLength(10);
    deletetext->setMaxLengthEnabled(true);
    deletetext->setTouchAreaEnabled(true);
    deletetext->setTouchSize(Size(50, 30));
    deletetext->setPosition(Vec2(420, 170));
    deletetext->addEventListener(CC_CALLBACK_2(SceneCinSold::textFieldEvent, this));
    this->addChild(deletetext, 10);


    buttonDelete = Button::create("delete.jpg", "delete2.jpg");
    buttonDelete->setTitleText("Button Text");
    buttonDelete->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type)
    {
            auto path = FileUtils::getInstance()->getWritablePath();
    switch (type)
    {
    case ui::Widget::TouchEventType::BEGAN:
        break;
    case ui::Widget::TouchEventType::ENDED:
        deleteSoldir(deletetext->getString());
        break;
    default:
        break;
    }
    });

    buttonDelete->setPosition(Vec2(420, 120));
    buttonDelete->setScale(0.2);

    this->addChild(buttonDelete);



    auto button = Button::create("back.png", "back2.png");
    button->setTitleText("Button Text");
    button->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) 
        {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            break;
        case ui::Widget::TouchEventType::ENDED:
            Director::getInstance()->replaceScene(SceneA::createScene());
            std::cout << "Button 1 clicked" << std::endl;
            break;
        default:
            break;
        }
        });


    auto spriteWhite = Sprite::create("White.png");
    spriteWhite->setPosition(40, 40);
    spriteWhite->setScale(0.4);
    this->addChild(spriteWhite);

    button->setPosition(Vec2(40, 40));
    button->setScale(0.2);

    this->addChild(button);

    auto myText = Label::createWithSystemFont("Soldier list Free :", "Arial", 16);
    
    myText->setColor(Color3B(100, 100, 100));
    myText->setPosition(Vec2(120, 210));
    this->addChild(myText, 10);

    auto myText2 = Label::createWithSystemFont("Soldier :", "Marker Felt.ttf", 16);

    myText2->setColor(Color3B(100, 100, 100));
    myText2->setPosition(Vec2(290, 210));
    this->addChild(myText2, 10);

    
    std::string sbuf;
    auto path = FileUtils::getInstance()->getWritablePath() ;
    FileUtils::getInstance()->getContents(path + "Soldierlist.txt", &sbuf );
   
    ui::ListView* listview = ListView::create();
    
    listview->setContentSize({ 120, 200 });

    ui::Text* text = ui::Text::create(sbuf , "fontName.ttf", 16);
    text->setTextAreaSize({ 300, 0 });
    listview->addChild(text);
    listview->requestDoLayout();
    listview->setPosition({ 280, 0 });
    this->addChild(listview);
    

    std::string sbuff;
    FileUtils::getInstance()->getContents(FileUtils::getInstance()->getWritablePath() + "SoldierlistFree.txt", &sbuff);
    ui::ListView* listviewFree = ListView::create();


    listviewFree->setContentSize({ 120, 200 });
    ui::Text* textt = ui::Text::create(sbuff, "fontName.ttf", 16);
    textt->setTextAreaSize({ 300, 0 });
    listviewFree->addChild(textt);
    listviewFree->requestDoLayout();
    listviewFree->setPosition({ 80, 0 });
    this->addChild(listviewFree);




    return true;


}

void SceneCinSold::textFieldEvent(Ref *sender, TextField::EventType type)
{
    ui::TextField *textCin = dynamic_cast<ui::TextField *> ( sender );

    switch (type)
    {
    case ui::TextField::EventType::ATTACH_WITH_IME:
        log("Start typing rev rev");
        break;
    case ui::TextField::EventType::DETACH_WITH_IME:
        log("Start typing rev rev");
        break;
    case ui::TextField::EventType::INSERT_TEXT:
        log("%s", textCin-> getString( ).c_str());
        break;
    case ui::TextField::EventType::DELETE_BACKWARD:
        log("%s", textCin->getString().c_str());
        break;
    default:

        break;
    }


}

void SceneCinSold::lidv1()
{
    if (textField->getString() != "")
    {
        Soldier Tomas;
        string SoldierList = FileUtils::getInstance()->getWritablePath() + "Soldierlist.txt";
        string SoldierListFree = FileUtils::getInstance()->getWritablePath() + "SoldierlistFree.txt";
        string SoldierList2 = FileUtils::getInstance()->getWritablePath() + "Soldierlist2.txt";
        string SoldierListFree2 = FileUtils::getInstance()->getWritablePath() + "SoldierlistFree2.txt";

        fstream fs;
        fstream fsf;

        fs.open(SoldierList, fstream::in | fstream::out | fstream::app);
        fsf.open(SoldierListFree, fstream::in | fstream::out | fstream::app);

        vector<string> list;
        string solger;

        int logic = 1;
        while (true)
        {
            fs >> solger;
            if (fs.eof())
            {
                break;
            }
            else
            {
                list.emplace_back(solger);
            }
        }

        solger = "1";
        if (list.size() != 0)
        {
            logic = list.size() + 1;
            solger = to_string(logic);
        }

        auto path = FileUtils::getInstance()->getWritablePath();
        v1 = FileUtils::getInstance()->getStringFromFile(path + "Soldierlist.txt");

        v1 += textField->getString();
        FileUtils::getInstance()->writeStringToFile( v1 +"_" + solger + ")" + "\n", path + "Soldierlist.txt");


        auto pathFree = FileUtils::getInstance()->getWritablePath();
        v1 = FileUtils::getInstance()->getStringFromFile(pathFree + "SoldierlistFree.txt");

        v1 += textField->getString();
        FileUtils::getInstance()->writeStringToFile(v1 + "\n", pathFree + "SoldierlistFree.txt");

        fs.close();
        fsf.close();

        fs.open(SoldierList2, fstream::in | fstream::out | fstream::app);
        fsf.open(SoldierListFree2, fstream::in | fstream::out | fstream::app);

        Tomas.SetCallsign(textField->getString());
        fs << Tomas << "\n";
        fsf << Tomas << "\n";

        fs.close();
        fsf.close();



        scheduleOnce(SEL_SCHEDULE(&SceneCinSold::SceneCinSoldCin), 0);
    }

}

void SceneCinSold::deleteSoldir (string nomer)
{
    if (nomer != "")
    {
        string SoldierList = FileUtils::getInstance()->getWritablePath() + "Soldierlist.txt";
        string SoldierListFree = FileUtils::getInstance()->getWritablePath() + "SoldierlistFree.txt";
        string SoldierList2 = FileUtils::getInstance()->getWritablePath() + "Soldierlist2.txt";
        string SoldierListFree2 = FileUtils::getInstance()->getWritablePath() + "SoldierlistFree2.txt";

        fstream fs;
        fstream fss;
        fstream fs2;
        fstream fss2;
        // обьект класса 
        ofstream clear;
        fs.open(SoldierList, fstream::in | fstream::out | fstream::app);//чтение и запись в файл
        fss.open(SoldierListFree, fstream::in | fstream::out | fstream::app);
        fs2.open(SoldierList2, fstream::in | fstream::out | fstream::app);
        fss2.open(SoldierListFree2, fstream::in | fstream::out | fstream::app);
        int nomerr = std::stoi(nomer);

        string p;
        string pFree;
        Soldier p2;
        Soldier pFree2;

        vector <string> list;
        vector <string> listFree;
        vector <Soldier> list2;
        vector <Soldier> listFree2;
        int logik = 1;
        while (true)
        {
            fs >> p;
            if (fs.eof())
            {
                break;
            }
            else
            {
                list.emplace_back(p);
            }
        }
        while (true)
        {
            fss >> pFree;

            if (fss.eof())
            {
                break;
            }
            else
            {
                listFree.emplace_back(pFree);
            }
        }
        while (true)
        {
            fs2 >> p2;
            if (fs2.eof())
            {
                break;
            }
            else
            {
                list2.emplace_back(p2);
            }
        }
        while (true)
        {
            fss2 >> pFree2;

            if (fss2.eof())
            {
                break;
            }
            else
            {
                listFree2.emplace_back(pFree2);
            }
        }
        if (nomerr <= 0 || nomerr > list.size())
        {
            //cout << "Davay po novoy" << endl;
        }
        if (nomerr <= 0 || nomerr > listFree.size())
        {
            //cout << "Davay po novoy" << endl;
        }
        if (nomerr <= 0 || nomerr > list2.size())
        {
            //cout << "Davay po novoy" << endl;
        }
        if (nomerr <= 0 || nomerr > listFree2.size())
        {
            //cout << "Davay po novoy" << endl;
        }

        else
        {
            fs.close();
            fss.close();
            fs2.close();
            fss2.close();
            clear.open(SoldierListFree, ofstream::out | ofstream::trunc);
            clear.close();
            clear.open(SoldierList, ofstream::out | ofstream::trunc);
            clear.close();
            clear.open(SoldierListFree2, ofstream::out | ofstream::trunc);
            clear.close();
            clear.open(SoldierList2, ofstream::out | ofstream::trunc);
            clear.close();
            nomerr -= 1;
            list.erase(list.begin() + nomerr);
            listFree.erase(listFree.begin() + nomerr);
            list2.erase(list2.begin() + nomerr);
            listFree2.erase(listFree2.begin() + nomerr);

            fs.open(SoldierList, fstream::in | fstream::out | fstream::app);
            fss.open(SoldierListFree, fstream::in | fstream::out | fstream::app);
            fs2.open(SoldierList2, fstream::in | fstream::out | fstream::app);
            fss2.open(SoldierListFree2, fstream::in | fstream::out | fstream::app);

            for (auto i = list.cbegin(); i != list.cend(); i++)
            {
                cout << *i << endl;

                fs << *i << endl;
            }
            for (auto i = listFree.cbegin(); i != listFree.cend(); i++)
            {
                cout << *i << endl;

                fss << *i << endl;
            }
            for (auto i = list2.cbegin(); i != list2.cend(); i++)
            {
                cout << *i << endl;

                fs2 << *i << endl;
            }
            for (auto i = listFree2.cbegin(); i != listFree2.cend(); i++)
            {
                cout << *i << endl;

                fss2 << *i << endl;
            }
        }

        fs.close();
        fss.close();
        fs2.close();
        fss2.close();
    }
    

    Director::getInstance()->replaceScene(SceneCinSold::createScene());
}




Scene* ScenePinpozicion::createScene()
{
    return ScenePinpozicion::create();
}
bool ScenePinpozicion::init()
{
    if (!Scene::init())
    {
        return false;
    }

    auto spriteWhite = Sprite::create("White.png");
    spriteWhite->setPosition(40, 40);
    spriteWhite->setScale(0.4);
    this->addChild(spriteWhite);

    auto button = Button::create("back.png", "back2.png");

    button->setTitleText("Button Text");

    button->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            break;
        case ui::Widget::TouchEventType::ENDED:
            Director::getInstance()->replaceScene(SceneA::createScene());
            std::cout << "Button 1 clicked" << std::endl;
            break;
        default:
            break;
        }
        });
    button->setPosition(Vec2(40, 40));
    button->setScale(0.2);
    this->addChild(button);

    buttonSave = Button::create("save.png", "save2.png");
    buttonSave->setTitleText("Button Text");
    buttonSave->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type)
        {
            auto path = FileUtils::getInstance()->getWritablePath();
    switch (type)
    {
    case ui::Widget::TouchEventType::BEGAN:
        break;
    case ui::Widget::TouchEventType::ENDED:
        save();
        Director::getInstance()->replaceScene(ScenePinpozicion::createScene());
        break;
    default:
        break;
    }
        });

    buttonSave->setPosition(Vec2(420, 50));
    buttonSave->setScale(0.2);

    this->addChild(buttonSave);


    textCinPoz = cocos2d::ui::TextField::create("________", "Arial", 16);
    textCinPoz->setTextHorizontalAlignment(cocos2d::TextHAlignment::CENTER);
    textCinPoz->setTextVerticalAlignment(cocos2d::TextVAlignment::CENTER);
    textCinPoz->setColor(Color3B(100, 100, 100));
    textCinPoz->setMaxLength(10);
    textCinPoz->setMaxLengthEnabled(true);
    textCinPoz->setTouchAreaEnabled(true);
    textCinPoz->setTouchSize(Size(200, 150));
    textCinPoz->setPosition(Vec2(200, 300));
    this->addChild(textCinPoz, 10);

    textCinSoldierneed = cocos2d::ui::TextField::create("________", "Arial", 16);
    textCinSoldierneed->setTextHorizontalAlignment(cocos2d::TextHAlignment::CENTER);
    textCinSoldierneed->setTextVerticalAlignment(cocos2d::TextVAlignment::CENTER);
    textCinSoldierneed->setColor(Color3B(100, 100, 100));
    textCinSoldierneed->setMaxLength(10);
    textCinSoldierneed->setMaxLengthEnabled(true);
    textCinSoldierneed->setTouchAreaEnabled(true);
    textCinSoldierneed->setTouchSize(Size(100, 20));
    textCinSoldierneed->setPosition(Vec2(200, 280));
    this->addChild(textCinSoldierneed, 10);


    auto myText2 = Label::createWithSystemFont("Position :", "Marker Felt.ttf", 16);

    myText2->setColor(Color3B(100, 100, 100));
    myText2->setPosition(Vec2(290, 210));
    this->addChild(myText2, 10);

    
    std::string sbuf;
    auto path = FileUtils::getInstance()->getWritablePath();
    FileUtils::getInstance()->getContents(path + "pozicion.txt", &sbuf);

    ui::ListView* listview = ListView::create();

    listview->setContentSize({ 120, 200 });

    ui::Text* text = ui::Text::create(sbuf, "fontName.ttf", 16);
    text->setTextAreaSize({ 300, 0 });
    listview->addChild(text);
    listview->requestDoLayout();
    listview->setPosition({ 280, 0 });
    this->addChild(listview);


    auto myTextPoz = Label::createWithSystemFont("Pozicion :", "Arial", 16);

    myTextPoz->setColor(Color3B(100, 100, 100));
    myTextPoz->setPosition(Vec2(120, 300));
    this->addChild(myTextPoz, 10);

    auto myTextNeed = Label::createWithSystemFont(" Pozicion Need Soldier :", "Arial", 16);

    myTextNeed->setColor(Color3B(100, 100, 100));
    myTextNeed->setPosition(Vec2(80, 280));
    this->addChild(myTextNeed, 10);


    deletepoz = cocos2d::ui::TextField::create("to delete :", "Arial", 20);
    deletepoz->setTextHorizontalAlignment(cocos2d::TextHAlignment::CENTER);
    deletepoz->setTextVerticalAlignment(cocos2d::TextVAlignment::CENTER);
    deletepoz->setColor(Color3B(255, 0, 0));
    deletepoz->setMaxLength(10);
    deletepoz->setMaxLengthEnabled(true);
    deletepoz->setTouchAreaEnabled(true);
    deletepoz->setTouchSize(Size(50, 30));
    deletepoz->setPosition(Vec2(420, 170));
    this->addChild(deletepoz, 10);


    buttonDelete = Button::create("delete.jpg", "delete2.jpg");
    buttonDelete->setTitleText("Button Text");
    buttonDelete->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type)
        {
            auto path = FileUtils::getInstance()->getWritablePath();
    switch (type)
    {
    case ui::Widget::TouchEventType::BEGAN:
        break;
    case ui::Widget::TouchEventType::ENDED:
        DeletePoz(deletepoz->getString());
        break;
    default:
        break;
    }
        });

    buttonDelete->setPosition(Vec2(420, 120));
    buttonDelete->setScale(0.2);

    this->addChild(buttonDelete);


    auto ButtonZa = Button::create("za.png", "za2.png");
    ButtonZa->setTitleText("Button Text");
    ButtonZa->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            break;
        case ui::Widget::TouchEventType::ENDED:
            Director::getInstance()->replaceScene(SceneInfoPozicion::createScene());
            break;
        default:
            break;
        }
        });
    ButtonZa->setPosition(Vec2(40, 100));
    ButtonZa->setScale(0.3);
    this->addChild(ButtonZa);


    return true;
}
void ScenePinpozicion::save()
{

    if (textCinPoz->getString() != "" && textCinSoldierneed->getString() != "")
    {
        Positions Avrora;

        string PozicionList = FileUtils::getInstance()->getWritablePath() + "pozicion.txt";

        fstream fs;

        fs.open(PozicionList, fstream::in | fstream::out | fstream::app);

        int nomerr = std::stoi(textCinSoldierneed->getString());
        Avrora.SetInfoPositions(nomerr, textCinPoz->getString());
        fs << Avrora;

        fs.close();
    }
}

void ScenePinpozicion::DeletePoz(string nomer)
{
    if (deletepoz->getString() != "")
    {
        Positions Avrora;

        string PozicionList = FileUtils::getInstance()->getWritablePath() + "pozicion.txt";
        ofstream clear;
        fstream fs;
        fs.open(PozicionList, fstream::in | fstream::out | fstream::app);
        int nomerr = std::stoi(nomer);

        string poz;
        vector <Positions> listPoz;

        int logik = 1;
        while (true)
        {
            if (fs >> Avrora)
            {
                listPoz.emplace_back(Avrora);
            }
            else
            {
                break;
            }

        }
        if (nomerr <= 0 || nomerr > listPoz.size())
        {
            //cout << "Davay po novoy" << endl;break;
        }
        else
        {
            fs.close();
            clear.open(PozicionList, ofstream::out | ofstream::trunc);
            clear.close();

            nomerr -= 1;
            listPoz.erase(listPoz.begin() + nomerr);
            fs.open(PozicionList, fstream::in | fstream::out | fstream::app);

            for (auto i = listPoz.cbegin(); i != listPoz.cend(); i++)
            {
                cout << *i << endl;

                fs << *i << endl;
            }
            fs.close();
            Director::getInstance()->replaceScene(ScenePinpozicion::createScene());
        }
    }


}

vector <Positions> listPozZapis;

string SceneZapisNapozicion::PleyZaPoz()
{
    Soldier  p;
    Positions avrora_21;

    string PositionsListBusy = FileUtils::getInstance()->getWritablePath() + "PositionsListBusy.txt";
    string Finish = "";
    fstream fspb;
    fspb.open(PositionsListBusy, fstream::in | fstream::out | fstream::app);

    int iter;
    int t = 24;
    int min = 0;

    vector <int> TimeLine(t);
    for (int i = 0; i < t; i++)
    {
        TimeLine[i] = i;
    }

    while (true)
    {
        if (fspb >> avrora_21)
        {
            fspb >> iter;
            if (!fspb.eof())
            {
                cout << "\n" << avrora_21.GetNamePositions() << endl;
                Finish += "\n" + avrora_21.GetNamePositions() + " : \n";
            }
            for (int i = 0; i < (avrora_21.GetNeedSoldier() * iter); i++)
            {
                if (i == 0 || i % avrora_21.GetNeedSoldier() == 0)
                {
                    cout << TimeLine[min] << ":00" << endl;
                    Finish += "\n" + to_string(TimeLine[min]) + ":00\n";

                    min = (t / iter) + min;
                }
                fspb >> p;
                cout << p << endl;
                Finish += p.GetCallsign() + "\n";
            }
            min = 0;
        }
        else
        {
            //cout << endl << endl;
            break;
        }
    }
    return Finish;
}

Scene* SceneZapisNapozicion::createScene()
{
    return SceneZapisNapozicion::create();
}
bool SceneZapisNapozicion::init()
{
    if (!Scene::init())
    {
        return false;
    }

    PleyZaPoz();



    std::string sbuf;
    auto path = FileUtils::getInstance()->getWritablePath();
    FileUtils::getInstance()->getContents(path + "PositionsListBusy.txt", &sbuf);

    ui::ListView* listview = ListView::create();

    listview->setContentSize({ 1400, 200 });

    ui::Text* text = ui::Text::create(PleyZaPoz(), "fontName.ttf", 16);
    text->setTextAreaSize({ 480, 0 });
    listview->addChild(text);
    listview->requestDoLayout();
    listview->setPosition({ 80, 80 });
    this->addChild(listview);

    auto spriteWhite = Sprite::create("White.png");
    spriteWhite->setPosition(40, 40);
    spriteWhite->setScale(0.4);
    this->addChild(spriteWhite);

    auto button = Button::create("back.png", "back2.png");

    button->setTitleText("Button Text");

    button->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            break;
        case ui::Widget::TouchEventType::ENDED:
            Director::getInstance()->replaceScene(SceneA::createScene());
            std::cout << "Button 1 clicked" << std::endl;
            break;
        default:
            break;
        }
        });
    button->setPosition(Vec2(40, 40));
    button->setScale(0.2);
    this->addChild(button);

    return true;
}



void SceneInfoPozicion::zapisNaPozi()
{

    if (chas->getString() != "" && Nomerposition->getString() != "")
    {
        Positions Avrora;

        string PozicionList = FileUtils::getInstance()->getWritablePath() + "pozicion.txt";

        fstream fs;

        fs.open(PozicionList, fstream::in | fstream::out | fstream::app);

        int nomerr = std::stoi(Nomerposition->getString());
        int chasik = std::stoi(chas->getString());

        for (int i = 0; i < nomerr; i++)
        {
            fs >> Avrora;
        }

        //Avrora.SetInfoPositions(nomerr, Nomerposition->getString());
        //fs << Avrora;
        //fsFree << Avrora;



        
        fs.close();
        ZapisNaPoz(Avrora.GetNeedSoldier(), Avrora.GetNamePositions(), chasik);
        Director::getInstance()->replaceScene(SceneInfoPozicion::createScene());
    }
}


Scene* SceneInfoPozicion::createScene()
{
    return SceneInfoPozicion::create();
}
bool SceneInfoPozicion::init()
{
    if (!Scene::init())
    {
        return false;
    }

    
    chas = cocos2d::ui::TextField::create("________", "Arial", 16);
    chas->setTextHorizontalAlignment(cocos2d::TextHAlignment::CENTER);
    chas->setTextVerticalAlignment(cocos2d::TextVAlignment::CENTER);
    chas->setColor(Color3B(100, 100, 100));
    chas->setMaxLength(10);
    chas->setMaxLengthEnabled(true);
    chas->setTouchAreaEnabled(true);
    chas->setTouchSize(Size(200, 150));
    chas->setPosition(Vec2(300, 300));
    this->addChild(chas, 10);

    Nomerposition = cocos2d::ui::TextField::create("________", "Arial", 16);
    Nomerposition->setTextHorizontalAlignment(cocos2d::TextHAlignment::CENTER);
    Nomerposition->setTextVerticalAlignment(cocos2d::TextVAlignment::CENTER);
    Nomerposition->setColor(Color3B(100, 100, 100));
    Nomerposition->setMaxLength(10);
    Nomerposition->setMaxLengthEnabled(true);
    Nomerposition->setTouchAreaEnabled(true);
    Nomerposition->setTouchSize(Size(100, 20));
    Nomerposition->setPosition(Vec2(200, 280));
    this->addChild(Nomerposition, 10);



    auto myTextPoz = Label::createWithSystemFont("Peresmenka vo skolko chasov? :", "Arial", 16);

    myTextPoz->setColor(Color3B(100, 100, 100));
    myTextPoz->setPosition(Vec2(120, 300));
    this->addChild(myTextPoz, 10);

    auto myTextNeed = Label::createWithSystemFont("Nomer position :", "Arial", 16);

    myTextNeed->setColor(Color3B(100, 100, 100));
    myTextNeed->setPosition(Vec2(80, 280));
    this->addChild(myTextNeed, 10);

    auto myText2 = Label::createWithSystemFont("Positions :", "Marker Felt.ttf", 16);

    myText2->setColor(Color3B(100, 100, 100));
    myText2->setPosition(Vec2(290, 210));
    this->addChild(myText2, 10);

    std::string sbuf;
    auto path = FileUtils::getInstance()->getWritablePath();
    FileUtils::getInstance()->getContents(path + "pozicion.txt", &sbuf);

    ui::ListView* listview = ListView::create();

    listview->setContentSize({ 120, 200 });

    ui::Text* text = ui::Text::create(sbuf, "fontName.ttf", 16);
    text->setTextAreaSize({ 300, 0 });
    listview->addChild(text);
    listview->requestDoLayout();
    listview->setPosition({ 280, 0 });
    this->addChild(listview);

    auto ButtonZa = Button::create("za.png", "za2.png");
    ButtonZa->setTitleText("Button Text");
    ButtonZa->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            break;
        case ui::Widget::TouchEventType::ENDED:
            std::cout << "Button 1 clicked" << std::endl;
            zapisNaPozi();
            break;
        default:
            break;
        }
        });
    ButtonZa->setPosition(Vec2(40, 100));
    ButtonZa->setScale(0.3);
    this->addChild(ButtonZa);


    auto spriteWhite = Sprite::create("White.png");
    spriteWhite->setPosition(40, 40);
    spriteWhite->setScale(0.4);
    this->addChild(spriteWhite);

    auto button = Button::create("back.png", "back2.png");

    button->setTitleText("Button Text");

    button->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            break;
        case ui::Widget::TouchEventType::ENDED:
            Director::getInstance()->replaceScene(ScenePinpozicion::createScene());
            std::cout << "Button 1 clicked" << std::endl;
            break;
        default:
            break;
        }
        });
    button->setPosition(Vec2(40, 40));
    button->setScale(0.2);
    this->addChild(button);
return true;
}

