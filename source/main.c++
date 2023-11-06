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
 * File:   main.c++
 * Author: Maxwell Aguiar Silva <maxwellaguiarsilva@gmail.com>
 *
 * Created on 24 de julho de 2022, 20:30
 */
//	#define DISABLE_INSTANCE_COUNTER

#include <iostream>
#include <string>
#include <sak/common.hpp>
#include <sak/debug/test_handler/test_handler.hpp>


//	Using.
using ::std::cout;
using ::std::endl;
SAK_USING_DEFAULT_DERIVED;


SAK_DECLARE_DEFAULT_DERIVED( abstract_base, derived_one );
//	Usa o template na herança.
class abstract_base : public SAK_DEFAULT_DERIVED( abstract_base )
{ENABLE_INSTANCE_COUNTER;
public:

	abstract_base ( ) = default;
	virtual ~abstract_base ( ) = default;
	virtual void print( ) const = 0;

};

//	Após declara a classe abstrata.
//	#include "derived_one.hpp"

//	
class derived_one : public abstract_base
{ENABLE_INSTANCE_COUNTER;
public:

	derived_one( ) = default;
	virtual ~derived_one ( ) = default;
	
	virtual void print( ) const 
	{
		cout
			<<	"derived_one->print"
			<<	endl
		;
	};

};

//	
class derived_two : public abstract_base
{ENABLE_INSTANCE_COUNTER;
public:

	derived_two( ) = default;
	virtual ~derived_two( ) = default;
	
	virtual void print( ) const 
	{
		cout
			<<	"derived_two->print"
			<<	endl
		;
	};

};


int main( int argc, char** argv )
{{
	
	SAK_PRINT_EXEC(	shared_default_derived< abstract_base >( )		->print( )	);
	SAK_PRINT_EXEC(	shared_default_derived< abstract_base, derived_two >( )	->print( )	);
	SAK_PRINT_EXEC(	unique_default_derived< abstract_base >( )		->print( )	);
	SAK_PRINT_EXEC(	unique_default_derived< abstract_base, derived_two >( )	->print( )	);
	
}return (EXIT_SUCCESS);}

