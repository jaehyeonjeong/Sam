#include <stdio.h>

int main(void)
{
	char *txt = "abcd";
	char swap_txt[4];

	for(int i = 0, z = 3; i < 4; i++, z--)
		swap_txt[z] = txt[i];

	printf("%s\n", swap_txt);
	return 0;
}
