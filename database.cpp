#include "database.h"

Database::Database()
{
    database.open("D:\\Workspace\\Qt\\DigitInterpreter\\DigitInterpreter\\database.txt", std::ios::app);
}

Database::~Database()
{
    database.close();
}

void Database::putValuesIntoDatabase(Square *squares[N][M])
{

    for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                database << squares[i][j]->getValue();

    database << "0";
    database << endl;
}



