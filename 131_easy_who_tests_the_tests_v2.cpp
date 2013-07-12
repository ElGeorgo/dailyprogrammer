	#include <iostream>
	#include <string>
	#include <vector>
	#include <sstream>
	#include <cctype>

	using namespace std;

	void test(int testcases,string input, string expectedOutput)
	{
		if(testcases == 0)
			reverse(input.begin(), input.end());
		else
			for(int k = 0; k < input.length(); k++)
				{
					input[k] = toupper(input[k]);	
				}

		if(input == expectedOutput)
			printf("Good test data \n");
		else
			printf("Mismatch! Bad test data \n");

	}

	int main()
		{
		    int N;// Number of Rows
		    cin >> N;
			for (int i=0; i<N; ++i)
			{
			    int testno;
			    string input;
			    string expectedOutput;

			    cin >> testno >> input >> expectedOutput;
			    test(testno, input, expectedOutput);
			}

		    return 0;
		}