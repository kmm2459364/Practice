//==========================================================
//	�z��T���v��
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()

const int N = 5;

int main()
{
	srand(time(nullptr));

	int a[N];   // ���z��̐錾
	for (int i = 0; i < N; i++) {
		a[i] = rand() % 100;  // ���z��̗v�f�ɑ��
	}
	for (int i = 0; i < N; i++) {
		printf("a[%d] =%d\n", i, a[i]);  // ���z��̗v�f���擾
	}
	return 0;
}