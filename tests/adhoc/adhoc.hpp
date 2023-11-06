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
 * File:   adhoc.hpp
 * Author: Maxwell Aguiar Silva <maxwellaguiarsilva@gmail.com>
 *
 * Created on 7 de agosto de 2022, 17:23
 */


//	Prama once
#pragma once 
#ifndef HPP196029231
#define HPP196029231

#include <iostream>
#include <string>
#include <sak/common.hpp>
#include <sak/debug/test_handler/test_handler.hpp>



using ::std::cout;
using ::std::endl;
using ::std::string;


#ifndef HPP196029231_MAIN
#define HPP196029231_MAIN( __FN_NAME )	\
int __FN_NAME ## _main( int argc = 0, char** argv = { } );
#endif


HPP196029231_MAIN(	sketch_singleton		);
HPP196029231_MAIN(	smart_ptr_polymorphism	);
HPP196029231_MAIN(	thread_test				);
	

#endif