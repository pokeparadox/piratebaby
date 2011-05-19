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
*   \file CLASS_NAME is INSERT DESCRIPTION
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
        ACTION_NONE,
        ACTION_IDLE,
        ACTION_DANCE,
        ACTION_BLINK,
        ACTION_SLEEP
    };

    // Forward class declarations
    class AnimatedSprite;
    class Timer;


    class Baby : public RenderObject, public UpdateObject, private ConfigFile
    {
        public:
            /** Default constructor */
            Baby();
            /** Default destructor */
            virtual ~Baby();

            void render();
            virtual void update();

            int getLevel();

            void setLevel(const int& l);

        protected:
            //  this function test rules for this creature to evolve
            virtual void evolve();
            int intelligence;
            int age;
            int health;
            float weight;
            int strength;
            int happiness;
            int cleanliness;
            int level;          // This is the discipline level which adds new responsibilities as it increaes

            AnimatedSprite* sprite;

        private:
    };
}
#endif // BABY_H
