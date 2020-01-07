/////////////////////////////////////////////////////////////
////
////  금오공과대학교 경영학과 
////  학번: 20101215
////  이름: 정 원 영 ///////////////////////////////////////
////  파일명: Process.H 
////  설명: 희소행렬의 곱이 구현되는 곳. (Process) 처리영역

#ifndef _PROCESS_H
#define _PROCESS_H

#include "structure.h"

using namespace std;

int Matrix::Calculate(int _Type)
{
	int Choose = FALSE;

	switch (_Type)
	{

	case PROCESS:
		Multiply(YES);
		Choose = TRUE;
		break;

	default:
		break;

	}

	// 성공 여부 판단
	if (Choose == TRUE)
		return RESULT;

	else
		return FALSE;
}

// 행렬의 곱셈
void Matrix::Multiply(int _Process)
{
	int x, y;
	int Sum = 0;
	int CountIDX = 0;

	x = 0;
	while (x < GetM())
	{
		y = 0;
		while (y < GetP())
		{
			Sum = ValueOfMatrix(x, y);

			if (Sum != 0)
			{
				InsertMatrix(x, y, Sum, MatrixC, CountIDX);
				CountIDX++;
			}

			y++;
		}
		x++;
	}

	// 희소행렬 크기 지정
	InsertResize(CountIDX, MatrixC);

}

int Matrix::ValueOfMatrix(int _TargetRows, int _TargetCols)
{
	int i = 0;

	int NumA = 0, NumB = 0, NumC = 0;

	int B_Rows = 0;

	i = 0;
	while (i < GetSizeA())
	{
		NumA = 0;
		NumB = 0;
		if (A_Spas[i].row == _TargetRows)
		{
			NumA = A_Spas[i].value;
			NumB = B_ValueOfMatrix(B_Rows, _TargetCols);
			B_Rows++;
		}

		if (NumA != 0 && NumB != 0)
			NumC = NumC + (NumA * NumB);

		i++;
	}

	return NumC;
}

int Matrix::B_ValueOfMatrix(int _TargetRows, int _TargetCols)
{
	int i;
	int Num = 0;

	i = 0;
	while (i < GetSizeB())
	{
		if (B_Spas[i].row == _TargetRows && B_Spas[i].col == _TargetCols)
		{
			Num = B_Spas[i].value;
			break;
		}
		i++;
	}

	return Num;
}

#endif