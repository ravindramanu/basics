#include <stdio.h>

#define HEAD 0x59

typedef struct framestructure {
    unsigned char headb1;
    unsigned char headb2;
    unsigned char distlo;
    unsigned char disthi;
    unsigned char strghi;
    unsigned char strglo;
    unsigned char mode;
    unsigned char spare;
    unsigned char checksum;
} Frame;

Frame lidarframe;
unsigned char buffer[27] = {0x59, 0x59, 0x01, 0x90, 0x01, 0x90, 0x02, 0x00, 0xD6,
                            0x59, 0x59, 0x01, 0x20, 0x01, 0x90, 0x02, 0x00, 0xD6,
                            0x59, 0x52, 0x01, 0x20, 0x01, 0x90, 0x02, 0x00, 0xD6
};
unsigned char position=0;

unsigned int distance=0;

void parsedistance(){
    
    int sum = (lidarframe.headb1 +
               lidarframe.headb2 +
               lidarframe.disthi +
               lidarframe.distlo +
               lidarframe.strghi +
               lidarframe.strglo +
               lidarframe.mode   +
               lidarframe.spare);
    
    printf("\n SUM is %02x ", sum);
    
            
    if(lidarframe.checksum == (sum&0xFF)) {
        distance = (lidarframe.disthi<<8) + (lidarframe.distlo);
        printf("\n");
    }
    else {
        printf("Check fail\n");
    }
    
}

void readlidar(unsigned char byte){
    switch(position){
        case 0: {
            if(byte == HEAD){
                
                lidarframe.headb1=byte;
                position+=1;
                
            }
            else {
                position=0;
            }
            break;
        }
        
        case 1: {
            if(byte == HEAD){
                lidarframe.headb2=byte;
                position+=1;
            }
            else {
                position=0;
                printf("\n frame drop \n");
            }
            break;
        }
        
        case 2: {
            //printf("%02x\n", byte);
            lidarframe.disthi=byte;
            position+=1;
            break;
        }
        
        case 3: {
            lidarframe.distlo=byte;
            position+=1;
            break;
        }
        
        case 4: {
            lidarframe.strghi=byte;
            position+=1;
            break;
        }
        
        case 5: {
            lidarframe.strglo=byte;
            position+=1;
            break;
        }
        
        case 6: {
            lidarframe.mode=byte;
            position+=1;
            break;
        }
        
        case 7: {
            lidarframe.spare=byte;
            position+=1;
            break;
        }
        
        case 8: {
            lidarframe.checksum=byte;
            parsedistance();
            position=0;
            break;
        }
    }
}

int main()
{
    int i=0;
    while(i<27){
        readlidar(buffer[i]);
        //printf("%d\n", position);
        i++;
        printf("DISTANCE: %d ", distance);
    }
    

    return 0;
}
