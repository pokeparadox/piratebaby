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
#include "Sprite.h"
#include "Timer.h"
#include "StringUtility.h"
using Penjin::Baby;
using Penjin::Sprite;
using Penjin::Timer;

Baby::Baby() :  action(ACTION_IDLE),intelligence(1),hunger(90),cleanliness(10), strength(0), weight(0.2f),
sprActive(NULL), sprIdle(NULL), sprJump(NULL), sprdance(NULL), sprWalkLeft(NULL), sprWalkRight(NULL), sprEat(NULL),
timer(NULL)
{
    //ctor
    Penjin::ERRORS e = load(DEFAULT_BABY_SAVE);

    sprIdle = new Sprite;
    sprJump = new Sprite;
    sprdance = new Sprite;
    sprWalkLeft = new Sprite;
    sprWalkRight = new Sprite;
    sprEat = new Sprite;

    string section = "Status";
    age = StringUtility::stringToInt(  getValue(section, "Age", "0")   );
    intelligence = StringUtility::stringToInt( getValue(section,"Intelligence", "1"));
    weight = StringUtility::stringToFloat( getValue(section, "Weight","0.2") );
    hunger = StringUtility::stringToInt( getValue(section,"Hunger", "90"));
    cleanliness = StringUtility::stringToInt( getValue(section,"Cleanliness", "10"));
    stringToAction(getValue(section, "Action","ACTION_IDLE"));
    if(hasChanged())
        save(DEFAULT_BABY_SAVE);
    timer = new Timer;
    timer->setMode(SECONDS);
    timer->start();
}

Baby::~Baby()
{
    //dtor
    sprActive=NULL;
    delete sprIdle;
    delete sprJump;
    delete sprdance;
    delete sprWalkLeft;
    delete sprWalkRight;
    delete sprEat;
    string section = "Status";
    setValue(section, "Age", StringUtility::intToString(age));
    setValue(section, "Intelligence", StringUtility::intToString(intelligence) );
    setValue(section, "Weight", StringUtility::floatToString(weight) );
    setValue(section, "Hunger", StringUtility::intToString(hunger) );
    setValue(section, "Action", actionToString());
    if(hasChanged())
        save(DEFAULT_BABY_SAVE);
}

string Baby::actionToString()
{
    if(action == ACTION_IDLE)
        return "ACTION_IDLE";
    else if(action == ACTION_EAT)
        return "ACTION_EAT";
    else if(action == ACTION_DANCE)
        return "ACTION_DANCE";
    else if(action == ACTION_JUMP)
        return "ACTION_JUMP";
    else if(action == ACTION_BLINK)
        return "ACTION_BLINK";
    else if(action == ACTION_SLEEP)
        return "ACTION_SLEEP";
    else if(action == ACTION_WAKE)
        return "ACTION_WAKE";
    else if(action == ACTION_EVOLVE)
        return "ACTION_EVOLVE";

    return "ACTION_NONE";
}

void Baby::stringToAction(const string& s)
{
    if(s == "ACTION_IDLE")
        action = ACTION_IDLE;
    else if(s == "ACTION_EAT")
        action = ACTION_EAT;
    else if(s == "ACTION_DANCE")
        action = ACTION_DANCE;
    else if(s == "ACTION_JUMP")
        action = ACTION_JUMP;
    else if(s == "ACTION_BLINK")
        action = ACTION_BLINK;
    else if(s == "ACTION_SLEEP")
        action = ACTION_SLEEP;
    else if(s == "ACTION_WAKE")
        action = ACTION_WAKE;
    else if(s == "ACTION_EVOLVE")
        action = ACTION_EVOLVE;
    else
        action = ACTION_NONE;
}

void Baby::render()
{
    sprActive->render();
}


void Baby::update()
{
    if(timer->getScaledTicks() >= 1)
    {
        ++age;
        timer->start();
    }
    //switchAction(nextAction);
    sprActive->setPosition(position);
    sprActive->update();
}

void Baby::switchAction(const BABY_ACTIONS& a)
{
    if(a != action)
    {
        if(a == ACTION_IDLE)
        {
            sprIdle->setPosition(sprActive->getPosition());
            sprActive = sprIdle;
        }
        else if(a == ACTION_EAT)
        {
            sprEat->setPosition(sprActive->getPosition());
            sprActive = sprEat;
        }
        action = a;
    }
}

void Baby::evolve()
{

}

void Baby::setAge(const int & a)
{
    age = a;
}

int Baby::getAge()
{
    return age;
}

int Baby::getLevel()
{
    return level;
}

float Baby::getWeight()
{
    return weight;
}

int Baby::getHunger()
{
    return hunger;
}

int Baby::getIntelligence()
{
    return intelligence;
}

void Baby::eat(Food* food)
{
    return;
}
