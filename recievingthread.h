#ifndef RECIEVINGTHREAD_H
#define RECIEVINGTHREAD_H
#include <QThread>
#include <libcaercpp/devices/davis.hpp>
#include <atomic>
#include <csignal>
#include "dvsimagedrawer.h"
#include "dvsfilesaver.h"
class DVSImageDrawer;
//class DVSFileSaver;

using namespace std;

static atomic_bool globalShutdown(false);


class RecievingThread : public QThread
{
public:
    RecievingThread(DVSImageDrawer* dvsImageDrawer);
    ~RecievingThread();
 volatile bool isThreadRunning = true;
 long long zeroEventsCount =0;
 //static atomic_bool globalShutdown(false);

   // static void globalShutdownSignalHandler(int signal);

    //static void usbShutdownHandler(void *ptr) ;
DVSImageDrawer *dvsImageDrawer;
DVSFileSaver *dvsFileSaver;

Q_OBJECT
     void run();
private:
     long long receivedUsbPackageCount=0;
signals:
    void resultReady(long long count);
    void dvsDatatReady();
public slots:
    void stopAndSave();

};


#endif // RECIEVINGTHREAD_H
