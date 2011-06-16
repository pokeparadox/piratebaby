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
//#include "Rectangle.h"
//#include "AnimatedSprite.h"
using Penjin::StateTitle;
//using Penjin::Rectangle;
using Penjin::SimpleJoy;
//using Penjin::AnimatedSprite;

StateTitle::StateTitle()
{
    //ctor
}

void StateTitle::init()
{
        Penjin::GFX::getInstance()->setClearColour(Colour(0,0,255));
    //Penjin::GFX::getInstance()->setDrawWidth(5);
/*rect = new Rectangle;
    rect->setColour(RED);
    rect->setDrawWidth(10);
    rect->setPosition(Vector2d<float>(50,50));
    rect->setWidth(200);
    rect->setHeight(200);*/

  /*  egg = NULL;
    egg = new AnimatedSprite;
    egg->loadFrames("images/egg.png",4,1);
    Vector2d<int> pos = GFX::getInstance()->getDimensions();
    Vector2d<int> offset;
    offset.x = egg->getWidth()*0.5;
    offset.y = egg->getHeight()*0.5;
    pos.x = pos.x*0.5f-offset.x;
    pos.y = pos.y*0.5f+offset.y;
    egg->setPosition(pos);
    egg->setFrameRate(FIFTEEN_FRAMES);*/
}

void StateTitle::clear()
{
    //delete rect;
    //delete egg;
}

StateTitle::~StateTitle()
{
    //dtor
    clear();
}

void StateTitle::render()
{
    //  Clear the screen
    Penjin::GFX::getInstance()->clear();
    //egg->render();
    //  Queue rectangle in displaylist.
    //rect->queueRender();
    //Penjin::GFX::getInstance()->drawPixel(Vector2d<float> (50,50));
   // Penjin::GFX::getInstance()->drawPixel(Vector2d<float> (51,50));
   // Penjin::GFX::getInstance()->drawPixel(Vector2d<float> (52,50));

   // Penjin::GFX::getInstance()->drawRectangle(Vector2d<float> (0,0), Vector2d<int> (20,20));
}

void StateTitle::update()
{
    //egg->update();
}

void StateTitle::input()
{
    if(Joy::getInstance()->isA())
    {
        Penjin::StateMan::getInstance()->setNextState(STATE_LEVEL);
        Joy::getInstance()->resetA();
    }
}
