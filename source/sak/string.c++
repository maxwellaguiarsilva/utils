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

//	Autor
/* 
 * File:   serial_data.hpp
 * Author: Maxwell Aguiar Silva <maxwellaguiarsilva@gmail.com>
 *
 * Created on 16 de julho de 2022, 21:08
 */

#include <sak/string.hpp>

using ::std::string;
using ::std::ostringstream;
using ::std::all_of;
using ::std::pair;


//	
bool ::sak::from_string::stobool( const string& value ) const
{
	string booleanString( value );
	std::transform( booleanString.begin( ), booleanString.end( ), booleanString.begin( ), ::tolower ); 
	if( booleanString == "true" ) return true;
	if( booleanString == "false" ) return false;
	throw std::invalid_argument( "\nInvalid boolean string (true/false): """ + booleanString + """" );
};

//	
const bool ::sak::numeric_string_comparison::operator( )( const string& left, const string& right ) const
{
	const pair size	=	{
		 left.size( )
		,right.size( )
	};
	const pair only_digits	=	{
		 is_only_digit( left )
		,is_only_digit( right )
	};
	const pair compare	=	{
		 size.first	==	size.second
		,only_digits.first	==	only_digits.second
	};
	
	return	( only_digits.first && only_digits.second	)
		?	( compare.first  ? left < right : size.first		<	size.second			)
		:	( compare.second ? left < right : only_digits.first	>	only_digits.second	)
	;
	
}


//	
const bool ::sak::is_only_digit( const string& value )
{
	return all_of( value.begin( ), value.end( ), ::isdigit );
};

//	
void ::sak::replace_substr(
	 string&	value
	,const string& to_search
	,const string& to_replace
)
{
    size_t	position	=	value.find( to_search ) ;
    while( position != string::npos )
    {
        value.replace( position, to_search.size( ), to_replace );
        position	=	value.find(
			 to_search
			,position	+	to_replace.size( )
		);
    }
};

//	
string sak::quoted( const string& value )
{
	ostringstream ss;
	return ( ss << ::std::quoted( value ) ), ss.str( );
};