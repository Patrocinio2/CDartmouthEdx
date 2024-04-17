/*
Activity: if else to find cost of carpool

You are planning a car trip so you post on a carpooling website in order to share the cost of the trip.

If you have 0 passengers the carpool site does not charge anything and you alone pay the full cost of the trip.
If you have 1 or more passengers the carpool site adds a $1 fee to the cost of the trip and evenly divides the total cost ($1 fee + gas)
among the passengers and you. You want to write a program that calculates the cost you have to pay. The program should read the number
of passengers (an integer) and the cost of gas for the trip (a decimal number). The program should then print the cost that you have to pay
(a decimal number) with 2 digits after the decimal point.

*/

#include <stdio.h>

int main()
{
    int passageiros;
    float valor;

    scanf("%d %f", &passageiros, &valor);

    if (passageiros == 0)
    {
        printf("%.2f", valor);
    }
    else
    {
        float valor1;
        valor1 = (valor + 1) / (passageiros + 1);
        printf("%.2f", valor1);
    }
    return 0;
}


// Solution

#include <stdio.h>
int main() {
    int nbPassengers = 0;
    double totalCost = 0.0;
    scanf("%d %lf", &nbPassengers, &totalCost);
    int alone = nbPassengers == 0;
    if(alone){
        printf("%.2lf", totalCost);
    }else{
        totalCost = totalCost + 1; //car pooling site fees
        printf("%.2lf", totalCost/(nbPassengers+1));
    }
    return 0;
}


/*
Activity: if else to find hostel cost

The hostel in which you plan to spend the night tonight offers very interesting rates, as long as you do not arrive too late.
Housekeeping finishes preparing rooms by noon, and the sooner guests arrive after noon, the less they have to pay.
You are trying to build a C program that calculates your price to pay based on your arrival time.

Your program will read an integer (between 0 and 12) indicating the number of hours past noon of your arrival.
For example, 0 indicates a noon arrival, 1 a 1pm arrival, 12 a midnight arrival, etc. The base price is 10 dollars,
and 5 dollars are added for every hour after noon. Thankfully the total is capped at 53 dollars, so you'll never have to pay more than that.
Your program should print the price (an integer) you have to pay, given the input arrival time.
*/

#include <stdio.h>

int main()
{
    int hour;
    scanf("%d", &hour);
    int valor = 10 + 5 * hour;
    if (valor <= 53)
    {
        printf("%d", valor);
    }
    else
    {
        printf("53");
    }
    return 0;
}

// Solution

#include <stdio.h>
int main() {
    int arrivalHour = 0;
    scanf("%d", &arrivalHour);
    int total = 10+5*arrivalHour;
    int totalExceeds53 = total > 53;
    if(totalExceeds53){
        printf("53");
    }else{
        printf("%d", total);
    }
    return 0;
}

/*
Activity: if statements: bridge tax

You arrive in front of a bridge that you must cross to reach a village before dark.
Crossing the bridge is not free - the bridgekeeper asks you to roll two dice to determine the cost.
You decide to write a program to verify that he is charging the right price.

Your program should read two integers, between 1 and 6, representing the values of each die.
If the sum is greater than or equal to 10, then you must pay a special fee (36 coins).
Otherwise, you pay twice the sum of the values of the two dice.
Your program must then display the text "Special tax" or "Regular tax" followed by the amount you have to pay on the next line.
*/

#include <stdio.h>

int main()
{
    int dado1;
    int dado2;
    
    scanf("%d", &dado1);
    scanf("%d", &dado2);
    
    int valor;
    valor = dado1 + dado2;
    
    if (valor >= 10)
    {
        printf("Special tax\n36");
    }
    else
    {
        printf("Regular tax\n%d", valor * 2);
    }
    
    return 0;
}

// Solution

#include <stdio.h>
int main(void) {
    int totalExceedsOrEquals10;
    int total;
    int dice1 = 0;
    int dice2 = 0;

    scanf("%d %d", &dice1, &dice2);
    total = dice1+dice2;
    totalExceedsOrEquals10 = total >= 10;

    if(totalExceedsOrEquals10){
        printf("Special tax\n");
        printf("36");
    }else{
        printf("Regular Tax\n");
        printf("%d", total*2);
    }

    return 0;
}


/*
Activity: if statements, Tug of War

You decide to bet on the final match of the Tug of War National Championship. 

Prior to the match the names and weights of the players are presented, alternating by team (team 1 player 1, team 2 player 1, team 1 player 2, and so on).
There is the same number of players on each side. You record the player weights as they are presented and calculate a total weight for each team to inform your bet.
You write a C program to assist with this.

Your program should first read an integer indicating the number of members per team.
Then, the program should read the player weights (integers representing kilograms) alternating by team. 

After calculating the total weight of each team, the program should display the text "Team X has an advantage"
(replacing X with 1 or 2 depending on which team has a greater total weight).

You will then display the text "Total weight for team 1:" followed by the weight of team 1, then
"Total weight for team 2:" followed by the weight of team 2 (see example below).

You are guaranteed that the two teams will not have the same total weight.

Example
Each team is composed of four players. Those of the first weigh 110, 113, 112, and 117kg,
while those of the second weigh 106, 102, 121, and 111kg.
Team 1 weighs a total of 452kg whereas team 2 weighs a total of 440kg, giving team 1 an advantage.
*/

# include <stdio.h>

int main()
{
    int number;
    scanf("%d", &number);
    
    int time1 = 0;
    int time2 = 0;
    
    int i;
    for (i = 0; i < number; i++)
    {
        int a;
        scanf("%d", &a);
        time1 = time1 + a;
        
        int b;
        scanf("%d", &b);
        time2 = time2 + b;
    }
    if (time1 > time2)
    {
        printf("Team 1 has an advantage\n");
        printf("Total weight for team 1: %d\n", time1);
        printf("Total weight for team 2: %d\n", time2);
    }
    else
    {
        printf("Team 2 has an advantage\n");
        printf("Total weight for team 1: %d\n", time1);
        printf("Total weight for team 2: %d\n", time2);
    }

    return 0;
}

// Solution

#include <stdio.h>
int main() {
    int i;
    int nbMembers = 0;
    int totalWeightTeam1 = 0;
    int totalWeightTeam2 = 0;
    int weightRead = 0;
    scanf("%d", &nbMembers);
    for(i=0; i<nbMembers; i++){
        scanf("%d", &weightRead);
        totalWeightTeam1 = totalWeightTeam1 + weightRead;
        scanf("%d", &weightRead);
        totalWeightTeam2 = totalWeightTeam2 + weightRead;
    }
    int advantageTeam1 = totalWeightTeam1 > totalWeightTeam2;
    if(advantageTeam1){
        printf("Team 1 has an advantage\n");
    }else{
        printf("Team 2 has an advantage\n");
    }
    printf("Total weight for team 1: %d\n", totalWeightTeam1);
    printf("Total weight for team 2: %d\n", totalWeightTeam2);
    return 0;
}

/*
Activity: more complex if statements: costly hotel rooms

The hostel in which you stop for the night changes its prices according to the age of the customer and the weight of their luggage.
The rules are not very clear, so you decide to write a small program that will easily allow you and your travel companions to know the price of one night.

One room costs nothing if you are exactly 60 (the age of the innkeeper), or 5 dollars if you are less than 10 years old.
For everyone else, the cost is 30 dollars plus an additional 10 dollars if you bring more than 20 pounds of luggage.
Your program should read the customer's age first, then the weight of their luggage, then output the price they have to pay.
*/

#include <stdio.h>

int main()
{
    int idade;
    int mala;
    scanf("%d", &idade);
    scanf("%d", &mala);

    if (idade == 60)
    {
        printf("0\n");
        return 0;
    }
    if (idade < 10)
    {
        printf("5\n");
    }
    else
    {
        if (mala > 20)
        {
            printf("40");
        }
        else
        {
            printf("30");
        }
    }

    return 0;
}


// Solution

#include <stdio.h>

int main(){
    int is60, isLessThan10, luggageMoreThan20;
	int age = 0;
	int luggageWeight = 0;

	scanf("%d %d", &age, &luggageWeight);

	is60 = age == 60;
	isLessThan10 = age < 10;
	luggageMoreThan20 = luggageWeight > 20;

	if(is60){
		printf("0");
	} else {
		if(isLessThan10){
			printf("5");
		} else {
			if(luggageMoreThan20){
				printf("40");
			} else {
				printf("30");
			}
		}
	}
	return 0;
}

/*
Activity: if statements, name that tree

As you cross a forest you can't help but admire the nature around you including the many species of trees.
Despite your interest, you are a very unskilled botanist and have a lot of trouble identifying different trees.
A friend gives you some guidance and you decide to write a program that will give you the name of the tree based on its characteristics.

There are 4 types of trees:

the "Tinuviel" is 5 meters high or less and its leaves are composed of 8 or more leaflets

the "Calaelen" is 10 meters high or more and its leaves are composed of 10 or more leaflets

the "Falarion" is 8 meters high or less and its leaves are composed of 5 or fewer leaflets

the "Dorthonion" is 12 meters tall or more and its leaves are composed of 7 or fewer leaflets

Your program should read the height and the number of leaflets of a given tree (both integers),
and should be able to determine and display the name of the corresponding tree. 
If the height and number of leaflets does not match any of the tree type descriptions, your program should display "Uncertain".
*/

#include <stdio.h>

int main()
{
    int height;
    int leaflets;
    
    scanf("%d", &height);
    scanf("%d", &leaflets);
    
    if (height <= 5 && leaflets >= 8)
    {
        printf("Tinuviel\n");
    }
    else if (height >= 10 && leaflets >= 10)
    {
        printf("Calaelen\n");
    }
    else if (height <= 8 && leaflets <= 5)
    {
        printf("Falarion\n");
    }
    else if (height >= 12 && leaflets <= 7)
    {
        printf("Dorthonion\n");
    }
    else
    {
        printf("Uncertain\n");
    }
    
    return 0;
}

// Solution

#include <stdio.h>
int main() {
    int height = 0;
    int nbLeaflets = 0;
    scanf("%d %d", &height, &nbLeaflets);
    int tinuviel = height <= 5 && nbLeaflets >= 8;
    int calaelen = height >= 10 && nbLeaflets >= 10;
    int falarion = height <= 8 && nbLeaflets <= 5;
    int dorthonion = height >= 12 && nbLeaflets <= 7;
    if(tinuviel) {
        printf("Tinuviel");
    }
    if(calaelen){
        printf("Calaelen");
    }
    if(falarion){
        printf("Falarion");
    }
    if(dorthonion){
        printf("Dorthonion");
    }
    if(!tinuviel && !calaelen && !falarion && !dorthonion){
        printf("Uncertain");
    }
    return 0;
}