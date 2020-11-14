#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(ui->nutcam,SIGNAL(clicked()),this,SLOT(show_cam()));
    connect(ui->file,SIGNAL(clicked()),this,SLOT(play_video()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::show_cam()
{
    if(cap.isOpened() == true)
    {
       disconnect(timer, SIGNAL(timeout()), this, SLOT(update_frame()));
       timer->start(20);
       cap.release();
    }
    cap.open(0);
    if(cap.isOpened() == false)
    {
        ui->khung->setText("lo ket noi");
    }
    else
    {
        connect(timer,SIGNAL(timeout()),this,SLOT(update_frame()));
        timer->start(20);
    }

}

void MainWindow::update_frame()
{
    cap.read(frame);
    cvtColor(frame,frame,COLOR_BGR2RGB);
    qt_img = QImage((uchar*) (frame.data), frame.cols, frame.rows, QImage::Format_RGB888);
    ui->khung->setPixmap(QPixmap::fromImage(qt_img));

}

void MainWindow::play_video(){
    file = QFileDialog::getOpenFileName(
                this,
                "Chon file",
                "D://",
                "All files (*.*))"
                );
    if(cap.isOpened() == true)
    {
       disconnect(timer, SIGNAL(timeout()), this, SLOT(update_frame()));
       timer->start(20);
       cap.release();
    }
    char const* str = file.toLatin1().data();
    cap.open(str);
    if(cap.isOpened() == false)
    {
        ui->khung->setText("lo ket noi");
    }
    else
    {
        connect(timer,SIGNAL(timeout()),this,SLOT(update_frame()));
        timer->start(20);
    }

}





