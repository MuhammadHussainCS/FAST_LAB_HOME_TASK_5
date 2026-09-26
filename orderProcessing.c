#include<stdio.h>
#define SHIPPING_PER_KM 20
#define CHARGE_FOR_PRIORITY 500
#define PRODUCT_CATEGORY_1 "ELECTRONICS"
#define PRODUCT_CATEGORY_2 "CLOTHING"
#define PRODUCT_CATEGORY_3 "BOOKS"
#define PRODUCT_CATEGORY_4 "HOUSEHOLD"
#define CUSTOMER_CATEGORY_1 "REGULAR"
#define CUSTOMER_CATEGORY_2 "PREMIUM"
#define CUSTOMER_CATEGORY_3 "CORPORATE"
int main(){
    printf("*******************************************************\n");
    printf("\tE-COMMERCE ORDER PROCESSING SYSTEM");
    printf("\n*******************************************************");
    int product_category; 

    label1:
    printf("\nENTER PRODUCT CATEGORY");
    printf("\n1. ELECTRONICS");
    printf("\n2. CLOTHING");
    printf("\n3. BOOKS");
    printf("\n4. HOUSEHOLD");
    printf("\nCHOICE : ");
    scanf("%d", &product_category); 

    if(product_category<1 || product_category>4) {
        printf("\nINVALID INPUT[!]");
        goto label1;
    }

    int customer_category;
    float order_amount;
    float delivery_distance;
    float discount_percentage = 0;
    float discount_amount = 0;
    float payable_amount = 0;
    float shipping_fee = 0;
    float priority_charges = 0;
    float total_payable_amount = 0;

    label2:
    printf("\nENTER CUSTOMER CATEGORY");
    printf("\n1. REGULAR");
    printf("\n2. PREMIUM");
    printf("\n3. CORPORATE");
    printf("\nCHOICE : ");
    scanf("%d", &customer_category);
    
    if(customer_category<1 || customer_category>3) {
        printf("\nINVALID INPUT[!]");
        goto label2;
    }

    int order_number;
    label5:
    printf("\nENTER ORDER NUMBER : ");
    scanf("%d", &order_number);
    if(order_number<=0) {
        printf("\nINVALID ORDER NUMBER[!]");
        goto label5;
    } 

    char *group;
    if(order_number % 4 == 0) {
        group = "GROUP A";
    } else if(order_number % 4 == 1) {
        group = "GROUP B";
    } else if(order_number % 4 == 2) {
        group = "GROUP C";
    } else {
        group = "GROUP D";
    }

    label3:
    printf("\nENTER ORDER AMOUNT : ");
    scanf("%f", &order_amount);

    if(order_amount<=0) {
        printf("\nINVALID INPUT");
        goto label3;
    }

    label4:
    printf("\nENTER DELIEVRY DISTANCE : ");
    scanf("%f", &delivery_distance);

    if(delivery_distance<=0) {
        printf("\nINVALID INPUT[!]");
        goto label4;
    }

    printf("\n******************************************************\n");
    printf("\tORDER SUMMARY");
    printf("\n******************************************************\n");
    switch (product_category)
    {
    case 1://electronics
        printf("\nPRODUCT CATEGORY = %s", PRODUCT_CATEGORY_1);
        switch (customer_category)
        {
        case 1://regular
            discount_percentage = 0.05;
            discount_amount = discount_percentage * order_amount;
            payable_amount = order_amount - discount_amount;
            if(payable_amount >= 5000) {
                shipping_fee = 0;
                printf("\nFREE SHIPPING");
            } else {
                shipping_fee = SHIPPING_PER_KM * delivery_distance;
            }
            total_payable_amount = shipping_fee + priority_charges + payable_amount;
            printf("\nCUSTOMER CATEGORY = %s", CUSTOMER_CATEGORY_1);
            printf("\nORDER AMOUNT = %.2f", order_amount);
            printf("\nDISCOUNT PERCENTAGE = %.2f", discount_percentage * 100);
            printf("\nDISCOUNT AMOUNT = %.2f", discount_amount);
            printf("\nFINAL PAYABLE AMOUNT = %.2f", payable_amount);
            printf("\nDELIVERY DISTANCE = %.2fKM",delivery_distance);
            printf("\nPRIORITY CHARGES = %.2f",priority_charges);
            printf("\nSHIPPING FEE = %.2f", shipping_fee);
            printf("\nTOTAL PAYABLE AMOUNT AFTER EVERY CALCULATION = %.2f", total_payable_amount);
            printf("\nGROUP = %s",group);
            break;
        case 2://premium
            discount_percentage = 0.10;
            discount_amount = discount_percentage * order_amount;
            payable_amount = order_amount - discount_amount;
            shipping_fee = 0;
            printf("\nFREE SHIPPING");
            if(order_amount>=10000) {
                priority_charges += CHARGE_FOR_PRIORITY;
                printf("\nPRIORITY DELIEVRY.RS 500 IS APPLIED AS ADDITIONAL CHARGE\n");
            }
            total_payable_amount = shipping_fee + priority_charges + payable_amount;
            printf("\nCUSTOMER CATEGORY = %s", CUSTOMER_CATEGORY_2);
            printf("\nORDER AMOUNT = %.2f", order_amount);
            printf("\nDISCOUNT PERCENTAGE = %.2f", discount_percentage * 100);
            printf("\nDISCOUNT AMOUNT = %.2f", discount_amount);
            printf("\nFINAL PAYABLE AMOUNT = %.2f", payable_amount);
            printf("\nDELIVERY DISTANCE = %.2fKM",delivery_distance);
            printf("\nPRIORITY CHARGES = %.2f",priority_charges);
            printf("\nSHIPPING FEE = %.2f", shipping_fee);
            printf("\nGROUP = %s",group);
            printf("\nTOTAL PAYABLE AMOUNT AFTER EVERY CALCULATION = %.2f", total_payable_amount);
            break;
        case 3://corporate
            discount_percentage = 0.15;
            discount_amount = discount_percentage * order_amount;
            payable_amount = order_amount - discount_amount;
            printf("\nFREE SHIPPING");
            if(order_amount>=10000) {
                priority_charges += CHARGE_FOR_PRIORITY;
                printf("\nPRIORITY DELIEVRY.RS 500 IS APPLIED AS ADDITIONAL CHARGE\n");
            }
            total_payable_amount = shipping_fee + priority_charges + payable_amount;
            printf("\nCUSTOMER CATEGORY = %s", CUSTOMER_CATEGORY_3);
            printf("\nORDER AMOUNT = %.2f", order_amount);
            printf("\nDISCOUNT PERCENTAGE = %.2f", discount_percentage * 100);
            printf("\nDISCOUNT AMOUNT = %.2f", discount_amount);
            printf("\nFINAL PAYABLE AMOUNT = %.2f", payable_amount);
            printf("\nDELIVERY DISTANCE = %.2fKM",delivery_distance);
            printf("\nPRIORITY CHARGES = %.2f",priority_charges);
            printf("\nSHIPPING FEE = %.2f", shipping_fee);
            printf("\nGROUP = %s",group);
            printf("\nTOTAL PAYABLE AMOUNT AFTER EVERY CALCULATION = %.2f", total_payable_amount);
            break;
        // default:
        //     break;
        }
        break;
    case 2://Clothing
        printf("\nPRODUCT CATEGORY = %s", PRODUCT_CATEGORY_2);
        switch (customer_category)
        {
        case 1://regular
            discount_percentage = 0.10;
            discount_amount = discount_percentage * order_amount;
            payable_amount = order_amount - discount_amount;
            if(payable_amount >= 5000) {
                shipping_fee = 0;
                printf("\nFREE SHIPPING");
            } else {
                shipping_fee = SHIPPING_PER_KM * delivery_distance;
            }
            total_payable_amount = shipping_fee + priority_charges + payable_amount;
            printf("\nCUSTOMER CATEGORY = %s", CUSTOMER_CATEGORY_1);
            printf("\nORDER AMOUNT = %.2f", order_amount);
            printf("\nDISCOUNT PERCENTAGE = %.2f", discount_percentage * 100);
            printf("\nDISCOUNT AMOUNT = %.2f", discount_amount);
            printf("\nFINAL PAYABLE AMOUNT = %.2f", payable_amount);
            printf("\nDELIVERY DISTANCE = %.2fKM",delivery_distance);
            printf("\nPRIORITY CHARGES = %.2f",priority_charges);
            printf("\nSHIPPING FEE = %.2f", shipping_fee);
            printf("\nGROUP = %s",group);
            printf("\nTOTAL PAYABLE AMOUNT AFTER EVERY CALCULATION = %.2f", total_payable_amount);
            break;
        case 2://premium
            discount_percentage = 0.15;
            discount_amount = discount_percentage * order_amount;
            payable_amount = order_amount - discount_amount;
            shipping_fee = 0;
            printf("\nFREE SHIPPING");
            if(order_amount>=10000) {
                priority_charges += CHARGE_FOR_PRIORITY;
                printf("\nPRIORITY DELIEVRY.RS 500 IS APPLIED AS ADDITIONAL CHARGE\n");
            }
            total_payable_amount = shipping_fee + priority_charges + payable_amount;
            printf("\nCUSTOMER CATEGORY = %s", CUSTOMER_CATEGORY_2);
            printf("\nORDER AMOUNT = %.2f", order_amount);
            printf("\nDISCOUNT PERCENTAGE = %.2f", discount_percentage * 100);
            printf("\nDISCOUNT AMOUNT = %.2f", discount_amount);
            printf("\nFINAL PAYABLE AMOUNT = %.2f", payable_amount);
            printf("\nDELIVERY DISTANCE = %.2fKM",delivery_distance);
            printf("\nPRIORITY CHARGES = %.2f",priority_charges);
            printf("\nSHIPPING FEE = %.2f", shipping_fee);
            printf("\nGROUP = %s",group);
            printf("\nTOTAL PAYABLE AMOUNT AFTER EVERY CALCULATION = %.2f", total_payable_amount);
            break;
        case 3://corporate
            discount_percentage = 0.20;
            discount_amount = discount_percentage * order_amount;
            payable_amount = order_amount - discount_amount;
            shipping_fee = 0;
            printf("\nFREE SHIPPING");
            if(order_amount>=10000) {
                priority_charges += CHARGE_FOR_PRIORITY;
                printf("\nPRIORITY DELIEVRY.RS 500 IS APPLIED AS ADDITIONAL CHARGE\n");
            }
            total_payable_amount = shipping_fee + priority_charges + payable_amount;
            printf("\nCUSTOMER CATEGORY = %s", CUSTOMER_CATEGORY_3);
            printf("\nORDER AMOUNT = %.2f", order_amount);
            printf("\nDISCOUNT PERCENTAGE = %.2f", discount_percentage * 100);
            printf("\nDISCOUNT AMOUNT = %.2f", discount_amount);
            printf("\nFINAL PAYABLE AMOUNT = %.2f", payable_amount);
            printf("\nDELIVERY DISTANCE = %.2fKM",delivery_distance);
            printf("\nPRIORITY CHARGES = %.2f",priority_charges);
            printf("\nSHIPPING FEE = %.2f", shipping_fee);
            printf("\nGROUP = %s",group);
            printf("\nTOTAL PAYABLE AMOUNT AFTER EVERY CALCULATION = %.2f", total_payable_amount);
            break;
        // default:
        //     break;
        }
        break;
    case 3://books
        printf("\nPRODUCT CATEGORY = %s", PRODUCT_CATEGORY_3);
        switch (customer_category)
        {
        case 1://regular
            discount_percentage = 0.08;
            discount_amount = discount_percentage * order_amount;
            payable_amount = order_amount - discount_amount;
            if(payable_amount >= 5000) {
                shipping_fee = 0;
                printf("\nFREE SHIPPING");
            } else {
                shipping_fee = SHIPPING_PER_KM * delivery_distance;
            }
            total_payable_amount = shipping_fee + priority_charges + payable_amount;
            printf("\nCUSTOMER CATEGORY = %s", CUSTOMER_CATEGORY_1);
            printf("\nORDER AMOUNT = %.2f", order_amount);
            printf("\nDISCOUNT PERCENTAGE = %.2f", discount_percentage * 100);
            printf("\nDISCOUNT AMOUNT = %.2f", discount_amount);
            printf("\nFINAL PAYABLE AMOUNT = %.2f", payable_amount);
            printf("\nDELIVERY DISTANCE = %.2fKM",delivery_distance);
            printf("\nPRIORITY CHARGES = %.2f",priority_charges);
            printf("\nSHIPPING FEE = %.2f", shipping_fee);
            printf("\nGROUP = %s",group);
            printf("\nTOTAL PAYABLE AMOUNT AFTER EVERY CALCULATION = %.2f", total_payable_amount);
            break;
        case 2://premium
            discount_percentage = 0.12;
            discount_amount = discount_percentage * order_amount;
            payable_amount = order_amount - discount_amount;
            shipping_fee = 0;
            printf("\nFREE SHIPPING");
            if(order_amount>=10000) {
                priority_charges += CHARGE_FOR_PRIORITY;
                printf("\nPRIORITY DELIEVRY.RS 500 IS APPLIED AS ADDITIONAL CHARGE\n");
            }
            total_payable_amount = shipping_fee + priority_charges + payable_amount;
            printf("\nCUSTOMER CATEGORY = %s", CUSTOMER_CATEGORY_2);
            printf("\nORDER AMOUNT = %.2f", order_amount);
            printf("\nDISCOUNT PERCENTAGE = %.2f", discount_percentage * 100);
            printf("\nDISCOUNT AMOUNT = %.2f", discount_amount);
            printf("\nFINAL PAYABLE AMOUNT = %.2f", payable_amount);
            printf("\nDELIVERY DISTANCE = %.2fKM",delivery_distance);
            printf("\nPRIORITY CHARGES = %.2f",priority_charges);
            printf("\nSHIPPING FEE = %.2f", shipping_fee);
            printf("\nGROUP = %s",group);
            printf("\nTOTAL PAYABLE AMOUNT AFTER EVERY CALCULATION = %.2f", total_payable_amount);
            break;
        case 3://corporate
            discount_percentage = 0.18;
            discount_amount = discount_percentage * order_amount;
            payable_amount = order_amount - discount_amount;
            shipping_fee = 0;
            printf("\nFREE SHIPPING");
            if(order_amount>=10000) {
                priority_charges += CHARGE_FOR_PRIORITY;
                printf("\nPRIORITY DELIEVRY.RS 500 IS APPLIED AS ADDITIONAL CHARGE\n");
            }
            total_payable_amount = shipping_fee + priority_charges + payable_amount;
            printf("\nCUSTOMER CATEGORY = %s", CUSTOMER_CATEGORY_3);
            printf("\nORDER AMOUNT = %.2f", order_amount);
            printf("\nDISCOUNT PERCENTAGE = %.2f", discount_percentage * 100);
            printf("\nDISCOUNT AMOUNT = %.2f", discount_amount);
            printf("\nFINAL PAYABLE AMOUNT = %.2f", payable_amount);
            printf("\nDELIVERY DISTANCE = %.2fKM",delivery_distance);
            printf("\nPRIORITY CHARGES = %.2f",priority_charges);
            printf("\nSHIPPING FEE = %.2f", shipping_fee);
            printf("\nGROUP = %s",group);
            printf("\nTOTAL PAYABLE AMOUNT AFTER EVERY CALCULATION = %.2f", total_payable_amount);
            break;
        // default:
        //     break;
        }
        break;
    case 4://household
        printf("\nPRODUCT CATEGORY = %s", PRODUCT_CATEGORY_4);
        switch (customer_category)
        {
        case 1://regular
            discount_percentage = 0.07;
            discount_amount = discount_percentage * order_amount;
            payable_amount = order_amount - discount_amount;
            if(payable_amount >= 5000) {
                shipping_fee = 0;
                printf("\nFREE SHIPPING");
            } else {
                shipping_fee = SHIPPING_PER_KM * delivery_distance;
            }
            total_payable_amount = shipping_fee + priority_charges + payable_amount;
            printf("\nCUSTOMER CATEGORY = %s", CUSTOMER_CATEGORY_1);
            printf("\nORDER AMOUNT = %.2f", order_amount);
            printf("\nDISCOUNT PERCENTAGE = %.2f", discount_percentage * 100);
            printf("\nDISCOUNT AMOUNT = %.2f", discount_amount);
            printf("\nFINAL PAYABLE AMOUNT = %.2f", payable_amount);
            printf("\nDELIVERY DISTANCE = %.2fKM",delivery_distance);
            printf("\nPRIORITY CHARGES = %.2f",priority_charges);
            printf("\nSHIPPING FEE = %.2f", shipping_fee);
            printf("\nGROUP = %s",group);
            printf("\nTOTAL PAYABLE AMOUNT AFTER EVERY CALCULATION = %.2f", total_payable_amount);
            break;
        case 2://premium
            discount_percentage = 0.14;
            discount_amount = discount_percentage * order_amount;
            payable_amount = order_amount - discount_amount;
            shipping_fee = 0;
            printf("\nFREE SHIPPING");
            if(order_amount>=10000) {
                priority_charges += CHARGE_FOR_PRIORITY;
                printf("\nPRIORITY DELIEVRY.RS 500 IS APPLIED AS ADDITIONAL CHARGE\n");
            }
            total_payable_amount = shipping_fee + priority_charges + payable_amount;
            printf("\nCUSTOMER CATEGORY = %s", CUSTOMER_CATEGORY_2);
            printf("\nORDER AMOUNT = %.2f", order_amount);
            printf("\nDISCOUNT PERCENTAGE = %.2f", discount_percentage * 100);
            printf("\nDISCOUNT AMOUNT = %.2f", discount_amount);
            printf("\nFINAL PAYABLE AMOUNT = %.2f", payable_amount);
            printf("\nDELIVERY DISTANCE = %.2fKM",delivery_distance);
            printf("\nPRIORITY CHARGES = %.2f",priority_charges);
            printf("\nSHIPPING FEE = %.2f", shipping_fee);
            printf("\nGROUP = %s",group);
            printf("\nTOTAL PAYABLE AMOUNT AFTER EVERY CALCULATION = %.2f", total_payable_amount);
            break;
        case 3://corporate
            discount_percentage = 0.20;
            discount_amount = discount_percentage * order_amount;
            payable_amount = order_amount - discount_amount;
            shipping_fee = 0;
            printf("\nFREE SHIPPING");
            if(order_amount>=10000) {
                priority_charges += CHARGE_FOR_PRIORITY;
                printf("\nPRIORITY DELIEVRY.RS 500 IS APPLIED AS ADDITIONAL CHARGE DUE TO PRIORITY\n");
            }
            total_payable_amount = shipping_fee + priority_charges + payable_amount;
            printf("\nCUSTOMER CATEGORY = %s", CUSTOMER_CATEGORY_3);
            printf("\nORDER AMOUNT = %.2f", order_amount);
            printf("\nDISCOUNT PERCENTAGE = %.2f", discount_percentage * 100);
            printf("\nDISCOUNT AMOUNT = %.2f", discount_amount);
            printf("\nFINAL PAYABLE AMOUNT = %.2f", payable_amount);
            printf("\nDELIVERY DISTANCE = %.2fKM",delivery_distance);
            printf("\nPRIORITY CHARGES = %.2f",priority_charges);
            printf("\nSHIPPING FEE = %.2f", shipping_fee);
            printf("\nGROUP = %s",group);
            printf("\nTOTAL PAYABLE AMOUNT AFTER EVERY CALCULATION = %.2f", total_payable_amount);
            break;
        // default:
        //     break;
        }
        break;

    // default:
    //     break;
    }

   

    return 0;
}