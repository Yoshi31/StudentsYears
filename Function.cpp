#include "Function.h"
#include "Film.h"
#include <iostream>

string name_value;
string genre_value;
float ratting_value;
int price_value;

void addfilm(string fileName) {
    Film* film;
    film = new Film;
    film->ScanFilm();
    int c;
    cout << "Âû äåéñòèòåëüíî õîòèòå äîáàâèòü ýòîò ôèëüì?" << endl;
    film->Print();
    cout << "1)Äà" << endl << "2)Íåò" << endl;
    cin >> c;
    switch (c)
    {
    case 1:
        film->Putinfile(string(argv[1]));
        cout << "Ôèëüì óñïåøíî äîáàâëåí â áàçó äàííûõ êèíîòåàòðà" << endl;
        break;
    case 2:
        cout << "Ôèëüì íå áóäåò äîáàâëåí â áàçó äàííûõ êèíîòåàòðà";
        exit(0);
    default:
        cout << "Îøèáêà" << endl;

    }
    delete film;

}

void deletefilm(string fileName) {
    cout << "Ââåäèòå íàçâàíèå ôèëüìà äëÿ óäàëåíèÿ" << endl;
    string deletename;
    string archiv;
    cin >> deletename;
    fstream file;
    int n, s = 0;
    Film *film;
    film = new Film;
    file.open(fileName);
    if (!file) {
        cout << "Îøèáêà ðàáîòû ñ ôàéëîì" << endl;
        return;
    }
    file.seekg(0, ios_base::end);
    n = file.tellg();
    file.seekg(0);
    do
    {
        Film* film;
        film = new Film;
        file >> *film;
        //file >> name_value >> genre_value >> ratting_value >> price_value;
        //film->SetFilm(name_value, genre_value, ratting_value, price_value);
        s = file.tellg();
        if (deletename != film->GetName()) 
        {
            string rattingstr = to_string(film->GetRatting());
            string pricestr = to_string(film->GetPrice());

            archiv += film->GetName() + " " + film->GetGenre() + " " + rattingstr + " " + pricestr + "\n";
        }
        delete film;

    } while (s < n - 4);
    file.close();
    file.open(fileName);
    if (!file) {
        cout << "Îøèáêà ðàáîòû ñ ôàéëîì" << endl;
        return;
    }
    file << archiv;
    file.close();
    cout << "Ôèëüì áûë óñïåøíî óäàëåí!" << endl;
}

void searchfilm() {
    cout << "Ïîèñê ôèëüìîâ ïî:" << endl << "1)Íàçâàíèþ" << endl << "2)Æàíðó" << endl;
    int c;
    cin >> c;
    switch (c)
    {
    case 1:
        searchfilm_name(string(argv[1]));
        break;
    case 2:
        searchfilm_genre(string(argv[1]));
        break;
    default:
        cout << "Îøèáêà" << endl;

    }
}

void searchfilm_name(string fileName) {
    string check;
    cout << "Ââåäèòå íàçâàíèå ôèëüìà äëÿ ïîèñêà" << endl;
    cin >> check;
    ifstream file;
    int n, s = 0;
    char c;
    Film *film;
    film = new Film;
    file.open(fileName);
    if (!file) {
        cout << "Îøèáêà ðàáîòû ñ ôàéëîì" << endl;
        return;
    }
    file.seekg(0, ios_base::end);
    n = file.tellg();
    file.seekg(0);
    cout << "Ñïèñîê ôèëüìîâ ïî âàøåìó çàïðîñó:" << endl;
    do
    {
        file >> *film;
       // >> name_value >> genre_value >> ratting_value >> price_value;
      // film->SetFilm(name_value, genre_value, ratting_value, price_value);
        s = file.tellg();
        if (film->GetName() == check) {
            film->Print();
        }



    } while (s < n - 4);
    file.close();
}

void searchfilm_genre(string fileName) {
    string check;
    cout << "Ââåäèòå æàíð ôèëüìà äëÿ ïîèñêà" << endl;
    cin >> check;
    ifstream file;
    int n, s = 0;
    char c;
    Film *film;
    film = new Film;
    file.open(fileName);
    if (!file) {
        cout << "Îøèáêà ðàáîòû ñ ôàéëîì" << endl;
        return;
    }
    file.seekg(0, ios_base::end);
    n = file.tellg();
    file.seekg(0);
    cout << "Ñïèñîê ôèëüìîâ ïî âàøåìó çàïðîñó:" << endl;
    do
    {
        file >> *film;
        //file >> name_value >> genre_value >> ratting_value >> price_value;
       // film->SetFilm(name_value, genre_value, ratting_value, price_value);
        s = file.tellg();
        if (film->GetGenre() == check) {
            film->Print();
        }



    } while (s < n - 5);
    file.close();
}

void listfilm(string fileName) {
    fstream file;
    int n, s = 0;
    Film *film;
    film = new Film;
    file.open(fileName);
    if (!file) {
        cout << "Îøèáêà ðàáîòû ñ ôàéëîì" << endl;
        return;
        
    }
    file.seekg(0, ios_base::end);
    n = file.tellg();
    file.seekg(0);
    do
    {
        file >> *film;
        film->Print();
        s = file.tellg();



    } while (s < n - 5);
    file.close();
}

void changefilm(string fileName) {
    string changename;
    string archive;
    cout << "Ââåäèòå íàçâàíèå ôèëüìà êîòîðûé õîòèòå èçìåíèòü: ";
    cin >> changename;
    fstream file;
    int n, s = 0;
    char c;
    Film* film;
    film = new Film;
    file.open(fileName);
    if (!file) {
        cout << "Îøèáêà ðàáîòû ñ ôàéëîì" << endl;
        return;
    }
    file.seekg(0, ios_base::end);
    n = file.tellg();
    file.seekg(0);
    do {
        file >> *film;
        s = file.tellg();
        if (changename == film->GetName()) {
            film->Print();
            cout << "×òî âû õîòèòå èçìåíèòü?"<<endl;
            cout << "1)Íàçâàíèå" << endl << "2)Æàíð" << endl << "3)Ðåéòèíã" << endl << "4)Ñòîèìîñòü áèëåòà" << endl;
            int c;
            cin >> c;
            string newname;
            string newgenre;
            float newratting;
            int newprice;
            string rattingstr = to_string(film->GetRatting());
            string pricestr = to_string(film->GetPrice());
            switch (c)
            {
            case 1:
                cout<<"Ââåäèòå íîâîå íàçâàíèå: ";
                cin >> newname;
                archive += newname + " " + film->GetGenre() + " " + rattingstr + " " + pricestr + "\n";
                cout << "Íàçâàíèå ôèëüìà óñïåøíî èçìåíåíî!"<<endl;
                break;
            case 2:
                cout << "Ââåäèòå íîâûé æàíð: ";
                cin >> newgenre;
                archive += film->GetName() + " " + newgenre + " " + rattingstr + " " + pricestr + "\n";
                cout << "Æàíð ôèëüìà óñïåøíî èçìåíåí!" << endl;
                break;
            case 3:
                cout << "Ââåäèòå íîâûé ðåéòèíã: ";
                cin >> newratting;
                rattingstr = to_string(newratting);
                archive += film->GetName() + " " + film->GetGenre() + " " + rattingstr + " " + pricestr + "\n";
                cout << "Ðåéòèíã ôèëüìà óñïåøíî èçìåíåí!" << endl;
                break;
            case 4:
                cout << "Ââåäèòå íîâóþ ñòîèìîñòü: ";
                cin >> newprice;
                pricestr = to_string(newprice);
                archive += film->GetName() + " " + film->GetGenre() + " " + rattingstr + " " + pricestr + "\n";
                cout << "Ñòîèìîñòü ôèëüìà óñïåøíî èçìåíåíà!" << endl;
                break;
            default:
                cout << "Îøèáêà" << endl;

            }
        }
        else {
            string rattingstr = to_string(film->GetRatting());
            string pricestr = to_string(film->GetPrice());

            archive += film->GetName() + " " + film->GetGenre() + " " + rattingstr + " " + pricestr + "\n";
        }
    } while (s < n - 5);
    file.close();
    file.open(fileName);
    if (!file) {
        cout << "Îøèáêà ðàáîòû ñ ôàéëîì" << endl;
        return;
    }
    file << archive;
    file.close();
}

ostream& operator<<(ostream& os, const Film& film) {
    os << film.name << " " << film.genre << " " << film.ratting << " " << film.price << "\n";
    return os;
}

istream& operator>>(istream& is, Film& film) {
    is >> film.name >> film.genre >> film.ratting >> film.price;
    return is;
}
int menu_select()
{
    char s[80];
    int c;
    do
    {
        cout << "---------------------------------------------------------------------------------------------------------------" << endl;
        cout << "1 - Äîáàâèòü ôèëüì" << endl << "2 - Ñïèñîê ôèëüìîâ" << endl << "3 - Ïîèñê ôèëüìà" << endl << "4 - Óäàëèòü ôèëüì" << endl << "5 - Èçìåíèòü ôèëüì" << endl << "6 - âûõîä" << endl << "Âàø âûáîð: ";
        cin >> s;
        c = atoi(s);
        cout << "---------------------------------------------------------------------------------------------------------------" << endl;
    } while (c < 0 || c>6);
    return c;
}
