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
#include "QuitButton.h"
#include "GFX.h"
using Penjin::QuitButton;

QuitButton::QuitButton()
{
    //ctor
    setColour(RED);
}

QuitButton::~QuitButton()
{
    //dtor
}

void QuitButton::render()
{
    Button::render();

    Renderer* gfx = GFX::getInstance();
    gfx->setDrawColour(WHITE);
    Vector2d<float> pos = getScaledPosition();
    Vector2d<float> dim = getScaledDimensions();
    pos.x+=2;
    pos.y+=2;
    dim.x-=4;
    dim.y-=4;

    gfx->drawLine(pos,pos+dim);
    gfx->drawLine(Vector2d<float>(pos.x,pos.y+dim.y), Vector2d<float>(pos.x+dim.x,pos.y));
}
