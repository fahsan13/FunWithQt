#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSignalMapper>
#include <QDebug>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QLabel>
#include <QPushButton>
#include <QSystemTrayIcon>
#include <QString>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(const int &NUM_BUTTONS, QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void generateButtons(const int &NUM_BUTTONS);

    QSignalMapper *signalMapper;  // Used to bundle multiple signals to pass to a single slot

private slots:
    void handleButtons(const QString &buttonText);
};

#endif // MAINWINDOW_H
