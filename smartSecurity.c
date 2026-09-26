#include<stdio.h>
int main(){
    printf("================================================");
    printf("\nSMART HOME SECURITY CONTROLLER\n");
    printf("================================================");

    int door = 1;
    int alarm = 2;
    int camera = 4;
    int sensor = 8;
    int status = 0;
    int operation;

    label1:
    printf("\nSELECT AN OPERATION\n");
    printf("\n1. ACTIVATE A DEVICE");
    printf("\n2. DEACTIVATE A DEVICE");
    printf("\n3. CHECK THE STATUS OF DEVICE");
    printf("\n4. Toggle a device\n");
    printf("\nChoice : ");
    scanf("%d", &operation);

    if(operation<1 || operation>4) {
        printf("\nInvald Input[!]\n");
        goto label1;
    }

    int device_option;
    
    label2:
    printf("\nSELECT THE DEVICE\n");
    printf("\n1. MAIN DOOR LOCK");
    printf("\n2. ALARM SYSTEM");
    printf("\n3. CCTV CAMERA");
    printf("\n4. MOTION SENSOR");
    printf("\nCHOICE : ");
    scanf("%d", &device_option);

    if(device_option<1 || device_option>4) {
        printf("\nInvalid input[!].");
        goto label2;
    }

    switch (operation)
    {
    case 1://activate a device
        switch (device_option)
        {
        case 1://activate a device(door)
            status = status | door;
            printf("\nMain door lock Security is on successfully\n");
            printf("\nStatus Value = %d", status);
            break;
        case 2://activate a device(alarm)
            status = status | alarm;
            printf("\nAlarm Security is on successfully\n");
            printf("\nStatus Value = %d", status);
            break;
        case 3://activate a device(camera)
            status = status | camera;
            printf("\nCamera Security is on successfully\n");
            printf("\nStatus Value = %d", status);
            break;
        case 4://activate a device(sensor)
            status = status | sensor;
            printf("\nMotion Security is on successfully\n");
            printf("\nStatus Value = %d", status);
            break;
        default:
            printf("\nINVALID CHOICE[!]\n");
            break;
        }
        break;
    case 2://deactivate a device
        switch (device_option)
        {
        case 1:
            if(status == 1) {
                status = status & ~(door);
                printf("\nDoor lock system is successfuly deactivated\n");
                printf("\nStatus Value = %d", status);
            break;
            } else {
                printf("\nDoor Lock is already deactivated");
                printf("\nStatus Value = %d", status);
            }
        break;
        case 2:
            if(status == 2) {
                status = status & ~(alarm);
                printf("\nAlarm security is successfuly deactivated\n");
                printf("\nStatus Value = %d", status);
            } else {
                printf("\nAlarm Security is already deactivated");
                printf("\nStatus Value = %d", status);
            }
            break;
        case 3:
            if(status == 4) {
                status = status & ~(camera);
                printf("\nCCTV Camera security is successfuly deactivated\n");
                printf("\nStatus Value = %d", status);
            } else {
                printf("\nCCTV Camear is already deactivated\n");
                printf("\nStatus Value = %d", status);
            }
            break;
        
        case 4:
            if(status == 8) {
                status = status & ~(sensor);
                printf("\nis successfuly deactivated\n");
                printf("\nStatus Value = %d", status);
            } else {
                printf("\nMotion sensir is already deactivated\n");
                printf("\nStatus Value = %d", status);
            }
            break;
        default:
            printf("\nINVALID INPUT[!]");
            break;
        }
        break;
    case 3://Status a device
        switch (device_option) {
            case 1: printf("\nMain Door Lock is %s\n", (status & door) ? "ACTIVE" : "INACTIVE"); break;
            case 2: printf("\nAlarm System is %s\n", (status & alarm) ? "ACTIVE" : "INACTIVE"); break;
            case 3: printf("\nCCTV Camera is %s\n", (status & camera) ? "ACTIVE" : "INACTIVE"); break;
            case 4: printf("\nMotion Sensor is %s\n", (status & sensor) ? "ACTIVE" : "INACTIVE"); break;
        }
        break;
    case 4://toggle a device
        switch (device_option)
        {
        case 1:
            printf("\nBefore toggling DOOR security = %d", status);
            status = status ^ door;
            printf("\nAfter toggling DOOR security = %d", status);
            break;
        case 2:
            printf("\nBefore toggling ALARM security = %d", status);
            status = status ^ alarm;
            printf("\nAfter toggling ALARM security = %d", status);
            break;
        case 3:
            printf("\nBefore toggling CCTV Camera security = %d", status);
            status = status ^ camera;
            printf("\nAfter toggling CCTV Camera security = %d", status);
            break;
        case 4:
            printf("\nBefore toggling Motion security = %d", status);
            status = status ^ sensor;
            printf("\nAfter toggling Motion security = %d", status);
            break;
        default:
            printf("\nINVALID CHOICE[!]");
            break;
        }
        
        break;
    default:
        printf("\nINVALID CHOICE[!]");
        break;
    }

    int security_mode;
    label6:
    printf("\nENTER SECURITY MODE");
    printf("\n1. HOME MODE");
    printf("\n2. AWAY MODE");
    printf("\n3. NIGHT MODE\n");
    scanf("%d", &security_mode);

    if(security_mode<1 || security_mode>3) {
        printf("\nINVALID INPUT[!]");
        goto label6;
    }
    
    switch (security_mode)
    {
    case 1:
        status = status | door;
        status = status | camera;
        printf("\nDOOR AND CAMERA SECURITY IMPLEMENTED DUE TO HOME MODE\n");
        printf("\nStatus Value = %d", status);
        break;
    case 2:
        status = status | door;
        status = status | camera;
        status = status | alarm;
        status = status | sensor;
        printf("\nDOOR, CAMERA, ALARM, MOTION SENSOR SECURITY IMPLEMENTED DUE TO AWAY MODE\n");
        printf("\nStatus Value = %d", status);
        break;
    case 3:
        status = status | door;
        status = status | alarm;
        status = status | sensor;
        printf("\nDOOR, CAMERA, AND MOTION SENSOR SECURITY IMPLEMENTED DUE TO NIGHT MODE\n");
        printf("\nStatus Value = %d", status);
        break;
    default:
    printf("\nINVALID CHOICE[!]");
        break;
    }

    if((status & door) && (status & alarm) && (status & camera) && (status & sensor)) {
        printf("\nFULLY ARMED");
        printf("\nStatus Value = %d", status);
    } else {
        printf("\nNOT FULLY ARMED");
    }

    return 0;
}