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
 * File:   local_instance_counter.hpp
 * Author: Maxwell Aguiar Silva <maxwellaguiarsilva@gmail.com>
 *
 * Created on 17 de agosto de 2022, 22:06
 */

#include <sak/debug/instance_counter/instance_counter.hpp>
#include <unordered_map>

#pragma	once
#ifndef HPP767186102
#define HPP767186102

namespace sak
{;
namespace debug
{;
namespace instance_counter
{;
namespace local_instance_counter
{;

using ::std::unordered_map;

//	Contador de instâncias interno/local.
class local_instance_counter : public instance_counter
{
public:
	
	local_instance_counter( ) = default;
	virtual ~local_instance_counter( );
	
private:
	
	virtual void udpate( const void* const target, const type_info& info ) override;
	
	
	//	Cada tipo monitorado.
	class item
	{
	public:
		string name;
		unsigned int increment;
		unordered_map< void*, unsigned int > instances;

		item( const string& name = "" )
			:name( name )
			,increment( 0 )
		{ };
		virtual ~item( ){ };
	};
	//	Conjutos de tipos monitorados.
	using instance_counter_map	=	unordered_map< type_index, item >;
	instance_counter_map items;
};


}}}};
#endif	