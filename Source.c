#include <stdio.h>
#include <stdlib.h>
int checkequality(double a)
{
    double fractional = a - (int)a;
    while ( (int)fractional < (int)a)
    {
        fractional = fractional * 10;
        if ((int)fractional == (int)a)
        {
            return 1;
        }
        if ((int)fractional > (int)a)
        {
            return 0;
        }
        if ((int)fractional == 0)
        {
            return 0;
        }
    }
}

int main()
{
    //declaration
    int i;
    double addresult = 0;
    double validnumber = 0;

    //open and read file
    FILE *myFile;
    myFile = fopen("Array.txt", "r");

    if (myFile == NULL)
    {
        printf("Error Reading File\n");
        exit(0);
    }

    //allocate memory to array
    int numNumbers = 0;
    fscanf(myFile, "%d", &numNumbers);

    //insert numbers to array
    double* numberArray = malloc(numNumbers * sizeof(double));

    for (i = 0; i < numNumbers; i++)
    {
        fscanf(myFile, "%lf,", &numberArray[i]);
    }

    //print initial arrary
    printf("The initial array is\n");
    for (i = 0; i < numNumbers; ++i)
    {
        printf("%.3lf ", numberArray[i]);
    }

    //sort array by first digit
    for (i = 0; i < numNumbers; i++)
    {
        if (checkequality(numberArray[i]) == 1)
        {
            addresult += numberArray[i];
        }
    }

    //print result
    printf("\nThe sum of the addition is %lf\n", addresult);

    fclose(myFile);
    free(numberArray);
    
    return 0;
}
