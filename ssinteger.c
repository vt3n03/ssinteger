#include <stdio.h>

void numbers (int number);
int printNumbers (int number);

// fill the 3d array
const char segements[10][3][3] =
  // 0
{ {{' ', '_', ' '}, {'|', ' ', '|'}, {'|', '_', '|'}},
    // 1
{{' ', ' ', ' '}, {' ', ' ', '|'}, {' ', ' ', '|'}},
    // 2
{{' ', '_', ' '}, {' ', '_', '|'}, {'|', '_', ' '}},
    // 3
{{' ', '_', ' '}, {' ', '_', '|'}, {' ', '_', '|'}},
    // 4
{{' ', ' ', ' '}, {'|', '_', '|'}, {' ', ' ', '|'}},
    // 5
{{' ', '_', ' '}, {'|', '_', ' '}, {' ', '_', '|'}},
    // 6
{{' ', '_', ' '}, {'|', '_', ' '}, {'|', '_', '|'}},
    // 7
{{' ', '_', ' '}, {' ', ' ', '|'}, {' ', ' ', '|'}},
    // 8
{{' ', '_', ' '}, {'|', '_', '|'}, {'|', '_', '|'}},
    // 9
{{' ', '_', ' '}, {'|', '_', '|'}, {' ', '_', '|'}}
};

int
main ()
{
    int num = 0;
    char cont = 'Y';
    // Get an integer from the user
  do{
  printf("Enter an integer \n");
  scanf("%d", &num);
  printNumbers (num);
  // Keep looping until the user chooses to exit
  printf("\n Enter Y to enter another number and N to exit: \n");
  scanf(" %c", &cont);
  } while(cont == 'Y');
}

int
printNumbers (int number)
{
   // If number is 0
  if(number == 0){
        for(int q = 0; q < 3; q++){
            for(int p = 0; p < 3; p++){
        printf(" %c", segements[0][q][p]);
            }
        printf(" %c", '\n');
        }
        // exit function
        return -1;
  }
  // negative numbers
  char neg = ' ';
  if (number < 0)
    {
      neg = '_';
      number *= -1;
    }
  // remainder
  int rem;
  // exponent of the current digit
  int i = 1;
  // The number in its correct order
  int back = 0;
  // length of the number
  int length = 0;
  // get length of the number
  while (number != 0)
    {
      rem = number % 10;
      number = (number - rem) / 10;
      back += (rem * i);
      i = i * 10;
      length++;
    }

  // store the number as an array
  int numList[length];
  for (int i = 0; i < length; i++)
    {
      rem = back % 10;
      back = (back - rem) / 10;
      numList[length - 1 - i] = rem;
    }


// print in the correct format
// 3 rows
  for (int i = 0; i < 3; i++)
    {
      // print all characters row by row
      for (int q = 0; q < length; q++)
	{
	  // Print a negtive if number < 0
	  if(i == 1 && neg == '_'){
	  printf (" %c", neg);
	  neg = ' ';
	  } else{
	  printf (" %c", ' ');
	  }
	  printf (" %c", segements[numList[q]][i][0]);
	  printf (" %c", segements[numList[q]][i][1]);
	  printf (" %c", segements[numList[q]][i][2]);
	  }

	  printf (" %c", '\n');
	  }
return 0;
	  }


/*
#include <stdio.h>

// Array to store segments for digits 0 to 9 in a 3x3 grid
const char segments[10][3][3] = {
    // 0
    {{' ', '_', ' '}, {'|', ' ', '|'}, {'|', '_', '|'}},
    // 1
    {{' ', ' ', ' '}, {' ', ' ', '|'}, {' ', ' ', '|'}},
    // 2
    {{' ', '_', ' '}, {' ', '_', '|'}, {'|', '_', ' '}},
    // 3
    {{' ', '_', ' '}, {' ', '_', '|'}, {' ', '_', '|'}},
    // 4
    {{' ', ' ', ' '}, {'|', '_', '|'}, {' ', ' ', '|'}},
    // 5
    {{' ', '_', ' '}, {'|', '_', ' '}, {' ', '_', '|'}},
    // 6
    {{' ', '_', ' '}, {'|', '_', ' '}, {'|', '_', '|'}},
    // 7
    {{' ', '_', ' '}, {' ', ' ', '|'}, {' ', ' ', '|'}},
    // 8
    {{' ', '_', ' '}, {'|', '_', '|'}, {'|', '_', '|'}},
    // 9
    {{' ', '_', ' '}, {'|', '_', '|'}, {' ', '_', '|'}}
};

// Function to display a number in seven-segment format
void displayNumber(char* number) {
    // Iterate through each row of the segments array
    for (int i = 0; i < 3; i++) {
        // Iterate through each character of the input number
        for (int j = 0; number[j] != '\0'; j++) {
            // If the character is '-', print space and dash to represent negative sign
            if (number[j] == '-') {
                printf(" -\n");
            } else {
                // Convert character to integer to get the corresponding digit
                int digit = number[j] - '0';
                // Iterate through each column of the digit's segments
                for (int k = 0; k < 3; k++) {
                    // Print the segment character
                    printf("%c", segments[digit][i][k]);
                }
                // Add a space between digits
                printf(" ");
            }
        }
        // Move to the next row of segments for the next digit
        printf("\n");
    }
}

int main() {
    char choice;
    char input[100];

    do {
        // Ask the user to enter an integer
        printf("Enter an integer: ");
        scanf("%s", input);

        // Call the function to display the number in seven-segment format
        displayNumber(input);

        // Ask the user if they want to continue
        printf("\nDo you want to continue? (Y/N): ");
        scanf(" %c", &choice);

    } while (choice == 'Y' || choice == 'y');

    return 0;
}
*/