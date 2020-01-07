/////////////////////////////////////////////////////////////
////
////  �ݿ��������б� �濵�а� 
////  �й�: 20101215
////  �̸�: �� �� �� ///////////////////////////////////////
////  ���ϸ�: Process.H 
////  ����: �������� ���� �����Ǵ� ��. (Process) ó������

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

	// ���� ���� �Ǵ�
	if (Choose == TRUE)
		return RESULT;

	else
		return FALSE;
}

// ����� ����
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

	// ������ ũ�� ����
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