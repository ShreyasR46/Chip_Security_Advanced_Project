#include<stdio.h>
#include<iostream>
#include <fstream>
#include <stdlib.h>
#include <cstring>
#include<string>
#include"searcher.h"

#define AUTO
#define _GNU_SOURCE



using namespace std;
const char *fp = "property_definition.txt";

//searcher t1;

class Node  
{  
    public: 
    char type;
    int number;
    string name;  
    Node *next;  
}; 

void printList(Node* n) 
{ 
    while (n != NULL) 
    { 
        cout << n->type<< ": "<<n->number<<".) "<<n->name<<"\n"; 
        n = n->next; 
    }
}

void deleteList(Node** head_ref)  
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

void append(Node*& p, char t, int n, string d)
{
    Node* temp = new Node();
    temp->type=t;
    temp->number=n;
    temp->name=d;
    if(p == NULL) p = temp;
    else append(p->next,t,n,d);
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
    //std::cout<<"I am here outside function"<<"\n";

    //Node* head = NULL;
    //head = new Node();
    //head->next = NULL;

    void open_property_file(const char *filename)
    {
	string header;
	string line;
	string header_value;
	string header_number;
	string module_category;
	string module_name;
	string module_type;
	string key_name;
	string key_value;
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
					case'%':state=2;break;
					case'#':state=3;cout<<"state_changed to: "<<state<<"\n";break;
					case';':state=4;break;
					//default: state=0;
				}
				cout<<line[i]<<", ";
				if(state == 4)
				{
					cout<<"The header values are: "<<header_value<<"\n";
					if(header.compare("MODULE_TYPE") == 0){cout<<"into the module type: "<<header<<"\n";module_category = header_value;header_value.clear();header.clear();}
					if(header.compare("MODULE_NAME") == 0){module_name = header_value;header_value.clear();header.clear();}
					if(header.compare("INPUT_NUMBER") == 0){input_number = stoi(header_value);header_value.clear();header.clear();}
					if(header.compare("OUTPUT_NUMBER") == 0){output_number = stoi(header_value);header_value.clear();header.clear();}
					if(header.compare("KEY_NAME") == 0){key_name = header_value;header_value.clear();header.clear();}
					//if(header.compare("INPUT_NAME") == 0){append(head,'I',stoi(header_number),header_value);}
					//if(header.compare("OUTPUT_NAME") == 0){append(head,'O',stoi(header_number),header_value);}

				}
			}	
		}
		cout<<"the module category is: "<<module_category<<"\n";
		cout<<"the module name is: "<< module_name<<"\n";
		cout<<"the input number is: "<< input_number<<"\n";
		cout<<"the output number is: "<<output_number<<"\n";
	}
        
    }
};


int main()
{
	searcher object1;
	int result = 44;
	propertyDefinition properties;
        
	
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
  return 0;
}
