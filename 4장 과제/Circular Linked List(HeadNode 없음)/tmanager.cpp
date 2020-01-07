/* OOOOOOOOOOOOOO                                                */
/* 학번: 20101215                                                */
/* 이름: 정OO                                                    */
/* 과제: 4장 과제(2) Circular Double Linked List - HeadNode 제거 */

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
	cout << "학생의 이름과 학번이 저장된 파일을 입력하세요 : ";
}

void TManager::PrintMenu(){

	cout << "==========================================" << endl;
	cout << "(1) 새 학생 입력" << endl;
	cout << "(2) 학생 삭제" << endl;
	cout << "(3) 학번 순으로 전체 출력" << endl;
	cout << "(4) 학번 역순으로 전체 출력" << endl;
	cout << "(5) 특정 학번부터 전체 출력" << endl;
	cout << "(6) 특정 학번부터 첫학생까지 역순 출력" << endl;
	cout << "(7) 종료" << endl;
	cout << "==========================================" << endl;
	cout << "원하는 기능을 선택하세요 : ";
}

bool TManager::LoadFile(Node* pNode){

	bool Check = false;

	ifstream Read;
	IOHandler io;
	string UserTxt, FileName, Tmp, Memo;

	char* Buff = _getcwd(NULL, 0); // 현재경로 가져오기

	PrintTitle(); // 타이틀 출력 - friend 함수

	cin.sync();
	std::getline(cin, UserTxt);

	FileName.append(Buff); // Windows 기반 테스트
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
		Check = io.InputFile(Memo, *pNode);

	return Check;

}

void TManager::New(Node* pNode){
	
	DDList dList;
	Node* FirstNode = pNode;
	Node* CreateNode;
	string UserTxt;
	string chData, TmpData;
	bool Check = false;
	int i, Size, ColumnIDX;

	while (1)
	{
		cout << "학번과 이름을 입력하세요 : ";

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
					CreateNode = dList.Create(tCode, TmpData);
				else
					CreateNode = dList.Create(tData, TmpData);

				pNode = dList.Insert(CreateNode, pNode);
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
				if (ColumnIDX > MAXCOLUMNS)  // 최대 범위를 넘어갈 때
					break;

				if (ColumnIDX == MAXCOLUMNS) // 데이터가 일치할 때
				{
					CreateNode = dList.Create(tData, TmpData);
					pNode = dList.Insert(CreateNode, pNode);
					Check = true;
					break;
				}

				if (ColumnIDX < MAXCOLUMNS)  // 최소 범위를 넘어갈 때
					break;
			}

			i++;
		}

		// 조건이 맞을 때
		if (Check == true){
			//pNode = dList.Insert(FirstNode, pNode); // 삽입
			break;
		}
		else{
			TmpData.erase();         // 임시 공간 초기화
		}

		UserTxt.erase(); // 입력 데이터 초기화
	}

}

void TManager::Remove(Node* pNode){

	DDList dList;
	int Code;
	cout << "학번을 입력하세요 : ";
	cin >> Code;

	pNode = dList.Delete(Code, pNode);
}

void TManager::NormalAsc(Node pNode){
	Algorithm Algo;
	IOHandler io;

	Node* dNode = Algo.Sort(&pNode);
	io.PrintOut(*dNode, NORMAL, ASC);
}

void TManager::NormalDesc(Node pNode){
	Algorithm Algo;
	IOHandler io;

	Node* dNode = Algo.Sort(&pNode);
	io.PrintOut(*dNode, NORMAL, DESC);
}

void TManager::SpecificAsc(Node pNode){
	Algorithm Algo;
	IOHandler io;

	int Code;
	cout << "학번을 입력하세요 : ";
	cin >> Code;
	
	Node* dNode = Algo.Sort(&pNode);
	io.PrintOut(*dNode, SPECIFIC, NORMAL, Code);

}

void TManager::SpecificDesc(Node pNode){
	Algorithm Algo;
	IOHandler io;

	int Code;
	cout << "학번을 입력하세요 : ";
	cin >> Code;

	Node* dNode = Algo.Sort(&pNode);
	io.PrintOut(*dNode, SPECIFIC, REVERSE, Code);

}
