/**********************************************************
** Program: assignment1.cpp
 *
** Author: Tom Nyuma
 *
** Date: 01/08/2021
 *
** Description: This program was created to find the gross income and taxes for a cars salesperson.
 *
** Input: monthly salary, number of months worked in a year, cost of a car, number of cars sold
 * number of misconducts observed, tax year, and state.
 *
** Output: total taxes, income before taxes, income after taxes.
 * *************************************************/


#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

class Salesperson {

    public:
        int taxYear;
        string state;

};

int calculate_tp_profit(int profit)
    // This function takes the profit, calculates 2% of that profit and returns a
    // variable "tp_profit" to be used in our main() function.
{

    double tp_profit = profit * 0.02;


    return tp_profit;


}


int calculate_annual_salary(int monthly_salary,int months_worked)

    // This function takes the arguments: montly salary and months_worked and returns the annual salary.
{

    unsigned int annual_salary = monthly_salary * months_worked;

    return annual_salary;

}


int calculate_profit(int number_cars_sold, int cost_of_car)

/*
 * This function, calculate_profit() passes the number of cars sold and the cost of a car as parameters
 * What it does is generate a random number 5-10% above the cost and subtract it by the cost of the car
 * Then multiply it by the number of cars sold and set that value to the variable profit -- which is returned.
 */


{
    unsigned int average_sell_price = rand() % 10 + 5;
    unsigned int profit = number_cars_sold * (average_sell_price - cost_of_car);

    return profit;
}

int calculate_gross_income(int monthly_salary, int months_worked,int number_cars_sold, int cost_of_car, int deductions)

/*
 * This function takes all of the user given input and uses it to define their specific gross income.
 * The function first checks for the number of deductions and uses the amount to calculate the gross income
 * based on the sheer number of misconducts (deductions) observed. In the end of the conditional, gross income is
 * then returned.
 */

{
    double gross_income;
    int profit = calculate_profit(number_cars_sold,cost_of_car);

    if (deductions <= 0) {

        deductions = 0;
        gross_income = calculate_annual_salary(monthly_salary,months_worked) + calculate_tp_profit(profit) - deductions;

    } else {

        deductions = 100 * pow(2,deductions - 1);
        gross_income = calculate_annual_salary(monthly_salary,months_worked) + calculate_tp_profit(profit) - deductions;

    }

    return gross_income;
}



int main() {

    /*

     * This is our main() function. It will include the srand() intialization, the declaration to our
     * salesperson class as the salesperson object, intialization of our parameters to be used in the above functions
     * and throughout our program, the input sequence for the salespersoon, and the logic for calulating our taxes.

    */

    Salesperson salesperson;

    srand(time(NULL));


    unsigned int monthly_salary;
    unsigned short int months_worked;
    int number_cars_sold;
    int cost_of_car;
    int deductions;
    int taxes = 0;
    double gross_income;
    int income_left = 0;
    int year;
    string state;

    // Below is our prompt sequence for the car salesperson.

    // We're asking for the input specified in our header and then calculating taxes and other
    // things based on that data.

    cout << "Enter your current monthly salary: \n";

    cin >> monthly_salary;

    cout << "Now enter the number of months you have worked this year: " << endl;

    cin >> months_worked;

    cout << "Annual Salary is : " << calculate_annual_salary(monthly_salary,months_worked) << "\n";

    cout << "Enter the costs of the car: \n";

    cin >> cost_of_car;

    cout << "The cost of the car is: " << cost_of_car << endl;

    cout << "Enter the number of cars you've sold: \n";

    cin >> number_cars_sold;

    cout << "Number of misconducts observed: \n";

    cin >> deductions;

    gross_income =  calculate_gross_income(monthly_salary,months_worked,number_cars_sold,cost_of_car,deductions);

    cout << "Your gross income is: " << gross_income << endl;

    cout << "Now it's time to calculate your taxes. " << endl;

    cout << "What tax year are you in:  (2017 or 2018) " << endl;

    cin >> year;

    /* Below is the logic for our salesperson class, which utilized if/else
     * statements to determine what taxYear and state they're under.
      */

    if (year == 2017) {

        salesperson.taxYear = 2017;

    } else {
        salesperson.taxYear = 2018;
    }

    cout << "What state are you in? ( A / B / C ) " << endl;

    cin >> state;

    if (state == "A") {

        salesperson.state = "A";

    } else if (state == "B") {
        salesperson.state = "B";
    } else {
        salesperson.state = "C";
    }

    /* I intialized the act of calculating taxes as a bool so we can use "break;"
     * to stop our program at any point when calculating taxes. If it is not true or we've broken out of in our
     * while loop due to getting the values we need which in this case is: (taxes, remaining income) . */

    bool calculating_taxes;
    cout << "Calculating taxes...." << endl;
    calculating_taxes = true;
    while (calculating_taxes) {
            // Tax year 2017 logic
            if (salesperson.taxYear == 2017) {

                    if (salesperson.state == "A") {

                            taxes = 0.06 * gross_income;
                            income_left = gross_income - taxes;
                            break;

                    } else if (salesperson.state == "B") {

                            if (gross_income <= 200) {

                                taxes = 0;
                                income_left = gross_income - taxes;
                                break;

                            } else if (gross_income >= 2000 && gross_income <= 10000) {

                                taxes = 100;
                                income_left = gross_income - taxes;
                                break;

                            } else {

                                taxes = 0.01 * gross_income + 100;
                                income_left = gross_income - taxes;
                                break;

                            }

                    // State C cnditional logic for tax year 2017.
                    } else {

                        if (gross_income >= 0 && gross_income <= 3500) {

                            taxes = 0.05 * gross_income;
                            income_left = gross_income - taxes;
                            break;

                        } else if (gross_income > 3500 && gross_income <= 9000) {

                            taxes = 0.07 * gross_income + 175;
                            income_left = gross_income - taxes;
                            break;

                        } else if (gross_income > 9000 && gross_income <= 125000) {

                            taxes = 0.09 * gross_income + 560;
                            income_left = gross_income - taxes;
                            break;

                        } else {

                            taxes = 0.099 * gross_income + 11000;
                            income_left = gross_income - taxes;
                            break;

                        }

                    }
             // Tax year 2018 Logic
            } else {

                if (salesperson.state == "A") {

                    taxes = 0.08 * gross_income;
                    income_left = gross_income - taxes;
                    break;

                } else if (salesperson.state == "B") {

                    if (gross_income <= 2500) {

                        taxes = 0;
                        income_left = gross_income - taxes;

                    } else if (gross_income > 2500 && gross_income <= 10000) {

                        taxes = 115;
                        income_left = gross_income - taxes;
                        break;

                    } else {

                        taxes = 0.0105 * gross_income + 115;
                        income_left = gross_income - taxes;
                        break;

                    }
                // State C Logic, but under the 2018 tax year.
                } else {

                    if (gross_income >= 0 && gross_income <= 3450) {

                        taxes = 0.05 * gross_income;
                        income_left = gross_income - taxes;
                        break;

                    } else if (gross_income > 3450 && gross_income <= 8700) {

                        taxes = 0.07 * gross_income + 172.5;
                        income_left = gross_income - taxes;
                        break;

                    } else if (gross_income > 8700 && gross_income <= 125000) {

                        taxes = 0.09 * gross_income + 540;
                        income_left = gross_income - taxes;
                        break;

                    } else {

                        taxes = 0.099 * gross_income + 11007;
                        income_left = gross_income - taxes;
                        break;

                    }

                }


            }

    }

    // This is the final output sequence, which displays the income after taxes, before taxes, and total taxes.
    cout << "Your income before taxe: " << gross_income << endl;
    cout << "Your total taxes are: " << taxes << endl;
    cout << "Your income remaining is: " << income_left << endl;


    int restart;
    cout << "Would you like to calculate taxes for another salesperson? " << endl;

    cout << "1 for No 2 for Yes. " << endl;

    cin >> restart;

    if (restart == 1) {
        // Ends program since user didn't want to restart the execution of main()
        return 0;
    } else{
        // Re does the entire main() function with earlier input(s) flushed.
        main();
    }


}