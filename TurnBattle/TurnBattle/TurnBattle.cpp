//======================================
//	ターン制バトル
//======================================
#include "TurnBattle.h"
#include "Utility.h"
#include <stdio.h>  // printf()

// 関数プロトタイプ
static void execCommand(TurnBattle* btl, Command cmd, Character* offense, Character* defense);

// ターンバトル設定
void SetTurnBattle(TurnBattle* btl, Character* player, Character* enemy)
{
	btl->player = player;
	btl->enemy = enemy;
}
// イントロ「～が現れた!!」表示
void IntroTurnBattle(TurnBattle* btl)
{
	DrawBattleScreen(btl);
	printf("%sが現れた!!",GetName(btl->enemy));
	// ★ここで「(敵の名前)が　あらわれた!!」を表示してください
	WaitKey();
}
// バトル開始
void StartTurnBattle(TurnBattle* btl)
{
	btl->turn = 1;
	StartCharacter(btl->player);
	StartCharacter(btl->enemy);
}
// バトル画面を描画
void DrawBattleScreen(TurnBattle* btl)
{
	ClearScreen();
	IndicatePlayer(btl->player);
	putchar('\n');
	IndicateEnemy(btl->enemy);
	putchar('\n');
}
// プレーヤのターン実行
bool ExecPlayerTurn(TurnBattle* btl, Command cmd)
{
	execCommand(btl, cmd, btl->player, btl->enemy);
	if (IsDeadCharacter(btl->enemy)) {
		SetEraseAa(btl->enemy);
		DrawBattleScreen(btl);
		printf("%sをたおした!", GetName(btl->enemy));
		// ★ここで「(敵の名前)を　たおした!」を表示してください
		WaitKey();
		return true;
	}
	return IsEscapeCharacter(btl->player);
}
// 敵のターン実行
bool ExecEnemyTurn(TurnBattle* btl, Command cmd)
{
	execCommand(btl, cmd, btl->enemy, btl->player);
	if (IsDeadCharacter(btl->player)) {
		DrawBattleScreen(btl);
		printf("あなたは　しにました");
		// ★ここで「"あなたは　しにました」を表示してください
		WaitKey();
		return true;
	}
	return false;
}
// コマンド実行(offense:攻撃キャラ defense:防御キャラ)
static void execCommand(TurnBattle* btl, Command cmd, Character* offense, Character* defense)
{
	int dmg;
	switch (cmd) {
	case COMMAND_FIGHT:
		DrawBattleScreen(btl);
		printf("%sの こうげき!",GetName(offense));
		
		// ★ここで「(攻撃側の名前)の　こうげき!」を表示してください
		WaitKey();

		dmg = CalcDamage(offense);
		DamageCharacter(defense, dmg);
		DrawBattleScreen(btl);
		printf("%sに%dの　ダメージ!", GetName(defense),dmg);
		// ★ここで「(防御側の名前)に (ダメージ値)の　ダメージ!」を表示してください
		WaitKey();

		break;
	case COMMAND_SPELL:
		if (CanSpellCharacter(offense) == false) {
			DrawBattleScreen(btl);
			printf("MPが　たりない!");
			// ★ここで「ＭＰが　たりない!」を表示してください
			WaitKey();
			break;
		}
		UseSpellCharacter(offense);
		DrawBattleScreen(btl);
		printf("%sは　ヒールを　となえた!", GetName(btl->player));
		// ★ここで「(攻撃側の名前)は　ヒールを　となえた!」を表示してください
		WaitKey();

		RecoverCharacter(offense);
		DrawBattleScreen(btl);
		printf("%sのきずが　かいふくした!", GetName(btl->player));
		// ★ここで「(攻撃側の名前)のきずが　かいふくした!」を表示してください
		WaitKey();
		break;

	case COMMAND_ESCAPE:
		DrawBattleScreen(btl);
		printf("%sは　にげだした!", GetName(btl->player));
		// ★ここで「(攻撃側の名前)は　にげだした!」を表示してください
		WaitKey();
		SetEscapeCharacter(offense);
		break;
	}
}
// 次のターンへ
void NextTurnBattle(TurnBattle* btl)
{
	btl->turn++;
}