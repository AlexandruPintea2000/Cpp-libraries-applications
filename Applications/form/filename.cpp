#include <string>
#include <fstream>
#include <string.h>
#include <iostream>

using namespace std;

ofstream datafile;

int main()
{
	datafile.open( "data" );

	cout << "filename:\n\n";

	// Getting data
	datafile.close();

	return 0;
}