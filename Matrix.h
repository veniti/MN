#pragma once
#include<math.h>
#include<cstdlib>
#include<cstdio>


class Matrix {
public:
	int N;
	int M;
	double *body;

	Matrix(int N);
	Matrix::Matrix(int N, int M);


	void Matrix::print();
	static int Matrix::index(int i, int j, int N);
	static Matrix* Matrix::addMatrices(Matrix* A, Matrix* B);
	void Matrix::negMatrice();
	double * Matrix::vectTimesMatrix(double * A, double * V);
	void Matrix::diag(double a);
	void Matrix::across(double a, int that);

};