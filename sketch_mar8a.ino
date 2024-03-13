// Include Arduino Wire library for I2C
#include <Wire.h>
// Include LCD display library for I2C
#include <LiquidCrystal_I2C.h>
// Include Keypad library
#include <Keypad.h>

// Counter for character entries
byte data_count = 0;

// Character to hold key input
char customKey;

// Constants for row and column sizes
const byte ROWS = 4;
const byte COLS = 3;

// Array to represent keys on keypad
char hexaKeys[ROWS][COLS] = {
    {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}, {'*', '0', '#'}};

// Connections to Arduino
byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {6, 7, 8};

// Create keypad object
Keypad customKeypad =
    Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

// Create LCD object
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Defining local variables.
const int matrixTransposePin = 9, matrixMultiplyPin = 10, yesButtonPin = 11;

// Function clear the screen easily.
void clearScreen() { lcd.clear(); }

// Multiply the matrices function.
void matrixMultiply() {
  // Defining input variables
  int userChoice2 = 0;
  int userChoice3 = 0;

  // Defining user input variables.
  int matrixRowsA = 0, matrixColumnsA = 0;
  int matrixRowsB = 0, matrixColumnsB = 0;
  int cursorPosition = 0;

  do{
  // Prompting the user with the entering the first matrix dimension.
  clearScreen();
  lcd.setCursor(0, 0);
  lcd.print("Enter 1st Mat.");
  lcd.setCursor(0, 1);
  lcd.print("dimensions: ");
  delay(1500);
  clearScreen();

  // Requesting Number of Rows.
  lcd.print("Enter 1st Matrix");
  lcd.setCursor(0, 1);
  lcd.print("Row Number: ");

  matrixRowsA = 0; // Reset matrixRowsA for if do/while loop condition is true.
  bool enteredRowA =
      false;  // Flag to check if a digit has been entered for matrixRows

  while (true) {
    customKey = customKeypad.getKey();
    if (customKey) {
      // Check if the user pressed '#', indicating the end of input
      if (customKey == '#') {
        clearScreen();
        break;
      }

      // Check if a digit has already been entered for matrixRows
      if (!enteredRowA && isDigit(customKey)) {
        // Print the entered key on the LCD
        lcd.print(customKey);

        // Convert char to integer and update matrixRows
        matrixRowsA = matrixRowsA * 10 + (customKey - '0');
        enteredRowA = true;  // Set the flag to true after entering a digit

        delay(100);  // Add a small delay to avoid key bouncing
      }
    }
  }

  // Display the entered value
  clearScreen();
  lcd.print("Entered Rows: ");
  lcd.print(matrixRowsA);
  delay(2000);
  clearScreen();

  // Requesting number of Columns.
  lcd.setCursor(0, 0);
  lcd.print("Enter 1st Mat.");
  lcd.setCursor(0, 1);
  lcd.print("Columns: ");

  matrixColumnsA = 0; // Reset matrixColumnsA for if do/while loop condition is true.
  bool enteredColumnA =
      false;  // Flag to check if a digit has been entered for matrixColumns

  while (true) {
    customKey = customKeypad.getKey();
    if (customKey) {
      // Check if the user pressed '#', indicating the end of input
      if (customKey == '#') {
        clearScreen();
        break;
      }

      // Check if a digit has already been entered for matrixColumns
      if (!enteredColumnA && isDigit(customKey)) {
        // Print the entered key on the LCD
        lcd.print(customKey);

        // Convert char to integer and update matrixColumns
        matrixColumnsA = matrixColumnsA * 10 + (customKey - '0');
        enteredColumnA = true;  // Set the flag to true after entering a digit

        delay(100);  // Add a small delay to avoid key bouncing
      }
    }
  }

  // Display the entered value
  clearScreen();
  lcd.setCursor(0, 0);
  lcd.print("Entered Columns: ");
  lcd.setCursor(0, 1);
  lcd.print(matrixColumnsA);
  delay(2000);

  // Prompting the user with the entering the Second matrix dimension.
  clearScreen();
  lcd.setCursor(0, 0);
  lcd.print("Enter 2nd Mat.");
  lcd.setCursor(0, 1);
  lcd.print("dimensions: ");
  delay(2000);
  clearScreen();

  // Requesting Number of Rows.
  lcd.print("Enter 2nd Matrix");
  lcd.setCursor(0, 1);
  lcd.print("Row Number: ");
  
  matrixRowsB = 0; // Reset matrixRowsB for if do/while loop condition is true.
  bool enteredRowB =
      false;  // Flag to check if a digit has been entered for matrixRows

  while (true) {
    customKey = customKeypad.getKey();
    if (customKey) {
      // Check if the user pressed '#', indicating the end of input
      if (customKey == '#') {
        break;
      }

      // Check if a digit has already been entered for matrixRows
      if (!enteredRowB && isDigit(customKey)) {
        // Print the entered key on the LCD
        lcd.print(customKey);

        // Convert char to integer and update matrixRows
        matrixRowsB = matrixRowsB * 10 + (customKey - '0');
        enteredRowB = true;  // Set the flag to true after entering a digit

        delay(100);  // Add a small delay to avoid key bouncing
      }
    }
  }

  // Display the entered value
  clearScreen();
  lcd.print("Entered Rows: ");
  lcd.print(matrixRowsB);
  delay(2000);
  clearScreen();

  // Requesting number of Columns.
  lcd.setCursor(0, 0);
  lcd.print("Enter 2nd Mat.");
  lcd.setCursor(0, 1);
  lcd.print("Columns: ");
  
  matrixColumnsB = 0; // Reset matrixColumnsB for if do/while loop condition is true.
  bool enteredColumnB =
      false;  // Flag to check if a digit has been entered for matrixColumns

  while (true) {
    customKey = customKeypad.getKey();
    if (customKey) {
      // Check if the user pressed '#', indicating the end of input
      if (customKey == '#') {
        break;
      }

      // Check if a digit has already been entered for matrixColumns
      if (!enteredColumnB && isDigit(customKey)) {
        // Print the entered key on the LCD
        lcd.print(customKey);

        // Convert char to integer and update matrixColumns
        matrixColumnsB = matrixColumnsB * 10 + (customKey - '0');
        enteredColumnB = true;  // Set the flag to true after entering a digit

        delay(100);  // Add a small delay to avoid key bouncing
      }
    }
  }
  // Display the entered value
  clearScreen();
  lcd.setCursor(0, 0);
  lcd.print("Entered Columns: ");
  lcd.setCursor(0, 1);
  lcd.print(matrixColumnsB);
  delay(2000);

  //Checking if the Condition to multiply matrices is True or False.
  if(matrixColumnsA != matrixRowsB) {
    clearScreen();
    lcd.setCursor(0, 0);
    lcd.print("Invalid Input.");
    lcd.setCursor(0, 1);
    lcd.print("To Multiply: ");
    delay(2000);
    clearScreen();
    lcd.setCursor(0, 0);
    lcd.print("1st columns ==");
    lcd.setCursor(0, 1);
    lcd.print("2nd Rows");
    delay(2000);
    clearScreen();
  }
  }while(matrixColumnsA != matrixRowsB);

  // Defining the First matrix whose dimensions the user entered.
  int matrixA[matrixRowsA][matrixColumnsA];

  // Defining the First matrix whose dimensions the user entered.
  int matrixB[matrixRowsB][matrixColumnsB];

  //Prompting the user with first matrix input.
  clearScreen();
  lcd.setCursor(0, 0);
  lcd.print("Enter the 1st");
  lcd.setCursor(0, 1);
  lcd.print("Matrix Elements.");
  delay(2000);

  // Making a Loop for if the userChoice is no and for the First Matrix in
  // general.
  do {
    // Creating a loop for the user to assign the matrix values element by
    // element.
    for (int i = 0; i < matrixRowsA; i++) {
      for (int j = 0; j < matrixColumnsA; j++) {
        clearScreen();
        lcd.setCursor(0, 0);
        lcd.print("Enter element at ");
        lcd.setCursor(0, 1);
        lcd.print("(");
        lcd.print(i + 1);
        lcd.print(", ");
        lcd.print(j + 1);
        lcd.print("): ");

        bool enteredNumber = false;
        int value = 0;  // The variable value is to store the current entered
                        // value for each matrix element.

        while (true) {
          customKey = customKeypad.getKey();
          if (customKey) {
            // Check if the user pressed '#', indicating the end of input
            if (customKey == '#') {
              break;
            }

            // Check if a digit has already been entered
            if (!enteredNumber && (isDigit(customKey) || customKey == '-')) {
              // Print the entered key on the LCD
              lcd.print(customKey);

              // Convert char to integer and update the current value
              value = value * 10 + (customKey - '0');

              delay(100);  // Add a small delay to avoid key bouncing
            }
          }
        }

        // Assign the value to the matrixA element
        matrixA[i][j] = value;
      }
    }

    // Creating a loop to prompt the user with the values of the First matrix
    // entered.
    for (int i = 0; i < matrixRowsA; i++) {
      for (int j = 0; j < matrixColumnsA; j++) {
        clearScreen();
        lcd.setCursor(0, 0);
        lcd.print("Value Entered at");
        lcd.setCursor(0, 1);
        lcd.print("(");
        lcd.print(i + 1);
        lcd.print(", ");
        lcd.print(j + 1);
        lcd.print("): ");
        lcd.print(matrixA[i][j]);
        delay(2000);
      }
    }

    // Asking the user if the entered values are correct or not.
    clearScreen();
    lcd.setCursor(0, 0);
    lcd.print("Are the Values");
    lcd.setCursor(0, 1);
    lcd.print("Correct?");
    delay(1000);
    clearScreen();
    lcd.setCursor(0, 0);
    lcd.print("Enter 1-->Yes");
    lcd.setCursor(0, 1);
    lcd.print("Enter 0-->No: ");

    bool enteredUserChoice2 = false;

    while (true) {
      customKey = customKeypad.getKey();
      if (customKey) {
        // Check if the user pressed '#', indicating the end of input
        if (customKey == '#') {
          break;
        }

        // Check if a digit has already been entered for userChoice
        if (!enteredUserChoice2 && isDigit(customKey)) {
          // Print the entered key on the LCD
          lcd.print(customKey);

          // Convert char to integer and update userChoice
          userChoice2 = userChoice2 * 10 + (customKey - '0');
          enteredUserChoice2 =
              true;  // Set the flag to true after entering a digit

          delay(100);  // Add a small delay to avoid key bouncing
        }
      }
    }

  } while (userChoice2 == 0);

  //Prompting the user with Second matrix input.
  clearScreen();
  lcd.setCursor(0, 0);
  lcd.print("Enter the 2nd");
  lcd.setCursor(0, 1);
  lcd.print("Matrix Elements.");
  delay(2000);

  // Making a Loop for the second Matrix input and if the user entered No.
  do {
    // Creating a loop for the user to assign the matrix values element by
    // element.
    for (int i = 0; i < matrixRowsB; i++) {
      for (int j = 0; j < matrixColumnsB; j++) {
        clearScreen();
        lcd.setCursor(0, 0);
        lcd.print("Enter element at ");
        lcd.setCursor(0, 1);
        lcd.print("(");
        lcd.print(i + 1);
        lcd.print(", ");
        lcd.print(j + 1);
        lcd.print("): ");

        bool enteredNumber = false;
        int value = 0;  // The variable value is to store the current entered
                        // value for each matrix element.

        while (true) {
          customKey = customKeypad.getKey();
          if (customKey) {
            // Check if the user pressed '#', indicating the end of input
            if (customKey == '#') {
              break;
            }

            // Check if a digit has already been entered
            if (!enteredNumber && (isDigit(customKey) || customKey == '-')) {
              // Print the entered key on the LCD
              lcd.print(customKey);

              // Convert char to integer and update the current value
              value = value * 10 + (customKey - '0');

              delay(100);  // Add a small delay to avoid key bouncing
            }
          }
        }

        // Assign the value to the matrixA element
        matrixB[i][j] = value;
      }
    }

    // Creating a loop to prompt the user with the values of the First matrix
    // entered.
    for (int i = 0; i < matrixRowsB; i++) {
      for (int j = 0; j < matrixColumnsB; j++) {
        clearScreen();
        lcd.setCursor(0, 0);
        lcd.print("Value Entered at");
        lcd.setCursor(0, 1);
        lcd.print("(");
        lcd.print(i + 1);
        lcd.print(", ");
        lcd.print(j + 1);
        lcd.print("): ");
        lcd.print(matrixB[i][j]);
        delay(2000);
      }
    }

    // Asking the user if the entered values are correct or not.
    clearScreen();
    lcd.setCursor(0, 0);
    lcd.print("Are the Values");
    lcd.setCursor(0, 1);
    lcd.print("Correct?");
    delay(1000);
    clearScreen();
    lcd.setCursor(0, 0);
    lcd.print("Enter 1-->Yes");
    lcd.setCursor(0, 1);
    lcd.print("Enter 0-->No: ");

    bool enteredUserChoice3 = false;

    while (true) {
      customKey = customKeypad.getKey();
      if (customKey) {
        // Check if the user pressed '#', indicating the end of input
        if (customKey == '#') {
          break;
        }

        // Check if a digit has already been entered for userChoice
        if (!enteredUserChoice3 && isDigit(customKey)) {
          // Print the entered key on the LCD
          lcd.print(customKey);

          // Convert char to integer and update userChoice
          userChoice3 = userChoice3 * 10 + (customKey - '0');
          enteredUserChoice3 =
              true;  // Set the flag to true after entering a digit

          delay(100);  // Add a small delay to avoid key bouncing
        }
      }
    }

  } while (userChoice3 == 0);

  // Defining the Result matrix which is the multiplication of both matrixA and matrixB.
  int resultMatrix[matrixRowsA][matrixColumnsB];

  // Initialize resultMatrix to zero to prevent errors.
  for (int i = 0; i < matrixRowsA; i++) {
    for (int j = 0; j < matrixColumnsB; j++) {
    resultMatrix[i][j] = 0;
  }
}

  //Making a loop that performs the multiplication process.
  for (int i = 0; i < matrixRowsA; i++) {
    for (int j = 0; j < matrixColumnsB; j++) {
      for (int k = 0; k < matrixColumnsA; k++) {
        resultMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
      }
    }
  } 

  //Displaying the result matrix for the user on screen.
    for (int i = 0; i < matrixRowsA; i++) {
      for (int j = 0; j < matrixColumnsB; j++) {
        clearScreen();
        lcd.setCursor(0, 0);
        lcd.print("Multi result at:");
        lcd.setCursor(0, 1);
        lcd.print("(");
        lcd.print(i + 1);
        lcd.print(", ");
        lcd.print(j + 1);
        lcd.print("): ");
        lcd.print(resultMatrix[i][j]);
        delay(3000);
      }
    }

    //Clearing the screen at the end of the function to prevent any screen glitches.
    clearScreen();
    delay(300);
}

void setup() {
  // Setup LCD with backlight and initialize
  lcd.backlight();
  lcd.init();

  // Setting the button pins to state INPUT.
  pinMode(matrixTransposePin, INPUT);
  pinMode(matrixMultiplyPin, INPUT);
  pinMode(yesButtonPin, INPUT);
}

void loop() {
  // Defining input variables.
  int matrixTranspose = digitalRead(matrixTransposePin);
  int matrixMultiplyBtn = digitalRead(matrixMultiplyPin);
  int yesButton = digitalRead(yesButtonPin);
  int userChoice = 0;

  // Defining user input variables.
  int matrixRows = 0, matrixColumns = 0;

  // Waiting for user input.
  lcd.noAutoscroll();
  lcd.setCursor(0, 0);
  lcd.print("Press Any of");
  lcd.setCursor(0, 1);
  lcd.print("The Buttons.");

  // Look for buttonpress.
  if (matrixTranspose == HIGH) {
    clearScreen();

    // Requesting Number of Rows.
    lcd.print("Enter Matrix");
    lcd.setCursor(0, 1);
    lcd.print("Row Number: ");

    bool enteredRow =
        false;  // Flag to check if a digit has been entered for matrixRows

    while (true) {
      customKey = customKeypad.getKey();
      if (customKey) {
        // Check if the user pressed '#', indicating the end of input
        if (customKey == '#') {
          break;
        }

        // Check if a digit has already been entered for matrixRows
        if (!enteredRow && isDigit(customKey)) {
          // Print the entered key on the LCD
          lcd.print(customKey);

          // Convert char to integer and update matrixRows
          matrixRows = matrixRows * 10 + (customKey - '0');
          enteredRow = true;  // Set the flag to true after entering a digit

          delay(100);  // Add a small delay to avoid key bouncing
        }
      }
    }

    // Display the entered value
    clearScreen();
    lcd.print("Entered Rows: ");
    lcd.print(matrixRows);
    delay(2000);
    clearScreen();

    // Requesting number of Columns.
    lcd.setCursor(0, 0);
    lcd.print("Please enter No.");
    lcd.setCursor(0, 1);
    lcd.print("Of Columns: ");

    bool enteredColumn =
        false;  // Flag to check if a digit has been entered for matrixColumns

    while (true) {
      customKey = customKeypad.getKey();
      if (customKey) {
        // Check if the user pressed '#', indicating the end of input
        if (customKey == '#') {
          break;
        }

        // Check if a digit has already been entered for matrixColumns
        if (!enteredColumn && isDigit(customKey)) {
          // Print the entered key on the LCD
          lcd.print(customKey);

          // Convert char to integer and update matrixColumns
          matrixColumns = matrixColumns * 10 + (customKey - '0');
          enteredColumn = true;  // Set the flag to true after entering a digit

          delay(100);  // Add a small delay to avoid key bouncing
        }
      }
    }

    // Display the entered value
    clearScreen();
    lcd.setCursor(0, 0);
    lcd.print("Entered Columns: ");
    lcd.setCursor(0, 1);
    lcd.print(matrixColumns);
    delay(2000);

    // Defining the untransposed matrix whose dimensions the user entered.
    int matrixA[matrixRows][matrixColumns];

    // Making a Loop for if the userChoice is no
    do {
      // Creating a loop for the user to assign the matrix values element by
      // element.
      for (int i = 0; i < matrixRows; i++) {
        for (int j = 0; j < matrixColumns; j++) {
          clearScreen();
          lcd.setCursor(0, 0);
          lcd.print("Enter element at ");
          lcd.setCursor(0, 1);
          lcd.print("(");
          lcd.print(i + 1);
          lcd.print(", ");
          lcd.print(j + 1);
          lcd.print("): ");

          bool enteredNumber = false;
          int value = 0;  // The variable value is to store the current entered
                          // value for each matrix element.

          while (true) {
            customKey = customKeypad.getKey();
            if (customKey) {
              // Check if the user pressed '#', indicating the end of input
              if (customKey == '#') {
                break;
              }

              // Check if a digit has already been entered
              if (!enteredNumber && (isDigit(customKey) || customKey == '-')) {
                // Print the entered key on the LCD
                lcd.print(customKey);

                // Convert char to integer and update the current value
                value = value * 10 + (customKey - '0');

                delay(100);  // Add a small delay to avoid key bouncing
              }
            }
          }

          // Assign the value to the matrixA element
          matrixA[i][j] = value;
        }
      }

      // Creating a loop to prompt the user with the values of the matrix
      // entered.
      for (int i = 0; i < matrixRows; i++) {
        for (int j = 0; j < matrixColumns; j++) {
          clearScreen();
          lcd.setCursor(0, 0);
          lcd.print("Value Entered at");
          lcd.setCursor(0, 1);
          lcd.print("(");
          lcd.print(i + 1);
          lcd.print(", ");
          lcd.print(j + 1);
          lcd.print("): ");
          lcd.print(matrixA[i][j]);
          delay(2000);
        }
      }

      // Asking the user if the entered values are correct or not.
      clearScreen();
      lcd.setCursor(0, 0);
      lcd.print("Are the Values");
      lcd.setCursor(0, 1);
      lcd.print("Correct?");
      delay(1000);
      clearScreen();
      lcd.setCursor(0, 0);
      lcd.print("Enter 1-->Yes");
      lcd.setCursor(0, 1);
      lcd.print("Enter 0-->No: ");

      bool enteredUserChoice = false;

      while (true) {
        customKey = customKeypad.getKey();
        if (customKey) {
          // Check if the user pressed '#', indicating the end of input
          if (customKey == '#') {
            break;
          }

          // Check if a digit has already been entered for userChoice
          if (!enteredUserChoice && isDigit(customKey)) {
            // Print the entered key on the LCD
            lcd.print(customKey);

            // Convert char to integer and update userChoice
            userChoice = userChoice * 10 + (customKey - '0');
            enteredUserChoice =
                true;  // Set the flag to true after entering a digit

            delay(100);  // Add a small delay to avoid key bouncing
          }
        }
      }
    } while (userChoice == 0);

    // Defining the transposed matrix to store the transposed matrixA.
    int transposedMatrix[matrixRows][matrixColumns];

    // Creating a loop for the transposition operation and storing the values in
    // a new matrix.
    for (int i = 0; i < matrixRows; i++) {
      for (int j = 0; j < matrixColumns; j++) {
        transposedMatrix[j][i] = matrixA[i][j];
      }
    }

    // Printing out the transposed matrix the user entered.
    for (int i = 0; i < matrixRows; i++) {
      for (int j = 0; j < matrixColumns; j++) {
        clearScreen();
        lcd.setCursor(0, 0);
        lcd.print("Transposed Ele. at:");
        lcd.setCursor(0, 1);
        lcd.print("(");
        lcd.print(i + 1);
        lcd.print(", ");
        lcd.print(j + 1);
        lcd.print("): ");
        lcd.print(transposedMatrix[i][j]);
        delay(3000);
      }
    }

    // Clearing screen of any previous messages and waiting for user input.
    clearScreen();
    delay(500);
  }

  if (matrixMultiplyBtn == HIGH) {
    clearScreen();
    // Calling the MatrixMultiply function.
    matrixMultiply();
  }
}