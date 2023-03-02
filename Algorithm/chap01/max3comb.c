/*세 정수의 최댓값을 구하는 프로그램*/
#include <stdio.h>

/*---a,b,c의 최댓값을 구합니다.---*/
int max3(int a, int b, int c)
{
	int max = a; /*최댓값*/
	if(b > max) max = b;
	if(c > max) max = c;
	return max;
}

int main(void)
{
	int a, b, c;
	while(1) {
	printf("세 원소를 입력해주세요.\n");
	printf("a원소 : "); scanf("%d", &a);
	printf("b원소 : "); scanf("%d", &b);
	printf("c원소 : "); scanf("%d", &c);
	printf("max3(%d, %d, %d) = %d\n",a ,b, c, max3(a, b, c));
	}
	return 0;
}
	
