#include "patterns.h"
#include <QDebug>
#include <QtMath>

//Static patterns

void Patterns::square(int num_of_steps){

        QPoint point = QCursor::pos();
        int offsetx = point.x() + num_of_steps;
        int offsety = point.y() + num_of_steps;

        for(int i = point.x(); i < offsetx; i+=30){
            QCursor::setPos(i,point.y());
            QThread::usleep(100);

        }
        point = QCursor::pos();
        offsety = point.y() + num_of_steps;
        for(int i = point.y(); i < offsety; i+=30){
            QCursor::setPos(point.x(),i);
            QThread::usleep(100);
        }

        point = QCursor::pos();
        offsetx = point.x() - num_of_steps;
        for(int i = point.x(); i > offsetx; i-=30){
            QCursor::setPos(i,point.y());
            QThread::usleep(100);
        }

        point = QCursor::pos();
        offsety = point.y() - num_of_steps;

        for(int i = point.y(); i > offsety; i-=30){
            QCursor::setPos(point.x(),i);
            QThread::usleep(100);
        }


}

void Patterns::leftRight(int num_of_steps){

    QPoint point = QCursor::pos();
    int offsetx = point.x() + num_of_steps;
    int offsety = point.y() + num_of_steps;

    for(int i = point.x(); i < offsetx; i+=30){
        QCursor::setPos(i,point.y());
        QThread::usleep(100);
    }

    point = QCursor::pos();
    offsetx = point.x() - num_of_steps;
    for(int i = point.x(); i > offsetx; i-=30){
        QCursor::setPos(i,point.y());
        QThread::usleep(100);
    }

}

void Patterns::circle(int num_of_steps){
    QPoint point = QCursor::pos();

    for(double an = 0; an<2*M_PI; an+=0.2){
        double x = qCos(an) * num_of_steps;
        double y = qSin(an) * num_of_steps;

        x+=(point.x() - num_of_steps);
        y+=(point.y());

        QCursor::setPos((int)x, (int)y);
        QThread::usleep(100);
    }

    QCursor::setPos(point);


}
