#include "mainwindow.h"
#include "showtriangle.h"  // this file used for showing a simple colorful triangle

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    ShowTriangle st;
    st.show();
    return a.exec();
}
