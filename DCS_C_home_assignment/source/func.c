#include <stdio.h>
#include "..\header\func.h"     // private library - HAL layer

void show(char** strlst) {
	int i;
	for (i = 0; strlst[i]; i++)
		printf("%s\n", strlst[i]);
	return;
}

char** menu[] = {
	" Menu \n\r-------",
	"1) Create two 10x10 matrices Mat1, Mat2 using the next expression :",
	"	for i, j = { 0 - 9 } : Mat[i][j] = (offset + i * 10 + j) % 100",
	"2) Computeand show the materix Mat1 + Mat2",
	"3) Computeand show the maximal diagonal element between Mat1and Mat2",
	"4) Computeand show the the maximal Trace between matrices Mat1and Mat2",
	"5) Copy mat1 right diagonals to mat2 left diagonals",
	"6) Computeand show the transposed of a given Matrix",
	"7) Show a given Matrix",
	"8) show menu",
	"9) exit",
	NULL
};
char** vehicles[] = { "Chevrolet","Dodge","Chevrolet","Hyundai","Bentley","BMW",NULL };
char** currency[] = { "USD","EUR","GBP","JPY","Bitcoin",NULL };
char** animals[] = { "cat","dog","fish","lion",NULL };
//---------------------------------------------------------------
//                  Fill Matrix
//---------------------------------------------------------------
void FillMatrix(unsigned int Mat[M][M], int offset) {
	int i, j;
	for (i = 0; i < M; i++) {
		for (j = 0; j < M; j++) {
			Mat[i][j] = (offset + i * M + j) % CEIL;
		}
	}
}
//---------------------------------------------------------------
//                  show matrix
//---------------------------------------------------------------
void show_matrix(unsigned int Mat[M][M]) {
	int i, j;
	printf("[\n");
	for (i = 0; i < M; i++) {
		for (j = 0; j < M; j++)
			printf("%d, ", Mat[i][j]);
		printf("\n");
	}
	printf("]\n\n");
	return;
}
//---------------------------------------------------------------
//                  Trace Computation
//---------------------------------------------------------------
int ComputeTrace(int Mat[M][M]) {
	int Trace = 0, i;
	for (i = 0; i < M; i++) Trace += Mat[i][i];
	return Trace;
}
//---------------------------------------------------------------
//                  DiagonalsMax Computation
//---------------------------------------------------------------
int DiagonalsMax(int Mat[M][M]) {
	int Max = 0, i;
	for (i = 0; i < M; i++) {
		Max = max(Mat[i][i], Max);
		Max = max(Mat[i][N - 1 - i], Max);
	}
	return Max;
}
//---------------------------------------------------------------
//                  Matrix Transpose 
//---------------------------------------------------------------
void Transpose(int Mat1[M][M], int Mat2[M][M]) {
	int i, j;
	for (i = 0; i < M; i++) {
		for (j = 0; j < M; j++) {
			Mat2[i][j] = Mat1[j][i];
			Mat2[j][i] = Mat1[i][j];
		}
	}
}

