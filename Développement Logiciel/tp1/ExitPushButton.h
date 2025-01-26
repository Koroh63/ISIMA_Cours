#ifndef EXITPUSHBUTTON_H
#define EXITPUSHBUTTON_H

#include <QPushButton>

class ExitPushButton : public QPushButton{
    Q_OBJECT

private:
    QWidget *parent;

public:
    ExitPushButton(const QString &text, QWidget *parent = nullptr);

    public slots:
        void clickFonction();
};

#endif // EXITPUSHBUTTON_H
