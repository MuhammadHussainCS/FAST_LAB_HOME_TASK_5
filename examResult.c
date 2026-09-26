#include<stdio.h>

#define ATTENDANCE_FOR_DISTINCTION 90
#define THEORY_MARKS_FOR_DISTINCTION 85
#define PRACTICAL_MARKS_FOR_DISTINCTION 80


#define THEORY_PASS_FOR_CS 50
#define PRACTICAL_PASS_FOR_CS 40
#define ATTENDANCE_REQUIRED_FOR_CS  75

#define THEORY_PASS_FOR_EE 55
#define PRACTICAL_PASS_FOR_EE 45
#define ATTENDANCE_REQUIRED_FOR_EE  75

#define THEORY_PASS_FOR_BA 50
#define PRACTICAL_PASS_FOR_BA 35
#define ATTENDANCE_REQUIRED_FOR_BA 80

#define THEORY_PASS_FOR_MATHS 60
#define PRACTICAL_PASS_FOR_MATHS 40
#define ATTENDANCE_REQUIRED_FOR_MATHS 75
int main(){
    printf("*****************************************************");
    printf("\nUNIVERSITY EXAMINATION RESYLT PROCESSING SYSTEM\n");      
    printf("*****************************************************\n");

    int dept_choice;
    label1:
    printf("Select department \n");
    printf("\n1. COMPUTER SCIENCE");
    printf("\n2. ELECTRICAL ENGINEERING");
    printf("\n3. BUSINESS ADMINISTRATION");
    printf("\n4. MATHEMATICS");
    printf("\nChoice : ");
    scanf("%d", &dept_choice);
    
    if(dept_choice<1 || dept_choice>4) {
        printf("\nINVALID CHOICE[!]");
        goto label1;
    }

    float atten_percet;

    label2:
    printf("\nEnter Attendace Percantage : ");
    scanf("%f", &atten_percet);

    if(atten_percet<0 || atten_percet>100) {
        printf("\nINVALID INPUT[!]");
        goto label2;
    }

    float theory_marks, practical_marks;

    label3:
    printf("\nEnter THEORY marks : ");
    scanf("%f", &theory_marks);
    if(theory_marks<0 || theory_marks>100) {
        printf("\nINVALID INPUT[!]");
        goto label3;
    }

    label4:
    printf("\nEnter PRACTICAL marks : ");
    scanf("%f", &practical_marks);
    if(practical_marks<0 || practical_marks>100) {
        printf("\nINVALID INPUT[!]");
        goto label4;
    }

    printf("*******************************************************\n");
    printf("\t\tRESULT SUMMARY\n");  
    printf("*******************************************************\n");
    switch (dept_choice)
    {
    case 1://cs
        printf("\nCOMPUETR SCIENCE");
        switch (theory_marks>=THEORY_MARKS_FOR_DISTINCTION && practical_marks>= PRACTICAL_MARKS_FOR_DISTINCTION && atten_percet>=ATTENDANCE_FOR_DISTINCTION) 
        {
        case 1://distinction
            printf("\nYOU HAVE GOT DISTINCTION!");
            printf("\nTHEORY MARKS = %.2f", theory_marks);
            printf("\nPRACTTICAL MARKS = %.2f", practical_marks);
            printf("\nATTENDANCE PERCENTAGE = %.2f", atten_percet);                
            printf("\nFINAL EXAMINATION RESULT = PASS");
            break;
        case 0://no distinction
            printf("\nYOU DO NOT HAVE GOT DISTINCTION!");
            printf("\nTHEORY MARKS = %.2f", theory_marks);
            printf("\nPRACTTICAL MARKS = %.2f", practical_marks);
            printf("\nATTENDANCE PERCENTAGE = %.2f", atten_percet);
            switch (theory_marks>=THEORY_PASS_FOR_CS && practical_marks>=PRACTICAL_PASS_FOR_CS && atten_percet>=ATTENDANCE_REQUIRED_FOR_CS)
            {
            case 1://pass 
                printf("\nFINAL EXAMINATION RESULT = PASS");
                break;
            case 0: // no pass
                printf("\nFINAL EXAMINATION RESULT = FAIL");
                break;
            // default:
            //     break;
            }
        // default:
        //     break;
        }
        break;
    case 2://ee
        printf("\nELECTRICAL ENGINEERING");
        switch (theory_marks>=THEORY_MARKS_FOR_DISTINCTION && practical_marks>= PRACTICAL_MARKS_FOR_DISTINCTION && atten_percet>=ATTENDANCE_FOR_DISTINCTION)
        {
        case 1://distinction
            printf("\nYOU HAVE GOT DISTINCTION!");
            printf("\nTHEORY MARKS = %.2f", theory_marks);
            printf("\nPRACTTICAL MARKS = %.2f", practical_marks);
            printf("\nATTENDANCE PERCENTAGE = %.2f", atten_percet);                
            printf("\nFINAL EXAMINATION RESULT = PASS");
            break;
        case 0://no distinction
            printf("\nYOU DO NOT HAVE GOT DISTINCTION!");
            printf("\nTHEORY MARKS = %.2f", theory_marks);
            printf("\nPRACTTICAL MARKS = %.2f", practical_marks);
            printf("\nATTENDANCE PERCENTAGE = %.2f", atten_percet);
            switch (theory_marks>=THEORY_PASS_FOR_EE && practical_marks>=PRACTICAL_PASS_FOR_EE && atten_percet>=ATTENDANCE_REQUIRED_FOR_EE)
            {
            case 1://pass
                               
                printf("\nFINAL EXAMINATION RESULT = PASS");
                break;
            case 0://no pass  
                               
                printf("\nFINAL EXAMINATION RESULT = FAIL");
            // default:
            //     break;
            }
            break;
        // default:
        //     break;
        }
        break;
    case 3://ba
        printf("\nBUSINESS ADMINISTRATION");
        switch (theory_marks>=THEORY_MARKS_FOR_DISTINCTION && practical_marks>= PRACTICAL_MARKS_FOR_DISTINCTION && atten_percet>=ATTENDANCE_FOR_DISTINCTION)
        {
        case 1://distinction
            printf("\nYOU HAVE GOT DISTINCTION!");
            printf("\nTHEORY MARKS = %.2f", theory_marks);
            printf("\nPRACTTICAL MARKS = %.2f", practical_marks);
            printf("\nATTENDANCE PERCENTAGE = %.2f", atten_percet);                
            printf("\nFINAL EXAMINATION RESULT = PASS");
            break;
        case 0://no distinction
            printf("\nYOU DO NOT HAVE GOT DISTINCTION!");
            printf("\nTHEORY MARKS = %.2f", theory_marks);
            printf("\nPRACTTICAL MARKS = %.2f", practical_marks);
            printf("\nATTENDANCE PERCENTAGE = %.2f", atten_percet);                

            switch (theory_marks>=THEORY_PASS_FOR_BA && practical_marks>= PRACTICAL_PASS_FOR_BA && atten_percet>=ATTENDANCE_REQUIRED_FOR_BA)
            {
            case 1://pass 
                printf("\nFINAL EXAMINATION RESULT = PASS");
                break;
            case 0://no pass
                printf("\nFINAL EXAMINATION RESULT = FAIL");
                break;
            // default:
            //     break;
            }
            break;
        // default:
        //     break;
        }
        break;
    case 4://maths
        printf("\nMATHS");
        switch (theory_marks>=THEORY_MARKS_FOR_DISTINCTION && practical_marks>= PRACTICAL_MARKS_FOR_DISTINCTION && atten_percet>=ATTENDANCE_FOR_DISTINCTION)
        {
        case 1://distinction 
            printf("\nYOU HAVE GOT DISTINCTION!");
            printf("\nTHEORY MARKS = %.2f", theory_marks);
            printf("\nPRACTTICAL MARKS = %.2f", practical_marks);
            printf("\nATTENDANCE PERCENTAGE = %.2f", atten_percet);                
            printf("\nFINAL EXAMINATION RESULT = PASS");
            break;
        case 0://no distinction
            printf("\nYOU DO NOT HAVE GOT DISTINCTION!");
            printf("\nTHEORY MARKS = %.2f", theory_marks);
            printf("\nPRACTTICAL MARKS = %.2f", practical_marks);
            printf("\nATTENDANCE PERCENTAGE = %.2f", atten_percet);                

            switch (theory_marks>=THEORY_PASS_FOR_MATHS && practical_marks>=PRACTICAL_PASS_FOR_MATHS && atten_percet>=ATTENDANCE_REQUIRED_FOR_MATHS)
            {
            case 1://pass 
                printf("\nFINAL EXAMINATION RESULT = PASS");
                break;
            case 0://no pass
                printf("\nFINAL EXAMINATION RESULT = FAIL");
                break;
            // default:
            //     break;
            }
        // default:
        //     break;
        }
        break;
    
    default:
        printf("\nINVALID INPUT[!]\n");
        break;
    }

    char seat_category;
    if((int)theory_marks % 3 == 0) {
        seat_category = 'A';
        printf("\nSEAT CATEGORY = %c", seat_category);
    } else if((int)theory_marks % 3 == 1) {
        seat_category = 'B';
        printf("\nSEAT CATEGORY = %c", seat_category);
    } else {
        seat_category = 'C';
        printf("\nSEAT CATEGORY = %c", seat_category);
    }

    switch (dept_choice)
    {
    case 1:
        printf("\nPASSING MARKS FOR THEORY FOR CS DEPARTMENT = %i", THEORY_PASS_FOR_CS);
        printf("\nPASSING MARKS FOR PRACTICAL FOR CS DEPARTMENT = %i", PRACTICAL_PASS_FOR_CS);
        printf("\nATTENDANCE REQUIRED FOR CS DEPARTMENT = %i", ATTENDANCE_REQUIRED_FOR_CS);
        break;
    case 2:
        printf("\nPASSING MARKS FOR THEORY FOR EE DEPARTMENT = %i", THEORY_PASS_FOR_EE);
        printf("\nPASSING MARKS FOR PRACTICAL FOR EE DEPARTMENT = %i", PRACTICAL_PASS_FOR_EE);
        printf("\nATTENDANCE REQUIRED FOR EE DEPARTMENT = %i", ATTENDANCE_REQUIRED_FOR_EE);
        break;
    case 3:
        printf("\nPASSING MARKS FOR THEORY FOR BA DEPARTMENT = %i", THEORY_PASS_FOR_BA);
        printf("\nPASSING MARKS FOR PRACTICAL FOR BA DEPARTMENT = %i", PRACTICAL_PASS_FOR_BA);
        printf("\nATTENDANCE REQUIRED FOR BA DEPARTMENT = %i", ATTENDANCE_REQUIRED_FOR_BA);
        break;
    case 4:
        printf("\nPASSING MARKS FOR THEORY FOR MATHS DEPARTMENT = %i", THEORY_PASS_FOR_MATHS);
        printf("\nPASSING MARKS FOR PRACTICAL FOR MATHS DEPARTMENT = %i", PRACTICAL_PASS_FOR_MATHS);
        printf("\nATTENDANCE REQUIRED FOR MATHS DEPARTMENT = %i", ATTENDANCE_REQUIRED_FOR_MATHS);
        break;
    default:
        printf("\nINVALID CHOICE");
        break;
    }

    int display_distinction_marks;

    label:
    printf("\nWant to know marks required for distinction ? (1=Y)/(2=N) : ");
    scanf("%d", &display_distinction_marks);
    
    if(display_distinction_marks<1 || display_distinction_marks>2) {
        printf("\nINVALID INPUT[!]\n");
        goto label;
    }

    display_distinction_marks == 1 ? (printf("\nTHEORY MARKS FOR DISTINCTION = %d", THEORY_MARKS_FOR_DISTINCTION),
                                     printf("\nPRACTICAL MARKS FOR DISTINCTION = %d", PRACTICAL_MARKS_FOR_DISTINCTION),
                                     printf("\nATTENDANCE REQUIRED FOR DISTINCTION = %d", ATTENDANCE_FOR_DISTINCTION))
                                    : printf("\nOKAY NOT DISPLAYING DISTINCTION BREAKDOWN SINCE YOU DO NOT WANT IT."); 
    return 0;
}