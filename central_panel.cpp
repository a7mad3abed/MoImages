#include "central_panel.h"
#include <QPainter>
#include <QRect>
#include "DB_Manager.h"
#include "QDebug"

central_panel::central_panel(QWidget *parent) : QWidget(parent)
{
    QString url = "C:/Workspace/QtWorks/MoImage/bg.jpg";
    QPixmap *m_image= new QPixmap(url);


    image_label = new QLabel(this);
    image_label->setPixmap(QPixmap(m_image->scaled(500, 500)));
    search_entry = new QLineEdit(this);

    connect(search_entry, &QLineEdit::returnPressed, this, &central_panel::searchImage);
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

void central_panel::searchImage()
{
    std::string url = DB_Manager::instance().getUrl(search_entry->text().toStdString().c_str());
    qDebug() << url.c_str();
    QPixmap *m_image = new QPixmap(QString(url.c_str()));
    image_label->setPixmap(QPixmap(m_image->scaled(500,500)));
    search_entry->clear();

}
