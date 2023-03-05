#include <stdio.h>

void triangleLB(int n);
void triangleLU(int n);

int main(void)
{
	int n;
	printf("삼각형 단수를 입력하세요. : ");
	scanf("%d", &n);

	triangleLB(n);
	putchar('\n');
	triangleLU(n);

	return 0;
}

void triangleLB(int n)
{
	int i, j;
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= i; j++)
			putchar('*');
		putchar('\n');
	}
}

void triangleLU(int n)
{
	int i, j;

	for(i = 0; i < n; i++) {
		for(j = 1; j <= n - i; j++)
			putchar('*');
		putchar('\n');
	}
}













