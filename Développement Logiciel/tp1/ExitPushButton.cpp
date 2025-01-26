#include "ExitPushButton.h"
#include <QMessageBox>

ExitPushButton::ExitPushButton(const QString &text, QWidget *parent) : QPushButton(text,parent){
    connect(this,SIGNAL(clicked()),this,SLOT(clickFonction()));
    this->parent = parent;
}

void ExitPushButton::clickFonction()
{
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
