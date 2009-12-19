#include <QtGui/QApplication>
#include "qwebdev.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWebDev w;
    w.show();
	w.resize(640, 480);
    return a.exec();
}
