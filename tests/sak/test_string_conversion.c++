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

/* 
 * File:   TestStringConversion.c++
 * Author: Maxwell Aguiar Silva <maxwellaguiarsilva@gmail.com>
 *
 * Created on 19 de março de 2022, 11:32
 */

#include <string>
#include <sak/string.hpp>
#include <sak/debug/test_handler/test_handler.hpp>
#include <sak/common.hpp>


/*
 * Simple C++ Test Suite
 */

SAK_USING_STRING;
SAK_USING_TEST_HANDLER;


void testTo_string( test_interface& test )
{
	using namespace ::std::string_literals;
	bool value = true;
	const string result = to_string( value );
	test.validate( "Erro ao converter de boolean para string!"s, result == "true"s );	
};

void testFrom_string( test_interface& test )
{
	using namespace ::std::string_literals;
	const string& __value = "origin"s;
	from_string _from_string( __value );
	test.validate( "Erro no construtor from_string( string )!"s, ( const string )_from_string == "origin"s );
}

void testFrom_stringClone( test_interface& test )
{
	using namespace ::std::string_literals;
	const from_string& orig = from_string( "clone" );
	from_string _from_string( orig );
	test.validate( "Erro no construtor de clonagem!", ( const string )_from_string == string( "clone" ) );
}



int main( int argc, char** argv )
{{
	
	shared_ptr handler	=	shared_default_derived< test_handler >( );
	auto& suite		=	*handler;
	
	suite.init( "TestStringConversion" );
	
	suite.test( SAK_TEST(	testTo_string			) );
	suite.test( SAK_TEST(	testFrom_string			) );
	suite.test( SAK_TEST(	testFrom_stringClone	) );

 }return ( EXIT_SUCCESS );}