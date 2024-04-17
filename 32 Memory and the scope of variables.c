/*
Activity: compute space

A delivery company has hired you to manage their tracking services division.
It is your job to store all of the currently used tracking codes in the company's database.
These codes consist of either all integers, all decimal numbers, or all characters.
The chief technology officer has warned you that the database is old and has limited space,
so you want to determine how much memory the tracking codes will occupy before storing them.
You decide to write a program to assist you in this process. 

Your program should first read an integer number indicating how many tracking codes
you plan on entering.
Next, for each successive tracking code your program should read in the integer length
of code followed by a space and then the type of code ('i' for integer, 'd' for decimal,
or 'c' for character).
Finally your program should print the total amount of space required to store all
of the tracking codes (in bytes).
If the user enters an incorrect type for any tracking number,
the program should print 'Invalid tracking code type' and exit.
*/

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int listaInt[n];
    char listaChar[n];
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d %c", &listaInt[i], &listaChar[i]);
    }
    int soma = 0;
    for (i = 0; i < n; i++)
    {
        if (listaChar[i] != 'i' && listaChar[i] != 'd' && listaChar[i] != 'c')
        {
            printf("Invalid tracking code type\n");
            return 0;
        }
        else if(listaChar[i] == 'i')
        {
            soma = soma + (listaInt[i] * sizeof(int));
        }
        else if(listaChar[i] == 'd')
        {
            soma = soma + (listaInt[i] * sizeof(double));
        }
        else
        {
            soma = soma + (listaInt[i] * sizeof(char));
        }
    }
    printf("%d bytes\n", soma);
    return 0;
}

// Solution

#include <stdio.h>
int main(void)
{
	char type;
	int num, length, i;
	int total = 0;

	scanf("%d", &num);
	

	for(i = 0; i < num; i++){
	    
        scanf("%d %c", &length, &type);

        if(type == 'i'){       
                total += length*sizeof(int);
        }
        else if(type == 'd'){
            total += length*sizeof(double);
        }
        else if(type == 'c'){
            total += length*sizeof(char);
        }
        else{
            printf("Invalid tracking code type");
            return 0;
        }
	}
	
	printf("%d bytes", total);
	
	return 0;
}

/*
Activity: memory usage displayed

You are programming a toaster! The toaster does not have a lot of memory,
so you need to be careful about the data types you use (remember that different data types
use different amounts of memory).
To make this easier, you'd like an easy way to track how much memory your variables are going to use.

Your job is to write a program that shows, in human-readable form (see below for specifics),
how much memory a set of variables of a certain type will use.
Your program should read a character that identifies the data type ('i' for int, 's' for short,
'c' for char, 'd' for double).
Next it should read an integer that indicates how many variables of the given type you wish to store.

Your program should then calculate the amount of memory required to store the given variables.
Your program needs to be written in such a way that it would also perform correctly
on other computers.
In other words, rather than hard-coding specific sizes for the different variable types,
your program needs to use the "sizeof()" function to determine how much memory an individual
variable of a given type needs.

Finally, you need to output the amount of space required by your variables to the screen.
You need to make sure you provide this output in a form that is easy to read for humans.
The following examples illustrate what this means:
Examples

If the user input were:

i 36794

then the amount of space needed (if we assume that an integer uses 4 bytes in memory)
would be 4*36794 = 147176 bytes.
This corresponds to 147 kilobytes and 176 bytes, so the output should be:

147 KB and 176 B

 
Input:

d 654250

Output:

5 MB and 234 KB and 0 B

 
Input:

d 35

Output:

280 B

Note:
The kilobyte has different values in binary and in decimal.
Please note that for this exercise, we are referring to the kilobyte of value 1000.
Although this value is referred to using the symbol kB (read this article for more information),
please use the symbol KB when coding this exercise.
*/

#include <stdio.h>

int main()
{
    char type;
    int num;
    int space = 0;
    scanf("%c %d", &type, &num);
    if (type == 'i')
    {
        space = num * sizeof(int);
    }
    else if (type == 's')
    {
        space = num * sizeof(short);
    }
    else if (type == 'c')
    {
        space = num * sizeof(char);
    }
    else if (type == 'd')
    {
        space = num * sizeof(double);
    }
    int MB, KB, B;
    if (space >= 1000000)
    {
        MB = space / 1000000;
        KB = (space % 1000000) / 1000;
        B = space % 1000;
        printf("%d MB and %d KB and %d B", MB, KB, B);
    }
    else if (space >= 1000 && space < 1000000)
    {
        KB = space / 1000;
        B = space % 1000;
        printf("%d KB and %d B", KB, B);
    }
    else
    {
        printf("%d B", space);
    }
    
    return 0;
}

// Solution

#include <stdio.h>
 
int main(void){
    char c;
    int num;
    int spacePer;
    int memory;
    int mega, kilo, byte;
    
    scanf("%c", &c);
    scanf("%d", &num);
    
    if (c=='c') spacePer = sizeof(char);
    else if (c=='s') spacePer = sizeof(short);
    else if (c=='i') spacePer = sizeof(int);
    else spacePer = sizeof(double);
    
    memory = spacePer*num;
    mega = memory/1000000;
    kilo = (memory-mega*1000000)/1000;
    byte = memory-mega*1000000-kilo*1000;
    
    if (mega>0){
        printf("%d MB and %d KB and %d B", mega, kilo, byte);
    } else if (kilo>0){
        printf("%d KB and %d B", kilo, byte);
    } else{ 
        printf("%d B", byte);
    }
        
    return 0;
}
