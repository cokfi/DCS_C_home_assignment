#include <stdio.h>
#include "..\header\func.h"     // private library - HAL layer



int main() {

	int Mat[M][M], auxMat[M][M];
	int matTrace, maxDiag, offset = 0;
	char Selector = '0',ch, str[3];

	show(menu);

	while (1) {

		printf("insert a menu clause number: ");
		Selector = getchar();
		getchar(); // get the enter key

		switch (Selector) {
		case '0':
			break;

		case '1':
			do {
				printf("Insert an offset value between 0-100: ");
				gets(str);
				sscanf_s(str, "%d", &offset);
				if (offset >= 0 && offset <= 100) break;

			} while (1);
			FillMatrix(Mat, offset);
			break;

		case '2':
			maxDiag = DiagonalsMax(Mat);
			printf("The maximal diagonal element = %d\n", maxDiag);
			break;

		case '3':
			matTrace = ComputeTrace(Mat);
			printf("The mat Trace value = %d\n", matTrace);
			break;

		case '4':
			Transpose(Mat, auxMat);
			show_matrix(auxMat);
			break;

		case '5':
			show_matrix(Mat);
			break;

		case '6':
			show_menu(menu);
			break;

		case '7':
			return 0;

		default:
			printf("Try agian, You have inserted wrong number\n");
			break;
		}
	}
}