//==========================================================
//	九九表を表示する
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
int n1 = 1;

int main()
{
	printf("   |  1  2  3  4  5  6  7  8  9\n");
	printf("---+----------------------------\n");
	printf(" 1 |");
	while (n1<=9)
	printf("  %d", n1++);
	printf("\n");
	printf(" 2 |");
	for(int i=0;i<9;i++)
		printf("  %d",n1);

	// ここをコーディングしてください。
	return 0;
}