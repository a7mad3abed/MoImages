#include "mainwindow.h"
#include "central_panel.h"
#include "QAction"
#include "QMenuBar"
#include "QDir"
#include "QtDebug"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
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

}

void MainWindow::deleteImage(QString &image)
{

}
