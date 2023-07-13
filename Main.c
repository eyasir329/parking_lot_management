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
typedef struct {
    int plotNo;
    int AvailSpaceN;
    char location;
    struct parkingLot* next;
} parkingLot;

//CarInfo
typedef struct {
    int id;
    int needSpace;
    char needLocation;
} Vehicle;

//Function to initialize Parking Plot
void initializeParkingLot(int Space,int plotNo,char location){
    if(location=="east" && Space==200){
        for(int i=0;i<EASTMAX;i++){
            parkingLot* parkingCar = (parkingLot*)malloc(sizeof(parkingLot));
            parkingCar[i].AvailSpaceN = EASTMAX-i;
            return parkingCar[i].AvailSpaceN;
        }
    }
}
//Function to find Available Space

int main(){
    int Space = 150;
    int plotNo = 1;
    char location = "east";
    initializeParkingLot(Space,plotNo,location);
    return 0;
}