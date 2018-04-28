/*

Ax = b
A = dziedzina
b = wektor pobudzenia

r: x = wektor rozwiązań

Mr = b
Ax = b

A - NxN
b - N

N = 900

A :
5 diagonali -> a3 a2 a1 a2 a3




wektor residuum 
res(k) = A*x(k) - b
norm(res(k)) <- norma euklidesowa
=> błąd x(k)
dokładne -> wektor zerowy 
(res(k) < 10**-6 lub -9



*/

/*


Zadanie B– Zaimplementuj metody iteracyjne rozwiązywania układów równań
liniowych: Jacobiego i Gaussa–Seidla. Sprawdź ile iteracji potrzebuje 
każda z nich,dla  układu  równań  z  podpunktuA,  żeby  otrzymać  normę 
z  wektora  residuumrówną 10−9. Porównaj czas trwania algorytmów. (30%)

Zadanie C– Stwórz układ równań dlaa1 = 3,a2 =a3 =−1 iN= 9cd, natomiast
wektorbpozostaw bez zmian. Czy metody iteracyjne dla takich wartości 
zbiegająsię? (10%)


Zadanie D– Zaimplementuj metodę bezpośredniego 
rozwiązania układów rów-nań  liniowych:  metodę  faktoryzacji  LU  i 
zastosuj  do  przypadkuC.  Ile  wynosinorma z residuum w tym przypadku? (30%)

Zadanie E–  Stwórz  wykres  zależności  czasu  trwania  poszczególnych  algoryt-mów
od liczby niewiadomychN={100,500,1000,2000,3000. . .}dla przypadku
z punktuA. (10%)


Zadanie F–  Zwięźle  opisz  swoje  obserwacje  po  wykonaniu  podpunktów  A–E.(10%)

*/


//165600
/*



a1 = 11
a2 = a3 = -1
N = 900

b(n) = sin(6*n);
radiany czy kąty?


*/


#include "Matrix.h"
#define N 8






int J(double * matrixA, double * vectorD, double * matrixU, double * matrixL, double *vectorX, double * vectorB )
{
	int count = 0;
	double residuum = 1;

	while (residuum > 1e-9)
	{


		count++;
	}

	return count;
}


void GS()
{

}


int main()
{

	double *vectorB = (double*)malloc(N*sizeof(double));
	double *vectorX = (double*)malloc(N * sizeof(double));
	// x to wektor kolumnowy


	double *vectorD = (double*)malloc(N * sizeof(double));
	double *matrixL = (double*)malloc(N * N * sizeof(double));
	double *matrixU = (double*)malloc(N * N * sizeof(double));

	Matrix* matrixA = new Matrix(N);

	int a1 = 11, a2 = -1, a3 = -1;

	matrixA->diag(a1);
	matrixA->across(a2, 1);
	matrixA->across(a2, -1);
	matrixA->across(a3, 2);
	matrixA->across(a3, -2);
	matrixA->print();
	printf("\n");


	Matrix* matrixB = new Matrix(N);
	matrixB->across(3, 4);
	matrixB->across(-3, 2);
	matrixB->across(2, -2);
	matrixB->across(1, 1);
	matrixB->print();
	printf("\n");

	Matrix * matrixC = new Matrix(N);
	matrixC = Matrix::addMatrices(matrixA, matrixB);
	printf("\n");
	matrixC->print();
	for (int i = 0; i < N; i++)
	{
		vectorB[i] = sin(6 * i);
		vectorD[i] = a1;
		vectorX[i] = 1;
	}

	/*for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int ind = index(i, j);
			if (i == j)
			{
				matrixA[ind] = a1;
				matrixL[ind] = 0;
				matrixU[ind] = 0;
			}
			else if (i == j - 1)
			{
				matrixA[ind] = a2;
				matrixL[ind] = a2;
				matrixU[ind] = 0;

			}
			else if (i == j + 1)
			{
				matrixA[ind] = a2;
				matrixL[ind] = 0;
				matrixU[ind] = a2;
			}
			else if (i == j - 2)
			{
				matrixA[ind] = a3;
				matrixL[ind] = a3;
				matrixU[ind] = 0;
			}
			else if (i == j + 2)
			{
				matrixA[ind] = a3;
				matrixL[ind] = 0;
				matrixU[ind] = a3;
			}
			else
			{
				matrixA[ind] = 0;
				matrixL[ind] = 0;
				matrixU[ind] = 0;

			}
		}
	}*/

	/*
	sprawdź, czy macierz jest oki
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) {
			printf("%d ", (int)matrix[index(i,j)]);
		}
		printf("\n ");
	}
	
	*/

	for (int i = 0; i < N; i++)
	{
		printf("%f ", vectorB[i]);
	}


	bool *values = new bool[100];
	for (int i = 20; i < 100; i++)
	{
		values[i] = true;
	}

	for (int i = 0; i < 100; i++)
	{
		printf("%d ", values[i]);
	}




	/*double T[] = { 1,2,3,4 };
	double V[] = { 1,1 };

	double *R = vectTimesMatrix(T, V);
	printf("%d %d", (int)R[0], (int)R[1]);*/

	return 0;
}
