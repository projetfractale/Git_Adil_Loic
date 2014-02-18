#include "julia.h"

julia::julia(double reel,double im) : fractale()
{
    c_real = reel;
    c_im = im;
    QSlider *sliderV = new QSlider(Qt::Vertical,this);
    QSlider *sliderH = new QSlider(Qt::Horizontal,this);

    sliderH->setRange(0,1200);

    sliderV->setRange(0,1200);

    QLCDNumber *BoxH = new QLCDNumber(3,this);
    QLCDNumber *BoxV = new QLCDNumber(3,this);

    BoxH->display(-2);
    BoxV->display(2);

    QObject::connect(sliderH,SIGNAL(valueChanged(int)),this,SLOT(changerCompteurH(int)));
    QObject::connect(sliderV,SIGNAL(valueChanged(int)),this,SLOT(changerCompteurV(int)));
}

julia::~julia()
{
    delete BoxH;
    delete BoxV;
    delete sliderH;
    delete sliderV;
}

void julia::colorieJulia()
{
    QPainter *p_fractale_2 = new QPainter(&m_pixmap);
    double x_julia = c_real;
    double y_julia = c_im;
    int iteration_max = 100;
    for (int i=-600; i<=600; i++)
    {
        for (int j=-600; j<=600; j++)
        {
            int dummy=0;
            double x = ((double)i)/300;
            double y = ((double)j)/300;
            double a=0;
            int h=0;
            if (x*x+y*y>=4)
            {
                dummy=1;
            }
            else
            {
                while (h<iteration_max && x*x+y*y<4)
                {
                    a=x;
                    x=x*x -y*y + x_julia;
                    y=2*a*y + y_julia;
                    h=h+1;
                }
                if (h==iteration_max)
                {
                    p_fractale_2->setPen(QPen(Qt::black));
                    p_fractale_2->drawPoint(i+600,j+600);
                }
                if (1<=h && h<15)
                {
                    p_fractale_2->setPen(QPen(Qt::darkBlue));
                    p_fractale_2->drawPoint(i+600,j+600);
                }
                if (15<=h && h<30)
                {
                    p_fractale_2->setPen(QPen(Qt::blue));
                    p_fractale_2->drawPoint(i+600,j+600);
                }
                if (30<=h && h<45)
                {
                    p_fractale_2->setPen(QPen(Qt::darkCyan));
                    p_fractale_2->drawPoint(i+600,j+600);
                }
                if (45<=h && h<iteration_max)
                {
                    p_fractale_2->setPen(QPen(Qt::cyan));
                    p_fractale_2->drawPoint(i+600,j+600);
                }

            }
        }
    }
    delete p_fractale_2;
}

void julia::changerCompteurH(int horiz)
{
    double horiz_help = ((double)horiz/300)-2;
    BoxH->display(horiz_help);
}

void julia::changerCompteurV(int vertic)
{
    double vertic_help = 2-((double)vertic/300);
    BoxV->display(vertic_help);
}

QSlider* julia::getSliderH()
{
    return sliderH;
}

QSlider* julia::getSliderV()
{
    return sliderV;
}
QLCDNumber* julia::getboxH()
{
    return BoxH;
}

QLCDNumber* julia::getboxV()
{
    return BoxV;
}

