#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

int length ( string a[] )
{
	int i = 0;

	while ( a[ i ].length() > 0 )
		i = i + 1;

	return i;
}

bool is_in_strings ( string strings[], string a )
{
	int size = length( strings );

	for ( int i=0; i<size; i=i+1 )
		if ( strings[i] == a )
			return true;

	return false;
}


// move words of   string text   into   words[]
void move_words ( string text, string words[] )
{
	text = text + " ";

	int size = text.length();

	int words_iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( text[i] == ' ' )
		{
			words_iter = words_iter + 1;
			words[ words_iter ] = "";
		}
		else
			words[ words_iter ] = words[ words_iter ] + text[i];
}

void bag_of_words ( string data, string bag[] )
{
	string words[ 1000 ];
	move_words( data, words );

	int size = length( words );
	int l = 0;

	for ( int i = 0; i < size; i = i + 1 )
		if ( ! is_in_strings( bag, words[ i ] ) )
		{
			bag[ l ] = words[ i ];
			l = l + 1;
		}
}

int main ()
{
	string data;
	cout << "Data: ";
	getline( cin, data );
	if ( data == "" )
		getline( cin, data );
	string bag[ 1000 ];

	bag_of_words( data, bag );

	int size = length( bag );
	cout << "{ ";
	for ( int i = 0; i < size; i = i + 1 )
	{
		cout << '"' << bag[ i ] << '"';
		if ( i != size - 1 )
			cout << ", ";
	}
	cout << " } ";
	return 0;
}
