#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {

  // unsigned char str[100];
  long double str[100];
  char output_chars[] = "0123456789abcdefjhijklmnopqrstuvwxwzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char output_hash[100];
  int i;


  printf("\nEnter a string to hash, bro: ");
  scanf("%[^\n]%*c", &str);
  printf("Your hash before: %s \n", (char)str);

  for(i = 0; i < strlen(str); i++ ) {
    output_hash[i] = output_chars[str[i] * str[i] % 9 * str[i] * str[i] % 62];
  }

  //for debugging:
  for(i = 0; i < strlen(str); i++ ) {
    printf("Output_hash index %i = %d \n", i, output_hash[i]);
  }

  printf("\nOutput_hash: %s \n", output_hash);

  return 0;
}
