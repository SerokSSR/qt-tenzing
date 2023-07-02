#include "gamemap.h"
#include <cstdlib>

GameMap::GameMap(QObject *parent)
    : QObject{parent}
{
    mRow = 20;
    mCol = 20;

    InitByRand();
    //("://map/map.txt");
}

void GameMap::Paint(QPainter* _p, QPoint _Pos) {
    for(int i=0; i<mRow; i++) {
        for(int j=0; j<mCol; j++) {

            QString imgUrl= ":/image/chien-pao.png";
            if(mPArr[i][j] > 3) continue;
            switch(mPArr[i][j]) {
            case Grass:
                continue;
            case Cigar:
                imgUrl = ":/image/1305.jpg"; break;
            case Elec:
                imgUrl = ":/image/1305.jpg"; break;
            case Jiu:
                imgUrl = ":/image/1305.jpg"; break;
            }
            QImage img(imgUrl);
            _p->drawImage(QRect(_Pos.x() + j*20, _Pos.y() + i*20, 20, 20), img);
        }

    }
    _p->drawImage(QRect(20, 300, 200, 100), QImage(":/image/title.png"));
}

void GameMap::PaintDialog(QPainter* _p, QPoint _Pos) {
    for(int i=0; i<mRow; i++) {
        for(int j=0; j<mCol; j++) {

            QString imgUrl= ":/image/chien-pao.png";
            if(mPArr[i][j] > 3) continue;
            switch(mPArr[i][j]) {
            case Grass:
                continue;
            case Cigar:
                imgUrl = ":/image/1305.jpg"; break;
            case Elec:
                imgUrl = ":/image/1305.jpg"; break;
            case Jiu:
                imgUrl = ":/image/1305.jpg"; break;
            }
            QImage img(imgUrl);
            _p->drawImage(QRect(_Pos.x() + j*20, _Pos.y() + i*20, 20, 20), img);
        }

    }
}

void GameMap::InitByFile(QString fileName) {

}

void GameMap::InitByRand() {
    srand(time(NULL));
    for(int i=0; i<mRow; ++i) {
        for(int j=0; j<mCol; ++j) {
            mPArr[i][j] = rand() % 100;
            if(mPArr[i][j] > 3) mPArr[i][j] = 0;
        }
    }
    mPArr[0][0] = 0;
}
