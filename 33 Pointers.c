/*
Activity: use pointers to create elixir

You are developing an elixir that supposedly makes a person younger.
You just need to get the software working correctly before starting to market your product.
Your program keeps track of a person's age, but in order to be more secretive you work with
a pointer rather than the variable that stores the age directly. 

You are provided with a main function -- please complete it.
Do not change any of the lines of code that have already been completed.
Please only change the lines that are currently comments.

Provided code

#include <stdio.h>

int main(void) {

    int age;

    // add a line here that declares an integer pointer named "ageptr"

    scanf("%d", &age);

    // add a line here that stores the address of age in ageptr  

    printf("The secret address is... ");

    // add a line here that prints out the address stored in ageptr  

    printf("Now take three drops of the magic elixir. \n");

    // add a line that uses only ageptr to lower the age by 5 years

    printf("Did the elixir work? You are %d years old!", age);

    return 0;

}
*/

#include <stdio.h>

int main(void) {

    int age;
    
    int * ageptr;

    scanf("%d", &age);

    ageptr = &age;

    printf("The secret address is... ");
    
    printf("%p\n", ageptr);


    printf("Now take three drops of the magic elixir. \n");
    
    * ageptr = * ageptr - 5;

    printf("Did the elixir work? You are %d years old!", age);

    return 0;

}

// Solution

#include <stdio.h>
int main(void) {
    int age;
    int *ageptr; // add a line here that declares an integer pointer named "ageptr"
    
    scanf("%d", &age);
    ageptr = &age; // add a line here that stores the address of age in ageptr
    
    printf("The secret address is... ");
    printf("%p\n", ageptr); // add a line here that prints out the address stored in ageptr
    
    printf("Now take three drops of the magic elixir. \n");
    *ageptr = *ageptr - 5; // add a line that uses only ageptr to lower the age by 5 years
    
    printf("Did the elixir work? You are %d years old!", age);
    return 0;
}

/*
Activity: use pointers to improve elixir

You are continuing to work on your elixir of youth, and it turns out that, before purchasing the elixir,
customers would like to know how young they will become after drinking the elixir!

The way your elixir works is that anyone who is at least 21 years old becomes ten years younger.
However, the elixir does not work on anyone twenty years old or younger - when these people try the elixir,
they actually double in age!

You have already created a main function, shown below.
All you need to do now is write a function which accepts the integer pointer "ageAddr" as an argument
and modifies the integer this pointer points to according to the rules of your elixir.
Since you are using pointers to change the value of the variable age, your function should have a
void return type. 

Be sure not to modify the code that has been given to you, other than to add the following:

    Your function definition.
    The appropriate function call where indicated in the main function.
    Your function prototype where indicated in the provided code.

#include <stdio.h>

//Write your function prototype here

int main(void){
	int age;
	int *ageAddr = &age;
	scanf("%d", ageAddr);
	printf("Your current age is %d.\n", age);

	//Write your function call here

	printf("Your new age will be %d!\n", age);
	return 0;
}

//Write your function here
*/

#include <stdio.h>

//Write your function prototype here
int finalage(int * age);

int main(void){
	int age;
	int *ageAddr = &age;
	scanf("%d", ageAddr);
	printf("Your current age is %d.\n", age);

	//Write your function call here
    finalage(&age);

	printf("Your new age will be %d!\n", age);
	return 0;
}

//Write your function here
int finalage(int * age)
{
    if (*age < 21)
    {
        *age = *age * 2;
    }
    else
    {
        *age = *age - 10;
    }
}

// Solution
#include <stdio.h>

void elixir(int *);

int main(void){
	int age;
	int *ageAddr = &age;
	scanf("%d", ageAddr);
	printf("Your current age is %d.\n", age);

	elixir(ageAddr);

	printf("Your new age will be %d!\n", age);
	return 0;
}


void elixir(int *age){
	if (*age>20){
		*age -= 10;
	} else {
		*age *= 2;
	}
}

/*
Activity: passing array to function to swap

Within this program, we will pass an array with 6 integers to a function, have the function swap
the first and last integer, the second and the second to last integer,
the third and the third to last integer.

The function is called reverseArray and doesn't return anything (void).
It should take one parameter, representing the array of integers. 

The main function first reads 6 integers from the input, and assigns them to the array.
The main function then calls reverseArray, passing the array as an argument.

The main function then prints the reversed array.
*/

#include <stdio.h>

void reverseArray(int * vet);

int main()
{
    int array[6];
    int i;
    for (i = 0; i < 6; i++)
    {
        scanf("%d", &array[i]);
    }
    reverseArray(array);
    for (i = 0; i < 6; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}

void reverseArray(int * vet)
{
    int temp;
    temp = vet[0];
    vet[0] = vet[5];
    vet[5] = temp;
    temp = vet[1];
    vet[1] = vet[4];
    vet[4] = temp;
    temp = vet[2];
    vet[2] = vet[3];
    vet[3] = temp;
}

// Solution

#include <stdio.h>

void reverseArray(int *arr);

int main (void){
	int arr[6];
	int i;

	for (i = 0; i < 6; i++){
		scanf("%d", &arr[i]);
	}

	reverseArray(arr);

	for (i = 0; i < 6; i++){
		printf("%d ", arr[i]);
	}

	return 0;
}

void reverseArray(int *arr){
	int swap;

	swap = arr[5];
	arr[5] = arr[0];
	arr[0] = swap;
	
	swap = arr[4];
	arr[4] = arr[1];
	arr[1] = swap;
	
	swap = arr[3];
	arr[3] = arr[2];
	arr[2] = swap;
}