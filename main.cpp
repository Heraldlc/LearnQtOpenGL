#include "mainwindow.h"
#include "showtriangle.h"  // this file used for showing a simple colorful triangle
#include "drawxyzwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    ShowTriangle st;
//    st.show();
    DrawXYZWidget drawXYW;
    drawXYW.show();


    return a.exec();
}
