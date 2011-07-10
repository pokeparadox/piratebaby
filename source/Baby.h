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
*   \file Baby is the base class for a series of different Babies
*   \author Kevin Winfield-Pantoja
*/
#ifndef BABY_H
#define BABY_H

#include "Vector2d.h"
#include "RenderObject.h"
#include "UpdateObject.h"
#include "PositionObject.h"
#include "ConfigFile.h"

namespace Penjin
{
    /*These are tyhe states that the baby can be in*/
    enum BABY_ACTIONS
    {
        ACTION_NONE=-1,
        ACTION_IDLE,
        ACTION_WALK_LEFT,
        ACTION_WALK_RIGHT,
        ACTION_EAT,
        ACTION_POOP,
        ACTION_ILL,
        ACTION_DIE,
        ACTION_DANCE,
        ACTION_JUMP,
        ACTION_BLINK,
        ACTION_SLEEP,
        ACTION_WAKE,
        ACTION_EVOLVE
    };

    // These are the different evolutions that the baby can be in
    enum BABY_EVOLUTIONS
    {
        EVO_EGG=0,
        EVO_BLOB,
        EVO_EGG_BABY,
        EVO_GHOST,
        EVO_SKELETON,
        EVO_ZOMBIE,
        EVO_PIRATE,
        EVO_NINJA
    };

    const string DEFAULT_BABY_SAVE = "config/Baby01.baby";

    // Forward class declarations
    class Sprite;
    class Timer;
    class Prop;
    class Food;
    class CollisionRegion;

    class Baby : public RenderObject, public UpdateObject, private ConfigFile
    {
        public:
            /** Default constructor */
            Baby();
            /** Default destructor */
            virtual ~Baby();

            void loadStats();

            void render();
            virtual void update();

            virtual void eat(Food* food);
            virtual void wash();
            virtual void heal();
            virtual void touch();

            void setAge(const int& age);
            int getAge();
            int getIntelligence();
            float getWeight();
            int getHunger();
            int getHygiene();
            int getHealth();
            int getLevel();
            CollisionRegion* getCollisionRegion();
            void setLevel(const int& l);
            // request the next form this baby will take.
            virtual string getNextForm(){return "Blob";}
            //  What action is this baby doing
            BABY_ACTIONS getAction(){return action;}
            bool hasLevelChanged(){return levelChanged;}
            void setLevelChanged(const bool& c){levelChanged = c;}
        protected:
            //  Return the string version of action
            string actionToString();
            void stringToAction(const string& s);
            //  this function test rules for this creature to evolve
            virtual void evolve();
            void defaultConfig();
            void switchAction(const BABY_ACTIONS& a);
            void saveData();

            BABY_ACTIONS action;    //  current action of baby
            int touchCount;         //  amount of time the user has clicked baby
            int intelligence;
            int age; // age is in seconds
            int health;
            float weight;
            int strength;
            int hunger;         // Hunger level
            int happiness;
            int hygiene;    //
            int level;          // This is the discipline level which adds new responsibilities as it increaes
                                // It is increased by various conditions.
            bool levelChanged;
            int toilet;        // This is the poopy level. Poop is released when full.
            Timer* timer;

            // This sprite points to the active animated sprite.
            Sprite* sprActive;

            Sprite* sprIdle;
            Sprite* sprJump;
            Sprite* sprdance;
            Sprite* sprWalkLeft;
            Sprite* sprWalkRight;
            Sprite* sprEat;

        private:
    };
}
#endif // BABY_H
