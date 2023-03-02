/*네 값의 최댓값을 구하는 함수 max4를 작성하세요.*/
#include <stdio.h>

int max4(int a, int b, int c, int d)
{
	int max = a;
	if(b > max) max = b;
	if(c > max) max = c;
	if(d > max) max = d;
	return max;
}

int main(void)
{
	int a, b, c, d;
	while (1) {
	printf("네 개의 원소를 입력하세요. \n");
	printf("a의 값 : "); scanf("%d", &a);
	printf("b의 값 : "); scanf("%d", &b);
	printf("c의 값 : "); scanf("%d", &c);
	printf("d의 값 : "); scanf("%d", &d);
	printf("max4(%d, %d. %d. %d) = %d\n", a, b, c, d, max4(a, b, c, d));
	}
	return 0;
}
	
