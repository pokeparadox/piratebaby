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
#include "Sprite.h"
#include "Baby.h"
#include "BabyEgg.h"
using Penjin::StateLevel;
using Penjin::Panel;
using Penjin::Button;
using Penjin::SpriteButton;
using Penjin::Sprite;
using Penjin::Baby;
using Penjin::BabyEgg;

#ifdef DEBUG
    #include <iostream>
    using namespace std;
#endif

StateLevel::StateLevel() : baby(NULL), panel(NULL), background(NULL)
{
    //ctor
    Penjin::GFX::getInstance()->setClearColour(Colour(255,255,255));

    // Load list of babies and general settings
    load(BABY_LIST);
    string section = "Baby01";

    // now we setup the correct baby object based on the type detected.
    setupBabyType(getValue(section,"Type","Egg"));

    if(hasChanged())
        save(BABY_LIST);

    // Now setup the GUI
    panel = new Panel;
    Widget* a = NULL;
    Widget* b = NULL;
    a = new Button;
    //a->loadImage("images/feed.png");
    panel->addWidget(a);
    b = NULL;
    b = new Button;
    panel->addWidget(b);

    // prepare the background
    background = new Image;
    background->load("images/background.png");
}

StateLevel::~StateLevel()
{
    if(hasChanged())
        save(BABY_LIST);
    delete baby;
    delete panel;
    delete background;
}

void StateLevel::setupBabyType(const string& t)
{
    delete baby;
    baby = NULL;
    if(t == "" || t == "Egg")
        baby = new BabyEgg;
}

void StateLevel::update()
{
    baby->update();
    panel->update();
    handleButtons(panel->whichWidget());
}

void StateLevel::handleButtons(const int& b)
{
    if(b == 0)
    {
        // Give food
    }
    else if(b == 1)
    {
        // Wash
    }
}

void StateLevel::render()
{
    GFX::getInstance()->clear();
    background->render();
    baby->render();
    panel->render();
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
        if(Joy::getInstance()->getMouse().y < GFX::getInstance()->getHeight() / 90)
        {
            panel->setShouldHide(false);
        }
    }
    else
    {
        if(Joy::getInstance()->isA())
        {
            panel->selectionConfirm();
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