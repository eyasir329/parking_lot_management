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

// size of each locatiom
int eastSize = EASTMAX + EASTMID + EASTMIN;
int westSize = WESTMAX + WESTMID + WESTMIN;
int northSize = NORTHMAX + NORTHMID + NORTHMIN;
int southSize = SOUTHMAX + SOUTHMID + SOUTHMIN;

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

// function to create a new node
struct parkingNode *createNode(int carID, int needSpace, char Location)
{
    struct parkingNode *newNode = (struct parkingNode *)malloc(sizeof(struct parkingNode));
    newNode->carid = carID;
    newNode->needSPACE = needSpace;
    newNode->location = Location;
    newNode->nextpNode = NULL;
    return newNode;
}

// function to insert a node at the end of the linkedList
void insertEnd(struct parkingNode **head, int carID, int needSpace, char Location)
{
    struct parkingNode *newNode = createNode(carID, needSpace, Location);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct parkingNode *current = *head;
        while (current->nextpNode != NULL)
        {
            current = current->nextpNode;
        }
        current->nextpNode = newNode;
    }
}

// function to concatenate each linked list
struct parkingNode *concatenateLists(struct parkingNode *list1, struct parkingNode *list2)
{
    if (list1 == NULL)
    {
        return list2;
    }
    else if (list2 == NULL)
    {
        return list1;
    }

    struct parkingNode *current = list1;
    while (current->nextpNode != NULL)
    {
        current = current->nextpNode;
    }
    current->nextpNode = list2;
    return list1;
}

//Search a car in the concated linked list
struct parkingNode* search(struct parkingNode* head,int key ){
    struct parkingNode* current = head;
    while(current!=NULL){
        if(current->carid==key){
            return current;
        }
        current = current->nextpNode;
    }
    //if not available return NULL
    return NULL;
}

//Delete A specific Car
void deleteNode(struct parkingNode** head,int key){
    struct parkingNode* current = *head;
    struct parkingNode* prev =NULL;
    //search for the node with the given key
    while (current!=NULL&&current->carid!=key)
    {
        prev=current;
        current= current->nextpNode;
    }
    //if the car is not found in the list
    if(current==NULL){
        printf("This Car ID isn't found in our Linked list\n");
        return;
    }
    //if the node to be deleted is the head node
    if(prev==NULL){
        *head=current->nextpNode;
    }else{
        prev->nextpNode=current->nextpNode;
    }
    free(current);
}

// display linked list
void displayList(struct parkingNode *head)
{
    struct parkingNode *current = head;
    while (current != NULL)
    {
        printf("%d %d %c\n", current->carid, current->needSPACE, current->location);
        current = current->nextpNode;
    }
}



// pre available space
void preAvailSpace()
{
    printf("Pre Available Space:\n");
    // initializing total parking space
    struct parkingNode eastNode[eastSize];
    struct parkingNode westNode[westSize];
    struct parkingNode northNode[northSize];
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
    // east side node
    struct parkingNode *eastMAX = NULL;
    struct parkingNode *eastMID = NULL;
    struct parkingNode *eastMIN = NULL;
    int ems = 0, emis = 0, emin = 0;
    // west side node
    struct parkingNode *westMAX = NULL;
    struct parkingNode *westMID = NULL;
    struct parkingNode *westMIN = NULL;
    int wms = 0, wmis = 0, wmin = 0;
    // north side node
    struct parkingNode *northMAX = NULL;
    struct parkingNode *northMID = NULL;
    struct parkingNode *northMIN = NULL;
    int nms = 0, nmis = 0, nmin = 0;
    // south side node
    struct parkingNode *southMAX = NULL;
    struct parkingNode *southMID = NULL;
    struct parkingNode *southMIN = NULL;
    int sms = 0, smis = 0, smin = 0;

    int carID;
    int needSpace;
    char Location;
    int key;

    int choice = 0;
    while (choice != 9)
    {
        printf("\n\n*********Main Menu*********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n0.Pre Available Space\n1.Insert Car in the Parking Lot\n2.Printing Booked Space After Adding Car in the Parking Lor\n3.Available Space After Adding Car in the Parking Lot\n4.Print All Linked List At one Place\n5.Searching a Car Using Car ID\n6.Free Up the Space\n7.Display After Deletion\n10.Exit\n");
        printf("\nEnter your choice?\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            preAvailSpace();
            break;
        case 1:
            printf("Enter Car ID, Need Space[200,150,100], Location[e,w,n,s] [e.g. 123 200 w]: ");
            scanf("%d %d %c", &carID, &needSpace, &Location);
            // some condition
            // have to do
            // east side start
            // EAST MAX
            if (Location == 'e' && needSpace == 200)
            {
                if (ems == EASTMAX)
                {
                    printf("You are breaking limit in our Allocated Space\n");
                    printf("Not find any space in this lot\n");
                    printf("Please Check Our Available List, and Try again\n");
                }
                else
                {
                    insertEnd(&eastMAX, carID, needSpace, Location);
                    printf("Location East ----- Size Maximum[200]\n");
                    printf("Booked Space :%d\nAvailable Space :%d\nTotal Space :%d\n", ems + 1, EASTMAX - (ems + 1), EASTMAX);
                    ems++;
                }
            }
            // EAST MID
            else if (Location == 'e' && needSpace == 150)
            {
                if (emis == EASTMID)
                {
                    printf("You are breaking limit in our Allocated Space\n");
                    printf("Not find any space in this lot\n");
                    printf("Please Check Our Available List, and Try again\n");
                }
                else
                {
                    insertEnd(&eastMID, carID, needSpace, Location);
                    printf("Location East ----- Size Midium[150]\n");
                    printf("Booked Space :%d\nAvailable Space :%d\nTotal Space :%d\n", emis + 1, EASTMID - (emis + 1), EASTMID);
                    emis++;
                }
            }
            // EAST MIN
            else if (Location == 'e' && needSpace == 100)
            {
                if (emin == EASTMIN)
                {
                    printf("You are breaking limit in our Allocated Space\n");
                    printf("Not find any space in this lot\n");
                    printf("Please Check Our Available List, and Try again\n");
                }
                else
                {
                    insertEnd(&eastMIN, carID, needSpace, Location);
                    printf("Location East ----- Size Minimum[100]\n");
                    printf("Booked Space :%d \nAvailable Space :%d\nTotal Space :%d\n", emin + 1, EASTMIN - (emin + 1), EASTMIN);
                    emin++;
                }
            }
            // east side end
            // west side start
            // WEST MAX
            else if (Location == 'w' && needSpace == 200)
            {
                if (wms == WESTMAX)
                {
                    printf("You are breaking limit in our Allocated Space\n");
                    printf("Not find any space in this lot\n");
                    printf("Please Check Our Available List, and Try again\n");
                }
                else
                {
                    insertEnd(&westMAX, carID, needSpace, Location);
                    printf("Location West ----- Size Maximum[200]\n");
                    printf("Booked Space :%d\nAvailable Space :%d\nTotal Space :%d\n", wms + 1, WESTMAX - (wms + 1), WESTMAX);
                    wms++;
                }
            }
            // WEST MID
            else if (Location == 'w' && needSpace == 150)
            {
                if (wmis == WESTMID)
                {
                    printf("You are breaking limit in our Allocated Space\n");
                    printf("Not find any space in this lot\n");
                    printf("Please Check Our Available List, and Try again\n");
                }
                else
                {
                    insertEnd(&westMID, carID, needSpace, Location);
                    printf("Location West ----- Size Midium[150]\n");
                    printf("Booked Space :%d\nAvailable Space :%d\nTotal Space :%d\n", wmis + 1, WESTMID - (wmis + 1), WESTMID);
                    wmis++;
                }
            }
            // WEST MIN
            else if (Location == 'w' && needSpace == 100)
            {
                if (wmin == WESTMIN)
                {
                    printf("You are breaking limit in our Allocated Space\n");
                    printf("Not find any space in this lot\n");
                    printf("Please Check Our Available List, and Try again\n");
                }
                else
                {
                    insertEnd(&westMIN, carID, needSpace, Location);
                    printf("Location West ----- Size Minimum[100]\n");
                    printf("Booked Space :%d \nAvailable Space :%d\nTotal Space :%d\n", wmin + 1, WESTMIN - (wmin + 1), WESTMIN);
                    wmin++;
                }
            }
            // west side end
            // north side start
            // NORTH MAX
            else if (Location == 'n' && needSpace == 200)
            {
                if (nms == NORTHMAX)
                {
                    printf("You are breaking limit in our Allocated Space\n");
                    printf("Not find any space in this lot\n");
                    printf("Please Check Our Available List, and Try again\n");
                }
                else
                {
                    insertEnd(&northMAX, carID, needSpace, Location);
                    printf("Location North ----- Size Maximum[200]\n");
                    printf("Booked Space :%d\nAvailable Space :%d\nTotal Space :%d\n", nms + 1, NORTHMAX - (nms + 1), NORTHMAX);
                    nms++;
                }
            }
            // NORTH MID
            else if (Location == 'n' && needSpace == 150)
            {
                if (nmis == NORTHMID)
                {
                    printf("You are breaking limit in our Allocated Space\n");
                    printf("Not find any space in this lot\n");
                    printf("Please Check Our Available List, and Try again\n");
                }
                else
                {
                    insertEnd(&northMID, carID, needSpace, Location);
                    printf("Location North ----- Size Midium[150]\n");
                    printf("Booked Space :%d\nAvailable Space :%d\nTotal Space :%d\n", nmis + 1, NORTHMID - (nmis + 1), NORTHMID);
                    nmis++;
                }
            }
            // NORTH MIN
            else if (Location == 'n' && needSpace == 100)
            {
                if (nmin == NORTHMIN)
                {
                    printf("You are breaking limit in our Allocated Space\n");
                    printf("Not find any space in this lot\n");
                    printf("Please Check Our Available List, and Try again\n");
                }
                else
                {
                    insertEnd(&northMIN, carID, needSpace, Location);
                    printf("Location North ----- Size Minimum[100]\n");
                    printf("Booked Space :%d \nAvailable Space :%d\nTotal Space :%d\n", nmin + 1, NORTHMIN - (nmin + 1), NORTHMIN);
                    nmin++;
                }
            }
            // north side end
            // south side start
            // SOUTH MAX
            else if (Location == 's' && needSpace == 200)
            {
                if (sms == SOUTHMAX)
                {
                    printf("You are breaking limit in our Allocated Space\n");
                    printf("Not find any space in this lot\n");
                    printf("Please Check Our Available List, and Try again\n");
                }
                else
                {
                    insertEnd(&southMAX, carID, needSpace, Location);
                    printf("Location South ----- Size Maximum[200]\n");
                    printf("Booked Space :%d\nAvailable Space :%d\nTotal Space :%d\n", sms + 1, SOUTHMAX - (sms + 1), SOUTHMAX);
                    sms++;
                }
            }
            // SOUTH MID
            else if (Location == 's' && needSpace == 150)
            {
                if (smis == SOUTHMID)
                {
                    printf("You are breaking limit in our Allocated Space\n");
                    printf("Not find any space in this lot\n");
                    printf("Please Check Our Available List, and Try again\n");
                }
                else
                {
                    insertEnd(&southMID, carID, needSpace, Location);
                    printf("Location South ----- Size Midium[150]\n");
                    printf("Booked Space :%d\nAvailable Space :%d\nTotal Space :%d\n", smis + 1, SOUTHMID - (smis + 1), SOUTHMID);
                    smis++;
                }
            }
            // SOUTH MIN
            else if (Location == 's' && needSpace == 100)
            {
                if (smin == SOUTHMIN)
                {
                    printf("You are breaking limit in our Allocated Space\n");
                    printf("Not find any space in this lot\n");
                    printf("Please Check Our Available List, and Try again\n");
                }
                else
                {
                    insertEnd(&southMIN, carID, needSpace, Location);
                    printf("Location South ----- Size Minimum[100]\n");
                    printf("Booked Space :%d \nAvailable Space :%d\nTotal Space :%d\n", smin + 1, SOUTHMIN - (smin + 1), SOUTHMIN);
                    smin++;
                }
            }else{
                printf("Your Input isn't fill our requirement\nPlease Try Again!\n");
            }
            // south side end
            // condition end
            break;
        case 2:
            printf("Booked Space After adding Car\n");

            printf("East Location\n");
            displayList(eastMAX);
            displayList(eastMID);
            displayList(eastMIN);

            printf("West Location\n");
            displayList(westMAX);
            displayList(westMID);
            displayList(westMIN);

            printf("North Location\n");
            displayList(northMAX);
            displayList(northMID);
            displayList(northMIN);

            printf("South Location\n");
            displayList(southMAX);
            displayList(southMID);
            displayList(southMIN);
            break;

        case 3:
            printf("Availabe Space After adding Car\n");

            printf("Total Space Available in the East side\n");
            printf("200 Space Requirement : %d\n", EASTMAX - ems);
            printf("150 Space Requirement : %d\n", EASTMID - emis);
            printf("100 Space Requirement : %d\n", EASTMIN - emin);

            printf("Total Space Available in the East side\n");
            printf("200 Space Requirement : %d\n", WESTMAX - wms);
            printf("150 Space Requirement : %d\n", WESTMID - wmis);
            printf("100 Space Requirement : %d\n", WESTMIN - wmin);

            printf("Total Space Available in the East side\n");
            printf("200 Space Requirement : %d\n", NORTHMAX - nms);
            printf("150 Space Requirement : %d\n", NORTHMID - nmis);
            printf("100 Space Requirement : %d\n", NORTHMIN - nmin);

            printf("Total Space Available in the East side\n");
            printf("200 Space Requirement : %d\n", SOUTHMAX - sms);
            printf("150 Space Requirement : %d\n", SOUTHMID - smis);
            printf("100 Space Requirement : %d\n", SOUTHMIN - smin);
            break;
        case 4:
            // concatenated each linked list for Searching
            printf("Concatenate all List\n");
            struct parkingNode *concatenatedList = concatenateLists(eastMAX, eastMID);
            concatenatedList = concatenateLists(concatenatedList, eastMIN);
            concatenatedList = concatenateLists(concatenatedList, westMAX);
            concatenatedList = concatenateLists(concatenatedList, westMID);
            concatenatedList = concatenateLists(concatenatedList, westMIN);
            concatenatedList = concatenateLists(concatenatedList, northMAX);
            concatenatedList = concatenateLists(concatenatedList, northMID);
            concatenatedList = concatenateLists(concatenatedList, northMIN);
            concatenatedList = concatenateLists(concatenatedList, southMAX);
            concatenatedList = concatenateLists(concatenatedList, southMID);
            concatenatedList = concatenateLists(concatenatedList, southMIN);
            displayList(concatenatedList);
            break;
        case 5:
            printf("Searching Car using Car ID\n");
            printf("Enter Car ID:\n");
            scanf("%d",&key);
            struct parkingNode* foundNode = search(concatenatedList,key);
            if(foundNode!=NULL){
                printf("Car Found \n");
                printf("Car ID :%d\nRequired Space :%d\nLocation :%c\n",foundNode->carid,foundNode->needSPACE,foundNode->location);
            }else{
                printf("Car ID :%d isn't Found in our list\n",carID);
            }
            break;
        case 6:
            printf("Delete a Car That are found in case 5\n");
            if(foundNode!=NULL){
                deleteNode(&concatenatedList,key);
                printf("Car ID %d deleted from the list\n",key);
            }else{
                printf("Car ID %d isn't deleted from the list\n",key);
            }
            break;
        case 7:
            printf("Show Final Linked List\n");
            displayList(concatenatedList);
            break;
        case 10:
            exit(0);
            break;
        default:
            printf("Please enter valid choice..");
        }
    }
}
