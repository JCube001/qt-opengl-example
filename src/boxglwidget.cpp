#include "boxglwidget.h"

BoxGLWidget::BoxGLWidget(QWidget *parent) :
    QGLWidget(parent)
{
}

BoxGLWidget::~BoxGLWidget()
{
}

QSize BoxGLWidget::sizeHint() const
{
    return QSize(640, 480);
}

void BoxGLWidget::initializeGL()
{

}

void BoxGLWidget::resizeGL(int width, int height)
{

}

void BoxGLWidget::paintGL()
{

}

void BoxGLWidget::mousePressEvent(QMouseEvent *event)
{

}

void BoxGLWidget::mouseMoveEvent(QMouseEvent *event)
{

}

void BoxGLWidget::wheelEvent(QWheelEvent *event)
{

}
