#include <stdio.h>
#include <string.h>
#include <math.h>

int return_floats(char input);

int main() {

  // unsigned char str[100];
  char str[200];
  char output_chars[] = "0123456789abcdefjhijklmnopqrstuvwxwzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char output_hash[200];
  int i;
  int new_array;


  printf("\nEnter a string to hash, bro: ");
  scanf("%[^\n]%*c", str);
  printf("Your hash before: %s \n", str);

  new_array = return_floats(str);
  printf("new_array: %i \n", new_array);

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

int return_floats(char input) {

  int i;
  int int_out[200];
  long double for_math[200];

  for(i = 0; i < strlen(input); i++ ) {
    for_math[i] = input[i];

    int_out[i] = for_math[i] * for_math[i] % 9 * for_math[i] * for_math[i] % 62;
    return int_out;
  }
}
