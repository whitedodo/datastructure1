/* OOOOOOOOOOOOOO                                                */
/* 학번: 20101215                                                */
/* 이름: 정OO                                                    */
/* 과제: 4장 과제(2) Circular Double Linked List - HeadNode 제거 */

#ifndef _DDL_H_
#define _DDL_H_

#include <iostream>
#include <string>

// 출력
const int REVERSE = -1;
const int NONE = 0;
// 정렬 방법
const int ASC = 1;
const int DESC = 2;
// 조회 타입
const int NORMAL = 3;       // 보통 조회
const int SPECIFIC = 4;     // 특정 학번 조회
// Column MAX
const int MAXCOLUMNS = 2;   // COLUMNS MAX

enum { tCode, tData };      // Field

class Node{
public:
	int type;
	int code;
	std::string Data;
	Node* prev;
	Node* next;
	Node* up;
	Node* down;
};

class DDList{
public:
	DDList();
	~DDList();
	Node* Create(int _Type, std::string Data);
	Node* Insert(Node* createNode, Node* pNode);
	Node* Delete(int _Code, Node* pNode);
};

class TManager{
	friend void PrintTitle();
public:
	TManager();
	~TManager();

	void PrintMenu();
	bool LoadFile(Node* pNode);

	void New(Node* pNode);
	void Remove(Node* pNode);
	void NormalAsc(Node pNode);
	void NormalDesc(Node pNode);
	void SpecificAsc(Node pNode);
	void SpecificDesc(Node pNode);
};

class IOHandler{
public:
	IOHandler();
	~IOHandler();

	bool InputFile(std::string Data, Node& pNode);
	/* 
	Default(특정 지정 없이 출력 가능)
	설명: (DDList* List,
	      int Type = NORMAL, , 
		  int SortType = ASC, DESC
		  int Type = SPECIFIC
		  int SortType = NONE, NORMAL, REVERSE, 
		  int Code = 코드(학번) 입력
	*/
	void PrintOut(Node pNode, int PrintType = NORMAL, int SortType = ASC, int Code = NONE);

private:
	void UserView(Node* pNode);
	void Print_Normal(Node* pNode, int SortType);
	void Print_Specific(Node* pNode, int Sort, int Code);
};

class Algorithm{
public:
	Node* Sort(Node* pNode);

private:
	void Swap(Node* X_Node, Node* Y_Node);
};

#endif