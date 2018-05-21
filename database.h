#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <fstream>

#include <QDebug>

#include "square.h"

#define N 10
#define M 10

using namespace std;

class Database
{
public:
    Database();
    ~Database();
    void putValuesIntoDatabase(Square *squares[N][M]);
    void putTestDataIntoFile(Square *squares[N][M]);
private:
    std::fstream database;

};

#endif // DATABASE_H
