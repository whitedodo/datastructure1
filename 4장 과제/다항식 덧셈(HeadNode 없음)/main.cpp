/*    OOOOOOOOOOO 경영학과
	  학번: 20101215
	  이름: 정 O O
	  과제: 4장 (3번) - 다항식 곱셈 (HeadNode 제거)
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

	cout << "첫번째";
	PolyList.Write(X);

	cout << "두번째";
	PolyList.Write(Y);

	Result = *Poly.Multiply(&X, &Y);

 	cout << "두 다항식의 곱은 : ";
	Poly.PrintOut(Result);
}
