#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <math.h>

int * return_ints(char *input);

int main() {

  char str[200];
  char output_chars[] = "0123456789abcdefjhijklmnopqrstuvwxyz";
  int i;
  int *new_array;

  printf("\nEnter a string to hash, bro: ");
  scanf("%[^\n]%*c", str);

  new_array = return_ints(str);

  for(i = 1; i < new_array[0] + 1; i++ ) {
    printf("%c", output_chars[new_array[i]]);
  }
  free(new_array);

  return 0;
}

int * return_ints(char *input) {

  int i;
  int *int_out = malloc (sizeof (int) * 200);
  long long for_math[200];
  long long element_summary = 0;
  long long multiplier;

  for(i = 0; i < strlen(input); i++) {
    element_summary = element_summary + input[i];
    // printf("sum for %i = %lld\n", i, element_summary);
  }

  element_summary = ((element_summary * element_summary * element_summary % 23) + 1) * 100000 % 256;

  for(i = 1; i < strlen(input) + 1; i++ ) {
    for_math[i] = input[i - 1];
    multiplier = for_math[i] + strlen(input) + 100;
    int_out[i] = (((((element_summary * element_summary * multiplier * multiplier) % 11) + strlen(input) + i) * multiplier) * multiplier) % 36;
    //debugging
    // printf("int_out[i] %i = %d \n", i, int_out[i]);
  }
  int_out[0] = strlen(input);
  printf("int_out[0] (length) = %d \n", int_out[0]);

  return int_out;
}
