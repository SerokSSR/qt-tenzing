#pragma once

#ifndef CONST_H
#define CONST_H

#endif // CONST_H

enum {
    Grass,
    Cigar,
    Elec,
    Jiu,
    Mount,
};

constexpr int Size = 50;
constexpr int N = 12;

constexpr int Inix = 40, Iniy = 40;

const QString dialog[10][2] = {
    {"",""},
    {"你不幸碰触了传统香烟，生命值-5",""},
    {"你捡到了芋泥啵啵味烟弹，攻击力+10",""},
    {"然日卡在哪里？\n然日卡……然日卡……回到然日卡……",""},
    {"远处的雪山……",""},
    };
