#include <stdio.h>

void square(int n)
{
	int i, j;
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			printf("*");
		}
		printf("\n");
	}
}

int main(void)
{
	int n;
	puts("사각형을 출력합니다.");
	printf("입력할 수 : "); scanf("%d", &n);
	square(n);
	return 0;
}

