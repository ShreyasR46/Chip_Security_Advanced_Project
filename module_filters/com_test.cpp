//============================================================================
// Name        : com_test.cpp
// Author      : Akhil Gudge Subramanya
// Version     :
// Copyright   : Your copyright notice
// Description : Comment Filter
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//bool s_cmt = false;
//    bool m_cmt = false;
string removeComments(string abc)
{
    int n = abc.length();
    string res;

    // Flags to indicate that single line and multpile line comments
    // have started or not.
    bool s_cmt = false;
    bool m_cmt = false;


    // Traverse the given program
    for (int i=0; i<n; i++)
    {
        // If single line comment flag is on, then check for end of it
        if (s_cmt == true && abc[i] == '\0')
            s_cmt = false;

        // If multiple line comment is on, then check for end of it
        else if  (m_cmt == true && abc[i] == '*' && abc[i+1] == '/')
            m_cmt = false, i++;

        // If this character is in a comment, ignore it
        else if (s_cmt || m_cmt)
            continue;

        // Check for beginning of comments and set the approproate flags
        else if (abc[i] == '/' && abc[i+1] == '/')
            s_cmt = true, i++;
        else if (abc[i] == '/' && abc[i+1] == '*')
            m_cmt = true,  i++;

        // If current character is a non-comment character, append it to res
        else  res += abc[i];
    }
    return res;
}


int main() {
		string line;
		ifstream myfile("test.txt");
		if(myfile.is_open())
		{
			while(getline(myfile,line))
			{
				cout << removeComments(line) << '\n';
			}
			myfile.close();
		}
//	    cout << " Modified Program ";
//	    cout << removeComments(prgm);
	return 0;
}



