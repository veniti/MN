#include "Matrix.h"


Matrix::Matrix(int N)
{
	this->N = N;
	this->body = (double*)calloc(N*N, sizeof(double));
}

Matrix::Matrix(int N, int M)
{
	this->N = N;
	this->M = M;
	this->body = (double*)calloc(N*M, sizeof(double));
}



int Matrix::index(int i, int j, int N)
{
	return i + N*j;
}

void Matrix::print()
{
	for (int i = 0; i < this->N; i++)
	{
		for (int j = 0; j < this->N; j++) {
			printf("%-2d ", (int)this->body[index(i, j, N)]);
		}
		printf("\n");
	}
}


void Matrix::diag(double a)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) {
			if (i == j)
			{
				this->body[index(i, j, N)] = a;
			}
		}
	}
}

Matrix* Matrix::addMatrices(Matrix* A, Matrix* B)
{
	if (A->N != B->N) return 0;
	Matrix *R = new Matrix(A->N);
	for (int i = 0; i < R->N; i++)
	{
		for (int j = 0; j < R->N; j++) {
		
			R->body[index(i, j, R->N)] = A->body[index(i, j, R->N)] + B->body[index(i, j, R->N)];
		}
	}
	return R;
}

void Matrix::across(double a, int that)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) {
			if (i == j + that)
			{
				this->body[index(i, j, N)] = a;
			}
		}
	}
}











double * Matrix::vectTimesMatrix(double * A, double * V)
{
	double *R = (double*)calloc(N, sizeof(double));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			R[i] += A[j + N*i] * V[j];
		}
	}
	return R;
}
