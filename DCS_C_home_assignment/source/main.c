#include <stdio.h>
#include "..\header\func.h"     // private library - HAL layer



int main() {

	int Mat1[M][M], Mat2[M][M], auxMat[M][M];
	int matTrace1, matTrace2, maxDiag1, maxDiag2, offset = 0;
	char Selector = '0',matName[30],str[3];

	show(menu);

	while (1) {

		printf("Choose a menu clause number: ");
		Selector = getchar();
		getchar(); // get the enter key

		switch (Selector) {
		case '0':
			break;

		case '1':
			//fill matrix 1
			do {
				printf("In order to creat Mat1 please insert an offset value between 0-100:");
				gets(str);
				sscanf_s(str, "%d", &offset);
				if (offset >= 0 && offset <= 100) break;

			} while (1);
			FillMatrix(Mat1, offset);
			//fill matrix 2
			do {
				printf("In order to creat Mat2 please insert an offset value between 0-100:");
				gets(str);
				sscanf_s(str, "%d", &offset);
				if (offset >= 0 && offset <= 100) break;

			} while (1);
			FillMatrix(Mat2, offset);
			break;

		case '2':
			// adding two matrices
			for (int i = 0; i < M; ++i)
				for ( int j = 0; j < M; ++j) {
					auxMat[i][j] = Mat1[i][j] + Mat2[i][j];
					
				}
			show_matrix(auxMat);
			break;
		case '3':
			//find max diagonal element
			maxDiag1 = DiagonalsMax(Mat1);
			maxDiag2 = DiagonalsMax(Mat2);
			if (maxDiag1 > maxDiag2) {
				printf("Mat1 has the maximal diagonal element value: %d\n", maxDiag1);
			}
			else {
				printf("Mat2 has the maximal diagonal element value: %d\n", maxDiag2);
			}
			break;

			
		case '4':
			//find the biggest trace 
			matTrace1 = ComputeTrace(Mat1);
			matTrace2 = ComputeTrace(Mat2);
			if (matTrace1 > matTrace2) {
				printf("Mat1 has the maximal Trace value : %d\n", matTrace1);
			}
			else {
				printf("Mat2 has the maximal Trace value : %d\n", matTrace2);
			}
			break;

		case '5':
			// Copy mat1 right diagonals to mat2 left diagonals
			for (int i = 0; i < M; ++i)
				 Mat2[i][i] = Mat1[i][M-1-i] ;

			break;

		case '6':
			while (1) {
				printf("Insert the wanted matrix[Mat1 or Mat2] :");
				fgets(matName, sizeof(matName), stdin);  // read string
				if (matName[3] == '1') {
					Transpose(Mat1, auxMat);
					break;
				}
				else if (matName[3] == '2') {
					Transpose(Mat2, auxMat);
					break;
				}
			}
			show_matrix(auxMat);
			break;

		case '7':
			while (1) {
				printf("Insert the wanted matrix[Mat1 or Mat2] :");
				fgets(matName, sizeof(matName), stdin);  // read string
				if (matName[3] == '1') {
					show_matrix(Mat1);
					break;
				}
				else if (matName[3] == '2') {
					show_matrix(Mat2);
					break;
				}
			}
			break;

		case '8':
			show(menu);
			break;

		case '9':
			return 0;

		default:
			printf("Try agian, You have inserted wrong number\n");
			break;
		}
	}
}