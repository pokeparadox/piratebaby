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
    class BabyBlob;
    class BabyEggBaby;
    class Panel;
    class SpriteButton;
    class Button;
    class QuitButton;
    class Image;
    class StatsWindow;
    class Food;
    class Cheese;
    class Rectangle;
    class SimpleDirection;

    class StateLevel : public ApplicationState, public ConfigFile
    {
        public:
            /** Default constructor */
            StateLevel();
            /** Default destructor */
            virtual ~StateLevel();

            virtual void init();
            virtual void render();
            virtual void update();
            virtual void input();
            virtual void clear();


        protected:
            void handleActions();                       // performs different actions depending on the action of the baby
            void setupBabyType(const string& type);     // Create the correct Baby class
            void setupPanel();                          // Setup the panel depending on the level of the baby
            void setupWindows();                        // Prepares any windows we may need to view.
            void handleButtons(const int& b);           // perform relevant actions depending on button

            Baby* baby;
            Panel* panel;
            Image* background;
            StatsWindow* statWindow;            //  Window showing all info of baby
            Food* food;                         //  The food object for baby to eat.
            Rectangle* water;                   //  Water to wash baby
            SimpleDirection* waterDir;          //  Direction water is moving (UP/DOWN)
            QuitButton* quitButton;             //  Button which you can quit the app
            Button* creditsButton;
            Button* splashButton;
            //vector <Prop*> props;             //  Vector of props the Baby can interact with.
    };
}
#endif // STATELEVEL_H
