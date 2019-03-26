#ifndef DVSFILESAVER_H
#define DVSFILESAVER_H

#include <vector>
#include <QString>
using namespace std;
struct intEvent{int32_t ts; uint16_t x; uint16_t y;bool pol;};

class DVSFileSaver
{
public:
    DVSFileSaver();

vector<intEvent> intEvents;
vector<QString> events;

int INITIAL_SIZE = 2000000;
void addEvent(int32_t ts, uint16_t x, uint16_t y,bool pol);
void saveToFile();
void convertToStrings();

};

#endif // DVSFILESAVER_H
