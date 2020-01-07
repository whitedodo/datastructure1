/*
	�ݿ��������б�
	����: ����(Binary Tree) ����5 - 2��(����)
	�а�: Business & CSE
	�й�: 20101215
	�̸�: ������
*/

#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>
#include <string>

using namespace std;

const int MAX = 100;

template <class T>
class BinaryNode;

template <class T>
class BinaryTree;

template <class T>
class CalcTree;

template <class T>
class Node{
public:
	T Data;
	Node<T>* prev;
	Node<T>* next;
};

template <class T>
class Stack{
public:
	Stack();
	~Stack();
	void push(T t);
	T pop(void);
	T get_stack_top(void);
	int is_stack_empty(void);

private:
	int Count;
	Node<T>* Top;
};

#include "stack_inl.h"

#endif
