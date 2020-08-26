#include "DB_Manager.h"
#include "QDebug"

DB_Manager::DB_Manager()
{
    init_db();
}

DB_Manager::~DB_Manager()
{
    db.close();
}


bool DB_Manager::init_db()
{
    const QString DRIVER("QSQLITE");
    if(QSqlDatabase::isDriverAvailable(DRIVER))
    {
        db = QSqlDatabase::addDatabase(DRIVER);
        db.setDatabaseName("MoImageDB");
    }

    if (!db.open()) {
        qWarning() << "ERROR: " << db.lastError();
    }


    if (init_table())
    {
        return true;
    } else return false;
}

bool DB_Manager::init_table() const
{
    QSqlQuery query ( "CREATE TABLE if not exists images (\
                        id INTEGER PRIMARY KEY,\
                        name TEXT UNIQUE NOT NULL,\
                        address TEXT,\
                        Timestamp DATETIME DEFAULT CURRENT_TIMESTAMP);");
    if(!query.isActive())
    {
        qWarning() << "ERROR: " << query.lastError().text();
        return false;
    }
    return true;
}

bool DB_Manager::add_record(const char *name, const char *address) const
{
    QSqlQuery query;
    query.prepare( "insert into images (name, address) values ((:name), (:address));");
    query.bindValue(":name", name);
    query.bindValue(":address", address);

    if(!query.exec())
    {
        qWarning() << "ERROR" << query.lastError().text();
        return false;
    }
    return true;
}

bool DB_Manager::remove_record(const char* name)
{
    QSqlQuery query;
    query.prepare("DELETE FROM images WHERE name=?");
    query.addBindValue(name);

    if(!query.exec())
    {
        qWarning() << "ERROR" << query.lastError().text();
        return false;
    }
    return true;
	
}




bool DB_Manager::clean_db() const
{
    QSqlQuery query;
    query.prepare("DROP TABLE IF EXISTS Learn_Text;");

    if(!query.exec())
    {
        qWarning() << "ERROR" << query.lastError().text();
        return false;
    }
    return true;
}



std::vector<Result> DB_Manager::retrieve_results() const
{
    QSqlQuery query;
    query.prepare("select * from images");
    query.exec();

    std::vector<Result> results;



    while (query.next())
    {
        Result newResult;
    newResult.id = query.value(0).toInt();
    newResult.name = query.value(1).toString().toStdString().c_str();
    newResult.address = query.value(2).toString().toStdString().c_str();
    newResult.date =query.value(3).toString().toStdString().c_str();
    results.push_back(newResult);
    }

    return results;

}

// here i had problems because i left the vector results to pushback the results. Therefore i had everytime more than one result in the vector
// although there was only one result in db. I solved the problem by initializing a new vector within the function geturl() to make the vector
// a local variable.

std::string DB_Manager::getUrl(const char* title)
{
    std::string url = "";

    QSqlQuery query;
    query.prepare("select * from images where name= (:name)");
    query.bindValue(":name", title);

    if(!query.exec()) qDebug() << "exex not possible";

    //query.first();
    //qDebug() << query.value(1).toString();

    std::vector<Result> innerResult;
    Result newResult;


    query.first();
    url = query.value(2).toString().toStdString();

    qDebug() << url.c_str();

    return url;
}

DB_Manager& DB_Manager::instance()
{
    static DB_Manager singleton;
    return singleton;
}

