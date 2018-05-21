#include "messagebox.h"

MessageBox::MessageBox()
{

}

void MessageBox::showMessage(double nn[K], int t[K], int result)
{
    QString status = QString("Classified as: %1\n\n"
                             "distance: %2\n"
                             "value: %3\n"
                             "distance: %4\n"
                             "value: %5\n"
                             "distance: %6\n"
                             "value: %7").arg(result).arg(nn[0]).arg(t[0]).arg(nn[1]).arg(t[1]).arg(nn[2]).arg(t[2]);

    msgBox.setText(status);

    msgBox.exec();
}
