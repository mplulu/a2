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
int main(int argc, char* argv[])
{
    GJCType gjc;
    int initFlag, dataFlag, exitFlag=FALSE;
    char c[MAX_OPTION_INPUT+EXTRA_SPACES];
    /* Initialise the Gloria Jean's Coffee system to a safe empty state. */
    initFlag = systemInit(&gjc);

    /* Populate the Gloria Jean's Coffee system with data from the data files. */
    /* Uncomment this line when you are ready to use command line arguments:*/
    if(argv[1]==NULL||argv[2]==NULL){
	printf("No argument found\n");
	exit(EXIT_SUCCESS);
    }


    dataFlag = loadData(&gjc, argv[1], argv[2]); 

    /* Testing to see if both systemInit(.) and loadData(.) are ok */
    if (initFlag == FAILURE || dataFlag == FAILURE){
	exit(EXIT_FAILURE);
    }


    /* Interactive menu providing user with access to the 9 menu options */
    while(exitFlag==FALSE){
	printf("Main Menu:\n");


	printf("(1) Hot Drinks Summary\n");
	printf("(2) Cold Drinks Summary\n");
	printf("(3) Detailed Menu Report\n");
	printf("(4) Add Menu Category\n");
	printf("(5) Delete Menu Category\n");
	printf("(6) Add Menu Item\n");
	printf("(7) Delete Menu Item\n");
	printf("(8) Save & Exit\n");
	printf("(9) Abort\n");
	printf("Select your option (1-9):");

	fgets(c,MAX_OPTION_INPUT+EXTRA_SPACES,stdin);
	if(c[0]=='\n'){
	    printf("Invalid input\n");
	}else if(stringIsInRange(c,MAX_OPTION_INPUT)==FALSE){
	    readRestOfLine();
	    printf("Invalid input\n");
	}else{
	    stripNewLine(c);
	    if(strcmp(c,"1")==0){
		displaySummary(&gjc,HOT);	        
	    }else if(strcmp(c,"2")==0){
		displaySummary(&gjc,COLD);	        
	    }else if(strcmp(c,"3")==0){
	    }else if(strcmp(c,"4")==0){
	    }else if(strcmp(c,"5")==0){
	    }else if(strcmp(c,"6")==0){
	    }else if(strcmp(c,"7")==0){
	    }else if(strcmp(c,"8")==0){
	    }else if(strcmp(c,"9")==0){
		exitFlag=TRUE;
	    } 
	}
    }

    /* Deallocate all dynamically allocated memory. */
    systemFree(&gjc);

    exit(EXIT_SUCCESS);

}
