#include"moviemain.c"

int saet = 90 ;

void Enterdetails();
void Lookall(); 
void Find(); 
void reserve_ticket(); 
void past_record(); 
void enterdetails()
{
	
	FILE *fptr;
	struct reserve x;
	printf("enter the code of the movie  ");	
	scanf("%s",x.cod);
	printf("enter the  name of the movie ");	
	scanf("%s",x.nam);
	printf("enter the releasing Data ");	
	scanf("%s",x.dat);
	printf("enter the Price of the ticket ");	
	scanf("%d",&x.price);
	
	fptr=fopen("data.txt","a");

	if(fptr == NULL)
	{
		printf("the file was not found");
	}
	else
	{
		fprintf(fptr,"%s %s %s %d \n",x.cod,x.nam,x.dat,x.price);
		printf("insertion of record is sucessfull");
	}
		printf("\n");
	fclose(fptr);
}
void Find() 
{
	struct reserve x;
	FILE *fptr;
	
	char ch[30];
	printf("enter the code of the movie");
	scanf("%s",ch);
	fptr = fopen("data.txt","r");
	if(fptr == NULL)
	{
		printf("the file was not found");
		exit(1);

	}
	else
	{	
		while(getc(fptr) != EOF)
		{
			fscanf(fptr,"%s %s %s %d",x.cod,x.nam,x.dat,&x.price);
			if(strcmp(x.cod,ch) == 0)
			{	
			
				printf("\n Record Found\n");
				printf("\n\t\tname of the code%s",x.cod);
				printf("\n\t\tname of the movie%s",x.nam);
				printf("\n\t\tdate of the show%s",x.dat);
				printf("\n\t\tprice of the ticket%d",x.price);
				break;
			}
		}
		
	}

	fclose(fptr);
}
void Lookall()
{
	char ch;
	FILE *fptr;

	fptr = fopen("data.txt","r");
	if(fptr == NULL)
	{
		printf("the file was not found");
		exit(1);

	}
	else
	{	
		system("clear");
		while( ( ch = fgetc(fptr) ) != EOF )
      		printf("%c",ch);
		
	}
	fclose(fptr);
}
/* for ticket reservation*/ 
void reserve_ticket()
{
 struct reserve x;
	FILE *fptr;

	FILE *ufp;

	int total_seat,mobile,total_amount;
	char nam[30];

	
	char ch; 
	char movie_cod[30]; /* its for search*/

	/* display all the movies by automatically for movie code*/
	fptr = fopen("data.txt","r");
	if(fptr == NULL)
	{
		printf("the file was not found");
		exit(1);

	}
	else
	{	
		system("clear");
		while( ( ch = fgetc(fptr) ) != EOF )
      		printf("%c",ch);
		
	}
	fclose(fptr);
	
	
	printf("\n to reserve tickets enter the movie code along with movie's first letter");
	printf("\n enter the code of the movie ");
	scanf("%s",movie_cod);
	
	fptr = fopen("data.txt","r");
	if(fptr == NULL)
	{
		printf(" the file does not found !");
		exit(1);

	}
	else
	{	
		while(getc(fptr) != EOF)
		{
			fscanf(fptr,"%s %s %s %d",x.cod,x.nam,x.dat,&x.price);
			if(strcmp(x.cod,movie_cod) == 0)
			{	
				//printf("%s / %s / %s / %d\n",x.cod,x.nam,x.dat,x.price);
				printf("\n Record Found\n");
				printf("\n\t\tcode of the movie %s",x.cod);
				printf("\n\t\tname of the movie %s",x.nam);
				printf("\n\t\t show date %s",x.dat);
				printf("\n\t\tPrice of the ticket%d",x.price);
			}
		}
		
	}
	printf("\n* kindly fill your details  *");
	printf("\n enter your name ");
	scanf("%s",nam);
	printf("\n enter your mobilephone number ");
	scanf("%d",&mobile);
	printf("\n total no of tickets");
	scanf("%d",&total_seat);
	
	
	total_amount = x.price * total_seat;
	
	printf("\n @@@@ HAVE A NICE DAY @@@@\n");
	printf("\n\t\tenter your name  %s",nam);
	printf("\n\t\tenter your mobile phone number%d",mobile);
	printf("\n\t\tname of the movie %s",x.nam);
	printf("\n\t\ttotal no of movies %d",total_seat);
	printf("\n\t\t price for single ticket %d",x.price);
	printf("\n\t\tamount in total : %d",total_amount);
	
	
	ufp=fopen("pasttransaction.txt","a");
	if(ufp == NULL)
	{
		printf("the file was not found");
	}
	else
	{
		fprintf(ufp,"%s %d %d %d %s %d \n",nam,mobile,total_seat,total_amount,x.nam,x.price);
		printf("\n Record insert Sucessfull to the past record file");
	}
		printf("\n");
	fclose(ufp);
	fclose(fptr);

}
/* its for lookall  transactions of user*/
void past_record()
{
	char ch;
	FILE *fptr;


	
	fptr = fopen("pasttransaction.txt","r");
	if(fptr == NULL)
	{
		printf(" the file was not found ");
		exit(1);

	}
	else
	{	
		system("clear");
		while( ( ch = fgetc(fptr) ) != EOF )
      		printf("%c",ch);
		
	}
	fclose(fptr);


}