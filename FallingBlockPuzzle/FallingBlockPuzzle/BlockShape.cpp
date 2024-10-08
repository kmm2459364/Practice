//======================================
//      落ち物バズル ブロック形状
//======================================
#include "BlockShape.h"
#include <stdio.h>
// 関数プロトタイプ
static bool isInShapePattern(int x, int y);

// 形状テーブル
const BlockShape blockShapes[] = {
	{   // I字型
		3,
		{
			{0,1,0},
			{0,1,0},
			{0,1,0},
		}
	},
	{   // L字型
		3,
		{
			{0,1,0},
			{0,1,1},
			{0,0,0},
		}
	},
};
const int blockShapesSize = sizeof(blockShapes) / sizeof(blockShapes[0]);
// 形状をセットする
void SetShape(BlockShape* shape, int idx)
{
	if (0 <= idx && idx < blockShapesSize) {
		*shape = blockShapes[idx];
	}
}
// 形状を回転する
void RotateShape(BlockShape* shape)
{
	// 時計回り
	//  x         X=size-1-y
	// +-----+    +-----+
	//y|0,1,2|    |6,3,0|Y=x
	// |3,4,5| => |7,4,1|
	// |6,7,8|    |8.5.2|
	// +-----+    +-----+
	//　★反時計回り
	//  x         X=y
	// +-----+    +-----+
	//y|0,1,2|    |2,5,8|Y=size-1-x
	// |3,4,5| => |1,4,7|
	// |6,7,8|    |0.3.6|
	// +-----+    +-----+
	//
	BlockShape work = *shape;
	for (int y = 0; y < shape->size; y++) {
		for (int x = 0; x < shape->size; x++) {
			bool f = GetShapePattern(&work, x, y);
			SetShapePattern(shape, y, shape->size - 1 - x, f);
		}
	}
	// ★ここをコーディングしてください
	// shapeを走査します(x,y)
	// 反時計回りの回転 workの(x,y)を shapeの(y,size-1-x)へコピーします
	//
}
// 指定位置のパターンセット
void SetShapePattern(BlockShape* shape, int x, int y, bool value)
{
	if (isInShapePattern(x, y)) {
		shape->pattern[y][x] = value;
	}
	//
	// ★ここをコーディングしてください
	// isInShapePattern()を確認して、shapeのpqtternの(x,y)へvalueを書き込みます
	// isInShapePattern()外なら、なにもしません
	//
}
// 指定位置のパターン取得
bool GetShapePattern(BlockShape* shape, int x, int y)
{
	if (isInShapePattern(x, y)) {
		shape->pattern[y][x];
	}
	return false;
	//
	// ★ここをコーディングしてください
	// isInShapePattern()を確認して、shapeのpqtternの(x,y)の値を返します
	// isInShapePattern()外なら、falseを返します
	//
}
// 座標がパターン内か?
static bool isInShapePattern(int x, int y)
{
	return 0 <= x && x < SHAPE_WID_MAX
		&& 0 <= y && y < SHAPE_HEI_MAX;
}

void PrintShape(BlockShape* shape)
{
	for (int y = 0; y < shape->size; y++) {
		for (int x = 0; x < shape->size; x++) {
			printf("%s", GetShapePattern(shape, x, y) ? "◇" : "・");
		}
		putchar('\n');
	}
}