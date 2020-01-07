/*    OOOOOOOOOOO 경영학과
	  학번: 20101215
	  이름: 정 O O
	  과제: 4장 (3번) - 다항식 곱셈 (HeadNode 제거)
*/

#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_

const int EMPTY = -1;

enum VAR{ COEF, EXP };

class PolyNode{
public:
	PolyNode();
	~PolyNode();

	int Type;
	int Coef;
	PolyNode* Prev;
	PolyNode* Next;

	PolyNode* Up;
	PolyNode* Down;
	
	union
	{	
		int Exp;
	};
	
};

class List{
public:
	List();
	~List();
	void Write(PolyNode& List);
	PolyNode* Insert(PolyNode* dSource, PolyNode* dNode);
	PolyNode* Create(int _Type, int _Data);
	
	void at(int _IDX);
private:
};

class PolyNomial{
public:
	PolyNomial();
	~PolyNomial();

	PolyNode* pAdd(PolyNode* A_List, PolyNode* B_List);
	PolyNode* Multiply(PolyNode* A_List, PolyNode* B_List);
	void PrintOut(PolyNode List);

private:

};

#endif