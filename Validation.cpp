//
// Created by Wisam Haider on 04/07/2026.
//

#include "Validation.h"
#include <sstream>
#include <ctime>

using namespace std;

Validation::Validation()
{
}

bool Validation::isValidDate(string date) {
    // Check format DD/MM/YYYY
    if (date.length() != 10 || date[2] != '/' || date[5] != '/')
    {
        return false;
    }

    // day, month, year
    string dayStr = date.substr(0, 2);
    string monthStr = date.substr(3, 2);
    string yearStr = date.substr(6, 4);

    // Check if all are numbers
    for (char c : dayStr) if (!isdigit(c)) return false;
    for (char c : monthStr) if (!isdigit(c)) return false;
    for (char c : yearStr) if (!isdigit(c)) return false;

    int day = stoi(dayStr);
    int month = stoi(monthStr);
    int year = stoi(yearStr);

    if (month < 1 || month > 12) {return false;}
    if (day < 1 || day > 31) {return false;}

    return true;
}

bool Validation::isValidTime(string time)
{
    // Check format HH:MM
    if (time.length() != 5 || time[2] != ':')
    {
        return false;
    }

    string hoursStr = time.substr(0, 2);
    string minutesStr = time.substr(3, 2);

    // Check if all are numbers
    for (char c : hoursStr) if (!isdigit(c)) return false;
    for (char c : minutesStr) if (!isdigit(c)) return false;

    int hours = stoi(hoursStr);
    int minutes = stoi(minutesStr);

    if (hours < 0 || hours > 23) return false;
    if (minutes < 0 || minutes > 59) return false;

    return true;
}

bool Validation::isWithinCinemaHours(string time)
{
    // Cinema: 10:00 to 23:30
    if (!isValidTime(time)) return false;

    int hours = stoi(time.substr(0, 2));
    int minutes = stoi(time.substr(3, 2));

    int timeInMinutes = hours * 60 + minutes;
    int openTime = 10 * 60; // 10:00
    int closeTime = 23 * 60 + 30; // 23:30

    return timeInMinutes >= openTime && timeInMinutes <= closeTime;
}

bool Validation::hasEnoughSeats(int requestedTickets, int availableSeats)
{
    return requestedTickets <= availableSeats;
}



bool Validation::isEmpty(string str)
{
    return str.empty() || str.find_first_not_of(" \t\n\r\f\v") == string::npos;
}