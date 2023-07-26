#include <stdio.h>
#include <stdlib.h>

// pre built
#define TOTALPLOT 5
#define MAXSPACE 200    // east 4 west 2 north 3 south 2
#define MIDIUMSPACE 150 // east 1 west 3 north 2 south 1
#define MINSPACE 100    // east 3 west 1 north 1 south 3
// numofspace in each direction
#define EASTMAX 4
#define EASTMID 1
#define EASTMIN 3

#define WESTMAX 2
#define WESTMID 3
#define WESTMIN 1

#define NORTHMAX 3
#define NORTHMID 2
#define NORTHMIN 1

#define SOUTHMAX 2
#define SOUTHMID 1
#define SOUTHMIN 3

// each parking space have
struct parkingNode
{
    // int plot;
    int carid;
    int needSPACE;
    char location;
    struct parkingNode *nextpNode;
};
struct parkingNode *head;

// function
void beginsert()
{
}
void lastinsert()
{
}
void randominsert()
{
}
void begin_delete()
{
}
void last_delete()
{
}
void random_delete()
{
}
void search()
{
}
void display()
{
}

// pre available space
void preAvailSpace()
{
    printf("Pre Available Space:\n");
    // initializing total parking space
    int eastSize = EASTMAX + EASTMID + EASTMIN;
    struct parkingNode eastNode[eastSize];
    int westSize = WESTMAX + WESTMID + WESTMIN;
    struct parkingNode westNode[westSize];
    int northSize = NORTHMAX + NORTHMID + NORTHMIN;
    struct parkingNode northNode[northSize];
    int southSize = SOUTHMAX + SOUTHMID + SOUTHMIN;
    struct parkingNode southNode[southSize];
    // east
    for (int i = 0; i < eastSize; i++)
    {
        eastNode[i].carid = 0;
        if (i >= 0 && i < EASTMAX)
        {
            eastNode[i].needSPACE = 200;
        }
        else if (i >= EASTMAX && i < (EASTMAX + EASTMID))
        {
            eastNode[i].needSPACE = 150;
        }
        else
        {
            eastNode[i].needSPACE = 100;
        }
        eastNode[i].location = 'e';
    }
    // west
    for (int i = 0; i < westSize; i++)
    {
        westNode[i].carid = 0;
        if (i >= 0 && i < WESTMAX)
        {
            westNode[i].needSPACE = 200;
        }
        else if (i >= WESTMAX && i < (WESTMAX + WESTMID))
        {
            westNode[i].needSPACE = 150;
        }
        else
        {
            westNode[i].needSPACE = 100;
        }
        westNode[i].location = 'w';
    }
    // north
    for (int i = 0; i < northSize; i++)
    {
        northNode[i].carid = 0;
        if (i >= 0 && i < NORTHMAX)
        {
            northNode[i].needSPACE = 200;
        }
        else if (i >= NORTHMAX && i < (NORTHMAX + NORTHMID))
        {
            northNode[i].needSPACE = 150;
        }
        else
        {
            northNode[i].needSPACE = 100;
        }
        northNode[i].location = 'n';
    }
    // south
    for (int i = 0; i < southSize; i++)
    {
        southNode[i].carid = 0;
        if (i >= 0 && i < SOUTHMAX)
        {
            southNode[i].needSPACE = 200;
        }
        else if (i >= SOUTHMAX && i < (SOUTHMAX + SOUTHMID))
        {
            southNode[i].needSPACE = 150;
        }
        else
        {
            southNode[i].needSPACE = 100;
        }
        southNode[i].location = 's';
    }

    // print available space
    printf("\n");
    printf("In East Location :\n");
    for (int i = 0; i < eastSize; i++)
    {
        printf("Car Id :%d Space :%d Location :%c\n", eastNode[i].carid, eastNode[i].needSPACE, eastNode[i].location);
    }
    printf("\n");
    printf("In West Location :\n");
    for (int i = 0; i < westSize; i++)
    {
        printf("Car Id :%d Space :%d Location :%c\n", westNode[i].carid, westNode[i].needSPACE, westNode[i].location);
    }
    printf("\n");
    printf("In North Location :\n");
    for (int i = 0; i < northSize; i++)
    {
        printf("Car Id :%d Space :%d Location :%c\n", northNode[i].carid, northNode[i].needSPACE, northNode[i].location);
    }
    printf("\n");
    printf("In South Location :\n");
    for (int i = 0; i < southSize; i++)
    {
        printf("Car Id :%d Space :%d Location :%c\n", southNode[i].carid, southNode[i].needSPACE, southNode[i].location);
    }
}

int main()
{
    int carID;
    int needSpace;
    char Location;
    int t = 0;
    int choice = 0;
    while (choice != 9)
    {
        printf("\n\n*********Main Menu*********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n0.Pre Available Space\n1.Available Space\n2.Insert in begining\n3.Insert at last\n4.Insert at any random location\n5.Delete from Beginning\n6.Delete from last\n7.Delete node after specified location\n8.Search for an element\n9.Show\n10.Exit\n");
        printf("\nEnter your choice?\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            preAvailSpace();
        case 1:
            // printf("Enter Car ID, Need Space[200,150,100], Location[e,w,n,s] [e.g. 123 200 w]: ");
            // scanf("%d %d %c", &carID, &needSpace, &Location);
            // availSpace(carID, needSpace, Location, t);
            // t++;
        case 2:
            beginsert();
            break;
        case 3:
            lastinsert();
            break;
        case 4:
            randominsert();
            break;
        case 5:
            begin_delete();
            break;
        case 6:
            last_delete();
            break;
        case 7:
            random_delete();
            break;
        case 8:
            search();
            break;
        case 9:
            display();
            break;
        case 10:
            exit(0);
            break;
        default:
            printf("Please enter valid choice..");
        }
    }
}
