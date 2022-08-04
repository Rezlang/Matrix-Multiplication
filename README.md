# Matrix-Multiplication

Input file syntax:

There should be one ```.txt``` file for each matrix being multiplied formatted using
the following

2 Integers
    Number of columns in matrix
    Number of rows in matrix

Matrix with each integer seperated by a space

Line breaks do not matter, the entire input file could work as one line.


Output text file will be generated on program run or can be created ahead of time

Build and run:

Navigate to Build directory

run ```make``` command

Navigate to main program directory: ```cd ..```

Run program with ```Matrix-Multiplication Input1A.txt Input2A.txt OutputFile.txt``` where 
the arguments are replaced with your input and output files... (The above command can
be copied and pasted, the files specified already exist).


Program testing:
In order to assure that my program works as expected I tested it in a number of ways.
Initially I created small matrices randomly that were able to be multiplied together and
ran the program. It was able to compute small multiplications so I moved on to making sure
that it could detect when 2 given matrices could not be multiplied (to see the results of 
this, use input files with different numbers ex: 1A & 4B). After that I moved on
to timing the program and seeing if it could handle relatively large matrices (see input 4),
as well as testing parallelising the main loop in the multiplication method. Adding parallel
processing increases the runtime of the program by a minor amount for small matrices
(matrices smaller than ~50*50), but drastically reduces the time for larger tests. Due to
the fact that the main reason a program like this would exist is to compute solutions too
large for a human to desire to compute by hand, I decided that this minor tradeoff would be
worth it.

I sincerely hope that this is what you are looking for to secure a research internship 
position. I am very excited to hear more about the SCOREC project. Thanks!
