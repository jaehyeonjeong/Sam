/*Gauss의 수학 법칙을 이용한 합산 코드*/
#include <stdio.h>

int main(void)
{
	int n;
	puts("Gauss기법을 이용한 코드..1부터 시작해서 n의 값을 입력하세요.");
	printf("n의 값 : "); scanf("%d", &n);

	int halfn, othern, result;
	
	halfn = n / 2;
	othern = n - halfn;
	if(n % 2 == 0)
		result = (1 + n) * halfn;
	else
		result = (1 + n) * halfn + othern;
	printf("result : %d\n", result);
	return 0;
}
