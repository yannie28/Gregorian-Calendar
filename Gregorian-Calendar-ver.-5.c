#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>



#define TRUE    1
#define FALSE   0

//initialization for functions used
void inputView();
void inputStartOfTheWeek();
void inputDate();
void dailyView(int month, int day, int year);
void weekView(int month, int day, int year);
void monthView(int month, int year);
void yearView(int month, int day, int year, int counter);
int determineleapyear(int year);
int determineDaycode(int year);
int alterDaycode(int daycode);
bool checkDate(int month, int day, int year);
void determineMonths(int month);
int determineDaysInMonths(int month);

//default date view and start of the week (Daily View and starts at Monday)
int view = 1;
int startWeek = 2;

//initialization for the days in months (global variable because when its leap year, value of the feb will change to 29)
int jan = 31, feb = 28, mar = 31, apr = 30, may = 31, jun = 30, jul = 31, aug = 31, sep = 30, oct = 31, nov = 30, dec = 31;

int main () 
{
	system("Color F0");//change the color of the console
	int choose, temp, status;
	
	do{
		printf("============================\n");
		printf("KALENDARYO MAIN MENU \n");
		printf("============================\n");
		printf("1. Enter Date \n");
		printf("2. Change start of the week \n");
		printf("3. Change view format \n");
		printf("4. Exit \n\n");
		
		do{
			printf("Choose your desired option: ");
			status = scanf("%d", &choose);
			while((temp=getchar()) != EOF && temp != '\n'); //used to collect garbage characters (like the enter key when pressed)
			
			if(status != 1){ // check if the user enters a number (status = 0 = not number; status = 1 = number)
				system("cls");
				printf("Invalid input.\nPlease try again!\n\n");
				printf("============================\n");
				printf("KALENDARYO MAIN MENU \n");
				printf("============================\n");
				printf("1. Enter Date \n");
				printf("2. Change start of the week \n");
				printf("3. Change view format \n");
				printf("4. Exit \n\n");
			}
		}while(status != 1); // while input is not a number
		
		system("cls");
		switch(choose){
			case 1:
				inputDate();
				break;
			case 2:
				inputStartOfTheWeek();
				break;
			case 3:
				inputView();
				break;
			case 4:
				exit(0);
			default:
				system("cls");
				printf("Invalid input.\nPlease Try again!\n\n"); 
			
		}
	}while(choose != 4);
		getch();
}

//case 1: enter date
void inputDate()
{
	//system("cls");
	int date, status, temp;
	
 	do{
 		printf("Input Date(mmddyyyy): ");
		status = scanf("%d", &date);
		while((temp=getchar()) != EOF && temp != '\n'); //used to collect garbage characters (like the enter key when pressed)
		
		if(status != 1){ // check if the user enters a number (status = 0 = not number; status = 1 = number)
			system("cls");
			printf("Invalid input.\nPlease try again!\n\n");
		}
	}while(status != 1); // while input is not a number
	
	system("cls");	
	int month = date/1000000;
	int day = (date/10000)%100;
	int year = date%10000;
	
	bool check = checkDate(month, day, year);
	if(check == 0){
		printf("Invalid input.\nPlease try again!\n\n");
		inputDate();
	}
	else{
		printf("Date Specified: %d%d%d",month,day,year);
	
		if(view == 1){ //case 1: daily view
			dailyView(month,day,year);
		}
		
		else if(view == 2){ //case 2: weekly view
			weekView(month, day, year);
		}
		else if(view == 3){ //case 3: monthly view
			monthView(month, year);
		}
		
		else if(view == 4){ //case 4: yearly view
			yearView(month,day,year, 0);
		}
		printf("\n\n");
	}
	
	
}

//case 2: change start of the week (Default: Monday)
void inputStartOfTheWeek()
{
	int temp, status;
	
	//system("cls");
	printf("CHANGE START OF THE WEEK \n");
	printf("1. Starts at Sunday \n");
	printf("2. Starts at Monday \n\n");

	do{
		printf("Choose your desired option: ");
		status = scanf("%d", &startWeek);
		while((temp=getchar()) != EOF && temp != '\n'); //used to collect garbage characters (like the enter key when pressed)
		
		if(status != 1){ // check if the user enters a number (status = 0 = not number; status = 1 = number)
			system("cls");
			printf("Invalid input.\nPlease try again!\n\n");
			printf("CHANGE START OF THE WEEK \n");
			printf("1. Starts at Sunday \n");
			printf("2. Starts at Monday \n\n");
		}
	}while(status != 1); // while input is not a number
	
	system("cls");
	
	switch (startWeek){
		case 1:
		case 2:
			printf("You have successfully changed the start of the week\n");
			printf("Your choice: %d", startWeek);
			printf("\n\n");
			break;
		default:
			printf("Invalid input.\nPlease Try again!\n\n");
			inputStartOfTheWeek();
			break;
	
	}
}

//case 3: change view format (Default: Daily View)
void inputView()
{
	int temp, status;

	//system("cls");
	printf("CHANGE VIEW FORMAT \n");
	printf("1. Daily View \n");
	printf("2. Weekly View \n");
	printf("3. Monthly View \n");
	printf("4. Yearly View \n\n");
	
	do{
		printf("Choose your desired option: ");
		status = scanf("%d", &view);
		while((temp=getchar()) != EOF && temp != '\n'); //used to collect garbage characters (like the enter key when pressed)
		
		if(status != 1){ // check if the user enters a number (status = 0 = not number; status = 1 = number)
			system("cls");
			printf("Invalid input.\nPlease try again!\n\n");
			printf("CHANGE VIEW FORMAT \n");
			printf("1. Daily View \n");
			printf("2. Weekly View \n");
			printf("3. Monthly View \n");
			printf("4. Yearly View \n\n");
		}
	}while(status != 1); // while input is not a number
	
	system("cls");
	
	switch (view){
		case 1:
		case 2:
		case 3:
		case 4:
			printf("You have successfully changed the view format\n");
			printf("Your choice: %d",view);
			printf("\n\n");
			break;
		default:
			printf("Invalid input.\nPlease try again!\n\n");
			inputView();
			break;
	}
	
}

//function for daily view
void dailyView(int month, int day, int year) 
{	
    int y = year - (14 - month) / 12;
    int x = y + y/4 - y/100 + y/400;
    int m = month + 12 * ((14 - month) / 12) - 2;
    int d = (day + x + (31*m)/12) % 7;
    
    determineMonths(month);
    printf(" %d, ", day);
    printf("%d", year);
    
    switch(d){
        case 0: //0 = Sunday
        	printf("\n(Sunday)");
        	break;
        case 1: //1 = Monday
        	printf("\n(Monday)");
       		break;
       	case 2: //2 = Tuesday
       		printf("\n(Tuesday)");
       		break;
       	case 3: //3 = Wednesday
       		printf("\n(Wednesday)");
       		break;
       	case 4: //4 = Thursday
       		printf("\n(Thursday)");
       		break;
       	case 5: //5 = Friday
       		printf("\n(Friday)");
       		break;
       	case 6: //6 = Saturday
       		printf("\n(Saturday)");
       		break;
	}
	
}

//function for weekly view
void weekView(int month, int day, int year)
{

	int flag = 0;
	int y = year - (14 - month) / 12;
    int x = y + y/4 - y/100 + y/400;
    int m = month + 12 * ((14 - month) / 12) - 2;
    int d = (day + x + (31*m)/12) % 7;	
    
    determineMonths(month);
	printf(" %d", year);
	determineleapyear(year);
	
	if(startWeek == 1){ //startWeek is Sunday
		printf("\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n" );
	}
	else{ //startWeek is Monday
		d = alterDaycode(d);
		printf("\nMon  Tue  Wed  Thu  Fri  Sat  Sun\n" );		
	}
	
	if(d != 0){ //check if d is not equal to the first day of the week
		flag = 1;
	}
		
	if(flag == 1){ //if d is not the first day of the week, decrement day in order to compute for the first day of the week
		while(d != 0){
			day--;
			d--;
		}
	}
	
	//looping dor the 7 days in a week
	int i;
	for(i = 1; i <= 7; i++){
		
		if(day < 1){ //if the computed first day is less than 1 then print spaces
			printf("     ");
			day++;
		}
		else if(day > determineDaysInMonths(month)){ //if the computed first day is greater than the number of days in a month then print spaces
			printf("   ");
		}
		else{ //printing the days in a week
			printf("%2d", day );
			printf("   ");
			day++;
		}
		
	}			
}

//function for monthly view
void monthView(int month, int year)
{
	int d, daycode, tempDaycode;
	
	determineMonths(month);
	printf(" %d", year);
	
	determineleapyear(year); //check if given year is leap year
	
	if(startWeek == 1){ //startWeek is Sunday
		printf("\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n" );
		daycode = determineDaycode(year);
	}
	else{ //startWeek is Monday
		printf("\nMon  Tue  Wed  Thu  Fri  Sat  Sun\n" );
		tempDaycode = determineDaycode(year);
		daycode = alterDaycode(tempDaycode);
	}
	
	//every month's daycode	is dependent to the previous months' daycodes
	/*this for loop computes for the daycode of the given month*/
	 int i;
	for (i = 1; i < month; i++ ){
		daycode = ( daycode + determineDaysInMonths(i)) % 7;
	}
				
	//set the position for the first date
	for (d = 1; d <= 1 + daycode * 5; d++ )
	{
		printf(" ");
	}
				
	//print all the dates for one month
	for (d = 1; d <= determineDaysInMonths(month); d++ )
	{
		printf("%2d", d );
			
		//is day before daycode 6 (which is Saturday if startWeek is Sunday & Sunday if startWeek is Monday)? else start next line Sun/Mon.
		if ( ( d + daycode ) % 7 > 0 )
			printf("   ");
		else
			printf("\n " );
	}			
}


void yearView(int month, int day, int year, int counter){
	/*counter functionality: if 1 = it will display the "\n\nInvalid input.\nPlease try again!"
							if 2 = it will not display "\n\nInvalid input.\nPlease try again!"*/
	
	int i = 1,j = 2,k = 3, l = 4;
	int choose, temp, status;
	
	do{
		system("cls");
		printf("Date Specified: %d%d%d",month,day,year);
		monthView(i, year); //display odd positioned months
		monthView(j, year); //display even positioned months
		monthView(k, year);
		monthView(l, year);
		
		do{
			if(counter == 1){ //this if statement checks if the method calling is from the method yearView or from the inputDate or the last month is december
				printf("\n\nInvalid input.\nPlease try again!"); //prints if method calling is from the yearView method and the even positioned month is not december
				counter = 0;
			}
			
			printf("\n\nPress 1 for next, 2 for Previous and 0 for Exit: ");
			status = scanf("%d", &choose);
			while((temp=getchar()) != EOF && temp != '\n'); //used to collect garbage characters (like the enter key when pressed)
			
			if(status != 1){ // check if the user enters a number (status = 0 = not number; status = 1 = number)
				system("cls");
				printf("Date Specified: %d%d%d",month,day,year);
				monthView(i, year);
				monthView(j, year);
				monthView(k, year);
				monthView(l, year);
				printf("\n\nInvalid input.\nPlease try again!");
			}
		}while(status != 1); // while input is not a number
		
		if(choose == 1 && l < 12){
			i+=4; //increment by 2 the odd positioned months 
			j+=4; //increment by 2 the even positioned months 
			k+=4;
			l+=4;
		}
		else if(choose == 2 && i > 1){
			i-=4; //decrement by 2 the odd positioned months 
			j-=4; //decrement by 2 the even positioned months 
			k-=4;
			l-=4;
		}
		else if(choose == 0){
			system("cls");
			main();
		}43
		else{
			if(l == 12) //checks if the last month is december
				yearView(month, day, year, 0);
			else
				yearView(month, day, year, 1); 
		}
	}while(choose != 0);
	
	system("cls");
}


//check if the input year is leap yearm
int determineleapyear(int year)
{
	if(year% 4 == FALSE && year%100 != FALSE || year%400 == FALSE){
		feb= 29;
		return TRUE;
	}
	else{
		feb = 28;
		return FALSE;
	}
}

//compute for the weekday of the first day of the year
int determineDaycode(int year)
{
	/*Below are the corresponding daycodes:
	Sunday: 0
	Monday: 1
	Tuesday: 2
	Wednesday: 3
	Thursday: 4
	Friday: 5
	Saturday: 6
	*/
	int daycode;
	int d1, d2, d3;
	
	d1 = (year - 1.)/ 4.0;
	d2 = (year - 1.)/ 100.;
	d3 = (year - 1.)/ 400.;
	daycode = (year + d1 - d2 + d3) %7;
	return daycode;
}

//alter daycodes if monday is the start of the week
int alterDaycode(int daycode)
{
	/*Since the positioning of the weekdays moved to the left, the daycodes will also change
	Monday: 0
	Tuesday: 1
	Wednesday: 2
	Thursday: 3
	Friday: 4
	Saturday: 5
	Sunday: 6
	*/
	switch(daycode){
		case 0: //sunday
			daycode = 6; //change daycode 0 to 6
			break;
		case 1: //monday
			daycode = 0; //change daycode 1 to 0
			break;
		case 2: //tuesday
			daycode = 1; //change daycode 2 to 1
			break;
		case 3: //wednesday
			daycode = 2; //change daycode 3 to 2
			break;
		case 4: //thursday
			daycode = 3; //change daycode 4 to 3
			break;
		case 5: //friday
			daycode = 4; //change daycode 5 to 4
			break;
		case 6: //saturday
			daycode = 5; //change daycode 6 to 5
			break;	
	}
	return daycode;
}

bool checkDate(int month, int day, int year){
if (year>=1600 && year <=9999)
	{
		if (month>=1 && month <=12)
		{
			if((day>=1 && day<=31) && (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)){
                //printf("Date is valid.\n");
				return 1;                
            }else if((day>=1 && day<=30) && (month==4 || month==6 || month==9 || month==11)){
                //printf("Date is valid.\n");
                return 1;  
            }else if((day>=1 && day<=28) && (month==2)){			
                printf("Date is valid.\n");
                return 1;  
            }else if(day==29 && month==2 && (year%400==0 ||(year%4==0 && year%100!=0))){
                //printf("Date is valid.\n");
                return 1;  
            }else{
			    //printf("Date is invalid.\n");
                return 0;
		}
		}else
        {
            //printf("Date is not valid.\n");
            //main ();
            return 0;
        }
    }
    else
    {
        return 0;
	}
}

//determine the number of days in a month
int determineDaysInMonths(int month){
	switch(month){
		case 1: //1 = 31 days (January)
			month = jan;
			break;
		case 2: //2 = 28 days (February)
			month = feb;
			break;
		case 3: //3 = 31 days (March)
			month = mar;
			break;
		case 4: //4 = 30 days (April)
			month = apr;
			break;
		case 5: //5 = 31 days (May)
			month = may;
			break;
		case 6: //6 = 30 days (June)
			month = jun;
			break;
		case 7: //7 = 31 days (July)
			month = jul;
			break;
		case 8: //8 = 31 days (August)
			month = aug;
			break;
		case 9: //9 = 30 days (September)
			month = sep;
			break;
		case 10: //10 = 31 days (October)
			month = oct;
			break;
		case 11: //11 = 30 days (November)
			month = nov;
			break;
		case 12: //12 = 31 days (December)
			month = dec;
			break;
	}
	
	return month;
}

//determine the corresponding month given a number
void determineMonths(int month){
	switch(month){
		case 1: //1 = January
			printf("\n\nJanuary");
			break;
		case 2: //2 = February
			printf("\n\nFebruary");
			break;
		case 3: //3 = March
			printf("\n\nMarch");
			break;
		case 4: //4 = April
			printf("\n\nApril");
			break;
		case 5: //5 = May
			printf("\n\nMay");
			break;
		case 6: //6 = June
			printf("\n\nJune");
			break;
		case 7: //7 = July
			printf("\n\nJuly");
			break;
		case 8: //8 = August
			printf("\n\nAugust");
			break;
		case 9: //9 = September
			printf("\n\nSeptember");
			break;
		case 10: //10 = October
			printf("\n\nOctober");
			break;
		case 11: //11 = November
			printf("\n\nNovember");
			break;
		case 12: //12 = December
			printf("\n\nDecember");
			break;
	}
}



     

