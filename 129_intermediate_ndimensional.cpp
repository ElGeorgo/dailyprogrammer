#include <iostream>
#include <assert.h> 
#include <cmath>
#include <vector>

using namespace std;

double veclength(vector<double> input)
{
	double sum = 0;
    for(int i = 0; i < input.size(); i++)
        sum += (input[i]*input[i]);
    return sqrt(sum);
}

double dotprod(vector<double> input, vector<double> input2)
{
	double sum = 0;
    assert(input.size() == input2.size());
    for(int i = 0; i < input.size(); i++)
        sum += (input[i]*input2[i]);
    return sum;
}

vector<double> norm(vector<double> input)
{
	double length = veclength(input);
    for(int i = 0; i < input.size(); i++)
        input[i] /= length;
    return input;
}

int main()
{
	int N;
	vector< vector<double> > input;
	vector< vector<double> > results;
	cin >> N;
	for (int i=0; i<N; ++i)
	{
		int A = 0;
		vector<double> vec;
		cin >> A;
		double d;

		for(;A>0;--A) 
		{
			cin >> d;
			vec.push_back(d);
		}
		input.push_back(vec);
	}

	//now get the operands
	cin >> N;
	for (int i=0; i<N; ++i)
	{
		char c;
		double i;
		std::vector<double> v;
		cin >> c;
		cin >> i;
		switch(c)
		{
			case 'l':
				v.push_back(veclength(input[i]));
				results.push_back(v);
				break;
			case 'n':
				results.push_back(norm(input[i]));
				break;
			case 'd':
				int i2;
				cin >> i2;
				v.push_back(dotprod(input[i],input[i2]));
				results.push_back(v);
				break;
			default:
				break;
		}
	}

	//output
	for(int i = 0; i < results.size(); i++)
	{
		for(int k = 0; k < results[i].size(); k++)
		{
			//printf("%f ",results[i][k]);
			cout << results[i][k] << " ";

		}
		printf("\n");
	}
}