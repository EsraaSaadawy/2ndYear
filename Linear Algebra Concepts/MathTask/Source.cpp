
#include "Matrix.h"

int main()
{
	char C;
	int ROW, COLUMN;
	double r;

	while (true)
	{
		cout << "A: Add. \nT: Transpose. \nR: Scale. \nS: Subtract. \nM: Multiply. \nP: Power. \nI: Inverse Matrix. \nC: Echelon Form. \nU: Reduced Echelon Form. \nD: Determinant. \nE: Exit.\n enter your choice: ";
		cin >> C;

		if (C == 'A' || C == 'a')
		{
			cout << "Enter your matrix size(row,column) : ";
			cin >> ROW >> COLUMN;
			Matrix A(ROW, COLUMN), B(ROW, COLUMN);
			cout << "Enter the first matrix" << endl;
			A.SetMatrix();
			cout << "Enter the second matrix" << endl;
			B.SetMatrix();
			cout << "The Sum of The Two Matrices is : " << endl;
			A.AddMatrix(A, B);
		}

		else if (C == 'i' || C == 'I')
		{
			cout << "Enter your matrix size (row,column) : ";
			cin >> ROW >> COLUMN;
			if (ROW != COLUMN)
			{
				cout << "Matrix must be square" << endl;
			}
			else
			{
				Matrix A(ROW, COLUMN);
				cout << "Enter the matrix" << endl;
				A.SetMatrix();
				cout << "The inverse matrix is : " << endl;
				A.InverseMatrix();
			}
		}

		else if (C == 'C' || C == 'c')
		{
			cout << "Enter Augmented matrix size (row,column) : ";
			cin >> ROW >> COLUMN;
			Matrix A(ROW, COLUMN);
			cout << "Enter the augmented matrix" << endl;
			A.SetMatrix();
			A.EchelonForm();
			cout << "The augmented matrix in echelon form : " << endl;
			A.DisplayMatrix();
			A.ConsistentAndBasic();
		}

		else if (C == 'U' || C == 'u')
		{
			cout << "Enter Augmented matrix size (row,column) : ";
			cin >> ROW >> COLUMN;
			Matrix A(ROW, COLUMN);
			cout << "Enter the augmented matrix" << endl;
			A.SetMatrix();
			A.ReducedEchelonForm();
			cout << "The augmented matrix in reduced echelon form : " << endl;
			A.DisplayMatrix();
			A.ConsistentAndBasic();
		}

		else if (C == 'P' || C == 'p')
		{
			cout << "Enter your matrix size(row,column) : ";
			cin >> ROW >> COLUMN;
			Matrix A(ROW, COLUMN), B(ROW, COLUMN);
			if (ROW != COLUMN)
			{
				cout << "Matrix must be square" << endl;
			}
			else
			{
				cout << "Enter your matrix" << endl;
				A.SetMatrix();
				cout << "Enter power you want to raise matrix to : ";
				cin >> r;
				B.Power(r, A);
			}
		}

		else if (C == 'M' || C == 'm')
		{
			cout << "Enter the number of rows & columns of the first matrix and the number of columns of the second one : ";
			cin >> ROW >> COLUMN;
			Matrix A(ROW, COLUMN);

			cin >> ROW;
			Matrix B(COLUMN, ROW);

			cout << "Enter the first matrix" << endl;
			A.SetMatrix();

			cout << "Enter the second matrix" << endl;
			B.SetMatrix();

			Matrix C(A.Row, B.Column);
			C.Multiplication(A, B);
			cout << "The Two Matrices Multiplied :  " << endl;
			C.DisplayMatrix();
		}

		else if (C == 'S' || C == 's')
		{
			cout << "Enter your matrix size(row,column) : ";
			cin >> ROW >> COLUMN;
			Matrix A(ROW, COLUMN), B(ROW, COLUMN);
			cout << "Enter the first matrix" << endl;
			A.SetMatrix();
			cout << "Enter the second matrix" << endl;
			B.SetMatrix();
			cout << "The Subtraction of The Two Matrices is : " << endl;
			A.SubtractMatrix(A, B);
		}

		else if (C == 'E' || C == 'e')
		{
			cout << "GoodBye :D " << endl;
			break;
		}

		else if (C == 'T' || C == 't')
		{
			cout << "Enter your matrix size(row,column) : ";
			cin >> ROW >> COLUMN;
			Matrix A(ROW, COLUMN);

			cout << "Enter your matrix" << endl;
			A.SetMatrix();
			A.Transpose();
		}

		else if (C == 'R' || C == 'r')
		{
			cout << "Enter your matrix size(row,column) : ";
			cin >> ROW >> COLUMN;
			Matrix A(ROW, COLUMN);
			cout << "Enter your matrix" << endl;
			A.SetMatrix();
			cout << "Enter number you want to scale matrix" << endl;
			cin >> r;
			A.ScaleMatrix(r);
		}
		else if (C == 'D' || C == 'd')
		{

			cout << "Enter the determinant dimensions (row,column) : ";
			cin >> ROW >> COLUMN;
			if (ROW != COLUMN)
			{
				cout << "Determinant must be square." << endl;
			}
			else
			{
				Matrix A(ROW, COLUMN);
				cout << "Enter your determinant" << endl;
				A.SetMatrix();
				A.CalculateDeterminant();
			}
		}
	}
	system("pause");

	return 0;
}