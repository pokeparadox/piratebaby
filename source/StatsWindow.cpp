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

#include "StatsWindow.h"
#include "Button.h"
#include "Baby.h"
#include "Text.h"
#include "LocalisedStringManager.h"

using Penjin::StatsWindow;
using Penjin::Widget;
using Penjin::Baby;
using Penjin::Text;

StatsWindow::StatsWindow() : baby(NULL), window(NULL), text(NULL)
{
    //ctor
    hidden = true;
    setDimensions(Penjin::GFX::getInstance()->getDimensions() * 0.8f);
    setPosition((Penjin::GFX::getInstance()->getDimensions() - dimensions) *0.5f);

    window = new Button;
    window->setPosition(position);
    window->setDimensions(dimensions);
    window->a = 128;

    text = new Text;
    text->load("fonts/unispace.ttf",8);
    text->setColour(BLACK);
    text->setRelativity(true);
    text->setWrapping(false);
    text->setPosition(position + Vector2d<float>(2,2));
    text->setCursorPosition(position + Vector2d<float>(2,2));
    text->setDimensions(dimensions);
}

StatsWindow::~StatsWindow()
{
    //dtor
    delete window;
    delete text;
}

void StatsWindow::setBaby(Baby* b)
{
    baby = b;
}

void StatsWindow::render()
{
    if(hidden)
        return;
    // Render Button as the window area
    window->render();
    text->setCursorPosition(position + Vector2d<float>(2,2));
    if(baby)
    {
        // Level 00
        string section="StatsWindow";
        text->print(    LocaleMan::getInstance()->getValue(section,"Title","Baby Stats.") +"\n\n"   );
        text->print(    LocaleMan::getInstance()->getValue(section,"Age","Age") + ":"   ); text->print(baby->getAge()/600); text->print("\n");
        int level = baby->getLevel();
        text->print(    LocaleMan::getInstance()->getValue(section,"Level","Level") + ":"); text->print(level);text->print("-");
        if(level == 0)
            text->print(LocaleMan::getInstance()->getValue(section,"Patience","Patiance")    +"." );
        else if(level == 1)
            text->print(LocaleMan::getInstance()->getValue(section,"Nutrition","Nutrition")    +"." );
        text->print("\n");


        text->print("Intelligence:"); text->print(baby->getIntelligence()); text->print("\n");
        text->print("Weight:"); text->print(baby->getWeight()); text->print("\n");
        // Level 01
        if(level>=1)
        {
            text->print("Hunger:"); text->print(baby->getHunger()); text->print("\n");
        }

    }
    if(LocaleMan::getInstance()->hasChanged())
        LocaleMan::getInstance()->save();
}

void StatsWindow::update()
{
    if(!hidden)
    {
        if(window->isActive())
            hidden = true;
    }
}
