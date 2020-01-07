/*
	�ݿ��������б�
	����: ����(Binary Tree) ����5 - 2��(����)
	�а�: Business & CSE
	�й�: 20101215
	�̸�: ������
*/

#ifndef _STACK_INL_H_
#define _STACK_INL_H_

#include <iostream>
#include "stack.h"

using namespace std;

template <class T>
Stack<T>::Stack(){
	Count = 0;
	Top = new Node<T>();
	Top->Data = NULL;
	Top->prev = NULL;
	Top->next = NULL;
}

template <class T>
Stack<T>::~Stack(){

	Node<T>* prevNode;
	while (Top != NULL)
	{
		prevNode = Top;
		Top = Top->prev;
		delete prevNode;
	}
}

template <class T>
void Stack<T>::push(T Data){

	if (Top->Data == NULL)
	{
		Top->Data = Data;
	}
	else
	{
		Node<T>* createNode = new Node<T>();
		createNode->Data = Data;
		createNode->prev = Top;
		createNode->next = NULL;

		Top->next = createNode;
		Top = Top->next;
	}

	Count++;

}

template <class T>
T Stack<T>::pop(){

	T Data = NULL;

	if (Top->prev == NULL)
	{
		Top->prev = NULL;
		Top->next = NULL;
		Data = Top->Data;
		Top->Data = NULL;
	}
	else{

		Node<T>* prevNode = Top->prev;
		Data = Top->Data;
		delete Top;

		Top = prevNode;
	}
	Count--;

	return Data;
}

template <class T>
T Stack<T>::get_stack_top(void)
{
	return (Top->Data == NULL) ? -1 : Top->Data;

}

template <class T>
int Stack<T>::is_stack_empty(void)
{
	return (Top->Data == NULL);
}

#endif