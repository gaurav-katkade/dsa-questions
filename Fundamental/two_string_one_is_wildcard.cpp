#include<iostream>
using namespace std;
bool check(char *str1, char * str2) 
{ 
    cout<<str1<<" "<<str2<<endl;
    // checking end of both the strings 
    if (*str1 == '\0' && *str2 == '\0') 
         return true; 
  
    // comparing the characters of both the strings and wild characters(*)
    if (*str1 == '*' && *(str1+1) != '\0' && *str2 == '\0') 
         return false; 
  
    // checking wild characters(?) 
    if (*str1 == '?' || *str1 == *str2) 
         return check(str1+1, str2+1); 
  
    
    if (*str1 == '*') 
         return check(str1+1, str2) || check(str1, str2+1); 
     return false; 
}
int main() 
{ 
    char str1[100],str2[100];
    printf("Enter first string with wild characters : ");
    gets(str1);
    printf("Enter second string without wild characters : ");
    gets(str2);
    cout<<check(str1,str2);
    return 0; 
} 

