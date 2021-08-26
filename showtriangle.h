#ifndef SHOWTRIANGLE_H
#define SHOWTRIANGLE_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <GL/gl.h>
#include <GL/glu.h>

class ShowTriangle : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    ShowTriangle(QWidget *parent = nullptr);
    //override paint function
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
};

#endif // SHOWTRIANGLE_H
