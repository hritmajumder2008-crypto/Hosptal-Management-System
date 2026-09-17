#include <stdio.h>
#include <string.h>

#define MAX 100

// Structures
struct Patient {
    int id;
    char name[50];
    int age;
    char gender[10];
    char disease[50];
};

struct Appointment {
    int appointmentId;
    int patientId;
    char doctor[50];
    char date[20];
};

struct Bill {
    int billId;
    int patientId;
    float consultationFee;
    float medicineFee;
    float testFee;
    float total;
};

// Global variables
struct Patient patients[MAX];
struct Appointment appointments[MAX];
struct Bill bills[MAX];

int patientCount = 0;
int appointmentCount = 0;
int billCount = 0;

// Function declarations
void patientManagement();
void appointmentManagement();
void billingManagement();

void addPatient();
void viewPatients();
void searchPatient();
void updatePatient();

void bookAppointment();
void viewAppointments();
void cancelAppointment();

void createBill();
void calculateTotal();
void viewBills();

int main() {
    int choice;

    do {
        printf("\n========== HOSPITAL MANAGEMENT SYSTEM ==========\n");
        printf("1. Patient Management\n");
        printf("2. Appointment Management\n");
        printf("3. Billing Management\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                patientManagement();
                break;

            case 2:
                appointmentManagement();
                break;

            case 3:
                billingManagement();
                break;

            case 4:
                printf("\nThank you for using the system!\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }
    } 
	while (choice != 4);

    return 0;
}

// Patient Management
void patientManagement() {
    int choice;

    do {
        printf("\n------ PATIENT MANAGEMENT ------\n");
        printf("1. Add Patient\n");
        printf("2. View Patient\n");
        printf("3. Search Patient\n");
        printf("4. Update Patient\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPatient();
                break;

            case 2:
                viewPatients();
                break;

            case 3:
                searchPatient();
                break;

            case 4:
                updatePatient();
                break;

            case 5:
                break;

            default:
                printf("Invalid choice!\n");
        }
    } 
	while (choice != 5);
}

// Add Patient
void addPatient() {
    if (patientCount >= MAX) {
        printf("Patient limit reached!\n");
        return;
    }

    printf("\nEnter Patient ID: ");
    scanf("%d", &patients[patientCount].id);

    printf("Enter Patient Name: ");
    scanf(" %[^\n]", patients[patientCount].name);

    printf("Enter Age: ");
    scanf("%d", &patients[patientCount].age);

    printf("Enter Gender: ");
    scanf("%s", patients[patientCount].gender);

    printf("Enter Disease: ");
    scanf(" %[^\n]", patients[patientCount].disease);

    patientCount++;

    printf("\nPatient added successfully!\n");
}

// View Patients
void viewPatients() {
    int i;

    if (patientCount == 0) {
        printf("\nNo patients available!\n");
        return;
    }

    printf("\n------ PATIENT DETAILS ------\n");

    for (i = 0; i < patientCount; i++) {
        printf("\nPatient ID: %d", patients[i].id);
        printf("\nName: %s", patients[i].name);
        printf("\nAge: %d", patients[i].age);
        printf("\nGender: %s", patients[i].gender);
        printf("\nDisease: %s\n", patients[i].disease);
    }
}

// Search Patient
void searchPatient() {
    int id, i, found = 0;

    printf("\nEnter Patient ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            printf("\nPatient Found!\n");
            printf("Name: %s\n", patients[i].name);
            printf("Age: %d\n", patients[i].age);
            printf("Gender: %s\n", patients[i].gender);
            printf("Disease: %s\n", patients[i].disease);
            found = 1;
            break;
        }
    }

    if (found!=1) {
        printf("\nPatient not found!\n");
    }
}

// Update Patient
void updatePatient() {
    int id, i, found = 0;

    printf("\nEnter Patient ID to update: ");
    scanf("%d", &id);

    for (i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            printf("Enter New Name: ");
            scanf(" %[^\n]", patients[i].name);

            printf("Enter New Age: ");
            scanf("%d", &patients[i].age);

            printf("Enter New Gender: ");
            scanf("%s", patients[i].gender);

            printf("Enter New Disease: ");
            scanf(" %[^\n]", patients[i].disease);

            printf("\nPatient updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (found!=1) {
        printf("\nPatient not found!\n");
    }
}

// Appointment Management
void appointmentManagement() {
    int choice;

    do {
        printf("\n------ APPOINTMENT MANAGEMENT ------\n");
        printf("1. Book Appointment\n");
        printf("2. View Appointment\n");
        printf("3. Cancel Appointment\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bookAppointment();
                break;

            case 2:
                viewAppointments();
                break;

            case 3:
                cancelAppointment();
                break;

            case 4:
                break;

            default:
                printf("Invalid choice!\n");
        }
    } 
	while (choice != 4);
}

// Book Appointment
void bookAppointment() {
    if (appointmentCount >= MAX) {
        printf("Appointment limit reached!\n");
        return;
    }

    printf("\nEnter Appointment ID: ");
    scanf("%d", &appointments[appointmentCount].appointmentId);

    printf("Enter Patient ID: ");
    scanf("%d", &appointments[appointmentCount].patientId);

    printf("Enter Doctor Name: ");
    scanf(" %[^\n]", appointments[appointmentCount].doctor);

    printf("Enter Date (DD/MM/YYYY): ");
    scanf("%s", appointments[appointmentCount].date);

    appointmentCount++;

    printf("\nAppointment booked successfully!\n");
}

// View Appointments
void viewAppointments() {
    int i;

    if (appointmentCount == 0) {
        printf("\nNo appointments available!\n");
        return;
    }

    printf("\n------ APPOINTMENT DETAILS ------\n");

    for (i = 0; i < appointmentCount; i++) {
        printf("\nAppointment ID: %d",
               appointments[i].appointmentId);
        printf("\nPatient ID: %d",
               appointments[i].patientId);
        printf("\nDoctor: %s", appointments[i].doctor);
        printf("\nDate: %s\n", appointments[i].date);
    }
}

// Cancel Appointment
void cancelAppointment() {
    int id, i, j, found = 0;

    printf("\nEnter Appointment ID to cancel: ");
    scanf("%d", &id);

    for (i = 0; i < appointmentCount; i++) {
        if (appointments[i].appointmentId == id) {
            for (j = i; j < appointmentCount - 1; j++) {
                appointments[j] = appointments[j + 1];
            }

            appointmentCount--;
            printf("\nAppointment cancelled successfully!\n");
            found = 1;
            break;
        }
    }

    if (found!=1) {
        printf("\nAppointment not found!\n");
    }
}

// Billing Management
void billingManagement() {
    int choice;

    do {
        printf("\n------ BILLING MANAGEMENT ------\n");
        printf("1. Create Bill\n");
        printf("2. Calculate Total\n");
        printf("3. View Bill\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createBill();
                break;

            case 2:
                calculateTotal();
                break;

            case 3:
                viewBills();
                break;

            case 4:
                break;

            default:
                printf("Invalid choice!\n");
        }
    } 
	while (choice != 4);
}

// Create Bill
void createBill() {
    if (billCount >= MAX) {
        printf("Bill limit reached!\n");
        return;
    }

    printf("\nEnter Bill ID: ");
    scanf("%d", &bills[billCount].billId);

    printf("Enter Patient ID: ");
    scanf("%d", &bills[billCount].patientId);

    printf("Enter Consultation Fee: ");
    scanf("%f", &bills[billCount].consultationFee);

    printf("Enter Medicine Fee: ");
    scanf("%f", &bills[billCount].medicineFee);

    printf("Enter Test Fee: ");
    scanf("%f", &bills[billCount].testFee);

    bills[billCount].total =
        bills[billCount].consultationFee +
        bills[billCount].medicineFee +
        bills[billCount].testFee;

    billCount++;

    printf("\nBill created successfully!\n");
}

// Calculate Total
void calculateTotal() {
    int id, i, found = 0;

    printf("\nEnter Bill ID: ");
    scanf("%d", &id);

    for (i = 0; i < billCount; i++) {
        if (bills[i].billId == id) {
            bills[i].total =
                bills[i].consultationFee +
                bills[i].medicineFee +
                bills[i].testFee;

            printf("\nTotal Bill Amount: %.2f\n",
                   bills[i].total);

            found = 1;
            break;
        }
    }

    if (found!=1) {
        printf("\nBill not found!\n");
    }
}

// View Bills
void viewBills() {
    int i;

    if (billCount == 0) {
        printf("\nNo bills available!\n");
        return;
    }

    printf("\n------ BILL DETAILS ------\n");

    for (i = 0; i < billCount; i++) {
        printf("\nBill ID: %d", bills[i].billId);
        printf("\nPatient ID: %d", bills[i].patientId);
        printf("\nConsultation Fee: %.2f",
               bills[i].consultationFee);
        printf("\nMedicine Fee: %.2f",
               bills[i].medicineFee);
        printf("\nTest Fee: %.2f",
               bills[i].testFee);
        printf("\nTotal Amount: %.2f\n",
               bills[i].total);
    }
}

