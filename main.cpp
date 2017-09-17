#include "newson.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Newson w;
    w.show();

    return a.exec();
}
