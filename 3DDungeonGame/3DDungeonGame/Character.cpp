//====================================
//	3D�_���W����  �L�����N�^
//======================================
#include "Character.h"
#include "Direction.h"
#include "Vector2.h"

// ������
void InitCharacter(Character* ch, Vector2 pos, Direction dir)
{
	ch->pos = pos;
	ch->dir = dir;
}
//�@��������
void TurnBackCharacter(Character* ch)
{
	// �k������A��������
	ch->dir = DirectionAdd(ch->dir, 2);
	// ���������R�[�f�B���O���Ă�������
	// DirectionAdd()���Ăт܂�
}
// ��������
void TurnLeftCharacter(Character* ch)
{
	// �k�������쁨��
	ch->dir = DirectionAdd(ch->dir, 1);
	// ���������R�[�f�B���O���Ă�������
	// DirectionAdd()���Ăт܂�
}
// �E������
void TurnRightCharacter(Character* ch)
{
	// �k�������쁨��
	ch->dir = DirectionAdd(ch->dir, -1);
	// ���������R�[�f�B���O���Ă�������
	// DirectionAdd()���Ăт܂�
}