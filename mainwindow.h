#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QFileDialog>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>


using namespace cv;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void show_cam();
    void update_frame();
    void play_video();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    VideoCapture cap;
    Mat frame;
    QImage qt_img;
    QString file;
};

#endif // MAINWINDOW_H


