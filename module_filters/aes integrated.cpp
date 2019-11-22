//============================================================================
// Name        : aes.cpp
// Author      : Akhil Gudge Subramanya
// Version     :
// Copyright   : Your copyright notice
// Description : Integrated AES key search
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

vector<string> myvector;

string GetBinaryStringFromHexString (string sHex)
{
	string sReturn = "";
	for (int i = 0; i < sHex.length (); ++i)
	{
		switch (sHex [i])
		{
			case '0': sReturn.append ("0000"); break;
			case '1': sReturn.append ("0001"); break;
			case '2': sReturn.append ("0010"); break;
			case '3': sReturn.append ("0011"); break;
			case '4': sReturn.append ("0100"); break;
			case '5': sReturn.append ("0101"); break;
			case '6': sReturn.append ("0110"); break;
			case '7': sReturn.append ("0111"); break;
			case '8': sReturn.append ("1000"); break;
			case '9': sReturn.append ("1001"); break;
			case 'a': sReturn.append ("1010"); break;
			case 'b': sReturn.append ("1011"); break;
			case 'c': sReturn.append ("1100"); break;
			case 'd': sReturn.append ("1101"); break;
			case 'e': sReturn.append ("1110"); break;
			case 'f': sReturn.append ("1111"); break;
		}
	}
	return sReturn;
}

string ToHex(string abc)
{
	if(abc == "0000"){return "0";}
	else if (abc == "0001"){return "1";}
	else if (abc == "0010"){return "2";}
	else if (abc == "0011"){return "3";}
	else if (abc == "0100"){return "4";}
	else if (abc == "0101"){return "5";}
	else if (abc == "0110"){return "6";}
	else if (abc == "0111"){return "7";}
	else if (abc == "1000"){return "8";}
	else if (abc == "1001"){return "9";}
	else if (abc == "1010"){return "a";}
	else if (abc == "1011"){return "b";}
	else if (abc == "1100"){return "c";}
	else if (abc == "1101"){return "d";}
	else if (abc == "1110"){return "e";}
	else return "f";
}

string BinaryToHexWithUnderscore(string str1)
{
	string str2,str3,str4,str5,str6;
	int i=0;int j=0;
	for(i=str1.length()-1;i>=0;i--)
	{
		str2=str1[i]+str2;
		if(str2.length()==4)
		{
			str3 = str2;
			str2 = "";
			str4 = ToHex(str3) + str4;
//			cout << str3 <<" " <<  str4 << endl;
		}

	}
	if((str2.length()<4) && (str2.length()>0))
	{
		while(str2.length()<4)
		{
			str2='0'+str2;
		}
		str4 = ToHex(str2) + str4;
//		cout <<str2 << " " << str4 << endl;
	}
	for(j=str4.length()-4;j>=0;j=j-4)
	{
		if(j!=0){
		str5 = '_' + str4.substr(j,4);
		str6 = str5 +str6;
		str5="";
//		cout << str3 << endl;
		}
		else
		{
			str5 = str4.substr(j,4);
			str6 = str5 +str6;
			str5="";
		}
	}
	if(str4.length()%4!=0)
	{
		str6 = str4.substr(0,str4.length()%4) + str6;
	}
	//cout << str3 << endl;
	return str6;
}

void sequence_gen(string str)
{
	ofstream file;
	string str4,str5,str6,str8;
	string str7="";
	string str2="";
	string str3;
	int block_size=0;
	int start_pos=0;
	int i=0,l=0;
	file.open ("example.txt", ios::out | ios::app);
	for(block_size=64;block_size<=str.length();block_size++)
	{
		for(start_pos=0;start_pos<(str.length()-block_size+1);start_pos++)
		{
			for(i=start_pos;i<str.length();i++)
			{
				if(str2.size()< block_size)
				{
					str2+=str[i];
					l++;
					//cout << hex <<l<< endl;
				}
				if(str2.length()==block_size)
				{
					str3 = str2;
					//myvector.push_back(str3);
					//cout << str2 << endl;
					str2="";
					//file << str3 << " block_size " << block_size << " starting point " << start_pos<< '\n';
					str4 = BinaryToHexWithUnderscore(str3);
					file << str4 << '\n';
					myvector.push_back(str4);
					break;
				}
			}
		}
	}
	file.close();
}

int main() {
	string str1,str2,str3;
	ifstream myfile;
	myfile.open("key.txt");
	getline(myfile,str1);
	myfile.close();
	cout << str1 << endl;  // str1 has the hex string read from the file
	for(int i=0;i<str1.length();i++) // For loop to remove '_' from the hex string
	{
		if(str1[i]=='_')
		{
			//cout << "Eureka: " << i << endl;
			continue;
		}
		else str2+=str1[i];

	}
	cout << str2 << endl;  // str2 has the hex string without the '_'
	str3 = GetBinaryStringFromHexString(str2); // Convert hexadecimal string to binary string
	cout << str3 << endl;
	int l = str3.length();
	//cout << l << " " << str3.size() << endl;
	cout << "" << endl;
	sequence_gen(str3);
	cout << myvector.size() << endl;

	return 0;
}
