#pragma once

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <iostream>
#include <vector>

struct Result;

class DB_Manager
{
    public:
        bool init_db();
        bool clean_db() const;
        bool add_record(const char *name, const char* address) const;
        bool init_table() const;
        bool remove_record(const char* name);
        std::string getUrl(const char* title);
        std::vector<Result> retrieve_results() const;
        static DB_Manager& instance();

protected:
    explicit DB_Manager();

    private:
    std::vector<Result> results;
        ~DB_Manager();
        DB_Manager(const DB_Manager&);
        DB_Manager& operator=(const DB_Manager& dbM);
    QSqlDatabase db;

};

struct Result
{
	std::string name;
	std::string address;
    std::string date;
    std::string id;
};

