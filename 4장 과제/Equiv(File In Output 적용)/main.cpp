#include <iostream>
#include "equiv.h"

using namespace std;
void Equivalence(char*);

// 인자 존재 여부(파일 이름 파악)
bool IsArgv(int argc, char** argv){
	int i = 0;

	while (i < argc)
	{
		if (i > 1)
			break;
		i++;
	}

	if (i == 2)
		return true;
	else
		return false;
}

char* GetFileName(char** argv){
	return argv[1];
}

int main(int argc, char** argv)
{
	//if (IsArgv(argc, argv) == true)
		Equivalence(GetFileName(argv));
	//else
		cout << "인자가 준비되어 있지 않습니다." << endl;
	
}