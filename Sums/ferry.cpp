/*

Ferry Loading

One more time with Dynamic Programming! The code for this should be similar to check cashing. If you really understand check cashing, you should be able to figure out how to do this one too!

You are running a ferry that can carry cars across a river. The ferry has two lanes (left and right), and there is a line of cars that want to get onto the ferry. You know the length of the ferry, the number of cars, and the length of each car. Put as many cars as you can onto the ferry, directing each one (in order) onto either the left or right side.

You must keep the cars in order. You cannot change the order, or skip any cars. Get the maximum number of cars on, and print out which side you put them onto.

Here are some sample input files, and appropriate answers. The output should print the number of cars that were successfully put onto the ferry, and either left or right for each of them (use either L or R). Note that there is a "mirror image" for each possible answer, so there's not just one possible output for each input.

eg-
Input
4
9
2 2 3 2 1 1 1 1 1
Output - 
3
R
R
L

http://www.cs.binghamton.edu/~pmadden/courses/cs575/Programs/program06/index.html
*/




#include <iostream>
#include <stdio.h>
#include <assert.h>
//using namespace std;

int total_value, no_of_cars, total_sum_possible = 0;

int main()
{
//	int total_value, no_of_checks, total_sum_possible = 0;
	std::cin>>total_value;
	std::cin>>no_of_cars;
	int car_array[no_of_cars+1];
	car_array[0] = 0;
	for(int i = 1; i <= no_of_cars; i++) {
		std::cin>>car_array[i];

	}
	int matrix[no_of_cars + 1][total_value + 1];
	//inic
        for(int i = 0; i <= no_of_cars; i++){
		for(int j = 0; j <= total_value; j++)
		{
			matrix[i][j] = -1; 
		}
	}
        //////////////////////////////////////////////////////
	//create the matrix
	matrix[0][0] = 1;
//	int flag = 0;
	//matrix[0][3] = 1;
	int total_till_now = 0;
	int latest_car = 0;
	for(int i = 1; i <= no_of_cars; i++) {
		total_till_now += car_array[i];
		for(int j = 0; j <= total_value; j++) {
		
			if(matrix[i-1][j] == 1) {
				int right = total_till_now - j;
				if(right > 0 && right <= total_value)   //this is the main condition. Assuming the current length of left is j, so right  = total_till_now  - j, is this right valid?? only if it is valid, this solution is possible
					{
					latest_car = i;  //just checking and noting the max car which can be fitted
					matrix[i][j] = 1;
					if(car_array[i] + j <= total_value)//array out of bound checking	
						matrix[i][j + car_array[i]] = 1;
					}
			}
		}
			
	}
	/*
	for(int i = 0; i <= no_of_cars; i++){
		std::cout<<"\n";
		for(int j = 0; j <= total_value; j++)
		{
			//std::cout<<" "<<matrix[i][j]; 
			if(matrix[i][j] == -1)
				std::cout<<"F ";
			else
				std::cout<<"T ";
		}
		
	}	*/
	std::cout<<latest_car<<"\n";
	for(int i = latest_car; i > 0; i--) {
		int k;
		if( i == latest_car)
		{
			for(k = total_value; k >= 0; k--) {
				if(matrix[latest_car][k] == 1)
					break;
			}
		}		
		if(matrix[i-1][k] == 1)
			std::cout<<"R"<<"\n";
			//take right if above is true
		else {
			//take left
			k -= car_array[i];
			std::cout<<"L"<<"\n";
		}
			
	}
}
