# Qt5下OpenGL程序写法

在Qt5种，引入了新的QOpeGL...类，取代原来的QGL...类

以下是从Qt5例子中抠出的两种OpenGL模板，方便参考

## 方法一

### 头文件定义

```c++
#ifndef TRIANGLEWINDOW_H
#define TRIANGLEWINDOW_H
 
#include <QWindow>
#include <QOpenGLFunctions>
 
class QPainter;
class QOpenGLContext;
class QOpenGLPaintDevice;
 
class TriangleWindow : public QWindow, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit TriangleWindow(QWindow *parent = 0);
    ~TriangleWindow();
    
    virtual void render(QPainter *);
    virtual void render();
    virtual void initialize();
    
public slots:
    void renderNow();
 
protected:
    void exposeEvent(QExposeEvent *);
    void resizeEvent(QResizeEvent *);
 
private:
    bool m_update_pending;
 
    QOpenGLContext *m_context;
    QOpenGLPaintDevice *m_device;
    
};
 
#endif // TRIANGLEWINDOW_H
```

