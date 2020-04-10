#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
using namespace std;

int main()
{
	string s1, s2;
	int c, n, k;
    char filename1[15], filename2[15];
    ifstream file1;
    ofstream file2;
    cout << "Vvedite nazvanie faila so strokoy"<<endl;
    cin >> filename1;
	file1.open(filename1);
	if (!file1.is_open()) {
		cout << "Error" << endl;

	}
	else {
		cout << "File is open" << endl;

	}
	file1 >> s1;
	c = s1.length();
	
	cout << "Vvdeite nomera pervogo i poslednego simvola dlya udaleniya" << endl;
	cin >> n;
	cin >> k;
	if ((n >= 0) && (k >= n)&&(c>=k)) {
		cout << "normal rabotaem" << endl;
		s2 = s1.erase(n-1, k - n+1);
		cout << "Vvedite nazvanie faila dlya vivoda" << endl;
		cin >> filename2;
		file2.open(filename2);
		if (!file2.is_open()) {
			cout << "Error" << endl;

		}
		else {
			cout << "File is open or created" << endl;

		}
		file2 << s2;
	}
	else cout << "Udalenie ne vozmozhno, dlina stroki: "<<c << endl;
}

