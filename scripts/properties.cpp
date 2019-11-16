#include<stdio.h>
#include<iostream>
#include<string>

#define AUTO

using namespace std;

class searchClass;  //declarartion
class propertiesDefinition;
class module_analysis;

class searchClass
{
  public: 
// This area is to assign the search strings at the default values  
#ifdef AUTO
    string path_to_search, keyword, filename_to_save;
#endif    
    
   //member fuinction declaration
   void take_input()
   {
      string path_to_search, keyword, filename_to_save;
      cout<<"Provide the path to search: "<<"\n";
      //cin.getline(filename);
      cin>>path_to_search;
      cout<<"Give the keyword to search: "<<"\n";
      cin>>keyword;
      cout<<"Give the file where to save data: "<<"\n";
      cin>>filename_to_save;
   }

   int grep_search_and_store(string keyword_local, string path_to_search_local, string filename_to_save_local )
   {
      string command1 = "grep -R";
      command1 = command1 + " " + keyword_local + " " + path_to_search_local + " " +  ">" + " " + filename_to_save_local;
      cout<<"The command executed is: "<<command1<<"\n";
      const char *command = command1.c_str();
      cout << "Compiling file using " << command << endl; 
      return system(command);
   }

   void search_and_divide(const char *filename_name, const char *data_name, const char *dictionary_name)
   { 
	char dot_sv = ':';
	FILE *dictionary, *filename, *data;
	long int n =0;
    	long int total_lines=0, flag = 0,i = 0, k =0;
    	char ct = '`';
   	char *line = NULL;
   	size_t len = 0;
    	long int offset = 2;
    	int counter=0;
        long int alphabet_array[27];
        long int temp=0, nread;


      	filename = fopen(filename_name,"w");
	data = fopen(data_name,"w");
	dictionary = fopen(dictionary_name, "r");
  	if(dictionary == NULL)
  	{
		perror ("Error opening file.");
 	}
	else
	{
		while((nread= getline(&line,&len,dictionary))!=-1)
		{
			cout<<"The nread value is: "<<nread<<"\n";
			printf("length = %ld: \n total length = %ld\n\n\n", nread, temp);
			for(int i=0,flag=0;i<nread;i++)
			{		
				if(flag == 1)
				{	
					putc(line[i], data);
					cout<<line[i];
				}
				if(dot_sv == line[i] && (flag == 0))
				{
					flag = 1;
					putc('\n', filename);
					putc('\r', filename);
					cout<<"\n\r";
				}
				if(flag == 0)
				{
					putc(line[i], filename);
					cout<<line[i];
				}
			}
			cout<<"\n\r";
		}
	}
  	free(line); 
  	fclose(dictionary);
	fclose(filename);
	fclose(data);
   }   
};

class propertyDefinition
{
  //searchClass t1;
  //t1.path_to_search = "~/Documents/Github_Directories/Chip_Security_Advanced_Project/ariane/";
  //t1.keyword = "\"aes\"";
  public: 
    void open_property_file()
    {
	FILE *property;
        
        
    }
};



int main()
{
  searchClass object1;
  object1.path_to_search = "~/Documents/Github_Directories/Chip_Security_Advanced_Project/ariane/";
  object1.keyword = "\"aes\"";
  object1.filename_to_save = "search_results.txt";
  
  int result = 44;
#ifdef AUTO
  result = object1.grep_search_and_store(object1.keyword, object1.path_to_search, object1.filename_to_save);
  object1.search_and_divide("filename.txt", "data.txt", "search_results.txt");
#else
  object1.take_input();
  result = object1.grep_search_and_store(object1.keyword, object1.path_to_search, object1.filename_to_save);
  object1.search_and_divide("filename.txt", "data.txt", "search_results.txt");
#endif
  return 0;
}
