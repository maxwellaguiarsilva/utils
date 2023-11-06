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
 * File:   debug.c++
 * Author: Maxwell Aguiar Silva <maxwellaguiarsilva@gmail.com>
 *
 * Created on 24 de agosto de 2022, 22:38
 */


#include <sak/debug/debug.hpp>
#include <cxxabi.h>
#include <regex>

//	Using.
SAK_USING_STRING;
using ::sak::replace_substr;
using ::std::regex;
using ::std::regex_replace;

//	
const string ( ::sak::debug::get_real_type_name )( const string& name, const bool full_name )
{
	int     status = 0;
	char*	realname	=	::abi::__cxa_demangle(
		 name.c_str( )
		,0
		,0
		,&status
	);
	string result = realname;
	free( realname );
	
	replace_substr( result, "<", "< " );
	replace_substr( result, ">", " >" );
	
	if( !full_name )
	{
		regex identifier_rule( "[a-zA-Z_$][a-zA-Z0-9_$]*::" );
		result = regex_replace( result, identifier_rule, "" );		
	}
	
	return	result;
};
