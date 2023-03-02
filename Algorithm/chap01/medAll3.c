/*세 정수의 값을 입력하고 중앙값을 구합니다. */
#include <stdio.h>

/*---a,b,c의 중앙값을 구합니다.---*/
int med3(int a, int b, int c)
{
	if(a >= b)
		if(b >= c)
			return b;
		else if(a <= c)
			return a;
		else
			return c;
	else if(a > c)
		return a;
	else if(b > c)
		return c;
	else
		return b;
}

int main(void)
{
	printf("med3(%d, %d, %d) = %d,", 1, 2, 2, med3(1, 2, 2));
	printf("med3(%d, %d, %d) = %d,", 1, 3, 3, med3(1, 3, 3));   
	printf("med3(%d, %d, %d) = %d,", 1, 2, 3, med3(1, 2, 3));   
	printf("med3(%d, %d, %d) = %d,", 1, 3, 2, med3(1, 3, 2));   
	printf("med3(%d, %d, %d) = %d,", 2, 1, 3, med3(2, 1, 3));
	printf("med3(%d, %d, %d) = %d,", 2, 3, 1, med3(2, 3, 1));   
	printf("med3(%d, %d, %d) = %d,", 2, 2, 3, med3(2, 2, 3));   
	printf("med3(%d, %d, %d) = %d,", 2, 2, 3, med3(2, 2, 3));   
	printf("med3(%d, %d, %d) = %d,", 3, 2, 3, med3(3, 2, 3));   
	printf("med3(%d, %d, %d) = %d,", 3, 2, 1, med3(3, 2, 1));   
	return 0;
}
