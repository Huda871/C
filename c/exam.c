/* file name: Exam.c
Created by: Huda AL Rubayawi.  studentnumber: C19738789.  date:  20/04/2020.
this program about security authorisation based on numeric codes. The codes are four (4) single digit integer numbers between 0 and 9. The program allow a user to enter any four digit code or generate a random code, encrypt the code and compare it to a fixed, authorised access code and allow the user to decrypt an already encrypted code. the default authorised access code is 4523 and this cod sorted in a 1 dimentional array called acess code and not allowed to change. i used online compiler onlinegdb.com */


#include <stdio.h>
#include <stdlib.h> // required to generate random integers
#define SIZE 4     // size of array

struct code_counter{
    
int correct_code;
int wrong_code;
};
void enter_code(int*); // first function, will pass down one functions
void encrypted_code(int*);  // second function to encrypt code
void compare_numbers(int*, int*, struct code_counter*);//third function,it will pass down 2 functions to compare
void decrypted_code(int*); // function to decrypt code
void ending(void);
void my_counter(struct code_counter *ptr);

int main()
{
    struct code_counter code={0,0}, *ptr = &code;
    int my_arr1[SIZE];
    int access_code[]={4, 5, 2, 3};
    char menu_choice;
    int opt_A_first=0; //to check if the user picks option A in their first try
    int opt_B_first=0; //to check if the user picks option B in their first try
    int opt_C_first=0; //to check if the user picks option C in their first try
    int opt_D_first=0; //to check if the user picks option C in their first try

        for(;;)     // this loop the menu after each function or invalid choice
    {
        //*******************************************MENU**************************************************
   printf("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
       
           printf("\n\t\t  |================================================| ");
           printf("\n\t\t  | $$$*** Welcome to security Authorization ***$$$| ");
           printf("\n\t\t  |================================================| \n");
    
    printf("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        
    printf("\n++++=====================================================++++\n\n");
    printf("\n  A) Chose A to Enter a code or generate a random code");
    printf("\n  B) Chose B to Encrypt code");
    printf("\n  C) Chose C to Check if the encrypted code matches");
    printf("\n  D) Chose D to Decrypt code");
    printf("\n  E) Chose E to diplay number of times encrypted code");
    printf("\n  F) Chose F to Exit ");
    printf("\n++++=====================================================++++\n\n");
    scanf("%1s",&menu_choice);
        
        // switch case statment to execute the program based on the chosen menu option
       switch(menu_choice)
       {
        case 'a':
        case 'A':
        {
            system("cls");       // clear screen
            enter_code(my_arr1);
            opt_A_first++;     //increment the function so if user choice any option except option A it will desplay
            opt_D_first++;     //  to play one game first
            break;
        }//end case
        case 'b':
        case 'B':
            if(opt_A_first>=1)   // if statement to check user option A is selected first
            {
            printf("Please Choose Your Code First\n");
            }
            else
            {
            system("cls");
            encrypted_code(my_arr1);
            opt_B_first++;
            }
            break;
            
        case 'c':
        case 'C':
        if(opt_B_first<=0)      // if statement to check user has played one game
            {
            printf("Choose the code and Encrypted First\n");
            }
            else
            {
            system("cls");
            compare_numbers(my_arr1,access_code,ptr);
            opt_C_first++;

            }
            break;

        case 'd':
        case 'D':
        if(opt_B_first<=0)    // to check user has played one game
            {
            printf("Choose the code and Encrypted First\n");
            }
            else
            {
            system("cls");
            decrypted_code(my_arr1);
            }
            break;

        case 'e':
        case 'E':
        if(opt_C_first<=0)
            {
            printf("Choose the code and Encrypted and Compared First\n");
            }
            else
            {
            system("cls");
            my_counter(ptr);    // calling the function commonness and pass one array
            }
            break;

        case 'f':
        case 'F':
        {
            system("cls");
            ending();        //calling the function ending
            break;
        }// default statements executed if expression does not equal
        default:
        {
        printf("Invalid choice please choose between A to F only\n");
        }//end default
       }// end switch
    }// end for
            
    return 0;
}// end
//Implement function enter_code
/*in this function user will choose number 1 to enter the 4 diget numer or code or choose 2 to generate a random code 0000 – 9999 inclusive.
 */
void enter_code(int *numbers)
{
    int i;
    int choice;   // this fuction is for stat and ask user to choos code
    
       printf("\n&&&&&&&&&&&&&&&&$$$$$$$******************$$$$$$$&&&&&&&&&&&&&&&\n");
       printf("\n please choose 1 to Enter a code or 2 to generate a random code");
       printf("\n________________________________________________________________\n\n");
       scanf("%d",&choice);
    
    if(choice == 1)        // if statment for user chose 1 then can enter 4 diget numbers
    {
      printf("\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
      printf("\n  Please enter 4 numbers between 1 to 9 only \n ");
      printf("\n================================================\n\n");
     for(i = 0; i < SIZE; i++)
    {
        scanf("%d", & *(numbers + i));
        
        if (*(numbers + i) > 9)
        {
            printf("\n          RESTART         \n");
            printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
            printf("\n\t Your number is out of range\n");
            printf("\n=================================\n\n");
            return;
        }//end if
    }//end for
    }//end if
    if(choice == 2)   // if statment if user chose number 2 then generate a random code betwee (0000-9999)
    {
        for(i = 0; i < SIZE; i++)
        {
            *(numbers + i)= rand()%9+0;
        }
        
        printf("\n&&&&&&&&&&&&&&&&&&&&&&&&\n");
        printf("\n\t Your numbers are:\n");
        printf("\n======================\n\n");
        for(i = 0; i < SIZE; i++)
        {
            printf("%d",*(numbers + i));
        }
    printf("\n++++++++++++++++++++++++++++++++\n\n");
    }
}// end void enter_code

/*Implement function encrypted_code */
/*this function Encrypt the code entered. Swap the 1st number with the 3rd number and Swap the 2nd number with the 4th number and add 1 to each number. If any number has a value equal to 10 it change this value to 0. */
void encrypted_code(int *arr)
{
    int i, temp1, temp2;
    
    temp1= *(arr)+1;      // this part swap and encrypt the code swapp the first with 3rd and 2nd with 4th and add 1 to
    *(arr) = *(arr+2+1);  //each number
    *(arr+2) =temp1;

    temp2= *(arr+1)+1;
    *(arr+1) = *(arr+3)+1;
    *(arr+3) =temp2;

    for(i = 0; i < SIZE; i++)  // here  If any number has a value equal to 10 it change this value to 0.
    {
        if(*(arr+i) == 10)
        {
            *(arr+i) = 0;
        }
    }
    printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");    //to print encrypt code
    printf("\n\t   Your Encrypted Code is :\n");
    printf("\n====================================\n\n");
    
    for(i = 0; i < SIZE; i++)          // for loop to print the encrypt code
    {
    printf("%d", *(arr+i));
    }
}// end encrypted_code

/*Implement function compare_numbers */
/* function to compere the encrypted code with the access code [4523] stored in the 1- Dimensional array called access_code. and if the two codes match displayed a message of “Correct Code entered”. If the two codes do not match it display a message saying “Wrong Code entered */
void compare_numbers(int *my_array, int *arr2, struct code_counter *ptr)
{
    int i;
    
    for( i = 0; i < SIZE; i++)
    {
        printf("%d", *(my_array+i)); // for loop to compare the encrypted code with the access code [4523] stored
    }
        printf("\n\n");
    for(i = 0; i < SIZE; i++)
    {
        printf("%d", *(arr2+i));
    }
    for(i = 0; i < SIZE; i++)
    {
            if(*(my_array+i) == *(arr2+i))    //if the two codes match displayed a message of “Correct Code entered”
            {
                    (*ptr).correct_code++ ;
            printf("\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");     // to print the correct code
            printf("\n\t Correct Code entered:\n");
            printf("==================================\n\n");
            break;
            }                                                //If the two codes do not match it display a message saying
            else                                             //“Wrong Code entered
            {
                (*ptr).wrong_code++ ;
            printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");     // to print the wrong code
            printf("\n\t sorry, Wrong Code entered :\n");
            printf("===================================\n\n");
            break;
            }//end if

        }// end for
}// end compare_numbers
/*Implement function decrypted_code */
/*this function about decrypt and encrypted code and it subtract 1 from each number and if any number has a value equal to -1 it will change this value to 9 and it will Swap the 1st number with the 3rd number and Swap the 2nd number with the 4th number.*/
void decrypted_code(int *arr3)
{
    int i, temp1, temp2;
    
    temp1= *(arr3)-1;     // using swap again number 1 by 3 and number two by four and decryment by subtract 1 from each
    *(arr3) = *(arr3+2)-1;
    *(arr3+2) =temp1;

    temp2 = *(arr3+1)-1;
    *(arr3+1) = *(arr3+3)-1;
    *(arr3+3) = temp2;

    for(i = 0; i < SIZE; i++) // this forloop for any number has a value equal to -1 it will change this value to 9
    {
        if(*(arr3+i) == -1)
        {
            *(arr3+i) = 9;
        }
    }
    printf("\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");  // to print the decrypted code
    printf("\n\t your decrypted Code is :\n");
    printf("\n==============================\n\n");
    for(i = 0; i < SIZE; i++)
    {
    printf("%d", *(arr3+i));
    }
}// end decrypted_code
//Implement function my_counter
/*this function display the number of times the encrypted code is correct and/or wrong in each run of the program.
*/
void my_counter(struct code_counter *ptr)
{
    printf("\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
    printf("\n\t Number of correct is:%d \n",ptr->correct_code);
    printf("\n\t Number of wrong is:%d \n",ptr->wrong_code);
    printf("\n================================================\n\n");

}// end my_counter
/*Implement function ending */
/* this function tell user to choos eixt the program or back to menu*/
void ending()
{
    char user_decision ;
    while(1)
    {
    
          printf("\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
          printf("\n Press y to Exit program if press n will back to Menu\n");
          printf("\n---------------------------------------------------------\n\n");
            scanf("%c",&user_decision);
        
            if(user_decision == 'y') //using if end else to aske the user choos y to exet by zero
            {
            exit(0);
            }
            else if(user_decision == 'n') // else if to ask user if choos n then will return to start mmenu
            {
             return;
            }// end if
    }// end while
}// end function

 
