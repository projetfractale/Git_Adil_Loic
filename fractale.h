#ifndef FRACTALE_H
#define FRACTALE_H

#include <QObject>
#include <QWidget>
#include <QPixmap>
#include <QApplication>
#include <QImage>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QPainter>
#include <QPen>
#include <QSlider>
#include <QGraphicsProxyWidget>

class fractale : public QWidget
{
    Q_OBJECT
public:
    explicit fractale(QWidget *parent = 0);
    QPixmap getPixmap();

signals:

public slots:

protected:
    QPixmap m_pixmap;
    static const int m_largeur=1200;
    static const int m_longueur=1200;

};

#endif // FRACTALE_H
