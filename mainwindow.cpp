#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "recievingthread.h"
#include "QToolButton"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QToolBar* tb = new QToolBar();
    QToolButton* saveButton = new QToolButton();
    saveButton->setText(QString("Stop and save"));
    tb->addWidget(saveButton);
    addToolBar(tb);



    dVSImageDrawer= new DVSImageDrawer();

    workerThread = new RecievingThread(dVSImageDrawer);
       connect(workerThread, &RecievingThread::dvsDatatReady, dVSImageDrawer, &DVSImageDrawer::handleDVSData);
       connect(workerThread, &RecievingThread::finished, workerThread, &QObject::deleteLater);
       connect(saveButton, SIGNAL(clicked(bool)), workerThread, SLOT(stopAndSave()));

       workerThread->start();

       dVSImageDrawer->show();

}

MainWindow::~MainWindow()
{
    workerThread->isThreadRunning=false;
    delete ui;

}

void MainWindow::handleResults(long long count)
{
   // dVSImageDrawer->packageCount++;

  //  dVSImageDrawer->packageCount = count;
//dVSImageDrawer->update();
    //printf("\n pkg :%d",10 );
}

void MainWindow::closeEvent(QCloseEvent *event)
{
   workerThread->isThreadRunning=false;

}
