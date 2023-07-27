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

// Search a car in the concated linked list
struct parkingNode *search(struct parkingNode *head, int key)
{
    struct parkingNode *current = head;
    while (current != NULL)
    {
        if (current->carid == key)
        {
            return current;
        }
        current = current->nextpNode;
    }
    // if not available return NULL
    return NULL;
}

// Delete A specific Car
void deleteNode(struct parkingNode **head, int key)
{
    struct parkingNode *current = *head;
    struct parkingNode *prev = NULL;
    // search for the node with the given key
    while (current != NULL && current->carid != key)
    {
        prev = current;
        current = current->nextpNode;
    }
    // if the car is not found in the list
    if (current == NULL)
    {
        printf("This Car ID isn't found in our Linked list\n");
        return;
    }
    // if the node to be deleted is the head node
    if (prev == NULL)
    {
        *head = current->nextpNode;
    }
    else
    {
        prev->nextpNode = current->nextpNode;
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

// car structure started
//  Each car have
struct carNode
{
    int CarID;
    int NeedSpace;
    char Location;
    struct carNode *nextCar;
};

struct carNode *frontCar = NULL;
struct carNode *rearCar = NULL;

// Enqueue() operation on our waiting list
void carEnqueue(int carID, int needSpace, char location)
{
    struct carNode *carPtr;
    carPtr = (struct carNode *)malloc(sizeof(struct carNode));
    carPtr->CarID = carID;
    carPtr->NeedSpace = needSpace;
    carPtr->Location = location;
    carPtr->nextCar = NULL;
    if ((frontCar == NULL) && (rearCar == NULL))
    {
        frontCar = rearCar = carPtr;
    }
    else
    {
        rearCar->nextCar = carPtr;
        rearCar = carPtr;
    }
    printf("=====================================================================\n");
    printf("\t\tInserted Car ID:%d in our waiting list successful\n", carID);
    printf("=====================================================================\n");
}

// Dequeue() operation on a queue
struct carNode *carDequeue()
{
    struct carNode *tempQueue;
    if (frontCar == NULL)
    {
        printf("\nUnderflow\n");
        // return -1;
    }
    else
    {
        struct carNode *temp = frontCar;
        tempQueue->CarID = frontCar->CarID;
        tempQueue->NeedSpace = frontCar->NeedSpace;
        tempQueue->Location = frontCar->Location;
        // int temp_data = frontCar->CarID;
        frontCar = frontCar->nextCar;
        free(temp);
        // return temp_data;
        return tempQueue;
    }
    printf("=====================================================================\n");
    printf("\t\tMoving Car ID:%d Waiting list to Main Parking Slot Successfully\n", tempQueue->CarID);
    printf("=====================================================================\n");
}

// Display all elements of the queue
void displayQueue()
{
    struct carNode *temp;
    if ((frontCar == NULL) && (rearCar == NULL))
    {
        printf("\nCar Waiting list is Empty\n");
    }
    else
    {
        printf("Car Waiting list is:\n \n");
        temp = frontCar;
        while (temp != NULL)
        {
            printf("Car ID :%d Need Space :%d Location :%c--->\n", temp->CarID, temp->NeedSpace, temp->Location);
            temp = temp->nextCar;
        }
        printf("NULL\n");
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

// user switch case
void userSwitch(int carID, int needSpace, char location)
{
    int userChoice, pay;
    while (userChoice != 6)
    {
        printf("\n\t\t1.Have to Book a Space\n\t\t2.Receive Your PreBooked Slip\n\t\t3.Payment Confirmation\n\t\t4.Confirmation Slip\n\t\t5.Display Car Waiting List\n\t\t6.Exit from User Mode\n");
        printf("\n\n\t\tEnter your choice : ");
        scanf("%d", &userChoice);
        switch (userChoice)
        {
        case 1:
            printf("=====================================================================\n");
            printf("\t\tYou have to Insert a car in our Parking Space\n");
            printf("=====================================================================\n");
            printf("\t\tPlease Fill up the Requirement that we need\n");
            printf("\t\tCar ID: ");
            scanf("%d", &carID);
            printf("\n\t\tHow much space in your car need [100,150,200]: ");
            scanf("%d", &needSpace);
            printf("\n\t\tEnter location that you prefer\n\t\t[East-e,West-w,North-n,South-s]: ");
            scanf("%s", &location);
            if ((needSpace == 100 || needSpace == 150 || needSpace == 200) && (location == 'e' || location == 'w' || location == 'n' || location == 's'))
            {
                carEnqueue(carID, needSpace, location);
            }
            else
            {
                printf("=====================================================================\n");
                printf("\t\tInput Requirement Failed\n");
                printf("\t\tPlease Input Again!\n");
                printf("=====================================================================\n");
            }
            break;
        case 2:
            FILE *preBook;
            preBook = fopen("preBooked.text", "w");
            if (preBook == NULL)
            {
                printf("Error To Making the Slip");
            }
            else
            {
                if (carID != 0)
                {
                    fprintf(preBook, "===========================================\n");
                    fprintf(preBook, "\t\tABC Parking Company\n");
                    fprintf(preBook, "===========================================\n");
                    fprintf(preBook, "\t\tWaiting Confirmation\n\n");
                    fprintf(preBook, "\t\tCar ID :%d\n", carID);
                    fprintf(preBook, "\t\tNeed Space :%d\n", needSpace);
                    // location
                    if (location == 'e')
                    {
                        fprintf(preBook, "\t\tLocation :EAST\n");
                    }
                    else if (location == 'w')
                    {
                        fprintf(preBook, "\t\tLocation :WEST\n");
                    }
                    else if (location == 'n')
                    {
                        fprintf(preBook, "\t\tLocation :NORTH\n");
                    }
                    else
                    {
                        fprintf(preBook, "\t\tLocation :SOUTH\n");
                    }
                    // pay
                    if (needSpace == 100)
                    {
                        fprintf(preBook, "\t\tHave to Pay :100TK\n");
                    }
                    else if (needSpace == 150)
                    {
                        fprintf(preBook, "\t\tHave to Pay :200TK\n");
                    }
                    else
                    {
                        fprintf(preBook, "\t\tHave to Pay :300TK\n");
                    }
                    fprintf(preBook, "\t\tWaiting From Payment Confirmation\n");
                    fprintf(preBook, "===========================================\n");
                    fprintf(preBook, "\t\tThanks For Choosing Our Services\n");
                    fprintf(preBook, "===========================================\n");
                    printf("=====================================================================\n");
                    printf("\t\tSuccessfully Done To Make PreBooked Slip\n");
                    printf("=====================================================================\n");
                }
                else
                {
                    printf("=====================================================================\n");
                    printf("\t\tRequirement Failed\n");
                    printf("\t\tYou have to make a slip before you enter a car\n");
                    printf("=====================================================================\n");
                }
            }
            fclose(preBook);
            break;
        case 3:
            printf("=====================================================================\n");
            printf("\t\tPayment Confirmation\n");
            printf("=====================================================================\n");
            FILE *fPay;
            fPay = fopen("payment.csv", "a");
            if (fPay == NULL)
            {
                printf("\n\t\tpayment.csv not find\n");
            }
            if (needSpace == 100)
            {
                printf("\t\tHave to Pay :100TK\n");
                printf("\n\t\tEnter You Payment :");
                scanf("%d", &pay);
                if (pay == 100)
                {
                    printf("=====================================================================\n");
                    printf("\t\tYour Payment is Done\n");
                    printf("=====================================================================\n");
                    fprintf(fPay, "%d,%d\n", carID, pay);
                }
                else
                {
                    printf("\n\t\tYou Tried Wrong Payment");
                }
            }
            else if (needSpace == 150)
            {
                printf("\t\tHave to Pay :200TK\n");
                printf("\n\t\tEnter You Payment :");
                scanf("%d", &pay);
                if (pay == 200)
                {
                    printf("=====================================================================\n");
                    printf("\t\tYour Payment is Done\n");
                    printf("=====================================================================\n");
                    fprintf(fPay, "%d,%d\n", carID, pay);
                }
                else
                {
                    printf("\n\t\tYou Tried Wrong Payment");
                }
            }
            else
            {
                printf("\t\tHave to Pay :300TK\n");
                printf("\n\t\tEnter You Payment :");
                scanf("%d", &pay);
                if (pay == 300)
                {
                    printf("=====================================================================\n");
                    printf("\t\tYour Payment is Done\n");
                    printf("=====================================================================\n");
                    fprintf(fPay, "%d,%d\n", carID, pay);
                }
                else
                {
                    printf("\n\t\tYou Tried Wrong Payment");
                }
            }
            fclose(fPay);
            break;
        case 4:
            printf("=====================================================================\n");
            printf("\t\tReceive The Slip\n");
            printf("=====================================================================\n");
            FILE *paySlip;
            paySlip = fopen("paymentConfirmed.text", "w");
            if (paySlip == NULL)
            {
                printf("Error To Making the Slip");
            }
            else
            {
                if (carID != 0)
                {
                    fprintf(paySlip, "===========================================\n");
                    fprintf(paySlip, "\t\tABC Parking Company\n");
                    fprintf(paySlip, "===========================================\n");
                    fprintf(paySlip, "\t\tPayment Slip\n\n");
                    fprintf(paySlip, "\t\tCar ID :%d\n", carID);
                    fprintf(paySlip, "\t\tNeed Space :%d\n", needSpace);
                    // location
                    if (location == 'e')
                    {
                        fprintf(paySlip, "\t\tLocation :EAST\n");
                    }
                    else if (location == 'w')
                    {
                        fprintf(paySlip, "\t\tLocation :WEST\n");
                    }
                    else if (location == 'n')
                    {
                        fprintf(paySlip, "\t\tLocation :NORTH\n");
                    }
                    else
                    {
                        fprintf(paySlip, "\t\tLocation :SOUTH\n");
                    }
                    // pay
                    if (needSpace == 100)
                    {
                        if (pay == 100)
                        {
                            fprintf(paySlip, "\t\tPayment Done 100TK\n");
                        }
                        else
                        {
                            fprintf(paySlip, "\t\tPayment Not Done 100TK\n");
                        }
                    }
                    else if (needSpace == 150)
                    {
                        if (pay == 200)
                        {
                            fprintf(paySlip, "\t\tPayment Done 200TK\n");
                        }
                        else
                        {
                            fprintf(paySlip, "\t\tPayment Not Done 200TK\n");
                        }
                    }
                    else
                    {
                        if (pay == 300)
                        {
                            fprintf(paySlip, "\t\tPayment Done 300TK\n");
                        }
                        else
                        {
                            fprintf(paySlip, "\t\tPayment Not Done 300TK\n");
                        }
                    }
                    fprintf(paySlip, "\t\tPayment Confirmed\n");
                    fprintf(paySlip, "===========================================\n");
                    fprintf(paySlip, "\t\tThanks For Choosing Our Services\n");
                    fprintf(paySlip, "===========================================\n");
                    printf("\t\tSuccessfully Done To Make Payment Slip\n");
                    printf("=====================================================================\n");
                }
                else
                {
                    printf("=====================================================================\n");
                    printf("\t\tRequirement Failed\n");
                    printf("\t\tYou have to make a slip before you enter a car\n");
                    printf("=====================================================================\n");
                }
            }
            fclose(paySlip);
            break;
        case 5:
            printf("=====================================================================\n");
            printf("Display All Car That are just enroled in our waiting list\n");
            displayQueue();
            printf("=====================================================================\n");
            break;
        case 6:
            printf("=====================================================================\n");
            printf("\t\tExited Successfully from User Mode\n");
            printf("=====================================================================\n");
            // exit(0);
            break;
        default:
            printf("=====================================================================\n");
            printf("\t\tWrong Choice\n");
            printf("=====================================================================\n");
            break;
        }
    }
}

// admin switch case
void adminSwitch(int carID, int needSpace, char location)
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

    // checking
    // printf("%d %d %c\n", carID, needSpace, location);
    int lcarID;
    int lneedSpace;
    char lLocation;
    int key;

    int adminChoice = 0;
    printf("=====================================================================\n");
    while (adminChoice != 9)
    {
        printf("\n0.Pre Available Space\n1.DeQueue\n2.Insert car in the parking lot\n3.Printing Booked Space After Adding Car in the Parking Lor\n4.Available Space After Adding Car in the Parking Lot\n5.Print All Linked List At one Place\n6.Searching a Car Using Car ID\n7.Free Up the Space\n7.Display After Deletion\n8.Display Final Linked List\n9.Exit From Administration Mode\n");
        printf("\n\t\tEnter your choice : ");
        scanf("%d", &adminChoice);
        printf("=====================================================================\n");
        switch (adminChoice)
        {
        case 0:
            preAvailSpace();
            break;
        case 1:
            struct carNode *tempQueue = carDequeue();
            printf("%d %d %c\n", tempQueue->CarID, tempQueue->NeedSpace, tempQueue->Location);
            lcarID = tempQueue->CarID;
            lneedSpace = tempQueue->NeedSpace;
            lLocation = tempQueue->Location;
            break;
        case 2:
            // some condition
            // have to do
            // east side start
            // EAST MAX
            if (lLocation == 'e' && lneedSpace == 200)
            {
                if (ems == EASTMAX)
                {
                    printf("You are breaking limit in our Allocated Space\n");
                    printf("Not find any space in this lot\n");
                    printf("Please Check Our Available List, and Try again\n");
                }
                else
                {
                    insertEnd(&eastMAX, lcarID, lneedSpace, lLocation);
                    printf("Location East ----- Size Maximum[200]\n");
                    printf("Booked Space :%d\nAvailable Space :%d\nTotal Space :%d\n", ems + 1, EASTMAX - (ems + 1), EASTMAX);
                    ems++;
                }
            }
            // EAST MID
            else if (lLocation == 'e' && lneedSpace == 150)
            {
                if (emis == EASTMID)
                {
                    printf("You are breaking limit in our Allocated Space\n");
                    printf("Not find any space in this lot\n");
                    printf("Please Check Our Available List, and Try again\n");
                }
                else
                {
                    insertEnd(&eastMID, lcarID, lneedSpace, lLocation);
                    printf("Location East ----- Size Midium[150]\n");
                    printf("Booked Space :%d\nAvailable Space :%d\nTotal Space :%d\n", emis + 1, EASTMID - (emis + 1), EASTMID);
                    emis++;
                }
            }
            // EAST MIN
            else if (lLocation == 'e' && lneedSpace == 100)
            {
                if (emin == EASTMIN)
                {
                    printf("You are breaking limit in our Allocated Space\n");
                    printf("Not find any space in this lot\n");
                    printf("Please Check Our Available List, and Try again\n");
                }
                else
                {
                    insertEnd(&eastMIN, lcarID, lneedSpace, lLocation);
                    printf("Location East ----- Size Minimum[100]\n");
                    printf("Booked Space :%d \nAvailable Space :%d\nTotal Space :%d\n", emin + 1, EASTMIN - (emin + 1), EASTMIN);
                    emin++;
                }
            }
            // east side end
            // west side start
            // WEST MAX
            else if (lLocation == 'w' && lneedSpace == 200)
            {
                if (wms == WESTMAX)
                {
                    printf("You are breaking limit in our Allocated Space\n");
                    printf("Not find any space in this lot\n");
                    printf("Please Check Our Available List, and Try again\n");
                }
                else
                {
                    insertEnd(&westMAX, lcarID, lneedSpace, lLocation);
                    printf("Location West ----- Size Maximum[200]\n");
                    printf("Booked Space :%d\nAvailable Space :%d\nTotal Space :%d\n", wms + 1, WESTMAX - (wms + 1), WESTMAX);
                    wms++;
                }
            }
            // WEST MID
            else if (lLocation == 'w' && lneedSpace == 150)
            {
                if (wmis == WESTMID)
                {
                    printf("You are breaking limit in our Allocated Space\n");
                    printf("Not find any space in this lot\n");
                    printf("Please Check Our Available List, and Try again\n");
                }
                else
                {
                    insertEnd(&westMID, lcarID, lneedSpace, lLocation);
                    printf("Location West ----- Size Midium[150]\n");
                    printf("Booked Space :%d\nAvailable Space :%d\nTotal Space :%d\n", wmis + 1, WESTMID - (wmis + 1), WESTMID);
                    wmis++;
                }
            }
            // WEST MIN
            else if (lLocation == 'w' && lneedSpace == 100)
            {
                if (wmin == WESTMIN)
                {
                    printf("You are breaking limit in our Allocated Space\n");
                    printf("Not find any space in this lot\n");
                    printf("Please Check Our Available List, and Try again\n");
                }
                else
                {
                    insertEnd(&westMIN, lcarID, lneedSpace, lLocation);
                    printf("Location West ----- Size Minimum[100]\n");
                    printf("Booked Space :%d \nAvailable Space :%d\nTotal Space :%d\n", wmin + 1, WESTMIN - (wmin + 1), WESTMIN);
                    wmin++;
                }
            }
            // west side end
            // north side start
            // NORTH MAX
            else if (lLocation == 'n' && lneedSpace == 200)
            {
                if (nms == NORTHMAX)
                {
                    printf("You are breaking limit in our Allocated Space\n");
                    printf("Not find any space in this lot\n");
                    printf("Please Check Our Available List, and Try again\n");
                }
                else
                {
                    insertEnd(&northMAX, lcarID, lneedSpace, lLocation);
                    printf("Location North ----- Size Maximum[200]\n");
                    printf("Booked Space :%d\nAvailable Space :%d\nTotal Space :%d\n", nms + 1, NORTHMAX - (nms + 1), NORTHMAX);
                    nms++;
                }
            }
            // NORTH MID
            else if (lLocation == 'n' && lneedSpace == 150)
            {
                if (nmis == NORTHMID)
                {
                    printf("You are breaking limit in our Allocated Space\n");
                    printf("Not find any space in this lot\n");
                    printf("Please Check Our Available List, and Try again\n");
                }
                else
                {
                    insertEnd(&northMID, lcarID, lneedSpace, lLocation);
                    printf("Location North ----- Size Midium[150]\n");
                    printf("Booked Space :%d\nAvailable Space :%d\nTotal Space :%d\n", nmis + 1, NORTHMID - (nmis + 1), NORTHMID);
                    nmis++;
                }
            }
            // NORTH MIN
            else if (lLocation == 'n' && lneedSpace == 100)
            {
                if (nmin == NORTHMIN)
                {
                    printf("You are breaking limit in our Allocated Space\n");
                    printf("Not find any space in this lot\n");
                    printf("Please Check Our Available List, and Try again\n");
                }
                else
                {
                    insertEnd(&northMIN, lcarID, lneedSpace, lLocation);
                    printf("Location North ----- Size Minimum[100]\n");
                    printf("Booked Space :%d \nAvailable Space :%d\nTotal Space :%d\n", nmin + 1, NORTHMIN - (nmin + 1), NORTHMIN);
                    nmin++;
                }
            }
            // north side end
            // south side start
            // SOUTH MAX
            else if (lLocation == 's' && lneedSpace == 200)
            {
                if (sms == SOUTHMAX)
                {
                    printf("You are breaking limit in our Allocated Space\n");
                    printf("Not find any space in this lot\n");
                    printf("Please Check Our Available List, and Try again\n");
                }
                else
                {
                    insertEnd(&southMAX, lcarID, lneedSpace, lLocation);
                    printf("Location South ----- Size Maximum[200]\n");
                    printf("Booked Space :%d\nAvailable Space :%d\nTotal Space :%d\n", sms + 1, SOUTHMAX - (sms + 1), SOUTHMAX);
                    sms++;
                }
            }
            // SOUTH MID
            else if (lLocation == 's' && lneedSpace == 150)
            {
                if (smis == SOUTHMID)
                {
                    printf("You are breaking limit in our Allocated Space\n");
                    printf("Not find any space in this lot\n");
                    printf("Please Check Our Available List, and Try again\n");
                }
                else
                {
                    insertEnd(&southMID, lcarID, lneedSpace, lLocation);
                    printf("Location South ----- Size Midium[150]\n");
                    printf("Booked Space :%d\nAvailable Space :%d\nTotal Space :%d\n", smis + 1, SOUTHMID - (smis + 1), SOUTHMID);
                    smis++;
                }
            }
            // SOUTH MIN
            else if (lLocation == 's' && lneedSpace == 100)
            {
                if (smin == SOUTHMIN)
                {
                    printf("You are breaking limit in our Allocated Space\n");
                    printf("Not find any space in this lot\n");
                    printf("Please Check Our Available List, and Try again\n");
                }
                else
                {
                    insertEnd(&southMIN, lcarID, lneedSpace, lLocation);
                    printf("Location South ----- Size Minimum[100]\n");
                    printf("Booked Space :%d \nAvailable Space :%d\nTotal Space :%d\n", smin + 1, SOUTHMIN - (smin + 1), SOUTHMIN);
                    smin++;
                }
            }
            else
            {
                printf("Your Input isn't fill our requirement\nPlease Try Again!\n");
            }
            // south side end
            // condition end
            break;

        case 3:
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
        case 4:
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
        case 5:
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
        case 6:
            printf("Searching Car using Car ID\n");
            printf("Enter Car ID:\n");
            scanf("%d", &key);
            struct parkingNode *foundNode = search(concatenatedList, key);
            if (foundNode != NULL)
            {
                printf("Car Found \n");
                printf("Car ID :%d\nRequired Space :%d\nLocation :%c\n", foundNode->carid, foundNode->needSPACE, foundNode->location);
            }
            else
            {
                printf("Car ID :%d isn't Found in our list\n", lcarID);
            }
            break;
        case 7:
            printf("Delete a Car That are found in case 5\n");
            if (foundNode != NULL)
            {
                deleteNode(&concatenatedList, key);
                printf("Car ID %d deleted from the list\n", key);
            }
            else
            {
                printf("Car ID %d isn't deleted from the list\n", key);
            }
            break;
        case 8:
            printf("Show Final Linked List\n");
            displayList(concatenatedList);
            break;
        case 9:
            ("=====================================================================\n");
            printf("Exited Successfully From the Administration Mode\n");
            ("=====================================================================\n");
            break;
        default:
            printf("Please enter valid choice..");
        }
    }
}

int main()
{
    // data that come from user
    int carID = 0;
    int needSpace;
    char location;

    int choice;
    printf("=====================================================================\n");
    printf("\t\t\tChoose The User Mode\n");
    printf("=====================================================================\n");
    while (choice != 40)
    {
        printf("\t\t1.USER\n\t\t2.ADMINISTRATOR\n\t\t3.EXIT");
        printf("\n\n\t\tEnter your choice : ");
        scanf("%d", &choice);
        printf("=====================================================================\n");
        switch (choice)
        {
            // user panel
        case 1:
            printf("\t\tYou are Using User Mode\n");
            printf("=====================================================================\n");
            userSwitch(carID, needSpace, location);
            printf("\t\t\tChoose The User Mode\n");
            printf("=====================================================================\n");
            break;
            // admin panel
        case 2:
            printf("\t\tYou are Using Administrator Mode\n");
            printf("=====================================================================\n");
            adminSwitch(carID, needSpace, location);
            printf("=====================================================================\n");
            printf("\t\t\tChoose The User Mode\n");
            printf("=====================================================================\n");
            break;
        case 3:
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\n\t\tWrong Choice\n");
        }
    }
    printf("=====================================================================\n");
    return 0;
}