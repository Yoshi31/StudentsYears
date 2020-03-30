#include <fstream>
#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, const char * argv[])
{
	int c, min, max;
	//char filename1[15], filename2[15];
	ifstream file1;
	ofstream file2;
	//cout << "Enter file name 1" << endl;
	//cin >> filename1;
	file1.open(argv[1]);
	if (!file1.is_open()) {
		cout << "Error" << endl;

	}
	else {
		cout << "File is open" << endl;

	}
	file1 >> c;
	max = c;
	min = c;
	while (!file1.eof()) {
		file1 >> c;
		if (c >= max) {
			max = c;
		}
		else if (c <= min) {
			min = c;
		}
	
	}
	file1.close();
	file1.open(argv[1]);
	//fseek(file1, 0, SEEK_SET);
	//rewind(file1);
	//cout << "Enter file name 2"<<endl;
	//cin >> filename2;
	file2.open(argv[2]);
	if (!file2.is_open()) {
		cout << "Error" << endl;

	}
	else {
		cout << "File is open" << endl;

	}
	file2 << min<<" ";
	while (!file1.eof()) {
		file1 >> c;
		if (c != min && c!=max) {
			file2 << c << " " ;
		}
	}
	file2 << max << " ";
	file1.close();
	file2.close();
}
