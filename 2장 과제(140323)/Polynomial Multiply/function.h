/////////////////////////////////////////////////////////////
////
////  금오공과대학교 경영학과 
////  학번: 20101215
////  이름: 정 원 영 ////////////////////////////////////////
////  파일명: function.h
////  설명: 기능 영역

#ifndef _Function_H_
#define _Function_H_

#include "common.h"
#include "storage.h"

using namespace std;

class Multi{
	int FirstCnt;
	int SecondCnt;
	int ResultCnt;

	Data *FirstArr;
	Data *SecondArr;
	Data *ResultArr;

public:
	Multi();
	~Multi();
	void Input(int, int, int);
	void InsertData(int, int, int);
	void Calculate(int);
	void Insert_Result(int, int);
	void Swap(int, int);
	void PrintOut(int);
};

Multi::Multi(){
	FirstCnt = 0;
	SecondCnt = 0;
	ResultCnt = 0;

	FirstArr = new Data[MAX];
	SecondArr = new Data[MAX];
	ResultArr = new Data[MAX];
}

Multi::~Multi(){
	delete[] FirstArr;
	delete[] SecondArr;
	delete[] ResultArr;
}

void Multi::Input(int _CoNum, int _ExpNum, int _Type)
{
	InsertData(_CoNum, _ExpNum, _Type); // 실제 데이터 입력
}

void Multi::InsertData(int _CoNum, int _ExpNum, int _Type){
	
	if (_Type == FIRST)
	{
		FirstArr[FirstCnt].CoEff = _CoNum;
		FirstArr[FirstCnt].Exp = _ExpNum;
		FirstCnt++;
	}
	else if (_Type == SECOND)
	{
		SecondArr[SecondCnt].CoEff = _CoNum;
		SecondArr[SecondCnt].Exp = _ExpNum;
		SecondCnt++;
	}

}

void Multi::Calculate(int _Type)
{

	int TargetofCoNum = 0;
	int TargetofExpNum = 0;
	int MultiofCoNum = 0;
	int SumofExpNum = 0;

	for (int i = 0; i < FirstCnt; i++)
	{
		TargetofCoNum = FirstArr[i].CoEff;
		TargetofExpNum = FirstArr[i].Exp;
		
		for (int j = 0; j < SecondCnt; j++)
		{
			MultiofCoNum = TargetofCoNum * SecondArr[j].CoEff;
			SumofExpNum = TargetofExpNum + SecondArr[j].Exp;

			Insert_Result(MultiofCoNum, SumofExpNum);

		}
	}
	
}

void Multi::Insert_Result(int _CoNum, int _ExpNum)
{
	int SearchIDX;
	int SumOfCoEff = 0;

	// 초기 값 여부 판별
	if (ResultCnt == FALSE)
	{
		ResultArr[ResultCnt].CoEff = _CoNum;
		ResultArr[ResultCnt].Exp = _ExpNum;
		ResultCnt++;
	}else
	{
		SearchIDX = 0;
		
		while (SearchIDX < ResultCnt)
		{
			SumOfCoEff = TRUE;

			// 기존 계수와 신규 계수가 같을 때
			if (ResultArr[SearchIDX].Exp == _ExpNum)
			{
				SumOfCoEff = ResultArr[SearchIDX].CoEff + _CoNum;

				// 계수의 합이 0 일 때, 검색 좌표가 결과 대상 공간하고 같을 때
				if (SumOfCoEff == 0 && SearchIDX + 1 == ResultCnt)
				{
					ResultArr[SearchIDX].CoEff = NULL;
					ResultArr[SearchIDX].Exp = NULL;
					ResultCnt--;
				}
				// 계수의 합이 0 일때, 검색 좌표가 결과 대상 안에 포함될 때
				else if (SumOfCoEff == 0 && SearchIDX + 1 < ResultCnt)\
					Swap(SearchIDX, SearchIDX + 1);	// Swap 법칙

				// 계수의 합이 0이 아닐 때
				else if (SumOfCoEff != 0)
					ResultArr[SearchIDX].CoEff = ResultArr[SearchIDX].CoEff + _CoNum;

				break;
			}
			SearchIDX++;
		}

		// 신규 계수 여부 판별
		if (SearchIDX == ResultCnt && SumOfCoEff == TRUE)
		{
			ResultArr[ResultCnt].CoEff = _CoNum;
			ResultArr[ResultCnt].Exp = _ExpNum;

			ResultCnt++;
		}

	}
}

void Multi::Swap(int X, int Y)
{
	Data *Temp;
	Temp = &*(ResultArr + X);
	ResultArr[X] = ResultArr[Y];
	ResultArr[Y] = ResultArr[X];
}

void Multi::PrintOut(int _Type)
{
	if (FirstCnt != FALSE || SecondCnt != FALSE)
	{
		cout << "두 다항식의 곱은: ";
		for (int i = 0; i < ResultCnt; i++)
		{
			if (ResultArr[i].CoEff == 1)
				cout << "x";
			else if (ResultArr[i].CoEff == -1)
				cout << "-x";
			else
				cout << ResultArr[i].CoEff << "x";

			if (ResultArr[i].Exp != 1)
				cout << "^" << ResultArr[i].Exp;

			if ((i + 1) != ResultCnt)
				cout << "+";
		}
	}
	
}

#endif