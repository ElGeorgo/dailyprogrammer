	#include <iostream>
	#include <string>
	#include <vector>
	#include <sstream>

	using namespace std;

	void test(vector<int> testcases,vector<string> data,int N)
	{
		for(int i = 0; i < N; i++)
		{
			string t  = data[2*i];
			if(testcases[i] == 0)
			{
				reverse(t.begin(), t.end());

			}
			else // testcases[i] == 1
			{
				for(int k = 0; k < t.length(); k++)
				{
					t[k] = toupper(t[k]);	
				}

			}
			if(t == data[2*i+1])
			{
				printf("Good test data \n");
			}
			else
			{
				printf("Mismatch! Bad test data \n");
			}
		}
	}

	int main()
		{
		    string s; 
		    int N;// Number of Rows
			getline(std::cin, s);

			std::istringstream is(s);
			is >> N;

			std::vector<int> testcases;
			testcases.resize(N);
			std::vector<string> data;
			data.resize(2*N);
			// reading in the rows
			for(int i = 0; i < N; i++)
			{
				string input;
		   
			    getline(std::cin, input);
			    istringstream iss(input); 
			    int j = 0;
			    int n;
			    string s;

			    //get the number
			    if(iss >> n)
			    	testcases[i] =n;

			    //the text
		    	while (iss >> s) 
		    	{
		        	data[2*i+j] = s;
		        	j++;
		    	}

			}

			test(testcases,data,N);

		    return 0;
		}