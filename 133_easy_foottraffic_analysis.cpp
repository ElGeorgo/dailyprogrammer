#include <iostream>

struct RoomAccess {
	RoomAccess(): in(-1),out(-1) {;}
	int in;
	int out;
};

int main()
{

	//input length
	int N;
	scanf("%d", &N);

	RoomAccess racc[100][1024];

	//get now input
	for(;N > 0;N--)
	{
		int user, room, timeStamp;
		char eventType;

		scanf("%d %d %c %d", &user, &room, &eventType, &timeStamp);

		if(eventType == 'I')
			racc[room][user].in = timeStamp;
		else
			racc[room][user].out = timeStamp;
	}

	//analyse the data and output
	for(int i = 0 ; i < 100; i++)
	{
		int userSum = 0, timeSum = 0;
		for(int k = 0; k < 1024; k++)
		{
			if(racc[i][k].in >=0)
			{
				timeSum += racc[i][k].out - racc[i][k].in;
				userSum++;
			}
		}

		if(userSum > 0)
			printf("Room %d, %d minute average visit, %d visitor%s total\n", i, (timeSum / userSum), userSum, (userSum > 1) ? "s" : "" );
	}

	return 0;
}