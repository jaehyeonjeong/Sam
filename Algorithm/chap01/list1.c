#include <stdio.h>

int main(void)
{
	int n;
	printf("수를 입력하세요. : ");
	scanf("%d", &n);

	if(n == 1)
		printf("1입니다.\n");
	else if(n == 2)
		printf("2입니다.\n");
	else if(n == 3)
		printf("3입니다.\n");
	else 
		;
	return 0;
}

