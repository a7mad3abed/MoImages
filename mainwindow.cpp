#include "mainwindow.h"
#include "DB_Manager.h"
#include "central_panel.h"
#include "QAction"
#include "QMenuBar"
#include "QDir"
#include "QFile"
#include "QFileInfo"
#include "QtDebug"
#include "QFileDialog"
#include "QInputDialog"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    DB_Manager::instance();
    c_panel = new central_panel();
    createFolder();
    createActions();
    createMenus();
    setCentralWidget(c_panel);
}

MainWindow::~MainWindow()
{
}

void MainWindow::createActions()
{
   newAct = new QAction("&New", this);
   newAct->setShortcut(QKeySequence::New);
   newAct->setStatusTip("Create new Image");
   connect(newAct, &QAction::triggered, this, &MainWindow::newImage);
   exitAct = new QAction("&Exit", this);
   exitAct->setShortcuts(QKeySequence::Close);
   exitAct->setStatusTip("Exit");
   connect(exitAct, &QAction::triggered, this, &QMainWindow::close);

}

void MainWindow::createFolder()
{
    QDir dir;
    if(dir.exists("my Images"))
    {
        qDebug() << "Folder already exists";
    }

    if(dir.mkdir("my Images"))
    {
        qDebug() << "Folder successfully created";
    }



}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu("&File");
    fileMenu->addAction(newAct);
    fileMenu->addAction(exitAct);
    fileMenu = menuBar()->addMenu("&Edit");
}

void MainWindow::newImage()
{
    bool ok;
    QString newEntry = QInputDialog::getText(this, tr("QInputDialog::getText()"), tr("Enter name for Image"), QLineEdit::Normal, QDir::home().dirName(), &ok);
    if(ok && !newEntry.isEmpty())
    {
        QString imageName = QFileDialog::getOpenFileName(this, "open image", "my images", "Image Files (*.png *.jpg *.bmp)" );
        QFileInfo info(imageName);
        QString imageNameOnly = info.fileName();
        if(imageName != "")
        {
            QString current = QDir().currentPath();
            current.append("/my images/");
            current.append(imageNameOnly);
            qDebug() << current;
            if(QFile::exists(current))
            {
                qDebug() << "it exists";
            }
            else
            {
                QFile::copy(imageName, current);
                DB_Manager::instance().add_record(newEntry.toStdString().c_str(), current.toStdString().c_str());

            }

        }
    }

}

void MainWindow::deleteImage(QString &image)
{

}
