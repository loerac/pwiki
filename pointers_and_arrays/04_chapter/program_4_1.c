#include <stdio.h>
#include <string.h>

unsigned int my_strlen(const char *string) {
   unsigned int i = 0;

   while (*string++ != '\0') {
      i++;
   }

   return i;
}

unsigned int my_strcat(char *dest, const char *src) {
   char *ptr = dest;
   unsigned int i = 0;
   if (  (*src != '\0') &&
         (*ptr != '\0') ) {

      while (*ptr != '\0') {
         ptr++;
      }

      while (*src != '\0') {
         *ptr++ = *src++;
         i++;
      }
      *ptr = '\0';
   }

   return i;
}

char *my_strchr(char *haystack, const char needle) {
   while (  (*haystack != needle) &&
            (*haystack++ != '\0') ) {
   }

   return haystack;
}

int main(int argc, char *argv[]) {
   char string_1[20] = "Periphery";
   const unsigned int string_1_len = my_strlen(string_1);
   printf("%s is %d characters long without the nul character\n", string_1, string_1_len);

   const char *const string_2 = " Rocks";
   printf("String 1 before: %s\n", string_1);
   (void)my_strcat(string_1, string_2);
   printf("String 1 after: %s\n", string_1);

   const char *const string_3 = my_strchr(string_1, 'h');
   printf("String 3: %s\n", string_3);

   return 0;
}
