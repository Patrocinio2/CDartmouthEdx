/*
Activity - Function Declaration Versus Definition

Petra lives in the United States, where temperature is measured in Fahrenheit, whereas Rémi lives in France,
where one measures in Celsius.
During their weekly meetings to discuss the preparation of this course, they often wonder who currently has
the nicer weather.

To help with this important discussion, complete the below C program that converts temperature from Fahrenheit
to Celsius or from Celsius to Fahrenheit, depending on the user's input.
The user should enter an integer, followed by a space, followed by the letter 'F' (for Fahrenheit) or the letter 'C'
(for Celsius) and the program then converts this temperature to the other unit and prints it out with one decimal place (see examples below).

Your job is to complete the given program by filling in the function prototypes, the function calls, and the printf()
statements at the indicated locations (lines that start with //).
Examples
Input:

45 F

Output:

7.2 C


Input:

28 C

Output:

82.4 F

Provided code

#include <stdio.h>

insert prototype for function ftoc() here

insert prototype for function ctof() here


int main(void) {

    int usertemp;
    char unit;
    double convertedtemp;

    scanf("%d %c", &usertemp, &unit);
    if (unit=='C'){
        insert function call here to convert usertemp 
        from Celsius to Fahrenheit and store the result in convertedtemp

        complete this line to print out the conversion result

    } else if (unit=='F'){

        insert function call here to convert usertemp 
        from Fahrenheit to Celsius and store the result in convertedtemp
        
        complete this line to print out the conversion result
        
    }

    return 0;

}

Function definitions below are provided for you

Conversion from Celsius to Fahrenheit:
double ctof(int x){
    return((9.0/5)*x+32);
}

Conversion from Fahrenheit to Celsius:
double ftoc(int x){
    return(5.0/9*(x-32));
}

*/

#include <stdio.h>

double ftoc(int x);
double ctof(int x);


int main(void)
{

    int usertemp;
    char unit;
    double convertedtemp;

    scanf("%d %c", &usertemp, &unit);
    if (unit=='C')
    {
        convertedtemp = ctof(usertemp);
        printf("%.1lf F", convertedtemp);
    }
    else if (unit=='F')
    {
        convertedtemp = ftoc(usertemp);
        printf("%.1lf C", convertedtemp);     
    }

    return 0;

}

double ctof(int x)
{
    return((9.0/5)*x+32);
}

double ftoc(int x)
{
    return(5.0/9*(x-32));
}

/*
Activity - use the math library

You are teaching a class on C-programming. The topic of your next lecture is libraries (what a coincidence!).
You would like to teach about the use of the mathematics library in C.
To accomplish this, you have written a program which you intend to discuss with your students during the next class. 

Your program should first read from the user an integer, and next take the square root of that integer and print it out with 8 decimal places.
Next, your program should find and print out (on a new line) the mathematical constant e (Euler's constant) with 10 decimal places.
To find e, use the mathematical function exp() and note that e = exp(1).

Finally, in order to remind your students how to use the compiler, please print (on a new line) the correct compiler command
to link the mathematics library with your program. Note that in the example given below this line needs to be correctly completed.
Your program's source code is stored in program.c, and your compilation command should produce an executable titled program.

Example
Input:

2

Output:

1.41421356                                                                      
2.7182818285                                                                    
gcc -std=c11 -Wall -fmax-errors=10 -Wextra (... you need to complete this line correctly ...)
*/

#include <stdio.h>
#include <math.h>

int main()
{
    int num;
    scanf("%d", &num);
    double e, raiz;
    raiz = sqrt(num);
    e = exp(1);
    printf("%.8lf\n%.10lf\n", raiz, e);
    printf("gcc -std=c11 -Wall -fmax-erros=10 -Wextra program.c -lm -o program");
    return 0;
}

/*
Activity - Using the JPEG library

You are still teaching that unit on libraries to your students! This time you want to demonstrate how to invoke the JPEG library (libjpeg.so),
which can be used to read and write image files in JPEG format (feel free to play around here - this is pretty neat!). 

You ask your students to write a program with source code stored in vizplus.c and which uses the JPEG library.
In order to help your students you decide to print out the compilation command for them that creates an executable file called vizplus from vizplus.c
along with linking the JPEG library during the translation process. 

Please write a program that prints the necessary compilation command with a simple printf().
Again, your students' source code is provided in vizplus.c. You only need to link the JPEG library and produce an executable file called vizplus.
*/

#include <stdio.h>

int main()
{
    printf("gcc -std=c11 -Wall -fmax-erros=10 -Wextra vizplus.c -ljpeg -o vizplus");
    return 0;
}