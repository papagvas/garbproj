#ifndef CHART_HPP
#define CHART_HPP

#include <QtCharts/QChart>

class QGestureEvent;


class Chart : public QtCharts::QChart
{
public:
    explicit Chart(QGraphicsItem *parent = 0, Qt::WindowFlags wFlags = 0);
    ~Chart();

protected:
    bool sceneEvent(QEvent *event);

private:
    bool gestureEvent(QGestureEvent *event);

private:

};


#endif // CHART_HPP
