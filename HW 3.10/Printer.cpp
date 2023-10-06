#include "Printer.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

void QueuePriority::Show() 
{
    for (int i = 0; i < Length; i++) 
    {
        cout << "User: " << PrintLine[i].user << " - Priority: " << Pri[i] << " - Time: ";
        char timeBuff[26];
        ctime_s(timeBuff, sizeof(timeBuff), &PrintLine[i].timeSubm);
        cout << timeBuff;
    }
}

QueuePriority::~QueuePriority()
{
    delete[] Wait;
    delete[] Pri;
    delete[] PrintLine;
}

QueuePriority::QueuePriority(int m) 
{
    MaxLength = m;
    Wait = new int[MaxLength];
    Pri = new int[MaxLength];
    PrintLine = new PrintJob[MaxLength];
    Length = 0;
}

void QueuePriority::Clear() 
{
    Length = 0;
}

bool QueuePriority::IsEmpty() 
{
    return Length == 0;
}

bool QueuePriority::IsFull() 
{
    return Length == MaxLength;
}

int QueuePriority::GetCount() 
{
    return Length;
}

void QueuePriority::Add(int c, int p, const string& user) 
{
    if (!IsFull()) 
    {
        Wait[Length] = c;
        Pri[Length] = p;
        PrintLine[Length].user = user;
        PrintLine[Length].timeSubm = time(nullptr);
        Length++;
    }
}

int QueuePriority::Extract()
{
    if (!IsEmpty())
    {
        int max_pri = Pri[0];
        int pos_max_pri = 0;

        for (int i = 1; i < Length; i++) 
        {
            if (max_pri < Pri[i]) 
            {
                max_pri = Pri[i];
                pos_max_pri = i;
            }
        }

        int temp1 = Wait[pos_max_pri];
        int temp2 = Pri[pos_max_pri];
        for (int i = pos_max_pri; i < Length - 1; i++) 
        {
            Wait[i] = Wait[i + 1];
            Pri[i] = Pri[i + 1];
            PrintLine[i] = PrintLine[i + 1];
        }
        Length--;
        return temp1;
    }
    else {
        return -1;
    }
}