#include <stdio.h>

double taxCalculator(double grossSalary, double totalSaving);

int main(){

    double grossSalary, totalSaving, totalTax;

    printf("Enter the gross salary: ");
    scanf("%lf", &grossSalary);
    printf("Enter the total saving: ");
    scanf("%lf", &totalSaving);

    totalTax = taxCalculator(grossSalary, totalSaving);

    printf("The gross salary is %.2f \n", grossSalary);
    printf("The total saving is %.2f \n", totalSaving);
    printf("The total tax is %.2f \n", totalTax);

    return 0;
}

double taxCalculator(double grossSalary, double totalSaving){
    double taxableIncome, netTax = 0;
    taxableIncome = grossSalary - (totalSaving > 100000 ? totalSaving : 100000);

    if(taxableIncome < 100000){
        netTax = 0;
    }
    else if(taxableIncome > 100000 && taxableIncome <= 200000){
        netTax = (taxableIncome - 100000) * 0.10;
    }
    else if(taxableIncome > 200000 && taxableIncome <= 500000){
        netTax = ((taxableIncome - 100000) * 0.10 + (taxableIncome - 200000) * 0.20);
    }
    else if(taxableIncome > 500000){
        netTax = ((taxableIncome - 100000) * 0.10 + (taxableIncome - 200000) * 0.20 + (taxableIncome - 500000) * 0.30);
    }
    return netTax;
}