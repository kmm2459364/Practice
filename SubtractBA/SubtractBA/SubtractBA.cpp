//==========================================================
//	差分b-a
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // sscanf(),scanf(),printf()
// 関数プロトタイプ

int main(int argc, char* argv[])
{
	int a, b;
	do {
		printf("aの値:");
		scanf("%d", &a);
	} while (a <= 0);
	do {
		printf("bの値:");
		scanf("%d", &b);
		if(b <= a)
		puts("aより大きな値を入力せよ！");
	} while (b <= a);
	
	// ここをコーディングしてください。
	// b<=a なら再度入力させます。

	printf("%d - %d = %d\n", b, a, b - a);
	return 0;
}