#include <stdio.h>
#include <stdlib.h>
/* For readline() and add_history() */
#include <editline/readline.h>
#include <editline/history.h>

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