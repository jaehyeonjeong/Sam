#include <stdio.h>

int main(void)
{
	int n;
	puts("n에 들어갈 숫자를 입력해주세요.");
	printf("n : "); scanf("%d", &n);
	int sum = 0;
	int i = 1;
	while(n >= i) {
		sum += i;
		i++;
	}
	printf("sum : %d\n", sum);
	return 0;
}
