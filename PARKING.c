#include <stdio.h>
#include <stdlib.h>

void Addcar();
int Findcar();
void Space();

int tscar=100;
int carcap=0;


struct node
{
    int cardata;
    struct node* carlink;

};

struct node* startcar=NULL;

void main()
{   int a,r1;
    printf("\t-----------------------------------------------------------------\n");
    printf("\t                PARKING MANAGEMENT\n");
    printf("\t-----------------------------------------------------------------\n");
    printf("\t\tCAR\n\t\t1.Car Entering\n\t\t2.Car exiting\n\t\t3.Total amount from car parking\n\n\t \n\t");
    printf("\t-----------------------------------------------------------------\n");

do{
    printf("\n\t\tSelect a number:-->");
    scanf("%d",&a);

    switch(a)
    {
        case 1:Addcar();
               break;

        case 2:r1=Findcar();
               if(r1==0)
               printf("\t\tThere is no car in parking area.\n");
               else if(r1==1)
               printf("\t\tThere is no such car in parking lot\n");
               else
               printf("\t\tEntery for car number %d is deleted.\n",r1);
               break;



     case 3: Space();
                break;
        default: printf("\t\tWrong choice!!!!!.\n");
    }

  }while(a>=1&&a<=3);
}

void Addcar()
{

 if(carcap<=tscar)
 {
    struct node* p;
    p=(struct node*)malloc(sizeof(struct node));



    printf("\t\tEnter the car number:");
    scanf("%d",&p->cardata);
     p->carlink=NULL;


    if(startcar==NULL)
    {
        startcar=p;
        carcap++;

        printf("\t\tEntry Successful!\n\n");
    }

    else
    {
        struct node* p1;
        p1=startcar;

        while(p1->carlink != NULL)
        {
            p1=p1->carlink;
        }


        p1->carlink=p;
        carcap++;
        printf("\t\tEntry Successful!\n\n");
    }
 }
 else
 {
     printf("\t\tParking area for Car is full\n\n");
 }

}


int Findcar()
{   int n1,loc=1,i=1;
    if(carcap==0)
    {
     return 0;
    }

    else
    {
        printf("\t\tEnter the number of car exiting:");
        scanf("%d",&n1);

        struct node* f1;
        struct node* m1;
        struct node* z1;
        f1=startcar;

        if(f1->carlink==NULL && f1->cardata==n1)
        {
            carcap--;
            startcar=NULL;
            return n1;
        }
        else if(f1->carlink!=NULL)
        {
            while(f1!=NULL)
            {
                loc++;
                if(f1->cardata==n1)
                {
                    carcap--;
                    z1=startcar;
                    while(i<loc-1)
                    {
                       z1=z1->carlink;
                       i++;
                    }
                    z1->carlink=f1->carlink;
                    f1->carlink=NULL;
                    free (f1);

                    return n1;

                }
                f1=f1->carlink;
            }
        }
        else
        {
          return 1;
        }

    }
}





void Space()
{

printf("\n\t\t.......Parking Area.......");

printf("\n\t\tTotal Number of Cars = %d",carcap);



}
