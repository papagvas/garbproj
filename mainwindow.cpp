#include "ui_mainwindow.h"
#include "mainwindow.hpp"
#include <QPainter>
#include "chart.hpp"
#include "chartview.hpp"
#include <boost-1_68/boost/math/special_functions/zeta.hpp>
#include <boost/math/special_functions/bernoulli.hpp>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton_3_clicked()
{
    QtCharts::QSplineSeries* series_1 = new QtCharts::QSplineSeries[116];
    int i = -20;
    while (i <= 0) {
        series_1->append(i,boost::math::zeta(i));
        ++i;
    }
    QPen pen(0x059605);
    pen.setWidth(3);
    series_1->setPen(pen);
    long double k = 0.05;
    while (k < 1) {
        series_1->append(k,boost::math::zeta<long double>(k));
        k+=0.01;
    }
    Chart *chart = new Chart();
    chart->legend()->hide();
    chart->addSeries(series_1);
    chart->setTitle("Riemann Zeta Function");
    QtCharts::QSplineSeries* series_2 = new QtCharts::QSplineSeries[109];
    series_2->setPen(pen);
    long double j = 1.000001;
    while (j < 11) {
        if (j < 2) {
            j+=0.01;
            series_2->append(j,boost::math::zeta(j));
        } else {
            series_2->append(j,boost::math::zeta(j));
            j++;
        }
    }
    chart->addSeries(series_2);
    chart->createDefaultAxes();
    chart->axisY()->setRange(-20, 40);
    chart->axisX()->setRange(-20,10);
    ui->chartview->setChart(chart);
}

void MainWindow::on_pushButton_2_clicked() {
    QtCharts::QScatterSeries *series0 = new QtCharts::QScatterSeries[11];
    for(int i = 0;i < 11;++i) {
        if(i % 2 == 0)
            series0->append(i,boost::math::bernoulli_b2n<long double>(i/2));
        else if (i == 1)
            series0->append(i,0.5);
        else
            series0->append(i,0);
    }
    series0->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    series0->setMarkerSize(12.0);
    ui->chartview->chart()->addSeries(series0);
    ui->chartview->chart()->createDefaultAxes();
    ui->chartview->chart()->axisX()->setRange(-20,10);
    ui->chartview->chart()->axisY()->setRange(-20,40);
}

