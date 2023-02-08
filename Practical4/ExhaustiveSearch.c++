
#include<iostream>
using namespace std;
 
int exhaustive(int head,int foot,int *chicken,int * rabbit) //function for exhaustive search
{
int re,i,j;
re=0;
for(i=0;i<=head;i++){ //iterate
j=head-i;
if(i*2+j*4==foot){ //judge

re=1; //to find the answer
*chicken=i;
*rabbit=j; 

}
}
return re; //return the index 
}
int main()
{
int chicken,rabbit,head,foot;
int re;

cout<<" Please enter the number of heads: ";
cin>>head;
cout<<" Please enter the number of feet: ";
cin>>foot;
re=exhaustive(head,foot,&chicken,&rabbit);
if(re==1)
{
cout<<" The chicken has "<<chicken<<" is the only, rabbit "<<rabbit<<" Only. "<<endl;
}
else
{
cout<<" Unsolvable! "<<endl;
}
return 0; 
} 
