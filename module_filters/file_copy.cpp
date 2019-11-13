//============================================================================
// Name        : file_copy.cpp
// Author      : Akhil Gudge Subramanya
// Version     :
// Copyright   : Your copyright notice
// Description : Copying data from one file to another.
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
	string line;
	string str1,str2;
	cout << "Enter the source file:" << endl;
	cin >> str1;
	cout << "Enter the target file:" << endl;
	cin >> str2;
	ifstream myfile;
	ofstream file;
	myfile.open(str1);
	file.open(str2);
	while(!myfile.eof())
	{
		getline(myfile,line);
		file << line << '\n';
	}
	cout << "File copy successful"<<endl;
	myfile.close();
	file.close();

	return 0;
}
