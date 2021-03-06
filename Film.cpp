#include "Film.h";
#include <string>
#include <iostream>

Film::Film() {
    name = "Null";
    genre = "Null";
    ratting = 0;
    price = 0;
}

void Film::SetFilm(string name_value, string genre_value, float ratting_value, int price_value) {
    name = name_value;
    genre = genre_value;
    ratting = ratting_value;
    price = price_value;
}
string Film::GetName() {
    return name;
}

string Film:: GetGenre() {
    return genre;
}

float Film::GetRatting() {
    return ratting;
}

int Film::GetPrice() {
    return price;
}

void Film:: ScanFilm() {
    setlocale(LC_CTYPE, "Russian");
    cout << "ÍÎÂÛÉ ÔÈËÜÌ" << endl << "Ââåäèòå äàííûõ î ôèëüìå" << endl;
    cout << "Íàçâàíèå:" << endl;
    cin >> name;
    cout << "Æàíð:" << endl;
    cin >> genre;
    cout << "Ðýéòèíã:" << endl;
    cin >> ratting;
    cout << "Öåíó çà áèëåò:" << endl;
    cin >> price;
};

void Film::Print() {
    setlocale(LC_CTYPE, "Russian");
    cout << "Íàçâàíèå: " << name << "\t Æàíð: " << genre << "\t Ðýéòèíã: " << ratting << "\t Öåíà: " << price << endl;
}

void Film::Putinfile(string fileName) {
    ofstream file;
    file.open(fileName, ios_base::app);
    if (!file) {
        cout << "Îøèáêà ðàáîòû ñ ôàéëîì" << endl;
        return;
    }
    file << name << " ";
    file << genre << " ";
    file << ratting << " ";
    file << price << " " << endl;
    file.close();
}


