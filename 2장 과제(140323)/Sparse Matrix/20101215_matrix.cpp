/////////////////////////////////////////////////////////////
////
////  금오공과대학교 경영학과 
////  학번: 20101215
////  이름: 정 원 영 ////////////////////////////////////////
////  파일명: Matrix.CPP
////  설명: Gom do ri - Sparse Matrix ......................

#include <iostream>
#include "structure.h"
#include "welcome.h"
#include "insert.h"
#include "printout.h"

using namespace std;

void main()
{
	int m, n, p;
	int Status = FALSE;
	Matrix *MatrixApp = NULL;

	MatrixApp->Intro();
	cin >> m >> n >> p;
	
	// Matrix 기초 생성
	if (m != 0 || n != 0 || p != 0){
		MatrixApp = new Matrix(m, n, p);
		Status = INSERT;
	}
	else
		Status = FALSE;


	// 신규 값 받기
	Status = MatrixApp->Insert(Status);
	
	// 진행 처리
	Status = MatrixApp->Calculate(Status);

	// 결과 처리
	MatrixApp->PrintOut(Status);

}