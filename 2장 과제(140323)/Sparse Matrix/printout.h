/////////////////////////////////////////////////////////////
////
////  금오공과대학교 경영학과 
////  학번: 20101215
////  이름: 정 원 영 ///////////////////////////////////////
////  파일명: Printout.H 
////  설명: 출력 영역

#ifndef _PRINTOUT_H_
#define _PRINTOUT_H_

#include "structure.h"

void Matrix::PrintOut(int _Status)
{
	if (GetSizeC() != FALSE)
	{
		cout << "곱셈 결과는 ";

		for (int i = 0; i < GetSizeC(); i++)
		{
			cout << "{" << C_Spas[i].row;
			cout << ",";
			cout << C_Spas[i].col;
			cout << "}=";
			cout << C_Spas[i].value;

			if (i + 1 != GetSizeC())
				cout << ",";
		}

		cout << "입니다." << endl;
	}
}

#endif