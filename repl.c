#include <stdio.h>

/* Buffer for user input */
static char input[2048];

int main(int argc, char **argv)
{
	/* Print version and exit command */
	puts("Blisp ver. 0.0.1");
	puts("Press Ctrl+C to Exit\n");

	while(1)
	{
		/* Prompt */
		fputs("Blisp> ", stdout);
		fgets(input, 2048, stdin);
		printf("After complex calculations, geeky "
			"looking output is: %s", input);
	}
	return 0;
}