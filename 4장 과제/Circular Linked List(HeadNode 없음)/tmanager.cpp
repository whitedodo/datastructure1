/* OOOOOOOOOOOOOO                                                */
/* �й�: 20101215                                                */
/* �̸�: ��OO                                                    */
/* ����: 4�� ����(2) Circular Double Linked List - HeadNode ���� */

#include <iostream>
#include <fstream>
#include <direct.h>
#include "ddl.h"

using namespace std;

TManager::TManager(){

}

TManager::~TManager(){

}

void PrintTitle(){
	cout << "�л��� �̸��� �й��� ����� ������ �Է��ϼ��� : ";
}

void TManager::PrintMenu(){

	cout << "==========================================" << endl;
	cout << "(1) �� �л� �Է�" << endl;
	cout << "(2) �л� ����" << endl;
	cout << "(3) �й� ������ ��ü ���" << endl;
	cout << "(4) �й� �������� ��ü ���" << endl;
	cout << "(5) Ư�� �й����� ��ü ���" << endl;
	cout << "(6) Ư�� �й����� ù�л����� ���� ���" << endl;
	cout << "(7) ����" << endl;
	cout << "==========================================" << endl;
	cout << "���ϴ� ����� �����ϼ��� : ";
}

bool TManager::LoadFile(Node* pNode){

	bool Check = false;

	ifstream Read;
	IOHandler io;
	string UserTxt, FileName, Tmp, Memo;

	char* Buff = _getcwd(NULL, 0); // ������ ��������

	PrintTitle(); // Ÿ��Ʋ ��� - friend �Լ�

	cin.sync();
	std::getline(cin, UserTxt);

	FileName.append(Buff); // Windows ��� �׽�Ʈ
	FileName.append("\\");

	FileName.append(UserTxt);
	Buff = &FileName[0];

	Read.open(Buff);

	while (getline(Read, Tmp))
	{
		Memo.append(Tmp);
		Memo.append("\n");
		Check = true;
	}

	if (Check == true)
		Check = io.InputFile(Memo, *pNode);

	return Check;

}

void TManager::New(Node* pNode){
	
	DDList dList;
	Node* FirstNode = pNode;
	Node* CreateNode;
	string UserTxt;
	string chData, TmpData;
	bool Check = false;
	int i, Size, ColumnIDX;

	while (1)
	{
		cout << "�й��� �̸��� �Է��ϼ��� : ";

		cin.sync();
		std::getline(cin, UserTxt);
		
		Size = UserTxt.size();
		
		ColumnIDX = 1;

		i = 0;
		while (i < Size)
		{
			chData = UserTxt.substr(i, 1);

			if (chData == " ")
			{
				if (ColumnIDX == 1)
					CreateNode = dList.Create(tCode, TmpData);
				else
					CreateNode = dList.Create(tData, TmpData);

				pNode = dList.Insert(CreateNode, pNode);
				TmpData.erase();

				ColumnIDX++;
			}

			if (ColumnIDX == 1)
			{
				if (isdigit(chData.at(0)))
					TmpData.append(chData.c_str());
				else
					break;
			}
			else
			{
				if (chData != " ")
					TmpData.append(chData.c_str());
			}

			if ((i + 1) == Size)
			{
				if (ColumnIDX > MAXCOLUMNS)  // �ִ� ������ �Ѿ ��
					break;

				if (ColumnIDX == MAXCOLUMNS) // �����Ͱ� ��ġ�� ��
				{
					CreateNode = dList.Create(tData, TmpData);
					pNode = dList.Insert(CreateNode, pNode);
					Check = true;
					break;
				}

				if (ColumnIDX < MAXCOLUMNS)  // �ּ� ������ �Ѿ ��
					break;
			}

			i++;
		}

		// ������ ���� ��
		if (Check == true){
			//pNode = dList.Insert(FirstNode, pNode); // ����
			break;
		}
		else{
			TmpData.erase();         // �ӽ� ���� �ʱ�ȭ
		}

		UserTxt.erase(); // �Է� ������ �ʱ�ȭ
	}

}

void TManager::Remove(Node* pNode){

	DDList dList;
	int Code;
	cout << "�й��� �Է��ϼ��� : ";
	cin >> Code;

	pNode = dList.Delete(Code, pNode);
}

void TManager::NormalAsc(Node pNode){
	Algorithm Algo;
	IOHandler io;

	Node* dNode = Algo.Sort(&pNode);
	io.PrintOut(*dNode, NORMAL, ASC);
}

void TManager::NormalDesc(Node pNode){
	Algorithm Algo;
	IOHandler io;

	Node* dNode = Algo.Sort(&pNode);
	io.PrintOut(*dNode, NORMAL, DESC);
}

void TManager::SpecificAsc(Node pNode){
	Algorithm Algo;
	IOHandler io;

	int Code;
	cout << "�й��� �Է��ϼ��� : ";
	cin >> Code;
	
	Node* dNode = Algo.Sort(&pNode);
	io.PrintOut(*dNode, SPECIFIC, NORMAL, Code);

}

void TManager::SpecificDesc(Node pNode){
	Algorithm Algo;
	IOHandler io;

	int Code;
	cout << "�й��� �Է��ϼ��� : ";
	cin >> Code;

	Node* dNode = Algo.Sort(&pNode);
	io.PrintOut(*dNode, SPECIFIC, REVERSE, Code);

}
