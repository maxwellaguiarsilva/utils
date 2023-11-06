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
 * File:   adhoc.c++
 * Author: Maxwell Aguiar Silva <maxwellaguiarsilva@gmail.com>
 *
 * Created on 7 de agosto de 2022, 17:10
 */

#include <stdlib.h>
#include <iostream>
#include "adhoc.hpp"
#include <sak/debug/test_handler/test_handler.hpp>


using ::std::cout;
using ::std::endl;
using ::std::string;
SAK_USING_TEST_HANDLER;


#ifndef HPP196029231_TEST_CALLER
#define HPP196029231_TEST_CALLER( __FN_NAME )	\
void adhoc_ ## __FN_NAME( test_interface& current_test )\
{ __FN_NAME ## _main( ); };
#endif

HPP196029231_TEST_CALLER(	sketch_singleton		);
HPP196029231_TEST_CALLER(	smart_ptr_polymorphism	);
HPP196029231_TEST_CALLER(	thread_test				);


int main( int argc, char** argv )
{{
	shared_ptr handler	=	shared_default_derived< test_handler >( );

	handler->init( "adhoc" );

	handler->test(	SAK_TEST(	adhoc_sketch_singleton			)	);
	handler->test(	SAK_TEST(	adhoc_smart_ptr_polymorphism	)	);
	handler->test(	SAK_TEST(	adhoc_thread_test				)	);

};return (EXIT_SUCCESS );}

