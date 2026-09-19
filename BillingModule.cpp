#include <stdio.h>
int main (){
	int choice;
	int billID= 101, PatientID= 1001;
	int c=0, s=0, m=0, tot=0;
	while(1){
		printf("BILLING MODULE\n");
		printf("1. Enter consultation fees: \n");
		printf("2. Enter service charges: \n");
		printf("3. Enter medicine charges: \n");
		printf("4. Calculate total charges: \n");
		printf("5. Display bill: \n");
		printf("6. Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter consultation fees in rupees: ");
			    scanf("%d",&c);
		       	printf("Consultation fee is updated.\n");
		    	break;
		    case 2:
			    printf("Enter service charges in rupees: ");
			    scanf("%d",&s);
		       	printf("Service charge is updated.\n");
		    	break;	
            case 3:
            	printf("Enter medicine charges in rupees: ");
			    scanf("%d",&m);
		       	printf("Medicine charge is updated.\n");
		    	break;
			case 4:
				tot=c+s+m;
				printf("Total bill: Rs. %d\n", tot);
                break;
            case 5:
			    tot = c + s + m;
                printf("Bill\n");
                printf("Bill ID: %d\n", billID);
                printf("Patient ID: %d\n", PatientID);
                printf("------------------------------------\n");
                printf("Consultation Fee: Rs. %d\n", c);
                printf("Service Charges: Rs. %d\n", s);
                printf("Medicine Charges: Rs. %d\n", m);
                printf("------------------------------------\n");
                printf("Total amount: Rs. %d\n", tot);
                break;
            case 6:
                printf("Thank You. Goodbye!\n");
                return 0;
			default:
			printf("Invalid choice!");
			break;	    
		}
	}
	return 0;
}
