#include <iostream>
#include <fstream>
#include <direct.h>
//#include <unistd.h>
#include "equiv.h"

using namespace std;

ListNode::ListNode(int d)
{
	data = d;
	link = 0;
}

void Equivalence(char* Filename)
{
	ifstream inFile("equiv.in");
	string YourFile;

	////char* Buff = getcwd(NULL, 0); // ������ ��������

	//char* Buff = _getcwd(NULL, 0); // ������ ��������

	//YourFile.append(Buff);
	////YourFile.append("\/");
	//YourFile.append("\\");

	//YourFile.append(Filename);
	//Buff = &YourFile[0];

	//inFile.open(Buff);

	if (!inFile)
	{
		cerr << "������ ���� �����ϴ�. " << endl;
		return;
	}

	int i, j, n;
	inFile >> n;

	ListNodePtr *seq = new ListNodePtr[n];
	Boolean *out = new Boolean[n];

	for (i = 0; i < n; i++) {
		seq[i] = 0;
		out[i] = FALSE;
	}

	// 1. ��ġ���� ������ �о� ���̱�
	inFile >> i >> j;

	while (inFile.good())  // ���� ������ ã��
	{
		ListNode *x = new ListNode(j);
		x->link = seq[i];
		seq[i] = x; // �߰� (j���� seq[i])
		
		ListNode *y = new ListNode(i);
		y->link = seq[j];
		seq[j] = y; // �߰� (i���� seq[j])
		inFile >> i >> j;
	}

	PrintOut(seq, out, n);

	delete[] seq;
	delete[] out;
}


// 2. ��� Ŭ����
void PrintOut(ListNode** seq, Boolean* out, int n){

	int i, j;
	int Cnt = 1;
	for (i = 0; i < n; i++)
	{
		if (out[i] == FALSE) { // ��¿� ���� �κ�

			cout << "��ġ�׷� " << Cnt++ << ": " << i;
			out[i] = TRUE;

			ListNode *x = seq[i];
			ListNode *top = 0; // �ʱ�ȭ Stack

			while (1) // �������� ���� Ŭ���� ã��
			{
				while (x) { // ���μ��� ����Ʈ ã�Ƴ���

					j = x->data;
					
					if (out[j] == FALSE) {

						cout << ", " << j;
						out[j] = TRUE;

						ListNode *y = x->link;

						x->link = top;
						top = x;
						x = y;

					}
					else
						x = x->link;

				} // While�� ��

				if (!top)
					break;
				else {
					x = seq[top->data];
					top = top->link; // UnStack�� ����
				}
			}

			cout << endl;

		} // if���� ��

	}
}
