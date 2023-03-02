/*세 값의 최솟값을 구하는 min 힘수를 작성하세요.*/
#include <stdio.h>

int min3(int a, int b, int c)
{
	int min = a;
	if(min > b) min = b;
	if(min > c) min = c;
	return min;
}

int main(void)
{
	int a, b, c;
	while(1){
	printf("세 원소를 입력하세요.\n");
	printf("a의 값 : "); scanf("%d", &a);
	printf("b의 값 : "); scanf("%d", &b);
	printf("c의 값 : "); scanf("%d", &c);
	printf("min3(%d, %d, %d) = %d\n", a, b, c, min3(a, b, c));
	}
	return 0;
}

