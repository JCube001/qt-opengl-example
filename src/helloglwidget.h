#ifndef HELLOGLWIDGET_H
#define HELLOGLWIDGET_H

#include <QGLWidget>
#include <QGLShaderProgram>

class HelloGLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit HelloGLWidget(QWidget *parent = 0);
    ~HelloGLWidget();
    QSize sizeHint() const;

protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();

private:
    QMatrix4x4 pMatrix;
    QGLShaderProgram shaderProgram;
    QVector<QVector3D> vertices;
};

#endif // HELLOGLWIDGET_H
