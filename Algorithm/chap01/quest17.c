#include <stdio.h>

void spira(int n);

int main(void)
{
	int n;
	printf("숫자를 입력하세요. : ");
	scanf("%d", &n);

	spira(n);

	return 0;
}

void spira(int n)					//4
{
	int i, j, left, middle;
	for(i = 1; i <= n; i++) {
		left = n - i;				//3
		middle = ((n - 1) * 2 + 1) - (left * 2); //1
		for(j = 1; j <= (n - 1) * 2 + 1; j++) {
			if(middle != 0) {
				if(left > 0) {
					putchar(' ');
					left--;
				} else {
					putchar('*');
					middle--;
				}	
			} else {
				putchar(' ');
			}
		}	
		putchar('\n');
	}
}
