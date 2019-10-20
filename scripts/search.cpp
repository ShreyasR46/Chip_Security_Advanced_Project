#include<stdio.h>
#include<iostream>
#include <bits/stdc++.h>
#include<string>

#define AUTO
#define DEBUG

using namespace std;

/*class search{
	public:

};*/

int main()
{
	string path_to_search, keyword, filename_to_save;
#ifdef AUTO
	path_to_search = "/home/parallels/Documents/Chip_Security_Advanced_Project/ariane/";
	keyword = "\"secure_reg\"";
	filename_to_save = "search_results.txt";
#else
	cout<<"Provide the path to search: "<<"\n";
        //cin.getline(filename);
        cin>>path_to_search;
        cout<<"Give the keyword to search: "<<"\n";
        cin>>keyword;
        cout<<"Give the keyword to save data: "<<"\n";
        cin>>filename_to_search;

#endif

	string command1 = "grep -R";
	command1 = command1 + " " + keyword + " " + path_to_search + " " +  ">" + " " + filename_to_save;
	cout<<"The command executed is: "<<command1<<"\n";
	const char *command = command1.c_str();
	cout << "Compiling file using " << command << endl; 
   	system(command);
	return 0;
}
