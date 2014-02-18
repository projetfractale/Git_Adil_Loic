#include "fractale.h"

fractale::fractale(QWidget *parent) : QWidget(parent), m_pixmap(1200,1200)
{
    m_pixmap.fill(Qt::white);
}

QPixmap fractale::getPixmap()
{
    return m_pixmap;
}
