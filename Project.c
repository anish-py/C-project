#include<stdio.h>
#include <stdlib.h>

#include<string.h>
#include <unistd.h>


void castVote();
void votesCount();
void getLeadingCandidate();
void login();



char CANDIDATE_COUNT[4]; 

char CANDIDATE1[] = "Balen Shah";   
char CANDIDATE2[] = "Gopi Hamal";
char CANDIDATE3[] = "Milan Bastola";
char CANDIDATE4[] = "Rajesh Hamal";



void login() {
   #define FILENAME "password.txt"
   


    int voterID;
    int inputvoterID;
    int found=0;
    
    FILE *file;

    
    file = fopen(FILENAME, "r");
    
    if (file == NULL) {
    	
        printf("Error opening file.\n");
      
    }
	
          top:
    printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############      WELCOME TO LOGIN PAGE                        ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");

    printf("\n\n\nEnter voter ID:  ");
    scanf("%d", &inputvoterID);
    
    
system("cls");
    
while (fscanf(file, "%d", &voterID) == 1) {
        if (inputvoterID == voterID) {
            found = 1;
            break; 
        }
    }

    fclose(file);

    if (found) {
        printf("Login successful!\n");
        sleep(2);
        system("clear");
         	
        int choice;  

    do{
    	
    	
       printf("\n\n ###### Welcome to Presidental election voting #####");
        printf("\n\n 1. Cast the Vote");
        printf("\n 2. Find Vote Count");
        printf("\n 3. Find leading Candidate");
        printf("\n 0. Exit");

        printf("\n\n Please enter your choice : ");
        scanf("%d", &choice);
        
        
        
		
		system("cls");



        switch(choice) {
        	
        	
            case 1: castVote(); break;
            case 2: votesCount(); break;
            case 3: getLeadingCandidate(); break;
            case 0: break; 
            default: printf("\n Error: Invalid Choice");
            sleep(4);
     system("cls");           
            
            
        }
        
    }while(choice != 0);
    getchar();
   
}
    
	
	else {
		
		
             printf("\t\t\t###########################################################################");
   
    printf("\n\t\t\t############Invalid voter id: You are not in the voter list  ############");
   
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t Please re-enter voter id ");
    printf("\n\t\t\t----------------------------------------------------------------------------\n");

 sleep(4);
     system("cls");
goto top;
    }
    }



int votescount1=0, votescount2=0, votescount3=0, votescount4=0, novotes=0;

void castVote(){
	
    int choice;
	
	    
    printf("\n\n !! Please choose your Candidate !! ");
    
printf("\n 1. %s", CANDIDATE1);
printf("\n 2. %s", CANDIDATE2);
printf("\n 3. %s", CANDIDATE3);
printf("\n 4. %s", CANDIDATE4);
printf("\n 5. %s", "None of These");

printf("\n\n Input your choice (1 - 5) : "); 
scanf("%d",&choice);

switch(choice){
	
    case 1: votescount1++; break;
    case 2: votescount2++; break;
    case 3: votescount3++; break;
    case 4: votescount4++; break;
    case 5: novotes++; break;
     
 
             getchar();
             
}
     system("cls");

printf("\n Thank you for the vote !!");

sleep(4);
     system("cls");

login();
}

void votesCount(){
	
printf("\n\n ##### Voting Statistics ####");
printf("\n %s - %d ", CANDIDATE1, votescount1);
printf("\n %s - %d ", CANDIDATE2, votescount2); 
printf("\n %s - %d ", CANDIDATE3, votescount3);
printf("\n %s - %d ", CANDIDATE4, votescount4);
printf("\n %s - %d ", "No Votes", novotes); 

sleep(4);
     system("cls");
     
}

void getLeadingCandidate(){
	
    printf("\n\n  #### Leading Candidate ####\n\n");
    
    if(votescount1 > votescount2 && votescount1 > votescount3 && votescount1 > votescount4)
        printf("[%s]", CANDIDATE1);
        
    else if (votescount2 > votescount3 && votescount2 > votescount4 && votescount2 > votescount1)
        printf("[%s]", CANDIDATE2);
        
    else if(votescount3 > votescount4 && votescount3 > votescount2 && votescount3 > votescount1)
        printf("[%s]", CANDIDATE3);
        
    else if(votescount4 > votescount1 && votescount4 > votescount2 && votescount4 > votescount3)
        printf("[%s]", CANDIDATE4);
        
    else
        printf("----- No-win situation ----");  
		  
		  sleep(4);
     system("cls");

login();
}

int main()
{
  
  system("color 0a");
   
    login();
} 

