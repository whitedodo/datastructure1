/////////////////////////////////////////////////////////////
////
////  �ݿ��������б� �濵�а� 
////  �й�: 20101215
////  �̸�: �� �� �� ///////////////////////////////////////
////  ���ϸ�: Welcome.H 
////  ����: ���ڿ��� �ϴ� Ÿ��Ʋ ����

#ifndef _WELCOME_H_
#define _WELCOME_H_

#include "structure.h"

// ��Ʈ�� - Ÿ��Ʋ
void Matrix::Intro(){

	cout << "���� �迭�� mxn �� nxp ũ���� ��,";
	cout << " m�� n�� p�� ���� ������� �Է��ϼ��� : ";
}

// �߰� - Ÿ��Ʋ

void Matrix::InsertTitle(int _Type, int _Count){

	// ������ Ÿ��Ʋ �ҷ�����
	switch (_Type)
	{

	case MatrixA:
		cout << "ù��° �迭�� ";
		break;

	case MatrixB:
		cout << "�ι�° �迭�� ";
		break;

	case MatrixC:
		break;

	}

	cout << _Count;
	cout << "���� ���� �Է��ϼ��� : ";

}

#endif