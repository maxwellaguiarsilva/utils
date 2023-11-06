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
 * File:   instance_counter.c++
 * Author: Maxwell Aguiar Silva <maxwellaguiarsilva@gmail.com>
 *
 * Created on 15 de agosto de 2022, 21:49
 */


#include <sak/debug/instance_counter/instance_counter.hpp>


using ::sak::debug::instance_counter::instance_counter;
SAK_USING_DEFAULT_DERIVED;


//	
instance_counter& ::sak::debug::instance_counter::default_instance_counter(	const shared_ptr< instance_counter >& target )
{
	static shared_ptr< instance_counter > instance;
	if( target )
		instance	=	target;	
	else
		if( !instance )
			instance	=	shared_default_derived< instance_counter >( );
	return *instance;
};