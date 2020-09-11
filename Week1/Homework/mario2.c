#include <cs50.h>
#include <stdio.h>
int get_positive_int(string prompt);
int main(void)
{
    int row,column,space;
    int height = get_positive_int("Height: ");
    for (row = 0; row < height; row++)
  {
      for(space=0;space < height-row-1;space++){
          printf(" ");
      }
      for (column = 0; column <= row; column++)
      {
          printf("#");
      }
      printf("  ");
      for(column = 0; column <= row; column++){
          printf("#");
      }
      printf("\n");
  }
}

// Prompt user for positive integer
int get_positive_int(string prompt)
{
    int n;
    do
    {
        n = get_int("%s", prompt);
    }
    while (n < 1 || n >8);
    return n;
}
