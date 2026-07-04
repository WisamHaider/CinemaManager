//
// Created by Wisam Haider on 03/07/2026.
//

#ifndef INC_453STAGES_FILEMANAGER_H
#define INC_453STAGES_FILEMANAGER_H

#include <string>
#include <vector>
#include "Booking.h"
#include "Screen.h"

using namespace std;

class FileManager
{
public:
    FileManager();

    // Booking File Operations
    void saveBookingToFile(Booking booking);
    vector<Booking> loadBookingsFromFile();
    void displayBookingsFromFile();

    // Schedule File Operations
    void saveScheduleToFile(vector<Screen> screens);
    void loadScheduleFromFile();

private:
    const string BOOKINGS_FILE = "bookings.csv";
    const string SCHEDULE_FILE = "schedule.csv";
};

#endif