#include "chartview.hpp"

#include <QtGui/QMouseEvent>
#include <QToolTip>
#include <QTextStream>

ChartView::ChartView(QWidget *parent) :
    QtCharts::QChartView(parent),
    m_isTouching(false) {
    setRubberBand(QtCharts::QChartView::RectangleRubberBand);
}

bool ChartView::viewportEvent(QEvent *event) {
    if (event->type() == QEvent::TouchBegin) {
        m_isTouching = true;
        chart()->setAnimationOptions(QtCharts::QChart::NoAnimation);
    }
    return QtCharts::QChartView::viewportEvent(event);
}

void ChartView::mousePressEvent(QMouseEvent *event) {
    if (m_isTouching)
        return;
    QtCharts::QChartView::mousePressEvent(event);
}

void ChartView::mouseMoveEvent(QMouseEvent *event) {
    if (m_isTouching)
        return;
    QtCharts::QChartView::mouseMoveEvent(event);
}

void ChartView::mouseReleaseEvent(QMouseEvent *event) {
    if (m_isTouching)
        m_isTouching = false;
    chart()->setAnimationOptions(QtCharts::QChart::SeriesAnimations);

    QtCharts::QChartView::mouseReleaseEvent(event);
}

void ChartView::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_Left:
        chart()->scroll(-10, 0);
        break;
    case Qt::Key_Right:
        chart()->scroll(10, 0);
        break;
    case Qt::Key_Up:
        chart()->scroll(0, 10);
        break;
    case Qt::Key_Down:
        chart()->scroll(0, -10);
        break;
    case Qt::Key_Space:
        chart()->zoomReset();
        break;
    default:
        QGraphicsView::keyPressEvent(event);
        break;
    }
}

QPointF ChartView::point_to_chart(const QPoint &pnt) {
    QPointF scene_point = mapToScene(pnt);
    QPointF chart_point = chart()->mapToValue(scene_point);
    return chart_point;
}

QPoint ChartView::chart_to_view_point(QPointF char_coord)
{
    QPointF scene_point = chart()->mapToPosition(char_coord);
    QPoint view_point = mapFromScene(scene_point);

    return view_point;
}
bool ChartView::event(QEvent *event) {
    if (event->type() == QEvent::ToolTip) {
        QHelpEvent *helpEvent = static_cast<QHelpEvent*>(event);
        if (chart()->contains(point_to_chart(helpEvent->pos()))) {
            QString str;
            QTextStream(&str) << "(" << point_to_chart(helpEvent->pos()).x() << ", " << point_to_chart(helpEvent->pos()).y() << ")";
            QToolTip::showText(chart_to_view_point(point_to_chart(helpEvent->pos())),str);
        } else {
              QToolTip::hideText();
              event->ignore();
        }
        return true;
    }
    return QtCharts::QChartView::event(event);
}
