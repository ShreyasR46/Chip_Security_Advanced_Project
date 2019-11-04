#include<iostream>
#include<fstream>
#include<vector>
#include<stdio.h>
#include<math.h>

using namespace std;


class read_f2
{
	public:
	string line;
	ifstream myfile;
	void read_f2()
	{
		vector<int> size_b;
		vector<string> line;
		myfile.open("data.txt");
		if(myfile.is_open())
		{
			while(getline(myfile,line))
			{
				
			}
		}	
	}
};
