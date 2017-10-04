#include<iostream>
#include<string.h>
#include <bits/stdc++.h>
using namespace std;

main()
{
    int No_Of_Trial;	
    cin >> No_Of_Trial;
    for(int Trial= 1;Trial<=No_Of_Trial;Trial++)
    {
      //Get the pancake positions
      string pancake;
      cin>>pancake;

      // Number of pancakes in current trial
      int n = pancake.size(); 

      //Get the Pancake Flipper's capacity
      int k; 
      cin>>k;      

      //Final solution 
      int Number_Of_Flips = 0;

      for(int i=0;i+k <= n;i++)
      {
	if(pancake[i] == '-')
	{
	
	  for(int j=i;j< i+k;j++)
	  {
	     pancake[j] = (pancake[j] == '+') ? '-' : '+'; //Flip the pancake 
	  }
	     Number_Of_Flips++;

	}
      }
      //Now we have flipped pancakes. Check which trials are full of happy faces;
      //if all are happy faces, then print the number of flips as solution
      //otherwise print "IMPOSSIBLE"

      bool All_Happyside = true;
      for (int i = 0; i < n; i++)
      {
	All_Happyside = (pancake[i] == '+');
	if(All_Happyside == false) 
	  break;
      }
      printf("Case #%d: ", Trial);
      if (All_Happyside)
	printf("%d\n", Number_Of_Flips);
      else
	 printf("IMPOSSIBLE\n");     
      
    }
   
    return 0;
}

