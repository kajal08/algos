#include<iostream>
using namespace std;
int comp=0;
void mergesort(int a[], int i, int j);
void merge(int a[], int i1,int j1, int i2, int j2);
int main()
{
	int n,t,j;
	cout<<"\nEnter the size of array:\n";
	cin>>n;
	int ar[n];
	cout<<"\nEnter elements in an array:\n";
	for(int i=0;i<n;i++)
		cin>>ar[i];
	cout<<"\nElements are:\n";
		for(int i=0;i<n;i++)
		cout<<ar[i]<<" ";
	mergesort(ar,0,n-1);
	cout<<"\nsorted array is:\n";
	for(int i=0;i<n;i++)
		cout<<" "<<ar[i];
	cout<<"\nTotal number of comparisons are: "<<comp;
	return 0;
}
void mergesort(int a[],int i,int j)
{
	int mid;
	if(i<j)
	{
		mid=(i+j)/2;
		mergesort(a,i,mid);		
		mergesort(a,mid+1,j);	
		merge(a,i,mid,mid+1,j);	
	}
}
 void merge(int a[],int i1,int j1,int i2,int j2)
{
	int temp[50];	
	int i,j,k;
	i=i1;	
	j=i2;	
	k=0;
	while(i<=j1 && j<=j2)	
	{
		if(a[i]<a[j])
		{
			temp[k++]=a[i++];
			comp++;
		}
		else
		{
			temp[k++]=a[j++];
			comp++;
		}
	}
	while(i<=j1)
		temp[k++]=a[i++];
	while(j<=j2)
		temp[k++]=a[j++];
	for(i=i1,j=0;i<=j2;i++,j++)
		a[i]=temp[j];
}
