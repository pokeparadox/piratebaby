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
#include "BabyEgg.h"
#include "AnimatedSprite.h"
#include "GFX.h"
using Penjin::BabyEgg;
using Penjin::AnimatedSprite;


BabyEgg::BabyEgg()
{
    sprite->loadFrames("images/egg.png",4,1);
    sprite->setPlayMode(pmPulse);
    sprite->setLooping(1);
    Vector2d<int> dim = GFX::getInstance()->getDimensions();
    dim.x = dim.x / 2.5f;
    dim.y = dim.y / 2.25f;
    sprite->setPosition(dim);
    action = ACTION_IDLE;
    level = 0;
}

BabyEgg::~BabyEgg()
{
    //dtor
}


void BabyEgg::update()
{
    if(action == ACTION_BLINK)
    {
        sprite->update();
        if(sprite->hasFinished())
            action=ACTION_IDLE;
    }
    else
    {
        sprite->rewind();
        if(age == 60 || age == 120 || age == 180)
        {
            action=ACTION_BLINK;// Egg wobbling is kind of like blinking... right?
            sprite->setLooping(1);
        }
        else if(age == 240 || age == 300)
        {
            action=ACTION_BLINK;// Egg wobbling is kind of like blinking... right?
            sprite->setLooping(2);
        }
        else if(age == 360 || age == 420 || age == 480)
        {
            action=ACTION_BLINK;// Egg wobbling is kind of like blinking... right?
            sprite->setLooping(3);
        }
        else if(age == 540 || age == 600)
        {
            action=ACTION_BLINK;// Egg wobbling is kind of like blinking... right?
            sprite->setLooping(5);
        }
    }

}
