# Gregorian Calendar

## 1 Description

#### This program will generate the Gregorian calendar of a specific date. The format of the calendar maybe: day, week, month, year.

### 1.1 Date

#### The user will specify the date that he wants to view. The user will provide the date as one integer value, following the format ```mmddyyyy```, e.g. 10082017

### 1.2 View

#### The calendar of the specified date will be shown. The format of the calendar shown depends on the current settings of View Format.

#### 1.2.1 Day View

#### In this view, the month (in words), day, year and weekday is displayed on screen. See Figure 1(a).

#### 1.2.2 Week View

#### In this view, the week that contains the specified date is shown. The display must contain month (in words) and year, days in that week and their specific weekdays. See Figure 1(b).

#### 1.2.3 Month View

#### In this view, the entire month that contains the specified date is displayed on the screen. See Figure 1(c).
### Figure 1: Different View Formats
```
(a)Day View
```
```
Date Specified: 06102011
```
```
December 3, 2017
(Sunday)
```

```
(b)Week View
```
```
Date Specified: 12082017
```
```
December 2017
M T W H F S S
4 5 6 7 8 9 10
```

```
(c)Month View
```
```
Date Specified: 12252017
```
```
December 2017
M T W H F S S
1 2 3
4 5 6 7 8 9 10
11 12 13 14 15 16 17
18 19 20 21 22 23 24
25 26 27 28 29 30 31
```



#### 1.2.4 Year View with navigation

#### In this view, the calendar of the entire year that is specified in date is displayed on screen. If the specified date is 07191954, the calendar must show January 1, 1954 until December 31, 1954. Since the 12-month calendar will not fit in one screen, navigation must be provided to allow the user to see the entire calendar. Assume that each screen (page) can only display 4 months (say January 1954 to April 1954), navigation like previous and back allows the user to move from one page to another. When the user presses Next, the next 4 months of the calendar will be shown (i.e. May 1954 to August 1954). When the user presses Previous, the display should show the previous 4 months (January 1954 to April 1954). The month is represented using numbers 1 – 12, where 1 is for January, 2 for February, 3 for March,...

### 1.3 First day of the Week
#### First day of the week may be specified by the user. There are only two options for this, either Sunday or Monday. The calendar displayed on the screen is affected by the specified first day of the week. Refer to Figure 2. By default, the first day of the week is set to Monday.

### Figure 2: Calendar View Depends on the First Day of the Week
```
(a)Week starts on a Monday.
```
```
Date Specified: 06102011
```
```
June 2011
M T W H F S S
6 7 8 9 10 11 12
```

```
(b)Week starts on a Sunday.
```
```
Date Specified: 06102011
```
```
June 2011
S M T W H F S
5 6 7 8 9 10 11
```
```
(b)Week starts on a Sunday.
```


## 2 Requirements

### The program is menu-driven. The user may execute different tasks by selecting an option in the menu. After execution of each task, the main menu is presented again. The program will only end when the user chooses the Exit option in the main menu.

### The program validates input data. Data entered by the user is validated. Erroneous data should not cause the program to end or crash. When data provided is not valid, the user is informed, and the user will be asked to input until a valid entry is provided.

### The program may be customized. The user may change the settings ofKalendaryo. By default, the view format isDay, and the start of the week isMonday.

### The program dates are aligned. The calendar displayed on screenmustbe properly formatted. Specifically, each day must be right aligned to its corresponding weekday.

### The program program has user-defined functions and uses of appropriate constructs The implementation of this application must contain user-defined functions, wherever applicable and possible. Use the appropriate constructs while developing this application. No functions or use of brute force solutions will mean ano submission of the project.