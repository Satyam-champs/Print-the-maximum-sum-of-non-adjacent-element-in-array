//Print the maximum sum of non-adjacent element in array
//Modified version of maximum sum of non-adjacent element in array
//Author-Satyam Champs
#include<bits/stdc++.h> 
using namespace std;
/*Function to return max sum such that no two elements 
are adjacent */
vector<int> FindMaxSum(int arr[], int n) 
{ 
int inside = 0; 
int outside = 0; 
int new_excl; 
int i;
vector<int> include,exclude,newexclude;

for (i = 0; i < n; i++) 
{ 
	/* current max excluding i */
	if (outside > inside){
            new_excl=outside;
            newexclude=exclude; //update vector if previous arr[i-1] was non-zero where exclude was updated with arr[i] i.e. flag1
	}
	else{
            new_excl=inside;
            newexclude=include; //update vector if previous arr[i-1] was non-zero where exclude was updated with arr[i] i.e. flag1
	}
    /* current max including i */
    inside = outside + arr[i];
    exclude.push_back(arr[i]); // flag1 
    include=exclude;
    outside = new_excl;
    exclude=newexclude;
}
/* return max of incl and excl */
if(outside>inside)
return exclude;
else
return include;

} 

/* Driver program to test above function */
int main() 
{ 
int t;
cin>>t;
while(t--)
{
    int n;
    cin>>n;
    int arr[n],max=-1001;
    for (int i = 0; i<n; i++)
    {
        cin>>arr[i];
        if(arr[i]>max)
        max=arr[i];
    }
    if(max<=0)
    cout<<max<<endl;
    else
        {
        vector<int> output;
        output=FindMaxSum(arr, n);
        int x=output.size();
        for (int i = 0; i < x; i++) 
            {
                if(output[i]!=0)
                cout<<output[i];
            }
        }
}
return 0; 
} 
