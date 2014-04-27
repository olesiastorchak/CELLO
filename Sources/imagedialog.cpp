#include "imagedialog.h"
#include "ui_imagedialog.h"

ImageDialog::ImageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImageDialog)
{
    createLayout();
    createSlots();
    ui->setupUi(this);
}

ImageDialog::ImageDialog(QString imageFileName, QWidget *parent):
    QDialog(parent),
    ui(new Ui::ImageDialog)
{
    createLayout();
    createSlots();
    ui->setupUi(this);

    if( !imageFileName.isEmpty() )
    {
        QImage image(imageFileName);
        if (image.isNull()) {
            QMessageBox::information(this, tr("Image Viewer"),
                                     tr("Cannot load %1.").arg(imageFileName));
            return;
        }
        imageLabel->setPixmap(QPixmap::fromImage(image));
        imageLabel->adjustSize();
        scaleFactor = 1.0;
    }
}

void ImageDialog::createLayout()
{
    imageLabel = new QLabel;
    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);

    scrollArea = new QScrollArea(this);
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    scrollArea->setWidget(imageLabel);

    zoomInButton = new QPushButton;
    zoomInButton->setIcon(QIcon(":/Zoom-In-icon 32.png"));
    zoomInButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    zoomInButton->setIconSize(QSize(32,32));

    zoomOutButton = new QPushButton;
    zoomOutButton->setIcon(QIcon(":/Zoom-Out-icon 32.png"));
    zoomOutButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    zoomOutButton->setIconSize(QSize(32,32));

    QSpacerItem* spc = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Fixed);
    QHBoxLayout* hLayout = new QHBoxLayout;
    hLayout->addWidget(zoomInButton);
    hLayout->addWidget(zoomOutButton);
    hLayout->addItem(spc);


    QVBoxLayout* layout = new QVBoxLayout;
    this->setLayout(layout);
    layout->addLayout(hLayout);
    layout->addWidget(scrollArea);
}

void ImageDialog::createSlots()
{
    connect(zoomInButton, SIGNAL(clicked()), this, SLOT(zoomIn()));

    connect(zoomOutButton, SIGNAL(clicked()), this, SLOT(zoomOut()));

}
void ImageDialog::zoomIn()
{
    scaleImage(1.25);
}

void ImageDialog::zoomOut()
{
    scaleImage(0.8);
}

void ImageDialog::scaleImage(double factor)
{
    Q_ASSERT(imageLabel->pixmap());
    scaleFactor *= factor;
    imageLabel->resize(scaleFactor * imageLabel->pixmap()->size());

    adjustScrollBar(scrollArea->horizontalScrollBar(), factor);
    adjustScrollBar(scrollArea->verticalScrollBar(), factor);

    zoomInButton->setEnabled(scaleFactor < 3.0);
    zoomOutButton->setEnabled(scaleFactor > 0.1);
}

void ImageDialog::adjustScrollBar(QScrollBar *scrollBar, double factor)
{
    scrollBar->setValue(int(factor * scrollBar->value()
                            + ((factor - 1) * scrollBar->pageStep()/2)));
}

ImageDialog::~ImageDialog()
{
    delete ui;
}
