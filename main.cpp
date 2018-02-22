#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {

    /* This is where we'd first use a database
     * connector class to retrieve data to pass into
     * MainWindow. NUM_BUTTONS is used to demonstrate
     * how to generate UI elements based on such data.
     * */

    const int NUM_BUTTONS = 50;
    QApplication a(argc, argv);
    MainWindow w(NUM_BUTTONS);
    w.show();

    return a.exec();
}
