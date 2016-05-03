#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QThread>
#include <makeblurimage.h>
#include <QImage>
#include <QSlider>

class QProgressBar;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void paintEvent(QPaintEvent*);

public slots:
    void Over(const QImage& img);
    void toMake(int lever);
    void updatePDialog(int range, int value);

signals:
    void mitMake(int lever);

private:
    int mBlurLever;
    QSlider *mSlider;
    QImage mImage;
    QThread *mMThread;
    MakeBlurImage *mMake;
    QProgressBar *mProgress;
};

#endif // WIDGET_H
