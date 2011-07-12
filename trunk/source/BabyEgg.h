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
  * \file BabyEgg is the class for a Egg type Baby that will hatch.
  * \author Kevin Winfield-Pantoja
*/
#ifndef BABYEGG_H
#define BABYEGG_H

#include "Baby.h"

namespace Penjin
{
    class BabyEgg : public Baby
    {
        public:
            /** Default constructor */
            BabyEgg();
            /** Default destructor */
            virtual ~BabyEgg();

            virtual void update();

            // Egg can only evolve into a blob or EggBaby
            virtual string getNextForm();

        protected:
            virtual void evolve();

    };
}
#endif // BABYEGG_H
