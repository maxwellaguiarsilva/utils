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
 * File:   Testserial_data.c++
 * Author: Maxwell Aguiar Silva <maxwellaguiarsilva@gmail.com>
 *
 * Created on 19 de março de 2022, 10:58
 */


#include <stdlib.h>
#include <iostream>
#include <sak/stream/serial_data.hpp>
#include <sak/debug/test_handler/netbeans_cpp_simple_test.hpp>


using ::std::cout;
using ::std::endl;
using ::sak::stream::serial_data;
SAK_USING_TEST_HANDLER;


//	Membros públicos.
struct location
{
	unsigned int aisle, shelf;
};
SERIALDATA_OPERATOR( location,
	SERIALDATA_ITEM( aisle )
	SERIALDATA_ITEM( shelf )
)

//	Membros privados.
class Weighed
{
public:	
	Weighed( float weight	=	0 )
		:weight( weight )
	{ };
	SERIALDATA_FRIEND( Weighed )
private:
	float weight;
};
SERIALDATA_OPERATOR(	Weighed,
	SERIALDATA_ITEM(	weight	)
)


//	Constante externa para manter os construtores padrões.
//	Construtores não podem ter parâmetro sem default.
const unsigned int SHELF_PER_AISLE = 5;	
class Product
{
public:	
	Product(
		 float price	=	0
	)
		:price( price )
		,cod_product( ++( Product::increment ) )
		,place( {
			 cod_product	/	SHELF_PER_AISLE
			,cod_product	%	SHELF_PER_AISLE
		} )
	{ };
	SERIALDATA_FRIEND( Product )
private:
	static int increment;
	unsigned int cod_product;
	float price;
	location place;
};
int Product::increment	=	0;
SERIALDATA_OPERATOR(	Product,
	SERIALDATA_ITEM(	cod_product	)
	SERIALDATA_ITEM(	price		)
	SERIALDATA_ITEM(	place		)
);


//	Templates.
template< typename _T1, typename _T2 >
struct pair_vector
{
	vector< _T1 > first;
	vector< _T2 > second;
};
template< typename _T1, typename _T2 >
SERIALDATA_OPERATOR(	pair_vector< _T1 __COMMA__ _T2 >,	//	__COMMA__ = ,
	SERIALDATA_ITEM(	first	)
	SERIALDATA_ITEM(	second	)
);


//	Herança.
class Fruit
	:public Weighed
	,public Product
{
public:
	Fruit(
		 const string& name			=	""
		,const float unit_price		=	0
		,const unsigned int amount	=	0
		,float weight				=	0
	)
		:Product( amount * unit_price )
		,Weighed( amount * weight )
		,name( name )
		,amount( amount )
		,unit_price( unit_price )
	{ };
	SERIALDATA_FRIEND(	Fruit	)
private:
	string name;
	unsigned int amount;
	float unit_price;
};
SERIALDATA_OPERATOR(	Fruit,
	SERIALDATA_BASE(	Product		)
	SERIALDATA_BASE(	Weighed		)
	SERIALDATA_ITEM(	name		)
);



void testserial_data( test_interface& test )
{

	unordered_map< string, Fruit >	source	=	{
		 {	"one"	,{ "banana"	,0.5, 6, 0.1 }	}
		,{	"two"	,{ "apple"	,0.8, 5, 0.3 }	}
	};
	
	//	Ida.
	cout
		<<	"Ida: "
		<<	source
		<<	endl
	;
	
	//	Volta.	
	serial_data	sd;
	sd & source;
	decltype( source )	target;
	sd & target;
	cout
		<<	"Volta: "
		<<	target
		<<	endl
	;
	
}

int main( int argc, char** argv )
{{
	
	shared_ptr handler	=	shared_default_derived< test_handler >( );
	
	handler->init( "Testserial_data" );
		
	handler->test( SAK_TEST( testserial_data ) );	
	
}return (EXIT_SUCCESS);}
