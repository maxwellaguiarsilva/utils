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
 * File:   netbeans_cpp_simple_test.hpp
 * Author: Maxwell Aguiar Silva <maxwellaguiarsilva@gmail.com>
 *
 * Created on 19 de agosto de 2022, 18:17
 */


//	Prama once
#pragma once 
#ifndef HPP964402082
#define HPP964402082

#include <sak/common.hpp>
#include <sak/debug/test_handler/test_handler.hpp>
#include <string>

namespace sak
{
namespace debug
{
namespace test_handler
{;


//	Using.
using ::std::string;
SAK_USING_TEST_HANDLER;


class netbeans_cpp_simple_test : public test_handler
{ENABLE_INSTANCE_COUNTER;
public:
	netbeans_cpp_simple_test( );
	virtual ~netbeans_cpp_simple_test( );
	

	virtual void init( const string& name ) override;
	virtual void validate( bool result, const string& message ) override;
	virtual void test( const string& name ) override;
	
private:
	
	void finish_test( );
	
	
	string suite_name;
	string test_name;
	
	
	//	######################################################################
	//	Textos usados no output do teste simples de c++ no NetBeans (CND 8.2).
	class output_texts
	{ENABLE_INSTANCE_COUNTER;
	public:
		
		//	CTC e DTC.
		output_texts(
			 const string& suite_name
			,const string& test_name
		);
		virtual ~output_texts( ) = default;
		
		//	Strings constatntes.
		const string suite_started		=	"%SUITE_STARTED%";
		const string suite_finished		=	"%SUITE_FINISHED% time=0";

		//	Strings calculadas.
		const string suite_starting( );
		const string test_started( );
		const string test_failed( const string& message );
		const string test_finished( );

		//	Strings com mensagens para o usuário
		struct
		{
			//	Essas strings devem ser externalizadas se possível.
			const string suite_starting		=	"Iniciando suíte de testes: ";
			const string test_starting		=	"Iniciando teste: ";
			const string test_finished		=	"Fim do teste: ";
		} user_messages;
		
	private:
		const string& suite_name;
		const string& test_name;
		
	} text_set;
	//	######################################################################
	
	
	
};


}}};

#endif
