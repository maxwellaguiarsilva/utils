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
 * File:   smart_ptr_polymorphism.c++
 * Author: Maxwell Aguiar Silva <maxwellaguiarsilva@gmail.com>
 *
 * Created on 2 de agosto de 2022, 06:22
 */

#include <iostream>
#include <memory>
#include "adhoc.hpp"


using ::std::cout;
using ::std::endl;
using ::std::istream;
using ::std::ostream;
using ::std::string;
using ::std::unique_ptr;
using ::std::make_unique;
using ::std::shared_ptr;
using ::std::make_shared;



class Base
{ENABLE_INSTANCE_COUNTER;
public:
	Base( ) = default;
	virtual ~Base( ) = default;
};

class Derived : public Base
{ENABLE_INSTANCE_COUNTER;
public:
	Derived( ) = default;
	virtual ~Derived( ) = default;
};

class NeedBase
{ENABLE_INSTANCE_COUNTER;
public:
	NeedBase( const shared_ptr< Base >& base = make_shared< Derived >( ) )
		:base( base )
	{};
	
	virtual ~NeedBase( )
	{};
	
private:
	shared_ptr< Base > base;
	
};



int smart_ptr_polymorphism_main( int argc, char** argv )
{{
	
	{
		SAK_PRINT_EXEC( Derived d	);
		{
			SAK_PRINT_EXEC( shared_ptr<Base> sp = make_shared<Derived>( )	)
			{
				SAK_PRINT_EXEC( NeedBase n( sp )	)
				SAK_PRINT_EXEC(
			}; "Remove NeedBase:" )
			SAK_PRINT_EXEC(
		}; "Remove shared_ptr:" )
		SAK_PRINT_EXEC(
	}; "Remove Derived:" )
	
}return (EXIT_SUCCESS);}