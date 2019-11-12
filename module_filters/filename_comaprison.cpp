//============================================================================
// Name        : filename_comaprison.cpp
// Author      : Akhil Gudge Subramanya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
	string line;
	string str1= "rom2.sv"; // String to store the file name and it remains same until a new filename is encountered while reading from filename.txt
	ifstream myfile;
	myfile.open("filename.txt");
	if(myfile.is_open())
	{
		while(getline(myfile,line))
		{
			if(line != str1)
			{
				str1 = line;
				cout << str1 << endl;

			}
			else continue;
		}
		myfile.close();
	}
	//cout << str1 <<endl;

	return 0;
}
