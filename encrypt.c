#include <stdio.h>
#include <string.h>

int  encrypt (char c, int k ); 
int  decrypt (char c, int k );
int main ()
{
		char message[30] = "HELLO my name is matthew";
		int length = strlen(message);
		char decryptedMessage [length];
		char cipher [length], c;
		int k = 7;
		
		printf("%d\n", length);
		
		for (int i = 0; i <=length; i++)		//loop for the length of the string
		{
			c = message[i];						// set char c to value of current index of message string
			cipher[i] = encrypt(c,k);			// set current cipher index to encrytped value by calling encrytp function
		}
		//length = strlen(cipher);
		printf("%d\n", length);
		for (int i = 0; i <= length; i++)
		{
			c = cipher[i];
			decryptedMessage[i] = decrypt(c,k);		
		}
		printf("Original message: %s\n", message);
		printf("Encrypted text: %s\n", cipher);
		printf("Decrypted message: %s\n", decryptedMessage);
return 0;
}

int encrypt (char c, int k)
{
	if (c >= 97 && c<= 122)						// check for lower case letters
	{
		c -=32;									// change to upper case by subtracting 32
	}
	//if (c == '\0' || c == ' ' )					// check for null, space or punctuation
	if (!(c >= 97 && c<= 122) && !(c>=65 && c<= 90)) //check if it is anything oterh than a letter
	{
		return c;
	}
	
	c = c - 65; 			// change the ASCI character value to between 0 - 25.
	
	 if (c >= 0 && c <= 25)
	{
			c = (c + k)%26;	// apply encrytpion algorithm as per assessment
	}
	
	if (c < 0) 				// check if the character went < zero
	{
			c += 26; 		//add 26 to rotate back around to positive value
	}
	return c+65;			//return the character to the correct ASCI value and send back to main
	
}
int decrypt (char c, int k) // function to decrypt the cipher, requires character to be deciphered and the key value.
{
	if (c >= 97 && c<= 122)						// check for lower case letters
	{
		c -=32;									// chnage to upper case by subtracting 32
	}
	//if (c == '\0' || c == ' ' )
	if (!(c >= 97 && c<= 122) && !(c>=65 && c<= 90))		// check if it is anything oter than a letter
	{
		return c;				
	}
	c = c - 65;				// assign the value of the character to the range 0-25
	
	if (c >= 0 && c <= 65)
	{
		c = (c - k)%26;		// apply decrytpion algorithm as per assessment
	}
	
	if (c < 0)
	{
		c += 26;
	}
	
	return c+65;			//return the character to the correct ASCI value and send back to main
}
