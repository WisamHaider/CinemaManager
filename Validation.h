//
// Created by Wisam Haider on 04/07/2026.
//

#ifndef INC_453STAGES_VALIDATION_H
#define INC_453STAGES_VALIDATION_H

#include <string>

using namespace std;

class Validation
{
public:
    Validation();

    // Date validation
    static bool isValidDate(string date); // DD/MM/YYYY format

    // Time validation
    static bool isValidTime(string time); // HH:MM format
    static bool isWithinCinemaHours(string time); // 10:00-23:30

    // Booking validation
    static bool hasEnoughSeats(int requestedTickets, int availableSeats);

    // String validation
    static bool isEmpty(string str);
};

#endif