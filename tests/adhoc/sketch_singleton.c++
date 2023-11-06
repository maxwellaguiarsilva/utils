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


#include "adhoc.hpp"
#include <sak/pattern/singleton_ptr.hpp>


using ::std::string;
using ::std::to_string;
using ::std::cout;
using ::std::endl;
using ::sak::pattern::singleton_ptr;



//	Teste de classe base.
class Base
{ENABLE_INSTANCE_COUNTER;
public: 
	Base( ) = default;
	virtual ~Base ( ) = default;;
	virtual void print( const string& value ) const = 0;
};


//	Teste de classe derivada.
class Derived : public Base
{ENABLE_INSTANCE_COUNTER;
public:

	Derived( ) = default;
	virtual ~Derived ( ) = default;
	void print( const string& value ) const override
	{
		cout
			<<	value
			<<	endl			
		;
	};
};



//	Main adaptado para teste adhoc.
int sketch_singleton_main( int argc, char** argv )
{{

	
	SAK_PRINT_EXEC( singleton_ptr< Base > sb1	=	singleton_ptr< Derived >( )	);
	SAK_PRINT_EXEC( singleton_ptr< Base > sb2	=	singleton_ptr< Derived >( )	);
	SAK_PRINT_EXEC( singleton_ptr< Derived > sd3	);
	
	
	SAK_PRINT_EXEC( Base& b = sb1	);
	SAK_PRINT_EXEC( b.print( "Hello world!" )	);
	SAK_PRINT_EXEC(	sb2->print( "Hello world!" )	);
	SAK_PRINT_EXEC( ( *sd3 ).print( "Hello world!" )	);
	
	SAK_PRINT_EXEC( Base* p	=	new Derived );
	SAK_PRINT_EXEC( delete p );
	
}return (EXIT_SUCCESS);}



