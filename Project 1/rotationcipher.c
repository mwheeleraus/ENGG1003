#include <stdio.h>
#include <string.h>
#include "rotation.h"

void rotationEncrypt();
void rotationDecrypt();

//Rotation Encrytpion task
void rotationEncrypt()
{
		// Read message into character array.
		char message[1500];
		char error[20] = "No Such file exists";
		FILE *file, *cipher;
		file = fopen("message.txt" ,"r");
		cipher = fopen("t\rotcipher.txt", "w");
		if (file == NULL) 		// check if file is loaded (i.e exists)
		{
			printf("%s", error); // print error message 
					// exit
	
		}
	
		fgets(message,1500, file);				//read file and write file content to message char array
		fclose(file);
/*begin processing message array for encrytption*/
		
		int length = strlen(message);			// calculate length of message array
		printf("%d\n", length);
		char cipherText [length], c;
		int k = -23;
		
		for (int i = 0; i <=length; i++)		//loop for the length of the string
		{
			c = message[i];						// set char c to value of current index of message string
			cipherText[i] = encrypt(c,k);			// set current cipher index to encrytped value by calling encrytp function
		}
		
		printf("Encrypted text: %s\n", cipherText);					// print the encrypted message
		fprintf(cipher,"Encrypted text: %s\n", cipherText);
		fclose(cipher);
		

}
//Rotation Decryption task
void rotationDecrypt()
{
	// Read cipher into character array.
		char cipher[1500],c;
		char error[20] = "No Such file exists";
		FILE *file;
		file = fopen("rotcipher.txt" ,"r");
		FILE *decrypted;
		decrypted  = fopen("decrypted.txt", "w");
		int length = strlen(cipher);
		int k = -23;
		fclose(file);
	
		if (file == NULL) 		// check if file is loaded (i.e exists)
		{
			printf("%s", error); // print error message 
					// exit
	
		}
		fgets(cipher,1500, file);				//read file and write file content to cipher char array
		char decryptedMessage[length];
		printf("%d\n", length);					// debug code to check the cipher is stored in array also use for sizing decryptted array
		for (int i = 0; i <= length; i++)
		{
			c = cipher[i];
			decryptedMessage[i] = decrypt(c,k);		
		}
		printf("Decrypted message: %s\n", decryptedMessage);	// print the decrytpted message (now in capitals)
		fprintf(decrypted,"Decrypted message: %s\n", decryptedMessage);
		fclose(decrypted);
}
