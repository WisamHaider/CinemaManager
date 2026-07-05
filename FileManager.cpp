//
// Created by Wisam Haider on 03/07/2026.
//

#include "FileManager.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

FileManager::FileManager()
{
}

void FileManager::saveBookingToFile(Booking booking)
{
    ofstream file(BOOKINGS_FILE, ios::app);

    if (!file.is_open())
    {
        cerr << "Error: Could not open bookings file for writing!" << endl;
        return;
    }

    // Check if file is empty to write header
    file.seekp(0, ios::end);
    if (file.tellp() == 0)
    {
        file << "Customer Name,Film Title,Booking Date,Booking Time,Total Cost\n";
    }

    // Write booking data
    file << booking.getCustomerName() << ","
         << booking.getFilmTitle() << ","
         << booking.getBookingDate() << ","
         << booking.getBookingTime() << ","
         << booking.calculateTotal() << "\n";

    file.close();
    cout << "Booking saved to file successfully." << endl;
}

vector<Booking> FileManager::loadBookingsFromFile()
{
    vector<Booking> bookings;
    ifstream file(BOOKINGS_FILE);

    if (!file.is_open())
    {
        cerr << "Bookings file not found. Creating new file." << endl;
        return bookings;
    }

    string line;
    bool firstLine = true;

    while (getline(file, line))
    {
        if (firstLine)
        {
            firstLine = false;
            continue; // Skip header
        }

        stringstream ss(line);
        string customerName, filmTitle, bookingDate, bookingTime, totalStr;

        getline(ss, customerName, ',');
        getline(ss, filmTitle, ',');
        getline(ss, bookingDate, ',');
        getline(ss, bookingTime, ',');
        getline(ss, totalStr, ',');

        // Create booking with dummy values
        Booking booking(customerName, filmTitle, bookingDate, bookingTime, 1, 0, 0, 0, "cash");
        bookings.push_back(booking);
    }

    file.close();
    return bookings;
}

void FileManager::displayBookingsFromFile()
{
    ifstream file(BOOKINGS_FILE);

    if (!file.is_open())
    {
        cout << "No bookings file found." << endl;
        return;
    }

    cout << "\n=== Bookings from File ===" << endl;
    cout << left;
    cout << "Customer Name" << " | " << "Film Title" << " | " << "Date" << " | " << "Time" << " | " << "Total Cost" << endl;
    cout << "-------|-------|-------|-------|-------" << endl;

    string line;
    bool firstLine = true;

    while (getline(file, line))
    {
        if (firstLine)
        {
            firstLine = false;
            continue;
        }

        stringstream ss(line);
        string customerName, filmTitle, bookingDate, bookingTime, totalStr;

        getline(ss, customerName, ',');
        getline(ss, filmTitle, ',');
        getline(ss, bookingDate, ',');
        getline(ss, bookingTime, ',');
        getline(ss, totalStr, ',');

        cout << customerName << " | " << filmTitle << " | " << bookingDate << " | " << bookingTime << " | £" << totalStr << endl;
    }

    file.close();
}

// Replace existing saveScheduleToFile method with:
void FileManager::saveScheduleToFile(vector<Screen> screens)
{
    ofstream file(SCHEDULE_FILE);

    if (!file.is_open())
    {
        cerr << "Error: Could not open schedule file for writing!" << endl;
        return;
    }

    // Write header with Start Time and End Time columns
    file << "Screen No,Facility,Film Title,Max Seats,Available Seats,Start Times,End Times\n";

    // Write schedule data
    for (int i = 0; i < screens.size(); i++)
    {
        file << screens[i].getScreenNo() << ","<< screens[i].getFacility() << ",";

        if (screens[i].getCurrentFilm() != nullptr)
        {
            file << screens[i].getCurrentFilm()->getTitle() << ",";
        }
        else
        {
            file << "No Film,";
        }

        file << screens[i].getMaxSeats() << ","
             << screens[i].getAvailableSeats() << ",";

        // Write START times
        vector<string> showtimes = screens[i].getShowtimes();
        for (int j = 0; j < showtimes.size(); j++)
        {
            file << showtimes[j];
            if (j < showtimes.size() - 1) file << "|";
        }
        file << ",";

        // Write end times
        vector<string> endTimes = screens[i].getShowEndTimes();
        for (int j = 0; j < endTimes.size(); j++)
        {
            file << endTimes[j];
            if (j < endTimes.size() - 1) file << "|";
        }

        file << "\n";
    }

    file.close();
    cout << "Schedule saved to file successfully." << endl;
}
void FileManager::loadScheduleFromFile()
{
    ifstream file(SCHEDULE_FILE);

    if (!file.is_open())
    {
        cout << "No schedule file found." << endl;
        return;
    }

    cout << "\n--- Weekly Schedule from File ---" << endl;
    cout << "Screen | Facility | Film Title | Start Times | End Times" << endl;
    cout << "-------|----------|------------|-------------|----------" << endl;

    string line;
    bool firstLine = true;

    while (getline(file, line))
    {
        if (firstLine)
        {
            firstLine = false;
            continue;
        }

        stringstream ss(line);
        string screenNo, facility, filmTitle, maxSeats, availableSeats, startTimes, endTimes;

        getline(ss, screenNo, ',');
        getline(ss, facility, ',');
        getline(ss, filmTitle, ',');
        getline(ss, maxSeats, ',');
        getline(ss, availableSeats, ',');
        getline(ss, startTimes, ',');
        getline(ss, endTimes, ',');

        cout << screenNo << " | " << facility << " | " << filmTitle << " | "<< startTimes << " | " << endTimes << endl;
    }

    file.close();
}