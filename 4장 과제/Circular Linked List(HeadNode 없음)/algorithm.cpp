/* OOOOOOOOOOOOOO                                                */
/* 학번: 20101215                                                */
/* 이름: 정OO                                                    */
/* 과제: 4장 과제(2) Circular Double Linked List - HeadNode 제거 */

#include <iostream>
#include <string>
#include "ddl.h"

using namespace std;

Node* Algorithm::Sort(Node* pNode){

	Node newNode = *pNode;
	Node* FirstNode = newNode.down;
	FirstNode = FirstNode->next;

	Node* X_Node = newNode.down;
	Node* Y_Node = NULL, *MinNode = NULL, TmpNode;

	// 버블 정렬
	while (X_Node != NULL)
	{
		Y_Node = FirstNode;

		while (Y_Node != NULL)
		{
			if (X_Node->code > Y_Node->code){
				Swap(X_Node, Y_Node);
			}

			if (Y_Node->next == FirstNode)
				break;

			Y_Node = Y_Node->next;
		
		} // end of while

		if (X_Node->next == FirstNode)
			break;

		X_Node = X_Node->next;
			
	}// end of while

	return X_Node;

}

void Algorithm::Swap(Node* X_Node, Node* Y_Node){
	int TmpNum;
	string TmpTxt;

	Node* FirstNode = X_Node;

	TmpNum = X_Node->code;
	X_Node->code = Y_Node->code;
	Y_Node->code = TmpNum;

	Node* X_DownNode = X_Node->down;
	Node* Y_DownNode = Y_Node->down;

	while (X_DownNode != NULL) // 하위 항목까지
	{
		TmpTxt = X_DownNode->Data;
		X_DownNode->Data = Y_DownNode->Data;
		Y_DownNode->Data = TmpTxt;

		if (X_DownNode->down == FirstNode)
			break;
		
		X_DownNode = X_DownNode->down; // 참고X_DownNode나 Y_DownNode나 아래 깊이는 같음.
		Y_DownNode = Y_DownNode->down;
	}

}