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
}


/****************************************************************************
 * Loads all data into the system.
 ****************************************************************************/
int loadData(GJCType *menu, char *menuFile, char *submenuFile)
{
    FILE *menu=fopen(menuFile,"r");
    FILE *submenu=fopen(submenuFile,"r");
    
    int flag;
    
    if(menu==NULL||submenu==NULL){
	prinf("Unable to open file\n");
	flag=0;
    }else{
	/*work on menu*/
	char line[MAX_LINE_SIZE];
	while ( fgets ( line,MAX_LINE_SIZE, menu ) != NULL ) {
	    stripNewLine(line);
	    printf("%s\n",line);
	}

	flag=1;
    }

    fclose(menu);
    fclose(submenu);
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



