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
*/
/***************************************************************************************************
*   \file Baby is the base class for the development of a baby in PirateBaby
*   \author Kevin Winfield-Pantoja
*/

#include "Baby.h"
#include "AnimatedSprite.h"
using Penjin::Baby;
using Penjin::AnimatedSprite;

Baby::Baby() : sprite(NULL)
{
    //ctor
    sprite = new AnimatedSprite;
}

Baby::~Baby()
{
    //dtor
    delete sprite;
}

void Baby::render()
{
    if(sprite)
        sprite->render();
}


void Baby::update()
{
    if(sprite)
        sprite->update();
}


void Baby::evolve()
{

}
