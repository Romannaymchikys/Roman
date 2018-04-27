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
			return s = 0;
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
}
std::chrono::nanoseconds Decryptor::Sorted(std::string strPassword)
{
	namespace cr = std::chrono;
	typedef cr::high_resolution_clock my_clock;
	auto startTime = my_clock::now();
	std::vector<std::string>  vecPassword(10, strPassword);
	std::accumulate(vecPassword.begin(),
		vecPassword.end(), std::string());
	std::sort(strPassword.begin(), strPassword.end(),
		                           std::greater<char>());
	auto endTime = my_clock::now();
	auto tookTime = endTime - startTime;
	return cr::duration_cast<cr::nanoseconds>(tookTime);
}
bool Decryptor::RefinementData(const std::string& strPassword,
	                           const std::string& strCompilation) 
{
	typedef std::future<std::chrono::nanoseconds> _futur;
	_futur timeSortedTwo = std::async(Sorted, strCompilation);
	_futur timeSortedOne = std::async(Sorted, strPassword);
	timeSortedTwo.wait();
	timeSortedOne.wait();
	auto resultTime = (timeSortedTwo.get().count() -
		               timeSortedOne.get().count());
	return static_cast<int>(resultTime + abs(resultTime));
}
std::string Decryptor::DecryptorRealization(std::string& strPassword,
	                                        std::string& strCompilation,
	                                        const size_t MAXSIZE_StrPassword,
	                                        const std::vector<char>& vecDataS,
	                                        std::vector<size_t>& vecIndex,
	                                        size_t& count)
{ 
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
		while (vecIndex.at((size_t)vecIndex.size() - 1) !=
			                                          SIZE_VecDataS - 1)
		{
			// проверяем на совпадения
			  if (std::equal(vecIndex.begin(), vecIndex.end(),
				  strPassword.begin(), strPassword.end(),std::equal_to<char>()))
			  {
				  //собираем проверочную строку
				  strCompilation.resize(count);
				  std::transform(vecIndex.begin(),
					  vecIndex.end(), strCompilation.begin(),
					  [&](size_t index)->char { return vecDataS.at(index); });
				  // проверяем равны ли по длине две строки,
				  //но немного другим способом
				  if (RefinementData(strPassword, strCompilation))
				   {
					  return strCompilation;
				   }
				  strCompilation.clear();
			  }
				// итерируем индекс 
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