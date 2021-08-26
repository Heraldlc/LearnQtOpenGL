#include "showtriangle.h"

#include <QPainter>
#include <QPen>


ShowTriangle::ShowTriangle(QWidget *parent)
    :QOpenGLWidget(parent)
{

}

//----------override funtion----------
//
//------------------------------------
void ShowTriangle::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
}

void ShowTriangle::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (float)w/h, 0.01, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);

}

void ShowTriangle::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-0.5, -0.5, 0);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f( 0.5, -0.5, 0);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f( 0.0,  0.5, 0);
    glEnd();

    // render text in widget
    glDisable(GL_DEPTH_TEST);
    QPainter painter;
    painter.begin(this);
    QPen pen;
    pen.setColor(Qt::red);
    painter.setPen(pen);
    painter.drawText(100, 100, "Hello Triangle");
    painter.end();
    glEnable(GL_DEPTH_TEST);




}
