#include "mainwindow.hpp"
#include <QApplication>
#include "chart.hpp"
#include "chartview.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    MainWindow k;
    k.grabGesture(Qt::PanGesture);
    k.grabGesture(Qt::PinchGesture);
    k.show();
    return app.exec();
}
