#include<iostream>
#include<string.h>
#include <bits/stdc++.h>
using namespace std;



//Function 
bool IsTidyNumber(string number);

int current_digit = -1;
bool bISlastNum_Repitative = false;
int repeate_count = 0;



main()
{
  int No_Of_Trial;	
  cin >> No_Of_Trial;
  for(int Trial= 1;Trial<=No_Of_Trial;Trial++)
  {
    //Get the last counted number by her
    string N; 
    cin>>N;      

    string tidy_number;

    //First check if the given number if tidy
    string temp = N;
    bool IsTidy = false;
    IsTidy = IsTidyNumber(N);
    if(IsTidy)
      tidy_number = N;
    else
    {
      //find the previous tidy number
  
      temp = N;
      int tidy_failure_at =  current_digit;
      
      if(bISlastNum_Repitative)
	tidy_failure_at = tidy_failure_at - repeate_count;

      tidy_failure_at = tidy_failure_at - 1;		
      int temp_num1 = temp[tidy_failure_at]-'0';
      
      if(temp_num1 == 1)
      {
	//in this case we have to skip LSB since we are reducing one place
	for(int i = tidy_failure_at;i<temp.length()-1;i++)
	{
	  temp[i] =  '9';
	}

	temp[temp.length()-1] = '\0';
						
      }
      else
      {
	temp[tidy_failure_at] = temp[tidy_failure_at]-1;
	for(int i = tidy_failure_at+1;i<temp.length();i++)
	{
	  temp[i] = '9' ; //
	}
      }

      tidy_number = temp;// * Number_place ) - 1;
    }
    
    //Print the solution here

    printf("Case #%d: ", Trial);
    printf("%s\n", tidy_number.c_str());

  }//End of No.Of.Trial for loop()     
   
  return 0;
}

bool IsTidyNumber(string number)
{
  current_digit = -1;
  repeate_count = 0;
  bISlastNum_Repitative = false;
  
  int current_number  = -1;
  int no_of_digits = number.length();
  int previous_number = -1;	
  bool IsTidy = false;
  string temp = number;

  for(int i = 0; i < number.size(); i++) 
  {
    previous_number = current_number;
    current_number = number[i]-'0';
    current_digit++;
    if(previous_number != -1)
    {
      if(current_number>=previous_number)
      {
	//so far tidy;continue checking next digits
	if(current_number == previous_number)	
	{	      
	  bISlastNum_Repitative = true;
	  repeate_count++;
	}				  
	else
	{
	  bISlastNum_Repitative = false;
	  repeate_count = 0;
	}
	
	IsTidy = true;	
      }
      else
      {
	//Not a tidy number
	IsTidy = false;
	break; // break the for loop 
      }
    }
    else
    {
      if(no_of_digits == 1)
      {
	//then it must be tidy number; 
	IsTidy = true;
	break; //break the for loop
      }
    }
  }//End of For Loop
  return IsTidy;

}
