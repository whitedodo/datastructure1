/////////////////////////////////////////////////////////////
////
////  금오공과대학교 경영학과 
////  학번: 20101215
////  이름: 정 원 영 ////////////////////////////////////////
////  파일명: 20101215_main.cpp
////  설명: 메인 영역

#include <iostream>
#include "function.h"

using namespace std;

int main()
{
	Multi *MultiApp = new Multi();
	int coNum;
	int expNum;
	int Status;

	Status = FIRST;

	while (1)
	{
		// 사용자 입력
		if (Status != RESULT)
			cin >> coNum >> expNum;

		if (coNum != 0)
			MultiApp->Input(coNum, expNum, Status);		// 컴퓨터에 입력

		// 상태 파악
		if ((expNum == 0) && Status == FIRST)
		{
			Status = SECOND;
		}
		else if ((expNum == 0) && Status == SECOND)
		{
			Status = RESULT;
		}

		// 입력이 다 되었을 때 - 컴퓨터가 처리하는 절차 수행
		if (Status == RESULT)
		{
			// 연산 처리
			MultiApp->Calculate(Status);

			// 출력
			MultiApp->PrintOut(Status);

			// 소멸
			MultiApp->~Multi();

			break;
		}

	}


}