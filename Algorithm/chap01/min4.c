/*네 값의 최솟값을 구하는 min4 함수를 작성하세요*/
#include <stdio.h>

int min4(int a, int b, int c, int d)
{
	int min = a;
	if(min > b) min = b;
	if(min > c) min = c;
	if(min > d) min = d;
	return min;
}

int main(void)
{
	int a, b, c, d;
	while(1){
		printf("네 원소를 입력하여 주세요.\n");
		printf("a의 값 : "); scanf("%d", &a);
		printf("b의 값 : "); scanf("%d", &b);
		printf("c의 값 : "); scanf("%d", &c);
		printf("d의 값 : "); scanf("%d", &d);
		printf("min4(%d, %d, %d, %d) = %d\n", a, b, c, d, min4(a, b, c, d));
	}
	return 0;
}

