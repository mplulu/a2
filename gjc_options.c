/****************************************************************************
 * COSC2541 - Programming Techniques
 * Semester 2 2011 Assignment #2
 * Full Name        : Dang Nguyen Hoang Gia 
 * Student Number   : s3269900
 * Start up code provided by Christopher Hoobin, Xiaodong Li and Quang Tran
 ****************************************************************************/

#include "gjc.h"
#include "gjc_options.h"
#include "gjc_utility.h"

/****************************************************************************
 * Menu option #1: Display Summary
 * Allows the user to display a summary of all hot or cold drink categories
 * and items.
 ****************************************************************************/
void displaySummary(GJCType *menu, char categoryType)
{
    int i=0;
    CategoryType *cur=menu->headCategory;

    printf("%s Drinks Summary\n",categoryType==HOT?"Hot":"Cold");
    printf("-----------------------\n");

    while(i<menu->numCategories){
	int j=0;
	ItemType *curItem=cur->headItem;

	if(cur->categoryType==categoryType){
	    printf("%s - %s (%d items)\n",cur->categoryID,cur->categoryName,cur->numItems);
	    printf("---------------------------------------\n");
	    printf("ID    Name                 Small  Med   Large\n");
	    printf("----- -------------------  -----  ----- -----\n");

	    while(j<cur->numItems){

		printf("%s %s             $%d.%d $%d.%d $%d.%d \n",curItem->itemID,curItem->itemName,curItem->prices[0].dollars,curItem->prices[0].cents,curItem->prices[1].dollars,curItem->prices[1].cents,curItem->prices[2].dollars,curItem->prices[2].cents);
		j++;
		curItem=curItem->nextItem;
	    }

	    printf("\n");



	}
	cur=cur->nextCategory;
	i++;
    }
}


/****************************************************************************
 * Menu option #2: Category Report
 * Allows the user to make a new report file for a chosen category.
 ****************************************************************************/
void categoryReport(GJCType *menu)
{
}


/****************************************************************************
 * Menu option #3: Add Category
 * Allows the user to add a new category record to the linked list.
 ****************************************************************************/
void addCategory(GJCType *menu)
{
}


/****************************************************************************
 * Menu option #4: Delete Category
 * Deletes a category and all corresponding items.
 ****************************************************************************/
void deleteCategory(GJCType *menu)
{
}


/****************************************************************************
 * Menu option #5: Add Item
 * Allows the user to add a new item to an existing category. An error
 * message is given if the category doesn't exist.
 ****************************************************************************/
void addItem(GJCType *menu)
{
}


/****************************************************************************
 * Menu option #6: Delete Item
 * Deletes a single item from a particular category.
 ****************************************************************************/
void deleteItem(GJCType *menu)
{
}


/****************************************************************************
 * Menu option #7: Save and Exit
 * Saves all system data back to the original files. This function does not
 * terminate the program - this is left to the main() function instead.
 ****************************************************************************/
void saveData(GJCType *menu, char *menuFile, char *submenuFile)
{
}
