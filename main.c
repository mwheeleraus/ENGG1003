#include <stdio.h>

int main()
{
	char message[100] = "hello matthew";
	char alphabet[26];
	
	for (int i = 0; i < 26; i++)
	{
		alphabet[i] = i+65; // ASCI capital alphabet assigned to array alphabet.
		
	}
	
	for (int i  = 0; message[i] != '\0'; i++)
	{
		message[i] = message[i]- 65;
	}
	for (int i =0 ; alphabet[i] != '\0' ;i++)
	{
	printf("%c", message[i]);
	}
	for( int i = 0; alphabet
	return 0;

}