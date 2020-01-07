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

	////char* Buff = getcwd(NULL, 0); // 현재경로 가져오기

	//char* Buff = _getcwd(NULL, 0); // 현재경로 가져오기

	//YourFile.append(Buff);
	////YourFile.append("\/");
	//YourFile.append("\\");

	//YourFile.append(Filename);
	//Buff = &YourFile[0];

	//inFile.open(Buff);

	if (!inFile)
	{
		cerr << "파일을 열수 없습니다. " << endl;
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

	// 1. 동치관계 데이터 읽어 들이기
	inFile >> i >> j;

	while (inFile.good())  // 파일 끝까지 찾기
	{
		ListNode *x = new ListNode(j);
		x->link = seq[i];
		seq[i] = x; // 추가 (j부터 seq[i])
		
		ListNode *y = new ListNode(i);
		y->link = seq[j];
		seq[j] = y; // 추가 (i부터 seq[j])
		inFile >> i >> j;
	}

	PrintOut(seq, out, n);

	delete[] seq;
	delete[] out;
}


// 2. 출력 클래스
void PrintOut(ListNode** seq, Boolean* out, int n){

	int i, j;
	int Cnt = 1;
	for (i = 0; i < n; i++)
	{
		if (out[i] == FALSE) { // 출력에 관한 부분

			cout << "동치그룹 " << Cnt++ << ": " << i;
			out[i] = TRUE;

			ListNode *x = seq[i];
			ListNode *top = 0; // 초기화 Stack

			while (1) // 존재하지 않은 클래스 찾기
			{
				while (x) { // 프로세스 리스트 찾아내기

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

				} // While문 끝

				if (!top)
					break;
				else {
					x = seq[top->data];
					top = top->link; // UnStack의 원리
				}
			}

			cout << endl;

		} // if문의 끝

	}
}
