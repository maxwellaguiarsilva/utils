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
 * File:   debug.hpp
 * Author: Maxwell Aguiar Silva <maxwellaguiarsilva@gmail.com>
 *
 * Created on 24 de agosto de 2022, 22:38
 */


//	Prama once
#pragma once 
#ifndef HPP098866387
#define HPP098866387

#include <sak/common.hpp>


//	Mostra o comando que está sendo executado.
#ifndef SAK_PRINT_EXEC
#define SAK_PRINT_EXEC( ... )	\
::std::cout	<<	::std::endl					\
	<<	::sak::line_type_e	<<	::std::endl	\
	<<	#__VA_ARGS__		<<	::std::endl	\
	<<	::sak::line_type_d	<<	::std::endl	\
; __VA_ARGS__ ; ::std::cout	<<	::std::endl	\
	<<	::sak::line_type_e	<<	::std::endl	\
;
#endif

namespace sak
{;
namespace debug
{;

SAK_USING_STRING;

//	Obtem o nome real de type_info::name.
const string get_real_type_name( const string& name, const bool full_name = false );

}};


#endif
