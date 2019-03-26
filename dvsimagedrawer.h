#ifndef DVSIMAGEDRAWER_H
#define DVSIMAGEDRAWER_H


#include <QWidget>
#include <QBrush>
#include <QPen>
#include <iostream>
#include <QPainter>
#include <QString>
#include <recievingthread.h>
#include <QImage>

using namespace std;

class DVSImageDrawer: public QWidget
{
    Q_OBJECT

public:
    DVSImageDrawer();
    ~DVSImageDrawer();
    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;
    void setData(char* data);
int* corners=0;
QString stringTest="start";
long int packageCount=2;
void handleResults(long long count);
void handleDVSData();
QImage* image;
int scale=3;

protected:
int rwidth=240;
int rheight=240;


char* data=0;
    QPen* pen;
    QBrush brush;
    QColor*  color;
protected:
    void paintEvent(QPaintEvent *event) override;

};






#endif // DVSIMAGEDRAWER_H
