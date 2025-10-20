Project Title: Final C++ Project 2D Array Pattern Generator
Name:  Nicolette Skudrzik
Course:  SDEV 140

Overview:
The program processes input data provided from the given file (InputData.csv). This document contains a table listing the x- and y-coordinates and a corresponding symbol for each. The program uses this data to create and display block annotated letters.

How It Works:
1.	The program reads each row of data from the InputData.docx file.
2.	Each row contains an x-coordinate, a character symbol, and a y-coordinate.
3.	The program determines the largest x and y values to calculate the size of the grid.
4.	A 2D array is created and filled with blank spaces.
5.	Each symbol is placed at its proper (x, y) coordinate in the grid.
6.	The completed array is printed to the screen and reveals the block letters.

How to Run:
1.	Open Visual Studio Code.
2.	Make sure the following files are in the same folder: finalproject.cpp and InputData.csv (if your program reads from this file).
3.	In the terminal, find to the folder containing your files.
4.	Compile the program by typing: g++ finalproject.cpp -o finalproject
5.	Run the compiled program by typing: ./finalproject
6.	The program will show the pattern made of block letters in the terminal.
7.	The message “Program finished successfully!” will appear when the program ends.

Expected Output: 
The program will print out the black and dotted rectangles to display the letters E I C M D K O.

Conclusion:
This project shows how to read data from a file, store it in a 2D array, and print a pattern using symbols. It uses basic C++ such as file input, arrays, and loops to reveal the text.
