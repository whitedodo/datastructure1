#ifndef _EQUIV_H_
#define _EQUIV_H_

#include <iostream>
#include <fstream>

enum Boolean { FALSE, TRUE };

class ListNode {
	friend void Equivalence(char*);
	friend void PrintOut(ListNode** seq, Boolean* out, int n);

private:
	int data;
	ListNode *link;
	ListNode(int);
};

typedef ListNode* ListNodePtr;

#endif