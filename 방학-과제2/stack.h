/*
	금오공과대학교
	과제: 방학(Binary Tree) 과제5 - 2번(계산식)
	학과: Business & CSE
	학번: 20101215
	이름: 정원영
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
