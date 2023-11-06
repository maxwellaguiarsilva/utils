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
 * File:   singleton_ptr.hpp
 * Author: Maxwell Aguiar Silva <maxwellaguiarsilva@gmail.com>
 *
 * Created on 7 de agosto de 2022, 16:51
 */


#pragma	once
#ifndef HPP247547271
#define HPP247547271


//	Includes.
#include <iomanip>
#include <memory>
#include <iostream>
#include <sak/debug/instance_counter/instance_counter.hpp>



namespace sak
{;
namespace pattern
{;



//	using.
using ::std::cout;
using ::std::endl;
using ::std::shared_ptr;
using ::std::make_shared;
using ::sak::debug::instance_counter::enable_instance_counter;


//	Ponteiro (smart_ptr) que garante a existência de apenas uma instância da classe informada.
template< class _T1 >
class singleton_ptr
{ENABLE_INSTANCE_COUNTER;
public:
	
	singleton_ptr( )
	{
		if( !init( ) )
			init( make_shared< _T1 >( ) );
	};
	virtual ~singleton_ptr( ){ };
	

	//	Recebe como parâmetro um singleton_ptr de uma classe derivada (filha).
	//	Isso deletará a instância anterior, trocando pela nova.
	template< class _T2 >
		requires	::std::is_base_of< _T1, _T2 >::value
	singleton_ptr( const singleton_ptr< _T2 >& other )
	{
		init( other.init( ) );	
	};
	
	//	Consumo do objeto instanciado.
	inline _T1& get(  ) { return *( init( ) ); };
	inline operator _T1& ( ) { return get( ); };
	inline _T1& operator*( ) { return get( ); };
	inline _T1* operator->( ) { return &get( ); };
	
	
//	singleton_ptr( singleton_ptr &other ) = default;
//	void operator=( const singleton_ptr & ) = default;

private:
	
	template< class _T2 >
	friend class singleton_ptr;
	
	shared_ptr< _T1 >& init( const shared_ptr< _T1 >& target = nullptr ) const
	{
		static shared_ptr< _T1 > instance;
		if( target )
			instance	=	target;	
		return instance;
	};
	
};



};};

#endif