#ifndef _func_H_
#define _func_H_

#define SIZE 6
#define M 10 
#define N 10
#define CEIL 100 
#define max(x,y) x>y ? x : y  // MACRO function
char** menu[];

extern void show(char** strlst);
int ComputeTrace(int Mat[M][M]);
int DiagonalsMax(int Mat[M][M]);
void Transpose(int Mat1[M][M], int Mat2[M][M]);
void FillMatrix(unsigned int Mat[M][M], int);

void show_matrix(unsigned int Mat[M][M]);

#endif








