#include <iostream>
#include <string>

using namespace std;

void findSubStr(string input) 
{
	// length and position of the longest sub-string
	int lPos = 0;
	int lLenght = 0;

	for (int i = 0; i < input.length()-1; i++)
	{
		//get the first to chars of the sub-string
		char c1 = input.at(i) ;
		char c2 = input.at(i+1);

		int length = 2;

		// check the next chars
		for(int j = i+length; j < input.length(); j++)
		{	
			//get a new char
			char x = input.at(j);

			//if both start chars are the same
			// replace one with a new char
			if(c1 == c2 && c1 != x)
			{
				c2 = x;
			}

			// if the new char equals, increase sub-string
			if(x == c1 || x == c2)
			{
				length++;
			}
			else
			{
				break;
			}
		}

		// if new solution is longer, replace the old
		if(length >= lLenght)
		{
			lLenght = length;
			lPos = i;
		}
		
	}
	// output the solution
	string sub = input.substr(lPos,lLenght);
	printf("%s \n",sub.c_str());
}

int main()
{
    string input;
	cin >> input;
    findSubStr(input);
    return 0;
}