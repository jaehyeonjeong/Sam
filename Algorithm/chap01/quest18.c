#include <stdio.h>

void rspira(int n);

int main(void)
{
	int n;
	printf("숫자를 입력하세요. : ");
	scanf("%d", &n);

	rspira(n);
	return 0;
}

void rspira(int n)
{
	int i, j, left, middle;
	for(i = n; i >= 1; i--) {
		left = n - i;
		middle = ((n - 1) * 2 + 1) - (left * 2);
		for(j = 1; j <= (n - 1) * 2 + 1; j++) {
			if(middle != 0) {
				if(left > 0) {
					putchar(' ');
					left--;
				} else {
					printf("%d", i % 10);
					middle--;
				}
			} else {
				putchar(' ');
			}
		}
		putchar('\n');
	}
}
