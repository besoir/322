#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * Three commands: palin, cascnvt, exit
 * palin: flips the entered text and the sentence
 * ex) a man, a plan, a canal
 * lanac a, nalp a, nam a
 */

void palin(char *forwards) {
	char *backwards = malloc(sizeof(forwards));
	int f = strlen(forwards) - 1;
	int b = 0;
	while(b < strlen(forwards)) {
		backwards[b] = forwards[f];
		f--;
		b++;
	}

	for(int j = 0; j < sizeof(forwards); j++){
	  if(forwards[j] == ' ' || forwards[j] == ',' || forwards[j] == '.' || forwards[j] == ';'
	     || forwards[j] == ':' || forwards[j] == '!' || forwards[j] == '?') {
	    for(int p = j; p <= sizeof(forwards); p++)
	       forwards[p] = forwards[p+1];
	  }
        }
	
	char *backnospace = malloc(sizeof(backwards));
	strcpy(backnospace, backwards);

	for(int u = 0; u < sizeof(backnospace); u++){
	  if(backnospace[u] == ' ' || backnospace[u] == ',' || backnospace[u] == '.' || backnospace[u] == ';'
	     || backnospace[u] == ':' || backnospace[u] == '!' || backnospace[u] == '?') {
	    for(int p = u; p <= sizeof(backnospace); p++)
	       backnospace[p] = backnospace[p+1];
	  }
        }
	
	printf("%s for, %s back\n", forwards,backnospace);
	//Since we have the arguments in forward and reverse, compare the two
	if(strcmp(forwards, backnospace) == 0)
		printf("%s <- palindrome \n", backwards);
	else
		printf("%s <- no palindrome \n", backwards);
	free(backwards);
	free(backnospace);
}

//Takes in a string, and a number for the switch case on what to change the chars to
char* cascnvt(char *c, int s) {
	switch(s) {
		case 0:
			//reverse the cases that are given
			for(int i = 0; i < strlen(c); i++) {
				//Change a lower case letter to upper case
				if(islower(c[i]) != 0) 
					c[i] = toupper(c[i]);
				else 
					c[i] = tolower(c[i]);
			}
			break;
		case 1:
			//This case will convert all the chars to lower case
			//Iterate through the char pointer
			for(int i = 0; i < strlen(c); i++) {
				//Change the char at i to lower case
				c[i] = tolower(c[i]);
			}
			break;
		case 2:
			//convert all the chars to upper case
			for(int i = 0; i < strlen(c); i++) {
				//Change the char at i to upper case
				c[i] = toupper(c[i]);
			}
			break;
		default:
			printf("You fucked up\n");
			break;
	}

	return c;
}

int main(void) {
  printf("%s\n", "Enter cascnvt, palin, or exit");
	printf("%s", "thanley>$ ");
	char cmd[67];
	//scanf("%s", cmd);
	fgets(cmd, sizeof(cmd), stdin);
	char *token;
	char *decisions;
	token = strtok(cmd, "(");
	decisions = strtok(NULL, ")");
	while(strcmp(token, "exit") != 0) {
		//If the user enters cascnvt
		if(strcmp(token, "cascnvt") == 0) {
			//tokenize the string to be adjusted
			char *tokenTwo;
			tokenTwo = strtok(decisions, ",");
			char *tokenThree;
			tokenThree = strtok(NULL, ")");
			if(strcmp(tokenThree, "0") == 0)
				tokenTwo = cascnvt(tokenTwo, 0);
			else if(strcmp(tokenThree, "1") == 0)
				tokenTwo = cascnvt(tokenTwo, 1);
			else if(strcmp(tokenThree, "2") == 0)
				tokenTwo = cascnvt(tokenTwo, 2);
			else
				printf("Incorrect");
			printf("%s\n", tokenTwo);
		}

		//If the user enters palin
		if(strcmp(token, "palin") == 0) {
			int i = 0;
			int j = 6;
			palin(decisions);
		}
		printf("%s\n", "Enter cascnvt, palin, or exit ");
		printf("%s", "thanley>$");
		fgets(cmd, sizeof(cmd), stdin);
		token = strtok(cmd, "(");
		decisions = strtok(NULL, ")");
	}
}
