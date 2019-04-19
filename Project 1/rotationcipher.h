#include <stdio.h>
#include <string.h>


int rotationEncrypt();
int rotationDecrypt();

//Rotation Encrytpion task
int rotationEncrypt()
{
		// Read message into character array.
		char message[1500];
		char error[20] = "No Such file exists";
		FILE *file, *cipher;
		file = fopen("messageforencryption.txt" ,"r");
		cipher = fopen("rotationencrypted.txt", "w");
		if (file == NULL) 		// check if file is loaded (i.e exists)
		{
			printf("%s", error); // print error message 
			// exit
		return 1;
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
		fprintf(cipher,cipherText);
		fclose(cipher);
		return 0;

}
//Rotation Decryption task
int rotationDecrypt()
{
	// Read cipher into character array.
		char cipher[1500],c;
		char error[20] = "No Such file exists";
		FILE *file, *decrypted;
		file = fopen("rotationencrypted.txt" ,"r");
		decrypted  = fopen("rotationdecrypted.txt", "w");
		int k = -23;
			
		if (file == NULL) 		// check if file is loaded (i.e exists)
		{
			printf("%s", error); // print error message 
					// exit
		return 1;
		}
		
		fgets(cipher,1500, file);				//read file and write file content to cipher char array
		fclose(file);
/*Begin decrypt process*/
		int length = strlen(cipher);
		char decryptedMessage[length];
		printf("%d\n", length);					// debug code to check the cipher is stored in array also use for sizing decryptted array
		for (int i = 0; i <= length; i++)
		{
			c = cipher[i];
			decryptedMessage[i] = decrypt(c,k);		
		}
		printf("Decrypted message: %s\n", decryptedMessage);	// print the decrytpted message (now in capitals)
		fprintf(decrypted,decryptedMessage);
		fclose(decrypted);
		return 0;
}
