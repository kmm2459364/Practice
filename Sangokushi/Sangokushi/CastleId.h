#pragma once//======================================
//	三国志  城ID
//======================================
#ifndef __CASTLE_ID_H
#define __CASTLE_ID_H

typedef enum {
    CASTLE_SHIREI,        // 米沢城
    CASTLE_YOSHU,      // 春日山城
    CASTLE_KISHU,  // 躑躅ヶ崎館
    CASTLE_ENSHU,         // 小田原城
    CASTLE_JOSHU,         // 岡崎城
    CASTLE_KEISHU,            // 岐阜城
    CASTLE_YOUSHU,            // 二条城
    CASTLE_EKISHU, // 吉田郡山城
    CASTLE_RYOSHU,             // 岡豊城
    CASTLE_YUSHU,            // 内城
    CASTLE_MAX,             // (種類の数)
    CASTLE_NONE = -1,         // リスト終端
} CastleId;

#endif //  __CASTLE_ID_H
