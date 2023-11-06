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
 * File:   local_instance_counter.c++
 * Author: Maxwell Aguiar Silva <maxwellaguiarsilva@gmail.com>
 *
 * Created on 17 de agosto de 2022, 22:06
 */


#include <sak/debug/instance_counter/local_instance_counter/local_instance_counter.hpp>



//	Using.
SAK_USING_LINES;
SAK_USING_IOS;
using ::sak::debug::instance_counter::local_instance_counter::local_instance_counter;
using ::sak::debug::get_real_type_name;



//
local_instance_counter::~local_instance_counter( )
{
	
	cout
		<<	line_type_d
		<<	endl
	;
	for( const auto& item : items )
	{
		const auto& target	=	item.second;
		if( target.instances.size( ) > 0 )
			cout	
				<<	"Possible memory leak: "
				<<	target.name
				<<	" => "
				<<	target.instances.size( )
				<<	endl
			;
	};
	cout
		<<	line_type_d
		<<	endl
	;
};


//	
void local_instance_counter::udpate( const void* const target, const type_info& info )
{
	
	//	Contador baseado no nome do tipo.
	const type_index&	target_index	=	type_index( info );
	const string&		target_name		=	get_real_type_name( info.name( ) );
	
	if( !( items.contains( target_index ) ) )
		items.try_emplace( target_index, target_name );
	
	const bool constructor		=	!(
		items[ target_index ].instances.contains( ( void* )target )
	);
	
	unsigned int	id;
	
	if( constructor )
		items[ target_index ]
			.instances[ ( void* )target ] = ( id = ++( items[ target_index ].increment ) );
	else	{
		id	=	items[ target_index ].instances[ ( void* )target ];
		items[ target_index ].instances.erase( ( void* )target );
	}
	
	using ::std::to_string;
	cout
		<<	setw( 50 )	<<	left
		<<	( constructor ? "(+) " : "(-) " ) + target_name
		<<	setw( 15 )	<<	left
		<<	"ID = " + to_string( id )
		<<	setw( 15 )	<<	left
		<<	"TOTAL = " + to_string( items[ target_index ].instances.size( ) )
		<<	endl
	;
	
};