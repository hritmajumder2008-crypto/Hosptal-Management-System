#include <stdio.h>
struct Appointment
{
	int appointmentID;
	int patientID;
	char doctor[50];
	char date[20];
	char time[10];
};
int main()
{
	struct Appointment a;
	printf("enter appointment ID:");
	scanf("%d",&a.appointmentID);
	printf("enter patient ID:");
	scanf("%d",&a.patientID);
	printf("enter doctor name:");
	scanf("%s",&a.doctor);
	printf("\nenter date:");
	scanf("%s",&a.date);
	printf("\nenter time:");
	scanf("%s",&a.time);

	printf("appointment ID:%d\n",a.appointmentID);
	printf("patient ID:%d\n",a.patientID);
	printf("doctor:%s\n",a.doctor);
	printf("date:%s\n",a.date);
	printf("time:%s\n",a.time);
	return 0;
}
