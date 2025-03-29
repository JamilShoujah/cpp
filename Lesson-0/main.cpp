// lesson 0: basics of compiling a cpp program

#include <iostream>     // this is called a preprocessor directive.
                        // basically its fancy wording for including libraries that we will use
                        // the io stream library is a library that allows us print messages in cpp
                        // more on that later on!

// program entry point
// every cpp code requires an entry point. what we mean by entry point is where the program starts executing
// without the main, the program will not know where to begin.
// all code that needs to be run will be written here
// that also include calling code that is outside of this section. 
// more on that later!
int main() {

    // did you notice the int keyword before main? that keyword basically specifies the return type of the function main.
    // yes main is a function but its a special function. its the only funtion that executes without being called.

    // why did we place the int keyword?
    // well that is to specify that the program expects an integer to be returned when the function completes its execution
    // hence we have return 0
    
    // why only int for the main?
    // because it returns a value to the operating system when the program finishes. 
    // This return value indicates whether the program ran successfully or encountered an error.

    // can we use other types for main?
    // If you used other types like void, string, bool, or float for main(), 
    // the operating system wouldn't know how to interpret the return value, leading to potential issues or confusion.

    std::cout << "hello world! this is my first cpp program!" << std::endl;
    // notice how the statement above ends with a semicolon (;). Thats how we tell the computer that this statement is done
    // failing to place a semicolon will result in an error. more on that later!

    // one more thing.. notice that we used "std::" before using cout. Why is that?"
    // that is is because cout is part of the std namespace in C++. 
    // The std namespace encapsulates the entire C++ Standard Library.
    // using std:: ensures that you're referring to the cout that is defined in the standard library.

    return 0;   // this zero here typically means successful execution of the program
                // Any non-zero value can indicate an error or abnormal termination (although the specifics can vary).
}              

/*
Compilation Steps with g++:

1.  Save this code in a file named main.cpp.

2.  Open the terminal and navigate to the directory containing main.cpp.
    Directory means the location of the file.. so in this example its lesson-0/main.cpp

3.  Run the following command to compile the code:
    --------------------------
    g++ main.cpp -o main
    --------------------------

    Explanation of the weird code above:
        * g++ is the C++ compiler.
        * main.cpp is the source file to compile.
        * -o main specifies the output file name.

4.  After successful compilation, run the program with this command:
    -----------
    ./main
    -----------

    This will execute the compiled program and display the output:
    hello world! this is my first cpp program!

5.  Optional (for debugging): If you want to include debugging symbols, use the "-g" flag when compiling:
    ------------------------
    g++ -g main.cpp -o main
    ------------------------
    (This will allow you to debug with tools like gdb or lldb).

6.  Optional (for optimization): If you want to optimize the program for faster execution, use the "-O2" flag:
    -------------------------
    g++ -O2 main.cpp -o main
    -------------------------
    (This enables optimizations during compilation).


for now, we dont need to know steps 5 and 6.

NOTE: if you are lazy like myself, you can combine steps 3 and 4 into 1 command by simply using "&&". checkout the code below:
    ----------------------------------
    g++ main.cpp -o main && ./main
    ----------------------------------
*/
