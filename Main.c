#include<stdio.h>
// #include<stdlib.h>

// #define TOTALPLOT 5
// #define MAXSPACE 200       //east 4 west 2 north 3 south 2
// #define MIDIUMSPACE 150    //east 1 west 3 north 2 south 1
// #define MINSPACE 100       //east 3 west 1 north 1 south 3

// //numofspace in each direction
// #define EASTMAX 4
// #define EASTMID 1
// #define EASTMIN 3

// #define WESTMAX 2
// #define WESTMID 3
// #define WESTMIN 1 

// #define NORTHMAX 3
// #define NORTHMID 2
// #define NORTHMIN 1 

// #define SOUTHMAX 2
// #define SOUTHMID 1
// #define SOUTHMIN 3        

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
// typedef struct ParkSpace{
//     int plotNo;
//     int id;
//     int AvailSpaceN;
//     int SpaceOccupied;
//     char location;
//     struct parkingLot* next;
// } parkingLot;

//CarInfo
// typedef struct {
//     int id;
//     int needSpace;
//     char needLocation;
// } Vehicle;

//Function to initialize Parking Plot
// void initializeParkingLot(parkingLot* ParkSpace, int carID,int cSpace,int cPlot,char cLocation,int nc){
//     if(cSpace==200){
//         if (cLocation == "east")
//         {
//             for (int i = 0; i < EASTMAX; i++)
//             {
//                 ParkSpace = (parkingLot *)malloc(sizeof(parkingLot));
//                 ParkSpace[i].id = carID;
//                 ParkSpace[i].plotNo = cPlot;
//                 ParkSpace[i].location = cLocation;
//                 ParkSpace[i].SpaceOccupied=0;
//                 ParkSpace[i].AvailSpaceN=i+1;
//                 ParkSpace->next=NULL;
//             }
//         }
//     }
    
// }
//Function to find Available Space
// int findAvailableParkingLot(parkingLot* ParkingSpace,int Space,int plotNo,char location){
//     if(location=="east" && Space==200){
//         for(int i=0;i<EASTMAX;i++){
            
//         }
//     }
// }

int main(){
    int numberOfCustomer=3;
    int Carid = 344;
    int CarSpace = 150;
    int CarPlotNo = 1;
    char Carloc = "east";
    
    //initializeParkingLot(parkingLot,Carid,CarSpace,CarPlotNo,Carloc,numberOfCustomer);
    //printf("%d %d %s",ParkSpace[0].id,ParkSpace[0].plotNo,ParkSpace[0].location);
    printf("Hello");
    return 0;
}