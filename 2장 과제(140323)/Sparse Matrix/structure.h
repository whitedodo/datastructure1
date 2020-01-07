/////////////////////////////////////////////////////////////
////
////  �ݿ��������б� �濵�а� 
////  �й�: 20101215
////  �̸�: �� �� �� ///////////////////////////////////////
////  ���ϸ�: Structure.H 
////  ����: ������ ���α׷� ���� ����

#ifndef _STRUCTURE_H_
#define _STRUCTURE_H_

using namespace std;

const int FALSE = 0;
const int TRUE = 1;
const int INSERT = 2;
const int PROCESS = 3;
const int RESULT = 5;

const int YES = 1;
const int NO = 0;

const int MatrixA = 0;
const int MatrixB = 1;
const int MatrixC = 2;

// ����� ��
class MatrixSpas{

public:
	int row;
	int col;
	int value;
};


// ����� ���
class Matrix{

private:
	int m, n, p;

	int A_Size;
	int B_Size;
	int C_Size;

	MatrixSpas *A_Spas;
	MatrixSpas *B_Spas;
	MatrixSpas *C_Spas;

public:
	void SetM(int _M){ m = _M; }
	void SetN(int _N){ n = _N; }
	void SetP(int _P){ p = _P; }
	void SetSizeA(int _SizeA){ A_Size = _SizeA; }
	void SetSizeB(int _SizeB){ B_Size = _SizeB; }
	void SetSizeC(int _SizeC){ C_Size = _SizeC; }

	int GetM(){ return m; }
	int GetN(){ return n; }
	int GetP(){ return p; }
	int GetSizeA(){ return A_Size; }
	int GetSizeB(){ return B_Size; }
	int GetSizeC(){ return C_Size; }

	void SetMatrix(int, int, int);

	Matrix(int, int, int);
	~Matrix();
	// Welcome
	void Intro();

	// �Է� ����
	int Insert(int);
	void InsertTitle(int, int);
	void InsertData(int, int, int);
	void InsertMatrix(int, int, int, int, int);
	void InsertResize(int, int);

	// ���μ��� ����
	int Calculate(int);

	// ����ó��
	void Multiply(int);

	int ValueOfMatrix(int, int);
	int B_ValueOfMatrix(int, int);

	// ��� ����
	void PrintOut(int);

};

// �ʱ�ȭ
Matrix::Matrix(int _M, int _N, int _P)
{
	SetM(_M);
	SetN(_N);
	SetP(_P);

	SetMatrix(GetM(), GetN(), GetP());
}

// �Ұ�
Matrix::~Matrix(){

	delete[] A_Spas;
	delete[] B_Spas;
	delete[] C_Spas;
}

void Matrix::SetMatrix(int M, int N, int P){

	SetSizeA(GetM() * GetN());
	SetSizeB(GetN() * GetP());
	SetSizeC(GetM() * GetP());

	A_Spas = new MatrixSpas[GetSizeA()];
	B_Spas = new MatrixSpas[GetSizeB()];
	C_Spas = new MatrixSpas[GetSizeC()];
}

#endif