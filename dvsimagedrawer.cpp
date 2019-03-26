#include "dvsimagedrawer.h"

DVSImageDrawer::DVSImageDrawer()
{
    color=new QColor;
    pen = new QPen;
    color->setRgb(200,100,100);
    pen->setColor(*color);
    image = new QImage(rwidth*scale,rheight*scale,QImage::Format_RGB32);

}

DVSImageDrawer::~DVSImageDrawer()
{

}




void DVSImageDrawer::paintEvent(QPaintEvent * /* event */)
{
    QPainter painter(this);

    color->setRgb(250,0,0);
    pen->setColor(*color);
    painter.setPen(*pen);
painter.drawImage(0,0,*image);
    painter.drawText(10,10,QString::number(packageCount));

}

void DVSImageDrawer::handleResults(long long count)
{
  packageCount=count;
  update();
}

void DVSImageDrawer::handleDVSData()
{

update();


}

QSize DVSImageDrawer::minimumSizeHint() const
{
    return QSize(100, 100);
}

QSize DVSImageDrawer::sizeHint() const
{
    return QSize(640, 480);
}
