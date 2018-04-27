#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include<TCHAR.H>
#include <chrono>
#include <numeric>
#include <future>


class Decryptor
{
public:
	Decryptor()
	{
		// перевод из чела в символ таблицы ASCI
		for (int i(0); i < SIZE_VecDataS; ++i)
		{
			vecDataS.push_back(((char*)&i)[0]);
			std::cout << vecDataS.at(i) << std::endl;
		}
	}
	// расшифровщик
	static std::string DecryptorRealization(std::string&,
		std::string&,
		const size_t,
		const std::vector<char>&,
		std::vector<size_t>&,
		size_t&);
	// шапка меню
	void aCapMenu(std::string functional(std::string&, std::string&,
		const size_t,
		const std::vector<char>&,
		std::vector<size_t>&, size_t&),
		const size_t,
		std::string&,
		std::string&,
		const std::vector<char>&,
		std::vector<size_t>&);
	
	std::string& getStrPassword() { return strPassword; }
	std::string& getStrCompilation() { return strCompilation; }
	std::vector<char> getVecDataS() { return vecDataS; }
	std::vector<size_t> getVecIndex() { return vecIndex; }

	static const size_t MAXSIZE_StrPassword = 10;
	static const size_t SIZE_VecDataS = 255;

	static size_t& index()
	{
		static size_t index_ = 0;
		return index_;
	}
	virtual~Decryptor() {};
private:
	// вектор с данными каждый элемент символ таблицы ASCI
	std::vector<char> vecDataS;
	// вектор для индексов
	std::vector<size_t> vecIndex;
	// строка пороля;
	std::string strPassword;
	// строка подборки;
	std::string strCompilation;



};
