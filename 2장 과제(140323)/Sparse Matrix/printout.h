/////////////////////////////////////////////////////////////
////
////  �ݿ��������б� �濵�а� 
////  �й�: 20101215
////  �̸�: �� �� �� ///////////////////////////////////////
////  ���ϸ�: Printout.H 
////  ����: ��� ����

#ifndef _PRINTOUT_H_
#define _PRINTOUT_H_

#include "structure.h"

void Matrix::PrintOut(int _Status)
{
	if (GetSizeC() != FALSE)
	{
		cout << "���� ����� ";

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

		cout << "�Դϴ�." << endl;
	}
}

#endif