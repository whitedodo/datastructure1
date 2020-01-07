/////////////////////////////////////////////////////////////
////
////  금오공과대학교 경영학과 
////  학번: 20101215
////  이름: 정 원 영 ///////////////////////////////////////
////  파일명: Welcome.H 
////  설명: 문자열로 하는 타이틀 영역

#ifndef _WELCOME_H_
#define _WELCOME_H_

#include "structure.h"

// 인트로 - 타이틀
void Matrix::Intro(){

	cout << "곱할 배열이 mxn 와 nxp 크기일 때,";
	cout << " m과 n과 p의 값을 순서대로 입력하세요 : ";
}

// 추가 - 타이틀

void Matrix::InsertTitle(int _Type, int _Count){

	// 희소행렬 타이틀 불러오기
	switch (_Type)
	{

	case MatrixA:
		cout << "첫번째 배열의 ";
		break;

	case MatrixB:
		cout << "두번째 배열의 ";
		break;

	case MatrixC:
		break;

	}

	cout << _Count;
	cout << "개의 값을 입력하세요 : ";

}

#endif