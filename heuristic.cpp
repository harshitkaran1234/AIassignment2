/*We have taken heuristic function as sum of index where queen is placed in each row. Fo ex- queen is placed at {1,1,1,1,1,1,1,1} then h=8.So, we are going to place all queen in possible place and find corresponding "h". One with least "h" will be explored. 
Initial state is {1,1,1,1,1,1,1,1} where each value denotes position of queen in each row, state transition :- we can give any right value between 1 to 8. As for least "h" we have to place queen in next possible index of compared to previous one. So algorithm is as follows-:*/ 

#include<iostream>
using namespace std;
int main(){
  int h,array[9],x=1;//state space will consist of values of column in which queen is placed of each row
  array[0]=0;
  h=0;
  for(int i=1;i<9;i++){
      array[i]=0;//queen is not placed so undefined value will be set which is 0 here
  }
  int a[9]={0,1,2,3,4,5,6,7,8};
  int flag1,flag2,k=0,j;
  flag1=0;
  flag2=0;
 for(int i=1;i<=8;i++){
     if(flag1==1){
         if(array[i]>8){
             i=i-2;
             flag2=1;
         }
         else{
         flag2=0;    
         x=array[i]+1;
         }
     }
     else{
     flag2=0;
     x=1;
     }
     if(flag2!=1){
     while(a[x]<=8){
        for(j=1;j<i;j++){
             if(a[x]==array[j]||a[x]-array[j]==i-j||array[j]-a[x]==i-j){
                 break;
             }
        }
        if(j>=i){
            break;
        }
        else{
        x++;
        }
     }
     if(a[x]>8){
         i=i-2;
         flag1=1;
         h=h-array[i]; //calculation of h
     }
     else{
     flag1=0;  
     array[i]=a[x];
     h=h+array[i];// calculation of h
    
     }
 }
 }
  for(int i=1;i<9;i++){
     cout<<array[i]<<" ";//final state
 }
 

 return 0;}
  
