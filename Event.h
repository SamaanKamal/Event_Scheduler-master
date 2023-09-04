#pragma once
#include <iostream>
using namespace std;

struct date
{
    int day;
    int month;
    int year;
    int hr;
    int min;
};

class Event
{

public:
    string name;
    date startDate;
    date endDate;
    date reminderDate;
    string place;
    bool isDone;
    Event();
    Event(string n, date sd, date ed, date rd, string p);
    Event(string n, date sd, date ed, date rd, string p, bool d);
    void Display();
    Event Update(Event Eupdated);
};
