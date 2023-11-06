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
 * File:   deserializable.hpp
 * Author: Maxwell Aguiar Silva <maxwellaguiarsilva@gmail.com>
 *
 * Created on 2 de janeiro de 2020, 13:09
 */

/*
 * Interface para classes que podem ter seus dados recebidos de um input stream (istream).
 */

//	Pragma once
#ifndef HPP634201726
#define HPP634201726

//	Includes
#include <string>
#include <iostream>
#include <fstream>


//	Namespace ::sak::stream
namespace sak
{
namespace stream
{

//	Using
using std::string;
using std::istream;


//	Interface para deserializar uma classe.
class deserializable
{
public:
	
	//	Construtor e destrutor
	deserializable( ){ };
	virtual ~deserializable( ){ };
	
	//	Carrega os dados serializados a partir de um arquivo.
	const bool load( const string& file_path );
	
private:
	
	//	Remove construtor de cópia
	deserializable( const deserializable& orig ) = delete;
	
	//	Método virtual para deserialização do objeto.
	virtual istream& stream( istream& is )	= 0;
	
	//	Permite usar a função privada "stream" na sobrecarga do operador>> externo ( objeto a direita do operador ).
	friend istream& operator>>( istream& is, deserializable& object );
	
	
};


//	Permite usar o objeto a direita do operador.
inline istream& operator>>( istream& is, deserializable& object ){ return object.stream( is ); };


};};


#endif
