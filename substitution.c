#include <stdio.h>
#include <string.h>

int main()
{
	int i;
	char c;
	char alphabet[26]  ="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char cipherTable[27] = "QWERTYABCDFGHIJKLMNOPSUVWXZ";
	char message[100] = "matthew is a total legend!";
	int length = strlen(message);
	char cipherMessage[100];
	char decryptMessage[100];
	//printf("%d", messageLength);
	
	
	//substitution encryption
	
	for (i = 0; i <=length; i++)
	{	
		c = message[i];
		if (c >= 97 && c<= 122)						// check for lower case letters
		{
		c -=32;											// change to upper case by subtracting 32
		}	
		if (!(c >= 97 && c<= 122) && !(c>=65 && c<= 90)) //check if it is anything other than a letter
		{
		cipherMessage[i] = c;							//write the non alphabet character into cipherMessage.
		}
		c = c-65;
		if (c >= 0 && c <= 25)							// write the applicable value from cipher table to the message.
		{
			cipherMessage[i] = cipherTable[c];						// apply encrytpion algorithm as per assessment
		}
	
		
	}
	printf("%s\n", cipherMessage);
	length = strlen(cipherMessage);
	// substitution decrytption
		for (i = 0; i <=length; i++)
	{	
		c = cipherMessage[i];
		if (c >= 97 && c<= 122)						// check for lower case letters
		{
		c -=32;									// change to upper case by subtracting 32
		}	
		if (!(c >= 97 && c<= 122) && !(c>=65 && c<= 90)) //check if it is anything other than a letter
		{
		decryptMessage[c] = i;							//write the non alphabet character into cipherMessage.
		}
		c = c-65;
		if (c >= 0 && c <= 25)							// write the applicable value from cipher table to the message.
		{
			decryptMessage[c] = cipherMessage[i];						// apply encrytpion algorithm as per assessment
		}
	
		
	}
	printf("%s", decryptMessage);
	
	return 0;
}