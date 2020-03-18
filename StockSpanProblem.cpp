#include <iostream> 
#include <stack> 
using namespace std; 
  

#include<iostream>
#include<stack>
using namespace std;
 class spanData{
     
     public:
     int data;
     int key = 1;

 };
void calculateSpan(spanData stockPrice[],int n){
    stack<spanData> s1;
    stack<spanData> s2;
    s2.push(stockPrice[0]);
    for (int i = 1; i < n; i++)
    { 
        spanData sp = s2.top();
        if (!stockPrice[i].data < stockPrice[i-1].data)
        {
        
       while(stockPrice[i].data > sp.data)
       {   
           s1.push(s2.top());
           s2.pop();
           if (s2.empty()){
           break;}
           sp = s2.top();
           
       }
       s2.push(stockPrice[i]);
       while (!s1.empty())
       { 
           stockPrice[i].key++;
           s2.push(s1.top());
           s1.pop();
       }}
  }

}
int main(){
    int sp[] = { 100, 80, 60, 70, 60, 75, 85};   
    int n = sizeof(sp)/sizeof(sp[0]);
    spanData stockPrice[n];
    for (int i = 0; i < n; i++)
    stockPrice[i].data = sp[i];
    
    calculateSpan(stockPrice,n);
    for(int i = 0; i < n; i++)
    {
        cout<<stockPrice[i].key<<" ";
    }
    
    
     return 0;
 } 
  

