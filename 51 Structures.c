/*
Activity: Pass Structures to Functions

You'd like to implement a date feature in the C programming language.
To this end you are provided with a structure definition, a main function, and two function prototypes: "readDate()" and "printDate()".
All that is left for you to do is to write these two functions.

Here are the exact specifications:

The function readDate() should read 3 integers from the user input.
The first integer is the year (a 4-digit number), the second integer is the month, and the third integer is the day of the date being read.
The function should store these three numbers in the appropriate parts of the structure being passed into it.

The function printDate() should print the date stored in the variable passed into it in the following format: mm/dd/yyyy with a new line afterwards.
So the month should be printed with two digits (01, 02, 03, ..., 11, 12), the day should be printed as two digits (01, 02, 03, ..., 30, 31),
and the year should be printed as a 4-digit number.

You should not modify the provided code.

 
Example
Input:

2018 10 2

Output:

10/02/2018

 
Provided Code:

#include <stdio.h>

struct date 
{
    int year;
    int month;
    int day;
};

void readDate(struct date *);
void printDate(struct date);

int main(void) 
{
	struct date today;
	readDate(&today);
	printDate(today);
	return 0;
}
*/


#include <stdio.h>

struct date {
        int year;
        int month;
        int day;
    };

void readDate(struct date *);
void printDate(struct date);

int main(void) {
	struct date today;
	readDate(&today);
	printDate(today);
	return 0;
}

void readDate(struct date *ptr)
{
    scanf("%d %d %d", &(*ptr).year, &(*ptr).month, &(*ptr).day);
}

void printDate(struct date x)
{
    printf("%d/%02d/%d", x.month, x.day, x.year);
}


/*
Solution

#include <stdio.h>

struct date {
        int year;
        int month;
        int day;
    };

void printDate(struct date);
void readDate(struct date *);

int main(void) {
	struct date today;
	readDate(&today);
	printDate(today);
	return 0;
}

void readDate(struct date *nowptr) {
    scanf("%d%d%d", &((*nowptr).year), &((*nowptr).month), &((*nowptr).day));
}

void printDate(struct date now) {
    printf("%02d/%02d/%4d\n", now.month, now.day, now.year);
}
*/


/*
Activity: Manipulate Structures with Functions

In this problem you will continue developing the data feature which you started implementing in the previous problem.
You will implement a "tomorrow" feature in the C programming language via a function called "advanceDay()".
The function advanceDay() should take as input a date (stored in a struct date) and return the date of the following day.
You do not have to take into account leap years (although you may if you wish to).
That is, it is okay for your function to always return March 1 as the day following February 28, no matter the year.

You are provided with a familiar date structure definition, a main function as well as the function prototypes for the readDate(), printDate(), and advanceDay() functions.
Do not modify any of the given code.
Simply add your function definitions underneath the main() function.
For the readDate() and printDate() functions you may simply copy and paste the code you developed in the previous task.

Examples

Input:

2018 10 2

Output:

10/02/2018                                                                      

10/03/2018


Input:

2018 10 31

Output:

10/31/2018                                                                      

11/01/2018


Input:

2018 11 30

Output:

11/30/2018                                                                      

12/01/2018                                                                      

 
Input:

2018 12 31

Output:

12/31/2018                                                                      

01/01/2019

 
Provided code

#include <stdio.h>

struct date {
        int year;
        int month;
        int day;
    };

function prototypes
void printDate(struct date);
void readDate(struct date *);
struct date advanceDay(struct date); 

int main(void) {
	struct date today, tomorrow;
	readDate(&today);
	printDate(today);
	tomorrow = advanceDay(today);
	printDate(tomorrow);
	return 0;
}

add your function definitions here

*/

#include <stdio.h>

struct date 
{
        int year;
        int month;
        int day;
};


void printDate(struct date);
void readDate(struct date *);

struct date advanceDay(struct date); 

int main(void) 
{
	struct date today, tomorrow;
	readDate(&today);
	printDate(today);
	tomorrow = advanceDay(today);
	printf("\n\n");
	printDate(tomorrow);
	return 0;
}


void readDate(struct date *ptr)
{
    scanf("%d %d %d", &(*ptr).year, &(*ptr).month, &(*ptr).day);
}

void printDate(struct date x)
{
    printf("%02d/%02d/%d\n", x.month, x.day, x.year);
}

struct date advanceDay(struct date today)
{
	struct date tomorrow = today;

	if (today.month == 1 || today.month == 3 || today.month == 5 || today.month == 7 || today.month == 8 || today.month == 10)
	{
		if (today.day + 1 > 31)
		{
			tomorrow.day = 1;
			tomorrow.month = today.month + 1;
			tomorrow.year = today.year;
		}
		else
		{
			tomorrow.day = today.day + 1;
			tomorrow.month = today.month;
			tomorrow.year = today.year;
		}
	}

	if (today.month == 2)
	{
		if (today.day + 1 > 28)
		{
			tomorrow.day = 1;
			tomorrow.month = 3;
		}
		
	}
	if (today.month == 12)
	{
		if (today.day + 1 > 31)
		{
			tomorrow.day = 1;
			tomorrow.month = 1;
			tomorrow.year = today.year + 1;
		}
		
	}
	else
	{
		if (today.day + 1 > 30)
		{
			tomorrow.day = 1;
			tomorrow.month = today.month + 1;
			tomorrow.year = today.year;
		}
		else
		{
			tomorrow.day = today.day + 1;
			tomorrow.month = today.month;
			tomorrow.year = today.year;
		}
	}
    return tomorrow;
}

/*
Solution

#include <stdio.h>

struct date {
        int year;
        int month;
        int day;
    };


void printDate(struct date);
void readDate(struct date *);
struct date advanceDay(struct date); 

int main(void) {
	struct date today, tomorrow;
	readDate(&today);
	printDate(today);
	tomorrow = advanceDay(today);
	printDate(tomorrow);
	return 0;
}


void readDate(struct date *nowptr) {
    scanf("%d%d%d", &((*nowptr).year), &((*nowptr).month), &((*nowptr).day));
}

void printDate(struct date now) {
    printf("%02d/%02d/%4d\n", now.month, now.day, now.year);
}

struct date advanceDay(struct date today) {
    int d = today.day;
    int m = today.month;
    int y = today.year;
    int days;
    struct date tomorrow;
    if ((m==1) || (m==3) || (m==5) || (m==7) || (m==8) || (m==10) || (m==12)) {
        days = 31;
    } else if (m==2) {
        if (y%4==0) {
            if (y%100 == 0) {
                if (y%400 ==0) {
                    days = 29;
                } else {
                    days = 28;
                }
            } else {
                days = 29;
            }
        } else {
            days = 28;
        }
    } else {
        days = 30;
    }
    if (d<days) d++;
    else {
        d=1;
        if (m==12) {
            m = 1;
            y++;
        } else m++;
    }
    tomorrow.year = y;
    tomorrow.month = m;
    tomorrow.day = d;
    return(tomorrow);
}
*/