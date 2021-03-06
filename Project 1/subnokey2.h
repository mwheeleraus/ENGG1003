// decipher substituton without phrase. In respons to Brentons 11th hour email on monday 29th Apr, have changed from decrypting from the subset(that works) to the common letters cipher table.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int subNoKey2();

int subNoKey2()
{
	char ciphertext[2000];
	char decryptedtext[2000];
	char alphabet[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ciphertable1[26]= "EARIOTNSLCUDPMHGBFYWKVXZJQ";	// common letters oxford dictionary
	char ciphertable2[26]= "ETAOINSRHLDCUMFPGWYBVKXJQZ"; 	// common letters for words (average).
	char lettercounter[3][26];								// char array to count letter usage in cipher and store most common in second row
	char subset[26] = "KEIJUTVHPSNCFAMWGD   YBROL";			// cipher table used to encrpyt worked out by looking at cipher text and substituting letters WORKS FOR BOTH DAY ONE TEXTS
	
	/* set up multidimension array*/
	for (int i = 0; i <26; i++)
	{
		lettercounter[0][i] = 0;							//set all first row indices of letter counter to 0
	}
	for (int i = 0;i<26; i++)
	{
		lettercounter[1][i] = alphabet[i]; 					// write the alphabet to indices on second row
		
	}
	for (int i = 0; i<26; i++)
	{
		
		lettercounter[2][i] = ciphertable1[i]; 				//place cipher table in 3rd row (now subset)
	}
	
	/*Begin Processing of string*/
	char c;
	int wordcount = 0;
	FILE *cipher, *cipher2;
	cipher = fopen("subcipher2.txt", "r");
	cipher2 = fopen("subcipher.txt", "r");
	fgets(ciphertext, 2000, cipher);
	fclose(cipher);
	fclose(cipher2);
	int length = strlen(ciphertext);
	printf("%s\n\n", ciphertext);
	
	if(cipher == NULL)
	{
		printf("no such file");
		return 0;
	}
	
	for(int i = 0 ; i<length; i++)						//loop looking for spaces
	{
		c = ciphertext[i];
		if (c == ' ')
		{
			wordcount ++;								// count words by interpreting spaces
		}	
	}
	wordcount++;										// add another to the count for last word as it is not followed by a space.
	printf("%d words in text\n", wordcount);			// print how many words are present 
	
	for (int i = 0; i<26; i++)							// loop through cipher text to compare every letter of alphabet.
	{
		c = alphabet[i];
		for(int j = 0; j<length; j++)					// loop  through cipher text comparing current alphabet character to current index poition of ciphertext
		{
			if(c == ciphertext[j])						//compare values (ASCI)
			{
				lettercounter[0][i]++;	
														// increment letter counter at index[i] i.e starting at 'A'....'Z'
			}
			
		}
	//printf("%d %c's in ciphertext\n", lettercounter[i], alphabet[i]);  // print out findings from letter search.

	}	

	// sort the letter counter array in ascending order
        

	for (int i = 0; i < 26; i++)                    		  //Loop for ascending ordering
	{
		for (int j = 0; j < 26; j++)             			  //Loop for comparing other values
		{
			if (lettercounter[0][j] < lettercounter[0][i])    //Comparing other array elements
			{
				int tmp = lettercounter[0][i];
				int tmp2 = lettercounter[1][i];				  //Using temporary variable for storing last value
				lettercounter[1][i] = lettercounter[1][j];
				lettercounter[0][i] = lettercounter[0][j]; 
				lettercounter[1][j] = tmp2;					 //replacing value
				lettercounter[0][j] = tmp;					 //storing last value										
			}  
			
		}
	}
	for (int i =26; i<26; i++)
	{
		for (int j = 0; j <26; j++)
		{
			if(alphabet[i] == ciphertable2[j])
			{
				lettercounter[2][j] = ciphertable2[j];	
			}	
		}	
	}
	printf("\n\nLetters in descending order of use:\n");                     	//Printing message
	for (int i = 0; i < 26; i++)                    						    //Loop for printing array data after sorting
	{
		printf("%dx%c's		%c \n", lettercounter[0][i],lettercounter[1][i],lettercounter[2][i]); // pritn out the stored elements from the 3 dimensional array
	}
	
	
// decrypt using the subset key 

for (int j= 0; j<26;j++)
{
	c = alphabet[j];										// letter to check

	for (int i =0; i<=length; i++)							// loop for length of text
	{
		char ec = ciphertext[i];							// letter in cipher to check
		if(ec == c)											// check if the are the same
		{
			decryptedtext[i] = lettercounter[2][j];					// write it to char array
		}
		if(!( ec >=65 && ec <= 90 || ec >=97 && ec <= 122)) // check for no letter char.
		{
			decryptedtext[i] = ciphertext[i];				// write it to array
		}
		if (ec == '\0')										// looking for the end of the string, witohut this i got errors.
		{
			decryptedtext[i] = ec;
		}
	}
}
printf("\nDecrypted text: %s", decryptedtext);				// print to console/terminal
FILE *decrypted;											// new file. 
decrypted = fopen("subdecrytped.txt", "w");					// open the new file for writing (and create it)
fprintf(decrypted,"%s", decryptedtext);						// print the char array to the file.
fclose(decrypted);											// close the file for editing.
return 0;
}