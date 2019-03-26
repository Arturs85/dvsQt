#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dvsimagedrawer.h"
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:

    Ui::MainWindow *ui;
DVSImageDrawer* dVSImageDrawer;
RecievingThread *workerThread;
void handleResults(long long count);
void closeEvent(QCloseEvent* event);

};

#endif // MAINWINDOW_H
