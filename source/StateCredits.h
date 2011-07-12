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
  * \file Displays the Credits screens
  * \author Kevin Winfield-Pantoja
*/#ifndef STATECREDITS_H
#define STATECREDITS_H

#include "ApplicationState.h"

namespace Penjin
{
    //class Brad;
    class Timer;
    class BackBuffer;
    class Text;
    class Sprite;

    class StateCredits : public ApplicationState
    {
        public:
            /** Default constructor */
            StateCredits();
            /** Default destructor */
            virtual ~StateCredits();

            virtual void init();
            virtual void render();
            virtual void update();
            virtual void input();
            virtual void clear();

        private:
            void printText();
            //Brad* angle;
            float angle;
            Timer* timer;
            BackBuffer* buff;
            Text* text;
            Sprite* sprite;
            int current;
    };
}

#endif // STATECREDITS_H
