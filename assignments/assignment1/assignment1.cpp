#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;



int calculate_tp_profit(int profit)

{

      double tp_profit = profit * 0.02;


      return tp_profit;


}


int calculate_annual_salary(int monthly_salary,int months_worked)

{

      unsigned int annual_salary = monthly_salary * months_worked;

      return annual_salary;

}


int calculate_profit(int number_cars_sold, int cost_of_car)

{
      unsigned int average_sell_price = rand() % 10 + 5;
      unsigned int profit = number_cars_sold * (average_sell_price - cost_of_car);

      return profit;
}

int calculate_gross_income(int monthly_salary, int months_worked,int number_cars_sold, int cost_of_car)

{
      int gross_income;
      int profit = calculate_profit(number_cars_sold,cost_of_car);

      gross_income = calculate_annual_salary(monthly_salary,months_worked) + calculate_tp_profit(profit);

      return gross_income;
}



int main()

{

      unsigned int monthly_salary;
      unsigned short int months_worked;
      int number_cars_sold;
      int cost_of_car;
      int deductions;

      cout << "Enter your current monthly salary: \n";

      cin >> monthly_salary;

      cout << "Now enter the number of months you have worked this year: " << endl;

      cin >> months_worked;

      cout << "Annual Salary is : " << calculate_annual_salary(monthly_salary,months_worked) << "\n";

      cout << "Enter the costs of the car: \n";

      cin >> cost_of_car;

      cout << "The cost of the car is: " << cost_of_car;

      cout << "Enter the number of cars you've sold: \n";

      cin >> number_cars_sold;

      cout << "Number of misconducts observed: \n";

      cin >> deductions;

      cout << "Gross income is:  " << calculate_gross_income(monthly_salary,months_worked,number_cars_sold,cost_of_car);





}
