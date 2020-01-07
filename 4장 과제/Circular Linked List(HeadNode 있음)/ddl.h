/* OOOOOOOOOOOOOO                                                */
/* 학번: 20101215                                                */
/* 이름: 정OO                                                    */
/* 과제: 4장 과제(2) Circular Double Linked List - HeadNode      */

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
	void Insert(Node* createNode);
	void Delete(int _Code);
	Node* GetTopNode(){ return TopNode; };
	Node* GetHeadNode(){ return HeadNode; };

private:
	Node* HeadNode;
	Node* TopNode;
};

class TManager{
	friend void PrintTitle();
public:
	TManager();
	~TManager();

	void PrintMenu();
	bool LoadFile(DDList* List);

	void New(DDList* List);
	void Remove(DDList* List);
	void NormalAsc(DDList* List);
	void NormalDesc(DDList* List);
	void SpecificAsc(DDList* List);
	void SpecificDesc(DDList* List);
};

class IOHandler{
public:
	IOHandler();
	~IOHandler();

	bool InputFile(std::string Data, DDList& List);
	/* 
	Default(특정 지정 없이 출력 가능)
	설명: (DDList* List,
	      int Type = NORMAL, SPECIFIC, 
		  int SortType = NONE, NORMAL, REVERSE, 
		  int Code = 코드(학번) 입력
	*/
	void PrintOut(DDList* List, int PrintType = NORMAL, int SortType = NONE, int Code = NONE);

private:
	void UserView(Node* pNode);
	void Print_Normal(DDList* List);
	void Print_Specific(DDList* List, int Sort, int Code);
};

class Algorithm{
public:
	void Sort(DDList& List, int Type);

private:
	void Swap(Node* X_Node, Node* Y_Node);
};

#endif