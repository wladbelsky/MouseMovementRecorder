#include "mousetrackingpanel.h"
#include "mainwindow.h"

#include <QMouseEvent>
#include <QPaintEvent>
#include <QStyleOption>
#include <QPainter>

mouseTrackingPanel::mouseTrackingPanel(QWidget *parent) : QWidget(parent)
{
    setMouseTracking(true);
}

void mouseTrackingPanel::mouseMoveEvent(QMouseEvent *event)
{
    MainWindow* main = (MainWindow*) window();
    main->mouseInfoUpdate(*event);
}

void mouseTrackingPanel::paintEvent(QPaintEvent *pe)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
};
