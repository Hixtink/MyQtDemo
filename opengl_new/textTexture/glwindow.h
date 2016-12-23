#ifndef GLWINDOW_H
#define GLWINDOW_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLTexture>
#include <QMatrix4x4>
#include <QVector>
#include <QPushButton>

class GLWindow : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    GLWindow(QWidget *parent = 0);
    ~GLWindow();

    // QOpenGLWidget interface
protected:
    void initializeGL() Q_DECL_OVERRIDE;
    void resizeGL(int w, int h) Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;
    void timerEvent(QTimerEvent *event) Q_DECL_OVERRIDE;

private:
    void initShaderProgram();
    void initUi();
    QOpenGLTexture* genTexture(int width, int height, const QString& text, int textPixelSize, const QColor &textColor);

private slots:
    void buttonClicked();

private:
    QOpenGLShaderProgram *mShaderProgram;
    QMatrix4x4 mProjMatrix;

    GLuint mPosAttr;
    GLuint mTexAttr;
    GLuint mMatrixLoc;
    GLuint mProjLoc;

    QOpenGLBuffer mBuffer;
    GLuint mVertexCount;

    QOpenGLTexture *mTexture;

    //ui
    QPushButton *mButton;
    bool rot;
};

struct Vertex {
    QVector3D positon;
    QVector2D tex;
};

#endif // GLWINDOW_H
