#include<stdio.h>
#include<stdbool.h>

void *raround(int n,int bt[], int wt[], int tat[])
{   int i;

	for (i= 0; i<n;++i)
{
    tat[i] = bt[i] + wt[i];
    
}

}

void roundrob(int bt1[],int tq,int n,int wt[])
{
	int i,pro[200];
	int pid=0;
	int k[200],o=0;
	int bt2[200];
	bool complete=true;
	int tat[200];
	int total_wt=0;
	int total_tat=0;
	i=0;
	        while(i<n)
	{
		pro[i]=bt1[i];
        ++i;
	}
	    i=0;
            while(i<n)
	{
		bt2[i]=bt1[i];
		++i;
	}
	int t=0;
	while(true)
	{
	    complete=true;
		for(i=0;i<n;i++)
		{
			if(pro[i]>0)
			{
			complete=false;
			if(pro[i]>tq)
			{
				t+=tq;
				pro[i]-=tq;
			}
			else
			{
				t=t+pro[i];
				wt[i]=t-bt2[i];
				pro[i]=0;
			if(pro[i]==0)
			{
				k[o]=i;
				o++;
			}
			}
		}
	}
			if(complete==true)
				break;
	}
	printf("\n");

	int k1,j;
	for (i = 0; i < o; i++)

	{
      for (j = i + 1; j < o;)
	  {
         if (k[j] == k[i])
		 {
            for (k1 = j; k1 < o; k1++)
			{
               k[k1] = k[k1 + 1];
            }
            o--;
         }
		 else
            j++;
      }
    }
    raround(n,bt1,wt,tat);
   	printf("\n");
   	printf("\t\t Round Robin Scheduling : ");
	for(i=0;i<o;i++)
	{
		printf("%d ",k[i]);
	}
	int q;
	 for (q=0; q<n; q++)
	 {
	 	total_wt = total_wt + wt[q];
       	total_tat = total_tat + tat[q];
        printf("\n\t\t  %d\t%d\t%d\t%d\n",q,bt1[q],wt[q],tat[q]);
	 }
	 float kq=total_wt/n;
	 float kw=total_tat/n;
	 printf("\n\n\t\t Average Waiting time : %f",kq);
	 printf("\n\n\t\t Average Turnaround time : %f",kw);
	 printf("\n\n\n");
}

void prior(int bt[],int pr[], int n,int p[])
{
	int i,j,temp,pos;
	int tat[200],total=0,wt[200];
	float avg_wt=0,avg_tat=0;
	    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }

        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;

        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
    i=0;
    while(i<n)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];

        total+=wt[i];
        ++i;
    }
    avg_wt=total/n;
	printf("\n\t\t Priority Scheduling gives : ");
	    for (i = 0 ; i <  n; i++)
        printf("%d ",p[i]);
        for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        total+=tat[i];
        printf("\n\t\t %d\t%d\t%d\t%d\n",p[i],bt[i],wt[i],tat[i]);
    }
    avg_tat=total/n;
    printf("\n\n\t\t Average Waiting Time : %f",avg_wt);
    printf("\n\n\t\t Average Turnaround Time : %f",avg_tat);
    printf("\n\n\n");
}
void *fcfsar( int processes[], int n,int bt[], int wt[], int tat[])
{   int i;
    for (i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}
void firstcome(int bt2[],int wt[],int n)
{
	int i,p[200],tat[200],total=0;
	float avg_tat=0,avg_wt=0,total_wt=0,total_tat=0;
    wt[0] = 0;
    for (i = 1; i < n ; i++ )
        wt[i] =bt2[i-1] + wt[i-1];
    fcfsar(p,n,bt2,wt,tat);
    printf("\n\t\t First Come First Serve : ");
    for(i=0;i<n;i++)
    {
    	p[i]=i;
    	printf("%d ",i);
	}

	for(i=0;i<n;i++)
	{
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("\n\t\t %d\t%d\t%d\t%d\n",p[i],bt2[i],wt[i],tat[i]);
	}
	avg_tat=total_tat/n;
	avg_wt=total_wt/n;
    printf("\n\n\t\t Average Waiting Time : %f",avg_wt);
    printf("\n\n\t\t Average Turnaround Time : %f",avg_tat);
	printf("\n\n\n");
}
int main()
{
	int i,j,n,n1,n2,p[200],bt1[200],bt2[200],bt3[200],tq=4,wt[200],wt1[200],pr[200];
	int com[200];
	printf("\n \t\t > Number of process in first queue : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p[i]=i;
		printf("\n\t\t > Burst time of process %d : ",i);
		scanf("%d",&bt1[i]);
	}
	printf("\n \t\t > Number of process in second queue : ");
	scanf("%d",&n1);
	for(i=0;i<n1;i++)
	{
		p[i]=i;
		printf("\n \t\t > Priority of process %d : ",i);
		scanf("%d",&pr[i]);
		printf("\n\t\t > Burst time of process %d : ",i);
		scanf("%d",&bt2[i]);

	}
	printf("\n\t\t > Number of process in third queue : ");
	scanf("%d",&n2);
	for(i=0;i<n2;i++)
	{
		p[i]=i;
		printf("\n\t\t > Burst time of process %d : ",i);
		scanf("%d",&bt3[i]);
	}
	printf("\n Results  > > > \n");
	printf("\n------------------------------------------------------\n");
			roundrob(bt1,tq,n,wt);
			prior(bt2,pr,n1,p);
			firstcome(bt3,wt,n2);
}
