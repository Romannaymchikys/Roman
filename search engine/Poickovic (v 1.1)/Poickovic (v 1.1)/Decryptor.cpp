#include "Decryptor.h"

class UnaryFunction
{
	bool selector = false;
public:
	size_t operator()(size_t& s)
	{
		if (s == Decryptor::SIZE_VecDataS)
		{
			selector = true;
			return s = Decryptor::index();
		}
		if (selector) {
			selector = false;
			return ++s;
		}
	}
};
void iteration(std::vector<size_t>& vecIndex)
{
	if (vecIndex.at(0) != Decryptor::SIZE_VecDataS) {
		++vecIndex.at(0);
	}
	if (vecIndex.at((size_t)vecIndex.size() - 1) == Decryptor::index() + 1) {
		++Decryptor::index();
	}
}
std::string Decryptor::DecryptorRealization(std::string& strPassword,
	std::string& strCompilation,
	const size_t MAXSIZE_StrPassword,
	const std::vector<char>& vecDataS,
	std::vector<size_t>& vecIndex,
	size_t& count)
{
	index() = 0;
	// собираем комбинации покера количество элементов	
	//в комбинации не достигнет maxSizeStrPassword
	if (count < MAXSIZE_StrPassword)
	{
		// заполняем вектор индексов начальными элементоми vecDataS
		vecIndex.resize(count);
		std::fill(vecIndex.begin(), vecIndex.end(), 0);
		//находимся в цикле покудо последний элемент vecIndex
		//не будет равен  SIZE_VecDataS т. к. 
		//итерация происходит с левао на право поэтому
		std::vector<size_t> vecIndexCopy;
		while (index() != SIZE_VecDataS - 1)
		{
			vecIndexCopy.resize(vecIndex.size());
			std::copy(vecIndex.begin(), vecIndex.end(), vecIndexCopy.begin());
			do {
				// проверяем на совпадения
				if (std::equal(vecIndexCopy.begin(), vecIndexCopy.end(),
					strPassword.begin(), strPassword.end(), std::equal_to<char>()))
				{
					//собираем проверочную строку
					strCompilation.resize(count);
					std::transform(vecIndexCopy.begin(),
						vecIndexCopy.end(), strCompilation.begin(),
						[&](size_t index)->char { return vecDataS.at(index); });
						return strCompilation;
				}
			} while (std::prev_permutation(vecIndexCopy.begin(), vecIndexCopy.end()));
			vecIndexCopy.clear();
			// итерируем
			iteration(vecIndex);
			//проверяем ненужно ли увеличивать
			// числа справо от итерируемого числа
			std::for_each(vecIndex.begin(), vecIndex.end(), UnaryFunction());
		}
		vecIndex.clear();
		return DecryptorRealization(strPassword, strCompilation,
			MAXSIZE_StrPassword,
			vecDataS, vecIndex, ++count);
	}
	return " did not come down ";
}
void Decryptor::aCapMenu(std::string functional(std::string&, std::string&,
	const size_t,
	const std::vector<char>&,
	std::vector<size_t>&, size_t&),
	const size_t MAXSIZE_StrPassword,
	std::string& strPassword,
	std::string& strCompilation,
	const std::vector<char>& vecDataS,
	std::vector<size_t>& vecIndex)
{
	size_t count = 1;
	std::cout << "password to inter:" << std::endl;
	std::cin >> strPassword;
	std::cout << functional(strPassword, strCompilation,
		MAXSIZE_StrPassword, vecDataS, vecIndex, count) << std::endl;
	return;
}