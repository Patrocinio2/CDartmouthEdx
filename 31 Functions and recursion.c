/*
Activity: program a smart unit converter

Write a C-program that converts metric measurements to imperial system values. 
Measurements are provided to your program in meters, grams or degrees Celsius and must be converted to feet, 
pounds and degrees Fahrenheit, respectively.

Here are the conversion rules to use:

1 meter = 3.2808 feet;

1 gram = 0.002205 pounds;

temperature in degrees Fahrenheit = 32 + 1.8 × temperature in degrees Celsius.

On the first input line you are given the number of conversions to be made. 
Each of the following lines contains a value to be converted as well as its unit:
m, g or c (for meters, grams or degrees Celsius). There will be a space between the number and the unit. 
You should print your output value for each input line immediately after calculating it
(ie, you do not have to wait until you have read all inputs).

Display the converted values with 6 decimal places, followed by a space and their unit:
ft, lbs or f (for feet, pounds or degrees Fahrenheit).
Each conversion result should be printed on its own line, and you should store and display all decimal values as doubles.

You may use functions to complete this exercise, but that is not required.
However, you will need to use a comparison operation with characters, for example:

char letter = 'a';

if(letter == 'a') {...}
*/

#include <stdio.h>

void conversion(double f, char c);

int main()
{
    // Numero de conversões
    int n;
    scanf("%d", &n);
    // Uso da função
    int i;
    double f;
    char c;
    for (i = 0; i < n; i++)
    {
        scanf("%lf %c", &f, &c);
        conversion(f, c);
    }
    return 0;
}

void conversion(double f, char c)
{
    double result;
    if (c == 'm')
    {
        result = f * 3.2808;
        printf("%.6lf ft\n", result);
    }
    if (c == 'g')
    {
        result = f * 0.002205;
        printf("%.6lf lbs\n", result);
    }
        if (c == 'c')
    {
        result = 32 + 1.8 * f;
        printf("%.6lf f\n", result);
    }
}

// Solution

#include <stdio.h>

double metersToFeet(double meters);
double gramsToPounds(double grams);
double celsiusToFahrenheit(double celsius);

int main(void) {
    int nbConversions, iConv;
    double value;
    char unit;
    
    scanf("%d", &nbConversions);
    for (iConv = 0; iConv < nbConversions; iConv = iConv + 1) {
        scanf("%lf %c", &value, &unit);
        if (unit == 'm'){
                printf("%lf ft\n", metersToFeet(value));
        } else if (unit == 'g'){
                printf("%lf lbs\n", gramsToPounds(value));
        }
        else if (unit == 'c'){
                printf("%lf f\n", celsiusToFahrenheit(value));
        }
    }
    return(0);
}

double metersToFeet(double meters)
{
    double feet_per_meter = 3.2808;
    return meters*feet_per_meter;
}
 
double gramsToPounds(double grams)
{
    double pounds_per_gram = .002205;
    return grams * pounds_per_gram;
}
 
double celsiusToFahrenheit(double celsius)
{
    double fahrenheit_per_celsius = 1.8;
    double zero_celsius_in_fahrenheit = 32;
    return celsius * fahrenheit_per_celsius + zero_celsius_in_fahrenheit;
}

/*
Activity: find the smallest integer

The goal of this problem is to find the smallest integer in a list of numbers.

To help you with this task, please write a function called min() that finds and returns
the smallest amongst two integers (be sure to also write a prototype for this function).
The function thus takes two integers as input and returns the smallest of the two.
This function will use an if statement with a condition that contains either "less than" or "greater than".

Next, please use min() in your main function to work your way through an entire list of numbers
in order to find its minimum.
The first number you read gives the number of elements in the list of integers under consideration.
You will then read the integer values, using min() to keep only the smallest integer read at each step.
In the end, please print out the smallest integer in the list.
*/

#include <stdio.h>

int min(int n);

int main()
{
    int n;
    int menor;
    scanf("%d", &n);
    menor = min(n);
    printf("%d", menor);
    return 0;
}

int min(int n)
{
    int menor;
    scanf("%d", &menor);
    int num;
    int i;
    for (i = 1; i < n; i++)
    {
        scanf("%d", &num);
        if (menor > num)
        {
            menor = num;
        }
    }
    return menor;
}


#include <stdio.h>

int min(int, int);

int main(void) {
	int i;
	int minimum;
	int num;
	int a;

	scanf("%d", &num);
	scanf("%d", &minimum);

	for (i = 1; i < num; i++) {
		scanf("%d", &a);
		minimum = min(minimum, a);
	}
	printf("%d\n", minimum);

	return 0;
}

int min(int a, int b) {
    if (a < b){
	return a;
    }else{
	return b;
    }
}

/*
Activity: use recursion to compute the sum of digits

Please write a C-program that uses a recursive function called "sumOfDigits()"
to compute the sum of the digits of a number.
To do so, your main function should first read an integer number as input and then
call sumOfDigits(), which should in turn call itself until there are no digits left
to sum, at which point the final sum should display to the user.

Here is the main idea of how the recursion in sumOfDigits() should work:

sumOfDigits(6452) = 2 + sumOfDigits(645)

sumOfDigits(645) = 5 + sumOfDigits(64)

...

sumOfDigits(6) = 6
*/

#include <stdio.h>

int sum(int x);

int main()
{
    int n;
    int soma = 0;
    scanf("%d", &n);
    soma = sum(n);
    printf("%d", soma);
    return 0;
}

int sum(int x)
{
    if (x == 0)
    {
        return 0;
    }
    else
    {
        int ultdig = x % 10;
        int novonumero = x / 10;
        return ultdig + sum(novonumero);
    }
}

// Solution

#include <stdio.h>
int sumOfDigits(int);
int main(void) {
	//! showMemory(start=65520)
	int num, sum;
    
	scanf("%d", &num);
	sum = sumOfDigits(num);
	printf("%d", sum);
	return 0;
}

int sumOfDigits(int n) {
	if (n<10) 
	    return n;
	else  
	    return (n%10 + sumOfDigits(n/10));
}
