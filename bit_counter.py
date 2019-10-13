
# Python3 program to find  
# total bit in given number 
import math 
def countBits(number): 
      
    # log function in base 2  
    # take only integer part 
    return int((math.log(number) / 
                math.log(2)) + 1); 
  
# Driver Code 
num = 3141592653589793238462643383279502884199629634681894698407006785501525376778150270661679422021593401; 
print(countBits(num)); 
  
# This code is contributed by mits 
