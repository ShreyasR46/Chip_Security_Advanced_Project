#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<fstream>

using namespace std;

class read_file
{
	//string line;
    public:	
	void rf()
	{
		string line;
		string temp;
		ifstream myfile;
		myfile.open("xyz.text");
		if(myfile.is_open())
		{
			while(getline(myfile,line))
			{
				//cout << line << '\n';
				for(string::iterator it = line.begin();it!=line.end();++it)
				{
					temp = *it;
					if(temp =="m")
					{
						cout << "EUREKA!!!"<<endl;
						break;		
					}
					//else cout << *it;
				}
			}
			myfile.close();
		}
		else cout << "not opening";	
		
	}
};


int main()
{
	read_file obj1;
	obj1.rf();
	return 0;
}
