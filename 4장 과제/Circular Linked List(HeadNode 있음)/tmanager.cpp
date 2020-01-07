/* OOOOOOOOOOOOOO                                                */
/* �й�: 20101215                                                */
/* �̸�: ��OO                                                    */
/* ����: 4�� ����(2) Circular Double Linked List - HeadNode      */

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

bool TManager::LoadFile(DDList* List){

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
		Check = io.InputFile(Memo, *List);

	return Check;

}

void TManager::New(DDList* List){
	
	DDList* dList;
	Node* CreateNode;
	string UserTxt;
	string chData, TmpData;
	bool Check = false;
	int i, Size, ColumnIDX;

	while (1)
	{
		dList = new DDList(); // ���� ����

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
					CreateNode = dList->Create(tCode, TmpData);
				else
					CreateNode = dList->Create(tData, TmpData);

				dList->Insert(CreateNode);
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
					CreateNode = dList->Create(tData, TmpData);
					dList->Insert(CreateNode);
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
			List->Insert(dList->GetHeadNode()); // ����
			break;
		}
		else{
			TmpData.erase();         // �ӽ� ���� �ʱ�ȭ
			delete dList;
		}

		UserTxt.erase(); // �Է� ������ �ʱ�ȭ
	}

}

void TManager::Remove(DDList* List){

	int Code;
	cout << "�й��� �Է��ϼ��� : ";
	cin >> Code;

	List->Delete(Code);
}

void TManager::NormalAsc(DDList* List){
	Algorithm Algo;
	IOHandler io;
	
	Algo.Sort(*List, ASC);
	io.PrintOut(List);
}

void TManager::NormalDesc(DDList* List){
	Algorithm Algo;
	IOHandler io;

	Algo.Sort(*List, DESC);
	io.PrintOut(List);
}

void TManager::SpecificAsc(DDList* List){
	Algorithm Algo;
	IOHandler io;

	int Code;
	cout << "�й��� �Է��ϼ��� : ";
	cin >> Code;

	Algo.Sort(*List, ASC);
	io.PrintOut(List, SPECIFIC, NORMAL, Code);

}

void TManager::SpecificDesc(DDList* List){
	Algorithm Algo;
	IOHandler io;

	int Code;
	cout << "�й��� �Է��ϼ��� : ";
	cin >> Code;

	Algo.Sort(*List, ASC);
	io.PrintOut(List, SPECIFIC, REVERSE, Code);

}
