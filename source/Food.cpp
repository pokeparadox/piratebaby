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
#include "Food.h"
#include "Random.h"
#include "GFX.h"
#include "Vector2d.h"
using Penjin::Food;
using Penjin::Vector2d;

Food::Food() : cNutrition(0), cWeight(0), cWaste(0), onFloor(false)
{
    //ctor
    Vector2d<int> dim = GFX::getInstance()->getResolution();
    position.x = Penjin::Random::nextInt(0,dim.x-dimensions.x);
    floorLevel = dim.y*0.65f;
}

Food::~Food()
{
    //dtor
}

bool Food::isExhausted()
{
    return(cNutrition>=nutrition && cWeight>=weight && cWaste>= waste);
}

bool Food::isOnFloor()
{
    return onFloor;
}

int Food::getNutrition()
{
    return nutrition;
}

float Food::getWeight()
{
    return weight;
}

int Food::getWaste()
{
    return waste;
}

void Food::update()
{
    Sprite::update();
    if(position.y < floorLevel)
        position.y+=2;
    else
        onFloor = true;
}

