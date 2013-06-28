#ifndef BOXGLWIDGET_H
#define BOXGLWIDGET_H

#include <QGLWidget>
#include <QGLShaderProgram>

class BoxGLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit BoxGLWidget(QWidget *parent = 0);
    ~BoxGLWidget();
    QSize sizeHint() const;
    
protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

private:
    QMatrix4x4 pMatrix;
    QGLShaderProgram shaderProgram;
    QVector<QVector3D> vertices;

    double alpha;
    double beta;
    double distance;
    QPoint lastMousePosition;
};

#endif // BOXGLWIDGET_H
