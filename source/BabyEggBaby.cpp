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
/**
  * \file A semi-hatched EggBaby
  * \author Kevin Winfield-Pantoja
*/
#include "BabyEggBaby.h"
#include "Sprite.h"
using Penjin::BabyEggBaby;
using Penjin::Sprite;

BabyEggBaby::BabyEggBaby()
{
    //ctor
    sprIdle->clear();
    sprIdle->load("images/eggbaby.png",4,1);
    sprIdle->setPlayMode(pmNormal);
    sprIdle->setFramesPerSecond(5);
    sprIdle->setLooping(true);

    sprEat->clear();
    sprEat->load("images/eggbabyeat.png",4,1);
    sprEat->setPlayMode(pmPulse);
    sprEat->setLooping(true);

    sprWalkLeft->clear();
    sprWalkLeft->load("images/eggbabywalkleft.png",4,1);
    sprWalkLeft->setPlayMode(pmNormal);
    sprWalkLeft->setLooping(true);


    sprWalkRight->clear();
    sprWalkRight->load("images/eggbabywalkright.png",4,1);
    sprWalkRight->setPlayMode(pmNormal);
    sprWalkRight->setLooping(true);


    Vector2d<int> dim = GFX::getInstance()->getResolution();
    dim.x = dim.x / 2.5f;
    dim.y = dim.y / 2.25f;
    sprIdle->setPosition(dim);
    action = ACTION_IDLE;
    sprActive = sprIdle;
}

BabyEggBaby::~BabyEggBaby()
{
    //dtor
}

void BabyEggBaby::render()
{
    BabyBlob::render();
}

void BabyEggBaby::update()
{
    BabyBlob::update();
}
