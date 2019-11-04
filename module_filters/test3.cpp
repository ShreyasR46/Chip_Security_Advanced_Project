#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main()
{
	std::string line,temp;
	std::ifstream file1,file2;
	file1.open("data.text");
	int i = 0;
	if(file1.is_open())
	{
		while(getline(file1,line))
		{
		       std:: cout << line << '\n';
			i++;
		}
		std::cout << "The number of line:" << i <<std:: endl;
		file1.close();
	}
	else std::cout << "Not opening";
	return 0;
	
}
