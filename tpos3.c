#include <stdio.h>
#include <stdlib.h>
typedef struct PDT
{
    int name;
    int size;
    char state;//F= free /A=allocated
}PDT ;
typedef struct WQ
{
    int id;
    int size;
}WQ ;

void readpdt(PDT P[],int n)
{
    for(int i=0; i<n; i++)
    {
        P[i].name=i+1;
        printf("Enter size of Partition %d :",P[i].name);
        scanf("%d",&P[i].size);
        P[i].state='F';
    }
}
void readprocess(WQ Q[],int m)
{
    for(int i=0 ; i < m ; i++)
    {
        Q[i].id=i+1;
        printf("Enter size of process %d : ",Q[i].id);
        scanf("%d",&Q[i].size);
    }
}
void Display_PDT(PDT P[], int n)
{//desplayfunction for pdt
    int i;
    printf("\n");
    printf("+------Memory Partitions+------+\n");
    printf("|   Partition | State | Size   |\n");
    printf("+------------------------------+\n");
    for(i = 0; i < n; i++)
    {
        printf("|%d\t\t|%c\t|%d\t|\n", P[i].name, P[i].state,P[i].size);
    }
        printf("+------------------------------+\n");
}

void firstfit(PDT P[],int n,WQ Q[],int m)
{
    int IF;
    int EX=0;
    for(int i=0;i<n;i++)//pdt counter
    {
        while(P[i].state=='A' && i<n)
        {i++;}
        for(int j=0;i<m;j++)//process counter
        {
    if(P[i].size>=Q[j].size && P[i].state=='F' && Q[j].size != -1 && Q[j].id != -1 )
    {
        P[i].state ='A';
        P[i].name=Q[j].id;
        IF=P[i].size-Q[j].size;
        printf("Process %d is allocated in partition %d \n",Q[i].id,P[i].name);
        Q[j].size= -1 ;
        Q[j].id= -1 ;
            printf("Internal fregmantation of partition %d = %d \n",P[i].name,IF);
            EX=EX+IF;
            break;//break loop of process
    }
    }
    }
    printf("External fregmantation is %d \n",EX);
}
void bestFit(PDT P[],int n,WQ Q[],int m)
{
    int IF,EX;
	for (int i = 0; i < m; i++)//process
	{
		int k = -1;
		for (int j = 0; j < n; j++)//pdt
		{
		            while(P[j].state=='A' && j<n)
                    {j++;}
			if ((P[j].size >= Q[i].size && P[j].state=='F') && (Q[i].size != -1 && Q[i].id != -1) )
			{
				if (k == -1)
					k = j;
				else if (P[k].size > P[j].size)
					k = j;
			}
		}
		if (k != -1)
		{
        P[k].state ='A';
        IF=P[k].size-Q[i].size;
        printf("Process %d is allocated in partition %d \n",Q[i].id,P[k].name);
        P[k].name=Q[i].id;
        Q[i].size=-1;
        Q[i].id=-1;
            printf("Internal fregmantation of partition %d = %d \n",P[i].name,IF);
            EX=EX+IF;
		}
		printf("the wq is : %d \n",Q[i].id);
	}
        printf("External fregmantation is %d",EX);
}

void deallocatedfunction(PDT P[],int n)
{
    char choise='Y';
    int a;
    printf("Which Process you want to terminat? \n");
    while(choise=='Y')
    {
        printf("Enter ID:");
        scanf("%d",&a);
        if(a<=0 || a>n || P[a-1].state=='F'){
            printf("sorry wrong number..\n");
         break;
        }
        for(int i =0;i<n;i++)
        {
        if(P[i].name==a)
        {
        P[i].name=0;
        P[i].state='F';
        break;
        }
        }
        printf("do you want to terminat another one ? (Y/N) :");
        scanf("%c",&choise);
    }
         if(a<=0 || a>n )
        deallocatedfunction(P,n);
}
int main ()
{
    int n,m;
    int choice;
        printf("\n  __  __          _               _  __ \n");
        printf(" |  \\/  |   /\\   | |        /\\   | |/ / \n");
        printf(" | \\  / |  /  \\  | |       /  \\  | ' /  \n");
        printf(" | |\\/| | / /\\ \\ | |      / /\\ \\ |  <   \n");
        printf(" | |  | |/ ____ \\| |____ / ____ \\| . \\  \n");
        printf(" |_|  |_/_/    \\_\\______/_/    \\_\\_|\\_\\ \n");
    printf("how many partition you need? : ");
    scanf("%d",&n);
    PDT P[n];
    printf("how many process you have? : ");
    scanf("%d",&m);
    WQ Q[m];
    do {
        printf("\nWELLCOME\n");
        printf("\t\t\tMENU\t\t\t\t\t\t\t");
        printf("\n============================================================\n");
        printf("1/ Enter DATA\n");
        printf("2/ First Fit\n");
        printf("3/ Best Fit\n");
        printf("4/ Deallocate Process\n");
        printf("5/ Display PDT\n");
        printf("6/ Exit\n");

        do {
            printf("Enter your choice: ");
            scanf("%d", &choice);
        } while(choice < 1 || choice > 6);
        switch(choice) {
            case 1:
                readpdt(P, n);
                readprocess(Q, m);
                break;
            case 2:
                firstfit(P,n,Q,m);
                break;
            case 3:
                bestFit(P,n,Q,m);
                break;
            case 4:
                deallocatedfunction(P,n);
            case 5:
                Display_PDT(P, n);
                break;
            }
            if(choice==6)
            return 0;
    } while(1);
}
