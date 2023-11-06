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
 * File:   serializable.hpp
 * Author: Maxwell Aguiar Silva <maxwellaguiarsilva@gmail.com>
 *
 * Created on 2 de janeiro de 2020, 13:09
 */

/*
 * Interface para classes que podem ter seus dados enviados para um output stream (ostream).
 */


//	Pragma once
#ifndef HPP285838337
#define HPP285838337


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
using ::std::string;
using ::std::ostream;


//	Interface para serializar uma classe.
class serializable
{
public:
	
	//	Construtor e destrutor.
	serializable( ){ };
	virtual ~serializable( ){ };
	
	//	Salva os dados serializados para um arquivo.
	const bool save( const string& file_path ) const;
	
	
private:
	
	//	Remove construtor de cópia.
	serializable( const serializable& orig ) = delete;
	
	//	Método virtual para serialização do objeto.
	virtual ostream& stream( ostream& os )	const	= 0;
	
	//	Permite usar a função privada "stream" na sobrecarga do operador<< externo ( objeto a direita do operador ).
	friend ostream& operator<<( ostream& os, const serializable& object );
	
	
};


//	Permite usar o objeto a direita do operador.
inline ostream& operator<<( ostream& os, const serializable& object ){ return object.stream( os ); };


};};


#endif

