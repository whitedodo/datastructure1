/////////////////////////////////////////////////////////////
////
////  �ݿ��������б� �濵�а� 
////  �й�: 20101215
////  �̸�: �� �� �� ////////////////////////////////////////
////  ���ϸ�: 20101215_main.cpp
////  ����: ���� ����

#include <iostream>
#include "function.h"

using namespace std;

int main()
{
	Multi *MultiApp = new Multi();
	int coNum;
	int expNum;
	int Status;

	Status = FIRST;

	while (1)
	{
		// ����� �Է�
		if (Status != RESULT)
			cin >> coNum >> expNum;

		if (coNum != 0)
			MultiApp->Input(coNum, expNum, Status);		// ��ǻ�Ϳ� �Է�

		// ���� �ľ�
		if ((expNum == 0) && Status == FIRST)
		{
			Status = SECOND;
		}
		else if ((expNum == 0) && Status == SECOND)
		{
			Status = RESULT;
		}

		// �Է��� �� �Ǿ��� �� - ��ǻ�Ͱ� ó���ϴ� ���� ����
		if (Status == RESULT)
		{
			// ���� ó��
			MultiApp->Calculate(Status);

			// ���
			MultiApp->PrintOut(Status);

			// �Ҹ�
			MultiApp->~Multi();

			break;
		}

	}


}