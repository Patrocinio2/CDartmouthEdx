/*
Activity: Pass numbers to a program from the command line

You are selling plants and are working on creating invoices for customer orders.
You are testing a program that should receive, as arguments passed in from the command line,
a number of plants to be purchased (an integer) and the price per plant (a decimal number).
Your job is to create an invoice for the customer (see examples) that prints out the total price
of the order (which can be found by multiplying the price per plant by the number of plants purchased). 

If your program is called with an incorrect number of arguments the user should receive the message
"Invalid input" (see Example 3).

Be sure to print prices with two decimal places, and to print the invoice exactly as presented in the
examples below.

When testing your program in Weblinux, you need to provide the command line arguments in the same
way you just learned in the video.
When you submit your program to taskgrader however, we will be supplying those arguments in order
to test your program.
In your submission you thus do not have to worry about providing command line arguments to your
program.

Examples
Input from the command line (via argv): 

5 2.39

Output:

5 plants for 2.39 dollars each cost 11.95 dollars.

 
Input from the command line (via argv): 

2 48.99

Output:

2 plants for 48.99 dollars each cost 97.98 dollars.

 
Input from the command line (via argv): 

48.99

Output:

Invalid input.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
    int wholeNumber;
    double decimalNumber, value;

    if (argc == 3)
    {
        wholeNumber = atoi(argv[1]);
        decimalNumber = atof(argv[2]);
        value = wholeNumber * decimalNumber;
        printf("%d plants for %.2lf dollars each cost %.2lf dollars.\n", wholeNumber, decimalNumber, 
        value);
    }
    else
    {
        printf("Invalid input.\n");
    }
    return 0;    
}

/*
Solution

#include <stdio.h>
#include <stdlib.h> // for atoi and atof

int main(int argc, char *argv[]) {
	int numberOfPlants;
	double pricePerPlant, cost;
	
	if (argc!=3) {
		printf("Invalid input.\n");
	} else {
		numberOfPlants = atoi(argv[1]);
		pricePerPlant = atof(argv[2]);
		cost = numberOfPlants*pricePerPlant;
		printf("%d plants for %.2lf dollars each cost %.2lf dollars.\n", numberOfPlants, pricePerPlant, 
        cost);
	}
	return 0;
}
*/


/*
Activity - Read numbers from a file

You are teaching a class on C-programming! You would like to find out whether your teaching has been effective,
and so you need to compute the average grade your students have received on the most recent assignment.
These grades (integers) are stored in the file studentGrades.txt.

The first entry in the file (an integer) is the number of student grades that are stored in the file.
For example, if the file was as follows:

9
56 3 8 11 0 45 55 2 78

this would mean that there are 9 grades stored in the file (starting with 56 and ending with 78).

Your job is to calculate and print out the average of the grades stored in the file.
Please print the average grade with two decimal places.
Things to consider:

To test your program you need to create your own file "studentGrades.txt" with grades stored as described.
In weblinux you can do so by first typing "touch studentGrades.txt" at the command prompt and then opening,
editing and saving the file studentGrades.txt in the file editor. When you submit your program to taskgrader
we will provide an input file for testing purposes.
It is thus crucially important that the file from whichyou are reading in your program is indeed named "studentGrades.txt".  

 
Examples
Input file "studentGrades.txt": 

4
100 99 90 98

Output: 

96.75

 
Input file "studentGrades.txt": 

2
100 50

Output: 

75.00

 
Input file "studentGrades.txt": 

7
90 88 76 93 44 98 33

Output: 

74.57
*/

#include <stdio.h>

int main()
{
    FILE *file;
    int N, i;
    double number, sum, media;
    sum = 0;

    file = fopen("studentsGrade.txt", "r");
    fscanf(file, "%d", &N);

    for (i = 0; i < N; i++)
    {
        fscanf(file, "%lf", &number);
        sum = sum + number;
    }
    media = sum / N;
    printf("%.2lf\n", media);

    fclose(file);

    return 0;    
}

/*
Resolution

#include <stdio.h>

int main(void) {
	FILE *ifile;  
	int i, N, grade, sum;
	double average;
	
	sum = 0;
	
	ifile = fopen("studentGrades.txt", "r"); 
	
	fscanf(ifile, "%d", &N); 
	
	for (i = 0; i<N; i++) {
		fscanf(ifile, "%d", &grade);
		sum += grade;
	}
	
	fclose(ifile); 
	average = (double) sum / N;
	printf("%.2lf\n", average);
	
	return 0
*/

/*
Activity - Find the end of the file

You are still teaching a class on C-programming! You would like to find out whether the students in your
class did better on the most recent assignment than the students in your colleagues' classes.
The average grades of all these classes are stored in a file called "gradeComparison.txt".
The first number stored in the file represents the average grade of the students in your class.
All of the subsequent numbers represent the average grades of students from other sections.

For example, if the file contained the following:

95.23 94.80 91.56

this would mean that the students in your class received an average grade of 95.23 on the last assignment,
which is higher than the average grades received by students in the other sections.

If, on the other hand, the file was

95.23 94.80 91.56 96.40 93.25

then this would mean that the students in the fourth class received a slightly higher grade than the students in your class.  

Your job is to find out whether the students in your class did better than the students in the other classes and if so,
print out the word "Yes". If on the other hand students in another class did better than your students then you should print out "No",
followed by one space, followed by the number of the first class in the file that had a better grade average.

 
Things to consider: 

(1) Unlike in the previous task, this time the file contains only average grades
(and does not start with the number of average grades stored in the file).

(2) To test your program you will need to create your own file "gradeComparison.txt" with average grades stored as described.
In weblinux you can do so by first typing "touch gradeComparison.txt" at the command prompt and then opening, editing, and
saving the file "gradeComparison.txt" in the file editor.
When you submit your program to taskgrader we will provide an input file for testing purposes.
It is thus crucially important that the file from which you are reading in your program is indeed named "gradeComparison.txt".  

 
Examples
Input file "gradeComparison.txt": 

95.23 94.80 91.56

Output: 

Yes

 
Input file "gradeComparison.txt": 

95.23 94.80 91.56 96.40 93.25 99.64

Output:

No 4
*/

#include <stdio.h>

int main()
{
    FILE *file;
    double grade, num;
    int n;


    file = fopen("gradeComparison.txt", "r");

    fscanf(file, "%lf", &grade);
    n = 1;
    while (fscanf(file, "%lf", &num) != EOF)
    {
        if (num <= grade)
        {
            n++;
        }
        else
        {
            n++;
            break;
        }
    }
    
    if (num > grade)
    {
        printf("No %d\n", n);
    }
    else
    {
        printf("Yes\n");
    }
    
    fclose(file);

    return 0;
}

/*
Solution

#include <stdio.h>

int main(void) {
	FILE *ifile;
	int N, done, best;
	double myClass, otherClass;
	
	ifile = fopen("gradeComparison.txt", "r");
	
	fscanf(ifile, "%lf", &myClass);
	N=1;
	done = 0;
	best = 1;
	
	while (!done) {
		done = fscanf(ifile, "%lf", &otherClass) == EOF;
		if (!done) {
			N++;
			if (otherClass>myClass) {
				done = 1;
				best = 0;
			}
		}
	}
	
	fclose(ifile);
	
	if (best) {
		printf("Yes\n");
	} else {
		printf("No %d\n", N);
	}
	
	return 0;
}

*/

/*
Activity: Write numbers to a file

You are grading final exams and you are recording grades (integers) in a file "myGrades.txt".
You just got distracted by a phone call and can't remember whether or not you already recorded
the grade of the student whose paper you just finished grading.

Expecting that this may not be the last time your phone rings you decide to write a C-program
to help you out.
The program should first read, from the user input, the grade (an integer) that you need to check on.
Next, the program should open the file "myGrades.txt", find the last number in the file, close the file,
and compare the last number from the file to the grade read from the user input.
If the two grades are equal then you presumably already recorded the grade and don't have to do anything.
If on the other hand the two grades do not equal each other then you have not yet recorded this new grade
and need to do so by appending this new grade to the file.

Finally, reopen the file and print its new contents to the screen.

 
Things to consider:

(1) Be sure to separate grades in the file by printing one space between the grades.

(2) To test your program you need to create your own file titled "myGrades.txt" with grades stored as described.
In weblinux you can do so by first typing "touch myGrades.txt" at the command prompt and then opening, editing and
saving the file "myGrades.txt" in the file editor.
When you submit your program to taskgrader we will provide an input file for testing purposes.
It is thus crucially important that the file from which you are reading in your program is indeed named "myGrades.txt".  

(3) You may assume that you have already recorded some grades in the file "myGrades.txt";
you therefore do not have to check whether the file indeed exists (although you may, of course, do so!)

 
Examples
User input: 

83

Input file "myGrades.txt": 

90 88 84 76

File "myGrades.txt" after program terminates:

90 88 84 76 83

 
User input: 

76

Input file "myGrades.txt": 

90 88 84 76

File "myGrades.txt" after program terminates:

90 88 84 76

 
User input: 

88

Input file "myGrades.txt": 

90 88 84 76

File "myGrades.txt" after program terminates:

90 88 84 76 88
*/

#include <stdio.h>

int main()
{
    FILE *file;
    char filename[] = "myGrades.txt";
    int new_note, last_note, num;

    scanf("%d", &new_note);


    file = fopen(filename, "r");

    while (fscanf(file, "%d", &num) != EOF)
    {
        last_note = num;
    }
    
    fclose(file);

    if (last_note != new_note)
    {
        file = fopen(filename, "a");
        fprintf(file, "%d ", new_note);
        fclose(file);
    }

    return 0;
}