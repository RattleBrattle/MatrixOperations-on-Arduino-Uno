# Arduino Matrix Calculator

A versatile Arduino project for matrix operations using a keypad and an LCD display.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Components](#components)
- [Setup](#setup)
- [Usage](#usage)
- [Code Structure](#code-structure)
- [Contributing](#contributing)
- [License](#license)

## Introduction

This Arduino project is designed for integer matrix operations, allowing users to perform matrix transposition and multiplication with the help of a keypad and an LCD display. It provides a user-friendly interface for entering matrix dimensions and values.
You can find A video of it working on my LinkedIn [https://www.linkedin.com/posts/basel-sayed-b11534243_arduino-opensource-matrixoperations-activity-7173627131460096001-TM3p?utm_source=share&utm_medium=member_desktop].

## Features

- Matrix transposition
- Matrix multiplication
- User-friendly interface with LCD display and keypad
- Error handling for invalid input
- Automatic result display on the LCD screen

## Components

- Arduino board
- Keypad
- LCD display (I2C)
- Resistors (as needed)
- Wires

## Setup

1. Connect the components following the provided circuit diagram.
2. Upload the Arduino code to your Arduino board.
3. Power up the Arduino.

## Usage

1. **Matrix Transposition**
   - Press the button corresponding to matrix transposition.
   - Enter the number of rows and columns for the matrix.
   - Input the matrix values when prompted.
   - Confirm the entered values.
   - View the transposed matrix on the LCD.

2. **Matrix Multiplication**
   - Press the button corresponding to matrix multiplication.
   - Enter the dimensions for the first and second matrices.
   - Make sure the condition for Matrix multiplication is met.
   - Input the matrix values for both the first and second matrices when prompted.
   - Confirm the entered values.
   - View the result of the multiplication of matrices on the LCD.

## Code Structure

The code is organized into the following sections:

- Initialization of libraries and constants
- Keypad and LCD setup
- Functions for matrix transposition and multiplication
- User input handling and validation
- Matrix operations and result display
- Main loop for button monitoring

## Contributing

Contributions to the project are welcome! If you have any improvements or feature suggestions, feel free to open an issue or submit a pull request.

## License

This project is licensed under the [GNU](LICENSE).

