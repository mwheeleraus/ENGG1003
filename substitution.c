#include <stdio.h>
#include <string.h>

int main()
{
	int i;
	char ec,dc;
	char alphabet[27]  ="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char cipherTable[27] = "QWERTYUIOPASDFGHJKLZXCVBNM";
	char message[100] = "matthew is a total legend!";
	int length = strlen(message);
	char cipherMessage[100];
	char decryptMessage[100];
	//printf("%d", messageLength);
	printf("Original text: %s\n", message);
	
	//substitution encryption
	
	for (i = 0; i <=length; i++)
	{	
		ec = message[i];
		if (ec >= 97 && ec<= 122)						// check for lower case letters
		{
		ec -=32;											// change to upper case by subtracting 32
		}	
		if (!(ec >= 97 && ec<= 122) && !(ec>=65 && ec<= 90)) //check if it is anything other than a letter
		{
			cipherMessage[i] = ec;							//write the non alphabet character into cipherMessage.
		}
		ec -= 65;
		if (ec >= 0 && ec <= 25)							// write the applicable value from cipher table to the message.
		{
			cipherMessage[i] = cipherTable[ec];						// apply encrytpion algorithm as per assessment
		}
		if (i == length)
		{
			cipherMessage[i] = '\0';
			
		}	
	}
	printf("Cipher text: %s\n", cipherMessage);
	
	length = strlen(cipherMessage);
	
	
	// substitution decrytption
		for (i = 0; i <=length; i++) //  loop for length of cipher
	{	
		dc = cipherMessage[i];
	
				// loop for alphabet
		{
			
		if( dc != alphabet[j])	
		{	
			continue;	
		}
		else if (dc == alphabet[j])
		{
			decryptMessage[i] = alphabet[j];
		}
		}
	}
	printf("Decrypted text: %s", decryptMessage);
	
	return 0;
}