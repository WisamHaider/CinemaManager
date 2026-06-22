//
// Created by Wisam Haider on 21/05/2026.
//

#include "Film.h"
#include <iostream>

using namespace std;

// Default Constructor
Film::Film(){
    title = "";
    description = "";
    genre = "";
    certificate = "";
    length = 0;
    mainStar = "";
    distributor = "";
    releaseDate = "";
}

Film::Film(string t, string desc, string g, string cert, int l, string star, string dist, string date){
    title = t;
    description = desc;
    genre = g;
    certificate = cert;
    length = l;
    mainStar = star;
    distributor = dist;
    releaseDate = date;

}

// Getters

string Film::getTitle() {
    return title;
}

string Film::getDescription() {
    return description;
}

string Film::getGenre() {
    return genre;
}

string Film::getCertificate() {
    return certificate;
}

int Film::getLength() {
    return length;
}

string Film::getMainStar() {
    return mainStar;
}

string Film::getDistributor() {
    return distributor;
}

string Film::getReleaseDate() {
    return releaseDate;
}


// Setters
void Film::setTitle(string t) {
    title = t;
}
void Film::setDescription(string desc) {
    description = desc;
}
void Film::setGenre(string g) {
    genre = g;
}
void Film::setCertificate(string cert) {
    certificate = cert;
}
void Film::setLength(int l) {
    length = l;
}
void Film::setMainStar(string star) {
    mainStar = star;
}
void Film::setDistributor(string dist) {
    distributor = dist;
}
void Film::setReleaseDate(string date) {
    releaseDate = date;
}

// Display Film Information
void Film::displayInfo()
{
    cout << "Title: " << title << endl;
    cout << "Description: " << description << endl;
    cout << "Genre: " << genre << endl;
    cout << "Certificate: " << certificate << endl;
    cout << "Runtime: " << length << " mins" << endl;
    cout << "Main Star: " << mainStar << endl;
    cout << "Distributor: " << distributor << endl;
    cout << "Release Date: " << releaseDate << endl;
}