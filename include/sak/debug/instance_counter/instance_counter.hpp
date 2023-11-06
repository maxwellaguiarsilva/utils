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
 * File:   instance_counter.hpp
 * Author: Maxwell Aguiar Silva <maxwellaguiarsilva@gmail.com>
 *
 * Created on 15 de agosto de 2022, 20:56
 */


#pragma once 
#ifndef HPP317391888
#define HPP317391888


//	Includes.
#include <typeinfo>
#include <typeindex>
#include <sak/common.hpp>
#include <sak/debug/debug.hpp>	//	::sak::debug::get_real_type_name



//	Habilita o contador de instâncias quando declarado dentro de uma classe ou struct.
#ifndef ENABLE_INSTANCE_COUNTER
#define ENABLE_INSTANCE_COUNTER	\
private: ::sak::debug::instance_counter::enable_instance_counter hpp317391888_enable{ typeid( *this ) };
#endif




//	Namespace
namespace sak
{;
namespace debug
{;
namespace instance_counter
{;



//	Using.
using ::std::type_index;
using ::std::type_info;
using ::std::shared_ptr;



class enable_instance_counter;
SAK_DECLARE_NAMESPACE_DEFAULT_DERIVED( instance_counter, local_instance_counter );


//	Conta as instâncias criadas na aplicação.
class instance_counter
	:public SAK_DEFAULT_DERIVED( instance_counter )
{
public:
	
	instance_counter( ) = default;
	virtual ~instance_counter( ) = default;
	
private:
	virtual void udpate( const void* const target, const type_info& info ) = 0;
	
	friend class enable_instance_counter;
	
};


//	Obtem a instância estática da implementação padrão do contador de instâncias.
instance_counter& default_instance_counter( const shared_ptr< instance_counter >& target = nullptr );

//	Classe base que habilita a contagem de instâncias.
class enable_instance_counter
{
public:
	enable_instance_counter( const type_info& info )
		:info( info )
	{
		#ifndef DISABLE_INSTANCE_COUNTER
			::sak::debug::instance_counter::default_instance_counter( ).udpate( this, info );
		#endif
	};
	virtual ~enable_instance_counter( )
	{
		#ifndef DISABLE_INSTANCE_COUNTER
			::sak::debug::instance_counter::default_instance_counter( ).udpate( this, info );
		#endif
	};
private:
	const type_info& info;
};



}}};


//	default_derived.
#include <sak/debug/instance_counter/local_instance_counter/local_instance_counter.hpp>

#endif
