#include "Matrix.h"

Matrix::Matrix(int NumRow, int NumColumn)
{
	Row = NumRow;
	Column = NumColumn;
	MyMatrix = new double*[NumRow];
	Pivots = new double[NumColumn];
	for (int i = 0; i < NumRow; i++)
	{
		MyMatrix[i] = new double[NumColumn];
	}
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Column; j++)
		{
			MyMatrix[i][j] = 0.0;
		}
	}
}

void Matrix::SetMatrix()
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Column; j++)
			cin >> MyMatrix[i][j];
	}
}

void Matrix::DisplayMatrix()
{
	cout << endl;
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Column; j++)
		{
			if (MyMatrix[i][j] == -0.0)
				MyMatrix[i][j] = 0.0;
			cout << MyMatrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void Matrix::AddMatrix(Matrix A, Matrix B)
{
	for (int i = 0; i < A.Row; i++)
	{
		for (int j = 0; j < A.Column; j++)
		{
			MyMatrix[i][j] = A.MyMatrix[i][j] + B.MyMatrix[i][j];
		}
	}
	DisplayMatrix();
}

void Matrix::ScaleMatrix(double r)
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Column; j++)
			MyMatrix[i][j] *= r;
	}
	cout << "Scaled matrix :" << endl;
	DisplayMatrix();
}

void Matrix::SubtractMatrix(Matrix A, Matrix B)
{
	for (int i = 0; i < A.Row; i++)
	{
		for (int j = 0; j < A.Column; j++)
		{
			MyMatrix[i][j] = A.MyMatrix[i][j] - B.MyMatrix[i][j];
		}
	}
	DisplayMatrix();
}

void Matrix::Transpose()
{
	for (int i = 0; i < Row - 1; i++)
	{
		for (int j = i + 1; j < Column; j++)
		{
			swap(MyMatrix[i][j], MyMatrix[j][i]);
		}
	}
	cout << "The Transposed Matrix is : " << endl;

	DisplayMatrix();
}

void Matrix::Multiplication(Matrix A, Matrix B)
{
	Row = A.Row;
	Column = B.Column;
	double Element;

	for (int i = 0; i < A.Row; i++)
	{
		for (int j = 0; j < B.Column; j++)
		{
			Element = 0;
			for (int h = 0; h < A.Column; h++)
			{
				Element = Element + (A.MyMatrix[i][h] * B.MyMatrix[h][j]);
			}
			MyMatrix[i][j] = Element;
		}
	}
}

Matrix Matrix::Copy(Matrix B, Matrix C)
{
	for (int i = 0; i < C.Row; i++)
	{
		for (int j = 0; j < B.Row; j++)
		{
			C.MyMatrix[i][j] = B.MyMatrix[i][j];
		}
	}
	return B;
}

void Matrix::SwitchRow(int RowOne, int RowTwo)
{
	for (int i = 0; i < Column; i++)
	{
		swap(MyMatrix[RowOne][i], MyMatrix[RowTwo][i]);
	}

}

void Matrix::Power(double p, Matrix A)
{
	Matrix B(A.Row, A.Column), D(A.Row, A.Column);
	Copy(A, B);
	for (double i = 0; i < p - 1; i++)
	{
		D.Multiplication(A, B);
		Copy(D, B);
	}
	cout << "The Matrix After Being Powered to " << p << " : " << endl;
	D.DisplayMatrix();
}

void Matrix::Divide(int RowOne, int RowTwo, double Coefficient)
{
	//Determinant /= (double)Coefficient;
	for (int i = 0; i < Column; i++)
	{
		MyMatrix[RowTwo][i] = (Coefficient* MyMatrix[RowOne][i]) + MyMatrix[RowTwo][i];
	}
}

int Matrix::FindPivot(int MatrixRow, int MatrixColumn)
{
	bool PivotFound = false;
	if (MyMatrix[MatrixRow][MatrixColumn] == 0)
	{
		for (int i = Row - 1; i > MatrixRow; i--)
		{
			if (MyMatrix[i][MatrixColumn] != 0)
			{
				SwitchRow(MatrixRow, i);
				Determinant *= -1.0;
				PivotFound = true;
			}
			if (PivotFound)
				break;
		}
		if (!PivotFound)
		{
			Pivots[MatrixColumn] = 0;
			return MatrixRow;
		}
		else
			Pivots[MatrixColumn] = 1;
	}
	for (int i = MatrixRow + 1; i < Row; i++)
	{
		Divide(MatrixRow, i, ((double)(-1.0)*((double)MyMatrix[i][MatrixColumn]) / (double)MyMatrix[MatrixRow][MatrixColumn]));
	}
	MatrixRow++;

	return MatrixRow;
}

void Matrix::ConsistentAndBasic()
{
	bool OneSolution = true;

	if (Row == Column - 1)
	{
		if (Pivots[Column - 1] == 1)
		{
			IsConsistent = false;
			cout << "System Is Inconsistent." << endl << "System Has No Solution." << endl;
		}
		else
		{
			cout << "System Is Consistent." << endl;
			
			for (int i = 0; i < Column - 1; i++)
			{																														 
				if (Pivots[i])
					cout << "X" << i + 1 << " Is Basic Variable." << endl;
				else
					cout << "X" << i + 1 << " Is Free Variable." << endl;
			}
			cout << endl;

			if (Pivots[Column - 2] == 0)
			{
				cout << "System Has Many Solutions." << endl;
			}
			else
			{
				cout << "System Has Only One Solution." << endl;
				ReducedEchelonForm();
				for (int i = 0; i < Row; i++)
				{
					cout << "X" << i + 1 << "=" << MyMatrix[i][Column - 1] << endl;
				}
			}
			cout << endl;
		}
	}
	else
	{
		if (Pivots[Column - 2] == 1)
		{
			IsConsistent = false;
			cout << "System Is Inconsistent." << endl << "System has no solution." << endl;
		}
		else
		{
			cout << "System Is Consistent." << endl;
			for (int i = 0; i < Column - 1; i++)
			{
				if (Pivots[i])
					cout << endl << "X" << i + 1 << " Is Basic Variable." << endl;
				else
					cout << endl << "X" << i + 1 << " Is Free Variable." << endl;
			}
			cout << endl;

			if (Pivots[Column - 2] == 0)
			{
				cout << "System Has Many Solutions." << endl;
			}
			else
			{
				cout << "System Has Only One Solution." << endl;
				ReducedEchelonForm();
				for (int i = 0; i < Row; i++)
				{
					cout << "X" << i + 1 << "=" << MyMatrix[i][Column - 1] << endl;
				}
			}
			cout << endl;
		}
	}

}

void Matrix::EchelonForm()
{
	int CurrentColumn = 0, CurrentRow = 0;
	while (CurrentColumn < Column && CurrentRow < Row)
	{
		CurrentRow = FindPivot(CurrentRow, CurrentColumn);
		CurrentColumn++;
	}
}

void Matrix::ReducePivot(int MatrixRow, int MatrixColumn){	double divisor = MyMatrix[MatrixRow][MatrixColumn];	for (int i = 0; i < Column; i++)	{		(double)MyMatrix[MatrixRow][i] /= divisor;		}	ZeroPivotColumn(MatrixRow, MatrixColumn);}void Matrix::ZeroPivotColumn(int PivotRow, int PivotColumn){  	for (int i = PivotRow-1; i >= 0; i--)	{		double Coefficient = -1.0*MyMatrix[i][PivotColumn];		for (int j = 0; j < Column; j++)		{			MyMatrix[i][j] = (MyMatrix[i][j]+( (double)Coefficient*MyMatrix[PivotRow][j])); 		}	}}
void Matrix::ReducedEchelonForm()
{
	EchelonForm();
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Column; j++)
		{
			if (MyMatrix[i][j] != 0)
			{
				ReducePivot(i, j);
				break;
			}
		}
	}
}

void Matrix::CalculateDeterminant()
{
	EchelonForm();
	for (int i = 0; i < Row; i++)
	{
		Determinant *= (double)MyMatrix[i][i];
	}
	cout << "Determinant = " << Determinant << endl << endl;
}

void Matrix::InverseMatrix()
{  
	if (Determinant == 0)
	{
		cout << "Matrix Isn't Invertible" << endl;
		return;
	}
	Matrix A(Row, 2 * Column);
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Column; j++)
		{
			A.MyMatrix[i][j] = MyMatrix[i][j];
		}
		A.MyMatrix[i][i + 3] = 1.0;
	}
	A.ReducedEchelonForm();
	for (int i = 0; i < Row; i++)
	{
		for (int j = (A.Column/2); j < A.Column; j++)
		{
			cout << A.MyMatrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

}

Matrix::~Matrix()
{
}
