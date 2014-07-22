#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    // TODO : close all opened dialogs when user closes main window
    delete ui;
}

void MainWindow::on_actionOpen_file_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open image file"),
                                                    "",
                                                    tr("Tif files (*.tif);;Tiff files (*.tiff);;Jpeg files (*.jpg);;All files (*.*)"));
    if( !fileName.isEmpty() )
    {
        QSharedPointer<ImageDialog> imageDialog( new ImageDialog(fileName) );
        imageDialog->setWindowTitle(fileName);
        imageDialog->show();
        openedImageDialogs.push_back(imageDialog);
    }
}

void MainWindow::on_actionOpen_fileset_triggered()
{

}

void MainWindow::on_MainWindow_destroyed()
{
    // TODO : close all opened dialogs when user closes main window
    //for( auto d : openedImageDialogs )
      //  d->close();
}
