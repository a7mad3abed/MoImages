#include "central_panel.h"
#include <QPainter>
#include <QRect>

central_panel::central_panel(QWidget *parent) : QWidget(parent)
{
    QString url = "C:/Workspace/QtWorks/MoImage/bg.jpg";
    m_image = QPixmap(url);


    image_label = new QLabel(this);
    image_label->setPixmap(QPixmap(m_image.scaled(500, 500)));
    search_entry = new QLineEdit(this);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    QHBoxLayout *upperLayout = new QHBoxLayout();
    QHBoxLayout *lowerLayout = new QHBoxLayout();
    QVBoxLayout *leftLayout = new QVBoxLayout();
    upperLayout->addLayout(leftLayout);
    upperLayout->addWidget(image_label);
    lowerLayout->addWidget(search_entry);
    mainLayout->addLayout(upperLayout);
    mainLayout->addLayout(lowerLayout);
    setLayout(mainLayout);
}
