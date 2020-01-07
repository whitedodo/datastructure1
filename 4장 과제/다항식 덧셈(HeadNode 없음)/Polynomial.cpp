/*    OOOOOOOOOOO 경영학과
      학번: 20101215
      이름: 정 O O
      과제: 4장 (3번) - 다항식 곱셈 (HeadNode 제거)
*/

#include <iostream>
#include "polynomial.h"

using namespace std;

PolyNode::PolyNode(){
	Type = -1; 
}

PolyNode::~PolyNode(){

}

List::List(){
}

List::~List(){
}

void List::Write(PolyNode& List){
	
	cout << " 다항식을 계수-지수 쌍으로 입력하세요.(계수나 지수가 0으로 입력되면 종료)" << endl;

	PolyNode* NewList = new PolyNode();

	while (1)
	{
		int coefNum;
		int expNum;
	
		cin >> coefNum;
		cin >> expNum;

		if (coefNum != 0)
		{
			PolyNode* CoefNode = Create(COEF, coefNum); // 계수 생성
			PolyNode* ExpNode = Create(EXP, expNum);    // 지수 생성
			
			NewList = Insert(CoefNode, NewList); // 계수 삽입
			NewList = Insert(ExpNode, NewList);  // 지수 삽입
		}

		if (coefNum == 0 || expNum == 0)
			break;

		cin.clear();
	}

	List = *NewList;

}

PolyNode* List::Create(int _Type, int _Data){

	PolyNode* NewList = new PolyNode();
	
	NewList->Type = _Type;

	switch (_Type)
	{
		case COEF:
			NewList->Coef = _Data;
			NewList->Down = NULL;
			break;

		case EXP:
			NewList->Up = NULL;
			NewList->Exp = _Data;
			break;
	}

	NewList->Prev = NULL;
	NewList->Next = NULL;

	return NewList;
}

PolyNode* List::Insert(PolyNode* dSource, PolyNode* dNode)
{
	PolyNode* TmpNode = dNode;
	PolyNode* PrevNode = TmpNode;
	PolyNode* FirstNode;

	if (TmpNode->Type == EMPTY)
	{
		TmpNode = dSource;
		TmpNode->Prev = TmpNode;
		TmpNode->Next = TmpNode;
	}
	else
	{
		FirstNode = dNode->Next; // FirstNode 가리키기.(환형 리스트)

		if (TmpNode->Up != NULL)
			TmpNode = TmpNode->Up;

		while (TmpNode != NULL)
		{
			PrevNode = TmpNode;
			if (TmpNode->Next == FirstNode) // FirstNode에 도달했을 때 탈출.
				break;

			TmpNode = TmpNode->Next;
		}

		switch (dSource->Type)
		{
			case COEF:
				dSource->Prev = PrevNode;
				dSource->Next = FirstNode;

				PrevNode->Next = dSource;
				FirstNode->Prev = PrevNode->Next; // 첫위치 변경
				TmpNode = dSource;
				break;

			case EXP:
				dSource->Up = PrevNode;
				PrevNode->Down = dSource;
				TmpNode = PrevNode;
				break;
		}
	}

	return TmpNode;
}

PolyNomial::PolyNomial(){

}

PolyNomial::~PolyNomial(){

}

PolyNode* PolyNomial::Multiply(PolyNode* A_List, PolyNode* B_List){

	int CoefNum, ExpNum;

	PolyNode* X_List,* Y_List;
	
	PolyNode* X_NextNode, *Y_NextNode;
	
	PolyNode* TmpNode, *FirstNode;
	PolyNode* NewNode = new PolyNode();

	List PolyList;

	X_List = A_List->Next; // A-List의 FirstNode 가리킴
	Y_List = B_List->Next; // B-List의 FirstNode 가리킴

	X_NextNode = X_List;
	
	do
	{
		Y_NextNode = Y_List;

		while (Y_NextNode != NULL)
		{
			PolyNode* NewCreate = new PolyNode();

			// X - 계산
			CoefNum = X_NextNode->Coef;
			TmpNode = X_NextNode->Down;
			ExpNum = TmpNode->Exp;

			// Y - 계산
			CoefNum *= Y_NextNode->Coef;
			TmpNode = Y_NextNode->Down;
			ExpNum += TmpNode->Exp;

			// X*Y - COEF
			TmpNode = PolyList.Create(COEF, CoefNum);
			NewCreate = PolyList.Insert(TmpNode, NewCreate);
			
			// X+Y - EXP
			TmpNode = PolyList.Create(EXP, ExpNum);
			NewCreate = PolyList.Insert(TmpNode, NewCreate);

			NewNode = pAdd(NewCreate, NewNode);

			// 다음 노드로 이동
			Y_NextNode = Y_NextNode->Next;

			if (Y_NextNode == Y_List) // Y_list 첫 위치에 도달시 탈출
				break;

		}

		X_NextNode = X_NextNode->Next;

		// 다음 노드로 이동
		if (X_NextNode == X_List) // X_list 첫 위치에 도달시 탈출
			break;
	
	} while (X_NextNode != NULL); 

	return NewNode;
}


PolyNode* PolyNomial::pAdd(PolyNode *A_List, PolyNode *B_List){

	PolyNode *PrevNode, *NextNode = B_List;
	PolyNode *FirstNode, *LeafNode;
	int User_Coef, User_Exp;
	List PolyList;
	
	if (NextNode->Type == EMPTY)
	{
		NextNode = A_List;
	}
	else
	{
		FirstNode = B_List->Next;
		NextNode = FirstNode;
		PrevNode = NextNode;

		User_Coef = A_List->Coef;
		LeafNode = A_List->Down;
		User_Exp = LeafNode->Exp;

		while (NextNode != NULL)
		{
			LeafNode = NextNode->Down;

			if (User_Exp == LeafNode->Exp)
			{
				int Sum = NextNode->Coef + User_Coef;
				NextNode->Coef = Sum;

				FirstNode = FirstNode->Prev;
				NextNode = FirstNode->Prev;
				break;
			}

			PrevNode = NextNode;
			NextNode = NextNode->Next;
			
			// NextNode가 FirstNode에 일치할 때
			if (NextNode == FirstNode)
			{
				NextNode = PrevNode;

				A_List->Prev = NextNode;
				A_List->Next = FirstNode;
				NextNode->Next = A_List;
				FirstNode->Prev = NextNode->Next;

				break;
			}
				
		}
	}

	return NextNode->Next;

}

void PolyNomial::PrintOut(PolyNode List){

	PolyNode* FirstNode = List.Next;
	PolyNode* NextNode = List.Next;
	PolyNode* TmpNode;
	int CoefNum, ExpNum;

	while (NextNode != NULL)
	{
		if (NextNode->Coef != 0)
		{
			TmpNode = NextNode->Down;
			CoefNum = NextNode->Coef;
			ExpNum = TmpNode->Exp;

			switch (CoefNum)
			{
				case -1:
					cout << "-x";
					break;
				
				case 1:
					cout << "x";
					break;

				default:
					cout << CoefNum << "x";
					break;
			}	

			if (ExpNum != 1)  // 지수가 1이 아닐 때
				cout << "^" << ExpNum;
			
		}
		else{
			NextNode = NextNode->Next;
			continue;
		}

		if (NextNode->Next == FirstNode) // 목표지점 도달시 탈출
			break;
		else
			cout << " + ";

		NextNode = NextNode->Next;
	}
	
	cout << endl;

}
