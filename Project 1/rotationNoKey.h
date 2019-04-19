#include <stdio.h>
#include <string.h>



void rotationNoKey();
int wordCheck(const char *);

void rotationNoKey()
{		
		char ciphertext[1500], c ; //large char array to store cipher text
		char error[20] = "No Such file exists";
		FILE *file;
		file = fopen("dayonerotationcipher.txt" ,"r");
		FILE *decrypted;
		decrypted = fopen("dayonerotationdecrypted.txt", "w");
		
		if (file == NULL) 		// check if file is loaded (i.e exists)
		{
			printf("%s", error); // print error message 
					// exit
	
		}
		fgets(ciphertext,1500,file);		//write content of encrytped file to ciphertext array (max 1000 char)
		fclose(file);						//close file
		int length = strlen(ciphertext);	// determine length of string stored in char array (used for storage calculation and loop iterations.
		char message[length];				// create a new char array to store the decrytep message.
		char word1[] = "IT";				// words to look for in decrypted text
		char word2[] = "THE";
/* begin processing message decryption brute force*/

		for (int k = 1; k <=26; k++)			// ignoring 0, including 26 to capture no rotation.
		{
			
			for (int i = 0; i <=length; i++)	// loop through for the entire cipher text
			{
				c = ciphertext[i];				// assign ciphertext[i] to the char used for testing
				message[i] = decrypt(c,k);		// write the return value from decrytp(c,k) to message array in pos [i]
			}
			if(!(strstr(message,word1) && strstr(message,word2)))		// simple word serch within first string. currently limited to 2 words.
			{
				continue;
			}
			else
			{	
				printf("(%d) %s\n\n",k, message);	// print the result to console
			
				fprintf(decrypted,"(%d) %s\n\n" ,k, message);	// write results to file
			}
		}
		fclose(decrypted); // close file

}

 
