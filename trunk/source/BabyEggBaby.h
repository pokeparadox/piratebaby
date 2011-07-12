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
  * \file BabyEggBaby is a class for a semi-hatched EggBaby
  * \author Kevin Winfield-Pantoja
*/
#ifndef BABYEGGBABY_H
#define BABYEGGBABY_H

#include "BabyBlob.h"

namespace Penjin
{
    class BabyEggBaby : public BabyBlob
    {
        public:
            /** Default constructor */
            BabyEggBaby();
            /** Default destructor */
            virtual ~BabyEggBaby();

            virtual void render();

            virtual void update();
        protected:
        private:
    };

}

#endif // BABYEGGBABY_H
