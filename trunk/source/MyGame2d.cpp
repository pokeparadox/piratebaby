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
#include "MyGame2d.h"
#include "MyStateList.h"
#include "StateTitle.h"
#include "StateLevel.h"
#include "StateCredits.h"
#include "GFX.h"
using Penjin::MyGame2d;
using Penjin::StateTitle;
using Penjin::StateLevel;

MyGame2d::MyGame2d()
{
    //ctor
    // This ensure that the correct base resolution is set.
    Penjin::GFX::getInstance()->setBaseResolution(Vector2d<int>(240,180));

    Penjin::StateManager* sm = Penjin::StateMan::getInstance();
    sm->addState(STATE_TITLE, new StateTitle);
    sm->addState(STATE_LEVEL, new StateLevel);
    sm->addState(STATE_CREDITS, new StateCredits);
    sm->setNextState(STATE_TITLE);
    sm->stateManagement();
}

MyGame2d::~MyGame2d()
{
    //dtor
}
