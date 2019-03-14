#include <stdio.h>
#include <string.h>
#include <math.h>

int return_floats(char *input);

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

  for(i = 0; i < strlen(str); i++ ) {
    //char type sucks for this - only 256 values:
    output_hash[i] = output_chars[str[i] * str[i] % 9 * str[i] * str[i] % 62];

    //for debugging:
    printf("Output_hash index %i = %d \n", i, output_hash[i]);
  }

  //with char types:
  printf("\nOutput_hash: %s \n", output_hash);

  //function using bigger types - not working as expected
  //not getting intended return from function
  new_array = return_floats(str);
  printf("new_array: %d \n", new_array);

  return 0;
}

int return_floats(char *input) {

  int i;
  int int_out[200];
  long long for_math[200];

  for(i = 0; i < strlen(input); i++ ) {
    for_math[i] = input[i];
    int_out[i] = (((((for_math[i] * for_math[i] * for_math[i]) % 9) + 7) * for_math[i]) * for_math[i]) % 62;
    //debugging
    printf("int_out[i] %i = %d \n", i, int_out[i]);
    // printf("for_math[i] %i = %lld \n", i, for_math[i]);

  }
  return *int_out;
}
