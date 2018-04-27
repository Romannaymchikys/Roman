#include <Windows.h>
#include "Decryptor.h"

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Decryptor _Dec;
	_Dec.aCapMenu(Decryptor::DecryptorRealization,
		Decryptor::MAXSIZE_StrPassword,
		_Dec.getStrPassword(),
		_Dec.getStrCompilation(),
		_Dec.getVecDataS(),
		_Dec.getVecIndex());
	system("pause");
}
