#include <iostream>
#include <vector>
#include "Film.h"

using namespace std;

void displayFilms(vector<Film>& films)
{
    cout << "Available Films \n\n";

    for (int i = 0; i < films.size(); i++)
    {
        cout << i + 1 << ". "
             << films[i].getTitle()
             << " | Genre: " << films[i].getGenre()
             << " | Runtime: " << films[i].getLength()
             << " mins\n";
    }
}

int main() {
    vector<Film> films;

    // Minimum 3 films required
    films.push_back(Film(
        "Avengers Endgame",
        "Action",
        181
    ));

    films.push_back(Film(
        "Interstellar",
        "Space",
        169
    ));

    films.push_back(Film(
        "Batman",
        "Action",
        176
    ));

    int filmChoice;
    string customerName;
    string bookingDate;
    string bookingTime;

    displayFilms(films);

    cout << "\nSelect film: ";
    cin >> filmChoice;

    // Validation
    while (filmChoice < 1 || filmChoice > films.size())
    {
        cout << "Invalid film selection. Try again: ";
        cin >> filmChoice;
    }
}