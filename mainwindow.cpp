#include "mainwindow.h"
#include "central_panel.h"
#include "QAction"
#include "QMenuBar"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    c_panel = new central_panel();
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
