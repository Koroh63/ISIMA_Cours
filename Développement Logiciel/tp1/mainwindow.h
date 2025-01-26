#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSpinBox>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QSlider>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QWidget* mainWidget;

    QSpinBox* concatSpinBox;
    QLineEdit* concatLineEdit;
    QPushButton* concatButton;
    QTextEdit* concatText;

    QSlider* slider;
    QLabel* label;

private slots:
    void onConcatClicked();
    void sliderChanged(int value);
};
#endif // MAINWINDOW_H
