/* OOOOOOOOOOOOOO                                                */
/* �й�: 20101215                                                */
/* �̸�: ��OO                                                    */
/* ����: 4�� ����(2) Circular Double Linked List - HeadNode ���� */

#ifndef _DDL_H_
#define _DDL_H_

#include <iostream>
#include <string>

// ���
const int REVERSE = -1;
const int NONE = 0;
// ���� ���
const int ASC = 1;
const int DESC = 2;
// ��ȸ Ÿ��
const int NORMAL = 3;       // ���� ��ȸ
const int SPECIFIC = 4;     // Ư�� �й� ��ȸ
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
	Default(Ư�� ���� ���� ��� ����)
	����: (DDList* List,
	      int Type = NORMAL, , 
		  int SortType = ASC, DESC
		  int Type = SPECIFIC
		  int SortType = NONE, NORMAL, REVERSE, 
		  int Code = �ڵ�(�й�) �Է�
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