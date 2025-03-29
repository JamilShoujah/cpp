// Lesson 2: Operators

// in cpp we have three types of operators.. logic operators, realation operatirs and arithmatic operators
// lets define two variables here so we can use while explaining

// one operator you definitly have seen before is the assignment operator. 1 equal sign is used to assign a value to a variable
// example below will be used throughout this lesson
int a = 3, b = 4;


// lets start of with the arithmatic operators. you definitly know these from school

// Arithmatic operators:

    // Addition:
        int addition = a + b; // value will be 3 + 4 which is 7

    // Subtraction:
        int subtraction = a - b; // value will be 3 - 4 which is -1

    // Multiplication:
        int multiplication = a * b; // value will be 3 * 4 which is 12

    // Division:
        int division = a / b; // value will be 3 / 4 which is 0.

        // wait why is it zero? shouldnt it be 0.75?
        // yes and no. the reason its not 0.75 is because we are dividing two ints and storing them in an int
        // we can defintly type cast it to a float, but theres another way

        // lets define c to be a float equal to 3.0
        float c = 3.0;
        // now if we divide the c we will get a float
        float divisionTwo = c / b; // this is the same as 3.0 / 4 which is 0.75
        // slightly confusing, but you will get used to it

        // NOTE: Even if we set the variable division to be of type float, the answer we will get is 0.0

    // Modulus:
        // the name might seem intimidating at first, but trust me when i say its not..
        // the modulus operator is used to get the remainder of the division.
        // ex:
        int modulus =  a % b; // same as getting the remainder of dividing 3 by 4 which is 0
        int modulusTwo = b % a; // same as getting the remainder of dividing 4 by 3 whihc is 1


// Relational Operators
    // these operators are simply used to compare values
    // the return boolean type results

    // Equals to "=="
        // this is as straight forward as it seems, checking if two values are equal
        // ex:
        bool isEqual = a == b; // false: 3 is not equal to 4

    // Not Equal "!="
        // the exact opposite of the above.. checks if two values are NOT equal
        // ex:

        bool notEqual = a  != b; // true: 3 and 4 are two different numbers

    // Strictly Less than "<"
        // checks if value to the left of this opperand is strictly smaller than the one on the right
        // ex:

        bool isStrictlySmaller = a < b; // true because 3 is less than 4

    // Less Than or equal to "<="" 
        // similar to the less than opperator, but allows for the values to be equal
        // ex:

        bool isSmallerThanOrEqualTo = a <= b; // true

    // Strictly Greater than ">"
        // check if value to the left of this opperand is strictly greater than the one on the right
        // ex:

        bool isStrictlyGreater = a > b; // false: 3 is not strictly greater than 4

    // greater than or eqaul to ">="
        // similar to the greater than opperator, but allows for the values to be equal
        // ex: 

         bool isGreaterThanOrEqualTo = a >= b; // False: 3 is not greater than 4

    
// Logic Operators
    // we have three logic operators in cpp

    // And "&&"
        // as the name implies, and is used to compare two truth values

        // this is a truth table that describes how and works
        // True && True => True
        // True && False => False
        // False && True => False
        // False && False => False

        // ex:
        bool andOperatorExample = (a > 5) && (b < 10);
            // false: a is not greater than 5, but b is less than 10
            // so false && true => false

        // ex:
         bool andOperatorExampleTwo = (a < 5) && (b > a);
            // True: a is less than 5, and b is greater than a
            // so True && True => True

    // OR "||"
        // and is used to compare two truth values

        // this is a truth table that describes how and works
        // True || True => True
        // True || False => True
        // False || True => True
        // False || False => False

        // ex:
        bool orOperatorExample = (a > 5) || (b < 10);
            // True: a is not greater than 5, but b is less than 10
            // so false || true => True

        // ex:
        bool orOperatorExampleTwo = (a < 1) && (b > 100);
            // False: a is not less than 1, and b is not greater than 100
            // so False || False => False

    // Not "!"
        // used to inverse the truth value
        
        // ex:
        bool notExample = !true; // false
        bool notExampleTwo = !false; // true

// bitwise operrator
    // Exclusive OR "^"
        // also known as the XOR operator
        // it is a bitwise operator that comaprese bit values
        // we say its a bitwise operator because it deals with the binary values of our values

        // the following is the truth table
        // 0 ^ 0 => 0
        // 0 ^ 1 => 1
        // 1 ^ 0 => 1
        // 1 ^ 1 => 0

        // in other words, the xor operator is the same as saying either one or nothing

        // example:

        int i = 5;  //  0101 in binary
        int j = 3;  //  0011 in binary
        int result = i ^ j; // => 6

        // why?
        // we have 5 as 0101 in binary
        // 3 is 0011 in binary
        // now lets compare the values of the each binary number respective of their position

        // starting from the rightmost to the leftmost 
        //  010 (1) // 5
        //  001 (1) // 3

        // now based of the truth table above, we can determine that 1 ^ 1 is 0
        // so the right most value of our number's binary code is 0 
        // new binary number is: XXX0

        // now moving to the next right most value 
        // 01 (0) 1 // 5
        // 00 (1) 1 // 3

        // 0 ^ 1 is 1
        // so the next right most value of our number's binary code is 1
        // new binary number is: XX10

        // Im too lazy to continue with this so well skip the details for now

        // continuing on in the same logic for the rest will result in the following binray number: 0110
        // 0110 in numeric form is 6
        // so the value of the above is 6

// Ternary Operator (? :)
    // known as a short hand if-elese statment. will discusss it in the next lesson