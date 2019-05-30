#ifndef CHARTVIEW_HPP
#define CHARTVIEW_HPP

#include <QMainWindow>
#include <QtCharts/QChartView>
#include <QtWidgets/QRubberBand>

class ChartView : public QtCharts::QChartView
{
public:
    ChartView(QWidget *parent = 0);
    QPointF point_to_chart(const QPoint&);
    QPoint chart_to_view_point(QPointF char_coord);

protected:
    bool viewportEvent(QEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    bool event(QEvent *event) override;

private:
    bool m_isTouching;
};




#endif // CHARTVIEW_HPP
