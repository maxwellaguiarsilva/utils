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
 * Created on 31 de maio de 2021, 00:53
 */


//	Prama once
#pragma once
#ifndef HPP104047749
#define HPP104047749


//	Includes
#include <map>
#include <unordered_map>
#include <vector>
#include <memory>
#include <functional>
#include <sak/string.hpp>
#include <sak/stream/serializable.hpp>

//	Macros
#define HPP104047749_PATH		"::sak::stream::"
#define HPP104047749_FULL_NAME	HPP104047749_PATH"serial_data"


#define HPP104047749_BASIC_TYPE_HPP( TYPE_NAME )\
serial_data( const TYPE_NAME value ) noexcept;	\
serial_data& update(								\
	 const string& name							\
	,TYPE_NAME& rightValue						\
);




#define HPP104047749_USING			\
using ::std::cout;					\
using ::std::endl;					\
using ::std::ostream;				\
using ::std::pair;					\
using ::std::map;					\
using ::std::string;				\
using ::std::to_string;				\
using ::std::vector;				\
using ::std::unique_ptr;			\
using ::std::make_unique;			\
using ::sak::from_string;			\
using ::sak::to_string;				\
using ::sak::stream::serializable;	\
//	HPP104047749_USING



//	Namespace ::sak::stream
namespace sak
{
namespace stream
{
	
HPP104047749_USING

class serial_data;
typedef	map< string, serial_data, ::sak::numeric_string_comparison >	serial_data_map;
typedef	pair< const string,  serial_data* >	serial_data_pair;

/*
 * Classe ::sak::stream::serial_data;
 * Guarda um dado e o nome do seu tipo básico como uma string.
 * Também pode ser usado como objeto, guardando elementos filhos em propriedades nomeadas.
 * HPP104047749
 */
class serial_data : public serializable
{
public:
	
	//	Construtores padrões ( dados estruturais ).
	serial_data( );
	serial_data( const serial_data& orig );
	virtual ~serial_data( );
	//	Construtores de conversão ( dados escalares ).
	HPP104047749_BASIC_TYPE_HPP( double );
	HPP104047749_BASIC_TYPE_HPP( float );
	HPP104047749_BASIC_TYPE_HPP( int );
	HPP104047749_BASIC_TYPE_HPP( long );
	HPP104047749_BASIC_TYPE_HPP( long double );
	HPP104047749_BASIC_TYPE_HPP( long long );
	HPP104047749_BASIC_TYPE_HPP( unsigned long );
	HPP104047749_BASIC_TYPE_HPP( unsigned int );
	HPP104047749_BASIC_TYPE_HPP( unsigned long long );
	HPP104047749_BASIC_TYPE_HPP( bool );
	HPP104047749_BASIC_TYPE_HPP( string );
	serial_data( const char * const value ) noexcept;	//	const char pointer.
	
	
	//	Get's.
	inline const string&			getType( )		const noexcept { return type; }; 
	inline const string&			getValue( )		const noexcept { return value; }; 
	inline const serial_data_map&	getElements( )	const noexcept { return elements; };
	
	inline const serial_data_pair operator[]( const string& name )
	{ return { name, this };	};
	inline const serial_data_pair operator[]( const unsigned int& index )
	{ return ( *this )[ to_string( index ) ]; };
	
	inline serial_data&	get( const string& name )
	{
		return elements[ name ];
	};
	
	
private:
	
	serial_data& operator=( const serial_data& orig )	=	delete;
	
	
	const string type;
	const string value;
	unique_ptr< serial_data_map >	elementsPointer	=	make_unique< serial_data_map >( );
	serial_data_map& elements	=	( *elementsPointer );
	
		
	//	Sobreescrita: serializable->stream; 
	virtual ostream& stream( ostream& os ) const override;
	

};


}};



//	Using for templates and macros.
using ::std::ostream;
using ::std::pair;
using ::std::map;
using ::std::unordered_map;
using ::std::string;
using ::std::to_string;
using ::std::vector;
using ::sak::stream::serial_data;
using ::sak::stream::serial_data_pair;



#define HPP104047749_PAIR_OPERATOR_HPP( TYPE_NAME )	\
inline void operator&(								\
	const serial_data_pair& sd_pair					\
	,TYPE_NAME& value								\
)													\
{ sd_pair.second->update( sd_pair.first, value ); };

HPP104047749_PAIR_OPERATOR_HPP( double );
HPP104047749_PAIR_OPERATOR_HPP( float );
HPP104047749_PAIR_OPERATOR_HPP( int );
HPP104047749_PAIR_OPERATOR_HPP( long );
HPP104047749_PAIR_OPERATOR_HPP( long double );
HPP104047749_PAIR_OPERATOR_HPP( long long );
HPP104047749_PAIR_OPERATOR_HPP( unsigned long );
HPP104047749_PAIR_OPERATOR_HPP( unsigned int );
HPP104047749_PAIR_OPERATOR_HPP( unsigned long long );
HPP104047749_PAIR_OPERATOR_HPP( bool );
HPP104047749_PAIR_OPERATOR_HPP( string );



//	Macros e templates de utilização.
#define SERIALDATA_OPERATOR( TYPE_NAME, ... )	\
serial_data& operator&(							\
	TYPE_NAME& target							\
	,serial_data& sd								\
)												\
{												\
	__VA_ARGS__									\
	return sd;									\
};

#define SERIALDATA_ITEM( ITEM_NAME )			\
	sd[ #ITEM_NAME ] & target.ITEM_NAME;

#define SERIALDATA_BASE( CLASS_NAME )			\
	static_cast< CLASS_NAME& >( target ) & sd;

#define SERIALDATA_FRIEND( TYPE_NAME )	\
friend serial_data& operator&(			\
	 TYPE_NAME& target					\
	,serial_data& sd						\
);




//	Tipos genéricos.

//	Operador invertido.
template<
	 class _T1
	,class	=	::std::enable_if< !::std::is_convertible< _T1&, serial_data& >::value >::type
>
inline serial_data& operator&( serial_data& sd, _T1& target ) { return target & sd; };

//	Elemento interno.
template< class _T1 >
inline serial_data& operator&(  const serial_data_pair& sd_pair, _T1& target )
{ return target & sd_pair.second->get( sd_pair.first ); };
template<
	 class _T1
	,class	=	::std::enable_if< !::std::is_convertible< _T1&, serial_data_pair& >::value >::type
>
inline serial_data& operator&( _T1& target, const serial_data_pair& sd_pair ) { return sd_pair & target; };


//	ostream.
template<
	 class	_T1
	,class	=	decltype( std::declval< _T1& >( ) & std::declval< serial_data& >( ) )
>
ostream& operator<<( ostream& os, const _T1& target )
{
	_T1 t	=	target;
	serial_data	sd;
	t	&	sd;
	return	os	<<	sd;
};


//	pair.
#define __COMMA__ ,
template< typename _T1 __COMMA__ typename _T2 >
SERIALDATA_OPERATOR(	pair< _T1 __COMMA__ _T2 >,
	SERIALDATA_ITEM(	first	)
	SERIALDATA_ITEM(	second	)
)


//	vector.
template< class _T1 >
SERIALDATA_OPERATOR(	vector< _T1 >,
	int size = sd.getElements( ).size( );
	if( size )
	{
		target.clear( );
		target.shrink_to_fit( );
		target.reserve( size );	
		_T1 value;
		while( --size >= 0 )
		{
			sd[ target.size( ) ] & value;
			target.emplace_back( value );
		}
	} else
	{
		size	=	target.size( );
		while( --size >= 0 )
			sd[ size ] & target[ size ];
	}
	target.shrink_to_fit( );
)
	

//	map or unordered_map.
template<
	 class __MAP_TYPE
	,class	=	typename __MAP_TYPE::key_type
	,class	=	typename __MAP_TYPE::value_type::second_type
>
SERIALDATA_OPERATOR(	__MAP_TYPE,	
	using _T1 = ::std::remove_const< typename __MAP_TYPE::key_type >::type;
	using _T2 = __MAP_TYPE::value_type::second_type;
	pair< _T1, _T2 > value;
	int size = sd.getElements( ).size( );
	if( size )
	{
		target.clear( );
		while( --size >= 0 )
		{
			sd[ target.size( ) ] & value;
			target.try_emplace( value.first, value.second );
		}
	}else
	{
		size = target.size( );
		for( const auto& item : target )
			sd[ --size ] & ( value	=	item );
	}
)


#endif
