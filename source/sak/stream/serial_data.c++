//	<editor-fold defaultstate="collapsed" desc="License">
/*
 * Copyright (C) 2021 Maxwell Aguiar Silva <maxwellaguiarsilva@gmail.com>
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
//	License </editor-fold>
//	Autor
/* 
 * File:   serial_data.hpp
 * Author: Maxwell Aguiar Silva <maxwellaguiarsilva@gmail.com>
 *
 * Created on 10 de julho de 2022, 12:09
 */

#include <sak/stream/serial_data.hpp>

HPP104047749_USING

using ::sak::stream::serial_data;
using ::sak::stream::serial_data_map;
using ::sak::numeric_string_comparison;
using ::sak::quoted;


//	Construtor de conversão de tipo + operador + update.
#define HPP104047749_CONSTRUCTOR_CPP( TYPE_NAME )		\
serial_data::serial_data( const TYPE_NAME value ) noexcept\
	:type( #TYPE_NAME )									\
	,value( to_string( value ) )						\
{ };

#define HPP104047749_UPDATE_CPP( TYPE_NAME )			\
serial_data& serial_data::update(							\
	 const string& name									\
	,TYPE_NAME & rightValue								\
)														\
{														\
	if( elements.find( name ) != elements.end( ) )		\
		rightValue = ( TYPE_NAME )(						\
			from_string( elements[ name ].getValue( ) )	\
		);												\
	else												\
		elements.try_emplace( name, rightValue );		\
	return *this;										\
};

#define HPP104047749_BASIC_TYPE_CPP( TYPE_NAME )	\
HPP104047749_CONSTRUCTOR_CPP( TYPE_NAME )			\
HPP104047749_UPDATE_CPP( TYPE_NAME )


//	Dados estruturados.
serial_data::serial_data( )
	:type( "object" )
	,value( "" )
{ };
serial_data::serial_data( const serial_data& orig )
	:type( orig.type )
	,value( orig.value )
{
	elements	=	const_cast<serial_data_map&>( orig.elements );
};
serial_data::~serial_data( )
{ };
//	Dados escalares.
HPP104047749_BASIC_TYPE_CPP( double );
HPP104047749_BASIC_TYPE_CPP( float );
HPP104047749_BASIC_TYPE_CPP( int );
HPP104047749_BASIC_TYPE_CPP( long );
HPP104047749_BASIC_TYPE_CPP( long double );
HPP104047749_BASIC_TYPE_CPP( long long );
HPP104047749_BASIC_TYPE_CPP( unsigned long );
HPP104047749_BASIC_TYPE_CPP( unsigned int );
HPP104047749_BASIC_TYPE_CPP( unsigned long long );
HPP104047749_BASIC_TYPE_CPP( bool );
HPP104047749_BASIC_TYPE_CPP( string );
serial_data::serial_data( const char * const value ) noexcept
	:serial_data( string( value ) )
{ };



const short tab_size	=	4;	//	Tamanho da tabulação.
//	Contém os dado sque serão usados no processo de identação.
struct args_bundle
{
	args_bundle(
		
	)	:target( target )
		,name( name )
		,tab_index( tab_index )
		,last( last )
	{ };
	~args_bundle( ) = default;
	
	const serial_data&	target;
	const string&		name;
	const int			tab_index;
	const bool			last;
};


//	Imprime dados do objeto de forma identada.
ostream& stream_indented(
	 ostream& os
	,const serial_data&	target
	,const string&		name			=	""
	,const bool			last			=	true
	,const int			tab_index		=	0
)
{
	const	bool				target_is_object	=	( target.getType( ) == "object" );
	const	serial_data_map&	elements			=	target.getElements( );
	const	string				tab_level			=	string( tab_index * tab_size, ' ' );
	
	os	<<	tab_level
		<<	( name.empty( ) ? ""  : quoted( name ) + ": " )
		<<	( target_is_object   ? "{" : quoted( target.getValue( ) ) + ( last ? " " : "," ) )
		<<	endl
	;
	
	for( const auto& element : elements )
		stream_indented(
			 os					//	Output Stream.
			,element.second		//	serial_data que será impresso.
			,element.first		//	Nome do elemento atual.
			,element.first	==	elements.rbegin( )->first	//	Caso seja o último.
			,tab_index + 1		//	Identação atual (level).
		);
	
	if( target_is_object )
		os	<<	tab_level
			<<	"}"
			<<	( last ? " " : "," )
			<<	endl;
	
	return	os;
};



//	Sobre-escrita de serializable.
ostream& serial_data::stream( ostream& os ) const
{
	return stream_indented( os, *this );
};
