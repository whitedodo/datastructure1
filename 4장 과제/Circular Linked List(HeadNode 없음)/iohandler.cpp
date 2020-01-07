/* OOOOOOOOOOOOOO                                                */
/* �й�: 20101215                                                */
/* �̸�: ��OO                                                    */
/* ����: 4�� ����(2) Circular Double Linked List - HeadNode ���� */

#include <iostream>
#include <direct.h>
#include "ddl.h"

using namespace std;


IOHandler::IOHandler(){

}

IOHandler::~IOHandler(){

}

bool IOHandler::InputFile(string Data, Node& pNode){

	bool Check = true;
	int ColumnIDX = 1;
	int i = 0;
	int MaxSize = Data.size();
	string chData, TmpData;
	Node* CreateNode;
	DDList dList;

	while (i < MaxSize)
	{
		chData = Data.substr(i, 1);

		if (chData == " ") // ���� �÷� �ѱ��
		{
			if (ColumnIDX == 1) // Column�� ���� �ڵ� �Է�(������)
			{
				CreateNode = dList.Create(tCode, TmpData);
			}
			else
			{
				CreateNode = dList.Create(tData, TmpData);
			}

			pNode = *dList.Insert(CreateNode, &pNode);
			TmpData.erase(); // �ӽ� ���� �ʱ�ȭ

			ColumnIDX++;
		}

		if (ColumnIDX == 1) // ù �ڵ忡 ���� ������ �ӽ� Append(�߰�)
		{
			if (isdigit(chData.at(0)))
				TmpData.append(chData.c_str());

			else{ Check = false; break; }
		}
		else
		{
			if (chData != " " && chData != "\n") // ������ �ƴ� ��
				TmpData.append(chData.c_str());
		}

		// �� �Ѿ �� ó��
		if (chData.at(0) == '\n')
		{
			if (ColumnIDX > MAXCOLUMNS)  // �ִ� ������ �Ѿ ��
			{
				Check = false;
				break;
			}

			if (ColumnIDX == MAXCOLUMNS) // �����Ͱ� ��ġ�� ��
			{
				CreateNode = dList.Create(tData, TmpData);
				pNode = *dList.Insert(CreateNode, &pNode);

				TmpData.erase();         // �ӽ� ���� �ʱ�ȭ
			}

			if (ColumnIDX < MAXCOLUMNS)  // �ּ� ������ �Ѿ ��
			{
				Check = false;
				break;
			}

			ColumnIDX = 1;   // �÷� �ʱ�ȭ
		}

		i++;
	}

	return Check;

}

void IOHandler::PrintOut(Node pNode, int PrintType, int SortType, int Code){

	switch (PrintType)
	{
		case NORMAL:
			Print_Normal(&pNode, SortType);
			break;

		case SPECIFIC:
			Print_Specific(&pNode, SortType, Code);
			break;
	}
}


void IOHandler::Print_Normal(Node* pNode, int SortType){

	Node* FirstNode;
	Node* PrevNode;
	Node* NextNode;
	
	switch (SortType)
	{
		case ASC:
			FirstNode = pNode;
			PrevNode = FirstNode;

			while (PrevNode != NULL)
			{
				UserView(PrevNode); // ���
				PrevNode = PrevNode->prev;

				if (PrevNode->code == FirstNode->code)
					break;
			}

			break;

		case DESC:
			FirstNode = pNode->next;
			NextNode = FirstNode;

			while (NextNode != NULL)
			{
				UserView(NextNode); // ���
				NextNode = NextNode->next;

				if (NextNode->code == FirstNode->code)
					break;
			}

			break;
	}

}

void IOHandler::Print_Specific(Node* pNode, int Sort, int Code){
	
	Node* FirstNode = pNode;
	Node* NextNode = FirstNode;
	
	bool Escape = false;
	bool Circular = false;

	while (NextNode != NULL)
	{
		switch (Sort)
		{
			case NORMAL:
				
				if (NextNode->code == Code)
				{
					if (Circular == false)
						Circular = true;
					else
					{
						Circular = false;
						Escape = true;
					}
				}

				// ������ ���
				if (Circular == true)
					UserView(NextNode);

				NextNode = NextNode->prev;

				break;

			case REVERSE:

				if (NextNode->code == Code)
				{
					if (Circular == false)
						Circular = true;
				}

				// HeadNode(First)�� �������� ��, Circular�� Prev�� ��ȯ�� ����
				if (NextNode->code == FirstNode->code && Circular == true)
					Escape = true;

				if (Circular == false)
					NextNode = NextNode->prev;
				else{
					UserView(NextNode);         // ���
					NextNode = NextNode->next;
				}

				break;
		}

		if (Escape == true) // Ż��
			break;
	}
}

void IOHandler::UserView(Node* pNode){
	
	Node* FirstNode = pNode;
	Node* DownNode;

	cout << pNode->code << " ";
 	DownNode = pNode->down;

	while (DownNode != NULL)
	{
		cout << DownNode->Data << endl;
		DownNode = DownNode->down;

		if (DownNode->code == FirstNode->code)
			break;

	}
}
