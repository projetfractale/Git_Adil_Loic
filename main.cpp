#include <QApplication>
#include <QImage>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QPixmap>
#include <QPainter>
#include <QPen>

#include "fractale.h"
#include "mandelbrot.h"
#include "buddha.h"
#include "julia.h"

int main(int argc,char *argv[])
{
    QApplication app(argc,argv);

    QGraphicsScene scene;

    mandelbrot essai;
    essai.colorieMandelbrot();
    scene.addPixmap(essai.getPixmap());

    //scene.addWidget(essai.getboxH());

    QGraphicsView view(&scene);
    view.show();

    return app.exec();
}
