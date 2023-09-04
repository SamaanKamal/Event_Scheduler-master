#include "Event.h"

Event::Event()
{
}
Event::Event(string n, date sd, date ed, date rd, string p)
{
    name = n;
    startDate = sd;
    endDate = ed;
    reminderDate = rd;
    place = p;
    isDone = false;
}
Event::Event(string n, date sd, date ed, date rd, string p, bool d)
{
    name = n;
    startDate = sd;
    endDate = ed;
    reminderDate = rd;
    place = p;
    isDone = d;
}

void Event::Display()
{
    cout << "the name of event is :"
         << "" << name << endl;
    cout << "the place is :"
         << " " << place << endl;
    cout << "the start date is :"
         << " " << startDate.day << "/" << startDate.month << "/" << startDate.year << " at " << startDate.hr << ":" << startDate.min << endl;
    cout << "the end date is :"
         << " " << endDate.day << "/" << endDate.month << "/" << endDate.year << " at " << endDate.hr << ":" << endDate.min << endl;
    cout << "the reminder date is :"
         << " " << reminderDate.day << "/" << reminderDate.month << "/" << reminderDate.year << " at " << reminderDate.hr << ":" << reminderDate.min << endl;
}

Event Event::Update(Event Eupdated)
{
    cout << "Enter a new value to update or enter 0 to keep it as it is " << endl;
    cout << "Enter The new name: ";
    string newName;
    cin >> newName;
    if (newName == "0")
    {
        newName = Eupdated.name;
    }
    cout << "Enter the new start date: ";
    date newStartDate;
    cout << "Enter Day: ";
    cin >> newStartDate.day;
    if (!newStartDate.day)
    {
        newStartDate.day = Eupdated.startDate.day;
    }
    cout << "Enter Month: ";
    cin >> newStartDate.month;
    if (!newStartDate.month)
    {
        newStartDate.month = Eupdated.startDate.month;
    }
    cout << "Enter Year: ";
    cin >> newStartDate.year;
    if (!newStartDate.year)
    {
        newStartDate.year = Eupdated.startDate.year;
    }
    cout << "Enter hour: ";
    cin >> newStartDate.hr;
    if (!newStartDate.hr)
    {
        newStartDate.hr = Eupdated.startDate.hr;
    }
    cout << "Enter minute: ";
    cin >> newStartDate.min;
    if (!newStartDate.min)
    {
        newStartDate.min = Eupdated.startDate.min;
    }
    cout << "Enter the new end date: ";
    date newEndDate;
    cout << "Enter Day: ";
    cin >> newEndDate.day;
    if (!newEndDate.day)
    {
        newEndDate.day = Eupdated.endDate.day;
    }
    cout << "Enter Month: ";
    cin >> newEndDate.month;
    if (!newEndDate.month)
    {
        newEndDate.month = Eupdated.endDate.month;
    }
    cout << "Enter Year: ";
    cin >> newEndDate.year;
    if (!newEndDate.year)
    {
        newEndDate.year = Eupdated.endDate.year;
    }
    cout << "Enter hour: ";
    cin >> newEndDate.hr;
    if (!newEndDate.hr)
    {
        newEndDate.hr = Eupdated.endDate.hr;
    }
    cout << "Enter minute: ";
    cin >> newEndDate.min;
    if (!newEndDate.min)
    {
        newEndDate.min = Eupdated.endDate.min;
    }
    cout << "Enter the new Reminder date: ";
    date newRemDate;
    cout << "Enter Day: ";
    cin >> newRemDate.day;
    if (!newRemDate.day)
    {
        newRemDate.day = Eupdated.reminderDate.day;
    }
    cout << "Enter Month: ";
    cin >> newRemDate.month;
    if (!newRemDate.month)
    {
        newRemDate.month = Eupdated.reminderDate.month;
    }
    cout << "Enter Year: ";
    cin >> newRemDate.year;
    if (!newRemDate.year)
    {
        newRemDate.year = Eupdated.reminderDate.year;
    }
    cout << "Enter hour: ";
    cin >> newRemDate.hr;
    if (!newRemDate.hr)
    {
        newRemDate.hr = Eupdated.reminderDate.hr;
    }
    cout << "Enter minute: ";
    cin >> newRemDate.min;
    if (!newRemDate.year)
    {
        newRemDate.year = Eupdated.reminderDate.year;
    }
    cout << "Enter the new place: ";
    string newPlace;
    cin >> newPlace;
    if (newPlace == "0")
    {
        newPlace = Eupdated.place;
    }
    cout << "Enter Y if event is done and N if not: ";
    bool done;
    char dstr;
    cin >> dstr;
    if (dstr == 'y' || dstr == 'Y')
    {
        done = true;
    }
    else
    {
        done = false;
    }

    Event Eupdate(newName, newStartDate, newEndDate, newRemDate, newPlace, done);
    return Eupdate;
}
