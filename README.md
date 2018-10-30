# InsuranceRates
This problem considers a simplified rate schedule for car insurance. 

Relevant information:

According to CarInsurance.com, the average annual base rates for a college driver (with 100/300/100 liability coverage) are:

 [Age, Average Annual Rate] - [18, $4,055], [19, $2,842], [20, $2,549], [21, $2,063], [22, $1,883], [23, $1,743].

From this base, insurance companies offer various discounts.
For the purposes of this problem, consider the following discounts that may or may not be typical.

  -  Students with good grades can get a "good student" discount: 25%
  -  Young drivers who have had a driving course can get a "driver education" discount: 13%
  -  Young drivers who have been driving at least 3 years can get a "good driver" discount, if they have not had an accident
     or traffic ticket in the past 3 years: 17% 

 When a driver is eligible for several of these discounts, combination rules may apply. For the purposes of this problem,
 apply the following rules which may or may not reflect practice.

  -  If a driver is eligible for two of these discounts, then the discounts are added — up to a 35% discount.
  -  If a driver is eligible for all three discounts, then the driver receives a 50% discount. 

Write a program that:

   - reads a drivers age (between 18 and 23, inclusive),
   - reads whether or not the driver is a "good student",
   - reads if the driver has had "driver education",
   - reads if the driver is a "good driver" (drivers at least 19), and
   - computes and prints the annual car insurance rate for this driver, based on the above sample data. 
