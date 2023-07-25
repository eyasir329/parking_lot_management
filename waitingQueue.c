#include <stdio.h>
#include <stdlib.h>

//-----car structure started-----//
// Each car have
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
    printf("Inserted car in our waiting list successful\n");
}

// Dequeue() operation on a queue
int carDequeue()
{
    if (frontCar == NULL)
    {
        printf("\nUnderflow\n");
        return -1;
    }
    else
    {
        struct carNode *temp = frontCar;
        int temp_data = frontCar->CarID;
        frontCar = frontCar->nextCar;
        free(temp);
        return temp_data;
    }
}

// Display all elements of the queue
void display()
{
    struct carNode *temp;
    if ((frontCar == NULL) && (rearCar == NULL))
    {
        printf("\nCar Waiting list is Empty\n");
    }
    else
    {
        printf("Car Waiting list is \n");
        temp = frontCar;
        while (temp!=NULL)
        {
            printf("Car ID %d Need Space %d Location %c--->", temp->CarID,temp->NeedSpace,temp->Location);
            temp = temp->nextCar;
        }
        printf("NULL\n\n");
    }
}

int main()
{
    int carID=0;
    int needSpace=0;
    char location=0;

    int choice;
    printf("\nEnter car in our waiting list\n");
    while (choice != 4)
    {
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nCar Insert in our waiting list: \n");
            printf("Car ID: ");
            scanf("%d", &carID);
            printf("\nHow much space in your car need [100,150,200]: ");
            scanf("%d", &needSpace);
            printf("\nEnter location that you prefer [East-e,West-w,North-n,South-s]: ");
            scanf("%s", &location);
            carEnqueue(carID, needSpace, location);
            break;
        case 2:
            printf("Popped element is :%d\n", carDequeue());
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nWrong Choice\n");
        }
    }
    return 0;
}
