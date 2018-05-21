#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <QMessageBox>

#define K 3
class MessageBox
{
public:
    MessageBox();
    void showMessage(double nn[K],int t[K],int result);
private:
    QMessageBox msgBox;
};

#endif // MESSAGEBOX_H
