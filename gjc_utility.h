/****************************************************************************
* COSC2541 - Programming Techniques
* Semester 2 2011 Assignment #2
* Full Name        : Dang Nguyen Hoang Gia 
* Student Number   : s3269900
* Start up code provided by Christopher Hoobin, Xiaodong Li and Quang Tran
****************************************************************************/

#ifndef GJC_UTILITY_H
#define GJC_UTILITY_H


/* Function prototypes. */
void readRestOfLine();
int systemInit(GJCType*);
int loadData(GJCType*, char*, char*);
void systemFree(GJCType*);
int stringIsInRange(char*,int);
void stripNewLine(char*);
#endif
