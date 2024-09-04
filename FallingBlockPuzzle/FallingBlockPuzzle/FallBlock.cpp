//======================================
//      �������o�Y�� �����u���b�N
//======================================
#include "FallBlock.h"
#include "Utility.h"  // GetRand()
#include <stdio.h>

// �����u���b�N�̈ړ�
void MoveFallBlock(FallBlock* fallBlock, int ofsx, int ofsy)
{
	fallBlock->x += ofsx;
	fallBlock->y += ofsy;

	//
	// ���������R�[�f�B���O���Ă�������
	// fallBlock��x���W �� ofsx �𑫂����݂܂�
	// fallBlock��y���W �� ofsy �𑫂����݂܂�
	//
}
// �����u���b�N�̉�]
void RotateFallBlock(FallBlock* fallBlock)
{
	RotateShape(&fallBlock->shape);
	//
	// ���������R�[�f�B���O���Ă�������
	//�@fallBlock��shape �̉�]���Ăяo���܂�
	//
}
// �����_���ȗ����u���b�N���Z�b�g
void SetRandomFallBlock(FallBlock* fallBlock, int x, int y)
{
	int idx = GetRand(blockShapesSize);
	SetShape(&fallBlock->shape, idx);
	int rotateCount = GetRand(4);
	for (int i = 0; i < rotateCount; i++) {
		RotateShape(&fallBlock->shape);
	}
	fallBlock->x = x;
	fallBlock->y = y;
	//
	// ���������R�[�f�B���O���Ă�������
	// (1) 0�`blockShapedSize-1 �̗������擾���āA���̃C���f�b�N�X��fallBlock��shape��SetShape()���܂�
	// (2) 0�`3 �̗������擾���āA���̉� fallBlock��shape����]���܂�
	// (3) x,y �� fallBlock��x,y���W�ɑ�����܂�
	//
}
// �����u���O���v�����g
void PrintFallBlock(FallBlock* fallBlock)
{
	printf("(%d,%d)\n", fallBlock->x, fallBlock->y);
	PrintShape(&fallBlock->shape);
}