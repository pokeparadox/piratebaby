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
#include "BabyEggBaby.h"
#include "Sprite.h"
using Penjin::BabyEggBaby;
using Penjin::Sprite;

BabyEggBaby::BabyEggBaby()
{
    //ctor
    sprite->clear();
    sprite->load("images/eggbaby.png",4,1);
    sprite->setPlayMode(pmPulse);
    sprite->setLooping(1);
    Vector2d<int> dim = GFX::getInstance()->getDimensions();
    dim.x = dim.x / 2.5f;
    dim.y = dim.y / 2.25f;
    sprite->setPosition(dim);
    action = ACTION_IDLE;
    level = 1;
}

BabyEggBaby::~BabyEggBaby()
{
    //dtor
}
