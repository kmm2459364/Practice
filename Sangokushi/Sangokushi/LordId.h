#pragma once//======================================
//	三国志  城主ID
//======================================
#ifndef __LORD_ID_H
#define __LORD_ID_H

typedef enum {
    LORD_RIKAKU,      // 
    LORD_RYUBI,    // 上杉謙信
    LORD_ENSHO,    // 武田信玄
    LORD_SOSO,      // 北条氏政
    LORD_RYOFU,  // 徳川家康
    LORD_RYUHYO,       // 織田信長
    LORD_SONSAKU,  // 足利義昭
    LORD_RYUSHO,      // 毛利元就
    LORD_BATO, // 長宗我部元親
    LORD_KOSONSAN,    // 島津義久
    LORD_MAX,       // (種類の数)
    LORD_NONE = -1,
} LordId;

#endif //  __LORD_ID_H
