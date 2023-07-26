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

// avail space
void availSpace(int carID, int needSpace, char Location, int t)
{
    int pre = 0;
    // something have to do
    if (Location == 'e' && needSpace == 200)
    {
        pre = 1;
    }
    else if (Location == 'e' && needSpace == 150)
    {
        pre = 2;
    }
    else if (Location == 'e' && needSpace == 100)
    {
        pre = 3;
    }
    /*
    //west
    if (Location == 'w' && needSpace == 200)
    {
        pre = 10;
    }
    if (Location == 'w' && needSpace == 150)
    {
        pre = 20;
    }
    if (Location == 'w' && needSpace == 100)
    {
        pre = 30;
    }
    //north
    if (Location == 'n' && needSpace == 200)
    {
        pre = 100;
    }
    if (Location == 'n' && needSpace == 150)
    {
        pre = 200;
    }
    if (Location == 'n' && needSpace == 100)
    {
        pre = 300;
    }
    //south
    if (Location == 's' && needSpace == 200)
    {
        pre = 1000;
    }
    if (Location == 's' && needSpace == 150)
    {
        pre = 2000;
    }
    if (Location == 's' && needSpace == 100)
    {
        pre = 3000;
    }

    */
    // finish that here
    // initializing total parking space
    int eastSize = EASTMAX + EASTMID + EASTMIN;
    struct parkingNode eastNode[eastSize];
    int westSize = WESTMAX + WESTMID + WESTMIN;
    struct parkingNode westNode[westSize];
    int northSize = NORTHMAX + NORTHMID + NORTHMIN;
    struct parkingNode northNode[northSize];
    int southSize = SOUTHMAX + SOUTHMID + SOUTHMIN;
    struct parkingNode southNode[southSize];
    // saving parking space
    //FILE *fileWrite, *fileRead;
    int carArr[100];
    //if(fileWrite==NULL){
    //   printf("File not found\n");
    //}
    // for east side
    if (pre == 1)
    {
        //fileWrite = fopen("parkingSpace.text", "a");
        if (t < EASTMAX)
        {
            eastNode[t].carid = carID;
            carArr[t]=carID;
            //fprintf(fileWrite, "Car ID\n%d\n", carID);
            eastNode[t].needSPACE = 200;
            //fprintf(fileWrite, "Space Requirement\n%d\n", needSpace);
            eastNode[t].location = 'e';
            //fprintf(fileWrite, "Location\n%c\n", eastNode[t].location);
        }
        //fclose(fileWrite);
        //fileRead = fopen("parkingSpace.text","r");
        for(int i=0;i<t;i++){
            eastNode[i].carid = carArr[i];
            eastNode[i].needSPACE = 200;
            eastNode[i].location = 'e';
        }
        for (int i = t + 1; i < eastSize; i++)
        {
            // something to do
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

        //for other space
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
    }
    else if (pre == 2)
    {
        for (int i = 0; i < eastSize; i++)
        {
            if (t == 1 && i == 4)
            {
                eastNode[i].carid = carID;

                eastNode[i].needSPACE = 150;

                eastNode[i].location = 'e';
            }
            else
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
    }
    else if (pre == 3)
    {
        for (int i = 0; i < eastSize; i++)
        {
            if (t == 1 && i == 5)
            {
                eastNode[i].carid = carID;

                eastNode[i].needSPACE = 100;

                eastNode[i].location = 'e';
            }
            else
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
    }
    // for west side
    else if (pre == 10)
    {
        for (int i = 0; i < westSize; i++)
        {
            if (t == 1 && i == 0)
            {
                westNode[i].carid = carID;

                westNode[i].needSPACE = 200;

                westNode[i].location = 'e';
            }
            else
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
    }
    else if (pre == 20)
    {
        for (int i = 0; i < westSize; i++)
        {
            if (t == 1 && i == 0)
            {
                westNode[i].carid = carID;

                westNode[i].needSPACE = 200;

                westNode[i].location = 'e';
            }
            else
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
    }
    else if (pre == 30)
    {
        for (int i = 0; i < westSize; i++)
        {
            if (t == 1 && i == 0)
            {
                westNode[i].carid = carID;

                westNode[i].needSPACE = 200;

                westNode[i].location = 'e';
            }
            else
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
    }
    // for north side
    else if (pre == 100)
    {
        for (int i = 0; i < northSize; i++)
        {
            if (t == 1 && i == 0)
            {
                northNode[i].carid = carID;

                northNode[i].needSPACE = 200;

                northNode[i].location = 'e';
            }
            else
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
    }
    else if (pre == 200)
    {
        for (int i = 0; i < northSize; i++)
        {
            if (t == 1 && i == 0)
            {
                northNode[i].carid = carID;

                northNode[i].needSPACE = 200;

                northNode[i].location = 'e';
            }
            else
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
    }
    else if (pre == 300)
    {
        for (int i = 0; i < northSize; i++)
        {
            if (t == 1 && i == 0)
            {
                northNode[i].carid = carID;

                northNode[i].needSPACE = 200;

                northNode[i].location = 'e';
            }
            else
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
    }
    // for south side
    else if (pre == 1000)
    {
        for (int i = 0; i < southSize; i++)
        {
            if (t == 1 && i == 0)
            {
                southNode[i].carid = carID;

                southNode[i].needSPACE = 200;

                southNode[i].location = 'e';
            }
            else
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
    }
    else if (pre == 2000)
    {
        for (int i = 0; i < southSize; i++)
        {
            if (t == 1 && i == 0)
            {
                southNode[i].carid = carID;

                southNode[i].needSPACE = 200;

                southNode[i].location = 'e';
            }
            else
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
    }
    else if (pre == 3000)
    {
        for (int i = 0; i < southSize; i++)
        {
            if (t == 1 && i == 0)
            {
                southNode[i].carid = carID;

                southNode[i].needSPACE = 200;

                southNode[i].location = 'e';
            }
            else
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
    }
    // primary available space for all location
    else
    {
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
    }
    // printing all spaces
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
        printf("\n0.Available Space\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n5.Delete from last\n6.Delete node after specified location\n7.Search for an element\n8.Show\n9.Exit\n");
        printf("\nEnter your choice?\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            printf("Enter Car ID, Need Space[200,150,100], Location[e,w,n,s] [e.g. 123 200 w]: ");
            scanf("%d %d %c", &carID, &needSpace, &Location);
            availSpace(carID, needSpace, Location, t);
            t++;
        case 1:
            beginsert();
            break;
        case 2:
            lastinsert();
            break;
        case 3:
            randominsert();
            break;
        case 4:
            begin_delete();
            break;
        case 5:
            last_delete();
            break;
        case 6:
            random_delete();
            break;
        case 7:
            search();
            break;
        case 8:
            display();
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("Please enter valid choice..");
        }
    }
}