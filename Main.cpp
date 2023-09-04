#include <iostream>
#include "LinkedList.cpp"
#include <fstream>
#include <limits>
using namespace std;

LinkedList<Event> SortStartDate(LinkedList<Event> E);
LinkedList<Event> SortReminderDate(LinkedList<Event> E);
LinkedList<Event> CreateEvent(LinkedList<Event> E);

int main()
{
    LinkedList<Event> Events;
    LinkedList<Event> doneEvents;
    Event Efile;
    ifstream EventFile("Events.txt");
    while (EventFile >> Efile.name >> Efile.startDate.day >> Efile.startDate.month >> Efile.startDate.year >> Efile.startDate.hr >> Efile.startDate.min >> Efile.startDate.day >> Efile.endDate.month >> Efile.endDate.year >> Efile.endDate.hr >> Efile.endDate.min >> Efile.reminderDate.day >> Efile.reminderDate.month >> Efile.reminderDate.year >> Efile.reminderDate.hr >> Efile.reminderDate.min >> Efile.place >> Efile.isDone)
        Events.Append(Efile);
    ifstream doneEventsFile("doneEvents.txt");
    while (doneEventsFile >> Efile.name >> Efile.startDate.day >> Efile.startDate.month >> Efile.startDate.year >> Efile.startDate.hr >> Efile.startDate.min >> Efile.startDate.day >> Efile.endDate.month >> Efile.endDate.year >> Efile.endDate.hr >> Efile.endDate.min >> Efile.reminderDate.day >> Efile.reminderDate.month >> Efile.reminderDate.year >> Efile.reminderDate.hr >> Efile.reminderDate.min >> Efile.place >> Efile.isDone)
        doneEvents.Append(Efile);
    while (true)
    {
        cout << "********** Event's Scheduler**********" << endl;
        cout << "(1) TO ADD EVENT " << endl;
        cout << "(2) TO UPDATE EVENT " << endl;
        cout << "(3) TO DELETE EVENT" << endl;
        cout << "(4) TO DISPLAY UPCOMING EVENTS" << endl;
        cout << "(5) TO DISPLAY DONE EVENTS" << endl;
        cout << "(6) TO Save All Changes" << endl;
        cout << "(7) TO EXIST THE PROGRAM" << endl;
        cout << "*****************************" << endl;
        cout << " ENTER THE NUMBER OF OPTION WHICH YOU WANT" << endl;
        int option;
        cin >> option;
        switch (option)
        {
        case 1:
        {
            Events = CreateEvent(Events);
            break;
        }
        case 2:
        {
            for (int i = 0; i < Events.Length(); i++)
            {
                cout << i << ": " << endl;
                Events.At(i).Display();
            }
            cout << "Enter the number of the event you want to update: ";
            int updateOption;
            cin >> updateOption;
            Event Etmp;
            Etmp = Etmp.Update(Events.At(updateOption));
            Events.Update(updateOption, Etmp);
            break;
        }
        case 3:
        {
            for (int i = 0; i < Events.Length(); i++)
            {
                cout << i << ": " << endl;
                Events.At(i).Display();
            }
            cout << "Enter the number of the event you want to delete: ";
            int deleteOption;
            cin >> deleteOption;
            Events.DeleteAt(deleteOption);
            break;
        }
        case 4:
        {
            cout << "Enter 1 to sort by starting dates and 2 to sort by reminder dates: ";
            int sortOption;
            cin >> sortOption;
            if (sortOption == 1)
                Events = SortStartDate(Events);
            else if (sortOption == 2)
                Events = SortReminderDate(Events);
            for (int i = 0; i < Events.Length(); i++)
            {
                cout << i << ": " << endl;
                Events.At(i).Display();
            }
            break;
        }
        case 5:
        {
            cout << "Enter 1 to sort by starting dates and 2 to sort by reminder dates: ";
            int sortOption;
            cin >> sortOption;
            if (sortOption == 1)
                doneEvents = SortStartDate(doneEvents);
            else if (sortOption == 2)
                doneEvents = SortReminderDate(doneEvents);
            for (int i = 0; i < doneEvents.Length(); i++)
            {
                cout << i << ": " << endl;
                doneEvents.At(i).Display();
            }
            break;
        }
        case 6:
        {
            fstream doneEventsFile;
            doneEventsFile.open("doneEvents.txt", fstream::out | fstream::trunc);
            for (int i = 0; i < doneEvents.Length(); i++)
            {
                doneEventsFile << doneEvents.At(i).name << " " << doneEvents.At(i).startDate.day << " " << doneEvents.At(i).startDate.month << " " << doneEvents.At(i).startDate.year << " " << doneEvents.At(i).startDate.hr << " " << doneEvents.At(i).startDate.min << " " << doneEvents.At(i).startDate.day << " " << doneEvents.At(i).endDate.month << " " << doneEvents.At(i).endDate.year << " " << doneEvents.At(i).endDate.hr << " " << doneEvents.At(i).endDate.min << " " << doneEvents.At(i).reminderDate.day << " " << doneEvents.At(i).reminderDate.month << " " << doneEvents.At(i).reminderDate.year << " " << doneEvents.At(i).reminderDate.hr << " " << doneEvents.At(i).reminderDate.min << " " << doneEvents.At(i).place << " " << doneEvents.At(i).isDone << endl;
            }
            doneEventsFile.close();
            fstream EventsFile;
            EventsFile.open("Events.txt", fstream::out | fstream::trunc);
            for (int i = 0; i < Events.Length(); i++)
            {
                EventsFile << Events.At(i).name << " " << Events.At(i).startDate.day << " " << Events.At(i).startDate.month << " " << Events.At(i).startDate.year << " " << Events.At(i).startDate.hr << " " << Events.At(i).startDate.min << " " << Events.At(i).startDate.day << " " << Events.At(i).endDate.month << " " << Events.At(i).endDate.year << " " << Events.At(i).endDate.hr << " " << Events.At(i).endDate.min << " " << Events.At(i).reminderDate.day << " " << Events.At(i).reminderDate.month << " " << Events.At(i).reminderDate.year << " " << Events.At(i).reminderDate.hr << " " << Events.At(i).reminderDate.min << " " << Events.At(i).place << " " << Events.At(i).isDone << endl;
            }
            EventsFile.close();
            cout << "***************************" << endl;
            cout << "Saved Successfully"<< endl;
            break;
        }
        case 7:
        {
            return 0;
            break;
        }
        default:
        {
            cout << " wrong option please try again" << endl;
            break;
        }
        }
        for (int i = 0; i < Events.Length(); i++)
        {
            if (Events.At(i).isDone)
            {
                doneEvents.Append(Events.At(i));
                Events.DeleteAt(i);
            }
        }
        cout << "*****************************************" << endl;
        cout << "Press enter to continue . . . ";
        cin.sync();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        system("CLS");
    }
}

LinkedList<Event> CreateEvent(LinkedList<Event> E)
{
    cout << "Enter values of event " << endl;
    cout << "Enter the name: ";
    string name;
    cin >> name;
    cout << "Enter the start date: ";
    date startDate;
    cout << "Enter Day: ";
    cin >> startDate.day;
    cout << "Enter Month: ";
    cin >> startDate.month;
    cout << "Enter Year: ";
    cin >> startDate.year;
    cout << "Enter hour: ";
    cin >> startDate.hr;
    cout << "Enter minute: ";
    cin >> startDate.min;
    cout << "Enter the end date: ";
    date endDate;
    cout << "Enter Day: ";
    cin >> endDate.day;
    cout << "Enter Month: ";
    cin >> endDate.month;
    cout << "Enter Year: ";
    cin >> endDate.year;
    cout << "Enter hour: ";
    cin >> endDate.hr;
    cout << "Enter minute: ";
    cin >> endDate.min;
    cout << "Enter the Reminder date: ";
    date remDate;
    cout << "Enter Day: ";
    cin >> remDate.day;
    cout << "Enter Month: ";
    cin >> remDate.month;
    cout << "Enter Year: ";
    cin >> remDate.year;
    cout << "Enter hour: ";
    cin >> remDate.hr;
    cout << "Enter minute: ";
    cin >> remDate.min;
    cout << "Enter the place: ";
    string place;
    cin >> place;
    Event Ecreated(name, startDate, endDate, remDate, place);
    for (int i = 0; i < E.Length(); i++)
    {
        if (Ecreated.startDate.year == E.At(i).startDate.year && Ecreated.endDate.year == E.At(i).endDate.year)
        {
            if (Ecreated.startDate.month == E.At(i).startDate.month && Ecreated.endDate.month == E.At(i).endDate.month)
            {
                if (Ecreated.startDate.day >= E.At(i).startDate.day && Ecreated.startDate.day <= E.At(i).endDate.day)
                {
                    cout << "The date entered is already taken by another event" << endl;
                    return E;
                }
            }
        }
    }
    E.Append(Ecreated);
    return E;
}

LinkedList<Event> SortStartDate(LinkedList<Event> E)
{
    LinkedList<Event> Esorted;
    Event *Es = new Event[E.Length()];
    for (int i = 0; i < E.Length(); i++)
    {
        Es[i] = E.At(i);
    }
    for (int i = 0; i < E.Length(); i++)
    {
        for (int j = i + 1; j < E.Length(); j++)
        {
            if (E.At(i).startDate.year > E.At(j).startDate.year)
            {
                Event etmp = Es[i];
                Es[i] = Es[j];
                Es[j] = etmp;
            }
            else if (E.At(i).startDate.year == E.At(j).startDate.year && E.At(i).startDate.month > E.At(j).startDate.month)
            {
                Event etmp = Es[i];
                Es[i] = Es[j];
                Es[j] = etmp;
            }
            else if (E.At(i).startDate.year == E.At(j).startDate.year && E.At(i).startDate.month == E.At(j).startDate.month && E.At(i).startDate.day > E.At(j).startDate.day)
            {
                Event etmp = Es[i];
                Es[i] = Es[j];
                Es[j] = etmp;
            }
        }
    }
    for (int i = 0; i < E.Length(); i++)
    {
        Esorted.Append(Es[i]);
    }
    return Esorted;
}

LinkedList<Event> SortReminderDate(LinkedList<Event> E)
{
    LinkedList<Event> Esorted;
    Event *Es = new Event[E.Length()];
    for (int i = 0; i < E.Length(); i++)
    {
        Es[i] = E.At(i);
    }
    for (int i = 0; i < E.Length(); i++)
    {
        for (int j = i + 1; j < E.Length(); j++)
        {
            if (E.At(i).reminderDate.year > E.At(j).reminderDate.year)
            {
                Event etmp = Es[i];
                Es[i] = Es[j];
                Es[j] = etmp;
            }
            else if (E.At(i).reminderDate.year == E.At(j).reminderDate.year && E.At(i).reminderDate.month > E.At(j).reminderDate.month)
            {
                Event etmp = Es[i];
                Es[i] = Es[j];
                Es[j] = etmp;
            }
            else if (E.At(i).reminderDate.year == E.At(j).reminderDate.year && E.At(i).reminderDate.month == E.At(j).reminderDate.month && E.At(i).reminderDate.day > E.At(j).reminderDate.day)
            {
                Event etmp = Es[i];
                Es[i] = Es[j];
                Es[j] = etmp;
            }
        }
    }
    for (int i = 0; i < E.Length(); i++)
    {
        Esorted.Append(Es[i]);
    }
    return Esorted;
}
