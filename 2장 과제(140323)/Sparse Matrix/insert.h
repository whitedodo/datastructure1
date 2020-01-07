/////////////////////////////////////////////////////////////
////
////  �ݿ��������б� �濵�а� 
////  �й�: 20101215
////  �̸�: �� �� �� ///////////////////////////////////////
////  ���ϸ�: Insert.H 
////  ����: ����ڷκ��� �����͸� ��ǻ�Ϳ� �Է�.

#ifndef _INSERT_H_
#define _INSERT_H_

#include "structure.h"
#include "welcome.h"
#include "process.h"

using namespace std;

//////////////////// �߰� ���           14.03.23
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////

int Matrix::Insert(int _Status)
{

	switch (_Status)
	{
		case INSERT:

			InsertData(GetM(), GetN(), MatrixA);
			InsertData(GetN(), GetP(), MatrixB);
			return PROCESS;
			break;

		default:

			return FALSE;
			break;

	}

}

void Matrix::InsertData(int _LastRow, int _LastCol, int _Type){

	int CountIDX = 0; // Ƚ�� �Ҵ� ��ȣ - ������
	int RowIDX; // ���� ������
	int ColIDX; // ���� ������ 
	int YourNum;

	InsertTitle(_Type, _LastRow * _LastCol);

	RowIDX = 0;

	while (RowIDX < _LastRow)
	{
		ColIDX = 0;
		while (ColIDX < _LastCol)
		{
			cin >> YourNum;
			InsertMatrix(RowIDX, ColIDX, YourNum, _Type, CountIDX);
			CountIDX++;
			ColIDX++;
		}

		RowIDX++;
	}
	
	// ������ ũ�� ����
	InsertResize(CountIDX, _Type);
}

void Matrix::InsertResize(int _Count, int _Type)
{

	// ������ ũ�� ����
	switch (_Type)
	{

		case MatrixA:
			SetSizeA(_Count);
			break;

		case MatrixB:
			SetSizeB(_Count);
			break;

		case MatrixC:
			SetSizeC(_Count);
			break;

	}
}

void Matrix::InsertMatrix(int _Row, int _Col, int _Num, int _Type, int _IDX)
{
	switch (_Type)
	{
		case MatrixA:
			A_Spas[_IDX].row = _Row;
			A_Spas[_IDX].col = _Col;
			A_Spas[_IDX].value = _Num;
			break;
		
		case MatrixB:
			B_Spas[_IDX].row = _Row;
			B_Spas[_IDX].col = _Col;
			B_Spas[_IDX].value = _Num;
			break;

		case MatrixC:
			C_Spas[_IDX].row = _Row;
			C_Spas[_IDX].col = _Col;
			C_Spas[_IDX].value = _Num;
			break;

	}
}

#endif