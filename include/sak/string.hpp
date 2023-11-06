//	<editor-fold defaultstate="collapsed" desc="License">
/*
 * Copyright (C) 2020 Maxwell Aguiar Silva <maxwellaguiarsilva@gmail.com>
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
 * File:   string.hpp
 * Author: Maxwell Aguiar Silva <maxwellaguiarsilva@gmail.com>
 * 
 * Created on 11 de novembro de 2020, 23:48
 */



#pragma once
#ifndef HPP597281476
#define HPP597281476


//	Include
#include <string>	//	::std::string
#include <algorithm>//	::std::all_of
#include <iomanip>	//	::std::quoted


#ifndef SAK_USING_STRING
#define SAK_USING_STRING	\
using ::std::string;		\
using ::std::to_string;		\
using ::sak::to_string;		\
using ::sak::from_string;	\
;
#endif



//	Utiliza as linhas para apoio para output.
#ifndef SAK_USING_LINES
#define SAK_USING_LINES	\
using ::sak::line_type_a;	\
using ::sak::line_type_b;	\
using ::sak::line_type_c;	\
using ::sak::line_type_d;	\
using ::sak::line_type_e;	\
;
#endif



//	Declara uma função inline de conversão de tipo usando sobrecarga de operador.
#ifndef HPP597281476_INLINE_OPERATOR
#define HPP597281476_INLINE_OPERATOR( __TYPENAME, __FN_NAME )	\
	inline operator const __TYPENAME ( ) const { return __FN_NAME( value ); }
#endif



//	Namespace sak;
namespace sak
{;


//	Using.
using ::std::string;
using ::std::ostringstream;
using ::std::all_of;



//	Linhas para apoio para output.
const string line_type_a	=	string( 100, '#' );
const string line_type_b	=	string( 100, '*' );
const string line_type_c	=	string( 100, '=' );
const string line_type_d	=	string( 100, '-' );
const string line_type_e	=	string( 100, '_' );




/*
 * Classe from_string
 * Converte uma string para um tipo básico.
 */
class from_string
{
public:
	
	//	Construtor e destrutor.
	from_string( const string& __value ) : value( __value ) { };
	from_string( const from_string& orig ) : from_string( orig.value ) { };
	virtual ~from_string( ) { };
	
	
	//	Números.
	HPP597281476_INLINE_OPERATOR( double				,::std::stod		);
	HPP597281476_INLINE_OPERATOR( float					,::std::stof		);
	HPP597281476_INLINE_OPERATOR( int					,::std::stoi		);
	HPP597281476_INLINE_OPERATOR( long					,::std::stol		);
	HPP597281476_INLINE_OPERATOR( long double			,::std::stold		);
	HPP597281476_INLINE_OPERATOR( long long				,::std::stoll		);
	HPP597281476_INLINE_OPERATOR( unsigned int			,::std::stoul		);
	HPP597281476_INLINE_OPERATOR( unsigned long			,::std::stoul		);
	HPP597281476_INLINE_OPERATOR( unsigned long long	,::std::stoull		);
	//	Boolean.
	HPP597281476_INLINE_OPERATOR( bool					,stobool	);
	
	//	String.
	inline operator const string& ( ) const { return value; }
	inline operator const char ( ) const { return value.at( 0 ); }
	
	
private:

	//	string value //	Valor armazenado.
	string value;
	

	//	stobool	//	Converte string para boolean.
	bool stobool( const string& value ) const;
	

};


//	Compara duas string numericamente caso tenham apenas dígitos (inteiros positivos).
struct numeric_string_comparison
{
	const bool operator()( const string& left, const string& right ) const;
};

//	to_string	//	Converte boolean para string.
inline const string to_string( bool value ) { return ( value )? "true" : "false" ; };
inline const string& to_string( const string& value ) { return value; };

//	Seis por meia dúzia?
const bool is_only_digit( const string& value );

//	É muita inocência imaginar que C++ teria algo tão moderno.
void replace_substr(
	 string&	value
	,const string& to_search
	,const string& to_replace
);

//	Alguém fumou muito antes de pesnsar que uma string com aspas não era uma string!	
string quoted( const string& value );


};

#endif

