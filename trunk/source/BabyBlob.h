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
*/#ifndef BABYBLOB_H
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
