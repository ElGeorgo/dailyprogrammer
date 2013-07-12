	#include <iostream>
	#include <string>
	#include <vector>
	#include <sstream>

	using namespace std;

	void fixStreets(vector<int> input, int N)
	{

		int maxPotholes = 0;
		int getsFixed = 0;

		while( getsFixed != -1)
		{	
			maxPotholes = 0;
			getsFixed = -1;

			//which has the most potholes? 
			//0 to n-1 represent rows, n to n*2-1 represent columns
			for(int i = 0; i < N*2; i++)
			{
				int potholes = 0;
				for (int j = 0; j < N; j++)
				{	
					if (i < N && input[i*N+j] <= 0 || i >= N && input[i-N+N*j] <= 0 )
					{
						potholes++;
					}

				}

				if(potholes > maxPotholes)
				{
					maxPotholes = potholes;
					getsFixed = i;
				}

			}

			// if a street is found, getsFixed is positive
			if(getsFixed < N && getsFixed >= 0)
			{
				printf("Row %d repaired.\n", getsFixed) ;
			}
			if(getsFixed >= N )
			{
				printf("Column %d repaired.\n", getsFixed-N) ;
			}

			// now repair the street!
			for(int k = 0; k < N; k++)
			{	
				
				if (getsFixed < N ) // row
				{
					input[getsFixed*N+k] = 1;
				}
				else // column
				{
					input[k*N+getsFixed-N] = 1;
				}
				
			}
		}
	} 

	int main()
	{
	    string s; 
	    int N;// Number of Rows and columns
		getline(std::cin, s);

		std::istringstream is(s);
		is >> N;

		// use one big block of memory to store the data
		// format will be row1 row 2 row 3 ... row n
		std::vector<int> streets;
		streets.resize(N*N);
		/*
		// reading in the rows
		for(int i = 0; i < N; i++)
		{
			string input;
	   
		    getline(std::cin, input);
		    istringstream iss(input); 
		    int j = 0;
		    int n;

	    	while (iss >> n) 
	    	{
	        	streets[i*N+j] = n;
	        	j++;
	    	}

		}*/

	    for(int i = 0; i < N*N; i++)
		{
			streets[i] = (rand() % 2);
		}
		printf("generated - fixing now")

		fixStreets(streets, N);
	
	    return 0;
	}