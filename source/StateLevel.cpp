/*
	Penjin is Copyright (c)2005, 2006, 2007, 2008, 2009, 2010, 2011 Kevin Winfield-Pantoja

	This file is part of Penjin.

	Penjin is free software: you can redistribute it and/or modify
	it under the terms of the GNU Lesser General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	Penjin is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public License
	along with Penjin.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "GFX.h"
#include "StateLevel.h"
#include "StringUtility.h"
#include "Panel.h"
#include "Button.h"
#include "SpriteButton.h"
#include "QuitButton.h"
#include "Sprite.h"
#include "Rectangle.h"
#include "StateManager.h"
#include "MyStateList.h"
// BABY INCLUDES
#include "Baby.h"
#include "BabyEgg.h"
#include "BabyBlob.h"
#include "BabyEggBaby.h"

//  PROPS
#include "Food.h"
#include "Cheese.h"

#include "StatsWindow.h"
using Penjin::StateLevel;
using Penjin::Panel;
using Penjin::Button;
using Penjin::SpriteButton;
using Penjin::Sprite;
using Penjin::Baby;
using Penjin::BabyEgg;
using Penjin::BabyBlob;
using Penjin::BabyEggBaby;
using Penjin::StatsWindow;
using Penjin::Food;
using Penjin::Cheese;
using Penjin::QuitButton;
//using Penjin::Rectangle;

#ifdef DEBUG
    #include <iostream>
    using namespace std;
#endif

StateLevel::StateLevel() : baby(NULL), panel(NULL), background(NULL), statWindow(NULL), food(NULL), water(NULL), waterDir(NULL), quitButton(NULL),
creditsButton(NULL), splashButton(NULL)
{
    //ctor
}

void StateLevel::init()
{
    shouldQuit = false;
    baby = NULL;
    panel = NULL;
    background = NULL;
    statWindow = NULL;
    food = NULL;
    water = NULL;
    waterDir = NULL;
    quitButton = NULL;
    creditsButton = NULL;
    splashButton = NULL;
    Penjin::GFX::getInstance()->setClearColour(Colour(0,0,0));

    // Load list of babies and general settings
    load(BABY_LIST);
    string section = "Baby01";

    // now we setup the correct baby object based on the type detected.
    setupBabyType(getValue(section,"Type","Egg"));

    if(hasChanged())
        save(BABY_LIST);


    setupPanel();
    setupWindows();

    quitButton = new QuitButton;
    quitButton->setPosition(Vector2d<float>(212,5));


    creditsButton = new Button;
    creditsButton->setPosition(Vector2d<float>(212,150));

    splashButton = new Button;
    splashButton->setPosition(Vector2d<float>(4,150));

    // prepare the background
    background = new Image;
    background->load("images/background.png");

    water = new Rectangle;
    water->setColour(Colour(0,0,(uchar)200,128));
    Vector2d<int> dim = GFX::getInstance()->getResolution();
    dim.y +=1;
    water->setDimensions(dim);
    dim.x = 0;
    water->setPosition(dim);

    waterDir = new SimpleDirection;
    waterDir->value = diNONE;
}

void StateLevel::clear()
{
    if(hasChanged())
        save(BABY_LIST);
    delete baby;
    delete panel;
    delete background;
    delete statWindow;
    delete food;
    delete water;
    delete waterDir;
    delete quitButton;
    delete splashButton;
    delete creditsButton;
    baby = NULL;
    panel = NULL;
    background=NULL;
    statWindow=NULL;
    food = NULL;
    water = NULL;
    waterDir = NULL;
    quitButton=NULL;
    splashButton=NULL;
    creditsButton=NULL;
}

StateLevel::~StateLevel()
{
    clear();
}


void StateLevel::setupWindows()
{
    // Stats window
    statWindow = new StatsWindow;
    statWindow->setTitle("Stats");
    statWindow->setBaby(baby);
}

void StateLevel::setupBabyType(const string& t)
{
    delete baby;
    baby = NULL;
    if(t == "" || t == "Egg")
        baby = new BabyEgg;
    else if(t == "Blob")
        baby = new BabyBlob;
    else if(t == "EggBaby")
        baby = new BabyEggBaby;
    if(statWindow)
        statWindow->setBaby(baby);
    setValue("Baby01","Type",t);
}


void StateLevel::setupPanel()
{
    int level = baby->getLevel();

    // Now setup the GUI
    if(panel == NULL)
        panel = new Panel;

    panel->clear();
    if(level >= 0)
    {
        SpriteButton* a = NULL;
        a = new SpriteButton;
        a->loadImage("images/status.png");
        panel->addWidget(a);
    }
    if(level >= 1)
    {
        SpriteButton* a = NULL;
        a = new SpriteButton;
        a->loadImage("images/food.png");
        panel->addWidget(a);
    }
    if(level >= 2)
    {
        SpriteButton* a = NULL;
        a = new SpriteButton;
        a->loadImage("images/wash.png");
        panel->addWidget(a);
    }
    if(level >= 3)
    {
        SpriteButton* a = NULL;
        a = new SpriteButton;
        a->loadImage("images/heal.png");
        panel->addWidget(a);
    }
}

void StateLevel::update()
{
    statWindow->update();
    baby->update();
    if(food)
    {
        food->update();
        if(food->isExhausted())
        {
            delete food;
            food = NULL;
        }
    }
    baby->eat(food);

    // Handle water
    if(waterDir->value == diBOTTOM)
    {
        if(water->getPosition().y < GFX::getInstance()->getHeight())
        {
            Vector2d<float> t = water->getPosition();
            t.y+=1;
            water->setPosition(t);
        }
        else
            waterDir->value = diNONE;

    }
    else if(waterDir->value == diTOP)
    {
        if(water->getPosition().y > 0)
        {
            Vector2d<float> t= water->getPosition();
            t.y-=1;
            water->setPosition(t);
        }
        else
            waterDir->value = diBOTTOM;
    }
    handleActions();

    panel->update();
    quitButton->update();
    creditsButton->update();
    splashButton->update();
    handleButtons(panel->whichWidget());
}

void StateLevel::handleActions()
{
    BABY_ACTIONS action = baby->getAction();
    // If the baby is ready to evolve set the next form
    if(action == ACTION_EVOLVE)
    {
        setupBabyType(baby->getNextForm());
        setupPanel();
    }
    else if(baby->hasLevelChanged())
    {
        // If level changes to 0 this means baby died - we reset
        if(baby->getLevel() == 0 && (baby->getWeight()<0.2f || baby->getHealth()==0))
        {
            setupBabyType("Egg");
            StateMan::getInstance()->setNextState(STATE_TITLE);
        }
        setupPanel();
        baby->setLevelChanged(false);
    }


}

void StateLevel::handleButtons(const int& b)
{
    if(b == 0)
    {
        // check stats
        statWindow->focus();        // Focus the Window
        panel->setShouldHide(true); // Hide the toolbar
    }
    else if(b == 1)
    {
        // feed
        if(food == NULL)
        {
            food = NULL;
            food = new Cheese;
        }
        panel->setShouldHide(true); // Hide the toolbar
    }
    else if(b == 2)
    {
        baby->wash();
        waterDir->value = diTOP;
        panel->setShouldHide(true); // Hide the toolbar
    }
    else if(b == 3)
    {
        baby->heal();
        panel->setShouldHide(true); // Hide the toolbar
    }

    // Check quitButton
    if(quitButton->isActive())
        shouldQuit = true;

    if(creditsButton->isActive())
        StateMan::getInstance()->setNextState(STATE_CREDITS);

    if(splashButton->isActive())
        StateMan::getInstance()->setNextState(STATE_TITLE);
}

void StateLevel::render()
{
    GFX::getInstance()->clear();
    background->render();
    baby->render();
    if(food)
        food->render();
    water->render();

    panel->render();
    statWindow->render();
    quitButton->render();
    if(creditsButton->isMouseSelected())
        creditsButton->render();

    if(splashButton->isMouseSelected())
        splashButton->render();
}

bool StateLevel::babyClicked()
{
    if(!Joy::getInstance()->isLeftClick())
        return false;
    CollisionRegion* r = baby->getCollisionRegion();
    if(r == NULL)
        return false;
    return(r->hitTest(Joy::getInstance()->getMouse()).hasCollided);
}

void StateLevel::input()
{
    if(panel->isHidden())
    {
        if(Joy::getInstance()->isA())
        {
            panel->setShouldHide(false);
            Joy::getInstance()->resetA();
        }
        else if(Joy::getInstance()->isB())
        {
            statWindow->hideWindow();
            Joy::getInstance()->resetB();
        }
        if(Joy::getInstance()->isX() || babyClicked())
        {
            if(baby->getLevel()==0)
                baby->touch();
            Joy::getInstance()->resetX();
        }
        if(Joy::getInstance()->isR() && Joy::getInstance()->isL())
        {
            quitButton->setActive(true);
            Joy::getInstance()->resetR();Joy::getInstance()->resetL();
        }
        if(Joy::getInstance()->isStart() && Joy::getInstance()->isSelect())
        {
            splashButton->setActive(true);
            //Joy::getInstance()->resetSelect();Joy::getInstance()->resetStart();
        }
        if(Joy::getInstance()->isStart() && Joy::getInstance()->isX())
        {
            creditsButton->setActive(true);
            //Joy::getInstance()->resetStart();Joy::getInstance()->resetX();
        }
        if(Joy::getInstance()->getMouse().y < GFX::getInstance()->getHeight() / 48)
        {
            panel->setShouldHide(false);
        }
    }
    else
    {
        if(Joy::getInstance()->isA())
        {
            handleButtons(panel->selectionConfirm());
            Joy::getInstance()->resetA();
        }
        else if(Joy::getInstance()->isB())
        {
            panel->setShouldHide(true);
            Joy::getInstance()->resetB();
        }
        if(Joy::getInstance()->isL())
        {
            panel->selectionPrevious();
            Joy::getInstance()->resetL();
        }
        else if(Joy::getInstance()->isR())
        {
            panel->selectionNext();
            Joy::getInstance()->resetR();
        }
    }
}
