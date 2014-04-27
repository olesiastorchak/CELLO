#ifndef IMAGEDIALOG_H
#define IMAGEDIALOG_H

#include <QDialog>
#include <QtWidgets>

namespace Ui {
class ImageDialog;
}

class ImageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ImageDialog(QWidget *parent = 0);
    explicit ImageDialog(QString imageFileName, QWidget *parent = 0);
    ~ImageDialog();

private slots:
    void zoomIn();
    void zoomOut();

private:
    void createLayout();
    void createSlots();
    void scaleImage(double factor);
    void adjustScrollBar(QScrollBar *scrollBar, double factor);

    Ui::ImageDialog *ui;
    QLabel *imageLabel;
    QScrollArea *scrollArea;
    QPushButton *zoomInButton;
    QPushButton *zoomOutButton;
    double scaleFactor;
};

#endif // IMAGEDIALOG_H
