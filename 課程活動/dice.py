from random import*
for r in range(6):
    C='● '
    s='-------\n| '+C[r<1]+' '+C[r<3]+' |\n| '+C[r<5]
    print(s+C[r&1]+s[::-1])

import time
  
# define the countdown func.
def countdown(t):
    
    while t:
        mins, secs = divmod(t, 60)
        timer = '{:02d}:{:02d}'.format(mins, secs)
        print(timer, end="\r")
        time.sleep(1)
        t -= 1
      
    print('Fire in the hole!!')
  
  
# input time in seconds
t = input("Enter the time in seconds: ")
  
# function call
countdown(int(t))