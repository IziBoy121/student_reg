#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "student.hpp"

using namespace std;

string capLength( string&, int );

int main (int argc, char * const argv[]) {
	
	string fileName;
	cout << "Enter a valid file path (relative or absolute): ";
	cin >> fileName;
	
	ifstream file;
	file.open( fileName.c_str() );
	if( !file.is_open() ){
		cerr << "File Error!!! Failing hard and fast\n";
		exit(EXIT_FAILURE);
	}
	
	Student bueler;
	string temp;
	int tempi;
	
	while (!file.eof()) {
		
		getline( file, temp );
		bueler.setFirstName(temp);
		
		getline( file, temp );
		bueler.setLastName(temp);
		
		getline( file, temp );
		bueler.setAddress(temp);
		
		if( ( file >> tempi) || cin.peek() != '\n' ){
		bueler.setID(tempi);
		} else {
			cerr << "Invalid ID\n";
			cin.clear();
			cin.ignore(30000, '\n');
		}

		if( ( file >> tempi) || cin.peek() != '\n' ){
			bueler.setCreditsCompleted(tempi);
		} else {
			cerr << "Invalid Credit Value\n";
			cin.clear();
			cin.ignore(30000, '\n');
		}
		
		if( ( file >> tempi) || cin.peek() != '\n' ){
			bueler.setQualityPoints(tempi);
		} else {
			cerr << "Invalid Quality Point Value\n";
			cin.clear();
			cin.ignore(30000, '\n');
		}
		
		bueler.display();
		
	}
	
	
	
#ifdef _WIN32
	system("PAUSE");
#endif
	
  return 0;
}

