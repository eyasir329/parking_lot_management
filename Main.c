#include<stdio.h>
#include<stdlib.h>

#define TOTALPLOT 5
#define MAXSPACE 200       //east 4 west 2 north 3 south 2
#define MIDIUMSPACE 150    //east 1 west 3 north 2 south 1
#define MINSPACE 100       //east 3 west 1 north 1 south 3

//numofspace in each direction
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

//parkingLotInitialize
//findAvailableSpace
//vehiclePark
//freeParkingSpace
//plotNo
//location
//avail
//parkinginfop
//linkedlist
//queue

//ParkingLotInfo
struct Parking{
    int plotNo;
    int id;
    int AvailSpaceN;
    int SpaceOccupied;
    char location;
    struct parkingLot* next;
} parkingLot;
typedef struct Parking park;


//CarInfo
// typedef struct {
//     int id;
//     int needSpace;
//     char needLocation;
// } Vehicle;

//Function to initialize Parking Plot
void initializeParkingLot(park* ParkSpace, int carID,int cSpace,int cPlot,char cLocation){
    if(cSpace==200){
        if (cLocation =='e')
        {
            for (int i = 0; i < 1; i++)
            {
                ParkSpace = (park *)malloc(sizeof(parkingLot));
                ParkSpace[i].id = carID;
                ParkSpace[i].plotNo = cPlot;
                ParkSpace[i].location = cLocation;
                ParkSpace[i].SpaceOccupied=0;
                ParkSpace[i].AvailSpaceN=i+1;
                ParkSpace->next=NULL;
            }
        }
    }
    
}
//Function to find Available Space
// int findAvailableParkingLot(parkingLot* ParkingSpace,int Space,int plotNo,char location){
//     if(location=="east" && Space==200){
//         for(int i=0;i<EASTMAX;i++){
            
//         }
//     }
// }

int main(){
    printf("Enter car id : ");
    int Carid;
    scanf("%d",Carid);
    printf("\nEnter car space [100,150,200] : ");
    int CarSpace;
    scanf("%d",CarSpace);
    
    int CarPlotNo = 1;
    char Carloc = 'e';
    struct Parking temp[0];
   
    initializeParkingLot(temp,Carid,CarSpace,CarPlotNo,Carloc);
    printf("%d %d %s",temp[0].id,temp[0].plotNo,temp[0].location);
    printf("Hello");
    return 0;
}