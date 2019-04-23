#include <stdio.h>
#include "rotation.h"
#include "rotationcipher.h"
#include "rotationNoKey.h"
#include "substitution.h"
#include "subnokey.h"


int main()
{

	int result;
	char c;
	
printf( "\n\n\n"
		"####### #     #  #####   #####    #    #####    ###     ###               ######                                                #\n"
		"#       ##    # #     # #     #  ##   #     #  #   #   #   #              #     # #####   ####       # ######  ####  #####     ##\n"
	    "#       # #   # #       #       # #         # #     # #     #             #     # #    # #    #      # #      #    #   #      # #\n"
	    "#####   #  #  # #  #### #  ####   #    #####  #     # #     #    #####    ######  #    # #    #      # #####  #        #        #\n"
		"#       #   # # #     # #     #   #         # #     # #     #             #       #####  #    #      # #      #        #        #\n"
		"#       #    ## #     # #     #   #   #     #  #   #   #   #              #       #   #  #    # #    # #      #    #   #        #\n"
		"####### #     #  #####   #####  #####  #####    ###     ###               #       #    #  ####   ####  ######  ####    #      #####\n\n");
   

	do{
	printf("\nPlease select from the following menu options: \n\n");
	printf("	(a) - Rotation encryption given text and key (file i/o)\n"
			"	(b) - Rotation decryption given text and key (file i/o)\n"
			"	(c) - Rotation decrytpion without key (file i/o)\n"
			"	(d) - Substitution encryption given text and phrase\n"
			"	(e) - Substitution decryption given text and phrase\n"
			"	(f) - Substitition DAY ONE\n"
			"	(g) - Substitution UNSEEN\n"
			"	(x) - Exit\n\n");
	printf("Selection : ");
	scanf("%c", &c);
		if (c == 'x')
		{
			printf("Program exit");
			return 0;
		}
		else if (c < 'a' || c > 'f')
		{
			printf("Invalid selection, try agin.\n\n");
		}
	}
	while (c < 'a' || c > 'f');
	
	switch (c){
	case 'a':	// encrypt rotaation with key
	rotationEncrypt();
	break;	
	case 'b':	// decrypt rotation with key
	rotationDecrypt();
	break;
	case 'c':	//rotation decryption no key
	rotationNoKey();
	break;	
	case 'd':	//sub encryption, known phrase/key
	subEncrypt();
	break;		
	case 'e':	//sub decryption, known phrase/key
	subDecrypt();
	break;
	case 'f':	//sub decryption no key/phrase DAY ONE
	subNoKey();
	break;
	case 'g':	//sub decryption UNSEEN cipher
	break;
	}
return 0;
}