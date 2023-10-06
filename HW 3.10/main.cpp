#include <iostream>
#include <string>
#include "Printer.h"

using namespace std;

int main() 
{
    srand(time(NULL));
    QueuePriority QUP(10);
    for (int i = 0; i < 6; i++) 
    {
        string user = "User" + to_string(i);
        QUP.Add(rand() % 100, rand() % 12, user);
    }
    QUP.Show();
    QUP.Extract();
    QUP.Show();
}