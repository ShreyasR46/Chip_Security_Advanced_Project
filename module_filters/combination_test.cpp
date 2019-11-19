//============================================================================
// Name        : combination_test.cpp
// Author      : Akhil Gudge Subramanya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main() {
	string str1 = "101100";
	string str2="";
	string str3;
	vector<string> myvector;
	int m=0;
	int i,k,l=0;
	int block_size=0;
	k = str2.length();
	//cout << k << endl;
	//int l=0;
	int start_pos=0;
//	while(j<str1.length()-1)
//	{
//		for(i=j;i<6;i++)
//		{
//			if(str2.size()<2)
//			{
//				str2+=str1[i];
//				l++;
//				//cout << hex <<l<< endl;
//			}
//			else if(str2.length()==2)
//			{
//				str3 = str2;
//				cout << str2 << endl;
//				str2="";
//				//cout << str3 <<endl;
//			}
//		}
//
//		//cout << str2 << endl;
//		j++;
//	}
	for(block_size=2;block_size<=str1.length();block_size++){
	for(start_pos=0;start_pos<(str1.length()-block_size+1);start_pos++){
	for(i=start_pos;i<str1.length();i++)
	{
		if(str2.size()< block_size)
		{
			str2+=str1[i];
			l++;
			//cout << hex <<l<< endl;
		}
		if(str2.length()==block_size)
		{
			str3 = str2;
			myvector.push_back(str3);
			//cout << str2 << endl;
			str2="";
			cout <<hex << str3 << " block_size " << block_size << " starting point " << start_pos<< endl;
			break;
		}
	}
	}
	}



	return 0;
}
