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
*/#ifndef STATSWINDOW_H
#define STATSWINDOW_H

#include "Window.h"

namespace Penjin
{
    class Baby;
    class Button;
    class Text;

    class StatsWindow : public Window
    {
        public:
            /** Default constructor */
            StatsWindow();
            /** Default destructor */
            virtual ~StatsWindow();

            /** \brief Set the Baby class instance we can extract the stats*/
            void setBaby(Baby* b);

            virtual void render();

            virtual void update();
        protected:
        private:
            Baby* baby;             //  This is set from outside the class, we don't need to tidy
            Button* window;         //  Button object not actually used as button, used as backing decoration for Window.
            Text* text;
    };
}

#endif // STATSWINDOW_H
