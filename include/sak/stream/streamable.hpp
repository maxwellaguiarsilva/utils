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
 * File:   Streamable.hpp
 * Author: Maxwell Aguiar Silva <maxwellaguiarsilva@gmail.com>
 *
 * Created on 2 de janeiro de 2020, 13:09
 */
/*
 * Interface para classes que podem ter seus dados transmitidos atrásves de streams.
 */

//	Pragma once
#ifndef HPP968314564
#define HPP968314564

//	Includes
#include <sak/stream/serializable.hpp>
#include <sak/stream/deserializable.hpp>


//	Namespace ::sak::stream
namespace sak
{
namespace stream
{

//	Using
using ::sak::stream::serializable;
using ::sak::stream::deserializable;

	
//	Interface para serializar/deserializar uma classe.
class Streamable 
	:public serializable
	,public deserializable
{
public:
	
	//	Construtor e destrutor
	Streamable( ) { };
	virtual ~Streamable( ) { };
	
	
private:
	
	//	Remove construtor de cópia
	Streamable( const Streamable& orig ) = delete;
		
	
};


};};


#endif
