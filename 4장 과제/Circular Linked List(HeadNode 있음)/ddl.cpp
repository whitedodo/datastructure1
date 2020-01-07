/* OOOOOOOOOOOOOO                                                */
/* 학번: 20101215                                                */
/* 이름: 정OO                                                    */
/* 과제: 4장 과제(2) Circular Double Linked List - HeadNode      */

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
		if (createNode->type == tCode){ // down이 아닐 때(하위 항목이 아닐 때)
			createNode->prev = TopNode; // 이전 주소 정하기
			createNode->next = HeadNode;
			TopNode->next = createNode; // 다음 주소 정하기
			TopNode = TopNode->next;    // 주소 넘기기 
		}
		else // down일 때
		{
			NextNode = TopNode;
			PrevNode = NextNode;

			while (NextNode != NULL)
			{
				PrevNode = NextNode;
				NextNode = NextNode->down;
			}

			createNode->up = PrevNode;   // 다음 주소 배정
			PrevNode->down = createNode; // 이전 주소 배정

			NextNode = createNode;       // 최상위 배정
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
		
		// NextNode가 TopHead에 도달할 때
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