/* OOOOOOOOOOOOOO                                                */
/* 학번: 20101215                                                */
/* 이름: 정OO                                                    */
/* 과제: 4장 과제(2) Circular Double Linked List - HeadNode      */

#include <iostream>
#include <direct.h>
#include "ddl.h"

using namespace std;


IOHandler::IOHandler(){

}

IOHandler::~IOHandler(){

}

bool IOHandler::InputFile(string Data, DDList& List){

	bool Check = true;
	int ColumnIDX = 1;
	int i = 0;
	int MaxSize = Data.size();
	string chData, TmpData;

	DDList dList;
	Node* CreateNode;

	while (i < MaxSize)
	{
		chData = Data.substr(i, 1);

		if (chData == " ") // 다음 컬럼 넘기기
		{
			if (ColumnIDX == 1) // Column은 고유 코드 입력(숫자형)
			{
				CreateNode = dList.Create(tCode, TmpData);
			}
			else
			{
				CreateNode = dList.Create(tData, TmpData);
			}

			List.Insert(CreateNode);
			TmpData.erase(); // 임시 공간 초기화

			ColumnIDX++;
		}

		if (ColumnIDX == 1) // 첫 코드에 대한 데이터 임시 Append(추가)
		{
			if (isdigit(chData.at(0)))
				TmpData.append(chData.c_str());

			else{ Check = false; break; }
		}
		else
		{
			if (chData != " " && chData != "\n") // 공백이 아닐 때
				TmpData.append(chData.c_str());
		}

		// 단 넘어갈 때 처리
		if (chData.at(0) == '\n')
		{
			if (ColumnIDX > MAXCOLUMNS)  // 최대 범위를 넘어갈 때
			{
				Check = false;
				break;
			}

			if (ColumnIDX == MAXCOLUMNS) // 데이터가 일치할 때
			{
				CreateNode = dList.Create(tData, TmpData);
				List.Insert(CreateNode);

				TmpData.erase();         // 임시 공간 초기화
			}

			if (ColumnIDX < MAXCOLUMNS)  // 최소 범위를 넘어갈 때
			{
				Check = false;
				break;
			}

			ColumnIDX = 1;   // 컬럼 초기화
		}

		i++;
	}

	return Check;

}

void IOHandler::PrintOut(DDList* List, int PrintType,  int SortType, int Code){

	switch (PrintType)
	{
		case NORMAL:
			Print_Normal(List);
			break;

		case SPECIFIC:
			Print_Specific(List, SortType, Code);
			break;
	}
}


void IOHandler::Print_Normal(DDList* List){

	Node* NextNode = List->GetHeadNode();
	bool Escape = false;

	while (NextNode != NULL)
	{
		UserView(NextNode); // 출력

		if (NextNode == List->GetTopNode())
			Escape = true;

		if (Escape == true) // 탈출
			break;

		NextNode = NextNode->next;
	}
}

void IOHandler::Print_Specific(DDList* List, int Sort, int Code){
	
	Node* NextNode = List->GetHeadNode();
	
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

				// 데이터 출력
				if (Circular == true)
					UserView(NextNode);

				NextNode = NextNode->next;

				break;

			case REVERSE:

				if (NextNode->code == Code)
				{
					if (Circular == false)
						Circular = true;
				}

				// HeadNode(First)에 도달했을 때, Circular가 Prev로 전환된 상태
				if (NextNode == List->GetHeadNode() && Circular == true)
					Escape = true;

				if (Circular == false)
					NextNode = NextNode->next;
				else{
					UserView(NextNode);         // 출력
					NextNode = NextNode->prev;
				}

				break;
		}

		if (Escape == true) // 탈출
			break;
	}
}

void IOHandler::UserView(Node* pNode){
	
	Node* DownNode;

	cout << pNode->code << " ";
	DownNode = pNode->down;

	while (DownNode != NULL)
	{
		cout << DownNode->Data << endl;
		DownNode = DownNode->down;
	}

}
