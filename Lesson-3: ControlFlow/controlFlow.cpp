// Lesson 3: Control flow

#include <iostream>
using namespace std;

// you might be asking, What is control flow?
// its really fancy wording for something simple..
// Control Flow is the order in which a program’s code is executed.

// Think of it like choosing a path in a video game:
// Sometimes, you make decisions (if-else).
// Other times, you repeat actions (loops).
// You may skip or stop certain actions (break/continue).


// How Control Flow Works
// Runs code line by line (top to bottom)
// Checks conditions (if statements) to decide which code to run
// Repeats code when needed (loops)
// Exits or skips parts of code when necessary (break/continue)

// Conditional Statements

    // If-Else Statement
        // if runs a block of code only if the condition is true.
        // else runs when the condition is false.

        // ex:
        void ConditionalExampleOne(){

            // focus only on the below
            // ---------------------------------------
            int age = 12;

            if (age >= 18) {
                cout << "You are an adult!" << endl;
            } else {
                cout << "You are a minor!" << endl;
            }
            // ---------------------------------------
        }

        // for now ignore the function i created above and just focus on its body
        // had to create a fucntion in order to avoid a cpp error
        // more on function soon

        // the code above is very simple.. it checks whether the age is greater than on equal to 18
        // based on that it executes what the body states
        // If age is 18 or more, it prints "You are an adult!"
        // If age is less than 18, it prints "You are a minor!"

        // since we set age to 12, and 12 is less than 18, it will only execute the body of the else statement
        // in order words it prints "You are a minor!"

        // if the age we provided was greater than 18.. it will only execute the body of the if statement


    // Else If: 
        // Used when you have multiple conditions to check.

        void ConditionalExampleTwo(){

            // focus only on the below
            // ---------------------------------------
            int num = 0;

            if (num > 0) {
                cout << "Positive number";
            } else if (num < 0) {
                cout << "Negative number";
            } else {
                cout << "Zero";
            }
            // ---------------------------------------
        }

        // This program checks if the number is positive, negative, or zero.
        // first if it checks if the number is greater than 0.. if thats the case it executes the if statement's body
        // if that wasnt the case, it would jump into the else if.. there it checks if the number is negative.
        // again if the number was negative, it would execute the body of the else if.
        // other wise, it would execute the body of the else

        // another way to write the wbove would be this:
         void ConditionalExampleThree(){

            // focus only on the below
            // ---------------------------------------
            int num = 0;

            if (num > 0) {
                cout << "Positive number";
            } else {
                if (num < 0) {
                cout << "Negative number";
                } else {
                    cout << "Zero";
                }
            }
            // ---------------------------------------
        }

        // the above is basically two if else statements.
        // the outer if else statement checks if the number is positive
        // if the number is positive, it executes the body of the if statement
        // if the number is negative or 0, it executes the body of the else which contains another if-else statement

        // the inner if-else statement checks if the number is negative
        // if the number is negative, it executes the body of the if statement
        // if the number is not negative it executes the body of the else statment

        // the two code above are similar, but for readability reasons, we often go with the first way.

    // Ternary Operator (? :)
        // functions the exact same way as an if else statement, but its a shortcut for lazy people like me
        // ex:
        int x = 10, y = 20;

        int max = (x > y) ? x : y; 

        // the example above us sets the value of the max to the value of either x or y based on which is bigger
        // we can also right the above as this

        void TernaryOperatorAsIfStatement(){

            // focus only on the below
            // ---------------------------------------
            int maxVal;
            
            if(x>y){
                maxVal = x;
            }else{
                maxVal = y;
            }
            // ---------------------------------------
        }

    // Switch Statement
        // Switch statement are basically another way of implementing if else statements
        //  Used when you have many fixed cases (like menu selections).
        // ex:

        void SwitchStatement(){
            int option = 2;

            // focus only on the below
            // ---------------------------------------
            switch (option) {
                case 1: cout << "You chose option 1"; break;
                case 2: cout << "You chose option 2"; break;
                case 3: cout << "You chose option 3"; break;
                default: cout << "Invalid option";
            }
            // ---------------------------------------
        }


        // Each case statement compares option to a value.
        // The break statement prevents executing all cases after a match.
        // The default case runs if no match is found.

        // in this case, option is equal to 2 so only case 2 will execute

        // what happens if we didnt include a break statement after each case?
        // that would result in the execution of all the remaining cases
        // if the exmaple above didnt have a break state, the folloing will be executed:
            // case 2, case 3, and default


// Loops 
    // Loops help repeat a block of code multiple times.
    // we have 3 types of loops. each used in a certain scenario 

    // for loops:
        // For Loop: Repeats a Fixed Number of Times
        //  Best for counting loops.
        // ex:
        void forLoopExample(){

            // focus only on the below
            // ---------------------------------------
            for (int i = 1; i <= 5; i++) {
                cout << "Iteration: " << i << endl;
            }
            // ---------------------------------------
        }

         // The loop's signature consists of three components:
            // 1️ - Initialization → Sets up the loop's starting point (int i = 1)
            // 2️ - Condition → Determines whether the loop continues (i <= 5)
            // 3️ - Update → Modifies the iterator after each iteration (i++)
            
        // This structure ensures the loop executes a controlled number of times.
        // Runs 5 times, printing "Iteration: 1" to "Iteration: 5".

        // why only 5 times?
        // because we started hen i is 1 till i becomes 5

        // what happens if we set i to 0?
        // the loop will iterate 6 times

        // what if we ser i to be strictly less than 5?
        // the loop iterates 4 times


    // while loops:
        // Repeats While a Condition is True
        // Best when you don't know how many times the loop will run.
        // ex

        void whileLoopExample(){
            // focus only on the below
            // ---------------------------------------
            int num = 1;

            while (num <= 5) {
                cout << num << endl;
                num++;  // Increase num
            }
            // ---------------------------------------
        }

        // as long as the condition is satisfied, the body of the while loop is executed
        
        // in the example above, since num is less than 5 the body will execute resulting in the printing of the number
        // as well as incrementing it.

        // the loop will stop when num becomes greater than 5


    // do while loops:
        // they are essentially while loops that execute at least once before its termination.

        void doWhileLoopExample(){
            // focus only on the below
            // ---------------------------------------
            int num = 10;
            do {
                cout << "Number: " << num << endl;
                num++;
            } while (num < 5);
            // ---------------------------------------
        }

        // Prints "Number: 10" even though num < 5 is false.

        // the do section of the do-while loop executes once always.
        // after that the condition in the while section is checked
        // if the condition is true, it does the do section again
