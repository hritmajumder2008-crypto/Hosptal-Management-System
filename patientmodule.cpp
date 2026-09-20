#include<stdio.h>
struct Patient{
	int id;
    char name[50];
    int age;
    char gender[10];
    char contact[15];
    char address[100];
};
struct Patient p[100];
int count = 0;

/*1. ADD PATIENTS DETAILS */
int addPatient(){
	printf(" ADD PATIENT DETAILS ");
    printf("Enter Patient ID: ");
    scanf("%d", &p[count].id);
    printf("Enter Name: ");
    scanf(" %[^\n]", p[count].name);
    printf("Enter Age: ");
    scanf("%d", &p[count].age);
    printf("Enter Gender: ");
    scanf("%s", p[count].gender);
    printf("Enter Contact: ");
    scanf("%s", p[count].contact);
    printf("Enter Address: ");
    scanf(" %[^\n]", p[count].address);
    count++;
    printf("PATIENTS DETAILS ADDED SUCCESSFULLY!!");
    return 1;
}

/*2. VIEW PATIENTS DETAILS */
int viewPatients(){
	int i;
    if (count == 0)
    {
        printf("NO PATIENT RECORD IS AVAILABLE");
        return 0;
    }
    printf("PATIENT RECORDS");
    for (i = 0; i < count; i++)
    {
        printf("\nPatient ID: %d", p[i].id);
        printf("\nName: %s", p[i].name);
        printf("\nAge: %d", p[i].age);
        printf("\nGender: %s", p[i].gender);
        printf("\nContact: %s", p[i].contact);
        printf("\nAddress: %s", p[i].address);
    }
    return 1;
}

/*3. SEARCH PATIENT DETAILS */
int searchPatient(){
	int id, i;
    printf("ENTER PATIENTS ID TO SEARCH: ");
    scanf("%d", &id);
    for (i = 0; i < count; i++){
    	if (p[i].id == id){
    		printf("PATIENT FOUND!!:)");
            printf("Patient ID: %d\n", p[i].id);
            printf("Name: %s\n", p[i].name);
            printf("Age: %d\n", p[i].age);
            printf("Gender: %s\n", p[i].gender);
            printf("Contact: %s\n", p[i].contact);
            printf("Address: %s\n", p[i].address);
            return 1;	
		}
	}
    printf("PATIENT NOT FOUND:(");
    return 0;
}

/*4. UPDATE PATIENTS RECORDS */
int updatePatient(){
	int id, i;
    printf("ENTER PATIENTS ID TO UPDATE DETAILS: ");
    scanf("%d", &id);
    for (i = 0; i < count; i++){
    	if (p[i].id == id){
    		printf("Enter New Name: ");
            scanf(" %[^\n]", p[i].name);
            printf("Enter New Age: ");
            scanf("%d", &p[i].age);
            printf("Enter New Gender: ");
            scanf("%s", p[i].gender);
            printf("Enter New Contact: ");
            scanf("%s", p[i].contact);
            printf("Enter New Address: ");
            scanf(" %[^\n]", p[i].address);
            printf("PATIENTS DETAILS UPDATED SUCCESSFULLY!\n");
            return 1;
		}
	}
	printf(" PATIENT NOT FOUND:( ");
    return 0;
}

/*5. MAIN FUNCTION*/
int main(){
	int choice;
    int result;

    while (1){
        printf("\n     HOSPITAL MANAGEMENT");
        printf("\n       PATIENT MODULE");
        printf("\n==============================");
        printf("\n1. Add Patient");
        printf("\n2. View Patients");
        printf("\n3. Search Patient");
        printf("\n4. Update Patient");
        printf("\n5. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice){
        	 case 1:
                result = addPatient();
                break;
            case 2:
                result = viewPatients();
                break;
            case 3:
                result = searchPatient();
                break;
            case 4:
                result = updatePatient();
                break;
            case 5:
                printf("\nThank you!\n");
                return 0;
            default:
                printf("\nInvalid choice!\n");
		}
	}
	return 0;
}



