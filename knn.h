#ifndef KNN_H
#define KNN_H

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <math.h>
#include "square.h"
#include "database.h"
#include "messagebox.h"
#include <QDebug>

#define K 3
#define N 10
#define M 10
using namespace std;

class kNN
{
public:
    kNN();
    ~kNN();
    void setSquares(Square *squares[N][M]);
    void searchkNN();
    double comupteDistance(string p);
    void sortDistance(double nn[K], int t[K]);
    int classify(int t[K]);

private:
    string p;
    double nn[K];
    int t[K];
    double dist;
    fstream database;
    Square *squares[N][M];
    int c[N*M];
    MessageBox messageBox;
    int result;

};

#endif // KNN_H
