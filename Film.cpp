//
// Created by Wisam Haider on 21/05/2026.
//

#include "Film.h"

// Default Constructor
Film::Film()
{
    title = "";
    genre = "";
    length = 0;
}

Film::Film(string t, string g, int l)
{
    title = t;
    genre = g;
    length = l;
}

// Getters
string Film::getTitle()
{
    return title;
}

string Film::getGenre()
{
    return genre;
}

int Film::getLength()
{
    return length;
}

// Setters
void Film::setTitle(string t)
{
    title = t;
}

void Film::setGenre(string g)
{
    genre = g;
}

void Film::setLength(int l)
{
    length = l;
}