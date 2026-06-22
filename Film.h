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
    string description;
    string genre;
    string certificate;
    int length;
    string mainStar;
    string distributor;
    string releaseDate;

public:
    // Constructors
    Film();
    Film(string t, string desc, string g, string cert, int l, string star, string dist, string date);

    // Getters
    string getTitle();
    string getDescription();
    string getGenre();
    string getCertificate();
    int getLength();
    string getMainStar();
    string getDistributor();
    string getReleaseDate();

    // Setters
    void setTitle(string t);
    void setDescription(string desc);
    void setGenre(string g);
    void setCertificate(string cert);
    void setLength(int l);
    void setMainStar(string star);
    void setDistributor(string dist);
    void setReleaseDate(string date);

    // Display
    void displayInfo();
};

#endif