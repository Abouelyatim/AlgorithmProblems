#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Berkane ibrahim*/
/*Bennaceur- hichem*/
/*SIL2*/

int N;
int save=0;
int ptsave[];

int subsetsum(int n,int *s,int sum)//retuen 1 if subset exist else 0
{
    if(n==0 && sum==0){return 1;}
    if(n==0 && sum!=0){return 0;}
    else
    {
        return (subsetsum(n-1,s,sum) || subsetsum(n-1,s,sum-s[n-1]));
    }
}

int allsubsetsum(int n,int *s,long long sum,int X[])//print all possible subset
{
    int i,count=0;

    if(n==0 && sum==0){
    	//printf("{");
        for(i=0;i<N;i++)
		{
    			if (X[i]) {
                	//printf("%d,", s[i]);
                	count++;
				}
   		 }
   	//printf("}");
    save=count;
    if(count<=save){	
		save=count;	
   		//for(i=0;i<N;i++){ptsave[i]=X[i];}	 
	}
    
    //printf("\n\n");
    return 1;
    }
    
    else{
        if(n==0 && sum!=0){ return 0;}
    	else
    	{
       		 X[n - 1] = 0;
       		 allsubsetsum(n-1,s,sum,X);
       		 X[n - 1] = 1;
       		 allsubsetsum(n-1,s,sum-s[n-1],X);
		 }
    }
    return 0;
}


int main()
{
	
    int n = 30;
    int s[n];
    int i;
    for (i = 0; i < n; i++) {
        s[i] = i + 1;
    }
    int X[n];
    
    long long k = 160;
    N = n;
    
    
    /*if(subsetsum(n,s,k)){printf("1) il ya subset de la somme %d :\n\n",k);
	}
	else {printf("1) il n ya pas subset\n\n");
	}*/
	
//	printf("2) tous les subset possible:\n\n");
	clock_t begin =clock();
	allsubsetsum(n,s,k,X);
	clock_t end =clock();
	clock_t tempExec = (double) (end-begin)*1000/CLOCKS_PER_SEC;
	printf("minimum subset: %d ,time: %d ms",save,tempExec);
	
	
	/*printf("\n3) minimum subset:\n\n");
    printf("{");
    for(i=0;i<N;i++)//print minimal subset
    {	
        if (ptsave[i]) printf("%d,", s[i]);
    }
    printf("}");*/
  
    return 0;
}

    
    
    

