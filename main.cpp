#include <iostream>
#include <list>



using namespace std;


void displayFilms(){
    cout << "Available Films\n\n";
    list<string> films = {"Avengers", "Batman", "Spiderman"};
    list<int> length ={125, 130, 95};


    auto it1 = films.begin();
    auto it2 = length.begin();


    while (it1 != films.end() && it2 != length.end()) {
        cout << *it1 << " - " << *it2 << "\n";
        it1++;
        it2++;
    }

}

int main() {

    displayFilms();

}