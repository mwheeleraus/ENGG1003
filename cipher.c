/* program to assign ASCI values to char arrays for Upper and lowercase alphabet.*/

#include <stdio.h>

int main ()
{
	char alphabet[26]; //array to store lower case alphabet 
	char ALPHABET[26]; //array to store upper case alphabet
	int index = 0;		// counter for cycling through array values, initailly set to zero (first index of array)
 
	
	for (int i = 65; i <=90; i++) // loop for ASCI values (uppercase) 65 is ASCI for 'A'
	{
		ALPHABET[index] = i;			// Assign ASCI value to char array at index postion (upper case)
		alphabet[index] = i + 32;		//Assign ASCI character to array at index position (lower case) 32 is the offset from 'A' to 'a' in ASCI table
		index++;
	}
	
	for (int j = 0; j<26; j++) // Loop through to display ASCI array values
	{
	printf("%c	%c\n", alphabet[j],ALPHABET[j]); //print array values to console as Char.
	}
	return 0;
}