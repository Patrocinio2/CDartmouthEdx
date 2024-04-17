/*
Activity: store recipe ingredients in an array

Your grandparents gave you a fantastic cooking recipe but you can never remember how much of each ingredient you have to use!
There are 10 ingredients in the recipe and the quantities needed for each of them are given as input (in grams).
Your program must read 10 integers (the quantities needed for each of the ingredients, in order) and store them in an array.
It should then read an integer which represents an ingredient's ID number (between 0 and 9), and output the corresponding quantity.
*/

#include <stdio.h>

int main()
{
    int vet[10];
    
    int i;
    for(i = 0; i < 10; i++)
    {
        scanf("%d", &vet[i]);
    }
    
    int cell;
    scanf("%d", &cell);
    printf("%d", vet[cell]);
    
    return 0;
}

// Solution

#include <stdio.h>

int main() {
    int array[10];
    int readValue = 0;
    int index = 0; //indice 

    for(int i = 0 ; i < 10 ; i++){
        scanf("%d", &readValue);
        array[index] = readValue;
        index = index + 1;
    }

    scanf("%d", &readValue);
    printf("%d", array[readValue]);
    return 0;
}

/*
Activity: use an array to balance weights

You are responsible for a rail convoy of goods consisting of several boxcars.
You start the train and after a few minutes you realize that some boxcars are overloaded and weigh too heavily on the rails while others are dangerously light.
So you decide to stop the train and spread the weight more evenly so that all the boxcars have exactly the same weight (without changing the total weight).
For that you write a program which helps you in the distribution of the weight.

Your program should first read the number of cars to be weighed (integer) followed by the weights of the cars (doubles).
Then your program should calculate and display how much weight to add or subtract from each car such that every car has the same weight.
The total weight of all of the cars should not change. These additions and subtractions of weights should be displayed with one decimal place.

You may assume that there are no more than 50 boxcars.
*/

#include <stdio.h>

int main()
{
    int boxcars;
    scanf("%d", &boxcars);
    double array[boxcars];
    
    int i;
    for (i = 0; i < boxcars; i++)
    {
        scanf("%lf", &array[i]);
    }
    double media = 0.0;
    for (i = 0; i < boxcars; i++)
    {
        media = media + array[i];
    }
    media = media / boxcars;
    
    for (i = 0; i < boxcars; i++)
    {
        printf("%.1lf\n", (media - array[i]));
    }
    return 0;
}

// Solution

#include <stdio.h>

int main(void)
{
    int nbBoxCars, carNumber;
    double weights[50];
    double totalWeight = 0.0;
    double averageWeight;
    
    scanf("%d\n",&nbBoxCars);
    for (carNumber = 0; carNumber < nbBoxCars; carNumber = carNumber + 1)
    {
        scanf("%lf",&weights[carNumber]);
        totalWeight = totalWeight + weights[carNumber];
    }

    averageWeight = totalWeight / nbBoxCars;

    for (carNumber = 0; carNumber < nbBoxCars; carNumber = carNumber + 1)
    {
        printf("%.1lf\n",averageWeight - weights[carNumber]);
    }
    return 0;
}


/*
Activity: array computation

You plan to make a delicious meal and want to take the money you need to buy the ingredients.
Fortunately you know in advance the price per pound of each ingredient as well as the exact amount you need.
The program should read in the number of ingredients (up to a maximum of 10 ingredients), then for each ingredient the price per pound.
Finally your program should read the weight necessary for the recipe (for each ingredient in the same order).
Your program should calculate the total cost of these purchases, then display it with 6 decimal places.
*/

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    double ingredientes[n];
    double valor[n];
    int i;
    for(i = 0; i < n; i++)
    {
        scanf("%lf", &ingredientes[i]);
    }
    for(i = 0; i < n; i++)
    {
        scanf("%lf", &valor[i]);
    }
    double soma = 0.0;
    for(i = 0; i < n; i++)
    {
        soma = soma + (ingredientes[i] * valor[i]);
    }
    printf("%.6lf", soma);
    return 0;
}

// Solution

#include <stdio.h>

int main()
{
    int nbIngredients=0;
    int i, idIngredient;
    double price[10];
    double totalPrice = 0.0;
    double readPrice=0.0;

    scanf("%d", &nbIngredients);

    for(i = 0; i < nbIngredients; i++){
        scanf("%lf",&readPrice);
        price[i] = readPrice;
    }

    for (idIngredient = 0; idIngredient < nbIngredients; idIngredient++)
    {
        double quantity;
        scanf("%lf\n",&quantity);
        totalPrice = totalPrice + price[idIngredient] * quantity;
    }
    printf("%lf\n",totalPrice);

    return 0;
}

/*
Activity: branch inside a loop, how many big cities?

You want to determine the number of cities in a given region that have a population strictly greater than 10,000.
To do this, you write a program that first reads the number of cities in a region as an integer, and then the populations for each city one by one (also integers)
*/

#include <stdio.h>

int main()
{
    int cities;
    scanf("%d", &cities);
    int pop[cities];
    int cont = 0;
    int i;
    for(i = 0; i < cities; i++)
    {
        scanf("%d", &pop[i]);
        if (pop[i] > 10000)
        {
            cont++;
        }
    }
    printf("%d", cont);
    return 0;
}

// Solution

#include <stdio.h>

int main(void){
    int nbCities;
    scanf("%d", &nbCities);
    int nbBigCities = 0;
    for(int i = 0; i < nbCities ; i++)
    {
        int population;
        scanf("%d", &population);
        if(population > 10 * 1000)
        {
            nbBigCities = nbBigCities + 1;
        }
    }
    printf("%d", nbBigCities);
    return 0;
}


/*
Activity: print a square of stars using nested loops

Create a program that displays on the screen a square of n x n stars, with the integer n given as an input.
*/

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int i;
    int j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}

// Solution

#include <stdio.h>
int main() {
    int i, j;
    int n = 0;
    scanf("%d", &n);

    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < n ; j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}


/*
Activity: compute budget using a while loop

Much of the work of a university administration (in addition to managing teachers, researchers, students, courses, etc.)
is to ensure the proper functioning of the university and in particular that the accounting job is well done.
Once a year, an annual report of expenditures must be made.

All expenses for the year have been recorded and classified in a multitude of files and the sum of all these expenses must now be calculated.
But no one knows exactly how many different expenses have been made in the past year!

Your program will have to read a sequence of positive integers and display their sum.
We do not know how many integers there will be, but the sequence always ends with the value -1 (which is not an expense, just an end marker).
*/

#include <stdio.h>

int main()
{
    int expense;
    int sum = 0;
    scanf("%d", &expense);
    sum = sum + expense;
    while(expense != -1)
    {
        scanf("%d", &expense);
        sum = sum + expense;
    }
    printf("%d", sum + 1);
    return 0;
}

// Solution

#include <stdio.h>

int main()
{
    int expense;
    scanf("%d",&expense);
    int sumOfExpenses = 0;
    while (expense != -1)
    {
        sumOfExpenses = sumOfExpenses + expense;
        scanf("%d",&expense);
    }
    printf("%d",sumOfExpenses);

    return 0;
}

/*
Activity: controlling an epidemic

In order to be able to better fight various epidemics in a region, the department of medicine of a major university has launched a large study.
Researchers are interested in how fast an epidemic spreads, and therefore the speed at which health measures must be put in place.
Your program should first read an integer representing the total population of the area.
Knowing that a person was infected on day 1 and that each infected person contaminates two new people every day,
you must calculate the day at which the entire population of the area will be infected.
*/

#include <stdio.h>

int main()
{
    int pop;
    scanf("%d", &pop);
    int day = 1;
    int totalinfected = 1;
    
    while (totalinfected < pop)
    {
        totalinfected = totalinfected + totalinfected * 2;
        day++;
    }
    printf("%d", day);
    return 0;
}

// Solution

#include <stdio.h>

int main()
{
    int day = 1;
    int contaminated = 1;
    int population;

    scanf("%d", &population);

    while (contaminated < population)
    {
        day++;
        contaminated *= 3;
    }

    printf("%d", day);

    return 0;
}

/*
Activity: guess my number

We would like you to develop a program capable of making a child play automatically the game of "more or less" -- 
the child must try to guess a secret number.
The program should respond to each guess with "it is more" or "it is less" until the child finds the right number.

Your program must first read an integer indicating the number that the child will have to find during the game.
Next the program should repeatedly read the player's guesses and display the text "it is more"
if the child has submitted a smaller number or "it is less" if they have submitted a larger number.
Once the correct number is reached, the program should print "Number of tries needed:" followed by a new line and the integer number of tries that it took the guesser.
*/

#include <stdio.h>

int main()
{
    int number;
    scanf("%d", &number);
    int ntentativa = 0;
    int tentativa;
    do 
    {
        scanf("%d", &tentativa);
        ntentativa++;

        if (tentativa < number) 
        {
            printf("it is more\n");
        } 
        else if (tentativa > number) 
        {
            printf("it is less\n");
        }
    } while (tentativa != number);
    printf("Number of tries needed:\n%d", ntentativa);
    return 0;
}

#include <stdio.h>

int main()
{
    int secretNumber;
    scanf("%d",&secretNumber);
    int proposal = secretNumber + 1;
    int nbTries = 0;
    while (proposal != secretNumber)
    {
        scanf("%d",&proposal);
        if (proposal < secretNumber)
            printf("it is more\n");
        if (proposal > secretNumber)
            printf("it is less\n");
        nbTries = nbTries + 1;
    }
    printf("Number of tries needed:\n%d\n",nbTries);

    return 0;
}

/*
Activity: monitoring a chemical experiment

University chemists have developed a new process for the manufacturing of a drug that heals wounds extremely quickly.
The manufacturing process is very lengthy and requires monitoring the chemicals at all times, sometimes for hours!
Entrusting this task to a student is not possible; students tend to fall asleep or not pay close attention after a while.
Therefore you need to program an automatic device to monitor the manufacturing of the drug.
The device measures the temperature every 15 seconds and provides these measurement to your program. 

Your program should first read two integers representing the minimum and maximum safe temperatures.
Next, your program should continuously read temperatures (integers) that are being provided by the device.
Once the chemical reaction is complete the device will send a value of -999, indicating to you that temperature readins are done.
For each recorded temperature that is in the correct range (it could also be equal to the min or max values), your program should display the text "Nothing to report".
But as soon as a temperature reaches an unsafe level your program must display the text "Alert!" and stop reading temperatures
(although the device may continue sending temperature values).
*/

#include <stdio.h>

int main()
{
    int min;
    int max;
    scanf("%d %d", &min, &max);
    int temp = 0;
    while(temp != -999)
    {
        scanf("%d", &temp);
        if(temp != -999)
        {
            if(temp > max || temp < min)
            {
                printf("Alert!\n");
                while(temp != -999)
                {
                    scanf("%d", &temp);
                }
            }
            else
            {
                printf("Nothing to report\n");
            }
        }
    }
    return 0;
}

// Solution

#include <stdio.h>
int main()
{
    int tempMin, tempMax, temperature;
    int tempIsValid = 1;
    int end = 0;
    scanf("%d%d", &tempMin, &tempMax);

    while (!end && tempIsValid){
        scanf("%d", &temperature);
        end = (temperature == -999);

        tempIsValid = (tempMin <= temperature && temperature <= tempMax);

        if(!end){
            if (tempIsValid){
                printf("Nothing to report\n");
            } else {
                printf("Alert!\n");
            }
        }
    }

    return 0;
}
