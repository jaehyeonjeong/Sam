#include <stdio.h>

int sumof(int a, int b)
{
	int sum = 0;
	if(a <= b) {
		while(a <= b) {
			sum += a;
			a++;
		}
	}
	else if(a >= b) {
		while(a >= b) {
			sum += b;
			b++;
		}
	}
	else
		sum = a;
	return sum;
}

int main(void)
{
	int a, b;
	puts("a와 b의 원소를 각각 입력하세요.");
	printf("a의 값 : "); scanf("%d", &a);
	printf("b의 값 : "); scanf("%d", &b);
	printf("result : %d\n", sumof(a, b));
	return 0;
}
