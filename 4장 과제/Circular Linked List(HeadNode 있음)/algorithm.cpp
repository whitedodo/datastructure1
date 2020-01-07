/* OOOOOOOOOOOOOO                                                */
/* 학번: 20101215                                                */
/* 이름: 정OO                                                    */
/* 과제: 4장 과제(2) Circular Double Linked List - HeadNode      */

#include <iostream>
#include <string>
#include "ddl.h"


using namespace std;

void Algorithm::Sort(DDList& List, int Type){

	Node* X_Node = List.GetHeadNode();
	Node* Y_Node = NULL, *MinNode = NULL, TmpNode;

	// 버블 정렬
	while (X_Node != NULL)
	{
		Y_Node = List.GetHeadNode();

		while (Y_Node != NULL)
		{
			switch (Type)
			{
				case ASC:
					if (X_Node->code < Y_Node->code){
						Swap(X_Node, Y_Node);
					}
					break;

				case DESC:
					if (X_Node->code > Y_Node->code){
						Swap(X_Node, Y_Node);
					}
					break;
			}

			if (Y_Node == List.GetTopNode())
				break;

			Y_Node = Y_Node->next;
		
		} // end of while

		if (X_Node == List.GetTopNode())
			break;

		X_Node = X_Node->next;
			
	}// end of while

}

void Algorithm::Swap(Node* X_Node, Node* Y_Node){
	int TmpNum;
	string TmpTxt;

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

		Y_DownNode = Y_DownNode->down;
		X_DownNode = X_DownNode->down;
	}
}