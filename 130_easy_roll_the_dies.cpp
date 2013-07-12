#include <iostream>	
#include <string>
#include <vector>
#include <String>
#include <sstream>

using namespace std;

int main() 
{
	string input;
	int n; // number of dice
	int a; // number of faces
	char* tkns;
	vector<string> numbers;

	getline(std::cin, input);

	stringstream inputStream(input);

	string num;
	while(getline(inputStream, num, 'd'))
	{
	   numbers.push_back(num);
	}

	//simple check if input is malformed
	if(numbers.size() < 2)
		return 0;
	n = atoi(numbers.at(0).c_str());
	a = atoi(numbers.at(1).c_str());
	
	//throwing the dice
	printf("Throwing %dd%d\n",n,a );
	srand (time(NULL));
	for(int i =0; i< n;i++)
	{
		printf("%d ", rand()%a+1);
	}
	printf("\n");
	return 0;
}