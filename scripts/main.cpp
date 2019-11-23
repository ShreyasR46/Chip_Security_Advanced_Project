#include<stdio.h>
#include<iostream>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include <cstring>
#include<string>
#include"searcher.h"
#include <vector>
#include <sstream>
//#include <bits/stdc++.h>

#define AUTO
#define _GNU_SOURCE

using namespace std;
const char *fp = "property_definition.txt";

//searcher t1;

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

class Node  
{  
    public: 
    char type;
    int number;
    string name;  
    Node *next;  
}; 

class LinkedList
{
  public:
	int length;
	Node *head;
	LinkedList();
    	~LinkedList();
	void deleteList(Node** head_ref);
	void print();
	void append(char t, int n, string d); 
};

LinkedList::LinkedList(){
    this->length = 0;
    this->head = NULL;
}

LinkedList::~LinkedList(){
    std::cout << "LIST DELETED";
}

void LinkedList::print(){
    Node* head = this->head;
    int i = 1;
    //cout<<"into head";
    while(head){
        cout << i << ".) " <<head->type<<", "<<head->number<<", "<<head->name<<", " << std::endl;
        head = head->next;
        i++;
    }
}

void LinkedList::deleteList(Node** head_ref)  
{      
// deref head_ref to get the real head 
Node* current = *head_ref;  
Node* next;  
  
while (current != NULL)  
{  
    next = current->next;  
    free(current);  
    current = next;  
}       
// deref head_ref to affect the real head back  
//    in the caller. 
*head_ref = NULL;  
}

void LinkedList::append(char t, int n, string d)
{
    Node* temp = new Node();
    temp->type=t;
    temp->number=n;
    temp->name=d;
    //if(p == NULL) p = temp;
    //else append(p->next,t,n,d);
    temp->next = this->head;
    this->head = temp;
    this->length++;
}   

class propertyDefinition : public searcher
{
  public:
  //t1.path_to_search = "~/Documents/Github_Directories/Chip_Security_Advanced_Project/ariane/";
  //t1.keyword = "\"aes\"";
    long int nread;
    long temp;
    //size_t len = 0; 
    string header;
    string number;
    string value;
    string header_value;
    string header_number;
    string module_category;
    string module_name;
    string module_type;
    string key_name;
    string key_value;

    //std::cout<<"I am here outside function"<<"\n";
    LinkedList* list = new LinkedList();

    Node* head = NULL;
    //head = new Node();
    //head->next = NULL;
    //searcher key_search;

    void open_property_file(const char *filename)
    {
	string header;
	string line;
	unsigned int input_number;
	unsigned int output_number;
	int state = 0;
	ifstream property;
        property.open(filename, ios::in);
	//propertyDefinition obj;
	//property.read((char *)&obj, sizeof(obj));
	cout<<"I am here"<<"\n";
        if(property == NULL)
	{
		perror("Error opening File of proprty_definition. ");
	}
        else
	{
		while(getline(property,line))
		{
			cout<<"The line read here is : "<<line<<"\n";
			state = 0;
			for(int i=0;line[i] != '\0';i++)
			{
				if(state == 1 && line[i] != '%' && line[i] != '#' && line[i] != ';' && line[i] != '$')
				{
					header.append(line,i,1);
					cout<<header<<"\n";
				}
				if(state == 2 && line[i] != '%' && line[i] != '#' && line[i] != ';' && line[i] != '$')
				{
					header_number.append(line,i,1);
					cout<<header_number<<"\n";
				}
				if(state == 3 && line[i] != '%' && line[i] != '#' && line[i] != ';' && line[i] != '$')
				{
					header_value.append(line,i,1);
					
					
				}
				switch(line[i])
				{
					case'$':state=1;break;
					case'%':state=2;cout<<"state_changed to: "<<state<<"\n";break;
					case'#':state=3;cout<<"state_changed to: "<<state<<"\n";break;
					case';':state=4;cout<<"state_changed to: "<<state<<"\n";break;
					//default: state=0;
				}
				cout<<line[i]<<", ";
				if(state == 4)
				{
					cout<<"The header values are: "<<header_value<<"\n";
					if(header.compare("MODULE_TYPE") == 0){cout<<"into the module type: "<<header<<"\n";module_category = header_value;header_value.clear();header.clear();}
					if(header.compare("MODULE_NAME") == 0){module_name = header_value;header_value.clear();header.clear();header_number.clear();}
					if(header.compare("INPUT_NUMBER") == 0){input_number = stoi(header_value);header_value.clear();header.clear();header_number.clear();}
					if(header.compare("OUTPUT_NUMBER") == 0){output_number = stoi(header_value);header_value.clear();header.clear();header_number.clear();}
					if(header.compare("KEY_NAME") == 0){key_name = header_value;header_value.clear();header.clear();header_number.clear();}
					if(header.compare("KEY_VALUE") == 0){key_value = header_value;header_value.clear();header.clear();header_number.clear();}
					if(header.compare("INPUT_NAME") == 0){list->append('I',stoi(header_number),header_value);header_value.clear();header.clear();header_number.clear();}
					if(header.compare("OUTPUT_NAME") == 0){list->append('O',stoi(header_number),header_value);header_value.clear();header.clear();header_number.clear();}
				}
			}	
		}
		cout<<"the module category is: "<<module_category<<"\n";
		cout<<"the module name is: "<<module_name<<"\n";
		cout<<"the input number is: "<<input_number<<"\n";
		cout<<"the output number is: "<<output_number<<"\n";
		cout<<"the key name is: "<<key_name<<"\n";
		cout<<"the key value is: "<<key_value<<"\n";

		cout<<"the IO ports are: "<<"\n";
		cout<<""<<"";
		list->print();

		//key_search.grep_search_and_store("key", , string filename_to_save_local)

	}
        
    }
};


int main()
{
	searcher object1;
	searcher object2;
	int result = 44;
	propertyDefinition properties;
        string str1,str2,str3;
	
#ifdef AUTO
	object1.path_to_search = "~/Documents/Github_Directories/Chip_Security_Advanced_Project/ariane/";
  	object1.keyword = "\"aes\"";
  	object1.filename_to_save = "search_results.txt";
	
	result = object1.grep_search_and_store(object1.keyword, object1.path_to_search, object1.filename_to_save);
	object1.search_and_divide("filename.txt", "data.txt", "search_results.txt");
	properties.open_property_file(fp);
#else
  	object1.take_input();
  	result = object1.grep_search_and_store(object1.keyword, object1.path_to_search, object1.filename_to_save);
  	object1.search_and_divide("filename.txt", "data.txt", "search_results.txt");
#endif
	str3 = GetBinaryStringFromHexString(properties.key_value); // Convert hexadecimal string to binary string
	//cout << str3 << endl;
	int l = str3.length();
	//cout << l << " " << str3.size() << endl;
	//cout << "" << endl;
	sequence_gen(str3);
	//cout <<myvector<<endl;
	for (int i = 0; i < myvector.size() ; i++)
	{
		//cout<<myvector.at(i)<<"\n";
		object2.path_to_search = "~/Documents/Github_Directories/Chip_Security_Advanced_Project/ariane/";
  		object2.keyword = myvector.at(i);
  		object2.filename_to_save = "results_for_sequence.txt";
		result = object2.grep_search_and_store(object2.keyword, object2.path_to_search, object2.filename_to_save);
		object2.search_and_divide("filename_for_sequences.txt", "data_for_sequences.txt",object2.filename_to_save);
		if(object2.empty_file == 1) break;
		//cout << result<<endl;

	}
	
	
  return 0;
}
