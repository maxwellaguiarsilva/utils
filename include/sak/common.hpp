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
 * File:   common.hpp
 * Author: Maxwell Aguiar Silva <maxwellaguiarsilva@gmail.com>
 *
 * Created on 18 de agosto de 2022, 22:33
 */


//	prama once
#pragma once 
#ifndef hpp579274111
#define hpp579274111

#include <exception>
#include <iostream>
#include <sak/string.hpp>
#include <sak/pattern/default_derived.hpp>
#include <sak/debug/instance_counter/instance_counter.hpp>


//	construtor padrão com destrutor virtual.
#ifndef default_ctc_dtc
#define default_ctc_dtc( __class_name )	\
__class_name( ) = default;				\
virtual ~__class_name( ) = default;
#endif


//	standart output/input.
#ifndef sak_using_ios
#define sak_using_ios	\
using ::std::cin;	\
using ::std::cout;	\
using ::std::endl;	\
using ::std::ostream;	\
using ::std::istream;	\
using ::std::ofstream;	\
using ::std::ifstream;	\
using ::std::setw;	\
using ::std::left;	\
;
#endif



#endif
