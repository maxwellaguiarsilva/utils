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
 * File:   test_handler.hpp
 * Author: Maxwell Aguiar Silva <maxwellaguiarsilva@gmail.com>
 *
 * Created on 18 de agosto de 2022, 22:19
 */


#pragma	once
#ifndef HPP481529913
#define HPP481529913

#include <sak/common.hpp>
#include <functional>



#ifndef SAK_TEST
#define SAK_TEST( __NAME ) &__NAME, ::std::string( #__NAME )
#endif

#ifndef SAK_USING_TEST_HANDLER
#define SAK_USING_TEST_HANDLER	\
using ::sak::debug::test_handler::test_handler;		\
using ::sak::debug::test_handler::test_interface;	\
SAK_USING_DEFAULT_DERIVED;
#endif


namespace sak
{;


namespace debug
{;
namespace test_handler
{;

//	Using.
using ::std::function;
SAK_USING_DEFAULT_DERIVED;

class test_interface
{ENABLE_INSTANCE_COUNTER;
public:
	inline	void fail( const string& message ){ validate( false, message ); };
	inline	void validate( const string& message, bool result ){ validate( result, message ); };
	virtual void validate( bool result, const string& message ) = 0;
};

class netbeans_cpp_simple_test;
class test_handler
	:public test_interface
	,public default_derived< netbeans_cpp_simple_test >
{ENABLE_INSTANCE_COUNTER;
public:
	DEFAULT_CTC_DTC( test_handler );
	
	virtual void init( const string& name ) = 0;
	
	inline	void test( const string& name, const function< void( test_interface& ) >& target ){ test( target, name ); };
	void test( const function< void( test_interface& ) >& target, const string& name )
	{
		test( name );
		target( *this );
	};
	
private:
	virtual void test( const string& name ) = 0;
};

}}};


//	default_derived.
#include <sak/debug/test_handler/netbeans_cpp_simple_test.hpp>


#endif
