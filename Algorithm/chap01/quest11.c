#include <stdio.h>

int main(void)
{
	int n, count;
	printf("숫자를 입력하세요 : "); scanf("%d", &n);
	do{
		n = n / 10;
		if(n != 0)
			count++;
	}while(n != 0);
	printf("그 수는 %d자리 입니다.\n", count + 1);
	return 0;
}
