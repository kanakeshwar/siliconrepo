#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void nonrec_bin(int [],int,int);
int rec_binse(int [],int,int,int);
int main()
{
  int a[50],n,i,x,ch,pos=-1;
  int low,high;
  printf("\n enter the no elements");
  scanf("%d",&n);
  printf("\n enter the elements");
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  printf("\n enter the element to be search");
  scanf("%d",&x);
  while(1)
  {
  printf("\n \t menu");
  printf("\n 1.binary search using nonrecursive");
  printf("\n 2.binary search recursive");
  printf("\n 3.exit");
  printf("\n enter your choice");
  scanf("%d",&ch);
  switch(ch)
  {
    case 1: printf("\n nonrecursive method");
	    nonrec_bin(a,x,n);
	    getch();
	    break;
   case 2: printf("\n recursive binary search");
	   pos=rec_binse(a,0,n,x);
	   if(pos==-1)
	      printf("\n element is not found");
	   else
	      printf("\n %d element is found at pos %d",x,pos+1);
	   getch();
	   break;
   case 3: exit(1);
   }
   }
}
void nonrec_bin(int a[],int x,int n)
{
  int low=0,high=n-1,mid;
  mid=(low+high)/2;
  while(low<=high)
  {
     if(a[mid]<x)
	 low=mid+1;
     else if(a[mid]==x)
     {
       printf("\n %d is found at location %d",x,mid+1);
       break;
     }
    else
       high=mid-1;
    mid=(low+high)/2;
  if(low>high)
     printf("%d is not found in the array",x);
}
}
int rec_binse(int a[],int low,int high,int x)
{
   int mid;
   mid=(low+high)/2;
    if(low>high)
       return -1;
  else if(a[mid]==x)
      return mid;
   else if(a[mid]>x)
      return rec_binse(a,low,mid-1,x);
   else if(a[mid]<x)
      return rec_binse(a,mid+1,high,x);
    if(low>high)
       return -1;
}
