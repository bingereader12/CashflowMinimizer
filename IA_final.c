/* Importing the libraries that are needed for the program to run*/
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
/* Defining the variables that will be used in the program and the maximum number of people*/
#define N 100
#define min(i, j) (((i) < (j)) ? (i) : (j))
int graph[N][N];
char people[N][N];
int n;

//returns index of minimum value in a[]//
int get_min(int a[])
{
    int min_ind = 0;
    for(int i=1; i<n; i++)
    {
        if (a[i] < a[min_ind])
        {
            min_ind = i;
        }
    }
    return min_ind;
}

//returns index of maximum value in a[]//
int get_max(int a[])
{
    int max_ind = 0;
    for(int i=1; i<n; i++)
    {
        if (a[i] > a[max_ind])
        {
            max_ind = i;
        }
    }
    return max_ind;
}

/* amt[p] indicates the net amount to be credited/debited to from person 'p'
  If amt[p] is positive, then i'th person will get amt[i]
  If amt[p] is negative, then i'th person will give  -amt[i]*/
void min_cashflow_rec(int amt[])
{
    int mcr = get_max(amt), mdb = get_min(amt);
    if(amt[mcr] == 0 && amt[mdb] == 0)
    {
        return;
    }
    int minval = min(-amt[mdb], amt[mcr]);
    amt[mcr] -= minval;
    amt[mdb] += minval;
    printf("\n%s will pay Rs.%d to %s",people[mdb],minval,people[mcr]);
    min_cashflow_rec(amt);
}

/*Given a set of persons as graph[] where graph[i][j] indicates the amount that person i needs
  to pay person j, this function finds and prints the minimum cash flow to settle all debts.*/
void min_cashflow(int graph[][N])
{
    int amt[n];
    for(int i=0; i<n; i++)
    {
        amt[i] = 0;
    }
    for(int p=0; p<n; p++)
    {
      for(int i=0; i<n; i++)
      {
        amt[p] += (graph[i][p] -  graph[p][i]);
      }
    }
    min_cashflow_rec(amt);
}

int main()
{
    printf("      ** Welcome to our Data Structures Project on Cash Flow Minimiser. **\n\n");
    printf("                                                                          -made by devesh,riya,ritvik ");
    printf("\nEnter no. of people: ");
    scanf("%d",&n);
    //initialize the graph to 0
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            graph[i][j] = 0;
            people[i][j]="";
        }
    }
    printf("Enter names of people\n");
    //accept names of people who owe each other
    for(int i=0; i<n; i++)
    {
        printf("Enter name %d : ",i+1);
        scanf("%s",&people[i]);
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i == j)
            {
                continue;
            }
            printf("How much %s has to pay %s?   Rs.",people[i],people[j]);
            scanf("%d",&graph[i][j]);
        }
    }
    min_cashflow(graph);
}
