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
 * File:   token.hpp
 * Author: Maxwell Aguiar Silva <maxwellaguiarsilva@gmail.com>
 * 
 * Created on 9 de outubro de 2020, 23:26
 */

#pragma once
#ifndef HPP678864635
#define HPP678864635

#include <string>

namespace sak
{
namespace parser
{

using ::std::string;

//	Classe token. Dados de token de um parser.
class token
{
public:
	//	Exemplo: token t( "string_literal", position, "\"foo\"" )
	token( 
		 const string& type
		,const unsigned int position
		,const string& value	=	type
	)	:type( type )
		,position( position )
		,value( value )
	{ };
	virtual ~token( ) { };
	
	inline const string&		get_type( )		const noexcept { return type; }; 
	inline const unsigned int&	get_position( ) const noexcept { return position; }; 
	inline const string&		get_value( )	const noexcept { return value; }; 
	
private:
	token( const token& orig ) = delete;	
	const string	type;
	const unsigned int position;
	const string value;
};


}};


#endif
