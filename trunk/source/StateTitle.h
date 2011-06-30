/*
	PirateBaby is Copyright (c) 2011 Kevin Winfield-Pantoja

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
*   \file StateTitle is a GameState to show the Title screen.
*/

#ifndef STATETITLE_H
#define STATETITLE_H

#include "ApplicationState.h"
#include <vector>
using std::vector;

namespace Penjin
{
    //  Forward decalrations
    class Sprite;
    class Timer;
    class Text;
    class BackBuffer;

    //  State delaration
    class StateTitle : public ApplicationState
    {
        public:
            /** Default constructor */
            StateTitle();
            /** Default destructor */
            virtual ~StateTitle();
            virtual void init();
            virtual void render();
            virtual void update();
            virtual void input();
            virtual void clear();
        private:
            void setupSplashes();       //  Setup the splash screen images to display
            void printText();           //  display the relevant text for each image
            Timer* timer;               //  To time the display of each splash
            vector<Sprite*> splashes;   //  Splash images for title
            int current;                //  The current splash to display
            Text* text;                 //  Display relevant text.
            BackBuffer* buff;
    };
}
#endif // STATETITLE_H
