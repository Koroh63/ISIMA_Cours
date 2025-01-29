#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSystemTrayIcon>




void MainWindow::onConcatClicked(){
    concatText->append(concatLineEdit->text()+ " - "+QString::number(concatSpinBox->value()));
}

void MainWindow::sliderChanged(int value){
    sliderLabel->setText(QString::number(value));
}

void MainWindow::tableChanged(int row,int colum){
    notif->showMessage("New Value","A new value has been added to the table");
    double sum = 0;
    for (int i = 0; i < table->columnCount(); i++) {
        for (int j = 0; j < table->rowCount(); j++) {
            QTableWidgetItem *item = table->item(j, i);
            if (item) {
                bool ok;
                int value = item->text().toInt(&ok);
                if (ok) {
                    sum += value;
                }
            }
        }
    }
    tableLabel->setText(QString::number(sum));
}

void MainWindow::exitMyApp(bool a){
    QMessageBox msgBox;
    msgBox.setText("Are you sure to Exit ?");
    msgBox.setStandardButtons(QMessageBox::Yes |QMessageBox::No);
    int ret = msgBox.exec();
    switch(ret){
    case QMessageBox::No:
        return;
    case QMessageBox::Yes:
        exit(0);
    default:
        return;
    }

    return;
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mainWidget = new QWidget(this);

    QVBoxLayout* verticalLayout = new QVBoxLayout(mainWidget);
    this->setCentralWidget(mainWidget);


        QWidget* concatWidget = new QWidget(mainWidget);
        QVBoxLayout* concatVerticalLayout = new QVBoxLayout(concatWidget);
        verticalLayout->addWidget(concatWidget);


            QWidget* concatInputWidget = new QWidget(concatWidget);
            QHBoxLayout* concatInputHorizontalLayout = new QHBoxLayout(concatInputWidget);
            concatVerticalLayout->addWidget(concatInputWidget);

                concatSpinBox = new QSpinBox(concatInputWidget);
                concatInputHorizontalLayout->addWidget(concatSpinBox);
                concatLineEdit = new QLineEdit(concatInputWidget);
                concatInputHorizontalLayout->addWidget(concatLineEdit);
                concatButton = new QPushButton("Concat",concatInputWidget);
                concatInputHorizontalLayout->addWidget(concatButton);
                connect(concatButton, SIGNAL(clicked()),this, SLOT(onConcatClicked()));

            QWidget* concatOutputWidget = new QWidget(concatWidget);
            QHBoxLayout* concatOutputHorizontalLayout = new QHBoxLayout(concatOutputWidget);
            concatVerticalLayout->addWidget(concatOutputWidget);

                concatText = new QTextEdit(concatOutputWidget);
                concatOutputHorizontalLayout->addWidget(concatText);

        QWidget* sliderWidget = new QWidget(mainWidget);
        QHBoxLayout* sliderHorizontalLayout = new QHBoxLayout(sliderWidget);
        verticalLayout->addWidget(sliderWidget);

            slider = new QSlider(Qt::Horizontal,sliderWidget);
            sliderHorizontalLayout->addWidget(slider);
            sliderLabel = new QLabel(sliderWidget);
            sliderHorizontalLayout->addWidget(sliderLabel);
            connect(slider,SIGNAL(valueChanged(int)),this, SLOT(sliderChanged(int)));

        QWidget* tableWidget = new QWidget(mainWidget);
        QVBoxLayout* tableVerticalLayout =  new QVBoxLayout(tableWidget);
        verticalLayout->addWidget(tableWidget);


            tableLabel = new QLabel(tableWidget);
            tableVerticalLayout->addWidget(tableLabel);
            table = new QTableWidget(10,5,tableWidget);
            tableVerticalLayout->addWidget(table);
            connect(table,SIGNAL(cellChanged(int,int)),this,SLOT(tableChanged(int,int)));

        notif = new QSystemTrayIcon(mainWidget);
        notif->show();


        menuBar = new QMenuBar();
        setMenuBar(menuBar);
        fileMenu = menuBar->addMenu(tr("&File"));
        quitAction = new QAction(tr("&Quit"));
        fileMenu->addAction(quitAction);
        connect(quitAction,SIGNAL(triggered(bool)),this,SLOT(exitMyApp(bool)));




}


MainWindow::~MainWindow()
{
    delete ui;
}
