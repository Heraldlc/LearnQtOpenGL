#ifndef DRAWXYZWIDGET_H
#define DRAWXYZWIDGET_H

#include <QOpenGLWidget>
#include <GL/gl.h>
#include <GL/glu.h>
#include <QOpenGLFunctions>

class DrawXYZWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    DrawXYZWidget(QWidget *parent = 0);
    ~DrawXYZWidget();

    // draw tools part
    void drawOneCube(GLfloat x, GLfloat y, GLfloat z);

    // mouse event control camera
    void mousePressEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;
    void mouseMoveEvent(QMouseEvent *e) override;
    void wheelEvent(QWheelEvent *e) override;

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

private:
    GLfloat x_rot;          // x轴旋转
    GLfloat	y_rot;			// Y轴旋转
    GLfloat	z_rot;			// Z轴旋转
    GLfloat x_speed;        // x轴旋转速度
    GLfloat y_speed;		// Y轴旋转速度
    GLfloat z_speed;		// Z轴旋转速度
    GLfloat	scr_depth;	    // 深入屏幕的距离

    // mouse control member
    bool bMousePress = false;
    QPoint startPoint;


};

#endif // DRAWXYZWIDGET_H
