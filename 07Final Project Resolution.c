#include <stdio.h>
//add additional header files here
#include <math.h>

struct star
{
    char name[50];
    int temperature;
    double luminosity;
    double radius;
    char classification;
};

void printStars(struct star mystars[], int N); 
//add your propotypes here
int readStars(struct star mystars[]);
void computeRadii(struct star mystars[], int N);
void classifyStars(struct star mystars[], int N);

// Do not modify the main() function!
int main(void)
{
    struct star mystars[50];
    int N;

    N = readStars(mystars);
    computeRadii(mystars, N);
    classifyStars(mystars, N);
    printStars(mystars, N);

    return 0;
}

// Do not modify the printStars() function!
void printStars(struct star mystars[], int N)
{
    int i;
    for (i=0; i<N; i++) 
    {
        printf("%s is a ", mystars[i].name);
        if (mystars[i].classification == 'M') 
        {
        	printf("Main Sequence Star\n");
        }
        else if (mystars[i].classification == 'G')
        {
            printf("Giant\n");
        }
        else if (mystars[i].classification == 'S')
        {
        	printf("Supergiant\n");
        }
        else if (mystars[i].classification == 'W')
        {
        	printf("White Dwarf\n");
        }
        else if (mystars[i].classification == 'N')
        {
        	printf("Unclassified Star\n");
        } 
        else
        {
        	printf(" !!! Warning: '%c' not a valid classification code!!!\n", mystars[i].classification);
        }
        printf("Temp = %d Kelvin, Lum = %.4lf Sol, Rad = %.2lf * R_Sun\n\n", mystars[i].temperature, mystars[i].luminosity, mystars[i].radius);
    }
}

//add the functions readStars(), computeRadii() and classifyStars() here.

int readStars(struct star mystars[])
{
    FILE *file = fopen("stardata.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 0;
    }

    int N = 0;
    while (fscanf(file, "%s %d %lf", mystars[N].name, &mystars[N].temperature, &mystars[N].luminosity) == 3)
    {
        N++;
        if (N == 50) {
            break; // Avoid exceeding array size
        }
    }

    fclose(file);
    return N;
}


void computeRadii(struct star mystars[], int N)
{
    const double TS = 3500.0; // Temperature of the sun in Kelvin

    for (int i = 0; i < N; i++)
    {
        double T = mystars[i].temperature;
        double L = mystars[i].luminosity;

        mystars[i].radius = pow((TS / T), 2) * sqrt(L);
    }
}

// Function to classify each star in the array of structures
void classifyStars(struct star mystars[], int N)
{
    for (int i = 0; i < N; i++) {
        double radius = mystars[i].radius;
        double luminosity = mystars[i].luminosity;

        if (luminosity >= 1e-2 && luminosity <= 1e6 && radius >= 0.1 && radius <= 10)
        {
            mystars[i].classification = 'M'; // Main Sequence
        } 
        else if (luminosity >= 1e3 && luminosity <= 1e5 && radius >= 10 && radius <= 100)
        {
            mystars[i].classification = 'G'; // Giant
        } 
        else if (luminosity >= 1e5 && luminosity <= 1e6 && radius > 100)
        {
            mystars[i].classification = 'S'; // Supergiant
        }
        else if (radius < 0.01)
        {
            mystars[i].classification = 'W'; // White Dwarf
        }
        else
        {
            mystars[i].classification = 'N'; // Unclassified
        }
    }
}

