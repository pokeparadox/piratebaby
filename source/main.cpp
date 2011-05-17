/*
	Penjin is Copyright (c)2005, 2006, 2007, 2008, 2009, 2010 Kevin Winfield-Pantoja

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
#include "MyGame2d.h"
using Penjin::Game2d;
using Penjin::MyGame2d;


int main(int argc, char** argv)
{
    Game2d* game = NULL;
    game = new MyGame2d;


    // Game loop
    game->loop();

    // Tidy up!
    delete game;
    return Penjin::PENJIN_OK;
	/*//ErrorHandler error;

	//	Setup game engine
	game = new MyGame;

	cout << error.getErrorString(game->argHandler(argc,argv));
	cout << error.getErrorString(game->penjinInit());

	while(game->stateLoop());	//	Perform main loop until shutdown
	cout << error.getErrorString(PENJIN_SHUTDOWN);

	//	Tidy up
    if(game)
    {
        delete game;
        game = NULL;
    }
    cout << error.getErrorString(PENJIN_GOODBYE);
    SDL_Quit();		//	Shut down SDL tidyly*/
	return EXIT_SUCCESS;	//	Normal program termination.
}
