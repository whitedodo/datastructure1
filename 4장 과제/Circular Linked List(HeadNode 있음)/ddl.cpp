/* OOOOOOOOOOOOOO                                                */
/* �й�: 20101215                                                */
/* �̸�: ��OO                                                    */
/* ����: 4�� ����(2) Circular Double Linked List - HeadNode      */

#include <iostream>
#include <string>
#include <direct.h>
#include "ddl.h"

using namespace std;

DDList::DDList(){
	HeadNode = NULL;
	TopNode = NULL;
}

DDList::~DDList(){
	HeadNode = NULL;
	TopNode = NULL;
}

void DDList::Insert(Node* createNode){

	Node* NextNode = HeadNode;
	Node* PrevNode;

	if (NextNode == NULL)
	{
		HeadNode = createNode;
		TopNode = HeadNode;
		HeadNode->next = TopNode;
	}
	else
	{
		if (createNode->type == tCode){ // down�� �ƴ� ��(���� �׸��� �ƴ� ��)
			createNode->prev = TopNode; // ���� �ּ� ���ϱ�
			createNode->next = HeadNode;
			TopNode->next = createNode; // ���� �ּ� ���ϱ�
			TopNode = TopNode->next;    // �ּ� �ѱ�� 
		}
		else // down�� ��
		{
			NextNode = TopNode;
			PrevNode = NextNode;

			while (NextNode != NULL)
			{
				PrevNode = NextNode;
				NextNode = NextNode->down;
			}

			createNode->up = PrevNode;   // ���� �ּ� ����
			PrevNode->down = createNode; // ���� �ּ� ����

			NextNode = createNode;       // �ֻ��� ����
		}
	}
}

void DDList::Delete(int _Code){

	Node* CurNode;
	Node* NextNode = HeadNode;
	Node* PrevNode = NextNode;

	while (NextNode != NULL)
	{
		if (_Code == NextNode->code)
		{
			PrevNode->next = NextNode->next;
			CurNode = NextNode;
			NextNode = NextNode->next;
			NextNode->prev = PrevNode;
			
			delete CurNode;
			break;
		}

		PrevNode = NextNode;
		
		// NextNode�� TopHead�� ������ ��
		if (NextNode == TopNode)
			break;
		
		NextNode = NextNode->next;

	}

}


Node* DDList::Create(int _Type, string Data){
	
	Node* CreateNode = new Node();
	int Num;

	switch (_Type)
	{
		case tCode:

			Num = atoi(Data.c_str());
			CreateNode->type = tCode;
			CreateNode->code = Num;
			CreateNode->up = NULL;
			CreateNode->down = NULL;
			CreateNode->prev = NULL;
			CreateNode->next = NULL;

			break;

		case tData:

			CreateNode->type = tData;
			CreateNode->Data = Data;
			CreateNode->up = NULL;
			CreateNode->down = NULL;
			CreateNode->prev = NULL;
			CreateNode->next = NULL;

			break;
	}

	return CreateNode;

}