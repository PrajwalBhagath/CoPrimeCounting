/*

Program Name: CountingCoPrime.cpp
Author: Prajwal Bhagath
ID: 18039504
Small Description:	This program asks the user to input a value 
					and calculates how many pairs of co primes 
					exisist between 0 and the number

*/

//Header files
#include <iostream>
#include <vector>

//function prototypes
unsigned count_coprimes(unsigned x);//for counting the number of coprimes
unsigned gcd(int a, int b);//for calculating the gcd

using namespace std;


int main()
{
	/* The main function of this program is adapted from the week one labs.
		It asks the user to input a positive integer so that the program 
		can calculate how many coprime pairs there are within 1 and the inserted value.
	*/
	//The intput should be a integer that is positve therefore I used unsigned.
	unsigned max;
	//command asking the user to input a value
	cout <<"Please enter a positive integer To find out how many coprime pairs there are between 1 and the entered value" << endl;
	//The input from the user
	cin >> max;
	//A new variable storing the numbers which calls the counting coprime numbers
	unsigned no_CoPrimes = count_coprimes(max);
	//Output giving the user the amount of co primes 
	cout << "The number of coprime pairs between between 0 and " << max
		<< " is " << no_CoPrimes << endl;
}

unsigned count_coprimes(unsigned x)
{
	//this sets up a 1D vector the size of a 2D vector setting boolean flags all set to false 
	vector <bool> coPrime(x * x, false);
	/*count starts 1 because in the GCD function it specifies that j(column) > i(row) 
	but when i = 1 and j = 1 the gcd is still one but this is the only exception where i = j
	*/
	unsigned count = 1;

	//for loop to go row by row of the vector
	for (unsigned i = 1; i <= x; i++)
	{
		//for loop to go through column by column
		for (unsigned j = 1; j <= x; j++)
		{
			//calling the gcd function to check if the gcd = 1 
			if (gcd(i, j) == 1)
			{
				//making the co primes in the vector = true and adding on to the count if they are co prime
				coPrime[i + j] = true;
				count++;
				
			}



		}
	}
	return count;
}

//Function used to calculate the GCD of the enered value
unsigned gcd(int a, int b) {
	//since dividing zero is impossible and dividing by zero we always get 1
	if (a == 0)
	{
		return b;
	}
	if (b == 0) {
		return a;
	}
	/*int the assignment breif it says "m < n" meaning that the verticle value of
	the 2d vector should not pass the horizontal grid value, which if it does will give us
	a fraction.
	*/
	if (a < b) {
		return gcd(b % a, a);
	}
	/*if the value of the verticle grid goes higher it will simply
	retun a number higher than one since our intention is only to
	find pairs with the GCD = 1
	*/
	else {
		return 5;
	}
}


//END OF PROGRAM;