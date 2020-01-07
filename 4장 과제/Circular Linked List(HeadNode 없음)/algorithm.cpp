/* OOOOOOOOOOOOOO                                                */
/* �й�: 20101215                                                */
/* �̸�: ��OO                                                    */
/* ����: 4�� ����(2) Circular Double Linked List - HeadNode ���� */

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

	// ���� ����
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

	while (X_DownNode != NULL) // ���� �׸����
	{
		TmpTxt = X_DownNode->Data;
		X_DownNode->Data = Y_DownNode->Data;
		Y_DownNode->Data = TmpTxt;

		if (X_DownNode->down == FirstNode)
			break;
		
		X_DownNode = X_DownNode->down; // ����X_DownNode�� Y_DownNode�� �Ʒ� ���̴� ����.
		Y_DownNode = Y_DownNode->down;
	}

}