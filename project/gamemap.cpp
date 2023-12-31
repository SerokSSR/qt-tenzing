#include "gamemap.h"
#include <cstdlib>

GameMap::GameMap(QObject *parent)
    : QObject{parent}
{
    mRow = N;
    mCol = N;

    curRow = 0;
    curCol = 0;

    InitByRand();
    //InitByFile("://map/map.txt");
}

void GameMap::Paint(QPainter* _p, QPoint _Pos) {
    for(int i=0; i<mRow; i++) {
        for(int j=0; j<mCol; j++) {
            QString imgUrl = ":/image/default.png";
            //QString imgUrl;
            switch(mPArr[i][j]) {
            case Grass:
                continue;
            case Cigar:
                imgUrl = ":/image/cigar.png"; break;
            case Elec:
                imgUrl = ":/image/elec.png"; break;
            case Jiu:
                imgUrl = ":/image/smoke.png"; break;
            case Mount:
                imgUrl = ":/image/ironbundle.png"; break;
            case Enemy:
                imgUrl = ":/image/Fluttermane.png"; break;
            }

            if(imgUrl == ":/image/default.png") {
                qDebug("error: %d\n", mPArr[i][j]);
            }
            QImage img(imgUrl);
            _p->drawImage(QRect(_Pos.x() + j*Size, _Pos.y() + i*Size, Size, Size), img);
        }
    }
    //_p->drawImage(QRect(600, 20, 200, 100), QImage(":/image/title.png"));
}

//void GameMap::InitByFile(QString fileName) {

//}

void GameMap::InitByRand() {
    srand(time(NULL));
    for(int i=0; i<mRow; ++i) {
        for(int j=0; j<mCol; ++j) {
            mPArr[i][j] = rand() % 15;
            if(mPArr[i][j] > 3) mPArr[i][j] = 0;
        }
    }
    mPArr[rand()%mRow][rand()%mCol]=4;
    int tx=rand()%mRow,ty=rand()%mCol;
    while(mPArr[tx][ty]==4){
        tx=rand()%mRow,ty=rand()%mCol;
    }
    mPArr[tx][ty]=5;
    mPArr[0][0] = 0;
}
