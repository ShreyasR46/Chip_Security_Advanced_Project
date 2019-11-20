#include<stdio.h>
#include<iostream>
#include<string>
#include "searcher.h"
using namespace std;

#define AUTO

#ifdef AUTO
 //searcher::path_to_search = "~/Documents/Github_Directories/Chip_Security_Advanced_Project/ariane/";
 //searcher::keyword = "\"aes\"";
 //searcher::filename_to_save = "search_results.txt";

#endif

//taking manual input!!
  void searcher::take_input()
   {
      string path_to_search, keyword, filename_to_save;
      cout<<"Provide the path to search: "<<"\n";
      cin>>path_to_search;
      cout<<"Give the keyword to search: "<<"\n";
      cin>>keyword;
      cout<<"Give the file where to save data: "<<"\n";
      cin>>filename_to_save;
   }


//grep searching
   int searcher::grep_search_and_store(string keyword_local, string path_to_search_local, string filename_to_save_local )
   {
      string command1 = "grep -R";
      command1 = command1 + " " + keyword_local + " " + path_to_search_local + " " +  ">" + " " + filename_to_save_local;
      cout<<"The command executed is: "<<command1<<"\n";
      const char *command = command1.c_str();
      cout << "Compiling file using " << command << endl; 
      return system(command);
   }


//segregating into different files!!
   void searcher::search_and_divide(const char *filename_name, const char *data_name, const char *dictionary_name)
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

