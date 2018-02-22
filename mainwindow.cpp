#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(const int &NUM_BUTTONS, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {

    ui->setupUi(this);
    this->setWindowTitle("Generating Buttons in a Scrollable Widget");
    generateButtons(NUM_BUTTONS);
}

MainWindow::~MainWindow() {
    delete ui;
}

/* Generate buttons based on data passed into method. In practice,
 * you'd probably pass in a vector of all objects retrieved
 * from a database then generate buttons based on vector size.
 * */
void MainWindow::generateButtons(const int &NUM_BUTTONS) {

    QVBoxLayout *vBox = new QVBoxLayout(ui->centralWidget);
    QWidget *central = new QWidget;
    QVBoxLayout *vLayout = new QVBoxLayout(central);
    QScrollArea *scroll = new QScrollArea;

    scroll->setWidget(central);
    scroll->setWidgetResizable(true);
    vBox->addWidget(scroll);

    signalMapper = new QSignalMapper(this);

    if (NUM_BUTTONS > 0) {
        for (int i = 0; i < NUM_BUTTONS; i++) {
            QWidget *wdg = new QWidget(this);
            QPushButton *itemButton = new QPushButton(wdg);
            itemButton->setText(tr("Button %1").arg(i+1)); // Add 1 as names not 0 indexed
            vLayout->addWidget(itemButton);

            /* Connect 'clicked' signal from button to signalMapper object
             * then map each button to its display text. Will be passed
             * into handler method.
             * */

            connect(itemButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
            signalMapper->setMapping(itemButton, itemButton->text());
        }

        // Connect the signalMapper to the handler method
        connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(handleButtons(QString)));
    } else {
       QLabel *l = new QLabel("No items found!");
       l->setAlignment(Qt::AlignCenter);
       vLayout->addWidget(l);
    }
}

// Handler for button presses. Does nothing special!
void MainWindow::handleButtons(const QString &buttonText) {

      qDebug() << "Pressed button: " << buttonText;

      // Uncomment to display message as system notification
//    QString messageText = QString("%1 clicked").arg(buttonText);
//    QSystemTrayIcon *notification = new QSystemTrayIcon;
//    notification->show();
//    notification->showMessage("Demo", messageText, QSystemTrayIcon::Information, 2000);
}
