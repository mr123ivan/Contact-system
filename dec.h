typedef struct{
	char name[1000];
	char phone[1000];
	char email[1000];
	char bday[100];
	int age;
}contact;



void add(contact c[],int *count);
void searchName(contact c[], int count, char name[]);
void searchPhone(contact c[], int count, char phone[]);
void updateContact(contact c[],int *count);
int deleteContact(contact c[], int *count, int yesno);
float avgAge(contact c[], int count);
void oldest(contact c[], int count);
void youngest(contact c[], int count);
int countbday(contact c[], int count, char bday[]);
