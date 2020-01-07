/*
	금오공과대학교
	과제: 방학(Binary Tree) 과제5 - 2번(계산식)
	학과: Business & CSE
	학번: 20101215
	이름: 정원영
*/

#ifndef _TREE_DETAIL_H_
#define _TREE_DETAIL_H_

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include "tree.h"

using namespace std;

std::string IntToString(int number);
std::string CharToString(char op);
const char stringToChar(std::string D, int i);

Tree::Tree(){
	newStack = new pStack();
}

Tree::~Tree(){
	DestoryTree(newStack->pop());
}


void Tree::DestoryTree(TreeNode* pNode){

	if (pNode != NULL)
	{
		DestoryTree(pNode->LeftNode);
		DestoryTree(pNode->RightNode);
		DestoryNode(pNode);
	}

}

void Tree::DestoryNode(TreeNode* pNode){
	delete pNode;
}

TreeNode* Tree::GetTree(){
	return newStack->GetTop();
}

void Tree::SetLine(bool check){
	printLine = check;
}

bool Tree::GetLine(){
	return printLine;
}

void Tree::PrintOut(TreeNode* pNode){
	PrintStack* newData = new PrintStack();
	PostOrder(pNode, 0, newData);
	cout << endl;
}


void Tree::SetData(int Type, std::string Data){

	switch (Type)
	{
		case ROOT:
			RootData = Data;
			break;

		case NODE:
			TreeData.append(Data);
			break;
	}

}

void Tree::PostOrder(TreeNode* pTreeNode, int level, PrintStack* pStackNode){

	string Data;

	// TreeNode가 아닐 때
	if (pTreeNode != NULL)
	{
		// 라인 바꾸기
		if (GetLine() == true)
		{
			string pData;
			int i = 0;

			int iStartNum = level;
			int iEndNum = pStackNode->GetCount();

			if (GetLine() == true){

				while (iStartNum < iEndNum)
				{
					pStackNode->pop();
					iStartNum++;
				}
			}

			while (i < pStackNode->GetCount())
			{
				string pTmpData = pStackNode->at(i);
				pData.append(pTmpData);
				i++;
			}


			cout << endl;

			i = 0;
			while (i <= pData.length())
			{
				cout << " ";
				i++;
			}

			SetLine(false);
		}

		if (level == 0)
			cout << pTreeNode->Data;
		else
			cout << " --- " << pTreeNode->Data;

		// Node
		if (pTreeNode->LeftNode == NULL && pTreeNode->LeftNode == NULL)
		{
			SetLine(true);
		}
		else
		{

			// 루트 위치 설정
			if (level == 0)
			{
				Data.append(pTreeNode->Data);
				SetData(ROOT, pTreeNode->Data);
			}

			// 노드 위치 설정
			if (level != 0)
			{
				if (pTreeNode->Data != "~")
				{
					Data.append(" --- ");
					Data.append(pTreeNode->Data);
				}
			}

			// cout << Data; - Stack 내용

			if (Data != ""){
				pStackNode->push(Data, level);
			}
		}

		PostOrder(pTreeNode->LeftNode, level + 1, pStackNode);
		PostOrder(pTreeNode->RightNode, level + 1, pStackNode);
	}

}

std::string Tree::GetResult(int number, char op){

	std::string pData;

	if (op == '~'){
		pData.push_back(op);
	}
	else{
		pData.push_back(op);
		pData.push_back(' ');
		pData.push_back('(');
		pData.append(IntToString(number));
		pData.push_back(')');
	}

	return pData;
}


/*
void Tree::Make(int left, int right, int result, char op){
cout << "left:" << left << "/right:" << right << "/result:" << result << "/op:" << op << endl;
}

*/

void Tree::Make(int left, int right, int result, char op){

	TreeNode* resultNode, *leftNode, *rightNode;
	bool Check = false;

	// 스택이 비어있을 때
	if (newStack->IsEmpty())
	{
		if (op == '~')
		{
			leftNode = new TreeNode();
			resultNode = new TreeNode();
			
			leftNode->Data = IntToString(left);
			leftNode->LeftNode = NULL;
			leftNode->RightNode = NULL;

			resultNode->Data = GetResult(result, op);
			resultNode->LeftNode = leftNode;
			resultNode->RightNode = NULL;
		}
		else{
			
			leftNode = new TreeNode();
			rightNode = new TreeNode();
			resultNode = new TreeNode();

			leftNode->LeftNode = NULL;
			leftNode->Data = IntToString(left);
			leftNode->RightNode = NULL;

			rightNode->LeftNode = NULL;
			rightNode->Data = IntToString(right);
			rightNode->RightNode = NULL;

			resultNode->LeftNode = leftNode;
			resultNode->Data = GetResult(result, op);
			resultNode->RightNode = rightNode;
		}

		newStack->push(resultNode);

	}
	else
	{

		if (newStack->GetCount() > 1){

			TreeNode* pNode = newStack->GetTop();
			TreeNode* pLeftNode, *pRightNode;

			// '^'일 때
			if (op == '^'){

				leftNode = new TreeNode();
				rightNode = new TreeNode();
				resultNode = new TreeNode();

				leftNode->LeftNode = NULL;
				leftNode->Data = IntToString(left);
				leftNode->RightNode = NULL;

				rightNode->LeftNode = NULL;
				rightNode->Data = IntToString(right);
				rightNode->RightNode = NULL;

				resultNode->LeftNode = leftNode;
				resultNode->Data = GetResult(result, op);
				resultNode->RightNode = rightNode;

				newStack->push(resultNode);

				Check = true;
				// Push 구현

			} // End of if

			// 1-1. '~'일 때
			if (op == '~')
			{
				leftNode = new TreeNode();
				resultNode = new TreeNode();

				leftNode->Data = IntToString(left);
				leftNode->LeftNode = NULL;
				leftNode->RightNode = NULL;

				resultNode->Data = GetResult(result, op);
				resultNode->LeftNode = leftNode;
				resultNode->RightNode = NULL;

				newStack->push(resultNode);

				Check = true;
				// Push 구현

			} // End of if

			// 1-2. '~'일 때
			if (pNode->Data == "~"){

				leftNode = new TreeNode();
				rightNode = new TreeNode();
				resultNode = new TreeNode();

				leftNode = newStack->pop();

				rightNode->LeftNode = NULL;
				rightNode->Data = IntToString(right);
				rightNode->RightNode = NULL;

				resultNode->LeftNode = leftNode;
				resultNode->Data = GetResult(result, op);
				resultNode->RightNode = rightNode;

				newStack->push(resultNode);

				Check = true;
				// Push 구현

			} // End of if

			// LeftNode - RightNode
			if (Check == false){

				int LeftNumber;
				int RightNumber;

				leftNode = newStack->pop();
				rightNode = newStack->pop();

				LeftNumber = resultToInt(rightNode->Data);
				RightNumber = resultToInt(leftNode->Data);

				if (LeftNumber == left && RightNumber == right)
				{
					resultNode = new TreeNode();
					resultNode->Data = GetResult(result, op);
					resultNode->LeftNode = rightNode;
					resultNode->RightNode = leftNode;

					newStack->push(resultNode);
				}
				else
				{
					newStack->push(rightNode);
					newStack->push(leftNode);

					leftNode = new TreeNode();
					rightNode = new TreeNode();
					resultNode = new TreeNode();

					leftNode->LeftNode = NULL;
					leftNode->Data = IntToString(left);
					leftNode->RightNode = NULL;

					rightNode->LeftNode = NULL;
					rightNode->Data = IntToString(right);
					rightNode->RightNode = NULL;

					resultNode->LeftNode = leftNode;
					resultNode->Data = GetResult(result, op);
					resultNode->RightNode = rightNode;

					newStack->push(resultNode);

				} // End of if

			} // End of if

		}
		else
		{
			// 1-1. '~'일 때
			if (op == '~')
			{
				leftNode = new TreeNode();
				resultNode = new TreeNode();

				leftNode->Data = IntToString(left);
				leftNode->LeftNode = NULL;
				leftNode->RightNode = NULL;

				resultNode->Data = GetResult(result, op);
				resultNode->LeftNode = leftNode;
				resultNode->RightNode = NULL;

				newStack->push(resultNode);

				Check = true;
				// Push 구현

			} // End of if
			else
			{
				leftNode = new TreeNode();
				rightNode = new TreeNode();
				resultNode = new TreeNode();

				leftNode->LeftNode = NULL;
				leftNode->Data = IntToString(left);
				leftNode->RightNode = NULL;

				rightNode->LeftNode = NULL;
				rightNode->Data = IntToString(right);
				rightNode->RightNode = NULL;

				resultNode->LeftNode = leftNode;
				resultNode->Data = GetResult(result, op);
				resultNode->RightNode = rightNode;

				newStack->push(resultNode);
			}
		
		}

	} // End of if
}

int Tree::resultToInt(std::string D){

	int i = 0, j = 0;
	int length = D.length();
	int result = 0;

	char ch;
	bool Check = false;
	bool Negative = false;

	while (i < length)
	{
		ch = stringToChar(D, i);

		// ) 일 때 종료처리
		if (Check == true && ch != ')')
		{
			if (ch == '-')
			{
				Negative = true;
			}
			else
			{
				// 숫자 범위 파악
				if (ch >= '0' && ch <= '9')
				{
					result = (result * 10) + ch - '0';
				} // End of if

			} // End of if

		} // End of if

		if (ch == '('){
			Check = true;
		} // End of if

		// Negative 수 처리
		if (ch == ')'){
			Check = false;

			// 음수로 변환(Result)
			if (Negative == true)
			{
				result = result * (-1);
			} // End of if

		} // End of if

		i++;
	} // End of while

	return result;

}

std::string IntToString(int number)
{
	ostringstream convStream;
	convStream << number;
	return convStream.str();
}

std::string CharToString(char op){
	string D;
	D.push_back(op);
	return D;
}

const char stringToChar(std::string D, int i){
	string T_Data = D.substr(i, 1);
	return T_Data.at(0);
}

pStack::pStack(){

	Count = 0;
	Top = new pNode();
	Top->Data = NULL;
	Top->prev = NULL;
	Top->next = NULL;

}

pStack::~pStack(){

	pNode* curNode;

	while (Top != NULL)
	{
		curNode = Top;
		Top = Top->prev;
		delete curNode;
	} // End of while

}
void pStack::push(TreeNode* _pNode){

	pNode* newNode = new pNode();
	newNode->Data = _pNode;
	newNode->prev = NULL;
	newNode->next = NULL;

	// 신규 추가
	if (Top->Data != NULL)
	{
		newNode->prev = Top;
		Top->next = newNode;
		Top = Top->next;
	}
	else
	{
		Top = newNode;
	} // End of if

	Count++;

}

TreeNode* pStack::pop(){

	TreeNode* pTreeNode;
	pNode* pNode;

	// 데이터가 없을 때
	if (Top->Data == NULL)
		return 0;

	if (Top->prev != NULL)
	{
		pTreeNode = Top->Data;
		pNode = Top;
		Top = Top->prev;
		delete pNode;
	}
	else
	{
		pTreeNode = Top->Data;
		Top->Data = NULL;
		Top->next = NULL;
	} // End of if

	Count--;

	return pTreeNode;
}

TreeNode* pStack::GetTop(){
	return Top->Data;
}

int pStack::IsEmpty(){

	if (Top->Data != NULL)
		return 0;
	else
		return 1;
}

int pStack::GetCount(){
	return Count;
}

PrintStack::PrintStack(){
	Top = new PrintNode();
	Top->Data = "NULL";
	Top->prev = NULL;
	Top->next = NULL;
}

PrintStack::~PrintStack(){

	PrintNode* curNode;

	while (Top != NULL)
	{
		curNode = Top;
		Top = Top->prev;
		delete curNode;
	} // End of while
}

void PrintStack::push(std::string _Data, int _Height){
	PrintNode* newNode = new PrintNode();
	newNode->Data = _Data;
	newNode->Height = _Height;
	newNode->prev = NULL;
	newNode->next = NULL;

	// 신규 추가
	if (Top->Data != "NULL")
	{
		newNode->prev = Top;
		Top->next = newNode;
		Top = Top->next;
	}
	else
	{
		Top->Data = _Data;
		Top->Height = _Height;
	} // End of if

	Count++;
}

std::string PrintStack::pop(){
	std::string pData;
	PrintNode* pNode;

	// 데이터가 없을 때
	if (Top->Data == "NULL")
		return 0;

	if (Top->prev != NULL)
	{
		pData = Top->Data;
		pNode = Top;
		Top = Top->prev;
		delete pNode;
	}
	else
	{
		pData = Top->Data;
		Top->Data = "NULL";
		Top->next = NULL;
	} // End of if

	Count--;

	return pData;
}

int PrintStack::GetCount(){
	return Count;
}

std::string PrintStack::at(int height){
	
	std::string pData = "NULL";

	PrintNode* pNode = Top;
	while (1)
	{
		// 루프 탈출
		if (pNode == NULL)
			break;

		if (pNode->Height == height){
			pData = pNode->Data;
			break;
		}

		pNode = pNode->prev;
	}

	return pData;
}

#endif
