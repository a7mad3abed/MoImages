#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class central_panel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    central_panel *c_panel;
    QMenu *fileMenu;
    QMenu * helpMenu;
    QAction *newAct;
    QAction *deleteAct;
    QAction *exitAct;

private slots:
    void newImage();
    void deleteImage(QString&);

private:
    void createActions();
    void createMenus();


};
#endif // MAINWINDOW_H
