/*
Cleared Checks

This program will need some dynamic programming, and a little bit of thinking on your part to see the solution. You will be given a number of checks that have been written, each with different dollar amounts. There is also the total amount of money that has been deducted from your account. Your program will have to determine if the dollar amound deducted corresponds to a possible combination of checks, and if so, provide a list of checks that could add up to the appropriate amount.

For example: suppose you have written three checks for $1, $3, and $4. If the amount deducted from your account is $1, then the answer is obvious -- the first check was cashed. If the amount deducted was $2, then this makes no sense -- the checks cannot add up the right way. If the amount deducted is $7, then it has to be the $3 and $4 checks that were cashed.

For output, your program should print either "Not possible" or give a list of check numbers (and their amounts).

As with other programs, read from standard input, write to standard output, and don't print any additional information. You'll turn your program in through Blackboard.

Here are some sample input files, with appropriate answers.

check1.txt, total debit of $50, 3 checks, with the checks worth $10, $20, $30. The checks are numbered starting with 1 (you'll thank me for this later), so your program should print out two numbers, one number on each line, 2 and 3. Here's a sample answer file: answer1.txt
check2.txt, total debit of $5, 3 checks, each check worth $2. Your program should print out "Not possible."
check3.txt, total debit of $10, 5 checks, worth $1, $3, $2, $7, and $5. There are multiple possible answers. One way is to use the 2nd, 3rd, and 5th check, which are worth $3, $2, and $5. You could als use the 2nd and 4th check, or the 1st, 3rd, and 4th check. Any one of these answers is fine.
check4.txt, a total debit of $99, 50 checks, each worth $2. Your program should print out "Not possible."
check5.txt, a total debit of $99, and 100 checks, each worth $3. There are a LOT of possible answers to this one. Any one of the answers will be fine.
The maximum debit will be 1000. There will not be more than 1000 checks in any input. The debit, and check numbers, will all be strictly positive (so no negative numbers, no zeros). Make sure your program works for all cases, not just the five examples shown. Read from standard input, write to standard output.
*/


#include <iostream>
#include <stdio.h>


using namespace std;

int total_value, no_of_checks, total_sum_possible = 0;

int main()
{
//	int total_value, no_of_checks, total_sum_possible = 0;
	cin>>total_value;
	cin>>no_of_checks;
	int check_array[no_of_checks+1];
	check_array[0] = 0;
	for(int i = 1; i <= no_of_checks; i++) {
		cin>>check_array[i];
		total_sum_possible += check_array[i];
	}
	int matrix[no_of_checks + 1][total_sum_possible + 1];
	//inic
        for(int i = 0; i <= no_of_checks; i++){
		for(int j = 0; j <= total_sum_possible; j++)
		{
			matrix[i][j] = -1; 
		}
	}
        //////////////////////////////////////////////////////
	//create the matrix
	matrix[0][0] = 1;
	int flag = 0;
	//matrix[0][3] = 1;
	for(int i = 1; i <= no_of_checks; i++) {
		for(int j = 0; j <= total_sum_possible; j++) {
			flag = 0;
			if(matrix[i-1][j] == 1) {
				matrix[i][j] = 1;
		//cout<<"i = "<<i<<"j = "<<j<<"Check Value = "<<check_array[i]<<" j calculated is : "<<check_array[i] + j<<"\n";
			matrix[i][check_array[i] + j] = 1;
			}
			//now backtrack if we reach till the current value;
			if(j == total_value && matrix[i][j] == 1)
			{
				while(total_value > 0)
				{
					if(matrix[i-1][j] == -1){ //we have to take the current check
						cout<<i<<"\n";
						total_value -= check_array[i];
						matrix[i][j] = 0;
					}
		//			else if(matrix[i-1][j] == 1) //else go to previous value of check
		//			{
		//				i--;
		//			}
					i--;
					j = total_value; 
				}
				flag = 1;
				break;
			}
		}
		if(flag == 1)
			break;
	}
	if(flag == 0)
		cout<<"Not possible"<<"\n";
	/////////////////////////////////////////////	
}
