#include <stdio.h>
#include "..\header\func.h"     // private library - HAL layer


int main() {

	char selector, ch;

	show(menu);
	while (1) {
		printf("Choose a menu clause number: ");
		selector = getchar();
		getchar();

		if (selector == '1')
			show(vehicles);
		else if (selector == '2')
			show(currency);
		else if (selector == '3')
			show(animals);
		else if (selector == '4')
			show(menu);
		else if (selector == '5')
			break; // exit from loop
		else
			printf("Try agian, You have inserted wrong number");
	}
	return 0;
}

