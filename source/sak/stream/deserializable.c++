//	<editor-fold defaultstate="collapsed" desc="License">
/*
 * Copyright (C) 2020 Maxwell Aguiar Silva <maxwellaguiarsilva@gmail.com>
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
//	License </editor-fold>
//	Autor
/* 
 * File:   deserializable.c++
 * Author: Maxwell Aguiar Silva <maxwellaguiarsilva@gmail.com>
 *
 * Created on 27 de julho de 2022, 22:10
 */

#include <sak/stream/deserializable.hpp>

using ::sak::stream::deserializable;
using ::std::ifstream;

//	Load.
const bool ::deserializable::load( const string& file_path )
{
	ifstream file( file_path );
	if( file.is_open( ) )
		file >> ( *this );
	else
		return false;
	file.close( );
	return true;
};