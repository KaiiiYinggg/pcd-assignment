#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <time.h>
#pragma warning(disable:4996)
#define PASS "1119lol"         // use as password

void menu();
//SALES INFORMATION MODULE
void salesinfo();
void carDetails();
void SalesAddSalesOrder();
void SalesFileModify(int qty, char code[]);
void SalesFileDelete(int qty, char code[]);
void SalesSearchSalesOrder();
void SalesModifySalesOrder();
void SalesDeleteSalesOrder();
void SalesDisplaySalesOrder();
void SalesPrintSalesOrder();
void SalesCalculateTotalPrice(salesOrder);

//STOCK INFORMATION MODULE
void stockinfo();  //sub-menu for stock information module
void StockDisplay();  //display stock information
void StockSearch();  //search for specific stock information
void StockAdd();  //add stock information
void StockModify();  //modify existed information
char* StockModifyItemCode();  //sub-function of the modify function
double StockModifyItemPrice(double price); //sub-function of the modify function
char* StockModifyItemDesc(); //sub-function of the modify function
int StockModifyItemQty(int qty);  //sub-function of the modify function
void StockModifyDate(int oldd, int oldm, int oldy, int* d, int* m, int* y);  //sub-function of the modify function
int StockModifyReservedQty(int rqty);  //sub-function of the modify function
char* StockModifyCustName();  //sub-function of the modify function
void StockDeleteInfo(); //use to delete the record
void StockCalculate();  //view the total product qty and some more
char StockValidate(char input);  //use to validate the input 

//MEMBER INFORMATION MODULE
void memberTitle();                              // display title
void memberLine();                              //dispaly line
void memberAddMember();                        //add new membe
void memberDeleteMember();                    //delete member by insert ID
void memberSearchMember();                   //search member by insert ID
void memberDisplayMember();                 //display all exist member
void memberFilterMember();                 //filter member by age
void memberModifyMember();                //modify member information
void memberExitMessage();                //exit message
void memberConfirmExit(char* choice);   //exitconfirmation
void memberMenu();                     //display menu

//STAFF INFORMATION MODULE
void StaffDisplay();
void StaffSearch();
void StaffAdd(char newStaffId[]);
void StaffValidate();
void StaffModify();
void StaffDeleted();
void staffinfo();
void StaffExited();

//SALES INFORMATION MODULE
typedef struct {
	int fileDate;
	int fileMonth;
	int fileYear;
} fileDate;
typedef struct {
	char fileCode[6];
	float filePrice;
	char fileName[50];
	int fileQty;
	char fileCustName[50];
	int fileCheckInQty;
	fileDate fd;
} car;
typedef struct {
	char itemCode[6];
	int qtyOrdered;
	float price;
	char itemName[50];
} item;
typedef struct {
	int date;
	int year;
	int month;
} day;
typedef struct {
	char salesOrderID[6];
	char name[50];
	item items[10];
	day d;
	int numItem;
	int contact;
} salesOrder;

//STOCK INFORMATION MODULE
struct Date {
	int day;
	int month;
	int year;
};
typedef struct {
	char itemCode[6];
	double itemPrice;
	char itemDesc[50];
	int qty;
	int reserqty;
	struct Date inDate;
	char cusName[50];
}Stock;

//MEMBER INFORMATION MODULE
typedef struct {              //store member birthday  dd/mm/yyy
	int day, month, year;
}birthday;
struct member {               //store member information

	char name[31];
	birthday date;
	char gender;
	int age;
	char icNum[13];
	char address[101];
	char contactNum[15];
	int idNum;

};

//STAFF INFORMATION MODULE
typedef struct
{
	int day;
	int month;
	int year;
}Date;
typedef struct
{
	char staffId[10];
	char staffName[30];
	char phoneNum[12];
	char department[20];
	Date date;
}Staff;

void main()
{

	char pass[11];
	time_t t;
	time(&t);

	do {

		printf("DATE/TIME: %s", ctime(&t));


		printf("---------------------------------------------------------\n");
		printf("|\t\t| WELCOME TO OUR SYSTEM |\t\t|\n");
		printf("---------------------------------------------------------\n\n");

		printf("\t\t Please enter the password:");
		scanf("%s", pass);

		if (strcmp(pass, PASS) == 0)
		{
			system("cls");
			menu();
		}

		else
		{
			system("cls");
			printf(" //////////////////// Access denied! ////////////////////\n");
		}


	} while (pass != PASS);

	//return 0;

}

void menu() 
{
	int selection;

	printf("\t\t WELCOME TO OUR SYSTEM\n");
	printf("=====================================================\n");
	printf("\t1. STOCK INFORMATION\n");
	printf("\t2. STAFF INFORMATION\n");
	printf("\t3. SALES INFORMATION\n");
	printf("\t4. MEMBER INFORMATION\n");
	printf("\t5. EXIT PROGRAM\n");
	printf("=====================================================\n");
	printf("\tEnter your selection :");
	rewind(stdin);
	scanf("%d", &selection);
	rewind(stdin);
	printf("=====================================================\n");

	while (selection < 1 || selection > 5)
	{
		printf("Invalid\n");
	printf("\tEnter your selection :");
	scanf("%d", &selection);
	rewind(stdin);
	printf("=====================================================\n");
	}

	switch (selection) 
	{
	case 1:stockinfo(); break;
	case 2:staffinfo(); break;
	case 3:salesinfo(); break;
	case 4:memberMenu(); break;
	case 5:exit(0); break;
	}
}

//SALES INFORMATION MODULE
void salesinfo() {

	int opt;
	do {
		printf("\n\t _________________________________________\n");
		printf("\t/ \\                                       \\\n");
		printf("\t\\__|       SALES INFORMATION               |\n");
		printf("\t   |---------------------------------------|\n");
		printf("\t   |   1.  Add Sales Order                 |\n");
		printf("\t   |   2.  Search Sales Order              |\n");
		printf("\t   |   3.  Modify Sales Order              |\n");
		printf("\t   |   4.  Delete Sales Order              |\n");
		printf("\t   |   5.  Display Sales Order             |\n");
		printf("\t   |   6.  Print Report                    |\n");
		printf("\t   |   7.  Return to menu                  |\n");
		printf("\t   |   8.  Exit                            |\n");
		printf("\t   |  _____________________________________|_\n");
		printf("\t   \\_/______________________________________/\n");

		printf("\n\t\tYour option: ");
		scanf(" %d", &opt);

		switch (opt) {
		case 1:system("cls"); SalesAddSalesOrder(); break;
		case 2:SalesSearchSalesOrder(); break;
		case 3:SalesModifySalesOrder(); break;
		case 4:SalesDeleteSalesOrder(); break;
		case 5:SalesDisplaySalesOrder(); break;
		case 6:system("cls"); SalesPrintSalesOrder(); break;
		case 7:system("cls"); printf("Logged out successfully !\n"); menu(); break;
		case 8:
			printf("\n\t*********************************************************\n");
			printf("\t*   Thank you for using our program. Have a nice day!   *\n");
			printf("\t*********************************************************\n");
			exit(-1);
		default: printf("Invalid Opt! Please choose again!\n\n");
		}
	} while (opt != 8);
}
void carDetails() {

	car c;

	FILE* carMenu;
	carMenu = fopen("stockinfo.txt", "r");
	if (carMenu == NULL) {
		printf("Unable to open the file");
		exit(-1);
	}

	printf("\n\t+----------+---------------------+--------------+----------+\n");
	printf("\t|   CODE   |        NAME         |    PRICE     | QUANTITY |\n");
	printf("\t+----------+---------------------+--------------+----------+\n");
	while (fscanf(carMenu, "%[^|]|%f|%[^|]|%d|%d %d %d|%d|%s\n", c.fileCode, &c.filePrice, c.fileName, &c.fileQty, &c.fd.fileDate, &c.fd.fileMonth, &c.fd.fileYear, &c.fileCheckInQty, c.fileCustName) != EOF) {
		printf("\t| %-8s | %-20s| RM%10.2f |   %-5d  |\n", c.fileCode, c.fileName, c.filePrice, c.fileQty);
	}
	printf("\t+----------+---------------------+--------------+----------+\n");
	fclose(carMenu);
}
void SalesAddSalesOrder() {
	car c[100];
	salesOrder s;
	item i;
	char checkCode[6], ans;
	int itemCount = 0;
	float total = 0;
	carDetails();

	printf("\n\tEnter Sales Order ID: ");
	rewind(stdin);
	scanf(" %s", s.salesOrderID);

	printf("\tEnter Customer Name: ");
	rewind(stdin);
	scanf(" %[^\n]", s.name);

	printf("\tEnter Contact Number: ");
	rewind(stdin);
	scanf(" %d", &s.contact);

	do {
		FILE* carMenu;
		carMenu = fopen("stockinfo.txt", "r");

		if (carMenu == NULL) {
			printf("Unable to open the file");
			exit(-1);
		}

		int found = 0;
		int j = 0;

		for (j = 0; fscanf(carMenu, "%[^|]|%f|%[^|]|%d|%d %d %d|%d|%s\n", c[j].fileCode, &c[j].filePrice, c[j].fileName, &c[j].fileQty, &c[j].fd.fileDate, &c[j].fd.fileMonth, &c[j].fd.fileYear, &c[j].fileCheckInQty, c[j].fileCustName) != EOF; j++);

		fclose(carMenu);

		while (found == 0)
		{
			printf("\n\tEnter car code: ");
			rewind(stdin);
			scanf("%s", &checkCode);

			for (int a = 0; a < j; a++) {
				if (strcmp(checkCode, c[a].fileCode) == 0) {
					strcpy(s.items[itemCount].itemCode, c[a].fileCode);
					strcpy(s.items[itemCount].itemName, c[a].fileName);
					s.items[itemCount].price = c[a].filePrice;
					found = 1;
					break;
				}
			}

			if (found == 0) {
				printf("\n\tInvalid car code! Please try again.\n");
			}
		}
		printf("\tEnter Quantity: ");
		scanf(" %d", &s.items[itemCount].qtyOrdered);

		printf("\n\tCar Code: %s\n", s.items[itemCount].itemCode);
		printf("\tCar Name: %s\n", s.items[itemCount].itemName);
		printf("\tOrdered Qty: %d\n", s.items[itemCount].qtyOrdered);

		itemCount++;

		printf("\n\tAdd a new car?(Y=Yes, N=No): ");
		scanf(" %c", &ans);

	} while (toupper(ans) == 'Y');

	printf("\n\tEnter Date: ");
	scanf(" %d", &s.d.date);

	printf("\tEnter Month: ");
	scanf(" %d", &s.d.month);

	printf("\tEnter Year: ");
	scanf(" %d", &s.d.year);

	printf("\n\tConfirm add Sales Order %s?(Y=Yes, N=No): ", s.salesOrderID);
	scanf(" %c", &ans);
	if (toupper(ans) == 'Y') {
		system("cls");
		printf("\t+--------------------------------------------------------+\n");
		printf("\t|                        INVOICE                         |\n");
		printf("\t|--------------------------------------------------------|\n");
		printf("\t|   Sales Order ID : %-30s      |\n", s.salesOrderID);
		printf("\t|   Customer Name  : %-30s      |\n", s.name);
		printf("\t|   Contact Number : +60%-30d   |\n", s.contact);
		printf("\t|   Order Date     : %02d-%02d-%04d                          |\n", s.d.date, s.d.month, s.d.year);
		printf("\t+--------------------------------------------------------+\n");
		printf("\t|                                                        |\n");
		printf("\t|                 Sales Order Details:                   |\n");
		printf("\t|                                                        |\n");
		printf("\t+--------------------------------------------------------+\n");
		printf("\t| Car Code  | Item Name            | Price        | Qty  |\n");
		printf("\t+--------------------------------------------------------+\n");

		for (int j = 0; j < itemCount; j++) {
			printf("\t| %-8s  | %-20s | RM %9.2f | %-3d  |\n", s.items[j].itemCode, s.items[j].itemName, s.items[j].price, s.items[j].qtyOrdered);
			total += s.items[j].price * s.items[j].qtyOrdered;
			SalesFileModify(s.items[j].qtyOrdered, s.items[j].itemCode);
		}

		printf("\t+--------------------------------------------------------+\n");
		printf("\t|                                                        |\n");
		printf("\t| Total Amount: RM %10.2f                            |\n", total);
		printf("\t+--------------------------------------------------------+\n");

		FILE* ptr;
		ptr = fopen("SalesInfo.dat", "ab");

		if (ptr == NULL) {
			printf("Unable to open the file");
			exit(-1);
		}
		s.numItem = itemCount;
		fwrite(&s, sizeof(salesOrder), 1, ptr);
		fclose(ptr);

		printf("\n\tAdd another Sales Order? (Y=Yes, N=No): ");
		scanf(" %c", &ans);
		if (toupper(ans) == 'Y') {
			system("cls");
			SalesAddSalesOrder();
		}
		else if (toupper(ans) == 'N') {
			printf("\n\t*************************************\n");
			printf("\t*   Sales Order add successfully!   *\n");
			printf("\t*************************************\n\n");
			printf("\n\t");
			system("pause");
			system("cls");
			salesinfo();
		}
		else {
			printf("\n\tReturn to sales order program\n");
		}
	}
	else {
		printf("\n\t****************************\n");
		printf("\t*   Return to sales menu   *\n");
		printf("\t****************************\n");
		printf("\n\n\t");
		system("pause");
		salesinfo();
	}
}
void SalesFileModify(int qty, char code[]) {
	car c;
	FILE* carMenu;
	FILE* editFile;

	carMenu = fopen("stockinfo.txt", "r");
	editFile = fopen("editfile.txt", "w");

	if (carMenu == NULL || editFile == NULL) {
		printf("Unable to open the file");
		exit(-1);
	}

	while (fscanf(carMenu, "%[^|]|%f|%[^|]|%d|%d-%d-%d|%d|%s\n", c.fileCode, &c.filePrice,
		c.fileName, &c.fileQty, &c.fd.fileDate, &c.fd.fileMonth, &c.fd.fileYear, &c.fileCheckInQty, c.fileCustName) != EOF) {
		if (strcmp(c.fileCode, code) == 0) {
			c.fileQty -= qty;
		}
		fprintf(editFile, "%s|%.2f|%s|%d|%02d-%02d-%04d|%d|%s\n", c.fileCode, c.filePrice,
			c.fileName, c.fileQty, c.fd.fileDate, c.fd.fileMonth, c.fd.fileYear, c.fileCheckInQty, c.fileCustName);
	}

	fclose(carMenu);
	fclose(editFile);
	remove("stockinfo.txt");
	rename("editfile.txt", "stockinfo.txt");
}
void SalesFileDelete(int qty, char code[]) {
	car c;
	FILE* carMenu;
	FILE* editFile;

	carMenu = fopen("stockinfo.txt", "r");
	editFile = fopen("editfile.txt", "w");

	if (carMenu == NULL || editFile == NULL) {
		printf("Unable to open the file");
		exit(-1);
	}

	while (fscanf(carMenu, "%[^|]|%f|%[^|]|%d|%d-%d-%d|%d|%s\n", c.fileCode, &c.filePrice,
		c.fileName, &c.fileQty, &c.fd.fileDate, &c.fd.fileMonth, &c.fd.fileYear, &c.fileCheckInQty, c.fileCustName) != EOF) {
		if (strcmp(c.fileCode, code) == 0) {
			c.fileQty += qty;
		}
		fprintf(editFile, "%s|%.2f|%s|%d|%02d-%02d-%04d|%d|%s\n", c.fileCode, c.filePrice,
			c.fileName, c.fileQty, c.fd.fileDate, c.fd.fileMonth, c.fd.fileYear, c.fileCheckInQty, c.fileCustName);
	}

	fclose(carMenu);
	fclose(editFile);
	remove("stockinfo.txt");
	rename("editfile.txt", "stockinfo.txt");
}
void SalesSearchSalesOrder() {
	FILE* ptr;
	ptr = fopen("SalesInfo.dat", "rb");
	if (ptr == NULL) {
		printf("Unable to open the file");
		exit(-1);
	}

	char searchID[6];
	int found = 0;
	char ans;

	printf("\n\tSearch Sales Order ID: ");
	scanf(" %s", searchID);

	salesOrder s;
	while (fread(&s, sizeof(salesOrder), 1, ptr) == 1) {
		system("cls");
		if (strcmp(searchID, s.salesOrderID) == 0) {
			printf("\n\t+--------------------------------------------------------+\n");
			printf("\t|                        INVOICE                         |\n");
			printf("\t|--------------------------------------------------------|\n");
			printf("\t|   Sales Order ID : %-30s      |\n", s.salesOrderID);
			printf("\t|   Customer Name  : %-30s      |\n", s.name);
			printf("\t|   Contact Number : +60%-30d   |\n", s.contact);
			printf("\t|   Order Date     : %02d-%02d-%04d                          |\n", s.d.date, s.d.month, s.d.year);
			printf("\t+--------------------------------------------------------+\n");
			printf("\t|                                                        |\n");
			printf("\t|                 Sales Order Details:                   |\n");
			printf("\t|                                                        |\n");
			printf("\t+--------------------------------------------------------+\n");
			printf("\t| Car Code  | Item Name            | Price        | Qty  |\n");
			printf("\t+--------------------------------------------------------+\n");

			for (int i = 0; i < s.numItem; i++) {
				printf("\t| %-8s  | %-20s | RM %9.2f | %-3d  |\n", s.items[i].itemCode, s.items[i].itemName, s.items[i].price, s.items[i].qtyOrdered);
			}
			printf("\t+--------------------------------------------------------+\n");
			printf("\t|                                                        |\n");
			SalesCalculateTotalPrice(s);
			printf("\t+--------------------------------------------------------+\n");
			found = 1;

			printf("\n\tFind another sales order? (Y=Yes, N=No): ");
			scanf(" %c", &ans);
			printf("\n\n\t");
			if (toupper(ans) == 'Y') {
				system("cls");
				SalesSearchSalesOrder();
			}
			else if (toupper(ans) == 'N') {
				system("pause");
				system("cls");
				salesinfo();
			}

		}
	}
	if (!found) {
		printf("\n\n\t*****************************\n");
		printf("\t*   Sales order not found   *\n");
		printf("\t*****************************");
		printf("\n\n\t");
		system("pause");
		system("cls");
	}

	fclose(ptr);
	salesinfo();
}
void SalesModifySalesOrder() {
	char searchID[6], ans;
	int found = 0, numOrders = 0;

	salesOrder s[100];
	FILE* ptr;
	ptr = fopen("SalesInfo.dat", "rb");
	if (ptr == NULL) {
		printf("Unable to open the file");
		exit(-1);
	}

	while (fread(&s[numOrders], sizeof(salesOrder), 1, ptr) == 1) {
		numOrders++;
	}
	fclose(ptr);

	printf("\n\tEnter Sales Order ID to modify: ");
	scanf(" %s", searchID);

	for (int i = 0; i < numOrders; ++i) {
		if (strcmp(searchID, s[i].salesOrderID) == 0) {
			found = 1;
			system("cls");
			printf("\n\n\t+--------------------------------------------------------+\n");
			printf("\t|                        INVOICE                         |\n");
			printf("\t|--------------------------------------------------------|\n");
			printf("\t|   Sales Order ID : %-30s      |\n", s[i].salesOrderID);
			printf("\t|   Customer Name  : %-30s      |\n", s[i].name);
			printf("\t|   Contact Number : +60%-30d   |\n", s[i].contact);
			printf("\t|   Order Date     : %02d-%02d-%04d                          |\n", s[i].d.date, s[i].d.month, s[i].d.year);
			printf("\t+--------------------------------------------------------+\n");
			printf("\t|                                                        |\n");
			printf("\t|                 Sales Order Details:                   |\n");
			printf("\t|                                                        |\n");
			printf("\t+--------------------------------------------------------+\n");
			printf("\t| Car Code  | Item Name            | Price        | Qty  |\n");
			printf("\t+--------------------------------------------------------+\n");
			for (int j = 0; j < s[i].numItem; j++) {
				printf("\t| %-8s  | %-20s | RM %9.2f | %-3d  |\n", s[i].items[j].itemCode, s[i].items[j].itemName, s[i].items[j].price, s[i].items[j].qtyOrdered);
			}
			printf("\t+--------------------------------------------------------+\n");
			printf("\t|                                                        |\n");
			SalesCalculateTotalPrice(s[i]);
			printf("\t+--------------------------------------------------------+\n\n");


			printf("\tModify Customer name?(Y=Yes, N=No): ");
			scanf(" %c", &ans);
			if (toupper(ans) == 'Y') {
				printf("\tEnter new Customer Name: ");
				scanf(" %[^\n]", s[i].name);
			}

			printf("\n\tModify contact number?(Y=Yes, N=No): ");
			scanf(" %c", &ans);
			if (toupper(ans) == 'Y') {
				printf("\tEnter new contact number: ");
				scanf(" %d", &s[i].contact);
			}


			printf("\n\tModify order date?(Y=Yes, N=No): ");
			scanf(" %c", &ans);
			if (toupper(ans) == 'Y') {
				printf("\tEnter new Order Date (dd-mm-yyyy): ");
				scanf(" %d-%d-%d", &s[i].d.date, &s[i].d.month, &s[i].d.year);
			}

			printf("\n\tModify car quantity?(Y=Yes, N=No): ");
			scanf(" %c", &ans);
			if (toupper(ans) == 'Y') {
				for (int j = 0; j < s[i].numItem; j++) {
					int previous_qty = s[i].items[j].qtyOrdered;
					printf("\tEnter new quantity for Car Code %s: ", s[i].items[j].itemCode);
					scanf(" %d", &s[i].items[j].qtyOrdered);
					SalesFileModify(s[i].items[j].qtyOrdered - previous_qty, s[i].items[j].itemCode);
				}
			}
			ptr = fopen("SalesInfo.dat", "wb");
			for (int k = 0; k < numOrders; ++k) {
				if (s[k].name[0] == '\0')break;
				fwrite(&s[k], sizeof(salesOrder), 1, ptr);
			}
			printf("\n\tSales Order modified successfully!\n\n");
			fclose(ptr);
			system("pause");
			system("cls");
			break;
		}
		if (found) break;
	}

	if (!found) {
		printf("\n\t*****************************\n");
		printf("\t*   Sales order not found   *\n");
		printf("\t*****************************");
		printf("\n\n\t");
		system("pause");
		system("cls");
	}
}
void SalesDeleteSalesOrder() {

	char searchID[6], ans;
	int found = 0, delCount = 0, count = 0, updCount = 0;

	salesOrder s;

	FILE* ptr;
	ptr = fopen("SalesInfo.dat", "rb");
	if (ptr == NULL) {
		printf("Unable to open the file\n");
		exit(-1);
	}

	while (fread(&s, sizeof(salesOrder), 1, ptr)) {
		count++;
	}
	fclose(ptr);

	printf("\n\tEnter Sales Order ID to delete: ");
	scanf("%s", searchID);

	ptr = fopen("SalesInfo.dat", "rb");
	FILE* delete = fopen("deleteFile.dat", "wb");
	if (ptr == NULL || delete == NULL) {
		printf("Unable to open the file\n");
		exit(-1);
	}

	found = 0;
	while (fread(&s, sizeof(salesOrder), 1, ptr)) {
		if (strcmp(searchID, s.salesOrderID) == 0) {
			found = 1;
			system("cls");
			printf("\t+--------------------------------------------------------+\n");
			printf("\t|                        INVOICE                         |\n");
			printf("\t|--------------------------------------------------------|\n");
			printf("\t|   Sales Order ID : %-30s      |\n", s.salesOrderID);
			printf("\t|   Customer Name  : %-30s      |\n", s.name);
			printf("\t|   Contact Number : +60%-30d   |\n", s.contact);
			printf("\t|   Order Date     : %02d-%02d-%04d                          |\n", s.d.date, s.d.month, s.d.year);
			printf("\t+--------------------------------------------------------+\n");
			printf("\t|                                                        |\n");
			printf("\t|                 Sales Order Details:                   |\n");
			printf("\t|                                                        |\n");
			printf("\t+--------------------------------------------------------+\n");
			printf("\t| Car Code  | Item Name            | Price        | Qty  |\n");
			printf("\t+--------------------------------------------------------+\n");

			for (int j = 0; j < s.numItem; j++) {
				printf("\t| %-8s  | %-20s | RM %9.2f | %-3d  |\n", s.items[j].itemCode, s.items[j].itemName, s.items[j].price, s.items[j].qtyOrdered);

			}
			printf("\t+--------------------------------------------------------+\n");
			printf("\t|                                                        |\n");
			SalesCalculateTotalPrice(s);
			printf("\t+--------------------------------------------------------+\n");

			printf("\n\tConfirm to delete? (Y=Yes, N=No): ");
			rewind(stdin);
			scanf(" %c", &ans);

			if (toupper(ans) == 'Y') {
				delCount++;
				for (int j = 0; j < s.numItem; j++) {
					SalesFileDelete(s.items[j].qtyOrdered, s.items[j].itemCode);
				}
			}
			else if (toupper(ans) == 'N') {
				fwrite(&s, sizeof(salesOrder), 1, delete);
			}
			else {
				fwrite(&s, sizeof(salesOrder), 1, delete);
			}
		}
		else {
			fwrite(&s, sizeof(salesOrder), 1, delete);
		}
	}
	fclose(ptr);
	fclose(delete);

	if (!found) {
		printf("\n\t*****************************\n");
		printf("\t*   Sales order not found   *\n");
		printf("\t*****************************");
		printf("\n\n\t");
		system("pause");
		system("cls");
	}
	else {
		ptr = fopen("SalesInfo.dat", "wb");
		delete = fopen("deleteFile.dat", "rb");
		if (ptr == NULL || delete == NULL) {
			printf("Unable to open the file\n");
			exit(-1);
		}
		while (fread(&s, sizeof(salesOrder), 1, delete)) {
			fwrite(&s, sizeof(salesOrder), 1, ptr);
			updCount++;
		}
		fclose(ptr);
		fclose(delete);
		remove("deleteFile.dat");
		printf("\n\t*****************************\n");
		printf("\t*   %d Record(s) deleted    *\n", delCount);
		printf("\t*****************************");
		printf("\n\n\t");
		system("pause");
		system("cls");
		salesinfo();
	}
}
void SalesDisplaySalesOrder() {

	salesOrder s;
	day d;

	int i = 0, found = 0, count = 0;
	FILE* fp;
	fp = fopen("SalesInfo.dat", "rb");
	if (fp == NULL) {
		printf("Unable to open the file");
		exit(-1);
	}
	system("cls");
	printf("\n\n\t****************************************************************\n");
	printf("\t*                                                              *\n");
	printf("\t*   Enter the date to show the sales order record of the day   *\n");
	printf("\t*                                                              *\n");
	printf("\t****************************************************************\n");
	printf("\n\tEnter the date (dd-mm-yyyy): ");
	scanf(" %d-%d-%d", &d.date, &d.month, &d.year);

	system("cls");
	while (fread(&s, sizeof(s), 1, fp) == 1) {
		if (s.d.date == d.date && s.d.month == d.month && s.d.year == d.year) {
			found = 1;
			count++;
			printf("\n\t+--------------------------------------------------------+\n");
			printf("\t|                  Sales Order Record %d                  |\n", count);
			printf("\t|--------------------------------------------------------|\n");
			printf("\t|   Sales Order ID : %-30s      |\n", s.salesOrderID);
			printf("\t|   Customer Name  : %-30s      |\n", s.name);
			printf("\t|   Contact Number : +60%-30d   |\n", s.contact);
			printf("\t|   Order Date     : %02d-%02d-%04d                          |\n", s.d.date, s.d.month, s.d.year);
			printf("\t+--------------------------------------------------------+\n");
			printf("\t|                                                        |\n");
			printf("\t|                 Sales Order Details:                   |\n");
			printf("\t|                                                        |\n");
			printf("\t+--------------------------------------------------------+\n");
			printf("\t| Car Code  | Item Name            | Price        | Qty  |\n");
			printf("\t+--------------------------------------------------------+\n");

			for (int i = 0; i < s.numItem; i++) {
				printf("\t| %-8s  | %-20s | RM %9.2f | %-3d  |\n", s.items[i].itemCode, s.items[i].itemName, s.items[i].price, s.items[i].qtyOrdered);
			}
			printf("\t+--------------------------------------------------------+\n");
			printf("\t|                                                        |\n");
			SalesCalculateTotalPrice(s);
			printf("\t+--------------------------------------------------------+\n");
			printf("\n\n");
		}
	}

	if (!found) {
		printf("\n\n\t************************************\n");
		printf("\t*   No sales order on %02d-%02d-%04d!  *\n", d.date, d.month, d.year);
		printf("\t************************************\n");
	}
	printf("\n\t*********************************************\n");
	printf("\t*   %d Sales Order Record found %02d-%02d-%04d!  *\n", count, d.date, d.month, d.year);
	printf("\t*********************************************");
	printf("\n\n\t");
	system("pause");
	system("cls");
	salesinfo();

	fclose(fp);
}
void SalesPrintSalesOrder() {

	day d;
	salesOrder s;

	int found = 0, reportCount = 0;
	s.numItem = 0;

	FILE* ptr;
	ptr = fopen("SalesInfo.dat", "rb");
	if (ptr == NULL) {
		printf("Unable to open the file");
		exit(-1);
	}

	printf("\n\t**********************************************************\n");
	printf("\t*                     SALES REPORT                       *\n");
	printf("\t**********************************************************\n\n");

	while (fread(&s, sizeof(salesOrder), 1, ptr)) {
		salesOrder s2;
		if (memcmp(&s2, &s, sizeof(s)) == 0)  continue;
		reportCount++;
		printf("\t+--------------------------------------------------------+\n");
		printf("\t|                   Sales Report %d                       |\n", reportCount);
		printf("\t+--------------------------------------------------------+\n");
		printf("\t| Sales Order ID : %-30s        |\n", s.salesOrderID);
		printf("\t| Customer Name  : %-30s        |\n", s.name);
		printf("\t| Contact Number : +60%-30d     |\n", s.contact);
		printf("\t| Order Date     : %02d-%02d-%04d                            |\n", s.d.date, s.d.month, s.d.year);
		printf("\t+--------------------------------------------------------+\n");
		printf("\t|                   Sales Order Details                  |\n");
		printf("\t+--------------------------------------------------------+\n");
		printf("\t| Car Code  | Item Name            | Price        | Qty  |\n");
		printf("\t+--------------------------------------------------------+\n");
		for (int i = 0; i < s.numItem; i++) {
			printf("\t| %-8s  | %-20s | RM %9.2f | %-3d  |\n", s.items[i].itemCode, s.items[i].itemName, s.items[i].price, s.items[i].qtyOrdered);
		}
		printf("\t+--------------------------------------------------------+\n");
		printf("\t|                                                        |\n");
		SalesCalculateTotalPrice(s);
		printf("\t+--------------------------------------------------------+\n");
		printf("\n\n");
		found = 1;
		printf("\tTotal sales report: %d record(s)\n\n", reportCount);
	}
	fclose(ptr);

	if (!found) {
		printf("\n\n\t\t**************************************\n");
		printf("\t\t*   No sales order are created yet   *\n");
		printf("\t\t**************************************\n");
		printf("\n\n\t\t");
		system("pause");
		system("cls");
		salesinfo();
	}
	system("pause");
	system("cls");
	salesinfo();

}
void SalesCalculateTotalPrice(salesOrder s) {

	float total = 0;
	for (int i = 0; i < s.numItem; i++) {
		total += s.items[i].price * s.items[i].qtyOrdered;
	}
	printf("\t| Total Price: RM%9.2f                               |\n", total);
}

//STOCK INFORMATION MODULE
void stockinfo() {

	int selection;

	printf("\n======================================================\n");
	printf("\t\t STOCK INFORMATION\n");
	printf("======================================================\n");
	printf("\t1. Display stock information\n");
	printf("\t2. Search stock information\n");
	printf("\t3. Modify stock information\n");
	printf("\t4. Add stock information \n");
	printf("\t5. Calculate stock information\n");
	printf("\t6. Delete stock information\n");
	printf("\t7. Back to menu\n");
	printf("\t8. Exit program\n");
	printf("======================================================\n");
	printf("\tEnter your selection :");
	rewind(stdin);
	scanf("%d", &selection);
	rewind(stdin);


	do {
		switch (selection) {
		case 1:StockDisplay(); break;
		case 2:StockSearch(); break;
		case 3:StockModify(); break;
		case 4:StockAdd(); break;
		case 5:StockCalculate(); break;
		case 6:StockDeleteInfo(); break;
		case 7:
			system("cls");
			printf("Logged out successfully !\n");
			menu();
			break;
		case 8:exit(0); break;
		default:printf("invalid\n");
		}

		printf("\tEnter your selection :");
		scanf("%d", &selection);
		rewind(stdin);


	} while (selection != 7);
}
void StockDisplay() {
	FILE* fp;
	fp = fopen("stockinfo.txt", "r");

	Stock stock;
	int count =0;

	if (fp == NULL) {
		printf("file open unsuccessfully...");
		return;
	}

	//header
	printf("\n");
	printf("\t\t\t\t\tStock Information Record\n");
	printf("======================================================================================================================\n");
	printf("Item code  Item price  Item Ddescription    Quantity   Date item-in   Quantity reserved   Customer(RESERVED)\n");
	printf("======================================================================================================================\n");

	//read from file store to struct
	while (fscanf(fp, "%[^|]|%lf|%[^|]|%d|%d-%d-%d|%d|%s\n",
		stock.itemCode, &stock.itemPrice, stock.itemDesc, &stock.qty, &stock.inDate.day, &stock.inDate.month, &stock.inDate.year,
		&stock.reserqty, stock.cusName) != EOF) {

		//display data from struct
		printf(" %-5s \t  %-2.2lf \t %-20s \t %-5d \t %02d-%02d-%04d \t %-14d \t %s \n",
			stock.itemCode, stock.itemPrice, stock.itemDesc, stock.qty, stock.inDate.day, stock.inDate.month, stock.inDate.year,
			stock.reserqty, stock.cusName);
		count++;

	}
	printf("\n\t\t\t\t\t %d Record Listed\n",count);
	printf("\n");
	fclose(fp);
	stockinfo();
}
void StockSearch() {

	FILE* fp;
	fp = fopen("stockinfo.txt", "r");

	Stock stock[100];
	char confirm, icode[6], input;
	int i = 0, data = 0;

	if (fp == NULL) {
		printf("file open unsuccessfully...");
		return;
	}

	//read information from file
	while (fscanf(fp, "%[^|]|%lf|%[^|]|%d|%d-%d-%d|%d|%s\n",
		stock[i].itemCode, &stock[i].itemPrice, stock[i].itemDesc, &stock[i].qty, &stock[i].inDate.day,
		&stock[i].inDate.month, &stock[i].inDate.year, &stock[i].reserqty, stock[i].cusName) != EOF) {
		data++;
		i++;
	}

	do {
		printf("======================================================\n");
		printf("Enter the item code to search for details: ");
		rewind(stdin);
		scanf("%s", &icode);

		int found = 0; //check if a record is found

		for (int i = 0; i <= data; i++) {

			//compare user input with itemcode in file
			if (strcmp(stock[i].itemCode, icode) == 0) {
				printf("======================================================\n");
				printf("Item code               : %s\n", stock[i].itemCode);
				printf("Item price              : %.2lf\n", stock[i].itemPrice);
				printf("Item description        : %s\n", stock[i].itemDesc);
				printf("Item quantity           : %d\n", stock[i].qty);
				printf("Item date-in            : %02d-%02d-%04d\n", stock[i].inDate.day, stock[i].inDate.month, stock[i].inDate.year);
				printf("Item quantity reserved  : %d\n", stock[i].reserqty);
				printf("Customer name(reserved) : %s\n", stock[i].cusName);

				found = 1; // set it as found
				break; // exit
			}
		}

		if (!found) {  //if record not found
			printf("\nThere is no %s record in the stock information file...", icode);
		}

		//ask for second time search
		printf("\nSearch Stock Information Record Again? (Y/y = Yes N/n = No) :");
		rewind(stdin);
		scanf("%c", &confirm);

		//input validation checking
		input = StockValidate(confirm);

	} while (toupper(input) == 'Y');

	fclose(fp);
	stockinfo();
}
void StockAdd() {

	Stock stock;
	char ans, confirm, input;
	int count = 0;

	do {
		printf("============================================================\n");
		printf("Item Code :");
		rewind(stdin);
		scanf("%s", stock.itemCode);

		//check itemcode input because it cant be the same itemcode inside the file
		FILE* fp2;
		fp2 = fopen("stockinfo.txt", "r");
		Stock tstock[100];
		int i = 0, tcount = 0;

		if (fp2 == NULL) {
			printf("file open unsuccessfully...");
			return;
		}

		while (fscanf(fp2, "%[^|]|%lf|%[^|]|%d|%d-%d-%d|%d|%s\n",
			tstock[i].itemCode, &tstock[i].itemPrice, tstock[i].itemDesc, &tstock[i].qty, &tstock[i].inDate.day, &tstock[i].inDate.month, &tstock[i].inDate.year, &tstock[i].reserqty, tstock[i].cusName) != EOF) {
			i++;
		}

		tcount = i;
		fclose(fp2);

		for (i = 0; i < tcount; i++) {
			while (strcmp(tstock[i].itemCode, stock.itemCode) == 0) {
				printf("\t The Item Code Have Already Exist Please Try Again ~\n\n");
				printf("Item Code :");
				rewind(stdin);
				scanf("%s", stock.itemCode);
			}
		}

		//continue to ask for new record information
		printf("Item Price :");
		scanf("%lf", &stock.itemPrice);

		printf("Item Description :");
		rewind(stdin);
		scanf("%[^\n]", stock.itemDesc);

		printf("Item Quantity :");
		scanf("%d", &stock.qty);

		//check for quantity validation
		while (stock.qty < 0) {
			printf("\tStock Quantity Cannot Less Than 0, Please Try Again.\n");
			printf("Item Quantity: ");
			scanf("%d", &stock.qty);
		}

		printf("Item Date-In (DD MM YYYY):");
		scanf("%d %d %d", &stock.inDate.day, &stock.inDate.month, &stock.inDate.year);

		printf("Item Reserved Quantity :");
		scanf("%d", &stock.reserqty);

		//check for reserved qty cant be larger than qty available
		while (stock.reserqty > stock.qty && stock.reserqty < 0) {
			printf("Item Reserved Quantity Cannot More Than Item Quantity (%d) or Less Than 0: ", stock.qty);
			scanf("%d", &stock.reserqty);
		}

		printf("Customer Name (Reserved) :");
		rewind(stdin);
		scanf("%[^\n]", stock.cusName);

		printf("============================================================\n");
		printf("Confirm to add record? (Y/y = yes N/n = no) :");
		rewind(stdin);
		scanf("%c", &confirm);

		//input validation checking
		input = StockValidate(confirm);

		FILE* fp1;
		fp1 = fopen("stockinfo.txt", "a");

		if (fp1 == NULL) {
			printf("file open unsuccessfully...");
			return;
		}

		//if yes record write to the file
		if (toupper(input) == 'Y') {
			count++;
			fprintf(fp1, "%s|%.2lf|%s|%d|%02d-%02d-%04d|%d|%s\n",
				stock.itemCode, stock.itemPrice, stock.itemDesc, stock.qty, stock.inDate.day, stock.inDate.month,
				stock.inDate.year, stock.reserqty, stock.cusName);
			printf("\n\tRecord added!\n\n");
			printf("====================================================\n");
		}
		fclose(fp1);

		//ask for second time add record 
		printf("Do you want to add record again? (Y/y = yes N/n = no) :");
		rewind(stdin);
		scanf("%c", &ans);

		input = StockValidate(ans);

	} while (toupper(input) == 'Y');

	printf("\n\t%d Record Successful Added\n\n", count);

	stockinfo();
}
void StockModify()
{

	Stock stock[100];
	int i = 0, tcount = 0, count = 0, found = 0, upqty, upd, upm, upy, upreserqty;
	char ans, icode[6], upcusName[50], upcode[10], updes[50], confirm, selection, input;
	double upprice;

	FILE* fp;
	fp = fopen("stockinfo.txt", "r");

	if (fp == NULL)
	{
		printf("file open unsucessfully\n");
		return;
	}

	while (fscanf(fp, "%[^|]|%lf|%[^|]|%d|%d-%d-%d|%d|%s\n",
		stock[i].itemCode, &stock[i].itemPrice, stock[i].itemDesc, &stock[i].qty, &stock[i].inDate.day,
		&stock[i].inDate.month, &stock[i].inDate.year, &stock[i].reserqty, stock[i].cusName) != EOF)
	{
		i++;
	}
	tcount = i;
	fclose(fp);

	do
	{
		printf("Enter the item code that you want to modify:");
		rewind(stdin);
		scanf("%[^\n]", icode);

		for (i = 0; i < tcount; i++) {
			if (strcmp(icode, stock[i].itemCode) == 0) {
				found = 1;

				//header
				printf("\n");
				printf("===============================================================================================================\n");
				printf("Item code  Item price  Item Ddescription    Quantity   Date item-in   Quantity reserved   Customer(RESERVED)\n");
				printf("===============================================================================================================\n");
				printf(" %-5s \t  %-2.2lf \t %-20s \t %-5d \t %02d-%02d-%04d \t %-14d \t %s \n",
					stock[i].itemCode, stock[i].itemPrice, stock[i].itemDesc, stock[i].qty, stock[i].inDate.day,
					stock[i].inDate.month, stock[i].inDate.year, stock[i].reserqty, stock[i].cusName);
				printf("===============================================================================================================\n");
				//ask for which information want to modify
				printf("\n\tINFORMATION WANT TO CHANGE	:\n");
				printf("=====================================================\n");
				printf("\t1. Item Code \n");
				printf("\t2. Item Price \n");
				printf("\t3. Item Description\n");
				printf("\t4. Item Quantity \n");
				printf("\t5. Item Check-in Date \n");
				printf("\t6. Item Reserved Quantity \n");
				printf("\t7. Reserved Customer Name \n");
				printf("=====================================================\n");
				printf("\tEnter your selection :");
				rewind(stdin);
				scanf("%d", &selection);
				printf("=====================================================\n");

				while (selection != 1 && selection != 2 && selection != 3 && selection != 4 && selection != 5 && selection != 6 && selection != 7) {
					printf("\tInvalid input, Please enter again: ");
					rewind(stdin);
					scanf("%c", &selection);
				}

				switch (selection) {
				case 1: {

					char* newCode;
					newCode = StockModifyItemCode();
					strcpy(stock[i].itemCode, newCode);
					count++;

					//display updated record
					printf("\nUpdated record:\n\n");
					printf("Item code  Item price  Item Ddescription    Quantity   Date item-in   Quantity reserved   Customer(RESERVED)\n");
					printf("===============================================================================================================\n");
					printf(" %-5s \t  %-2.2lf \t %-20s \t %-5d \t %02d-%02d-%04d \t %-14d \t %s \n",
						stock[i].itemCode, stock[i].itemPrice, stock[i].itemDesc, stock[i].qty, stock[i].inDate.day,
						stock[i].inDate.month, stock[i].inDate.year, stock[i].reserqty, stock[i].cusName);
					printf("===============================================================================================================\n");
					break;
				}

				case 2: {
					double price = stock[i].itemPrice;
					stock[i].itemPrice = StockModifyItemPrice(price);

					//display updated record
					printf("Updated record:\n");
					printf("Item code  Item price  Item Ddescription    Quantity   Date item-in   Quantity reserved   Customer(RESERVED)\n");
					printf("===============================================================================================================\n");
					printf(" %-5s \t  %-2.2lf \t %-20s \t %-5d \t %02d-%02d-%04d \t %-14d \t %s \n",
						stock[i].itemCode, stock[i].itemPrice, stock[i].itemDesc, stock[i].qty, stock[i].inDate.day,
						stock[i].inDate.month, stock[i].inDate.year, stock[i].reserqty, stock[i].cusName);
					printf("===============================================================================================================\n");
					break;
				}
				case 3: {
					char newDesc[50];
					newDesc == StockModifyItemDesc();
					strcpy(stock[i].itemDesc, newDesc);
					count++;

					//display updated record
					printf("Updated record:\n");
					printf("Item code  Item price  Item Ddescription    Quantity   Date item-in   Quantity reserved   Customer(RESERVED)\n");
					printf("===============================================================================================================\n");
					printf(" %-5s \t  %-2.2lf \t %-20s \t %-5d \t %02d-%02d-%04d \t %-14d \t %s \n",
						stock[i].itemCode, stock[i].itemPrice, stock[i].itemDesc, stock[i].qty, stock[i].inDate.day,
						stock[i].inDate.month, stock[i].inDate.year, stock[i].reserqty, stock[i].cusName);
					printf("===============================================================================================================\n");
					break;
				}
				case 4: {
					int newqty = stock[i].qty;
					stock[i].qty = StockModifyItemQty(newqty);
					count++;

					//display updated record
					printf("Updated record:\n");
					printf("Item code  Item price  Item Ddescription    Quantity   Date item-in   Quantity reserved   Customer(RESERVED)\n");
					printf("===============================================================================================================\n");
					printf(" %-5s \t  %-2.2lf \t %-20s \t %-5d \t %02d-%02d-%04d \t %-14d \t %s \n",
						stock[i].itemCode, stock[i].itemPrice, stock[i].itemDesc, stock[i].qty, stock[i].inDate.day,
						stock[i].inDate.month, stock[i].inDate.year, stock[i].reserqty, stock[i].cusName);
					printf("===============================================================================================================\n");
					break;
				}
				case 5: {
					int d, m, y, oldd, oldm, oldy;

					oldd = stock[i].inDate.day;
					oldm = stock[i].inDate.month;
					oldy = stock[i].inDate.year;
					StockModifyDate(oldd, oldm, oldy, &d, &m, &y);
					stock[i].inDate.day = d;
					stock[i].inDate.month = m;
					stock[i].inDate.year = y;
					count++;

					//display updated record
					printf("Updated record:\n");
					printf("Item code  Item price  Item Ddescription    Quantity   Date item-in   Quantity reserved   Customer(RESERVED)\n");
					printf("===============================================================================================================\n");
					printf(" %-5s \t  %-2.2lf \t %-20s \t %-5d \t %02d-%02d-%04d \t %-14d \t %s \n",
						stock[i].itemCode, stock[i].itemPrice, stock[i].itemDesc, stock[i].qty, stock[i].inDate.day,
						stock[i].inDate.month, stock[i].inDate.year, stock[i].reserqty, stock[i].cusName);
					printf("===============================================================================================================\n");
					break;
				}
				case 6: {
					int rqty;
					rqty = stock[i].qty;
					stock[i].reserqty = StockModifyReservedQty(rqty);
					count++;

					//display updated record
					printf("Updated record:\n");
					printf("Item code  Item price  Item Ddescription    Quantity   Date item-in   Quantity reserved   Customer(RESERVED)\n");
					printf("===============================================================================================================\n");
					printf(" %-5s \t  %-2.2lf \t %-20s \t %-5d \t %02d-%02d-%04d \t %-14d \t %s \n",
						stock[i].itemCode, stock[i].itemPrice, stock[i].itemDesc, stock[i].qty, stock[i].inDate.day,
						stock[i].inDate.month, stock[i].inDate.year, stock[i].reserqty, stock[i].cusName);
					printf("===============================================================================================================\n");
					break;
				}
				case 7: {
					char* newcust;
					newcust = StockModifyCustName();
					strcpy(stock[i].cusName, newcust);
					count++;

					//display updated record
					printf("\n Updated record:\n");
					printf("Item code  Item price  Item Ddescription    Quantity   Date item-in   Quantity reserved   Customer(RESERVED)\n");
					printf("===============================================================================================================\n");
					printf(" %-5s \t  %-2.2lf \t %-20s \t %-5d \t %02d-%02d-%04d \t %-14d \t %s \n",
						stock[i].itemCode, stock[i].itemPrice, stock[i].itemDesc, stock[i].qty, stock[i].inDate.day,
						stock[i].inDate.month, stock[i].inDate.year, stock[i].reserqty, stock[i].cusName);
					printf("===============================================================================================================\n");
					break;
				}
				default:printf("Invalid\n");
				}
			}
		}

		if (found != 1)
		{
			printf("There is no %s record in the stock information file...", icode);
		}

		//ask for second time 
		printf("\nModify Stock Information Record Again? (Y/y = Yes N/n = No) :");
		rewind(stdin);
		scanf("%c", &ans);


		input = StockValidate(ans);

	} while (toupper(input) == 'Y');

	fp = fopen("stockinfo.txt", "w");

	for (i = 0; i < tcount; i++) {
		fprintf(fp, "%s|%.2lf|%s|%d|%02d-%02d-%04d|%d|%s\n",
			stock[i].itemCode, stock[i].itemPrice, stock[i].itemDesc, stock[i].qty, stock[i].inDate.day,
			stock[i].inDate.month, stock[i].inDate.year, stock[i].reserqty, stock[i].cusName);
	}

	//display how many record modified
	printf("\n\t %d Record modified....\n", count);

	fclose(fp);
	stockinfo();
}
char* StockModifyItemCode() {

	char upcode[10], confirm, input;
	printf("Item Code :");
	rewind(stdin);
	scanf("%[^\n]", upcode);

	FILE* fp2 = fopen("stockinfo.txt", "r");
	Stock tstock[100];
	int i = 0, tcount = 0;

	if (fp2 == NULL) {
		printf("file open unsuccessfully...");
		return;
	}

	while (fscanf(fp2, "%[^|]|%lf|%[^|]|%d|%d-%d-%d|%d|%s\n",
		tstock[i].itemCode, &tstock[i].itemPrice, tstock[i].itemDesc, &tstock[i].qty, &tstock[i].inDate.day, &tstock[i].inDate.month, &tstock[i].inDate.year, &tstock[i].reserqty, tstock[i].cusName) != EOF) {
		i++;
	}

	tcount = i;
	fclose(fp2);

	for (i = 0; i < tcount; i++) {
		while (strcmp(tstock[i].itemCode, upcode) == 0) {
			printf("\t The Item Code Have Already Exist Please Try Again ~\n\n");
			printf("Item Code :");
			rewind(stdin);
			scanf("%s", upcode);
		}
	}

	printf("Confirm to modify item code? (Y/y = yes N/n = no) :");
	rewind(stdin);
	scanf(" %c", &confirm);
	printf("====================================================\n");
	input = StockValidate(confirm);

	if (toupper(input) == 'Y')
	{
		return upcode;
	}
	else {
		printf("No information edited...\n");
		stockinfo();// return an empty string
	}
}
double StockModifyItemPrice(double price) {

	double upprice;
	char confirm, input;
	printf("Item Price :");
	rewind(stdin);
	scanf("%lf", &upprice);

	printf("====================================================\n");
	printf("Confirm to modify item price? (Y/y = yes N/n = no) :");
	rewind(stdin);
	scanf(" %c", &confirm);

	input = StockValidate(confirm);

	if (toupper(input) == 'Y')
	{
		return upprice;
	}
	else {
		printf("No information edited...\n");
		stockinfo();
	}
}
char* StockModifyItemDesc() {
	char updes[50], confirm, input;
	printf("Item Description :");
	rewind(stdin);
	scanf("%[^\n]", &updes);

	printf("====================================================\n");
	printf("Confirm to modify item description? (Y/y = yes N/n = no) :");
	rewind(stdin);
	scanf("%c", &confirm);

	input = StockValidate(confirm);

	if (toupper(input) == 'Y')
	{
		return updes;
	}
	else {
		printf("No information edited...\n"); 	stockinfo();
	}
}
int StockModifyItemQty(int qty) {
	int upqty;
	char confirm, input;
	printf("Item Quantity :");
	rewind(stdin);
	scanf("%d", &upqty);

	printf("====================================================\n");
	printf("Confirm to modify item quantity? (Y/y = yes N/n = no) :");
	rewind(stdin);
	scanf("%c", &confirm);

	input = StockValidate(confirm);

	if (toupper(input) == 'Y')
	{
		return upqty;
	}
	else {
		printf("No information edited...\n"); 	stockinfo();
	}
}
void StockModifyDate(int oldd, int oldm, int oldy, int* d, int* m, int* y) {
	int upd, upm, upy;
	char confirm, input;
	printf("Item date-in (DD MM YYYY) :");
	scanf("%d %d %d", &upd, &upm, &upy);

	printf("====================================================\n");
	printf("Confirm to modify item check-in date? (Y/y = yes N/n = no) :");
	rewind(stdin);
	scanf("%c", &confirm);

	input = StockValidate(confirm);

	if (toupper(input) == 'Y')
	{
		*d = upd;
		*m = upm;
		*y = upy;
	}
	else {
		*d = oldd;
		*m = oldm;
		*y = oldy;
		printf("No information edited...\n"); 	stockinfo();
	}
}
int StockModifyReservedQty(int rqty) {

	int upreserqty;
	char confirm, input;
	printf("Item Reserved Quantity :");
	scanf("%d", &upreserqty);

	while (rqty < upreserqty) {
		printf("Item reserved quantity cannot more than item quantity (%d): ", rqty);
		scanf("%d", &upreserqty);
	}

	printf("====================================================\n");
	printf("Confirm to modify item reserved quantity? (Y/y = yes N/n = no) :");
	rewind(stdin);
	scanf("%c", &confirm);

	input = StockValidate(confirm);

	if (toupper(input) == 'Y')
	{
		return upreserqty;
	}
	else {
		printf("No information edited...\n");	stockinfo();
	}
}
char* StockModifyCustName() {
	char upcusName[100], confirm, input;
	printf("Customer Name (Reserved) :");
	rewind(stdin);
	scanf("%[^\n]", upcusName);

	printf("====================================================\n");
	printf("Confirm to modify reserved customer name? (Y/y = yes N/n = no) :");
	rewind(stdin);
	scanf("%c", &confirm);

	input = StockValidate(confirm);

	if (toupper(input) == 'Y')
	{
		return upcusName;
	}
	else {
		printf("No information edited...\n"); 	stockinfo();
	};
}
void StockDeleteInfo() {

	char code[10], confirm, input;

	printf("====================================================\n");
	printf("Enter Item Code To Delete: ");
	scanf("%s", code);

	// Open input and output files
	FILE* fp = fopen("stockinfo.txt", "r");
	FILE* tfp = fopen("temp.txt", "w");

	if (fp == NULL || tfp == NULL) {
		printf("File open unsuccessful.\n");
		return;
	}

	Stock stock;
	int found = 0;

	printf("====================================================\n");
	printf("Confirm To Delete Record? (Y/y = yes N/n = no) :");
	rewind(stdin);
	scanf(" %c", &confirm);

	input = StockValidate(confirm);
	if (toupper(input) == 'Y') {
		//find the row of data that match the item code
		while (fscanf(fp, "%[^|]|%lf|%[^|]|%d|%d-%d-%d|%d|%s\n", stock.itemCode, &stock.itemPrice, stock.itemDesc, &stock.qty,
			&stock.inDate.day, &stock.inDate.month, &stock.inDate.year, &stock.reserqty, stock.cusName) != EOF) {
			if (strcmp(stock.itemCode, code) == 0) {
				found = 1;
				continue;
			}
			//print to temp file
			fprintf(tfp, "%s|%.2lf|%s|%d|%02d-%02d-%04d|%d|%s\n",
				stock.itemCode, stock.itemPrice, stock.itemDesc, stock.qty, stock.inDate.day,
				stock.inDate.month, stock.inDate.year, stock.reserqty, stock.cusName);
		}
		fclose(fp);
		fclose(tfp);

		//replace the temp file as original file
		if (remove("stockinfo.txt") == 0 && rename("temp.txt", "stockinfo.txt") == 0) {
			if (found) {
				printf("\n\tRecord %s Deleted Successfully.\n\n", code);
				stockinfo();
			}
			else {
				printf("\t%s Record Not Found... \n", code);
			}
		}
		else {
			printf("\tError deleting record...\n\n");
		}
	}
	else stockinfo();
}
void StockCalculate() {

	FILE* fp;
	fp = fopen("stockinfo.txt", "r");
	Stock stock;
	int i = 0, t = 0, r = 0;

	if (fp == NULL) {
		printf("file open unsuccessfully...");
		return;
	}

	while (fscanf(fp, "%[^|]|%lf|%[^|]|%d|%d %d %d|%d|%s\n",
		stock.itemCode, &stock.itemPrice, stock.itemDesc, &stock.qty, &stock.inDate.day, &stock.inDate.month,
		&stock.inDate.year, &stock.reserqty, stock.cusName) != EOF) {
		i++;
		t += stock.qty;
		r += stock.reserqty;
	}

	//display result
	printf("\nTotal Types Of Product     : %d \n", i);
	printf("Total Quantity Of Product  : %d \n", t);
	printf("Total Reserved Product     : %d \n", r);
	fclose(fp);
	stockinfo();

}
char StockValidate(char input) {
	while (toupper(input) != 'Y' && toupper(input) != 'N') {
		printf("\tInvalid input~\n");
		printf("\tPlease enter again (Y/y = yes N/n = no) :");
		rewind(stdin);
		scanf("%c", &input);
		printf("====================================================\n");
	}
	return input;
}

//MEMBER INFORMATION MODULE
void memberTitle()
{
	printf("|%-20s|%-26s|%-13s|%-7s|%-15s|%-40s|%-15s|%-14s|\n", "Name", "Join Date(dd/mm/yyyy)", "Gender", "Age", "IC Number", "Address", "Contact No.", "ID Number");
}
void memberLine()
{
	printf("\n===============================================================================================================================================================\n");
}
void memberAddMember()
{

	struct member newMember[100];   //structure that can store 100 member
	struct member currentMember;
	char opt;
	int i = 0;
	int amt = 0;
	int idTaken = 0;





	do
	{
		printf("\nMember name: ");              //member name
		rewind(stdin);
		scanf(" %[^\n]", newMember[i].name);

		printf("\nJoin Date dd/mm/yyyy: ");    //member birthday
		rewind(stdin);
		scanf(" %d/%d/%d", &newMember[i].date.day, &newMember[i].date.month, &newMember[i].date.year);


		do {
			printf("\nGender (M/F): ");                 //member gender
			rewind(stdin);
			scanf(" %c", &newMember[i].gender);
			newMember[i].gender = toupper(newMember[i].gender);
		} while (newMember[i].gender != 'M' && newMember[i].gender != 'F');


		printf("\nAge: ");                    //member age
		rewind(stdin);
		scanf(" %d", &newMember[i].age);

		printf("\nIC Number(xxxxxxxxxxxx): ");             //member IC number
		rewind(stdin);
		scanf(" %s", newMember[i].icNum);

		printf("\nHouse Address: ");         //member house address
		rewind(stdin);
		scanf(" %[^\n]", newMember[i].address);

		printf("\nContact Number: ");        //member contact number
		rewind(stdin);
		scanf(" %s", &newMember[i].contactNum);
		char temp[15] = "+6";
		strcat(temp, newMember[i].contactNum);
		strcpy(newMember[i].contactNum, temp);




		do {
			// Generate a random ID number with 6 digits
			newMember[i].idNum = rand() % 900000 + 100000;
			printf("\n MemberID Number Generated : %d !", newMember[i].idNum);

			FILE* fptr;
			fptr = fopen("member.txt", "r");             // Open file for reading
			if (fptr == NULL) {
				printf("\nUnable to open member.txt, assuming you're first member.\n");           //display error message
				break;
			}

			// Check if ID number already exists in file
			idTaken = 0;
			char line[100];
			while (fgets(line, sizeof(line), fptr)) {
				struct member temp;
				sscanf(line, "%[^|]|%d/%d/%d|%c|%d|%[^|]|%[^|]|%[^|]|%d\n", temp.name, &temp.date.day, &temp.date.month, &temp.date.year, &temp.gender, &temp.age, &temp.icNum, temp.address, &temp.contactNum, &temp.idNum);
				if (newMember[i].idNum == temp.idNum) {
					printf("\nID number already exists. Regenerating ID number...\n");
					idTaken = 1;
					break;
				}
			}
			fclose(fptr);
		} while (idTaken);




		//validation check
		if (strlen(newMember[i].name) <= 1 || newMember[i].age <= 0 || strlen(newMember[i].contactNum) <= 9 || strlen(newMember[i].address) <= 1 || newMember[i].contactNum <= 1 || (newMember[i].idNum) <= 0) {
			printf("Invalid data, member not added.\n");
			return;
		}


		FILE* fptr;
		fptr = fopen("member.txt", "a");               // open file
		if (fptr == NULL) {
			printf("Error opening file.\n");           //display error message
			return;
		}




		fprintf(fptr, "%s|%02d/%02d/%d|%c|%d|%s|%s|%s|%d\n", newMember[i].name, newMember[i].date.day, newMember[i].date.month, newMember[i].date.year, newMember[i].gender,    //save member informaiton into text file
			newMember[i].age, newMember[i].icNum, newMember[i].address, newMember[i].contactNum,
			newMember[i].idNum);

		memberLine();
		memberTitle();                        //display added member information
		memberLine();
		printf("|%-20s|%02d/%02d/%-20d|%-13c|%-7d|%-15s|%-40s|%-15s|%-14d|\n", newMember[i].name, newMember[i].date.day, newMember[i].date.month, newMember[i].date.year, newMember[i].gender, newMember[i].age, newMember[i].icNum, newMember[i].address, newMember[i].contactNum, newMember[i].idNum);
		memberLine();




		fclose(fptr);

		printf("\n////////// New member added to file! //////////\n");
		printf("Total %d Member !\n", amt + 1);                    //display total member added
		i++;
		amt++;

		printf("continue to add member ? (y/n)");
		rewind(stdin);                                      //ask user want to continue ad member or not 
		scanf(" %c", &opt);
		opt = toupper(opt);


	} while (opt == 'Y');


}
void memberDeleteMember()
{
	int idToDelete;


	printf("Member List\n");
	printf("--------------\n");
	memberDisplayMember();
	printf("Enter ID Number of member to delete: ");   // ask ID
	scanf(" %d", &idToDelete);

	// Open input and output files
	FILE* fptr = fopen("member.txt", "r");
	FILE* tempFptr = fopen("temp.txt", "w");

	if (fptr == NULL || tempFptr == NULL) {
		printf("Error opening files.\n");
		return;
	}

	// Read data from input file and write to output file except the data of the member with the ID to be deleted
	struct member temp;
	int found = 0;
	while (fscanf(fptr, "%[^|]|%d/%d/%d|%c|%d|%[^|]|%[^|]|%[^|]|%d\n", temp.name, &temp.date.day, &temp.date.month, &temp.date.year, &temp.gender, &temp.age, &temp.icNum, temp.address, &temp.contactNum, &temp.idNum) != EOF) {
		if (temp.idNum == idToDelete) {
			found = 1;
			continue;
		}
		fprintf(tempFptr, "%s|%02d/%02d/%d|%c|%d|%s|%s|%s|%d\n", temp.name, temp.date.day, temp.date.month, temp.date.year, temp.gender, temp.age, temp.icNum, temp.address, temp.contactNum, temp.idNum);
	}

	// Close input and output files
	fclose(fptr);
	fclose(tempFptr);

	// Delete the original file and rename the temporary file to the original file name
	if (remove("member.txt") == 0 && rename("temp.txt", "member.txt") == 0) {
		if (found) {
			printf("Member with ID number %d deleted successfully\n", idToDelete);
		}
		else {
			printf("No member found with ID number %d.\n", idToDelete);
		}
	}
	else {
		printf("Error deleting member.\n");
	}
}
void memberSearchMember() {
	int searchId;
	printf("\nEnter the ID number of the member you want to search: ");
	scanf(" %d", &searchId);

	FILE* fptr;
	fptr = fopen("member.txt", "r");
	if (fptr == NULL) {
		printf("Error opening file.\n");
		return;
	}

	char line[256];
	printf("\n===============================================================================================================================================================\n");
	memberTitle();
	printf("===============================================================================================================================================================\n");

	while (fgets(line, sizeof(line), fptr)) {
		int idNum;
		char name[100], gender, address[200], icNum[13], contactNum[15];
		int day, month, year, age;

		sscanf(line, "%[^|]|%d/%d/%d|%c|%d|%[^|]|%[^|]|%[^|]|%d\n", name, &day, &month, &year, &gender, &age, &icNum, address, &contactNum, &idNum);

		if (idNum == searchId) {
			printf("|%-20s|%02d/%02d/%-20d|%-13c|%-7d|%-15s|%-40s|%-15s|%-14d|\n\n", name, day, month, year, gender, age, icNum, address, contactNum, idNum);
			break;
		}
	}

	printf("===============================================================================================================================================================\n");

	fclose(fptr);
}
void memberDisplayMember() // no need array , because it read data from  text file .  (fscanf)
{

	struct member currentMember;
	//birthday day;

	FILE* fptr;
	fptr = fopen("member.txt", "r");
	if (fptr == NULL) {
		printf("Error opening file.\n");
		return;
	}

	memberLine();
	memberTitle();
	memberLine();


	int m = 0;

	while (fscanf(fptr, "%[^|]|%d/%d/%d|%c|%d|%[^|]|%[^|]|%[^|]|%d\n", currentMember.name, &(currentMember.date.day), &(currentMember.date.month), &(currentMember.date.year), &(currentMember.gender),
		&(currentMember.age), &(currentMember.icNum), currentMember.address, &(currentMember.contactNum),
		&(currentMember.idNum))
		!= EOF) {

		printf("|%-20s|%02d/%02d/%-20d|%-13c|%-7d|%-15s|%-40s|%-15s|%-14d|\n\n", currentMember.name, currentMember.date.day, currentMember.date.month, currentMember.date.year, currentMember.gender,
			currentMember.age, currentMember.icNum, currentMember.address, currentMember.contactNum, currentMember.idNum);


		m++;


	}


	memberLine();
	printf("Total %d Member\n\n", m);



	fclose(fptr);
}
void memberFilterMember() {


	int minAge, maxAge, i = 0;
	printf("\nEnter minimum age: ");    //ask for minimum age
	scanf(" %d", &minAge);
	printf("Enter maximum age: ");     //ask for maximum age
	scanf(" %d", &maxAge);

	struct member filterMember[100];

	FILE* fptr;
	fptr = fopen("member.txt", "r");
	if (fptr == NULL) {
		printf("Error opening file.\n");
		return;
	}



	memberLine();
	memberTitle();
	memberLine();

	while (fscanf(fptr, "%[^|]|%d/%d/%d|%c|%d|%[^|]|%[^|]|%[^|]|%d\n", filterMember[i].name, &(filterMember[i].date.day), &(filterMember[i].date.month), &(filterMember[i].date.year), &(filterMember[i].gender),
		&(filterMember[i].age), &(filterMember[i].icNum), filterMember[i].address, &(filterMember[i].contactNum),
		&(filterMember[i].idNum))
		!= EOF) {
		if (filterMember[i].age >= minAge && filterMember[i].age <= maxAge) {
			printf("|%-20s|%02d/%02d/%-20d|%-13c|%-7d|%-15s|%-40s|%-15s|%-14d|\n\n", filterMember[i].name, filterMember[i].date.day, filterMember[i].date.month, filterMember[i].date.year, filterMember[i].gender,
				filterMember[i].age, filterMember[i].icNum, filterMember[i].address, filterMember[i].contactNum,
				filterMember[i].idNum);
		}

		i++;  // increment the index variable

	}

	memberLine();

	fclose(fptr);
}
void memberModifyMember() {
	int idNum;
	char opt;
	struct member modi;



	printf("Enter the ID number of the member to modify: ");      //ask for member ID to modify
	scanf(" %d", &idNum);

	FILE* fptr;
	FILE* fmodi;
	fptr = fopen("member.txt", "r");
	fmodi = fopen("modi.txt", "w");
	if (fptr == NULL || fmodi == NULL) {
		printf("Error opening file.\n");
		return;
	}

	int found = 0;
	while (fscanf(fptr, "%[^|]|%d/%d/%d|%c|%d|%[^|]|%[^|]|%[^|]|%d\n", modi.name, &modi.date.day, &modi.date.month, &modi.date.year, &modi.gender,
		&modi.age, &modi.icNum, modi.address, &modi.contactNum, &modi.idNum) != EOF) {

		if (modi.idNum == idNum) {
			printf("\n\n======================================================\n");
			printf("\t\tCurrent member data:");
			printf("\n======================================================\n\n");
			printf("Name: %s\nJoin Date: %02d/%02d/%d\nGender: %c\nAge: %d\nIC Number: %s\nAddress: %s\nContact Number: %s\nID Number: %d\n",
				modi.name, modi.date.day, modi.date.month, modi.date.year, modi.gender, modi.age, modi.icNum, modi.address, modi.contactNum, modi.idNum);

			printf("\n\n======================================================\n");
			printf("\t\tModify member data:");
			printf("\n======================================================\n\n");

			printf("\nDo you want to modify the member's name? (Y/N): ");
			char response;
			rewind(stdin);
			scanf(" %c", &response);
			response = toupper(response);
			if (response == 'Y') {
				printf("Name: ");
				rewind(stdin);
				scanf(" %[^\n]", modi.name);


			}

			printf("\nDo you want to modify the member's join date? (Y/N): ");
			rewind(stdin);
			scanf(" %c", &response);
			response = toupper(response);
			if (response == 'Y') {
				printf("Join Date dd/mm/yyyy: ");
				scanf(" %d/%d/%d", &modi.date.day, &modi.date.month, &modi.date.year);
			}

			printf("\nDo you want to modify the member's gender? (Y/N): ");
			rewind(stdin);
			scanf(" %c", &response);
			response = toupper(response);
			if (response == 'Y') {
				do {
					printf("Gender (M/F): ");
					rewind(stdin);
					scanf(" %c", &modi.gender);
					modi.gender = toupper(modi.gender);
				} while (modi.gender != 'M' && modi.gender != 'F');
			}

			printf("\nDo you want to modify the member's age? (Y/N): ");
			rewind(stdin);
			scanf(" %c", &response);
			response = toupper(response);
			if (response == 'Y') {
				printf("Age: ");
				rewind(stdin);
				scanf(" %d", &modi.age);
			}

			printf("\nDo you want to modify the member's IC number? (Y/N): ");
			rewind(stdin);
			scanf(" %c", &response);
			response = toupper(response);
			if (response == 'Y') {
				printf("IC Number: ");
				rewind(stdin);
				scanf(" %s", &modi.icNum);
			}

			printf("\nDo you want to modify the member's house address? (Y/N): ");
			rewind(stdin);
			scanf(" %c", &response);
			response = toupper(response);
			if (response == 'Y') {
				printf("House Address: ");
				rewind(stdin);
				scanf(" %[^\n]", modi.address);
			}

			printf("\nDo you want to modify the member's contact number? (Y/N): ");
			rewind(stdin);
			scanf(" %c", &response);
			response = toupper(response);
			if (response == 'Y') {
				printf("Contact Number: ");
				rewind(stdin);
				scanf(" %s", &modi.contactNum);
				char temp[15] = "+6";
				strcat(temp, modi.contactNum);
				strcpy(modi.contactNum, temp);
			}


			printf("\nMember data modified!\n");
			found = 1;

		}
		fprintf(fmodi, "%s|%02d/%02d/%d|%c|%d|%s|%s|%s|%d\n", modi.name, modi.date.day, modi.date.month, modi.date.year, modi.gender,
			modi.age, modi.icNum, modi.address, modi.contactNum, modi.idNum);
	}

	// if the member with the specified ID was not found, print an error message and delete the modi.txt file
	if (!found) {
		printf("Member with ID number %d not found.\n", idNum);
		remove("modi.txt");
		return;
	}

	// close the files
	fclose(fptr);
	fclose(fmodi);

	remove("member.txt");  // remove member.txt file
	rename("modi.txt", "member.txt");  // rename modi.txt to member.txt
}
void memberConfirmExit(char* choice)
{
	char exit;

	do
	{
		system("cls");

		printf("Confirm to Exit? (Y/N): ");  //ask user want to exit or not
		rewind(stdin);
		scanf(" %c", &exit);
		exit = toupper(exit);   //change exit to uppercase

	} while (exit != 'Y' && exit != 'N');

	*choice = exit;
}
void memberExitMessage()
{
	char choice;

	memberConfirmExit(&choice);

	if (choice == 'Y')
	{
		system("cls");
		printf("Logged out successfully !\n");
		//exit(0);    // if y = display menu() function
		main();
	}
	else
	{
		system("cls");
		memberMenu();    //if n = display menu() function
	}
}
void memberMenu()
{
	char choice;



	do {

		printf("\n=======================================================================\n");
		printf("|             | WELCOME TO MEMBER MANAGEMENT SYSTEM |                 |\n");
		printf("=======================================================================\n");
		printf("|///////////////////////////   MENU   ////////////////////////////////|\n");
		printf("|                                                                     |\n");
		printf("|   1. Display Member                                                 |\n");
		printf("|   2. Add Member                                                     |\n");
		printf("|   3. Search Member                                                  |\n");
		printf("|   4. Filter Member                                                  |\n");
		printf("|   5. Modify Member                                                  |\n");
		printf("|   6. Delete Member                                                  |\n");
		printf("|   7. Exit                                                           |\n");
		printf("|                                                                     |\n");
		printf("=======================================================================\n");

		printf("Enter your choice :");
		rewind(stdin);
		scanf(" %c", &choice);

		switch (choice) {
		case '1':
			system("cls");
			memberDisplayMember();
			break;
		case '2':
			system("cls");
			memberAddMember();
			break;
		case '3':
			system("cls");
			memberSearchMember();
			break;
		case '4':
			system("cls");
			memberFilterMember();
			break;
		case '5':
			system("cls");
			memberModifyMember();
			break;
		case '6':
			system("cls");
			memberDeleteMember();
			break;
		case '7':
			system("cls");
			memberExitMessage();
			break;


		default:
			system("cls");
			printf("Invalid choice, please try again.\n");
			break;
		}
	} while (tolower(choice) != '7');
	return 0;
}

//STAFF INFORMATION MODULE
void staffinfo()
{
	// display menu
	Staff staff;
	SYSTEMTIME t;
	int option;
	GetLocalTime(&t);
	printf("\n\t\tStaff Information - as at %d-%d-%d\n", t.wDay, t.wMonth, t.wYear);
	printf("========================================================================\n");
	printf("\t\t\tSTAFF INFORMATION\n");
	printf("========================================================================\n");

	printf("\t1.Display All Staff Information \n"
		"\t2.Search Staff Information \n"
		"\t3.Add New Staff Information\n"
		"\t4.Mofify Staff Information\n"
		"\t5.Delete Staff Information\n"
		"\t6.Return to menu\n"
		"\t7.Exit\n"
		"\tSelect a function : ");// ask user select a function to access
	scanf("%d", &option);

	// verify the option
	while (option != 1 && option != 2 && option != 3 && option != 4 && option != 5 && option != 6 && option != 7)
	{
		printf("Invalid option ! Enter again (1|2|3|4|5|6|7) :");
		rewind(stdin);
		scanf("%d", &option);
	}

	printf("\n");
	switch (option) //switch the option 
	{
	case 1:
		StaffDisplay();
		break;
	case 2:
		StaffSearch();
		break;
	case 3:
		StaffValidate();
		break;
	case 4:
		StaffModify();
		break;
	case 5:
		StaffDeleted();
		break;
	case 6:
		system("cls"); 
		printf("Logged out successfully !\n"); 
		menu(); break;
	case 7:
		StaffExited();
		break;
	}

}
void StaffDisplay()
{
	Staff staff;
	int i, count = 0;
	FILE* fptr;
	fptr = fopen("staff.dat", "rb");
	if (fptr == NULL)
	{
		printf("Unable to open this file\n");
		return;
	}
	printf("------------------------------------------------------------------------------------------------------\n");
	printf("%-30s%18s%18s%19s%18s", "Staff Name", "Staff ID", "Phone Number ", "Staff Department", "Date Joined\n");
	printf("------------------------------------------------------------------------------------------------------\n");

	while (fread(&staff, sizeof(Staff), 1, fptr))// check is end of file or not
	{
		count++;
		//display all record and check the date format
		if (staff.date.month < 10 && staff.date.day < 10) {
			printf("%-30s%15s%19s%15s             0%d-0%d-%d\n", staff.staffName, staff.staffId, staff.phoneNum, staff.department, staff.date.day, staff.date.month, staff.date.year);
		}
		else if (staff.date.month >= 10 && staff.date.day < 10) {
			printf("%-30s%15s%19s%15s             0%d-%.2d-%d\n", staff.staffName, staff.staffId, staff.phoneNum, staff.department, staff.date.day, staff.date.month, staff.date.year);
		}
		else {
			printf("%-30s%15s%19s%15s             %.2d-%.2d-%d\n", staff.staffName, staff.staffId, staff.phoneNum, staff.department, staff.date.day, staff.date.month, staff.date.year);
		}
	}
	printf("\n\t\t\t\t\t ** %d record display **\n", count);//display how many record are displayed
	printf("\n\n\t\t\t\t\tExit Display function\n");
	printf("----------------------------------------------------------------------------------------------------\n\n\n");
	fclose(fptr);
	printf("\n%40s", "*Return Main Menu*");
	staffinfo();//return to staff menu
}
void StaffSearch()
{
	Staff staff[999];//put array to Staff structure
	char option, option2, sel;
	char department[10], name[30], staffid[10];
	int month, year, i = 0, count, countA, countB, countC, countD, countE;
	FILE* fptr;
	fptr = fopen("staff.dat", "rb");
	if (fptr == NULL)//check file is exist or not 
	{
		printf("Unable to open this file\n");
		exit(-1);
	}

	while (fread(&staff[i], sizeof(Staff), 1, fptr)) // to check how many data is in the staff.dat
	{
		i++;
	}
	count = i;

	do {
		printf("What you want to search ?\n"
			"\tA.Department\n"
			"\tB.Month Joined\n"
			"\tC.Year Joined\n"
			"\tD.Staff id\n"
			"\tE.Name\n"
			"\tOption:");
		rewind(stdin);
		scanf("%c", &option);//get option form user

		//check option is correct or not
		while (toupper(option) != 'A' && toupper(option) != 'B' && toupper(option) != 'C' && toupper(option) != 'D' && toupper(option) != 'E')
		{
			printf("Invalid option ! Enter again (A || B || C || D || E ): ");
			rewind(stdin);
			scanf("%c", &option);
		}
		switch (option) // switch user option 
		{
			//to search the Department to display the record
		case 'A':
		case'a':
			printf("\nSelect the Staff's Department :\n");//ask user key in what department they want to search
			printf("A. IT department\n"
				"B. HR department\n"
				"C. Sales Department\n"
				"D. Finance Department\n"
				"E. Account Department\n"
				"Selection :");
			rewind(stdin);
			scanf("%c", &sel);
			printf("\n");
			while (sel != 'A' && sel != 'B' && sel != 'C' && sel != 'D' && sel != 'E' && sel != 'a' && sel != 'b' && sel != 'c' && sel != 'd' && sel != 'e') {
				printf("Invalid option ! Enter again (A || B || C || D || E ):");
				rewind(stdin);
				scanf("%c", &sel);
			}
			switch (sel) {
			case 'A':
			case'a':
				strcpy(department, "IT");
				break;
			case 'B':
			case'b':
				strcpy(department, "HR");
				break;
			case 'C':
			case'c':
				strcpy(department, "SALES");
				break;
			case 'D':
			case'd':
				strcpy(department, "FINANCE");
				break;
			case 'E':
			case'e':
				strcpy(department, "ACCOUNT");
				break;
			}
			countA = 0;
			printf("------------------------------------------------------------------------------------------------------\n");
			printf("%-30s%18s%18s%19s%18s", "Staff Name", "Staff ID", "Phone Number ", "Staff Department", "Date Joined\n");
			printf("------------------------------------------------------------------------------------------------------\n");

			for (i = 0; i < count; i++)
			{
				if (strcmp(staff[i].department, department) == 0)
				{
					countA++;
					if (staff[i].date.month < 10 && staff[i].date.day < 10) {
						printf("%-30s%15s%19s%15s             0%d-0%d-%d\n", staff[i].staffName, staff[i].staffId, staff[i].phoneNum, staff[i].department, staff[i].date.day, staff[i].date.month, staff[i].date.year);
					}
					else if (staff[i].date.month >= 10 && staff[i].date.day < 10) {
						printf("%-30s%15s%19s%15s             0%d-%.2d-%d\n", staff[i].staffName, staff[i].staffId, staff[i].phoneNum, staff[i].department, staff[i].date.day, staff[i].date.month, staff[i].date.year);
					}
					else {
						printf("%-30s%15s%19s%15s             %.2d-%.2d-%d\n", staff[i].staffName, staff[i].staffId, staff[i].phoneNum, staff[i].department, staff[i].date.day, staff[i].date.month, staff[i].date.year);
					}
				}
			}
			printf("\n------------------------------------------------------------------------------------------------------\n");
			printf("\n\t\t\t\t\t ** %d record display **\n", countA);
			printf("\n------------------------------------------------------------------------------------------------------\n");

			break;

			//to search the month join of staff to display the record
		case 'B':
		case'b':
			printf("\n");
			printf("Enter month joined of staff :");
			rewind(stdin);
			scanf("%d", &month);

			countB = 0;
			printf("------------------------------------------------------------------------------------------------------\n");
			printf("%-30s%18s%18s%19s%18s", "Staff Name", "Staff ID", "Phone Number ", "Staff Department", "Date Joined\n");
			printf("------------------------------------------------------------------------------------------------------\n");

			for (i = 0; i < count; i++)
			{
				if (month == staff[i].date.month)
				{
					countB++;
					if (staff[i].date.month < 10 && staff[i].date.day < 10) {
						printf("%-30s%15s%19s%15s             0%d-0%d-%d\n", staff[i].staffName, staff[i].staffId, staff[i].phoneNum, staff[i].department, staff[i].date.day, staff[i].date.month, staff[i].date.year);
					}
					else if (staff[i].date.month >= 10 && staff[i].date.day < 10) {
						printf("%-30s%15s%19s%15s             0%d-%.2d-%d\n", staff[i].staffName, staff[i].staffId, staff[i].phoneNum, staff[i].department, staff[i].date.day, staff[i].date.month, staff[i].date.year);
					}
					else {
						printf("%-30s%15s%19s%15s             %.2d-%.2d-%d\n", staff[i].staffName, staff[i].staffId, staff[i].phoneNum, staff[i].department, staff[i].date.day, staff[i].date.month, staff[i].date.year);
					}
				}
			}
			printf("\n------------------------------------------------------------------------------------------------------\n");
			printf("\n\t\t\t\t\t ** %d record display **\n", countB);
			printf("\n------------------------------------------------------------------------------------------------------\n");
			break;

			//to search the year join of staff to display the record
		case 'C':
		case'c':
			printf("\n");
			printf("Enter year joined of staff :");
			rewind(stdin);
			scanf("%d", &year);

			countC = 0;
			printf("------------------------------------------------------------------------------------------------------\n");
			printf("%-30s%18s%18s%19s%18s", "Staff Name", "Staff ID", "Phone Number ", "Staff Department", "Date Joined\n");
			printf("------------------------------------------------------------------------------------------------------\n");

			for (i = 0; i < count; i++)
			{
				if (year == staff[i].date.year)
				{
					countC++;
					if (staff[i].date.month < 10 && staff[i].date.day < 10) {
						printf("%-30s%15s%19s%15s             0%d-0%d-%d\n", staff[i].staffName, staff[i].staffId, staff[i].phoneNum, staff[i].department, staff[i].date.day, staff[i].date.month, staff[i].date.year);
					}
					else if (staff[i].date.month >= 10 && staff[i].date.day < 10) {
						printf("%-30s%15s%19s%15s             0%d-%.2d-%d\n", staff[i].staffName, staff[i].staffId, staff[i].phoneNum, staff[i].department, staff[i].date.day, staff[i].date.month, staff[i].date.year);
					}
					else {
						printf("%-30s%15s%19s%15s             %.2d-%.2d-%d\n", staff[i].staffName, staff[i].staffId, staff[i].phoneNum, staff[i].department, staff[i].date.day, staff[i].date.month, staff[i].date.year);
					}
				}
			}
			printf("\n------------------------------------------------------------------------------------------------------\n");
			printf("\n\t\t\t\t\t ** %d record display **\n", countC);
			printf("\n------------------------------------------------------------------------------------------------------\n");
			break;

			//to search staff id to display the record
		case 'D':
		case'd':
			printf("\n");
			printf("Enter Staff ID you want to seacrh :");
			rewind(stdin);
			scanf("%[^\n]", staffid);

			countD = 0;
			printf("------------------------------------------------------------------------------------------------------\n");
			printf("%-30s%18s%18s%19s%18s", "Staff Name", "Staff ID", "Phone Number ", "Staff Department", "Date Joined\n");
			printf("------------------------------------------------------------------------------------------------------\n");

			for (i = 0; i < count; i++)
			{
				if (strcmp(staff[i].staffId, staffid) == 0)
				{
					countD++;
					if (staff[i].date.month < 10 && staff[i].date.day < 10) {
						printf("%-30s%15s%19s%15s             0%d-0%d-%d\n", staff[i].staffName, staff[i].staffId, staff[i].phoneNum, staff[i].department, staff[i].date.day, staff[i].date.month, staff[i].date.year);
					}
					else if (staff[i].date.month >= 10 && staff[i].date.day < 10) {
						printf("%-30s%15s%19s%15s             0%d-%.2d-%d\n", staff[i].staffName, staff[i].staffId, staff[i].phoneNum, staff[i].department, staff[i].date.day, staff[i].date.month, staff[i].date.year);
					}
					else {
						printf("%-30s%15s%19s%15s             %.2d-%.2d-%d\n", staff[i].staffName, staff[i].staffId, staff[i].phoneNum, staff[i].department, staff[i].date.day, staff[i].date.month, staff[i].date.year);
					}
				}
			}
			printf("\n------------------------------------------------------------------------------------------------------\n");
			printf("\n\t\t\t\t\t ** %d record display **\n", countD);
			printf("\n------------------------------------------------------------------------------------------------------\n");
			break;


			//to search the staff name to display the record
		case 'E':
		case'e':
			printf("\n");
			printf("Enter Staff Name you want to seacrh :");
			rewind(stdin);
			scanf("%[^\n]", name);

			countE = 0;
			printf("------------------------------------------------------------------------------------------------------\n");
			printf("%-30s%18s%18s%19s%18s", "Staff Name", "Staff ID", "Phone Number ", "Staff Department", "Date Joined\n");
			printf("------------------------------------------------------------------------------------------------------\n");

			for (i = 0; i < count; i++)
			{
				if (strcmp(staff[i].staffName, name) == 0)
				{
					countE++;
					if (staff[i].date.month < 10 && staff[i].date.day < 10) {
						printf("%-30s%15s%19s%15s             0%d-0%d-%d\n", staff[i].staffName, staff[i].staffId, staff[i].phoneNum, staff[i].department, staff[i].date.day, staff[i].date.month, staff[i].date.year);
					}
					else if (staff[i].date.month >= 10 && staff[i].date.day < 10) {
						printf("%-30s%15s%19s%15s             0%d-%.2d-%d\n", staff[i].staffName, staff[i].staffId, staff[i].phoneNum, staff[i].department, staff[i].date.day, staff[i].date.month, staff[i].date.year);
					}
					else {
						printf("%-30s%15s%19s%15s             %.2d-%.2d-%d\n", staff[i].staffName, staff[i].staffId, staff[i].phoneNum, staff[i].department, staff[i].date.day, staff[i].date.month, staff[i].date.year);
					}
				}
			}
			printf("\n------------------------------------------------------------------------------------------------------\n");
			printf("\n\t\t\t\t\t ** %d record display **\n", countE);
			printf("\n------------------------------------------------------------------------------------------------------\n");
			break;
		}

		// ask user want to search another staff record or not and store in option 2
		printf("\nSearch another staff infomation ? (Y = Yes || N = No) : ");
		rewind(stdin);
		scanf("%c", &option2);

		while (toupper(option2) != 'Y' && toupper(option2) != 'N') //check option 2 is correct or not
		{
			printf("Invalid option ! Enter again (Y = Yes || N = No) : ");
			rewind(stdin);
			scanf("%c", &option2);
		}

	} while (toupper(option2) == 'Y');// loop while user option 2 is Y
	fclose(fptr);
	printf("\n%40s", "*Return Main Menu*");
	staffinfo();//if user dont want to continue search another staff info , then return to staff menu
}
void StaffValidate() {

	//to validate the staff id have repeated key in or not
	Staff staff[999];
	int i = 0, count, found = 0;
	char newStaffId[10];
	FILE* fptr;
	fptr = fopen("staff.dat", "rb");

	while (fread(&staff[i], sizeof(Staff), 1, fptr)) // to check how many data is in the staff.dat
	{
		i++;
	}
	count = i;
	fclose(fptr);

	printf("Enter Staff ID :");
	rewind(stdin);
	scanf("%[^\n]", newStaffId);

	// Check both staff array and file for existing staff ID
	for (int j = 0; j < count; j++)
	{
		if (strcmp(newStaffId, staff[j].staffId) == 0)
		{
			found = 1;
			while (found == 1)
			{
				printf("\nThis Staff ID has been used, try another Staff ID.\n");
				printf("Enter another Staff ID :");
				rewind(stdin);
				scanf("%[^\n]", newStaffId);
				found = 0;
				for (int k = 0; k < count; k++)
				{
					if (strcmp(newStaffId, staff[k].staffId) == 0)
					{
						found = 1;
						break;
					}
				}
				if (!found) {
					// Reread the file to update staff array
					fptr = fopen("staff.dat", "rb");
					i = 0;
					while (fread(&staff[i], sizeof(Staff), 1, fptr)) {
						i++;
					}
					count = i;
					fclose(fptr);
				}
			}
		}
	}

	StaffAdd(newStaffId);//if the staff id did not repeated use, then carry the staff id go to add function
}
void StaffAdd(char newStaffId[])
{
	//add new staff info
	Staff staff;
	int i;
	char option, option2, sel;
	FILE* fptr;
	fptr = fopen("staff.dat", "ab");
	if (fptr == NULL) //check file is exist or not
	{
		printf("Unable to open this file\n");
		return;
	}
	printf("\n");
	printf("Enter Staff Name :"); //enter new staff name
	rewind(stdin);
	scanf("%[^\n]", &staff.staffName);

	printf("\nEnter Staff's Phone Number :");// enter new staff phone number
	rewind(stdin);
	scanf("%[^\n]", &staff.phoneNum);

	printf("\nSelect the Staff's Department :\n");// select the new staff's  department
	printf("\tA. IT department\n"
		"\tB. HR department\n"
		"\tC. Sales Department\n"
		"\tD. Finance Department\n"
		"\tE. Account Department\n"
		"\tSelection :");
	rewind(stdin);
	scanf("%c", &sel);

	//check selection is correct or not
	while (sel != 'A' && sel != 'B' && sel != 'C' && sel != 'D' && sel != 'E' && sel != 'a' && sel != 'b' && sel != 'c' && sel != 'd' && sel != 'e')
	{
		//while not correct,ask user anter again until they key in correct selection 
		printf("Invalid option ! Enter again (A || B || C || D || E )");
		rewind(stdin);
		scanf("%c", &sel);
	}

	switch (sel)//switch user selection
	{
	case 'A':
	case'a':
		strcpy(staff.department, "IT");
		break;
	case 'B':
	case'b':
		strcpy(staff.department, "HR");
		break;
	case 'C':
	case'c':
		strcpy(staff.department, "SALES");
		break;
	case 'D':
	case'd':
		strcpy(staff.department, "FINANCE");
		break;
	case 'E':
	case'e':
		strcpy(staff.department, "ACCOUNT");
		break;
	}

	printf("\nEnter Date Joined (DD-MM-YYYY): ");  //enter date join for the new staff ,by format xx-xx-xxxx, include symbol '-'
	rewind(stdin);
	scanf("%d-%d-%d", &staff.date.day, &staff.date.month, &staff.date.year);

	strcpy(staff.staffId, newStaffId); // store the staff id form validate function

	printf("\nSure to add ? (Y = Yes || N = No) : ");
	rewind(stdin);
	scanf("%c", &option2);//store user option in 'option2' variable

	//check option2
	if (toupper(option2) == 'Y')
	{
		fwrite(&staff, sizeof(Staff), 1, fptr);
		printf("=============================================\n"
			"\n\t\tRecord added.\n");
		printf("=============================================\n");
	}

	else {
		printf("---------------------------------------------------\n");
		printf("Fail to add the record\n");
		printf("---------------------------------------------------\n");
	}
	fclose(fptr);

	//ask user want to add another record or not
	while (1)
	{
		printf("\n\nAdd Next Staff Info ? (Y = Yes || N = No) : ");
		rewind(stdin);
		scanf("%c", &option);//store user option in 'option' variable

		if (toupper(option) == 'Y')
		{
			StaffValidate();
		}

		else if (toupper(option) == 'N')//if user dont want to continue , then return to staff menu
		{
			printf("\n********************************************************************\n");
			printf("\t\tExit Add function\n");
			printf("********************************************************************\n\n\n");

			printf("\n%60s", "** ALL STAFF RECORD **\n");
			StaffDisplay();
		}

		else
		{
			printf("Invalid option ! Enter again (A || B || C || D || E )");
			rewind(stdin);
			scanf("%c", &option);
		}
	}
}
void StaffModify()
{
	Staff staff[999];//set array for Staff Structure
	char newName[30], newPhoneNum[10], newDepartment[10], staffid[10];
	char option, option2, ans, sel;
	int newDay, newMonth, newYear, i = 0, count, found, count2 = 0;

	FILE* fptr;
	fptr = fopen("staff.dat", "rb");

	if (fptr == NULL)//check file is exist or not 
	{
		printf("Unable to open this file\n");
		exit(-1);
	}

	while (fread(&staff[i], sizeof(Staff), 1, fptr))
	{
		i++;
	}
	count = i;
	fclose(fptr);

	do
	{
		printf("\nEnter Staff ID to modified : "); //enter staff id for do modify
		rewind(stdin);
		scanf("%s", staffid);
		printf("\n");
		found = 0;
		printf("------------------------------------------------------------------------------------------------------\n");
		printf("%-30s%18s%18s%19s%18s", "Staff Name", "Staff ID", "Phone Number ", "Staff Department", "Date Joined\n");
		printf("------------------------------------------------------------------------------------------------------\n");

		for (i = 0; i < count; i++)
		{
			if (strcmp(staff[i].staffId, staffid) == 0) // check the staff id that user key in is exist or not
			{
				found = 1;

				// display the staff info for modify
				if (staff[i].date.month < 10 && staff[i].date.day < 10) {
					printf("%-30s%15s%19s%15s             0%d-0%d-%d\n", staff[i].staffName, staff[i].staffId, staff[i].phoneNum, staff[i].department, staff[i].date.day, staff[i].date.month, staff[i].date.year);
				}
				else if (staff[i].date.month >= 10 && staff[i].date.day < 10) {
					printf("%-30s%15s%19s%15s             0%d-%.2d-%d\n", staff[i].staffName, staff[i].staffId, staff[i].phoneNum, staff[i].department, staff[i].date.day, staff[i].date.month, staff[i].date.year);
				}
				else {
					printf("%-30s%15s%19s%15s             %.2d-%.2d-%d\n", staff[i].staffName, staff[i].staffId, staff[i].phoneNum, staff[i].department, staff[i].date.day, staff[i].date.month, staff[i].date.year);
				}
				printf("\n");
				printf("What you want to modify ?\n"
					"\tA.Staff Name\n"
					"\tB.Department\n"
					"\tC.Phone Number\n"
					"\tD.Date Joined\n"
					"\tOption:");
				rewind(stdin);
				scanf("%c", &option);// ask user what they want to modify and store in 'option' variable
				while (toupper(option) != 'A' && toupper(option) != 'B' && toupper(option) != 'C' && toupper(option) != 'D')
				{
					printf("Invalid option ! Enter again (A|B|C|D) : ");
					rewind(stdin);
					scanf("%c", &option);
				}
				switch (option)//switch user option
				{
					// to modify the staff name
				case 'A':
				case'a':
					printf("\nEnter Staff Name to update : ");
					rewind(stdin);
					scanf("%[^\n]", newName);

					printf("\nSure to modify ?(Y = Yes || N = No) :");
					rewind(stdin);
					scanf("%c", &option);

					//check option
					while (toupper(option) != 'Y' && toupper(option) != 'N')
					{
						printf("Invalid option ! Enter again (Y = Yes || N = No) : ");
						rewind(stdin);
						scanf("%c", &option);
					}

					//if user option is 'Y' , then do modification
					if (toupper(option) == 'Y')
					{
						strcpy(staff[i].staffName, newName);
						count2++;

						//show the updated staff info
						printf("Updated record:\n");
						printf("------------------------------------------------------------------------------------------------------\n");
						printf("%-30s%18s%18s%19s%18s", "Staff Name", "Staff ID", "Phone Number ", "Staff Department", "Date Joined\n");
						printf("------------------------------------------------------------------------------------------------------\n");
						if (staff[i].date.month < 10 && staff[i].date.day < 10) {
							printf("%-30s%15s%19s%15s             0%d-0%d-%d\n", staff[i].staffName, staff[i].staffId, staff[i].phoneNum, staff[i].department, staff[i].date.day, staff[i].date.month, staff[i].date.year);
						}
						else if (staff[i].date.month >= 10 && staff[i].date.day < 10) {
							printf("%-30s%15s%19s%15s             0%d-%.2d-%d\n", staff[i].staffName, staff[i].staffId, staff[i].phoneNum, staff[i].department, staff[i].date.day, staff[i].date.month, staff[i].date.year);
						}
						else {
							printf("%-30s%15s%19s%15s             %.2d-%.2d-%d\n", staff[i].staffName, staff[i].staffId, staff[i].phoneNum, staff[i].department, staff[i].date.day, staff[i].date.month, staff[i].date.year);
						}

					}

					else if (toupper(option) == 'N') // if user option is 'N',then show 'no record modify'
					{
						printf("No record modify\n");
					}
					break;


				case 'B':
				case 'b':
					printf("\nSelect the Staff's Department :\n");
					printf("\tA. IT department\n"
						"\tB. HR department\n"
						"\tC. Sales Department\n"
						"\tD. Finance Department\n"
						"\tE. Account Department\n"
						"\tSelection :");
					rewind(stdin);
					scanf("%c", &sel);// ask user to select the new department

					//check the selection 
					while (sel != 'A' && sel != 'B' && sel != 'C' && sel != 'D' && sel != 'E' && sel != 'a' && sel != 'b' && sel != 'c' && sel != 'd' && sel != 'e')
					{
						printf("Invalid option ! Enter again (A || B || C || D || E )");
						rewind(stdin);
						scanf("%c", &sel);
					}

					printf("\nSure to modify ?(Y = Yes || N = No) :");
					rewind(stdin);
					scanf("%c", &option);

					while (toupper(option) != 'Y' && toupper(option) != 'N') {
						printf("Invalid option ! Enter again (Y = Yes || N = No) : ");
						rewind(stdin);
						scanf("%c", &option);
					}

					//check user selection 
					if (toupper(option) == 'Y') {
						switch (sel) {
						case 'A':
						case'a':
							strcpy(newDepartment, "IT");
							break;
						case 'B':
						case'b':
							strcpy(newDepartment, "HR");
							break;
						case 'C':
						case'c':
							strcpy(newDepartment, "SALES");
							break;
						case 'D':
						case'd':
							strcpy(newDepartment, "FINANCE");
							break;
						case 'E':
						case'e':
							strcpy(newDepartment, "ACCOUNT");
							break;
						}
						strcpy(staff[i].department, newDepartment);
						count2++;

						// display updated record
						printf("Updated record:\n");
						printf("------------------------------------------------------------------------------------------------------\n");
						printf("%-30s%18s%18s%19s%18s", "Staff Name", "Staff ID", "Phone Number ", "Staff Department", "Date Joined\n");
						printf("------------------------------------------------------------------------------------------------------\n");
						if (staff[i].date.month < 10 && staff[i].date.day < 10) {
							printf("%-30s%15s%19s%15s             0%d-0%d-%d\n", staff[i].staffName, staff[i].staffId, staff[i].phoneNum, staff[i].department, staff[i].date.day, staff[i].date.month, staff[i].date.year);
						}
						else if (staff[i].date.month >= 10 && staff[i].date.day < 10) {
							printf("%-30s%15s%19s%15s             0%d-%.2d-%d\n", staff[i].staffName, staff[i].staffId, staff[i].phoneNum, staff[i].department, staff[i].date.day, staff[i].date.month, staff[i].date.year);
						}
						else {
							printf("%-30s%15s%19s%15s             %.2d-%.2d-%d\n", staff[i].staffName, staff[i].staffId, staff[i].phoneNum, staff[i].department, staff[i].date.day, staff[i].date.month, staff[i].date.year);
						}
					}
					else if (toupper(option) == 'N')
					{
						printf("No record modify\n");// if user option is 'N'
					}
					break;

					// to modify the staff phone number
				case 'C':
				case'c':
					printf("\nEnter staff Phone Number : ");
					rewind(stdin);
					scanf("%[^\n]", newPhoneNum);
					printf("\nSure to modify ?(Y = Yes || N = No) :");
					rewind(stdin);
					scanf("%c", &option);

					//check option
					while (toupper(option) != 'Y' && toupper(option) != 'N')
					{
						printf("Invalid option ! Enter again (Y = Yes || N = No) : ");
						rewind(stdin);
						scanf("%c", &option);
					}

					if (toupper(option) == 'Y')
					{
						strcpy(staff[i].phoneNum, newPhoneNum);
						count2++;

						//display updated record
						printf("Updated record:\n");
						printf("------------------------------------------------------------------------------------------------------\n");
						printf("%-30s%18s%18s%19s%18s", "Staff Name", "Staff ID", "Phone Number ", "Staff Department", "Date Joined\n");
						printf("------------------------------------------------------------------------------------------------------\n");
						if (staff[i].date.month < 10 && staff[i].date.day < 10) {
							printf("%-30s%15s%19s%15s             0%d-0%d-%d\n", staff[i].staffName, staff[i].staffId, staff[i].phoneNum, staff[i].department, staff[i].date.day, staff[i].date.month, staff[i].date.year);
						}
						else if (staff[i].date.month >= 10 && staff[i].date.day < 10) {
							printf("%-30s%15s%19s%15s             0%d-%.2d-%d\n", staff[i].staffName, staff[i].staffId, staff[i].phoneNum, staff[i].department, staff[i].date.day, staff[i].date.month, staff[i].date.year);
						}
						else {
							printf("%-30s%15s%19s%15s             %.2d-%.2d-%d\n", staff[i].staffName, staff[i].staffId, staff[i].phoneNum, staff[i].department, staff[i].date.day, staff[i].date.month, staff[i].date.year);
						}
					}
					else if (toupper(option) == 'N')
					{
						printf("No record modify\n");// disply when user option is 'N'
					}
					break;
					// to modify staff date join
				case 'D':
				case'd':
					printf("\nEnter staff date joined (DD-MM-YYYY): ");
					rewind(stdin);
					scanf("%d-%d-%d", &newDay, &newMonth, &newYear);
					printf("\nSure to modify ?(Y = Yes || N = No) :");
					rewind(stdin);
					scanf("%c", &option);

					//check opion
					while (toupper(option) != 'Y' && toupper(option) != 'N')
					{
						printf("Invalid option ! Enter again (Y = Yes || N = No) : ");
						rewind(stdin);
						scanf("%c", &option);
					}


					if (toupper(option) == 'Y')
					{
						//asing the user key in data 
						staff[i].date.day = newDay;
						staff[i].date.month = newMonth;
						staff[i].date.year = newYear;
						count2++;

						//display updated record
						printf("Updated record:\n");
						printf("------------------------------------------------------------------------------------------------------\n");
						printf("%-30s%18s%18s%19s%18s", "Staff Name", "Staff ID", "Phone Number ", "Staff Department", "Date Joined\n");
						printf("------------------------------------------------------------------------------------------------------\n");
						if (staff[i].date.month < 10 && staff[i].date.day < 10) {
							printf("%-30s%15s%19s%15s             0%d-0%d-%d\n", staff[i].staffName, staff[i].staffId, staff[i].phoneNum, staff[i].department, staff[i].date.day, staff[i].date.month, staff[i].date.year);
						}
						else if (staff[i].date.month >= 10 && staff[i].date.day < 10) {
							printf("%-30s%15s%19s%15s             0%d-%.2d-%d\n", staff[i].staffName, staff[i].staffId, staff[i].phoneNum, staff[i].department, staff[i].date.day, staff[i].date.month, staff[i].date.year);
						}
						else {
							printf("%-30s%15s%19s%15s             %.2d-%.2d-%d\n", staff[i].staffName, staff[i].staffId, staff[i].phoneNum, staff[i].department, staff[i].date.day, staff[i].date.month, staff[i].date.year);
						}
					}
					else if (toupper(option) == 'N')
					{
						printf("No record modify\n");// display when user option is 'N'
					}

					break;

				}
			}
		}

		if (found != 1)
		{
			printf("\nNo record found with Staff ID %s\n", staffid); // display when the staff id is not found
		}


		printf("\nModify another Staff Info? ? (Y = Yes || N = No) : "); // ask user want to modify another record or not
		rewind(stdin);
		scanf("%c", &option2);// store in 'option2'

		//check the option1
		while (toupper(option2) != 'Y' && toupper(option2) != 'N')
		{
			printf("Invalid option ! Enter again (Y = Yes || N = No) : ");
			rewind(stdin);
			scanf("%c", &option2);
		}

	} while (toupper(option2) == 'Y'); //loop anain while the 'option2' is 'Y'

	fptr = fopen("staff.dat", "wb");

	for (i = 0; i < count; i++)
		fwrite(&staff[i], sizeof(Staff), 1, fptr); // write the new data into staff.dat

	printf("\n------------------------------------------------------------------------------------------------------\n");
	printf("\n\t\t\t\t\t ** %d Record(s) modified. **\n", count2);
	printf("\n------------------------------------------------------------------------------------------------------\n");

	fclose(fptr);
	printf("\n%40s", "*Return Main Menu*");
	staffinfo();//if user dont want to continue , then return to staff menu
}
void StaffDeleted()
{
	//delete staff info
	char cont, option;
	int i = 0, count, newCount, delCount = 0, found;
	char delstaffId[10];

	Staff staff[999]; // set array to Staff Structure
	FILE* fptr;

	do {
		fptr = fopen("staff.dat", "rb");
		if (fptr == NULL)//check file is exist or not 
		{
			printf("Unable to open this file\n");
			exit(-1);
		}

		while (fread(&staff[i], sizeof(Staff), 1, fptr))//check how many data are in the staff.dat
		{
			i++;
		}

		count = i;

		fclose(fptr);

		printf("\nEnter Staff ID to delete : "); // enter staff id
		rewind(stdin);
		scanf("%[^\n]", &delstaffId);

		found = 0;
		printf("\n");
		printf("----------------------------------------------------------------------------------------------\n");
		printf("%-30s%18s%18s%19s%18s", "Staff Name", "Staff ID", "Phone Number ", "Staff Department", "Date Joined\n");
		printf("----------------------------------------------------------------------------------------------\n");
		for (i = 0; i < count; i++)
		{
			if (strcmp(staff[i].staffId, delstaffId) == 0)//check staff id is exist or not
			{
				found = 1;
				//display record
				if (staff[i].date.month < 10 && staff[i].date.day < 10) {
					printf("%-30s%15s%19s%15s             0%d-0%d-%d\n", staff[i].staffName, staff[i].staffId, staff[i].phoneNum, staff[i].department, staff[i].date.day, staff[i].date.month, staff[i].date.year);
				}
				else if (staff[i].date.month >= 10 && staff[i].date.day < 10) {
					printf("%-30s%15s%19s%15s             0%d-%.2d-%d\n", staff[i].staffName, staff[i].staffId, staff[i].phoneNum, staff[i].department, staff[i].date.day, staff[i].date.month, staff[i].date.year);
				}
				else {
					printf("%-30s%15s%19s%15s             %.2d-%.2d-%d\n", staff[i].staffName, staff[i].staffId, staff[i].phoneNum, staff[i].department, staff[i].date.day, staff[i].date.month, staff[i].date.year);
				}
				printf("\n");
				printf("Confirm to Delete ? (Y = Yes || N = No) : ");
				rewind(stdin);
				scanf("%c", &option);

				//check option
				while (toupper(option) != 'Y' && toupper(option) != 'N')
				{
					printf("\n");
					printf("Invalid option ! Enter again (Y = Yes || N = No) : ");
					rewind(stdin);
					scanf("%c", &option);
				}

				if (toupper(option) == 'Y')
				{
					//do delete process
					for (i; i <= count; i++)
						staff[i] = staff[i + 1];
					delCount++;
					newCount = count - 1;

					fptr = fopen("staff.dat", "wb");
					for (i = 0; i < newCount; i++)
						fwrite(&staff[i], sizeof(Staff), 1, fptr);
					fclose(fptr);
				}
				else
				{
					printf("\nRecord not deleted.\n");//if user option != 'Y'
					delCount = 0;
					break;
				}
			}
		}

		if (found != 1)
		{
			printf("\nNo record found for %s\n", delstaffId); // if the staff id did not exist
		}
		else
		{
			printf("\n------------------------------------------------------------------------------------------------------\n");
			printf("\n\t\t\t\t\t ** %d Record Deleted. **\n\n", delCount);//display how many record had deleted
			printf("\n------------------------------------------------------------------------------------------------------\n");
		}

		printf("\nDo you want to delete another record? (Y = Yes || N = No) : ");
		rewind(stdin);
		scanf("%c", &cont);

		//check 'cont'
		while (toupper(cont) != 'Y' && toupper(cont) != 'N')
		{
			printf("Invalid option ! Enter again (Y = Yes || N = No) : ");
			rewind(stdin);
			scanf("%c", &cont);
		}

		delCount = 0;
		i = 0;

	} while (toupper(cont) == 'Y');// loop again while 'cont' is 'Y'

	printf("\n%40s", "Return Main Menu");
	staffinfo();//if user dont want to continue , then return to staff menu

}
void StaffExited()
{
	char option;
	printf("Sure to exit the programme ?\n"
		"Option (Y = Yes || N = No) : ");
	rewind(stdin);
	scanf("%c", &option);

	//check option
	while (toupper(option) != 'Y' && toupper(option) != 'N')
	{
		printf("Invalid option ! Enter again (Y = Yes || N = No) : ");
		rewind(stdin);
		scanf("%c", &option);
	}

	if (toupper(option) == 'N')
	{
		printf("\n%40s", "*Return Main Menu*");
		staffinfo();//if user want to continue , then return to staff menu
	}

	else
	{
		//if user dont want to continue, then end the programme
		printf("\n\t\t\tExit the staff function.....\n");
		printf("------------------------------------------------------------------\n\n");
		exit(0);
	}

}