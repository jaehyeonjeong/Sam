/*1,2 ..., n의 합을 구합니다.*/
#include <stdio.h>

int main(void)
{
	int i, n;
	int sum;	/*합*/
	puts("1부터 n까지의 합을 구합니다.");
	printf("n의 값 : ");
	scanf("%d", &n);
	sum = 0;
	i = 1;
	while(i <= n) { /*i가 n이하이면 반복합니다.*/
		printf("i : %d\n", i);
		sum += i;	/*sum에 i를 더합니다.*/
		i++;		/*i 값을 1증가 시킵니다.*/
		printf("i++ : %d\n", i);
	}
	printf("1부터 %d까지의 합은 %d입니다.\n", n, sum);

	return 0;
}
