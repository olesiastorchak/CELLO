#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "imagedialog.h"

#include <vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionOpen_file_triggered();

    void on_actionOpen_fileset_triggered();

    void on_MainWindow_destroyed();

private:
    Ui::MainWindow *ui;
    std::vector<QSharedPointer<ImageDialog>> openedImageDialogs;// TODO : close all opened dialogs when user closes main window
};

#endif // MAINWINDOW_H
