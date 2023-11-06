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
 * File:   default_derived.hpp
 * Author: Maxwell Aguiar Silva <maxwellaguiarsilva@gmail.com>
 *
 * Created on 22 de agosto de 2022, 22:31
 */


//	Prama once
#pragma once 
#ifndef HPP970795291
#define HPP970795291


#include <memory>

#ifndef SAK_USING_DEFAULT_DERIVED
#define SAK_USING_DEFAULT_DERIVED				\
using ::std::shared_ptr;						\
using ::std::make_shared;						\
using ::std::unique_ptr;						\
using ::std::make_unique;						\
using ::sak::pattern::default_derived;			\
using ::sak::pattern::shared_default_derived;	\
using ::sak::pattern::unique_default_derived;	\
;
#endif



#ifndef SAK_DECLARE_NAMESPACE_DEFAULT_DERIVED
#define SAK_DECLARE_NAMESPACE_DEFAULT_DERIVED( __BASE_TYPE, __DERIVED_TYPE )	\
namespace __DERIVED_TYPE { class __DERIVED_TYPE; };							\
using SAK_DEFAULT_DERIVED( __BASE_TYPE )	=								\
	::sak::pattern::default_derived< __DERIVED_TYPE::__DERIVED_TYPE >;		\
;
#endif

#ifndef SAK_DECLARE_DEFAULT_DERIVED
#define SAK_DECLARE_DEFAULT_DERIVED( __BASE_TYPE, __DERIVED_TYPE )	\
class __DERIVED_TYPE;												\
using SAK_DEFAULT_DERIVED( __BASE_TYPE )	=						\
	::sak::pattern::default_derived< __DERIVED_TYPE >;				\
;
#endif


#ifndef SAK_DEFAULT_DERIVED
#define SAK_DEFAULT_DERIVED( __BASE_TYPE )	HPP970795291_ ## __BASE_TYPE
#endif




namespace sak
{;
namespace pattern
{;

using ::std::shared_ptr;
using ::std::make_shared;
using ::std::unique_ptr;
using ::std::make_unique;

template<
	 class _T1
	,class _T2	= typename _T1::derived_type
	,class... _TYPE_ARGS
>
	requires ::std::is_base_of< _T1, _T2 >::value
shared_ptr< _T1 > shared_default_derived( _TYPE_ARGS... args )
{
	return make_shared< _T2 >( &args... );
};

template<
	 class _T1
	,class _T2	= typename _T1::derived_type
	,class... _TYPE_ARGS
>
	requires ::std::is_base_of< _T1, _T2 >::value
unique_ptr< _T1 > unique_default_derived( _TYPE_ARGS... args )
{
	return make_unique< _T2 >( &args... );
};



template< class _T1 >
class default_derived
{
private:
	typedef _T1 derived_type;
	
	
	template<
		class _ST1
	   ,class _ST2
	   ,class... _TYPE_ARGS
	>
		requires ::std::is_base_of< _ST1, _ST2 >::value
	friend shared_ptr< _ST1 > shared_default_derived( _TYPE_ARGS... args );
	

	template<
		 class _ST1
		,class _ST2
		,class... _TYPE_ARGS
	>
		requires ::std::is_base_of< _ST1, _ST2 >::value
	friend unique_ptr< _ST1 > unique_default_derived( _TYPE_ARGS... args );

};


}};
#endif
