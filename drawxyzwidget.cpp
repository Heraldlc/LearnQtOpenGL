#include "drawxyzwidget.h"

#include <QMouseEvent>
#include <QWheelEvent>


DrawXYZWidget::DrawXYZWidget(QWidget *parent)
    :QOpenGLWidget(parent)
{
    x_rot = 15.0f;
    y_rot = 45.0f;
    z_rot = 45.0f;
    x_speed = 0.0f;
    y_speed = 0.0f;
    z_speed = 0.0f;
    scr_depth = -15.0f;
}

DrawXYZWidget::~DrawXYZWidget()
{

}

void DrawXYZWidget::drawOneCube(GLfloat x, GLfloat y, GLfloat z)
{
    x=x-0.5;
    y=y-0.5;
    z=z-0.5;
    //const Cube::Color *color = b->getColor();
    //glBindTexture( GL_TEXTURE_2D, texture[color[0]] );
    glBegin( GL_QUADS );
    //后面 黄色
    glNormal3f( x, y, z );
    glTexCoord2f( 0,   0  );glVertex3f(x,   y, z);
    glTexCoord2f( 0+1, 0  );glVertex3f(x+1, y, z);
    glTexCoord2f( 0+1, 0+1);glVertex3f(x+1, y+1, z);
    glTexCoord2f( 0,   0+1);glVertex3f(x, y+1, z);

    glEnd();

    //glBindTexture( GL_TEXTURE_2D, texture[color[1]] );
    glBegin( GL_QUADS );
    //前面 白色
    glNormal3f( x, y, z+1 );
    glTexCoord2f( 0,   0  );glVertex3f(x,   y,   z+1);
    glTexCoord2f( 0+1, 0  );glVertex3f(x+1, y,   z+1);
    glTexCoord2f( 0+1, 0+1);glVertex3f(x+1,   y+1, z+1);
    glTexCoord2f( 0,   0+1);glVertex3f(x, y+1, z+1);

    glEnd();
    //glBindTexture( GL_TEXTURE_2D, texture[color[2]] );
    glBegin( GL_QUADS );

    //下面 蓝色
    glNormal3f( x, y, z);
    glTexCoord2f( 0,   0  );glVertex3f(x,   y,   z);
    glTexCoord2f( 0+1, 0  );glVertex3f(x+1, y,   z);
    glTexCoord2f( 0+1, 0+1);glVertex3f(x+1,   y, z+1);
    glTexCoord2f( 0,   0+1);glVertex3f(x, y, z+1);

    glEnd();
    //glBindTexture( GL_TEXTURE_2D, texture[color[3]] );
    glBegin( GL_QUADS );

    //上面 绿色
    glNormal3f( x, y+1, z);
    glTexCoord2f( 0,   0  );glVertex3f(x,   y+1,   z);
    glTexCoord2f( 0+1, 0  );glVertex3f(x+1, y+1,   z);
    glTexCoord2f( 0+1, 0+1);glVertex3f(x+1,   y+1, z+1);
    glTexCoord2f( 0,   0+1);glVertex3f(x, y+1, z+1);

    glEnd();
    //glBindTexture( GL_TEXTURE_2D, texture[color[5]] );
    glBegin( GL_QUADS );

    //左面 橙色
    glNormal3f( x, y, z);
    glTexCoord2f( 0,   0  );glVertex3f(x,   y,   z);
    glTexCoord2f( 0+1, 0  );glVertex3f(x, y+1,   z);
    glTexCoord2f( 0+1, 0+1);glVertex3f(x,   y+1, z+1);
    glTexCoord2f( 0,   0+1);glVertex3f(x, y, z+1);

    glEnd();

    //glBindTexture( GL_TEXTURE_2D, texture[color[4]] );
    glBegin( GL_QUADS );

    //右面 红色
    glNormal3f( x+1, y, z);
    glTexCoord2f( 0,   0  );glVertex3f(x+1,   y,   z);
    glTexCoord2f( 0+1, 0  );glVertex3f(x+1, y+1,   z);
    glTexCoord2f( 0+1, 0+1);glVertex3f(x+1,   y+1, z+1);
    glTexCoord2f( 0,   0+1);glVertex3f(x+1, y, z+1);

    glEnd();

}

//------------------------------------------------------
//---------------mouse control--------------------------
//------------------------------------------------------
void DrawXYZWidget::mousePressEvent(QMouseEvent *e)
{
    bMousePress = true;
    startPoint = e->pos();
}

void DrawXYZWidget::mouseReleaseEvent(QMouseEvent *e)
{
    bMousePress = false;
}

void DrawXYZWidget::mouseMoveEvent(QMouseEvent *e)
{
    if(bMousePress)
    {
        QPoint tmp = startPoint - e->pos();
        if(abs(tmp.x()) > abs(tmp.y())){
            // x direction
            y_rot += ((int)(4 * tmp.x()/3.0))%360;
        }
        else{
            // y direction
            x_rot += ((int)(4 * tmp.y()/3.0))%360;
        }
        startPoint = e->pos();
        update();

    }
}

// wheel zoom-in and zoom-out
void DrawXYZWidget::wheelEvent(QWheelEvent *e)
{
    scr_depth += e->angleDelta().y()/(qAbs(e->angleDelta().y()));
    update();
}

// ---------------------------------------------
//
//----------------------------------------------
void DrawXYZWidget::initializeGL()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glShadeModel(GL_SMOOTH);
    glClearDepth(1);
    glEnable(GL_DEPTH_TEST);
}

void DrawXYZWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, (GLint)w, (GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLfloat)w/(GLfloat)h, 0.1, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void DrawXYZWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(-1.0f, 0.0f, scr_depth);
    glLineWidth(3.0f); // 加粗画笔

    glRotatef(x_rot, 1.0f, 0.0f, 0.0f);
    glRotatef(y_rot,0.0f,1.0f,0.0f);    //绕Y轴旋转
    glRotatef(z_rot,0.0f,0.0f,1.0f);    //绕Z轴旋转

    glBegin(GL_LINES);
    // X axes
    glColor3f(0.0f, 1.0f, 0.0f);  // green
    glVertex3f(0.0f, 0.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);  // 终点
    glVertex3f(6.0f, 0.0f, 0.0f);

    // Y
    glColor3f(1.0f, 0.0f, 0.0f);  // red
    glVertex3f(0.0f, 0.0f, 0.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 6.0f, 0.0f);

    // Z轴线
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(0.0f,0.0f,0.0f);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(0.0f,0.0f,6.0f);

    glEnd();

    // draw cubes
   glColor3f(1.0f, 1.0f, 1.0f);  // black




}
