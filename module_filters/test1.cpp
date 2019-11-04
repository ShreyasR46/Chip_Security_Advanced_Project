#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

int main()
{

//	vector<int> size_b;
//	vector<string> str;
//	vector<string>::iterator it1;
//	it1 = str.begin();
	cout << "1st fine"<<'\n';
	string line;
	ifstream myfile ("data.text");
//	int i=0;
//	myfile.open("xyz.txt");
	cout << "2nd fine" << '\n';
	if(myfile.is_open())
	{
		while(getline(myfile,line))
		{
			cout << line << '\n';
		}
		myfile.close();
	}
	else cout << "Not opening"<<'\n';
	return 0;	
}

