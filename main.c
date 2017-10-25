#include<stdio.h>
#include<conio.h>
#include <Windows.h>
//header file for Sleep

void deposit(int*,float*);
void chkBal(int*,float*);
void withdraw(int*,float*);
void reload(float*);
void process(int*,float*);
void sendMoney(int*,float*);

int main(){
    int accNo=00000;
    float accBal=0.00;
    int attempt=0;
    int pin=0;
    int fpin=0;
    int i=100;
    int c=0;

    do{
        system("cls");
        attempt=0;
        while(attempt<3){
            //system("cls");
            printf("\n*************** Welcome to ABC Bank ATM **************** \n\n");
            printf("\n    Please enter your pin : ");
            scanf("%d",&pin);
            attempt=attempt+1;

            FILE *Fp;
            Fp=fopen("data.db","r");

             while(!feof(Fp)){
                fscanf(Fp,"%d\t%d\t%f",&fpin,&accNo,&accBal);
                
                c=0;
                if(pin==fpin)
                {
                    process(&accNo,&accBal);
                    break;
                }else{
                	c=c+1;
                }
             }
             if(c>0){
                printf("\n Attempt %d ",attempt);
                printf("\n Wrong pin. Try Again. \n \n");
             }
             if(attempt>=3){
                printf("\n You have failed to enter the pin %d times.\n Your account has locked temporary.\n Please Contact the Bank Manager. \n \n",attempt);
                getch();
             }
        }
        getch();
    }while(i>0);

    return 0;
}

void process(int *no,float *bal){
    int opt;
    int accNo=*no;
    float accBal=*bal;

   system("cls");

   do{
	//New Screen Every Time
	system("cls");
	//Display The Menu
	printf("\n++++++++++ ABC Bank ATM ++++++++");
	printf("\n\t1.Withdraw Money ");
	printf("\n\t2.Deposit Money");
	printf("\n\t3.Check Account Balance");
	printf("\n\t4.Reload Phone");
	printf("\n\t5.Send Money");
	printf("\n\t6.Change Pin");
	printf("\n\t7.Exit");

	//Get The User Input,Option
	printf("\n\nEnter Option To Continue : ");
	scanf("%d",&opt);

	//Calling Methods
	switch(opt){
	    case 1:withdraw(&accNo,&accBal);break;
	    case 2:deposit(&accNo,&accBal);break;
	    case 3:chkBal(&accNo,&accBal);break;
	    case 4:reload(&accBal);break;
	    case 5:sendMoney(&accNo,&accBal);break;
	    case 6:system("cls");printf("\n Please Contact the Bank Manager to Change the Pin.");break;
	    case 7:printf("\nThanks For Banking With Us :)");getch();system("cls");
	    default: if(opt!=7){printf("Invalid Input. Try Again.");};
	}
	getch();
   }while(opt!=7);
}


void deposit(int *accNo,float *bal)
{
    int ind,opt,i;
    system("cls");
    printf("\nEnter you money to the machine");

    printf("\n\nYour Money is Counting");

    for(i=0;i<3;i++){
		printf(".");
		Sleep(500);
    }

    ind=10000;
    printf("\n\nAmount You Inserted : %d",ind);

    *bal=*bal+ind;

    printf("\n\nAccount No : %d",*accNo);
    printf("\nYour New Acount Balance is %f",*bal);

    printf("\n\nTHANKS FOR TRANSACTION ");

}

void chkBal(int *accNo,float *bal){
	system("cls");
	printf("\n Account No : %d \n Balance : %f",*accNo,*bal);
}

 void withdraw(int *accNo,float *b){
	int amount,c,f,opt;
	float *bal;
	bal=b;
	system("cls");

	do
	{
		printf("\n\n Select the amount :");
		printf("\n 1.500");
		printf("\n 2.1000");
		printf("\n 3.2000");
		printf("\n 4.4000");
		printf("\n 5.5000");
		printf("\n 6.10000");
		printf("\n 7.15000");
		printf("\n 8.20000");
		printf("\n 9.Enter The Amount ");
		printf("\n 0. Go Back ");

		printf("\n\n  Enter The Option : ");
		scanf("%d",&opt);
		system("cls");

		switch(opt)
		{
			case 0:f=0;break;
			case 1:amount=500;break;
			case 2:amount=1000;break;
			case 3:amount=2000;break;
			case 4:amount=4000;break;
			case 5:amount=5000;break;
			case 6:amount=10000;break;
			case 7:amount=15000;break;
			case 8:amount=20000;break;
			case 9:printf("\n Enter the Amount : ");scanf("%d",&amount);break;
			default:printf("Invalid Option");
		}
		if(opt!=0){
			printf("\n Transaction is going on, hold a moment");

			for(c=1;c<=6;c++){
					printf(".");
					Sleep(270);
			}


			if(amount>=50 && amount>=(*bal-500)){
				 system("cls");
				 printf("\nYour acount balance is insufficient to complete the withdrawal.\nPlease check the balance and try again.");
				 f=1;
			}else{
				 *bal=*bal-amount;
				 system("cls");
				 printf("\n Withdrawal Successful. \n Your remaining balance is %f in account : %d ",*bal,*accNo);
				 f=0;
			}
		}

		}while(f==1);


		printf("\n \n  Press any key to continue..");

 }

 void reload(float *bal){
	int num,c;
	float amount;
	system("cls");

	printf("\n Please enter the phone number to reload to : ");
	scanf("%d",&num);

	printf("\n Please enter the amount to reload to : ");
	scanf("%f",&amount);

	printf("\n Transaction is going on, hold a moment");


		for(c=1;c<=6;c++){
			printf(".");
			Sleep(270);
		};

		if(amount>=50 && amount<=(*bal-500)){
			 system("cls");
			 *bal=*bal-amount;
			 printf("\n Reload is successfull. \n Your phone %d has reloaded with %f.\n Your new balance is %f",num,amount,*bal);
		}else{
		     system("cls");
			 printf("\n Reload is Unsuccessful. \n Your account balance is not sufficient.");
		}

	printf("\n\n Press any key to continue..");

 }

void sendMoney(int *accNo,float *bal){
    int recNo,c;
    float amount;

    system("cls");

    printf("Enter the account number to recieve money : ");
    scanf("%d",&recNo);

    printf("Enter the amount to send : ");
    scanf("%f",&amount);

    printf("\n Transaction is going on, hold a moment");


		for(c=1;c<=6;c++){
			printf(".");
			Sleep(270);
		};

    if(amount>=50 && amount<=(*bal-500)){
		 system("cls");
		 *bal=*bal-amount;
		 printf("\n Transaction Successful!");
         printf("\n\n Amount of %f sent to %d.\n Your new balance is %f",amount,recNo,*bal);
	}else{
	     system("cls");
		 printf("\n Your account balance is not sufficient.\n Transaction Failed. ");
	}
}
