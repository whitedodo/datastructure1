/*
	금오공과대학교
	과제: 방학(Binary Tree) 과제5 - 2번(계산식)
	학과: Business & CSE
	학번: 20101215
	이름: 정원영
*/

#ifndef _TREE_H_
#define _TREE_H_

#include <iostream>
#include <string>

using namespace std;

const int ROOT = 1;
const int NODE = 2;

class TreeNode;
class PrintNode;

class pNode{
public:
	TreeNode* Data;
	pNode* prev;
	pNode* next;
};

class pStack{
public:
	pStack();
	~pStack();
	void push(TreeNode* _pNode);
	TreeNode* pop();
	int IsEmpty();
	int GetCount();
	TreeNode* GetTop();

private:
	int Count;
	pNode* Top;
};

class TreeNode{
public:
	TreeNode* LeftNode;
	std::string Data;
	TreeNode* RightNode;
};

class PrintNode{
public:
	int Height = 0;
	std::string Data;
	PrintNode* prev;
	PrintNode* next;
};

class PrintStack{
public:
	PrintStack();
	~PrintStack();
	void push(std::string _Data, int _Height);
	std::string pop();
	int GetCount();
	std::string at(int height);
private:
	int Count;
	PrintNode* Top;
};

class Tree{
public:
	Tree();
	~Tree();
	TreeNode* Create(TreeNode* left, TreeNode* root, TreeNode* right);
	TreeNode* Create(int number);
	TreeNode* Create(int number, char op);

	void DestoryTree(TreeNode* pNode);
	void DestoryNode(TreeNode* pNode);
	void Make(int x, int y, int result, char op);
	void PostOrder(TreeNode* pTreeNode, int level = 0, PrintStack* pStackNode = NULL);
	void PrintOut(TreeNode* pNode);
	int SkewedHeight(int Type, TreeNode* pNode);
	TreeNode* GetTree();

private:
	int resultToInt(std::string D);	
	std::string GetResult(int number, char op);
	pStack* newStack;

protected:
	void SetLine(bool check);
	void SetData(int Type, std::string Data);
	bool GetLine();
	bool printLine;
	std::string RootData;
	std::string TreeData;
};

#include "tree_detail.h"

#endif
