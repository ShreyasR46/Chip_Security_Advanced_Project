#include<stdio.h>
#include<iostream>
#include<string>

#define AUTO
#define DEBUG

using namespace std;

/*class search{
	public:

};*/


class Node  
{  
    public: 
    string data;  
    Node *next;  
};  


void printList(Node* n) 
{ 
    while (n != NULL) 
    { 
        cout << n->data << " "; 
        n = n->next; 
    } 
} 

void deleteList(Node** head_ref)  
{  
      
/* deref head_ref to get the real head */
Node* current = *head_ref;  
Node* next;  
  
while (current != NULL)  
{  
    next = current->next;  
    free(current);  
    current = next;  
}  
      
/* deref head_ref to affect the real head back  
    in the caller. */
*head_ref = NULL;  
}

/*void append(Node*& reference, string str_data) 
{ 
   Node* new_node = new Node();
   //Node* last_node = new Node();
   new_node->data = str_data;
   if(*reference->next != NULL)
   { 
	//new_node = reference->next;
	append(&(reference->next), str_data);
   }
   else
   {
       	reference->next = new_node;
   }	
   return;  
}*/


void append(Node*& p, string d){
    Node* temp = new Node();
    temp->data=d;
    if(p == NULL) p = temp;
    else append(p->next, d);
}



int main()
{
	string path_to_search, keyword, filename_to_save;
	char dot_sv = ':';
        clock_t start, end;
  	double cpu_time_used;
	FILE *dictionary, *filename, *data;
  	long int n =0;
  	long int total_lines=0, flag = 0,i = 0, k =0;
  	char ct = '`';
 	char *line = NULL;
  	size_t len = 0;
  	long int offset = 2;
  	int counter=0;
        string search = "banana";
        string copied;
	long int alphabet_array[27];
        long int temp=0, nread;


	//Initializing linked List
  Node* head = NULL;
  Node* second = NULL;
  Node* base = NULL;
  ///
  head = new Node();
  second = new Node();
  base = new Node();
  //connecting head and base
  head->data = "Kartikey";
  head->next = second;
  
  second->data = "Ashish";
  second->next = base;
  
  base->data= "Deepraj";
  base->next = NULL;

////////////////////////////////////////////////////////////////
#ifdef AUTO
	path_to_search = "~/Documents/Github_Directories/Chip_Security_Advanced_Project/ariane/";
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

/////////////////////////////////////////////////////////////////
	
	filename = fopen("filename.txt","w");
	data = fopen("data.txt","w");
	dictionary = fopen("search_results.txt", "r");
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
			for(int i=0, flag = 0;i<nread;i++)
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
				
				//if(j == 2){j = 0;}
			}
			//putc('\n', data);
			//putc('\r', data);
			cout<<"\n\r";
		}
	}
  	free(line); 
  	fclose(dictionary);
	fclose(filename);
	fclose(data);

  	end = clock();
  	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
 	cout<<"Second is : "<<cpu_time_used<<"\n";
  

	
	return 0;
}
