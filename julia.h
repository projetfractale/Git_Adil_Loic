#ifndef JULIA_H
#define JULIA_H

#include "fractale.h"
#include <QSlider>
#include <QLCDNumber>

class julia : public fractale
{
    Q_OBJECT

    public:
        julia(double reel,double im);
        ~julia();
        void colorieJulia();
        QSlider* getSliderH();
        QSlider* getSliderV();
        QLCDNumber* getboxH();
        QLCDNumber* getboxV();

    signals:

    public slots:
        void changerCompteurH(int horiz);
        void changerCompteurV(int vertic);

    protected:
        double c_real;
        double c_im;
        QSlider *sliderH;
        QSlider *sliderV;
        QLCDNumber *BoxH;
        QLCDNumber *BoxV;
};

#endif // JULIA_H
