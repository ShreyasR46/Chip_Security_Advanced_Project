#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::stringstream, std::stringbuf

int main ()
{
 std::stringstream ss;
 std::string line;
 std::getline(std::cin,line);
 std::stringstream ss(line);
 std::cout << line << '\n';
 int i=0;
 std::string word;
 while(ss >> word)
      {
        // ++i;
         std::cout << word << '\t' << i << '\n';
         i++;
      }
                   // ss.str(line);
                                      //std::string s = ss.str();
                                       // std::cout << s << '\n';
                                        std::cout << "The number of words is "<< i << std::endl;
                                          return 0;
                                          }
                                           
