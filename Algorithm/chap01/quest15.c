#include <stdio.h>

void rectangle(int a, int b);

int main(void)
{
	int a, b;
	puts("직사각형을 출력합니다.");
	printf("높이 : "); scanf("%d", &a);
	printf("너비 : "); scanf("%d", &b);
	rectangle(a, b);
	return 0;
}

void rectangle(int a, int b)
{
	int i, j;
	for(i = 0; i < a; i++) {
		for(j = 0; j < b; j++) {
			printf("*");
		}
		printf("\n");
	}
}
