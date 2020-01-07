/* OOOOOOOOOOOOOO                                                */
/* 학번: 20101215                                                */
/* 이름: 정OO                                                    */
/* 과제: 4장 과제(2) Circular Double Linked List - HeadNode      */

#include <iostream>
#include "ddl.h"

const int NEW = 1;
const int REMOVE = 2;
const int NORMAL_ASC = 3;
const int NORMAL_DESC = 4;
const int SPECIFIC_ASC = 5;
const int SPECIFIC_DESC = 6;
const int EXIT = 7;

using namespace std;

int main()
{
	TManager tm;
	DDList dList;

	bool inFile = tm.LoadFile(&dList); // 파일 입력 받기

	while (inFile)
	{
		int menu;

		tm.PrintMenu(); // 타이틀 출력

		cin >> menu;    // 기능 입력 받기
		
		if (menu == EXIT)
			break;

		switch (menu)
		{
			case NEW:
				tm.New(&dList);
				break;

			case REMOVE:
				tm.Remove(&dList);
				break;

			case NORMAL_ASC:
				tm.NormalAsc(&dList);
				break;

			case NORMAL_DESC:
				tm.NormalDesc(&dList);
				break;

			case SPECIFIC_ASC:
				tm.SpecificAsc(&dList);
				break;

			case SPECIFIC_DESC:
				tm.SpecificDesc(&dList);
				break;
				
			default:
				cout << "기능을 올바르게 입력하세요.";
				break;
		}
	}

	return 0;
}