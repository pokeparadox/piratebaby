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
*/
/***************************************************************************************************
*   \file StateTitle is a GameState to show the Title screen.
*/

#ifndef STATETITLE_H
#define STATETITLE_H

#include "ApplicationState.h"

namespace Penjin
{
    //  Forward decalrations
    //class Rectangle;
    //class AnimatedSprite;

    //  State delaration
    class StateTitle : public ApplicationState
    {
        public:
            /** Default constructor */
            StateTitle();
            /** Default destructor */
            virtual ~StateTitle();

            virtual void render();
            virtual void update();
            virtual void input();

        private:
            //Rectangle* rect;
            //AnimatedSprite* egg;
    };
}
#endif // STATETITLE_H
