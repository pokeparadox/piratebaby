/*
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
*/#ifndef STATELEVEL_H
#define STATELEVEL_H
/* StateLevel is the state to handle the world the baby occupies in PirateBaby*/
#include "ApplicationState.h"
#include "ConfigFile.h"

namespace Penjin
{
    const string BABY_LIST = "config/babies.ini";

    class Baby;
    class BabyEgg;
    class Panel;
    class Image;

    class StateLevel : public ApplicationState, public ConfigFile
    {
        public:
            /** Default constructor */
            StateLevel();
            /** Default destructor */
            virtual ~StateLevel();

            virtual void render();
            virtual void update();
            virtual void input();


        protected:
            void setupBabyType(const string& type);
            void handleButtons(const int& b);   // perform relevant actions depending on button

            Baby* baby;
            Panel* panel;
            Image* background;
    };
}
#endif // STATELEVEL_H
