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
 * File:   netbeans_cpp_simple_test.c++
 * Author: Maxwell Aguiar Silva <maxwellaguiarsilva@gmail.com>
 *
 * Created on 19 de agosto de 2022, 18:17
 */

#include <sak/debug/test_handler/netbeans_cpp_simple_test.hpp>
#include <string>
#include <iostream>
#include <assert.h>




using ::std::string;
using ::std::cout;
using ::std::endl;
using ::sak::debug::test_handler::netbeans_cpp_simple_test;
SAK_USING_LINES;



//	######################################################################
netbeans_cpp_simple_test::netbeans_cpp_simple_test( )
	:suite_name( "" )
	,test_name( "" )
	,text_set( suite_name, test_name )
{ };
netbeans_cpp_simple_test::~netbeans_cpp_simple_test( )
{
	finish_test( );
};
//	######################################################################
void netbeans_cpp_simple_test::init( const string& name )
{
	assert(
		"O nome da suíte de testes não pode ser vazio!"
		&&	( ! name.empty( ) )
	);
	suite_name	=	name;
	cout	<<	endl
		<<	endl	<<	line_type_a
		<<	endl	<<	text_set.suite_finished
		<<	endl	<<	line_type_a	<<	endl
		<<	endl	<<	line_type_c
		<<	endl	<<	( text_set.user_messages.suite_starting + suite_name )
		<<	endl	<<	text_set.suite_starting( )
		<<	endl	<<	text_set.suite_started
		<<	endl	<<	line_type_c
		<<	endl
	;
};

//	######################################################################
void netbeans_cpp_simple_test::validate( bool result, const string& message )
{
	if( result )
		return;
	cout	<<	endl
		<<	endl	<<	line_type_b
		<<	endl	<<	text_set.test_failed( message )
		<<	endl	<<	line_type_b
		<<	endl
	;
};

//	######################################################################
void netbeans_cpp_simple_test::finish_test( )
{
	cout
		<<	endl	<<	line_type_d
		<<	endl	<<	text_set.test_finished( )
		<<	endl	<<	text_set.user_messages.test_finished << test_name
		<<	endl	<<	line_type_e
		<<	endl
	;
};

//	**********************************************************************
void netbeans_cpp_simple_test::test( const string& name )
{
	assert(
		"O nome do do teste não pode ser vazio!"
		&&	( !name.empty( ) )
	);
	if( !test_name.empty( ) )
		finish_test( );
	test_name	=	name;
	cout
		<<	endl	<<	line_type_e
		<<	endl	<<	text_set.user_messages.test_starting << test_name
		<<	endl	<<	text_set.test_started( )
		<<	endl	<<	line_type_d
		<<	endl	<<	endl
	;
};
//	######################################################################




//	######################################################################
//	OUTPUT_TEXTS
//	######################################################################

//	######################################################################
netbeans_cpp_simple_test::output_texts::output_texts(
	 const string& suite_name
	,const string& test_name
)	:suite_name( suite_name )
	,test_name( test_name )
{ };
//	######################################################################
const string netbeans_cpp_simple_test::output_texts::suite_starting( )
{
	return "%SUITE_STARTING% " + suite_name;
};
//	######################################################################
const string netbeans_cpp_simple_test::output_texts::test_started( )	
{
   return	"%TEST_STARTED% "
	   +	test_name
	   +	" ("
	   +	suite_name
	   +	")"
   ;
};
//	######################################################################
const string netbeans_cpp_simple_test::output_texts::test_failed( const string& message )	
{
	return	"%TEST_FAILED% time=0 testname="
		+	test_name
		+	" ("
		+	suite_name
		+	") message=\""
		+	message	
		+	"\""
	;
};
//	######################################################################
const string netbeans_cpp_simple_test::output_texts::test_finished( )
{
	return	"%TEST_FINISHED% time=0 "
		+	test_name
		+	" ("
		+	suite_name
		+	")"
	;
}
//	######################################################################
