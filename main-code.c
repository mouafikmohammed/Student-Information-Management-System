#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Variable to keep track of number of students
int i = 0;

// Structure to store the student
struct sinfo {
	char fname[50];
	char lname[50];
	int roll;
	float cgpa;
	int cid[10];
} st[55];

// add
void add()
{

	printf("Add the Students Details\n");
	printf("-------------------------\n");
	printf("First name:\n");
	scanf("%s", st[i].fname);
	printf("Last name:\n");
	scanf("%s", st[i].lname);
	printf("Roll Number:\n");
	scanf("%d", &st[i].roll);
	printf("CGPA you obtained:\n");
	scanf("%f", &st[i].cgpa);
	printf("ID of each course:\n");
	for (int j = 0; j < 5; j++) {
		scanf("%d", &st[i].cid[j]);
	}
	i = i + 1;
}

// Find by the roll number
void find_rl()
{
	int x;
	printf("Enter the Roll Number:\n");
	scanf("%d", &x);
	for (int j = 1; j <= i; j++) {
		if (x == st[i].roll) {
			printf("Students Details are:\n");
			printf("First name is : %s\n",st[i].fname);
			printf("Last name is : %s\n",st[i].lname);
			printf("CGPA is : %f\n",st[i].cgpa);
			printf("ID of each course : \n");
		for (int j = 0; j < 5; j++) {
			printf("The course ID is %d\n",st[i].cid[j]); }
		}
		else
			printf("The Roll Number not Found\n");
	}
}

// Find by the first name
void find_fn()
{
	char a[50];
	printf("Enter the First Name:\n");
	scanf("%s", a);
	int c = 0;

	for (int j = 1; j <= i; j++) {
		if (!strcmp(st[j].fname, a)) {

			printf("Students Details are:\n");
			printf("First name is : %s\n",st[i].fname);
			printf("Last name is : %s\n",st[i].lname);
			printf("Roll Number is : %d\n ",st[i].roll);
			printf("CGPA is : %f\n",st[i].cgpa);
			printf("ID of each course :\n");

			for (int j = 0; j < 5; j++) {
				printf("The course ID is %d\n",st[i].cid[j]);
			}
			c = 1;
		}
		else
			printf("The First Name not Found\n");
	}
}

// Find the students enrolled in a particular course
void find_c()
{
	int id;
	printf("Enter the course ID \n");
	scanf("%d", &id);
	int c = 0;

	for (int j = 1; j <= i; j++) {
		for (int d = 0; d < 5; d++) {
			if (id == st[j].cid[d]) {

				printf("The Students Details are\n");
				printf("The First name is %s\n",st[i].fname);
				printf("The Last name is %s\n",st[i].lname);
				printf("The Roll Number is %d\n ",st[i].roll);
				printf("The CGPA is %f\n",st[i].cgpa);
				c = 1;
				break;
			}
			 else { printf("Not Found\n"); }
		}
	}
}

// Function to print the total number of students
void tot_s()
{
	printf("The total number of Student is %d\n",i);
	printf("\n you can have a max of 50 students\n");
	printf("you can have %d more students\n",50 - i);
}

// Delete by the roll number
void del_s()
{
	int a;
	printf("Enter the Roll Number which you want to delete\n");
	scanf("%d", &a);
	for (int j = 1; j <= i; j++) {
		if (a == st[j].roll) {
			for (int k = j; k < 49; k++)
				st[k] = st[k + 1];
			i--;
		}
	}
	printf("The Roll Number is removed Successfully\n");
}

// Update data
void up_s()
{

	printf("Enter the roll number to update the entry : ");
	long int x;
	scanf("%d", &x);
	for (int j = 0; j < i; j++) {
		if (st[i].roll == x) {
            printf("1. first name\n"
                   "2. last name\n"
                   "3. roll no.\n"
                   "4. CGPA\n"
                   "5. courses\n");
			int z;
			scanf("%d", &z);
			switch (z) {
			case 1:
				printf("New first name : \n");
				scanf("%s", st[i].fname);
				break;
			case 2:
				printf("New last name : \n");
				scanf("%s", st[i].lname);
				break;
			case 3:
				printf("New roll number : \n");
				scanf("%d", &st[i].roll);
				break;
			case 4:
				printf("New CGPA : \n");
				scanf("%f", &st[i].cgpa);
				break;
			case 5:
				printf("New courses ID \n");
				scanf(
					"%d%d%d%d%d", &st[i].cid[0],
					&st[i].cid[1], &st[i].cid[2],
					&st[i].cid[3], &st[i].cid[4]);

			}
			printf("UPDATED SUCCESSFULLY.\n");
		}
	}
}
// Menu
void main()

{
	int choice, count;
	while (i = 1) {
		printf("Choose the task you want:\n");
		printf("1. Add\n");
		printf("2. Search by Roll Number\n");
		printf("3. Search by First Name\n");
		printf("4. Search by Course Id\n");
		printf("5. Total number of Students\n");
		printf("6. Delete the Students Details by Roll Number\n");
		printf("7. Update the Students Details by Roll Number\n");
		printf("8. Exit program\n");
		printf("Enter your choice to find the task\n");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			add();
			break;
		case 2:
			find_rl();
			break;
		case 3:
			find_fn();
			break;
		case 4:
			find_c();
			break;
		case 5:
			tot_s();
			break;
		case 6:
			del_s();
			break;
		case 7:
			up_s();
			break;
		case 8:
			exit(0);
			break;
		}
	}
}
