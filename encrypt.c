#include <stdio.h>
#include <string.h>

int  encrypt (char c, int k ); 
int  decrypt (char c, int k );
int main ()
{
		char message[14] = "Hello MATTHEW";
		char decryptedMessage [14];
		char cipher [14], c;
		int k = 0;
		
		for (int i = 0; i <strlen(message); i++)
		{
			c = message[i];
			
			cipher[i] = encrypt(c,k);
		}
		
		for (int i = 0; i < strlen(cipher); i++)
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
	if (c == '\0' || c == ' ' )
	{
		return c;
	}
	else
	c = c - 65; 			// change the ASCI character value to between 0 - 25.
	
	 if (c >= 0 && c <= 25)
		{
			c = (c + k)%26;
		}
	else if (c >= 65 && c <= 90)
		{
			c = (c+k)-32;
		}
	if (c < 0) 				// check if the character went < zero
		{
			c += 26; 		//add 26 to rotate back around to positive value
		}
	return c+65;			//return the character to the correct ASCI value and send back to main
	
}
int decrypt (char c, int k) // function to decrypt the cipher, requires character to be deciphered and the key value.
{
	if (c == '\0' || c == ' ' )			// check if it is a space, if it is send it back
	{
		return c;				
	}
	c = c - 65;				// assign the value of the character in the range 0-25
	
	if (c >= 0 && c <= 65)
		{
		c = (c - k)%26;
		}
	else if (c >= 65 && c <= 90)
	{
		c = (c-k)-32;
	}
	if (c < 0)
	{
		c += 26;
	}
	
	return c+65;			//return the character to the correct ASCI value and send back to main
}
