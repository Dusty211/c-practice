#include <stdio.h>
#include <string.h>
#include <math.h>

int * return_ints(char *input);

int main() {

  char str[200];
  char output_chars[] = "0123456789abcdefjhijklmnopqrstuvwxwzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char output_hash[200];
  int i;
  int *new_array;
  // size_t new_array_size;


  printf("\nEnter a string to hash, bro: ");
  scanf("%[^\n]%*c", str);

  // for(i = 0; i < strlen(str); i++ ) {
  //   //char type sucks for this - only 256 values:
  //   output_hash[i] = output_chars[str[i] * str[i] % 9 * str[i] * str[i] % 62];
  // }

  //with char types:
  // printf("\nOutput_hash (old ghetto char-type function): %s \n\n", output_hash);

  //function using bigger types - not working as expected
  //not getting intended return from function


  new_array = return_ints(str);

  printf("new_array %d \n\n", new_array[0]);

  for(i = 1; i < new_array[0] + 1; i++ ) {
    printf("%d ", new_array[i]);
  }


  // printf("new_array: %d \n", new_array[25]);
  //
  // size_t new_array_size = sizeof(*new_array) / sizeof(new_array[0]);



  // printf("new array size: %d ", new_array_size);

  return 0;
}

int * return_ints(char *input) {

  int i;
  int int_out[200];
  long long for_math[200];

  for(i = 1; i < strlen(input) + 1; i++ ) {
    for_math[i] = input[i - 1];
    int_out[i] = (((((for_math[i] * for_math[i] * for_math[i]) % 9) + 7) * for_math[i]) * for_math[i]) % 62;
    //debugging
    printf("int_out[i] %i = %d \n", i, int_out[i]);
  }
  int_out[0] = strlen(input);
  printf("int_out[0] (length) = %d \n", int_out[0]);

  return int_out;
}
