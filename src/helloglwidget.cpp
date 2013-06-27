#include "helloglwidget.h"

HelloGLWidget::HelloGLWidget(QWidget *parent) :
    QGLWidget(QGLFormat(), parent)
{
}

HelloGLWidget::~HelloGLWidget()
{
}

QSize HelloGLWidget::sizeHint() const
{
    return QSize(640, 480);
}

void HelloGLWidget::initializeGL()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    qglClearColor(QColor(Qt::black));

    shaderProgram.addShaderFromSourceFile(QGLShader::Vertex, ":/vertexShader.vsh");
    shaderProgram.addShaderFromSourceFile(QGLShader::Fragment, ":/fragmentShader.fsh");
    shaderProgram.link();

    vertices << QVector3D(1, 0, -2) << QVector3D(0, 1, -2) << QVector3D(-1, 0, -2);
}

void HelloGLWidget::resizeGL(int width, int height)
{
    if (height == 0)
    {
        height = 1;
    }

    pMatrix.setToIdentity();
    pMatrix.perspective(60.0, (float)width / (float)height, 0.001, 1000);

    glViewport(0, 0, width, height);
}

void HelloGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    QMatrix4x4 mMatrix;
    QMatrix4x4 vMatrix;

    shaderProgram.bind();

    shaderProgram.setUniformValue("mvpMatrix", pMatrix * vMatrix * mMatrix);

    shaderProgram.setUniformValue("color", QColor(Qt::white));

    shaderProgram.setAttributeArray("vertex", vertices.constData());
    shaderProgram.enableAttributeArray("vertex");

    glDrawArrays(GL_TRIANGLES, 0, vertices.size());

    shaderProgram.disableAttributeArray("vertex");

    shaderProgram.release();
}
