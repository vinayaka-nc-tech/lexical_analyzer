# Lexical Analyzer in C

## About the Project

This project is part of my learning journey in C programming. I'm building a simple lexical analyzer that reads a C source file and identifies different types of tokens.

The main idea is to understand how source code is broken down into individual tokens, similar to the first stage of a compiler.

I'm implementing the token recognition logic myself to get a better understanding of C language syntax and compiler fundamentals.

## Features Implemented

Currently, the lexical analyzer can identify:

* Reserved keywords
* Identifiers
* Integer constants
* Floating-point constants
* Character constants
* Assignment operator
* Arithmetic operators
* Special symbols

I'm also testing the implementation with different inputs, including valid tokens and invalid token formats.

## Technologies Used

* C programming
* GCC compiler
* Linux terminal

## Project Structure

The project contains the C source files and supporting files used to implement and test the lexical analyzer.

## How to Run

### 1. Clone the repository

```bash
git clone <your-repository-url>
```

### 2. Navigate to the project directory

```bash
cd lexical_analyzer
```

### 3. Compile the program

Use the source files required by your implementation. For example, if the program is contained in a single C file:

```bash
gcc main.c -o lexer
```

If your implementation uses multiple source files, include them in the compilation command.

### 4. Run the program

```bash
./lexer samp.c
```

Replace `samp.c` with the name of the C source file you want to analyze.

## What's Next?

I'm currently working on extending the token recognition logic. Some of the features I plan to add are:

* Compound assignment operators such as `+=` and `-=`
* String literals, including strings containing spaces
* Header file and preprocessor directive identification
* Additional operators and edge-case handling
* More test cases for valid and invalid tokens

## Learning Goals

Through this project, I want to improve my understanding of C programming, string handling, file operations, and the fundamentals of compiler design.

I'll keep updating the repository as I implement and test new features.
