//
// Created by Wisam Haider on 21/05/2026.
//


#ifndef INC_453STAGES_FILM_H
#define INC_453STAGES_FILM_H

#include <string>

using namespace std;

class Film

{
private:
    string title;
    string genre;
    int length;

public:
    // Constructors

    Film();
    Film(string t, string g, int l);

    // Getters

    string getTitle();
    string getGenre();
    int getLength();

    // Setters

    void setTitle(string t);
    void setGenre(string g);
    void setLength(int l);
};

#endif