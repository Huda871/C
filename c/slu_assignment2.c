//
//  main.c
//
/* assignment2 of semester 2
    This program will play the Lotto game. This program allows the user to enter their 6 selected
    numbers and they have a set of options, each performing a specific requirement. 6 selected
    numbers are stored in a 1-Dimensional array.
    Using functions and pointer notations to access array*/
//
//  Created by Huda Al Rubayawi on 01/03/2020.
//  Copyright © 2020 huda. AllRubayawi rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define USER 6 // enternumbers, displaynumbers, sortnumbers and comparenumbers functions
#define LOTTO 6 // global array for fourth function
#define SIZE 42 //the size of the lotto numbers

//Declare prototypes
void enternumbers(int*,int*); // first function, will pass down 2 functions
void displaynumbers(int*); // second function
void sortnumbers(int*); //third function
void comparenumbers(int*,int*); // fourth function , it will pass down 2 functions to compare
void frequencynumbers(int *frq); //fifth function
void ending(void);

int main()
{
    char choice_menu;

    int winning_number[LOTTO] = {1,3,5,7,9,11}; //winning numbers array. comparenumbers function uses this array

    int repeat[SIZE+1] = {0}; // the array element starts at 0 so SIZE +1 will put a number inside element 0

    int arr1[USER];   // the array name for user input

    int option_1 = 0; //to check if the user picks option 1 in their first try
    int option_2 = 0; //to check if the user picks option 2 in their first try
    int option_3 = 0; //to check if the user picks option 3 in their first try
    int option_4 = 0; //to check if the user picks option 4 in their first try

    while(1)// do the following loop forever
    {
        //Menu
        printf("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
           
               printf("\n\t\t  |=========================================| ");
               printf("\n\t\t  | $$$*** Welcome to the LOTTO GAME  ***$$$| ");
               printf("\n\t\t  |=========================================| \n");
        
        printf("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");

        printf("\n++++==================================================++++\n\n");
        printf("\n  A) press A to Choose your 6 lucky numbers");
        printf("\n  B) press B to Display your 6 lucky numbers");
        printf("\n  C) press C to Your Lucky numbers sorted in Increasing Order ");
        printf("\n  D) press D to Compare your chosen numbers with the wining numbers");
        printf("\n  E) press E to Check the frequency of numbers you have entered");
        printf("\n  F) press F to Exit game \n");
        printf("\n++++===================================================++++\n\n");
        scanf("%1s",&choice_menu);

        // switch case statment to execute the program based on the chosen menu option
    switch(choice_menu)
    {
        case 'a':
        case 'A':
        {
            enternumbers(arr1,repeat);
            option_1++;
            option_2++;
            option_3++;
            option_4++;
            break;
        }//end case
        case 'b':
        case 'B':
            if(option_1 <= 0)
            {
            printf("\tPlease Choose Your Numbers First\n");
            }//end if
            else
            {
            displaynumbers(arr1);
            }//end else
            break;

        case 'c':
        case 'C':
        if(option_2 <= 0)
            {
            printf("\tPlease Choose Your Numbers First\n");
            }// end if
            else
            {
            sortnumbers(arr1);
            }//end
            break;

        case 'd':
        case 'D':
        if(option_3 <= 0)
            {
            printf("\tPlease Choose Your Numbers First\n");
            }// end if
            else
            {
            comparenumbers(winning_number,arr1);
            }// end else
            break;

        case 'e':
        case 'E':
        if(option_3 <= 0)
            {
            printf("\tPlease Choose Your Numbers First\n");
            }// end if
            else
            {
            frequencynumbers(repeat);
            }// end else
            break;

        case 'f':
        case 'F':
        {
            ending();
            break;
        }// default statements executed if expression does not equal.
        default:
        {
            //showing error message for invalid meun option
            printf("\tInvalid choice please choose between A to F only\n");
        }//end default
    }
    }//end switch
}//end main


/*Implement function enternumbers */
/*This functions reads in the 6 lotto numbers that the user has picked */
//my_Array are the ones that the user has selected for the lotto
//rep pointer determines how many times a certain number has been inputted
void  enternumbers(int *my_Array, int *rep)
{
    int i,j;

    int temp; // a temporary variable to hold each number inputted

        printf("\n\t\t\t  |===========================| ");
        printf("\n\t\t\t  | $$$***  LOTTO GAME  ***$$$| ");
        printf("\n\t\t\t  |===========================| \n");

        printf("\n\t ***|   Please enter your 6 lucky numbers   |***");
        printf("\n\t    |_______________________________________| \n");

    for(i = 0; i < USER; i++)
    {
        scanf("%d", & *(my_Array + i));
        /* the if statement checks if the user inputs numbers outside the range of 1 - 42 */
        if ( *(my_Array + i) >= 1 && *(my_Array + i) <= 42)
        {
            /*this checks if the user inputs the same number inside the array */
            for(j=0; j < i;j++)
            {
                if(*(my_Array +i) == *(my_Array +j))
                {
                    
                    printf("\n\t  ***| Please Don't use the same numbers |***");
                   
                    return;
                }//end inner if
            }//end inner for loop for checking
        }//end if
        /* the else statement confirms that the user input numbers outside the range of 1 - 42 */
        else
        {

            printf("\n\t\t ***| Please Choose Numbers Within the Range of 1 to 42 |***");
            printf("\n\t      |___________________________________________________| \n");
            break;/*allows the function to be executed again untill user inputs correct
                    numbers */
        }//end else

        temp= *(my_Array + i);/*outs each number inputted by user into the respective array
                             element */
        *(rep +temp) = *(rep +temp) +1; /*this gets incremented to determine how many
                                        times a certain number has been inputted by
                                        the user during the course of the */
}// end for
}//end function void enternumbers


/* Implement function displaynumbers */
/*This function displays the lotto numbers inputted by the user */
void displaynumbers(int *arr2)
{
    int i;

        printf("\n\t\t ***| Your Lucky numbers are |***:");
        printf("\n\t\t    |________________________|  \n");

    for(i=0; i < USER; i++)
    {
        printf("\t%d", *(arr2+i));
    }//end for

    printf("\n\n");
}// end function 2 displaynumbers


/*Implement function sortnumbers */
/*This function sorts the 6 lotto numbers in ascending order e.g 1,2,3,4..... */
void sortnumbers(int *arr3)
{
    int i,j,temp;

    for(i= 0; i < USER-1; i++)
    {
        for(j= i+1; j < USER; j++)
        {
         if(arr3[i] > arr3[j])
         {
            //
             temp = arr3[i];
             arr3[i] = arr3[j];
             arr3[j] = temp;
         }// end if
        }// end inner for
    }// end outer for

        printf("\n**| Your Lucky numbers sorted in Increasing Order are |**:");
        printf("\n  |___________________________________________________|\n\n");

    for(i=0; i< USER; i++)
    {
        printf("\t%d", *(arr3 + i));
    }// end for

        printf("\n\n");
}// end function sortnumbers


/*Implement function 4  comparennumbers*/
/*this function compares the winning lotto numbers with the user's chosen lotto numbers */
//compare are winning numbers and values are user input
void comparenumbers(int *winning, int *arr4)
{
    int i,j;

    int match = 0;

        printf("\n\t\t***| The 6 Winning Numbers are |*** :\n");
        printf("\n\t\t   |___________________________|   \n\n");

    for(i=0; i< LOTTO; i++)
    {
        printf("\t%d", *(winning + i));
    }

        printf("\n\n");

        printf("\n\t\t***| Your 6 Lucky numbers are |***:\n");
        printf("\n\t\t   |__________________________|\n\n");

    for(i=0; i< LOTTO; i++)
    {
        printf("\t%d", *(arr4+i));
    }

        printf("\n\n");

    for(i=0; i< LOTTO; i++)
    {
        for(j=0; j< LOTTO; j++)
        {
            if(*(winning+j)== *(arr4+i))
            {
                match++;
            }// end if
        }// end inner for loop
    }// end outer for loop

    /*These determines if the user wins anything */
     if(match == 6)
    {
        printf("\n\t\t***| You wone a Jackpot |***\n");
        printf("\n\t\t   |____________________| \n\n");
    }//end if
    else if(match == 5)
    {
        printf("\n\t\t***| Congratulation, You Win A New Car |***\n");
        printf("\n\t\t   |$$$$$$***********************$$$$$$| \n\n");
    }// end else if
    else if(match == 4)
    {
        printf("\n\t\t***|Congratulation, You Win A Weekend Away|*** \n");
        printf("\n\t\t   |$$$$$$$************************$$$$$$$|  \n\n");
    }
    else if(match == 3)
    {
        printf("\n\t\t***|waaaaw, You Win A Cinema Pass|*** \n");
        printf("\n\t\t   |$$$$$$$***************$$$$$$$|  \n\n");
    }
    else
    {
        printf("\n\t\t |Sorry, You lost. Try another time| \n");
        printf("\n\t\t |.................................| \n\n");
    }//end if
}//end fuction comparnumbers


/*Implement function 5 frequencynumbers */
/*This function keeps track on how many times a particular number has been inputted by the user */
void frequencynumbers(int *frq)
{
    int i;
        printf("\n\t\t  |===========================| ");
        printf("\n\t\t  | $$$***  LOTTO GAME  ***$$$| ");
        printf("\n\t\t  |===========================| ");

    for(i=0; i < SIZE+1; i++)
    {
         //if statement displays how many times a certain number has been inputted
        if(*(frq + i) != 0)
        {
            printf("\n\t\t Number %d has been selected %d times \n", i, *(frq +i));
        }
    }

    printf("\n\t\t=========================================\n\n");
}// end function frequencynumbers


void ending()
{
    while(1) // do the following loop forever
    {
        // asking user if want to contine with play or want to end the play

        printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
        printf("\n Are you sure you want to exit the program ??!!  Y for Yes and N for No \n");
        printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n");
        
        char user_decision;
        scanf("%1s", &user_decision);

        switch(user_decision)
        {
        case'y': // user can press y for yes to end the game
        case'Y':
            {
                exit(0); //  ending lotto
                break;
            }
        case'n':  //user choise n for no to repide the play again
        case'N':
            {
                main(); // back to main
                break;
            }// default statements executed if expression does not equal
                       // any case constant_expression
        default:
            {
                printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
                printf("\n\t Invalid value please choose between Y or N only\n ");
                printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
            }//end default
        }// end switch
    }// end while
}// end void ending

