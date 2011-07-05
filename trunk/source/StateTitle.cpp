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
/***************************************************************************************************
*   \file StateTitle is a GameState to show the Title screen.
*/

#include "StateTitle.h"
#include "GFX.h"
#include "SimpleJoy.h"
#include "StateManager.h"
#include "MyStateList.h"
#include "Timer.h"
#include "Sprite.h"
#include "Text.h"
#include "BackBuffer.h"
#include "LocalisedStringManager.h"
using Penjin::StateTitle;
using Penjin::Timer;
using Penjin::SimpleJoy;
using Penjin::Sprite;
using Penjin::Text;
using Penjin::BackBuffer;

StateTitle::StateTitle() : timer(NULL), current(0), text(NULL), buff(NULL)
{
    //ctor
}

void StateTitle::init()
{
    timer = new Timer;
    timer->setMode(SECONDS);
    current = 0;

    text = new Text;
    text->load("fonts/unispace.ttf",11);
    //text->setAlignment(TextClass::CENTRED);
    text->setColour(LIGHT_GREY);
    text->setRelativity(false);

    setupSplashes();

    buff = new BackBuffer;

    Penjin::GFX::getInstance()->setClearColour(Colour(0,0,0));
    timer->start();
}

void StateTitle::setupSplashes()
{
    const string path = "images/splash/";

    // Pirate Games Splash
    Sprite* t = NULL;
    t = new Sprite;
    t->load(path+"pirategames.png");
    Vector2d<float> pos;
    pos = Penjin::GFX::getInstance()->getResolution() - t->getDimensions();
    pos = pos *0.5f;
    t->setPosition(pos);
    splashes.push_back(t);

    // Penjin Powered
    t = NULL;
    t = new Sprite;
    t->load(path+"penjin.png");
    pos = Penjin::GFX::getInstance()->getResolution() - t->getDimensions();
    pos = pos *0.5f;
    t->setPosition(pos);
    splashes.push_back(t);

    #if defined (PLATFORM_PANDORA) || defined(PLATFORM_PC)
        // OpenPandora
        t = NULL;
        t = new Sprite;
        t->load(path+"pandora.png");
        pos = Penjin::GFX::getInstance()->getResolution() - t->getDimensions();
        pos = pos *0.5f;
        t->setPosition(pos);
        splashes.push_back(t);
    #endif

    // RIOTdigital
    t = NULL;
    t = new Sprite;
    t->load(path+"riot01.png");
    pos = Penjin::GFX::getInstance()->getResolution() - t->getDimensions();
    pos = pos *0.5f;
    t->setPosition(pos);
    splashes.push_back(t);

    t = NULL;
    t = new Sprite;
    t->load(path+"riot02.png");
    pos = Penjin::GFX::getInstance()->getResolution() - t->getDimensions();
    pos = pos *0.5f;
    t->setPosition(pos);
    splashes.push_back(t);
}

void StateTitle::clear()
{
    delete timer;
    timer = NULL;
    delete text;
    text = NULL;
    delete buff;
    buff = NULL;

    for(int i = splashes.size()-1;i>=0;--i)
    {
        delete splashes.at(i);
        splashes.at(i) = NULL;
    }
    splashes.clear();
}

StateTitle::~StateTitle()
{
    //dtor
    clear();
}

void StateTitle::render()
{
    // render current splash
    if(timer->getScaledTicks() < 2)
    {
        if(current<splashes.size())
            splashes.at(current)->render();
    }

    printText();


	buff->update();
	buff->setAlpha(253);
	Penjin::GFX::getInstance()->clear();
	buff->render();
}

void StateTitle::printText()
{
    // create shorthand for LSM
    Penjin::LocalisedStringManager* lsm = LocaleMan::getInstance();
    string section="StateTitleSplash";
    Text* t = text;
    t->setPosition(Vector2d<float>(2,160));
    //  Render localised text
    if(current == 0)
        t->print(lsm->getValue(section,"PirateGames", "Pirate Games 2011"));
    else if(current == 1)
        t->print(lsm->getValue(section,"PenjinTwo", "Using PenjinTwo."));
#if defined (PLATFORM_PANDORA) || defined(PLATFORM_PC)
    else if(current == 2)
        t->print(lsm->getValue(section,"OpenPandora", "On OpenPandora."));
    else if(current == 3)
        t->print(lsm->getValue(section,"RIOTdigital", "For RIOTdigital."));
    else if(current == 4)
        t->print(lsm->getValue(section,"SponsoredBy", "Sponsored by:"));
#else
    else if(current == 2)
        t->print(lsm->getValue(section,"RIOTdigital", "For RIOTdigital."));
    else if(current == 3)
        t->print(lsm->getValue(section,"SponsoredBy", "Sponsored by:"));
#endif
}

void StateTitle::update()
{
    if(timer->getScaledTicks() >= 4)
    {
        ++current;
        // reset timer
        timer->start();
    }

    if(current >= splashes.size())
    {
        StateMan::getInstance()->setNextState(STATE_LEVEL);
    }
}

void StateTitle::input()
{
    SimpleJoy* j = Joy::getInstance();
    if(j->isA() || j->isX() || j->isB() || j->isLeftClick())
    {
        ++current;
        j->resetKeys();
    }
}
