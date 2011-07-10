/**
    \section LICENSE
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
**********************************************************************************************/
/**
  * \file INSERT DECRIPTION HERE
  * \author Kevin Winfield-Pantoja
*/
#include "StateCredits.h"
#include "GFX.h"
//#include "Brad.h"
#include "Timer.h"
//#include "LUT.h"
#include "Text.h"
#include "Sprite.h"
#include "NumberUtility.h"
#include "BackBuffer.h"
#include "LocalisedStringManager.h"
#include "StateManager.h"
#include "StateList.h"

#include "Random.h"

#ifndef PI
#define PI 3.14159265
#endif
using Penjin::StateCredits;
//using Penjin::Brad;
using Penjin::BackBuffer;
using Penjin::Sprite;
using Penjin::Text;
using Penjin::Timer;

StateCredits::StateCredits()
{
    //ctor
}

StateCredits::~StateCredits()
{
    //dtor
}

void StateCredits::init()
{
    //angle = NULL;
    timer = NULL;
    buff = NULL;
    text = NULL;
    sprite = NULL;

    //angle = new Brad;
    timer = new Timer;
    buff = new BackBuffer;

    sprite = new Sprite;
    sprite->load("images/splash/piratebaby.png");
    Vector2d<float>pos = Penjin::GFX::getInstance()->getResolution() - sprite->getDimensions();
    pos = pos *0.5f;
    sprite->setPosition(pos);

    text = new Text;
    text->load("fonts/unispace.ttf",10);
    text->setRenderMode(GlyphClass::NICE);
    text->setRelativity(false);
    //text->setWrapping(false);
    text->setColour(DARK_GREY);

    Text* tx = TextMan::getInstance();
    tx->setColour(LIGHT_GREY);
    tx->setRelativity(false);
    //tx->setWrapping(false);
    tx->setRenderMode(GlyphClass::NICE);


    //text->setWrapping(false);
    Vector2d<float> pxScale = Penjin::GFX::getInstance()->getPixelScale();
    pos.y += sprite->getHeight();
    pos.y = pos.y/pxScale.y;

    text->setPosition(pos);
    tx->setPosition(pos - Vector2d<float>(2,2));

    timer->setMode(SECONDS);
    timer->start();
    //angle->setAngleDegrees(0);
    angle = 0.0f;
    //LUT::init();
    current=0;
}

void StateCredits::input()
{

}

void StateCredits::update()
{
    if(current >= 14)
        StateMan::getInstance()->setNextState(STATE_TITLE);

    if(timer->getScaledTicks()>4)
    {
        ++current;
        timer->start();
    }
    angle++;
    angle = NumberUtility::wrapValue(angle,359.0f);
}

void StateCredits::render()
{
    buff->setPosition(Vector2d<float>(0,0));
    Renderer* gfx = GFX::getInstance();

    unsigned char red,green,blue;
    float scale = 240.0f/180.0f;
    //for(unsigned int y = 0; y<gfx->getHeight(); ++y)
        float deg = angle*PI/180.0f;
        red = 128;
        green =0;//(LUT::Lsin(*angle + 1)+1);
        blue = 0;
        gfx->setDrawWidth(6);
        gfx->setDrawColour(Colour(red,green,blue));
        Vector2d<float> vec;
        vec.x = angle;
        vec.x *= scale;
        vec.y = sin(deg)*90.0f;//LUT::Lsin(*angle)*10;
        vec.y += gfx->getHeight()*0.5f;
        gfx->drawPixel(vec);

        vec.y = cos(deg)*60.0f;//LUT::Lsin(*angle)*10;
        vec.y += gfx->getHeight()*0.5f;
        red =0;
        green=128;
        gfx->setDrawColour(Colour(red,green,blue));
        gfx->drawPixel(vec);

        vec.x = angle;
        scale = scale/2;
        vec.x *= scale;
        vec.x = gfx->getWidth()-vec.x;
        vec.y = cos(deg)*100.0f;//LUT::Lsin(*angle)*10;
        vec.y += gfx->getHeight()*0.5f;
        blue =128;
        green=0;
        gfx->setDrawColour(Colour(red,green,blue));
        gfx->drawPixel(vec);
        //gfx->drawLine(Vector2d<float>(0,angle->getAngle()),Vector2d<float>(gfx->getWidth(),angle->getAngle()));

        sprite->render();

        printText();

	buff->update();
	buff->setAlpha(35);
	//Penjin::GFX::getInstance()->clear();

	buff->setPosition(Vector2d<float>(sin(deg)*1.5f,cos(deg)*1.2f));
	buff->render();
}

void StateCredits::printText()
{
    // create shorthand for LSM
    Penjin::LocalisedStringManager* lsm = LocaleMan::getInstance();
    Text* tx = TextMan::getInstance();

    string section="StateCredits";


    //  Render localised text
    if(current == 0)
    {
        text->print(lsm->getValue(section,"CREDITS", "CREDITS!"));
        tx->print(lsm->getValue(section,"CREDITS", "CREDITS!"));
    }
    else if(current == 1)
    {
        text->print(lsm->getValue(section,"PirateBaby", "PirateBaby"));
        tx->print(lsm->getValue(section,"PirateBaby", "PirateBaby"));
    }
    else if(current == 2)
    {
        text->print(lsm->getValue(section,"GameBy", "By PokeParadox"));
        tx->print(lsm->getValue(section,"GameBy", "By PokeParadox"));
    }

    else if(current == 3)
    {
        text->print(lsm->getValue(section,"ArtBy", "Art by Dragons_Slayer"));
        tx->print(lsm->getValue(section,"ArtBy", "Art by Dragons_Slayer"));
    }
    else if(current == 4)
    {
        text->print(lsm->getValue(section,"Penjin", "PenjinTwo"));
        tx->print(lsm->getValue(section,"Penjin", "PenjinTwo"));
    }
    else if(current == 5)
    {
        text->print(lsm->getValue(section,"PenjinBy", "By PokeParadox"));
        tx->print(lsm->getValue(section,"PenjinBy", "By PokeParadox"));
    }
    else if(current == 6)
    {
        text->print(lsm->getValue(section,"ThanksTo", "With thanks to:"));
        tx->print(lsm->getValue(section,"ThanksTo", "With thanks to:"));
    }
    else if(current == 7)
    {
        text->print(lsm->getValue(section,"Sebt3", "Sebt3"));
        tx->print(lsm->getValue(section,"Sebt3", "Sebt3"));
    }
    else if(current == 8)
    {
        text->print(lsm->getValue(section,"BAFelton61", "BAFelton61"));
        tx->print(lsm->getValue(section,"BAFelton61", "BAFelton61"));
    }
    else if(current == 9)
    {
        text->print(lsm->getValue(section,"Torpor", "Torpor"));
        tx->print(lsm->getValue(section,"Torpor", "Torpor"));
    }
    else if(current == 10)
    {
        text->print(lsm->getValue(section,"kayuz", "kayuz"));
        tx->print(lsm->getValue(section,"kayuz", "kayuz"));
    }
    else if(current == 11)
    {
        text->print(lsm->getValue(section,"PirateGames", "Presented by Pirate Games"));
        tx->print(lsm->getValue(section,"PirateGames", "Presented by Pirate Games"));
    }
    else if(current == 12)
    {
        text->print(lsm->getValue(section,"CopyRight", "(c)2011, All rights reserved."));
        tx->print(lsm->getValue(section,"CopyRight", "(c)2011, All rights reserved."));
    }
    else if(current == 13)
    {
        text->print(lsm->getValue(section,"Thanks", "Thanks for watching!"));
        tx->print(lsm->getValue(section,"Thanks", "Thanks for watching!"));
    }
}

void StateCredits::clear()
{
//    delete angle;
    delete timer;
    delete buff;
    delete text;
    delete sprite;
    timer = NULL;
    buff = NULL;
    text = NULL;
    sprite = NULL;

    if(LocaleMan::getInstance()->hasChanged())
        LocaleMan::getInstance()->save();
//    LUT::deInit();
}
