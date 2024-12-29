#include <bits/stdc++.h> 
int findGcd(int x, int y)
{   

    // Write your code here
    while (x != 0 && y != 0) {
      if (x > y) {
          x = x-y;
      } else {
          y = y-x;
      }
    }
    if(x==0)return y;
    return x;
}
