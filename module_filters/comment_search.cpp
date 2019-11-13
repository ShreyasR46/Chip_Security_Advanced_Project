/*
 * comment_search.cpp
 *
 *  Created on: Nov 11, 2019
 *      Author: ags58
 */
////////Not Required Anymore
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str1;
	cout << "Enter the string:" << endl;
	getline(cin, str1);
	int i,j;
	for(i=0,j=1;i<str1.length(),j<str1.length();i++,j++)
	{
		if(str1[i]=='/' && str1[j]== '/')
		{
			cout << "EUREKA" << endl;
			break;
		}
		else cout << "Comments not found" << endl;;

	}
	return 0;
}


