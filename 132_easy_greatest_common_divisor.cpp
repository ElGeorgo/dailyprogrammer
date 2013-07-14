#include <iostream>	

using namespace std;

int ggt(int a, int b)
{
	if(a == 0)
		return b;
	while(b != 0)
	{
		if(a > b)
			a = a-b;
		else
			b = b-a;
	}
	return a;
}

int main() 
{
	int a;
	int b;

	cin >> a >> b;

	int c = ggt(a,b);

	printf("%d \n",c );
	return 0;
}