#include <iostream>
#include "equiv.h"

using namespace std;
void Equivalence(char*);

// ���� ���� ����(���� �̸� �ľ�)
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
		cout << "���ڰ� �غ�Ǿ� ���� �ʽ��ϴ�." << endl;
	
}