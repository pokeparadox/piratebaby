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
  * \file Prop is a base class for anything that can be interacted with by the Baby class
  * \author Kevin Winfield-Pantoja
*/
#ifndef PROP_H
#define PROP_H

#include "Sprite.h"

namespace Penjin
{
    class Prop : public Sprite
    {
        public:
            /** Default constructor */
            Prop();
            /** Default destructor */
            virtual ~Prop();

        protected:
        private:
    };
}
#endif // PROP_H
