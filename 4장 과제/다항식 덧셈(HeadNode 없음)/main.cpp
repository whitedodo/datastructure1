/*    OOOOOOOOOOO �濵�а�
	  �й�: 20101215
	  �̸�: �� O O
	  ����: 4�� (3��) - ���׽� ���� (HeadNode ����)
*/

#include <iostream>
#include "polynomial.h"

using namespace std;

void PrintTitle(int);

int main()
{
	PolyNode X, Y, Result;
	List PolyList;
	PolyNomial Poly;

	cout << "ù��°";
	PolyList.Write(X);

	cout << "�ι�°";
	PolyList.Write(Y);

	Result = *Poly.Multiply(&X, &Y);

 	cout << "�� ���׽��� ���� : ";
	Poly.PrintOut(Result);
}
