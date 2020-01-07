/* OOOOOOOOOOOOOO                                                */
/* 학번: 20101215                                                */
/* 이름: 정OO                                                    */
/* 과제: 4장 과제(2) Circular Double Linked List - HeadNode 제거 */

#include <iostream>
#include <string>
#include <direct.h>
#include "ddl.h"

using namespace std;

DDList::DDList(){
}

DDList::~DDList(){
}

Node* DDList::Insert(Node* createNode, Node* pNode){

	Node* PrevNode, *FirstNode;
	Node* NextNode = pNode;
	Node* CurNode;

	if (pNode->up == NULL)
	{
		pNode = createNode;
		pNode->prev = pNode;
		pNode->next = pNode;
		pNode->up = pNode;
		pNode->down = pNode;
	}
	else
	{
		if (createNode->type == tCode)
		{
			FirstNode = pNode->down;
			FirstNode = FirstNode->next;
			PrevNode = pNode->down;
			PrevNode->next = createNode;
			
			CurNode = PrevNode->next;
			FirstNode->prev = CurNode;

			CurNode->prev = PrevNode;
			CurNode->next = FirstNode;
			CurNode->up = CurNode;
			CurNode->down = CurNode;

			pNode = CurNode;
		}
		else
		{
			FirstNode = NextNode->down;
			PrevNode = pNode->up;
			createNode->down = FirstNode;
			createNode->up = PrevNode;
			FirstNode->up = createNode;
			PrevNode->down = FirstNode->up;
			pNode = PrevNode->down;
		}
	}

	return pNode;

}

Node* DDList::Delete(int _Code, Node* pNode){

	Node* CurNode;
	Node* FirstNode = pNode->down;
	FirstNode = FirstNode->next;
	Node* NextNode = pNode->down;
	NextNode = NextNode->next;

	// 환형 더블리스트이므로 마지막 부위가 First인점
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
		NextNode = NextNode->next;

		// NextNode가 First에 도달할 때
		if (NextNode->code == FirstNode->code)
			break;
	
	}

	return NextNode;

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