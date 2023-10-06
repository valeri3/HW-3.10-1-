#pragma once
#include <iostream>

using namespace std;

struct PrintJob 
{
    string user;
    time_t timeSubm;
};

class QueuePriority
{
    int* Wait;
    int* Pri;
    PrintJob* PrintLine;
    int MaxLength;
    int Length;

public:
    QueuePriority(int m);
    ~QueuePriority();
    void Add(int c, int p, const string& user);
    int Extract();
    void Clear();
    bool IsEmpty();
    bool IsFull();
    int GetCount();
    void Show();
};