#include <stdio.h>
#include <string.h>

void subEncrypt();
void subDecrypt();

void subEncrypt()
{
	char ec;													// char's to hold single characters for processing in loops for encrypt/decrypt
	char alphabet[27]  ="ABCDEFGHIJKLMNOPQRSTUVWXYZ";			// alphabet stored for use in comparing 
	char cipherTable[27] = "QWERTYUIOPASDFGHJKLZXCVBNM";		// char array to store the cipher table
	char message[1500];											// originally hard coded message for testing purpose
							
	char cipherMessage[1500];									// char array to write the encrypted message to
	
	int wordCount =0;
	
	FILE *file;
	file = fopen("messageforencryption.txt", "r");
	fgets(message, 1500, file);
	fclose(file);
	printf("Original text: %s\n", message);						// print the message in plain english to console, 
	int length = strlen(message);								// determine how long the message to be encrypted is, used for loop termination
	printf("Length of message: %d\n", length);					// used to ensure the message length was being determined
	file = fopen("subencrypted.txt", "w");
	
	
	for (int i = 0; i <=length; i++)							// loop through the messsage until the end
	{	
		ec = message[i];										// ec is a char, used to store the current char we wish to test encrypt
		if (ec >= 97 && ec<= 122)								// check for lower case letters
		{
		ec -=32;												// change to upper case by subtracting 32
		}	
		if (!(ec >= 97 && ec<= 122) && !(ec>=65 && ec<= 90)) 	//check if it is anything other than a letter
		{
			if(ec == 32)
			{
				wordCount++;									// Count words by recognising spaces in text
			}
			cipherMessage[i] = ec;								//write the non alphabet character into cipherMessage.
		}
		ec -= 65;
		if (ec >= 0 && ec <= 25)								// write the applicable value from cipher table to the message.
		{
			cipherMessage[i] = cipherTable[ec];						
		}
		if (i == length+1)										// added to ensure stability, writes the null character at the end of string
		{
			cipherMessage[i] = '\0';
			
		}	
	}
	printf("Original text : %s\n", message);
	printf("Cipher text: %s\n", cipherMessage);					// Print the Encrypred message to console.
	//printf("%d words in message\n", wordCount+1);  //no longer used
	fprintf(file, cipherMessage);
	fclose(file);
}	
void subDecrypt()
{
	/*substitution decryption (CONVERT TO FUNCTION) - Loop through the encrypted message until the end and comparing the value to the value of the cipher table index. if it is the same write the alphabet character at that index to the message */ 
	

	char dc;													// char's to hold single characters for processing in loops for encrypt/decrypt
	char alphabet[27]  ="ABCDEFGHIJKLMNOPQRSTUVWXYZ";			// alphabet stored for use in comparing 
	char cipherTable[27] = "QWERTYUIOPASDFGHJKLZXCVBNM";		// char array to store the cipher table
							
	char cipherMessage[1500];									// char array to write the encrypted message to
	char decryptMessage[1500];									// char array to write the decrypted message to 

	int wordCount =0;
	
	FILE *file;
	file = fopen("subencrypted.txt", "r");
	fgets(cipherMessage, 1500, file);
	fclose(file);
	int length = strlen(cipherMessage);							// determine how long the message to be encrypted is, used for loop termination 
	file = fopen("subdecrypted.txt", "w");
	
	for (int i =0; i<=length; i++)								// loop through the encrytpted message until the end.
	{
		dc = cipherMessage[i];									// dc is a char, used to store the current char we wish to compare in loop.
		if (dc >= 97 && dc<= 122)								// check for lower case letters
		{
		dc -=32;												// change to upper case by subtracting 32
		}
		
		for(int j = 0; j<=26; j++)								// loop for length of alphabet(cipherTable)
		{
			if (!(dc >= 97 && dc<= 122) && !(dc>=65 && dc<= 90))//check if it is anything other than a letter by comparing to ASCI table values of upper and lower case letters.
			{
				decryptMessage[i] = dc;							//write the non alphabet character into decryptMessage.
				
				break;											// break the loop to take next char for processing						
			}
			if(dc == cipherTable[j])							// check current char against cipherTable
			{
				decryptMessage[i] = alphabet[j];				// if matched write to decrytpMessage array in current index poaition being checked
				
				break;											// break the loop to take next char for processing
			}	
		}
	}
	printf("Original Text : %s\n", cipherMessage);
	printf("Decrypted message: %s", decryptMessage);								// print the decrypted messsage to console.
	fprintf(file, decryptMessage);
	fclose(file);
}
