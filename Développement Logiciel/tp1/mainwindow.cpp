#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "ExitPushButton.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableWidget>




void MainWindow::onConcatClicked(){
    concatText->append(concatLineEdit->text()+ " - "+QString::number(concatSpinBox->value()));
}

void MainWindow::sliderChanged(int value){
    label->setText(QString::number(value));
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

            slider = new QSlider(sliderWidget);
            sliderHorizontalLayout->addWidget(slider);
            label = new QLabel(sliderWidget);
            sliderHorizontalLayout->addWidget(label);
            connect(slider,SIGNAL(valueChanged(int)),this, SLOT(sliderChanged(int)));

        QWidget* tableWidget = new QWidget(mainWidget);
            QVBoxLayout* tableVerticalLayout =  new QVBoxLayout();






        ExitPushButton* button = new ExitPushButton("exit",parent);
        verticalLayout->addWidget(button);
        QTableWidget* tab = new QTableWidget(this);
        verticalLayout->addWidget(tab);
}


MainWindow::~MainWindow()
{
    delete ui;
}
