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
/**
  * \file Food base class to derive different food types for baby to eat.
  * \author Kevin Winfield-Pantoja
*/#ifndef FOOD_H
#define FOOD_H

#include "Prop.h"

namespace Penjin
{
    class Food : public Prop
    {
        public:
            /** Default constructor */
            Food();
            /** Default destructor */
            virtual ~Food();

            int getNutrition();
            float getWeight();
            int getWaste();

            bool isExhausted();
            bool isOnFloor();

            virtual void update();

            // Current values used to test for exhaustion
            int cNutrition;
            float cWeight;
            int cWaste;

        protected:
            int nutrition;      //  This is how much we can lower the hunger level.
            float weight;       //  How much weight will be put on from this.
            int waste;           //  How much this will contribute to toilet stuff.
            //int happiness;    //  How happy eating this will make baby

        private:
            int floorLevel;          // The level of the floor
            bool onFloor;
    };

}

#endif // FOOD_H
