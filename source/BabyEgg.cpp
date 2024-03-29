/**
	\section LICENSE
	PirateBaby is Copyright (c)2011 Kevin Winfield-Pantoja

	This file is part of PirateBaby.

	PirateBaby is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	PirateBaby is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with PirateBaby.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "BabyEgg.h"
#include "Sprite.h"
#include "GFX.h"
using Penjin::BabyEgg;
using Penjin::Sprite;


BabyEgg::BabyEgg()
{
    sprIdle->clear();
    sprIdle->load("images/egg.png",4,1);
    sprIdle->setPlayMode(pmPulse);
    sprIdle->setLooping(true);
    Vector2d<int> dim = GFX::getInstance()->getResolution();
    dim.x = dim.x / 2.5f;
    dim.y = dim.y / 2.25f;
    sprIdle->setPosition(dim);
    position = dim;
    action = ACTION_IDLE;
    sprActive = sprIdle;
    touchCount = 0;
}

BabyEgg::~BabyEgg()
{
    //dtor
}


void BabyEgg::update()
{
    Baby::update();
    if(action == ACTION_BLINK)
    {
        sprActive->update();
        if(sprActive->hasFinished())
            action=ACTION_IDLE;
    }
    else if( action == ACTION_IDLE)
    {
        sprActive->rewind();
        if(age == 60 || age == 120 || age == 180)
        {
            action=ACTION_BLINK;// Egg wobbling is kind of like blinking... right?
            sprActive->setLooping(1);
            weight+=0.12f;
        }
        else if(age == 240 || age == 300)
        {
            action=ACTION_BLINK;// Egg wobbling is kind of like blinking... right?
            sprActive->setLooping(2);
            ++intelligence;
        }
        else if(age == 360 || age == 420 || age == 480)
        {
            action=ACTION_BLINK;// Egg wobbling is kind of like blinking... right?
            sprActive->setLooping(3);
            weight+=0.05f;
        }
        else if(age == 540 || age == 600)
        {
            action=ACTION_BLINK;// Egg wobbling is kind of like blinking... right?
            sprActive->setLooping(5);
            intelligence++;
        }
        else if(age > 600 || touchCount > 20)
        {
            action=ACTION_EVOLVE;
            evolve();
        }
    }
}

void BabyEgg::evolve()
{
    // Setup evolve animation
    sprActive->clear();
}


string BabyEgg::getNextForm()
{
    level = 1;
    if(age<300|| touchCount > 20)
    {
        return "Blob";
    }
    return "EggBaby";
}
