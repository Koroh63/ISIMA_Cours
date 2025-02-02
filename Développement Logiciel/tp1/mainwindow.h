#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSpinBox>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QSlider>
#include <QLabel>
#include <QTableWidget>
#include <QSystemTrayIcon>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QMessageBox>

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

    QMenuBar* menuBar;
    QMenu* fileMenu;
    QAction* quitAction;

    QSpinBox* concatSpinBox;
    QLineEdit* concatLineEdit;
    QPushButton* concatButton;
    QTextEdit* concatText;

    QSlider* slider;
    QLabel* sliderLabel;

    QTableWidget* table;
    QLabel* tableLabel;

    QSystemTrayIcon* notif;

private slots:
    void onConcatClicked();
    void sliderChanged(int value);
    void tableChanged(int row,int column);
    void exitMyApp(bool a);
};
#endif // MAINWINDOW_H
