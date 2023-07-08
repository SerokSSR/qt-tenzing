#pragma once
#include<QString>
#ifndef CONST_H
#define CONST_H

#endif // CONST_H

enum {
    Grass,
    Cigar,
    Elec,
    Jiu,
    Mount,
    Enemy
};

constexpr int Size = 50;
constexpr int N = 12;

const QString dialog[10][2] = {
    {"",""},
    {"你不幸碰触了传统香烟，hp-25",""},
    {"你捡到了芋泥啵啵味烟弹，atk+10&def+10",""},
    {"你捡到了草莓味锐克五，hp+50",""},
    {"然日卡在哪里？\n然日卡……然日卡……回到然日卡……",""},
    {"雪豹闭嘴!"}
    };
