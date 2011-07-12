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
/***************************************************************************************************
*   \file Baby is the base class for the development of a baby in PirateBaby
*   \author Kevin Winfield-Pantoja
*/

#include "Baby.h"
#include "Sprite.h"
#include "Timer.h"
#include "StringUtility.h"
#include "SimpleJoy.h"
#include "CollisionRegion.h"
using Penjin::Baby;
using Penjin::Sprite;
using Penjin::Timer;
using Penjin::CollisionRegion;

Baby::Baby() :  action(ACTION_IDLE), touchCount(0) ,intelligence(1),hunger(90),hygiene(10), toilet(20),strength(0), weight(0.2f),levelChanged(true),
sprActive(NULL), sprIdle(NULL), sprJump(NULL), sprdance(NULL), sprWalkLeft(NULL), sprWalkRight(NULL), sprEat(NULL),
timer(NULL)
{
    //ctor
    loadStats();

    sprIdle = new Sprite;
    sprJump = new Sprite;
    sprdance = new Sprite;
    sprWalkLeft = new Sprite;
    sprWalkRight = new Sprite;
    sprEat = new Sprite;


    timer = new Timer;
    timer->setMode(SECONDS);
    timer->start();
}

void Baby::loadStats()
{
    Penjin::ERRORS e = load(DEFAULT_BABY_SAVE);
    string section = "Status";
    age = StringUtility::stringToInt(  getValue(section, "Age", "0")   );
    level = StringUtility::stringToInt(  getValue(section, "Level", "0")   );
    intelligence = StringUtility::stringToInt( getValue(section,"Intelligence", "1"));
    weight = StringUtility::stringToFloat( getValue(section, "Weight","0.2") );
    hunger = StringUtility::stringToInt( getValue(section,"Hunger", "90"));
    health = StringUtility::stringToInt( getValue(section,"Health", "50"));
    hygiene = StringUtility::stringToInt( getValue(section,"Hygiene", "10"));
    toilet = StringUtility::stringToInt( getValue(section,"Toilet", "20"));
    strength = StringUtility::stringToInt( getValue(section,"Strength", "10"));
    stringToAction(getValue(section, "Action","ACTION_IDLE"));
    if(hasChanged())
        save(DEFAULT_BABY_SAVE);
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
    saveData();
}

void Baby::saveData()
{
    string section = "Status";
    setValue(section, "Age", StringUtility::intToString(age));
    setValue(section, "Level", StringUtility::intToString(level));
    setValue(section, "Intelligence", StringUtility::intToString(intelligence) );
    setValue(section, "Weight", StringUtility::floatToString(weight) );
    setValue(section, "Hunger", StringUtility::intToString(hunger) );
    setValue(section, "Health", StringUtility::intToString(health) );
    setValue(section, "Hygiene", StringUtility::intToString(hygiene) );
    setValue(section, "Toilet", StringUtility::intToString(toilet) );
    setValue(section, "Strength", StringUtility::intToString(strength) );

    setValue(section, "Action", actionToString());
    if(hasChanged())
        save(DEFAULT_BABY_SAVE);
}

void Baby::defaultConfig()
{
    string section = "Status";
    setValue(section, "Age", "0");
    age = 0;
    setValue(section, "Level", "0");
    level = 0;
    setValue(section, "Intelligence", "0" );
    intelligence = 0;
    setValue(section, "Weight", "0.2" );
    weight = 0;
    setValue(section, "Hunger", "90" );
    hunger = 90;
    setValue(section, "Health", "50");
    health = 50;
    setValue(section, "Hygiene", "10");
    hygiene = 10;
    setValue(section, "Toilet", "20");
    toilet = 20;
    setValue(section, "Strength", "10");
    strength = 10;
    action = ACTION_IDLE;
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
    else if(action == ACTION_POOP)
        return "ACTION_POOP";
    else if(action == ACTION_ILL)
        return "ACTION_ILL";
    else if(action == ACTION_DIE)
        return "ACTION_DIE";
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
    else if(s == "ACTION_POOP")
        action = ACTION_POOP;
    else if(s == "ACTION_ILL")
        action = ACTION_ILL;
    else if(s == "ACTION_DIE")
        action = ACTION_DIE;
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
    // aging
    if(timer->getScaledTicks() >= 1)
    {
        ++age;
        timer->start();
    }
    // Animations
    sprActive->setPosition(position);
    sprActive->update();
}

void Baby::touch()
{
    // User touch
    ++touchCount;
    switchAction(ACTION_BLINK);
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
        else if(a == ACTION_WALK_LEFT)
        {
            sprWalkLeft->setPosition(sprActive->getPosition());
            sprActive = sprWalkLeft;
        }
        else if(a == ACTION_WALK_RIGHT)
        {
            sprWalkRight->setPosition(sprActive->getPosition());
            sprActive = sprWalkRight;
        }
        else if(a == ACTION_POOP)
        {
            sprJump->setPosition(sprActive->getPosition());
            sprActive = sprJump;
            // Introduce washing Button at level 2
            if(level<=1)
            {
                level = 2;
                levelChanged = true;
            }
        }
        else if(a == ACTION_ILL)
        {
            //sprJump->setPosition(sprActive->getPosition());
            //sprActive = sprJump;
            // Introduce washing Button at level 2
            if(level<=2)
            {
                level = 3;
                levelChanged = true;
            }
        }
        else if(a == ACTION_DIE)
        {
            //sprJump->setPosition(sprActive->getPosition());
            //sprActive = sprJump;
            // Introduce washing Button at level 2

                defaultConfig();
                levelChanged = true;
        }
        action = a;
    }
}

void Baby::wash()
{
    hygiene = 100;
}

void Baby::heal()
{
    if(timer->getTicks()>500)
        health+=10;
    if(health>100)
        health = 100;
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

CollisionRegion* Baby::getCollisionRegion()
{
    if(sprActive)
        return sprActive->getCollisionRegion();
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

int Baby::getHygiene()
{
    return hygiene;
}

int Baby::getHealth()
{
    return health;
}

int Baby::getIntelligence()
{
    return intelligence;
}

void Baby::eat(Food* food)
{
    return;
}
