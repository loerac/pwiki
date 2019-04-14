#include <stdio.h>

char strA[80] = "A string to be used for demonstration purposes";
char strB[80];

/* Copy "source" into "destination" until the nul character */
char *my_strcpy(char *destination, const char *source) {
	char *p = destination;
	while (*source != '\0') {
		*p++ = *source++;
	}
	*p = '\0';

	return destination;
}

/**
 * Copy "source" into "destination" until the number of
 * characters copied is greater than "size" or until
 * "source" reaches the nul character.
 **/
int my_strncpy(char *destination, const char *source, const int size) {
	int i = 0;
	char *p = destination;
	while ( (size > i++) &&
		(*source != '\0') ) {
		*p++ = *source++;
	}
	*p = '\0';

   return i;
}

int main( void ) {
   char *pA;         /* A pointer to type character */
   char *pB;         /* Another pointer to type characters */

   puts(strA);       /* Show string A */
   pA = strA;        /* Point pA at string A */
   puts(pA);         /* Show what pA is pointing to */

   pB = strB;        /* Point pB at strig B */
   putchar('\n');    /* Move down one line on the screen */

   //(void)my_strcpy(strB, strA);
   //(void)my_strncpy(strB, strA, sizeof(strA));

   /**
    * While the character at *pA is not a nul character,
    * do the following
    **/
   while (*pA != '\0') {
      /**
       * Copy the character at *pA to *pB.
       * Increment *pA and *pB to the next space
       **/
      *pB++ = *pA++;
   }

   /* Copy the nul character to the end of the string */
   *pB = '\0';
   puts(strB);       /* Show strB on screen */

   return 0;
}
