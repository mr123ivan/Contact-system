#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "dec.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    //for adding
	int count=0;
	contact c[100];
	
	//inputs cpr
	char name[100];
	char phone[100];
	int yesno;
	char oldno[100];
	char birthday[100];
	
	//choice
	int choice;


//loading feature
int i;
printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t ");
char start[100]="Opening Contact System. Please wait";
char dot[100]={"......."};
for(i=0; i<strlen(start);i++){
	printf("%c",start[i]);
	Sleep(60);
}
for(i=0; i<strlen(dot);i++){
	printf("%c",dot[i]);
	Sleep(300);
}


system("cls");
// end of feature	
	
do{
	printf("Please choose from the option:");
	printf("\n[1] Add Contact");
	printf("\n[2] Search Name");
	printf("\n[3] Search Phone Number");
	printf("\n[4] Update Contact");
	printf("\n[5] Delete All Contact");
	printf("\n[6] Calculate Average Age");
	printf("\n[7] Find the Oldest");
	printf("\n[8] Find the Youngest");
	printf("\n[9] Number of students with Same birthdate");
	printf("\n\n(Special)");
	printf("\n[10] View All Names\n\n");
printf("\nEnter choice: ");
scanf("%d",&choice);

switch(choice){
	
	case 1: printf("\n\nADD TO CONTACTS\n");
	        add(c,&count);
	        printf("Press any key to continue...");
            break;
			
	case 2: printf("\n\nSEARCH NAME");
	        printf("\nName: ");
			scanf("%s", &name);
			searchName(c,count,name);
			break;
			
	case 3:	printf("\n\nSEARCH PHONE NUMBER");
	   
	        printf("\nEnter Phone Number: ");
			scanf("%s", phone);
			searchPhone(c,count,phone);	
			break;
			
	case 4: updateContact(c,&count);
	        break;
             
	        
			
	case 5: printf("\n\nAre you sure you want to delete all contacts?");
	        printf("\nEnter [1] if Yes");
			printf("\nEnter [0] if No");
			
			printf("\nHere: ");
			scanf("%d",&yesno);
			deleteContact(c,&count,yesno);	
			break;	
			
	case 6: printf("\n\nAVEARAGE AGE OF CONTACTS");
	        float avg=avgAge(c,count);
	        printf("\nAverage age: %.2f",avg);	
			break;	
			
	case 7: printf("\n\nTHE OLDEST CONTACT");
	        	
	        oldest(c,count);
			break;	
	
	case 8: printf("\n\nTHE YOUNGEST CONTACT");

	        youngest(c,count);
			break;
			
    case 9: printf("\n\nCOUNT SAME BIRTHDATE");
    
            printf("\nEnter Birthdate: ");
            scanf("%s",&birthday);
            
            int same= countbday(c,count,birthday);
            if(same!=0){
			printf("%s birthdate exist %dx in the contact",birthday,same);
			}
			
			else{
				printf("%s not found in the data!",birthday);
			}
			
			break;
            
	case 10: display(c,count);		
			 break;
			
	default: printf("\n\nWrong option!");	
		     printf("\nPress any key to continue...");
		     break;
			
			
			
			
			
						
}//end of switch

getch();
system("cls");	
}while(choice!=0);	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
