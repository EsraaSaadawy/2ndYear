#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

class Matrix
{
public:
	int Row, Column;
	double** MyMatrix;
	double* Pivots;
	bool IsConsistent;
	double Determinant = 1;
	
	Matrix(int NumRow ,int NumColumn);
	void SetMatrix();
	void DisplayMatrix();
	void AddMatrix(Matrix A, Matrix B);
	void ScaleMatrix(double r);
	void SubtractMatrix(Matrix A, Matrix B);
	void Transpose();
	void Multiplication(Matrix A ,Matrix B);
	Matrix Copy(Matrix B,Matrix C);
	void Power(double p,Matrix A);
	void EchelonForm();
	void SwitchRow(int RowOne, int RowTwo);
	void Divide(int RowOne, int RowTwo, double Coefficient);
	int FindPivot(int MatrixRow, int MatrixColumn);
	void ZeroPivotColumn(int PivotRow, int PivotColumn);
	void ReducedEchelonForm();
	void ReducePivot(int MatrixRow, int MatrixColumn);
	void ConsistentAndBasic();
	void CalculateDeterminant();
	void InverseMatrix();

	~Matrix();
};

