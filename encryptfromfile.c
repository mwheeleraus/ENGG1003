#include <stdio.h>
#include <string.h>
#include "rotation.h"


int main ()
{		// Read message into character array.
		char message[100];
		char error[20] = "No Such file exists";
		FILE *file;
		file = fopen("message.txt" ,"r");
	
		if (file == NULL) 		// check if file is loaded (i.e exists)
		{
			printf("%s", error); // pritn error message 
			return 0;				// exit
	
		}
	
		fgets(message,100, file);				//read file and write file content to message char array
		
		//begin processing message array for encrytption
		
		int length = strlen(message);			// calculate length of message array
		printf("%d\n", length);
		char decryptedMessage [length];
		char cipher [length], c;
		int k = 7;
		
		for (int i = 0; i <=length; i++)		//loop for the length of the string
		{
			c = message[i];						// set char c to value of current index of message string
			cipher[i] = encrypt(c,k);			// set current cipher index to encrytped value by calling encrytp function
		}
		
		printf("%d\n", length);
		for (int i = 0; i <= length; i++)
		{
			c = cipher[i];
			decryptedMessage[i] = decrypt(c,k);		
		}
		printf("Original message: %s\n", message);  	// print the Original message 
		printf("Encrypted text: %s\n", cipher);			// print the encrypted message
		printf("Decrypted message: %s\n", decryptedMessage);	// print the decrytpted message (now in capitals)
return 0;
}
/*Encryption and decryption migrated to rotation.h*/