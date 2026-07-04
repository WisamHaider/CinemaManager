//
// Created by Wisam Haider on 11/06/2026.
//

#include "CinemaManager.h"
#include <iostream>
#include <fstream>

using namespace std;


CinemaManager::CinemaManager()
{
    addDefaultFilms();
    initializeScreens();
    scheduleFilmsToScreens();
}

void CinemaManager::addDefaultFilms()
{
    films.push_back(Film("Avengers Endgame", "The final battle against Thanos", "Action",
        "12A", 181, "Robert Downey Jr.", "Marvel Studios", "26/04/2019"));

    films.push_back(Film("Interstellar", "A journey through space and time", "Space",
        "12A", 169, "Matthew McConaughey", "Warner Bros", "07/11/2014"));

    films.push_back(Film("Batman", "The Dark Knight rises", "Action",
        "15", 176, "Christian Bale", "Warner Bros", "20/07/2012"));
}

void CinemaManager::displayFilms()
{
    cout << "\nAvailable Films\n\n";

    for (int i = 0; i < films.size(); i++)
    {
        cout << "\n" << i + 1 << ". " << films[i].getTitle() << endl;
        cout << "   Genre: " << films[i].getGenre() << " | Certificate: " << films[i].getCertificate() << endl;
        cout << "   Runtime: " << films[i].getLength() << " mins | Star: " << films[i].getMainStar() << endl;
    }
}

void CinemaManager::createBooking()
{
    displayFilms();

    cout << "\nSelect film: ";
    int filmChoice = getValidIntInput(1, films.size());

    // Display available screens for the selected film
    displayScreensForFilm(films[filmChoice - 1].getTitle());

    cin.ignore();

    string customerName;
    cout << "Customer name: ";
    getline(cin, customerName);

    string bookingDate;
    cout << "Booking date (DD/MM/YYYY): ";
    getline(cin, bookingDate);

    string bookingTime;
    cout << "Booking time (HH:MM): ";
    getline(cin, bookingTime);

    cout << "\nAdult tickets: ";
    int adultTickets = getValidIntInput(0, 100);

    cout << "Child tickets: ";
    int childTickets = getValidIntInput(0, 100);

    cout << "Student tickets: ";
    int studentTickets = getValidIntInput(0, 100);

    cout << "Senior tickets: ";
    int seniorTickets = getValidIntInput(0, 100);

    // Check if total tickets exceed screen capacity
    int totalTickets = adultTickets + childTickets + studentTickets + seniorTickets;

    // Find the screen showing this film
    int selectedScreenCapacity = 0;
    for (int i = 0; i < screens.size(); i++)
    {
        if (screens[i].getCurrentFilm() != nullptr &&
            screens[i].getCurrentFilm()->getTitle() == films[filmChoice - 1].getTitle())
        {
            selectedScreenCapacity = screens[i].getAvailableSeats();
            break;
        }
    }

    if (totalTickets > selectedScreenCapacity)
    {
        cout << "\nError: Not enough seats available! Only " << selectedScreenCapacity << " seats left." << endl;
        return;
    }

    cin.ignore();

    string paymentMethod;
    cout << "\nPayment method (cash/card): ";
    cin >> paymentMethod;

    while (paymentMethod != "cash" && paymentMethod != "card")
    {
        cout << "Invalid payment type. Please enter 'cash' or 'card': ";
        cin >> paymentMethod;
    }

    Booking booking(customerName, films[filmChoice - 1].getTitle(), bookingDate,
                   bookingTime, adultTickets, childTickets, studentTickets, seniorTickets, paymentMethod);

    double total = booking.calculateTotal();

    cout << "\n--- Booking Summary ---" << endl;
    cout << "Customer: " << booking.getCustomerName() << endl;
    cout << "Film: " << booking.getFilmTitle() << endl;
    cout << "Date: " << booking.getBookingDate() << endl;
    cout << "Time: " << booking.getBookingTime() << endl;
    cout << "Total Cost: " << total << endl;

    if (paymentMethod == "cash")
    {
        cout << "Cash received: £";
        double cashPaid = getValidDoubleInput();

        while (cashPaid < total)
        {
            cout << "Insufficient cash. Enter amount again: £";
            cashPaid = getValidDoubleInput();
        }

        cout << "Change: £" << cashPaid - total << endl;
    }
    else if (paymentMethod == "card")
    {
        string cardNumber;
        string cvc;
        string expiry;

        cout << "Card Number: ";
        cin >> cardNumber;

        cout << "CVC: ";
        cin >> cvc;

        cout << "Expiry Date: ";
        cin >> expiry;

        cout << "Card payment approved.\n";
    }

    // Update screen seats
    for (int i = 0; i < screens.size(); i++)
    {
        if (screens[i].getCurrentFilm() != nullptr &&
            screens[i].getCurrentFilm()->getTitle() == films[filmChoice - 1].getTitle())
        {
            screens[i].bookSeats(totalTickets);
            break;
        }
    }

    // Save booking to history
    saveBookingToHistory(booking);

    cout << "\nBooking completed successfully.\n";
}

void CinemaManager::saveBookingToHistory(Booking booking)
{
    bookingHistory.push_back(booking);
}

void CinemaManager::displayBookingHistory()
{
    cout << "\n--- Booking History ---" << endl;
    if (bookingHistory.size() == 0)
    {
        cout << "No bookings found." << endl;
        return;
    }

    for (int i = 0; i < bookingHistory.size(); i++)
    {
        cout << "\nBooking " << i + 1 << ":" << endl;
        cout << "  Customer: " << bookingHistory[i].getCustomerName() << endl;
        cout << "  Film: " << bookingHistory[i].getFilmTitle() << endl;
        cout << "  Date: " << bookingHistory[i].getBookingDate() << endl;
        cout << "  Time: " << bookingHistory[i].getBookingTime() << endl;
        cout << "  Total: " << bookingHistory[i].calculateTotal() << endl;
    }
}

void CinemaManager::searchBookingsByName(string name)
{
    cout << "\n=== Search Results for Customer: " << name << " ===" << endl;
    bool found = false;

    for (int i = 0; i < bookingHistory.size(); i++)
    {
        if (bookingHistory[i].getCustomerName() == name)
        {
            cout << "\nBooking " << i + 1 << ":" << endl;
            cout << "  Film: " << bookingHistory[i].getFilmTitle() << endl;
            cout << "  Date: " << bookingHistory[i].getBookingDate() << endl;
            cout << "  Time: " << bookingHistory[i].getBookingTime() << endl;
            cout << "  Total: " << bookingHistory[i].calculateTotal() << endl;
            found = true;
        }
    }

    if (!found)
    {
        cout << "No bookings found for customer: " << name << endl;
    }
}

void CinemaManager::searchBookingsByFilm(string film)
{
    cout << "\n=== Search Results for Film: " << film << " ===" << endl;
    bool found = false;

    for (int i = 0; i < bookingHistory.size(); i++)
    {
        if (bookingHistory[i].getFilmTitle() == film)
        {
            cout << "\nBooking " << i + 1 << ":" << endl;
            cout << "  Customer: " << bookingHistory[i].getCustomerName() << endl;
            cout << "  Date: " << bookingHistory[i].getBookingDate() << endl;
            cout << "  Time: " << bookingHistory[i].getBookingTime() << endl;
            cout << "  Total: " << bookingHistory[i].calculateTotal() << endl;
            found = true;
        }
    }

    if (!found)
    {
        cout << "No bookings found for film: " << film << endl;
    }
}

void CinemaManager::searchBookingsByDate(string date)
{
    cout << "\n=== Search Results for Date: " << date << " ===" << endl;
    bool found = false;

    for (int i = 0; i < bookingHistory.size(); i++)
    {
        if (bookingHistory[i].getBookingDate() == date)
        {
            cout << "\nBooking " << i + 1 << ":" << endl;
            cout << "  Customer: " << bookingHistory[i].getCustomerName() << endl;
            cout << "  Film: " << bookingHistory[i].getFilmTitle() << endl;
            cout << "  Time: " << bookingHistory[i].getBookingTime() << endl;
            cout << "  Total: " << bookingHistory[i].calculateTotal() << endl;
            found = true;
        }
    }

    if (!found)
    {
        cout << "No bookings found for date: " << date << endl;
    }
}

void CinemaManager::managerAddNewFilm()
{
    cin.ignore();

    string title;
    cout << "Film Title: ";
    getline(cin, title);

    string description;
    cout << "Description: ";
    getline(cin, description);

    string genre;
    cout << "Genre: ";
    getline(cin, genre);

    string certificate;
    cout << "Certificate (e.g., 12A, 15, PG): ";
    getline(cin, certificate);

    cout << "Running Time (minutes): ";
    int length = getValidIntInput(1, 300);

    string mainStar;
    cout << "Main Star: ";
    cin.ignore();
    getline(cin, mainStar);

    string distributor;
    cout << "Distributor: ";
    getline(cin, distributor);

    string releaseDate;
    cout << "Release Date (DD/MM/YYYY): ";
    getline(cin, releaseDate);

    Film newFilm(title, description, genre, certificate, length, mainStar, distributor, releaseDate);
    films.push_back(newFilm);

    cout << "\nFilm '" << title << "' added successfully!" << endl;
}

void CinemaManager::managerCreateWeeklySchedule()
{
    cout << "\n--- Create Weekly Schedule ---" << endl;
    cout << "Choose films for each screen:" << endl;

    for (int i = 0; i < screens.size(); i++)
    {
        displayFilms();
        cout << "\nSelect film for Screen " << screens[i].getScreenNo() << " (" << screens[i].getFacility() << "): ";
        int filmChoice = getValidIntInput(1, films.size());

        screens[i].allocateFilm(&films[filmChoice - 1]);
        cout << "Screen " << screens[i].getScreenNo() << " allocated with " << films[filmChoice - 1].getTitle() << endl;
    }

    cout << "\nWeekly schedule created successfully!" << endl;
    cout << "All showtimes have been calculated based on cinema hours (10:00-23:30)." << endl;
}

Film* CinemaManager::getFilmByTitle(string title)
{
    for (int i = 0; i < films.size(); i++)
    {
        if (films[i].getTitle() == title)
            return &films[i];
    }
    return nullptr;
}

void CinemaManager::initializeScreens()
{
    // Initialize 5 screens with varying capacities
    screens.push_back(Screen(1, "Standard", 250));
    screens.push_back(Screen(2, "IMAX", 200));
    screens.push_back(Screen(3, "Couple Seats", 150));
    screens.push_back(Screen(4, "Seat Service", 100));
    screens.push_back(Screen(5, "Standard", 100));
}

void CinemaManager::scheduleFilmsToScreens()
{
    // Screen 1: Avengers
    screens[0].allocateFilm(&films[0]);

    // Screen 2: Interstellar
    screens[1].allocateFilm(&films[1]);

    // Screen 3: Batman
    screens[2].allocateFilm(&films[2]);

    // Screens 4 and 5: empty
}

void CinemaManager::displayScreensForFilm(string filmTitle)
{
    cout << "\n=== Available Screens for " << filmTitle << " ===\n";
    cout << "Screen | Facility      | Max seats | Available seats | Showtimes\n";
    cout << "-------|---------------|-----------|-----------------|----------------------------\n";

    bool found = false;
    for (int i = 0; i < screens.size(); i++)
    {
        if (screens[i].getCurrentFilm() != nullptr &&
            screens[i].getCurrentFilm()->getTitle() == filmTitle)
        {
            cout << screens[i].getScreenNo() << "      | "
                 << screens[i].getFacility();

            // Padding for facility
            for (int j = screens[i].getFacility().length(); j < 14; j++)
                cout << " ";

            cout << "| " << screens[i].getMaxSeats() << "        | "
                 << screens[i].getAvailableSeats() << "              | ";

            vector<string> showtimes = screens[i].getShowtimes();
            if (showtimes.size() > 0)
            {
                for (int j = 0; j < showtimes.size(); j++)
                {
                    cout << showtimes[j];
                    if (j < showtimes.size() - 1) cout << ", ";
                }
            }
            cout << "\n";
            found = true;
        }
    }

    if (!found)
    {
        cout << "No screens available for this film." << endl;
    }
}

void CinemaManager::displayAllScreens()
{
    cout << "\n--- Cinema Screens ---" << endl;

    for (int i = 0; i < screens.size(); i++)
        screens[i].displayScreenInfo();
}

int CinemaManager::getValidIntInput(int min, int max)
{
    int value;
    while (!(cin >> value) || value < min || value > max)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input. Please enter a number between " << min << " and " << max << ": ";
    }
    return value;
}

double CinemaManager::getValidDoubleInput()
{
    double value;
    while (!(cin >> value) || value < 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input. Please enter a valid amount: £";
    }
    return value;
}

string CinemaManager::getValidStringInput()
{
    string value;
    while (!(cin >> value) || value.empty())
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input. Please enter text: ";
    }
    return value;
}

void CinemaManager::displayMainMenu()
{
    cout << "\n--- Cinema Booking System ---" << endl;
    cout << "1. Staff Mode (Make Bookings)" << endl;
    cout << "2. Manager Mode (Schedule & Admin)" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter choice (1-3): ";
}

void CinemaManager::displayStaffMenu()
{
    cout << "\n--- Staff Menu ---" << endl;
    cout << "1. Create Booking" << endl;
    cout << "2. Search Bookings by Customer Name" << endl;
    cout << "3. Search Bookings by Film" << endl;
    cout << "4. Search Bookings by Date" << endl;
    cout << "5. View All Bookings" << endl;
    cout << "6. Back to Main Menu" << endl;
    cout << "Enter choice (1-6): ";
}

void CinemaManager::displayManagerMenu()
{
    cout << "\n--- Manager Menu ---" << endl;
    cout << "1. Add New Film" << endl;
    cout << "2. Create Weekly Schedule" << endl;
    cout << "3. View All Screens & Schedule" << endl;
    cout << "4. View All Bookings" << endl;
    cout << "5. Back to Main Menu" << endl;
    cout << "Enter choice (1-5): ";
}