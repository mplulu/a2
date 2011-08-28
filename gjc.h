/****************************************************************************
* COSC2541 - Programming Techniques
* Semester 2 2011 Assignment #2
* Full Name        : Dang Nguyen Hoang Gia 
* Student Number   : s3269900
* Start up code provided by Christopher Hoobin, Xiaodong Li and Quang Tran
****************************************************************************/

#ifndef GJC_H
#define GJC_H

/* System-wide header files. */
#include <stdio.h>
#include <stdlib.h>

/* System-wide constants. */
#define ID_LEN 5
#define MIN_NAME_LEN 1
#define MAX_NAME_LEN 25
#define MIN_DESC_LEN 1
#define MAX_DESC_LEN 250
#define NUM_PRICES 3
#define HOT 'H'
#define COLD 'C'

#define SUCCESS 1
#define FAILURE 0

/*
   my define constant here
*/
/* This is used to compensate for the extra character spaces taken up by
   the '\n' and '\0' when user is asked for input through fgets(). */
#define EXTRA_SPACES 2

/* Specifies the maximum input length a user can enter for the options
 menu. */
#define MAX_OPTION_INPUT 1
#define MAX_LINE_SIZE 555

#define MAX_TOKENS_MENU 4
#define MAX_TOKENS_SUBMENU 7 

#define TRUE 1
#define FALSE 0
typedef struct category *CategoryTypePtr;
typedef struct item *ItemTypePtr;

/* Structure definitions. */
typedef struct price
{
   unsigned dollars;
   unsigned cents;
} PriceType;

typedef struct item
{
   char itemID[ID_LEN + 1];
   char itemName[MAX_NAME_LEN + 1];
   PriceType prices[NUM_PRICES];
   char itemDescription[MAX_DESC_LEN + 1];
   ItemTypePtr nextItem;
} ItemType;

typedef struct category
{
   char categoryID[ID_LEN + 1];
   char categoryName[MAX_NAME_LEN + 1];
   char categoryType; /* (H)ot or (C)old. */
   char categoryDescription[MAX_DESC_LEN + 1];
   CategoryTypePtr nextCategory;
   ItemTypePtr headItem;
   unsigned numItems;
} CategoryType;

typedef struct gjc
{
   CategoryTypePtr headCategory;
   unsigned numCategories;
} GJCType;

#endif
