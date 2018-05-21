#include "knn.h"

kNN::kNN()
{
    database.open("D:\\Workspace\\Qt\\DigitInterpreter\\DigitInterpreter\\database.txt", std::ios::in);
    dist = 0;

}

kNN::~kNN()
{
    database.close();

}
void kNN::setSquares(Square *squares[N][M])
{
    int temp[N][M];

    for (int l = 0, n = 0; l < N; l++)
        for (int m = 0; m < M; m++,n++) {
            temp[l][m] = squares[l][m]->getValue();
            c[n] = temp[l][m];

        }

}


void kNN::searchkNN()
{
    double temp;    // temp value keeps distace between p and c
    //database.putValuesIntoDatabase(squares);   // remeber about changing 0 or 1 inside method

    database.clear();
    database.seekg(0,ios_base::beg);

    // fill array of Nearest Neighbour with first K vectors
    for (int  i = 0; i < K; i++)
    {
        database >> p;
        nn[i] = comupteDistance(p);
        t[i] = p[N*M]-'0';

    }
    sortDistance(nn,t);

    while(database >> p){

        temp = comupteDistance(p);
        if (temp < nn[K-1])
        {
            nn[K-1] = temp;
            t[K-1] = p[N*M]-'0';
            sortDistance(nn,t);
        }
    }

    qDebug() << "------result------";
    for (int  i = 0; i < K; i++)
    {
        qDebug() << "distance: " << nn[i];
        qDebug() << "value: "    <<  t[i];
    }
    qDebug() << "------result------";

    result = classify(t);
    messageBox.showMessage(nn,t,result);
    qDebug() << "classified as: " << result;
}

double kNN::comupteDistance(string p)
{
    dist = 0;
    for (int i = 0; i < N*M; i++)
    {
        dist += pow(c[i] - (p[i]-'0'),2);
    }

    return sqrt(dist);
}

void kNN::sortDistance(double nn[K], int t[K])
{
    double key1;
    int i, key2, j;
       for (i = 1; i < K; i++)
       {
           key1 = nn[i];
           key2 = t[i];
           j = i-1;

           while (j >= 0 && nn[j] > key1)
           {
               nn[j+1] = nn[j];
               j = j-1;
           }
           nn[j+1] = key1;
           t[j+1] = key2;
       }

}

int kNN::classify(int t[K])
{
    int zeroCounter = 0;
    int oneCounter = 0;

    for (int i = 0; i < K; i++)
    {
        if (t[i] == 0)
            zeroCounter ++;
        else
            oneCounter ++;
    }

    qDebug() << "zeroCounter: " << zeroCounter;
    qDebug() << "oneCounter: " << oneCounter;

    if (oneCounter > zeroCounter)
        return 1;
    else if (oneCounter == zeroCounter)
    {
        srand( time( NULL ) );
        return ( std::rand() % 1 ) + 0;
    }

    return 0;
}
