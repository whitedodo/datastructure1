/////////////////////////////////////////////////////////////
////
////  �ݿ��������б� �濵�а� 
////  �й�: 20101215
////  �̸�: �� �� �� ////////////////////////////////////////
////  ���ϸ�: Matrix.CPP
////  ����: Gom do ri - Sparse Matrix ......................

#include <iostream>
#include "structure.h"
#include "welcome.h"
#include "insert.h"
#include "printout.h"

using namespace std;

void main()
{
	int m, n, p;
	int Status = FALSE;
	Matrix *MatrixApp = NULL;

	MatrixApp->Intro();
	cin >> m >> n >> p;
	
	// Matrix ���� ����
	if (m != 0 || n != 0 || p != 0){
		MatrixApp = new Matrix(m, n, p);
		Status = INSERT;
	}
	else
		Status = FALSE;


	// �ű� �� �ޱ�
	Status = MatrixApp->Insert(Status);
	
	// ���� ó��
	Status = MatrixApp->Calculate(Status);

	// ��� ó��
	MatrixApp->PrintOut(Status);

}