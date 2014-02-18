#include "mandelbrot.h"

mandelbrot::mandelbrot() : fractale()
{
}

void mandelbrot::colorieMandelbrot()
{

    QPainter *p_fractale = new QPainter(&m_pixmap);
    //le compteur est initialisé à 0. Il va servir à l'it_max
    for (int i=-600;i<=600;i++)  //on commence par un carré
    {
        for (int j=-600;j<=600;j++)
        {
            int iteration_max = 100;
            double x=0;
            double y=0;
            double a=0;
            int h=0;
            while (h<iteration_max && x*x+y*y<4)
            {
                a=x;
                x=x*x-y*y+((double)i)/300;
                y=2*a*y+((double)j)/300;
                h++;
            }
            if (h==iteration_max)
            {
                p_fractale->setPen(QPen(Qt::black));
                p_fractale->drawPoint(i+600,j+600);
            }
            if (1<=h && h<15)
            {
                p_fractale->setPen(QPen(Qt::darkBlue));
                p_fractale->drawPoint(i+600,j+600);
            }
            if (15<=h && h<30)
            {
                p_fractale->setPen(QPen(Qt::blue));
                p_fractale->drawPoint(i+600,j+600);
            }
            if (30<=h && h<45)
            {
                p_fractale->setPen(QPen(Qt::darkCyan));
                p_fractale->drawPoint(i+600,j+600);
            }
            if (45<=h && h<iteration_max)
            {
                p_fractale->setPen(QPen(Qt::cyan));
                p_fractale->drawPoint(i+600,j+600);
            }
        }
    }
    delete p_fractale;
}
