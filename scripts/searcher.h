#ifndef SEARCHER_H
#define SEARCHER_H

using namespace std;

#pragma once
class searcher
{
	public:
	  string path_to_search; 
	  string keyword;
	  string filename_to_save;   
	  int empty_file; 
	  void take_input();
	  int grep_search_and_store(string keyword_local, string path_to_search_local, string filename_to_save_local );
	  void search_and_divide(const char *filename_name, const char *data_name, const char *dictionary_name);
};
#endif 
