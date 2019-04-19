/* Encryption and decryption functions for Assignment 1*/

int  encrypt (char c, int k ); 
int  decrypt (char c, int k );

// functions to calculate encryption and decrytpion
int encrypt (char c, int k)
{
	if (c >= 97 && c<= 122)						// check for lower case letters
	{
		c -=32;									// change to upper case by subtracting 32
	}
	//if (c == '\0' || c == ' ' )					// check for null, space or punctuation  o longer required
	if (!(c >= 97 && c<= 122) && !(c>=65 && c<= 90)) //check if it is anything oterh than a letter
	{
		return c;
	}
		
	c = c - 65; 								// change the ASCI character value to between 0 - 25.
	
	 if (c >= 0 && c <= 25)
	{
			c = (c + k)%26;						// apply encrytpion algorithm as per assessment
	}
	
	if (c < 0) 									// check if the character went < zero
	{
			c += 26; 							//add 26 to rotate back around to positive value
	}
	return c+65;								//return the character (integer value) to the correct ASCI value and send back to main
	
}
int decrypt (char c, int k)						// function to decrypt the cipher, requires character to be deciphered and the key value.
{
	if (c >= 97 && c<= 122)						// check for lower case letters
	{
		c -=32;									// chnage to upper case by subtracting 32
	}
	//if (c == '\0' || c == ' ' )				// no longer required see below.
	if (!(c >= 97 && c<= 122) && !(c>=65 && c<= 90))		// check if it is anything oter than a letter
	{
		return c;				
	}
	c = c - 65;									// assign the value of the character to the range 0-25
	
	if (c >= 0 && c <= 65)
	{
		c = (c - k)%26;							// apply decrytpion algorithm as per assessment
	}
	
	if (c < 0)									// if c is negative add 26 to return to positive

	{
		c += 26;
	}
	
	return c+65;								//return the character to the correct ASCI value and send back to main as(integer)
}

