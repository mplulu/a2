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
#include "string.h"

/****************************************************************************
 * Function readRestOfLine() is used for buffer clearing.
 * Please refer to "test_fgets.c" on Blackboard:
 * "Course Documents"->"Function Examples"->"Input Validation Examples"
 ****************************************************************************/
void readRestOfLine()
{
    int c;

    /* Read until the end of the line or end-of-file. */
    while ((c = fgetc(stdin)) != '\n' && c != EOF)
	;

    /* Clear the error and end-of-file flags. */
    clearerr(stdin);
}


/****************************************************************************
 * Initialises the system to a safe empty state.
 ****************************************************************************/
int systemInit(GJCType *menu)
{
    menu->numCategories=0;
    return 1;
}


/****************************************************************************
 * Loads all data into the system.
 ****************************************************************************/
int loadData(GJCType *menu, char *menuFile, char *submenuFile)
{
    FILE *menuPtr=fopen(menuFile,"r");
    FILE *submenuPtr=fopen(submenuFile,"r");

    int flag;

    if(menuPtr==NULL||submenuPtr==NULL){
	printf("Unable to open file\n");
	flag=0;
    }else{
	/*work on menu*/
	char line[MAX_LINE_SIZE];
	while ( fgets ( line,MAX_LINE_SIZE, menuPtr ) != NULL ) {

	    char *tokens[MAX_TOKENS_MENU];

	    splitString(tokens,line,"|");
	    initMenuDataItem(menu,tokens);

	}
	
	while ( fgets ( line,MAX_LINE_SIZE, submenuPtr ) != NULL ) {
	    char *tokens[MAX_TOKENS_SUBMENU];

	    splitString(tokens,line,"|");
	    initSubmenuDataItem(menu,tokens);

	}
	flag=1;
	fclose(menuPtr);
    }




    return flag;


}



/****************************************************************************
 * Deallocates memory used in the program.
 ****************************************************************************/
void systemFree(GJCType *menu)
{
}

/*
   check if string is in range and strip new line(\n) for managing input
 */
void stripNewLine(char *s){
    int i=0;
    while(s[i]!='\0'&&s[i]!='\n'){
	i++;
    }
    s[i]='\0';
}

int stringIsInRange(char *s,int range){
    int i=0;
    while(s[i] != '\0' && s[i] != '\n'){
	i++;
    }
    return i<=range?TRUE:FALSE;
}

int splitString(char *tokens[],char *string,char *delimiter){
    int i=0;
    tokens[i]=strtok(string,delimiter);
    while(tokens[i]!=NULL){
	i++;
	tokens[i]=strtok(NULL,delimiter);
    }
    return SUCCESS;
}

PriceType parsedPrice(char *stringValue){
    PriceType price;
    price.dollars=atoi(strtok(stringValue,"."));
    price.cents=atoi(strtok(NULL,"."));
    return price;


}

int initMenuDataItem(GJCType *gjc, char *tokens[]){
    CategoryType *newCategory=malloc(sizeof(CategoryType));
    CategoryType *cur=gjc->headCategory;
    int i=0;
    
    if(newCategory!=NULL){
	strcpy(newCategory->categoryID,tokens[0]);
	strcpy(newCategory->categoryName,tokens[2]);
	newCategory->categoryType=tokens[1][0];
	strcpy(newCategory->categoryDescription,tokens[3]);
	newCategory->numItems=0;
    }else{
	return FAILURE;
    }
    if(gjc->numCategories==0){
	gjc->headCategory=newCategory;
    }else{
	while(i+1<gjc->numCategories){
	    cur=cur->nextCategory;
	    i++;
	}
	cur->nextCategory=newCategory;
    }

    gjc->numCategories+=1;
	
    return SUCCESS;

}


int initSubmenuDataItem(GJCType *gjc,char *tokens[]){
    ItemType *item=malloc(sizeof(ItemType));


    CategoryType *cur=gjc->headCategory;
    char categoryID[ID_LEN+1];
    PriceType prices[NUM_PRICES];
    int i=0;

    if(item==NULL){
	return FAILURE;
    }

    strcpy(item->itemID,tokens[0]);
    strcpy(categoryID,tokens[1]);
    strcpy(item->itemName,tokens[2]);
    
    /*price*/
    prices[0]=parsedPrice(tokens[3]);
    prices[1]=parsedPrice(tokens[4]);
    prices[2]=parsedPrice(tokens[5]);
    item->prices=prices;


    strcpy(item->itemDescription,tokens[6]);


    while(i<gjc->numCategories){
	if(strcmp(cur->categoryID,categoryID)==0){
	    if(cur->numItems==0){
		cur->headItem=item;
		
	    }else{
		int j=0;
		ItemType *curItem=cur->headItem;
		while(j+1<cur->numItems){
		    curItem=curItem->nextItem;
		    j++;
		}
		curItem->nextItem=item;
		
	    }
	    cur->numItems+=1;
	    break;
	}else{
	    cur=cur->nextCategory;
	    i++;
	}
    }
    return SUCCESS;

}
    

