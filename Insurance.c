    /***********************************************************************
     * Name: Agne Lukoseviciute                                            *
     * Box:  4129                                                          *
     * Assignment name:  Sup. Problem Number 1                             *
     * Assignment for 2018-02-12                                           *
     ***********************************************************************/

    /* *********************************************************************
     * Academic honesty certification:                                     *
     *   Written/online sources used:                                      *
     *     CSC 161 reading on Conditional Statements                       *
     *   Help obtained                                                     *
     *      Professor Walker                                               *
     *   My signature below confirms that the above list of sources        *
     *   is complete AND that I/we have not talked to anyone else          *
     *   (e.g., CSC 161 students) about the solution to this problem       *
     *                                                                     *
     *   Signature:                                                        *
     ***********************************************************************/

/* This program calculates the annual car insurance rate for a college-aged
   driver given the driver's age and information regarding qualification
   for certain discounts. */

#include <stdio.h>         

int age;
double final_discount = 0;
double adjusted_rate;

/* The calculate_discount procedure calculates the discount which the driver
 may receive depending on:  whether or not the driver is a good student, whether
 or not the driver had a driving course, and whether or not the driver had an
 accident or traffic ticket in the past 3 years. */
void calculate_discount ()
{
  int num_of_discounts = 0;
  double discount_so_far = 0;
  int current_discount = 0;
  
  printf ("Enter the driver's age: ");
  scanf ("%d", &age);

  printf ("Enter 1 if the driver is a good student, otherwise enter 0: ");
  scanf ("%d", &current_discount);
  if (current_discount == 1)    /*checks if the driver qualifies for discount*/
    {num_of_discounts++;       /*if qualified, increments num_of_discounts*/ 
      discount_so_far = .25 + discount_so_far;}
  /*and adds the appropriate discount to discount_so_far*/
  

  printf ("Enter 1 if the driver had a driving course, otherwise enter 0: ");
  scanf ("%d", &current_discount);  
  if (current_discount == 1)
    {num_of_discounts++;
      discount_so_far = .13 + discount_so_far;}
  /*similar as for previous discount, only difference is the discount amount*/
  
  if (age >= 19)
    {printf ("Enter 1 if the driver has been driving at least 3 years,\n");
      printf ("otherwise enter 0: ");
      scanf ("%d", &current_discount);
      if (current_discount == 1)
        {printf ("Enter 1 if the driver has not had an accident or\n");
          printf ("a traffic ticket in the past 3 years: ");
          scanf ("%d", &current_discount);
          if (current_discount == 1)
            {num_of_discounts++;
              discount_so_far = .17 + discount_so_far;}}}
  /*similar as for previous discounts but with extra if statements. First to check
    the age(only 19 or above may qualify). The second if statement could have 
    been avoided but I decided to split the question into two parts. Discount
    amount is also different*/
  
  if (num_of_discounts == 0)
    final_discount = 0;
  /*if the driver didn't qualify for any discounts then final_discount is zero*/
  
  if (num_of_discounts == 1)
    final_discount = discount_so_far;
  /*if the driver qualified for only one discount then final_discount is
    the value of that discount*/

  if (num_of_discounts == 2)
    if (discount_so_far > .35)
        final_discount = .35;
   else final_discount = discount_so_far;
  /*if the driver qualified for two discounts then these discounts are added up
    but may not exceed .35*/

  if (num_of_discounts == 3)
    final_discount = .50;
  /* if the driver qualified for all three discounts then final_discount is .50*/
 
}

/* The calculate_rate procedure uses the Average Annual Rate given the driver's
   age and the final_discount from the calculate_discount to compute the 
   annual car insurance rate for this driver. */
void calculate_rate ()
{
  int avg_rate_18 = 4055;
  int avg_rate_19 = 2842;
  int avg_rate_20 = 2549;
  int avg_rate_21 = 2063;
  int avg_rate_22 = 1883;
  int avg_rate_23 = 1743;
  
  switch (age)  /*adjusts the rate according to the discount received*/
    {
    case 18:
      adjusted_rate = (avg_rate_18 - (avg_rate_18 * final_discount));
      break;
    case 19:
      adjusted_rate = (avg_rate_19 - (avg_rate_19 * final_discount));
      break;
    case 20:
      adjusted_rate = (avg_rate_20 - (avg_rate_20 * final_discount));
      break;
    case 21:
      adjusted_rate = (avg_rate_21 - (avg_rate_21 * final_discount));
      break;
    case 22:
      adjusted_rate = (avg_rate_22 - (avg_rate_22 * final_discount));
      break;
    case 23:
      adjusted_rate = (avg_rate_23 - (avg_rate_23 * final_discount));
      break;
    default:
      printf ("erorr: age outside of range [18, 23]");
      break;
    }
}

/*The main procedure uses the calculations from calculate_discount and
  calculate_rate to display the driver's annual car insurance rate. */
int main ()
{
  calculate_discount (); /*calculates discount*/

  calculate_rate ();  /*uses calculated dicount to calculate the rate*/
    
  printf ("Driver's annual car insurance rate is $%5.2lf\n", adjusted_rate);
  /*displays the calculated rate*/
  
  return 0;                
}
