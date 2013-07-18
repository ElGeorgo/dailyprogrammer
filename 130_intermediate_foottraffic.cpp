#include <iostream>

using namespace std;

struct Visitor {
	Visitor(): isInRoom(false),roomNumber(-1) {;}
	bool isInRoom;
	int roomNumber;
};

void generateTraffic(int e, int v, int r, int i, int o) {

	//# number of events to be generated
	int events = e*2;
	cout << events << endl;

	//create all visitors
	Visitor visitors[v];

	//seed random generator
	srand (time(NULL));

	//helper variables
	int currentTime = i;
	int peopleEntered = 0;
	int peopleNeedToLeave = 0;

	//compute propability of an occuring event
	int propapilityForEvent = events*100/(o-i);

	//while there are events to do and there is enough time to do them
	while(events > 0 && currentTime <= o && peopleNeedToLeave < o-currentTime ) {

		// chosse if event will be generated
		if(rand() % 100 <= propapilityForEvent) {
			//choose a random person
		int person = rand() % v;

		// if the person is in the room -> leave
		if(visitors[person].isInRoom ) {
			visitors[person].isInRoom = false;
			peopleNeedToLeave--;
			cout << person << " " << visitors[person].roomNumber << " " <<  "O" << " " << currentTime << endl;
		} 
		// if person is in no room and there is enough time and not to many peope entered allready
		if((!visitors[person].isInRoom) && peopleNeedToLeave < events && peopleEntered < e){
			visitors[person].roomNumber= rand() % r;
			visitors[person].isInRoom = true;
			peopleEntered++;
			peopleNeedToLeave++;
			cout << person << " " << visitors[person].roomNumber << " " << "I" << " " << currentTime << endl;
		}

		events--;
		}

		//advance time
		currentTime++;
		
	}

	// if time or events are running out, force the people to leave ;)
	if(peopleNeedToLeave > 0)
	{
		for(int k = 0; k < v; k++) {
			if(visitors[k].isInRoom) {
				currentTime++;
				cout<< k << " " << visitors[k].roomNumber << " " <<  "O" << " " << currentTime << endl;
			} 
		}
	}
	
		
}

int main() {

	//read input
	int e = 0; // # Events
	int v = 0; // # Visitors
	int r = 0; // # Roms
	int i = 0; // earliest time for event
	int o = 0; // latest time for event

	cin >> e >> v >> r >> i >> o;

	generateTraffic(e,v,r,i,o);

	return 0;
}
