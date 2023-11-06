// <editor-fold defaultstate="collapsed" desc="License">
/*
 * Copyright (C) 2022 Maxwell Aguiar Silva <maxwellaguiarsilva@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
// License </editor-fold>
/* 
 * File:   thread_test.c++
 * Author: Maxwell Aguiar Silva <maxwellaguiarsilva@gmail.com>
 *
 * Created on 13 de agosto de 2022, 09:32
 */

#include "adhoc.hpp"
#include <iostream>
#include <thread>

using ::std::cout;
using ::std::cin;
using ::std::endl;
using ::std::thread;
using ::std::this_thread::sleep_for;

bool running = true;

void parallel_task( )
{
	using namespace ::std::literals::chrono_literals;
		
	while( running )
	{
		cout
			<<	"The parallel task is running....."
			<<	endl
		;
		sleep_for( 1s );
	};
};

int thread_test_main( int argc, char** argv )
{{
	
//	using namespace ::std::literals::chrono_literals;
//	
//	thread task( parallel_task );
//	
//	sleep( 10 );
//	
//	running	=	false;
	

 }return ( EXIT_SUCCESS );};