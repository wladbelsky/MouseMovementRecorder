#ifndef MOUSETRACKINGPANEL_H
#define MOUSETRACKINGPANEL_H

#include <QWidget>
#include <QMouseEvent>
#include <QPaintEvent>

class mouseTrackingPanel : public QWidget
{
    Q_OBJECT
public:
    explicit mouseTrackingPanel(QWidget *parent = nullptr);
    void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *pe);


signals:

};

#endif // MOUSETRACKINGPANEL_H
