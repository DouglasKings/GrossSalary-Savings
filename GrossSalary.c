#include <stdio.h>

// Function prototype for tax calculation
double taxCalculator(double grossSalary, double totalSaving);

int main(){
    double grossSalary, totalSaving, totalTax;

    // Prompting the user to enter the gross salary and total savings
    printf("Enter the gross salary: ");
    scanf("%lf", &grossSalary);
    printf("Enter the total saving: ");
    scanf("%lf", &totalSaving);

    // Calculate the total tax based on the gross salary and total savings
    totalTax = taxCalculator(grossSalary, totalSaving);

    // Display the entered values and calculated tax
    printf("The gross salary is %.2f \n", grossSalary);
    printf("The total saving is %.2f \n", totalSaving);
    printf("The total tax is %.2f \n", totalTax);

    return 0;
}

// Calculates the net tax based on the gross salary and total savings
double taxCalculator(double grossSalary, double totalSaving){
    double taxableIncome, netTax = 0;
    
    // Adjust the taxable income based on the total savings, capping at 100,000 if savings exceed this amount
    taxableIncome = grossSalary - (totalSaving > 100000 ? totalSaving : 100000);

    // Determine the tax rate based on the taxable income range
    if(taxableIncome < 100000){
        // No tax for incomes below 100,000
        netTax = 0;
    }
    else if(taxableIncome >= 100000 && taxableIncome <= 200000){
        // 10% tax for incomes between 100,000 and 200,000
        netTax = (taxableIncome - 100000) * 0.10;
    }
    else if(taxableIncome > 200000 && taxableIncome <= 500000){
        // Combined 10% and 20% tax for incomes between 200,000 and 500,000
        netTax = ((taxableIncome - 100000) * 0.10 + (taxableIncome - 200000) * 0.20);
    }
    else if(taxableIncome > 500000){
        // Combined 10%, 20%, and 30% tax for incomes above 500,000
        netTax = ((taxableIncome - 100000) * 0.10 + (taxableIncome - 200000) * 0.20 + (taxableIncome - 500000) * 0.30);
    }
    
    return netTax;
}
