#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "candidate.h"

int main()
{
    system("clear");
    int choice = 0;
    while(1)
    {
        printf("========== Candidate Database ==========\n\n\n");
        printf("1. Add candidate\n");
        printf("2. View candidates\n");
        printf("3. Search candidate\n");
        printf("4. Update candidate\n");
        printf("5. Delete candidate\n");
        printf("6. Exit\n\n\n");
        printf("Enter Choice\n");
        scanf("%d", &choice);
        if(choice == 1)
        {
            system("clear");
            add_candidate();
            printf("\n");
        }
        else if(choice == 2)
        {
            system("clear");
            read();
            printf("\n");
        }
        else if(choice == 3)
        {
            system("clear");
            search_candidate();
            printf("\n");
        }
        else if(choice == 4)
        {
            system("clear");
            update_candidate();
            printf("\n");
        }
        else if(choice == 5)
        {
            system("clear");
            delete_candidate();
            printf("\n");
        }
        else if(choice == 6)
        {
            system("clear");
            printf("THANK YOU!!\n");
            break;
        }
        else
        {
            system("clear");
            printf("Choose again!!\n");;
        }
        //system("clear");
    }
    //system("clear");
    //printf("Thank You !!\n");

    return 0;
}