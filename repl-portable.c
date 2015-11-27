#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <string.h>

static char buffer[2048];

/* readline() wrapper for windows */
char * readline(char *prompt)
{
	fputs(prompt, stdout);
	fgets(buffer, 2048, stdin);
	/* Dynamically allocate memory as we use free()
	 * later on
	*/
	 char *cpy = malloc(strlen(buffer) + 1);
	 strcpy(cpy, buffer);
	 /* Assign terminating NULL character */
	 cpy[strlen(cpy) - 1] = '\0';
	 return cpy;
}

/* add_history() wrapper for windows */
void add_history(char *unused){ }

#else
/* For readline() and add_history() */
#include <editline/readline.h>
#include <editline/history.h>
#endif

int main(int argc, char **argv)
{
	/* Print Version and Exit information */
	puts("Blisp ver. 0.0.1");
	puts("Press Ctrl+C to Exit\n");

	while(1)
	{
		/* Displays prompt, allocates memory and
		 * stores input
		*/
		char *input = readline("Blisp> ");
		/* Add input to history */
		add_history(input);
		printf("After complex calculations, geeky "
			"looking output is: %s\n", input);
		/* free() is required as readline() allocates fresh
		 * memory every time
		*/
		free(input);
	}
	return 0;
}