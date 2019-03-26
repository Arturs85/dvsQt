#include "dvsfilesaver.h"
#include <fstream>

DVSFileSaver::DVSFileSaver()
{
    events.reserve(INITIAL_SIZE);
    intEvents.reserve(INITIAL_SIZE);

}

void DVSFileSaver::addEvent(int32_t ts, uint16_t x, uint16_t y, bool pol)
{

intEvents.push_back(intEvent{ts,x,y,pol});
}

void DVSFileSaver::saveToFile()
{
  convertToStrings();
    std::ofstream out("outputDVS.txt");
    for (int i = 0; i < events.size(); ++i) {
        out << (events[i]).toStdString();
        out<<"\n";
    }

    out.close();
    printf("\n saved to File");
}

void DVSFileSaver::convertToStrings()
{
    for (int i = 0; i < intEvents.size(); ++i) {
        intEvent e = intEvents[i];
        double tsd = e.ts/1000000.0;
           QString res = QString::number(tsd)+" "+QString::number(e.x)+" "+QString::number(e.y)+" "+QString::number(e.pol);
          //if(res.length()>9)
           events.push_back(res);

    }

}
