//Written by David Tullis - Assignment3

#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <iomanip>


using namespace std;

const int ITEM_W = 4;
const int NO_ITEMS = 6;

//The sieve is a simple function which takes a range of numbers, checks for primes w/ the modulus
//operator, and then removes them using iterators
void sieve( set<int>& s, const int lower, const int upper) {
	set<int>::const_iterator incr;
	set<int>::const_iterator incr2;
	
	s.clear();
	for(int base = 2; base <= upper; base++)
		s.insert(base);
	
	for (incr = s.begin(); incr != s.end(); incr++){
		for (incr2 = incr; incr2!= s.end(); incr2++){
			if((*incr2%*incr==0) && (*incr2 != *incr)){
				s.erase(incr2);
			}
		}
	}
	for(incr = s.begin(); *incr < lower;incr ++){
		s.erase(incr);
	}
}

//This print function displays the remaining print function in 's'. It organizes
//them using both 'setw' and 'endl' so that they are evenly displayed.
void print_primes( const set<int>& s, const int lower, const int upper) {
	set<int>::const_iterator incr;
	int counter = 0;
	cout<< "\nThere are " << s.size() << " prime numbers between " << lower << " and " << upper << ": \n";
	for(incr = s.begin(); incr != s.end(); incr++){
		if (counter != NO_ITEMS){
			cout << setw(ITEM_W) << *incr;
			counter++;
		} else {
			cout << endl;
			cout << setw(ITEM_W) << *incr;
			counter = 1;
		}
	}
	cout << endl;
}

//This function controls the 'game' itself. It is primarilly run through a while loop. It accepts the initial 
//values, calls the functions, and then allows for an escape with an if statement.
void run_game(set<int>& s) {
	bool running_game = true;
	int lower = 0, upper = 0;
	string response;
	
	//primary while loop that locks the process flow until the escape condition (yes)
	//has been met
	while(running_game){
		
	cout << "Please input lower bound and upper bound and hit enter (e.g. 10 100):\n";
	cin >> lower;
	cin >> upper;
	if( lower > upper ){
		lower = 2;
		upper = 99;
	} else if (lower < 2)
		lower = 2;
	
	sieve(s, lower, upper);
	print_primes(s, lower, upper);
	
	//escape
	cout<< "\nDo you want to continue or not? Please answer yes or no and hit enter: \n";
	cin.ignore(256, '\n');
	cin.clear();
	getline(cin, response);
	if(response != "yes" )
		running_game = false;
	
	}
}

int main() {
    set<int> s;
    run_game(s);
    return 0;
}
