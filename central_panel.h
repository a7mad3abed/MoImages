#ifndef CENTRAL_PANEL_H
#define CENTRAL_PANEL_H

#include <QWidget>
#include "QHBoxLayout"
#include "QVBoxLayout"
#include "QLineEdit"
#include "QLabel"

class QLabel;
class QPixmap;
class QLineEdit;

class central_panel : public QWidget
{
    Q_OBJECT
public:
    explicit central_panel(QWidget *parent = nullptr);

private:
private:
    QPixmap m_image;
    QLabel *image_label;
    QLineEdit *search_entry;

signals:


};

#endif // CENTRAL_PANEL_H
