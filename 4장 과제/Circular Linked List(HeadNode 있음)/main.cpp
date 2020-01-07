/* OOOOOOOOOOOOOO                                                */
/* �й�: 20101215                                                */
/* �̸�: ��OO                                                    */
/* ����: 4�� ����(2) Circular Double Linked List - HeadNode      */

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

	bool inFile = tm.LoadFile(&dList); // ���� �Է� �ޱ�

	while (inFile)
	{
		int menu;

		tm.PrintMenu(); // Ÿ��Ʋ ���

		cin >> menu;    // ��� �Է� �ޱ�
		
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
				cout << "����� �ùٸ��� �Է��ϼ���.";
				break;
		}
	}

	return 0;
}