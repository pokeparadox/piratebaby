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
  * \file BabyBlob is the class for a Blob type Baby.
  * \author Kevin Winfield-Pantoja
*/
#ifndef BABYBLOB_H
#define BABYBLOB_H

#include "BabyEgg.h"
namespace Penjin
{
    class Prop;

    class BabyBlob : public BabyEgg
    {
        public:
            /** Default constructor */
            BabyBlob();
            /** Default destructor */
            virtual ~BabyBlob();

            virtual void update();
            virtual void render();

            // interect with a prop in game.
            virtual void interact(Prop* prop);

            void eat(Food* food);
            virtual void wash();
            virtual void heal();

            virtual string getNextForm();
        protected:
            void doPoop();
            vector <Sprite*> poops;
            Sprite* illness;
        private:
    };
}


#endif // BABYBLOB_H
