#include<stdio.h>
#include<string.h>
#include "dec.h"


void add(contact c[],int *count){
//	printf("Enter Name: ");
//	scanf("\n%[^\n]%*c", &c[*count].name);
//	
//	printf("Enter Phone Number: ");
//	scanf("\n%[^\n]%*c", &c[*count].phone);
//	
//	printf("Enter Email: ");
//	scanf("\n%[^\n]%*c", &c[*count].email);
//	
//	printf("Enter Birthdate(yyyy-mm-dd): ");
//	scanf("\n%[^\n]%*c", &c[*count].bday);
//	
//	(*count)++;

	printf("Enter Name: ");
	scanf("%s", &c[*count].name);
	
	printf("Enter Phone Number: ");
	scanf("%s", &c[*count].phone);
	
	printf("Enter Email: ");
	scanf("%s", &c[*count].email);
	
	printf("Enter Birthdate(yyyy-mm-dd): ");
	scanf("%s", &c[*count].bday);
	
	printf("Enter Age: ");
	scanf("%d", &c[*count].age);
	
	(*count)++;


}
// extra function to display
void display(contact c[],int count){
	int i;
	for( i=0; i<count; i++){
		printf("\nContact listed: %s - %s - %s - %s - %d", c[i].name, c[i].phone, c[i].email, c[i].bday, c[i].age);
	}
	
	if(count==0){
		printf("\n\nYou're Contact is Empty");
	}
}
//name search
void searchName(contact c[], int count, char name[]){
	int i;
	int found=0;
	
	printf("Contact Matches:");
	for(i=0; i<count; i++){
		if(strcmpi(c[i].name,name)==0){
			printf("\nName: %s", c[i].name);
		 	printf("\nPhone: %s", c[i].phone);
		   	printf("\nEmail: %s", c[i].email);
			printf("\nBirthdate: %s", c[i].bday); 
			printf("\nAge: %d", c[i].age); 
			found=1;
		break;
		
		}
		
     
	 }
	
	if(found!=1){
     	printf("Contact not found!");
	}
}

//number search
void searchPhone(contact c[], int count, char phone[]){
	int i;
	int found=0;

	printf("Contact Matches:");
	for(i=0; i<count; i++){
		if(strcmpi(c[i].phone,phone)==0){
			printf("\nName: %s", c[i].name);
		 	printf("\nPhone: %s", c[i].phone);
		   	printf("\nEmail: %s", c[i].email);
			printf("\nBirthdate: %s", c[i].bday); 
			printf("\nAge: %d", c[i].age);
			found=1;
		break;
		}
		
	}
	if(found==0){
		printf("\nPhone number not Found!");	
		
	}
}


//update func
void updateContact(contact c[],int *count){
	char newno[100];
	int index=-1;
	
	
int yesno;	
	
printf("Enter Phone number to edit:");
scanf("%s",newno);	
int i;	
for( i=0; i<*count; i++){
	if(strcmpi(c[i].phone,newno)==0){
		index=i;
		break;
	}
}

if(index!=-1){
	//current display
	printf("\n\nCONTACT FOUND!");
	printf("\nCurrent name: %s",c[i].name);
	printf("\nCurrent Phone no: %s",c[i].phone);
	printf("\nCurrent Email: %s",c[i].email);
	printf("\nCurrent Birthdate: %s",c[i].bday);
	printf("\nCurrent Age: %d",c[i].age);
	
	
	//---------------------------------------
	//update section
	printf("\n\nEnter New Name for %s: ",c[i].name);
	scanf("%s",c[index].name);
	
	printf("Enter New Phone No: ");
	scanf("%s",c[index].phone);
	 
	printf("Enter New Email: ");
	scanf("%s",c[index].email); 

    printf("Enter New Birthdate: ");
	scanf("%s",c[index].bday);
	
	printf("Enter New Birthdate: ");
	scanf("%d",&c[index].age);
	
	printf("\nContact Updated Sucessfully!");
}
else {
        
        printf("\n%s is not found!",newno);
        printf("\nDo you want %s to be added to your new Contacts?",newno);
        printf("\nType [1] if yes\nType [0] if No");
        printf("\nHere: ");
        scanf("%d", &yesno);

        if (yesno == 1) {
            strcpy(c[*count].phone, newno);

            printf("Enter Name: ");
            scanf("%s", &c[*count].name);

            printf("Enter Email: ");
            scanf("%s", &c[*count].email);

            printf("Enter Birthdate: ");
            scanf("%s", &c[*count].bday);
            
            printf("Enter Age: ");
            scanf("%d", &c[*count].age);
            
            (*count)++;

            printf("\nContact Added Successfully!");
        } else {
            printf("\nContact not added. Press any key to continue...");
        }
    }
}




//delete function
int deleteContact(contact c[], int *count, int yesno){
	if(yesno==1){
		printf("All contacts deleted Sucessfully");
		return *count=0;
	}
	else if(yesno==0){
		printf("You can choose [10] to view your contacts. Press any key to go back...");
	}
}



//average age

float avgAge(contact c[], int count){

	int i;
	int sum=0;
	for( i=0; i<count; i++){
sum+=c[i].age;		

	}
	float avg= (float)sum/count;
return 	avg;
	
}

//find oldest age
void oldest(contact c[], int count){
	int i;
	int old=c[0].age;
	for(i=1; i<count; i++){
	
	if(c[i].age>old){
		old=c[i].age;
	
	 
	}
		
	}
		printf("\nOldest age in the contact is: %d yrs old",old);
	
}

//find youngest age
void youngest(contact c[], int count){
	int i;
	int young=c[0].age;
	for(i=1; i<count; i++){
	
	if(c[i].age<young){
		young=c[i].age;
	
	 
	}
		
	}
		printf("\nYoungest age in the Contact is: %d yrs old",young);
}


//count bday

int countbday(contact c[], int count, char bday[]){
	int i;
	int counter=0;
	for(i=0; i<count; i++){
		if(strcmp(c[i].bday,bday)==0){
			counter++;
		
		}
	}
	return counter;
}

