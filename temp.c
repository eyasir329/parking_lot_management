#include <stdio.h>
#include <stdlib.h>

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

// user switch case
void userSwitch(int carID, int needSpace, char location)
{
    int userChoice, pay;
    while (userChoice != 5)
    {
        printf("\n\t\t1.Have to Book a Space\n\t\t2.Receive Your PreBooked Slip\n\t\t3.Payment Confirmation\n\t\t4.Confirmation Slip\n\t\t5.Exit from User Mode\n");
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
            fPay=fopen("payment.csv","a");
            if(fPay==NULL){
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
                    fprintf(fPay, "%d,%d\n",carID,pay);
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
                    fprintf(fPay, "%d,%d\n",carID,pay);
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
                    fprintf(fPay, "%d,%d\n",carID,pay);
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
                        if(pay==100){
                            fprintf(paySlip, "\t\tPayment Done 100TK\n");
                        }else{
                            fprintf(paySlip, "\t\tPayment Not Done 100TK\n");
                        }
                    }
                    else if (needSpace == 150)
                    {
                        if(pay==200){
                            fprintf(paySlip, "\t\tPayment Done 200TK\n");
                        }else{
                            fprintf(paySlip, "\t\tPayment Not Done 200TK\n");
                        }
                    }
                    else
                    {
                        if(pay==300){
                            fprintf(paySlip, "\t\tPayment Done 300TK\n");
                        }else{
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

//admin switch case
void adminSwitch(int carID,int needSpace,char location){
    
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
    while (choice != 2)
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
            adminSwitch(carID,needSpace,location);
            printf("\t\t\tChoose The Administration Mode\n");
            printf("=====================================================================\n");
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("\n\t\tWrong Choice\n");
        }
    }
    printf("=====================================================================\n");
    return 0;
}