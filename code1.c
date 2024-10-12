/*Hannah Prosch 
EECS 148 Lab5
Programming Problem #1:
Sales Report
October 11, 2024*/

#include <stdio.h>

/*Used for the size of the array for my list of months.*/
#define SIZE 12

//void monthlySalesReport(double salesFigures[], char months[SIZE][SIZE]);
//void salesSummaryReport(double salesFigures[], char months[SIZE][SIZE]);
//void sixMonthMovingAverageReport(double salesFigures[], char months[SIZE][SIZE]);
//void salesReportHightestToLowest(double salesFigures[], char months[SIZE][SIZE]);

void monthlySalesReport(double salesFigures[], char months[SIZE][SIZE]) {
        /*Prints the monthly sales report*/
        printf("Monthly Sales Report for 2024\n\n");
        printf("Month\t    Sales");

        /*Loop through arrays to print each month's data.*/
        for(int i = 0; i < SIZE; i++) {
            printf("\n%-10s  %.2f", months[i], salesFigures[i]);
        }
}

void salesSummaryReport(double salesFigures[], char months[SIZE][SIZE]) {
    int minIndex = 0;
    int maxIndex = 0;
    double average = 0;
    double min = salesFigures[0];
    double max = salesFigures[0];
    
    printf("\n\nSales Summary report:\n\n");
    
    //Find min value:
    for (int i = 0; i < SIZE; i++) {
        if (min > salesFigures[i]) {
            min = salesFigures[i];
            minIndex = i;
        }
    }
    printf("Minimum sales: %.2f (%s)", min, months[minIndex]);
    
    //Find max value:
    for (int i = 0; i < SIZE; i++) {
        if (max < salesFigures[i]) {
            max = salesFigures[i];
            maxIndex = i;
        }
    }
    printf("\nMaximum sales: %.2f (%s)", max, months[maxIndex]);
    
    /*Find Average Value*/
    for (int i = 0; i < SIZE; i++) {
        average = average + salesFigures[i];
    }
    average = average / SIZE;
    printf("\nAverage sales: %.2f", average);
}

void sixMonthMovingAverageReport(double salesFigures[], char months[SIZE][SIZE]) {
    double average = 0;
    
    printf("\n\nSix-Month moving average report:\n\n");
    
    /*Finds the average sales over a 6 month period,
    starting from January to July:*/
    for (int i = 0; i < SIZE; i++) {
        if (i+5 < 12) {
            average = 0;
            for(int j = 0; j < 6; j++) {
                average = average + salesFigures[i+j];
            }
                average = average/6.0;
            printf("%s-%s\t%.2f\n", months[i], months[i+5], average);
        }
    }
}

void salesReportHightestToLowest(double salesFigures[], char months[SIZE][SIZE]) {
    double highToLow[SIZE];

    /*Copying array to my copy, highToLow:*/
    for(int i = 0; i < SIZE; i++) {
        highToLow[i] = salesFigures[i];
    }

    printf("\n\nSales report (hightest to lowest):\n\n");
    printf("Month\t    Sales\n");
    
    /*Sort array from high to low*/
    for (int i = 0; i < SIZE - 1; i++) {
        int max = i;
        /*Find maximum element in the array*/
        for (int j = i + 1; j < SIZE; j++) {
            if (highToLow[j] > highToLow[max]) {
                max = j;
            }
        }
        /*Swap the elements*/
        double temp = highToLow[max];
        highToLow[max] = highToLow[i];
        highToLow[i] = temp;
    }

    /* Print out the high to low report:*/
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (highToLow[i] == salesFigures[j]) {
                printf("%-10s  $%.2f\n", months[j], highToLow[i]);
            }
        }
    }

}

int main() {

    double salesFigures[SIZE];
    char months[SIZE][SIZE] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "Novmeber", "December"};

    /*Identify and open file to read input values:*/
    FILE *salesvalues;
    salesvalues = fopen("salesvalues.txt", "r");

    /*Error handling for if the file can't be used:*/
    if (NULL == salesvalues) {
        printf("File cannot be opened");
    }

    /*Read input values and copy them into the salesFigure array:*/
    for (int i = 0; i < SIZE; i++) {
            fscanf(salesvalues, "%lf", &salesFigures[i]);
    }   

    /*Close the file*/
    fclose(salesvalues);
    
    /*Function calls to the various reports*/
    monthlySalesReport(salesFigures, months);
    salesSummaryReport(salesFigures, months);
    sixMonthMovingAverageReport(salesFigures, months);
    salesReportHightestToLowest(salesFigures, months);
}