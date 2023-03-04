/*곱셈표를 출력합니다.*/
#include <stdio.h>

int main(void)
{
	int i, j;
	printf("-----덧셈표-----\n");
	printf("  | ");
	for(i = 1; i <= 9; i++) {
		printf("%3d", i);
	}

	printf("\n--+----------------------------\n");

	for(i = 1; i <= 9; i++) {
		printf("%d | ", i);	
		for(j = 1; j <= 9; j++)
			printf("%3d", i + j);
		putchar('\n');
	}
	return 0;
}
