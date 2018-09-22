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

void palin() {

}

//Takes in a string, and a number for the switch case on what to change the chars to
void cascnvt(char **c, int s) {
	switch(s) {
		case 0:
			//reverse the cases that are given
			for(int i = 0; i < strlen(c); i++) {
				if(islower(c[i]) == 0) {
					toupper(c[i]);
					printf("%c\n", c[i]);
				}
				else {
					tolower(c[i]);
					printf("you fucked up\n");
				}
			}
			break;
		case 1:
			//convert all the chars to lower case
		printf("this didnt work\n");
			break;
		case 2:
			//convert all the chars to upper case
			printf("this didnt work\n");
			break;
		default:
			printf("You fucked up\n");
			break;
	}
	printf("This: %s\n", *c);
}

int main(void) {
	char buffer[102];
	printf("%s", "Enter a command: \n");
	char cmd[67];
	scanf("%s", cmd);
	char *token;
	char breaker[2] = " ";
	token = strtok(cmd, breaker);
	while(strcmp(token, "exit") != 0) {
		//printf("%s", buffer);
		if(strcmp(token, "palin") == 0) {
			printf("this worked\n");
			char *k = "ab";
			int j = 0;
			cascnvt(&k, 0);
		}
		printf("%s", "Enter a command: \n");
		scanf("%s", cmd);
		token = strtok(cmd, breaker);
	}
}