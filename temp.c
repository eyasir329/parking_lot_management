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

// avail space
void availSpace()
{

    int pre = 0;
    // east location
    int eastSize = EASTMAX + EASTMID + EASTMIN;
    struct parkingNode eastNode[eastSize];
    for (int i = 0; i < eastSize; i++)
    {
        if (pre == 0)
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
    }
    // west
    int westSize = WESTMAX + WESTMID + WESTMIN;
    struct parkingNode westNode[westSize];
    for (int i = 0; i < westSize; i++)
    {
        if (pre == 0)
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
    }
    // north
    int northSize = NORTHMAX + NORTHMID + NORTHMIN;
    struct parkingNode northNode[northSize];
    for (int i = 0; i < northSize; i++)
    {
        if (pre == 0)
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
    }
    // south
    int southSize = SOUTHMAX + SOUTHMID + SOUTHMIN;
    struct parkingNode southNode[southSize];
    for (int i = 0; i < southSize; i++)
    {
        if (pre == 0)
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
    }

    // printing
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

// add at the beginning of our parking lot
void beginsert(int CarID, int needSpace, char Location)
{
    struct parkingNode *ptr;
    int item;
    ptr = (struct parkingNode *)malloc(sizeof(struct parkingNode *));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
        availSpace(CarID,needSpace,Location);
    }
    else
    {
        ptr->carid = CarID;
        ptr->location = Location;
        ptr->nextpNode = head;
        head = ptr;
        printf("\nNode inserted");
    }
}

void display()
{
    struct parkingNode *ptr;
    ptr = head;
    if (ptr == NULL)
    {
        printf("Nothing to print");
    }
    else
    {
        printf("\n===============================================\n");
        printf("\nprinting values . . . . .\n");
        while (ptr != NULL)
        {
            printf("%d %c", ptr->carid, ptr->location);
            ptr = ptr->nextpNode;
        }
    }
}

// main function
int main()
{
    int carID;
    int needSpace;
    char Location;

    //
    int choice = 0;
    while (choice != 9)
    {
        printf("\n\n*********Main Menu*********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n0.Avail Space\n1.Insert in begining\n8.Show");
        printf("\nEnter your choice?\n");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 0:
            availSpace();
            break;
        case 1:
            printf("Enter Carid :");
            scanf("%d", &carID);
            printf("Required Space [%d, %d, %d] :", MAXSPACE, MIDIUMSPACE, MINSPACE);
            scanf("%d", &needSpace);
            printf("Enter Location [e,w,n,s]: ");
            scanf("%c", &Location);
            printf("\n");
            beginsert(carID, needSpace, Location);
            break;

        case 8:
            display();
            break;

        default:
            printf("Please enter valid choice..");
        }
    }

    return 0;
}