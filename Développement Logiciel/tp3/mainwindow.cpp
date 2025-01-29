#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QChart>
#include <QChartView>
#include <QLineSeries>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mainWidget = new QWidget();
    QVBoxLayout* mainLayout = new QVBoxLayout(mainWidget);
    this->setCentralWidget(mainWidget);

    QChart* lineChart = new QChart();
    lineChart->setTitle("1st Semester Grades");
    QLineSeries* lineSerie = new QLineSeries(lineChart);
    lineSerie->append(1,18);
    lineSerie->append(2,16);
    lineSerie->append(3,11);
    lineSerie->append(4,9);
    lineSerie->append(5,13);

    lineChart->addSeries(lineSerie);
    lineChart->createDefaultAxes();

    QChartView* viewChart = new QChartView(lineChart,mainWidget);

    viewChart->setRenderHint(QPainter::Antialiasing,true);
    mainLayout->addWidget(viewChart);



}

MainWindow::~MainWindow()
{
    delete ui;
}
