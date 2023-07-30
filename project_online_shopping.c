#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void ele_item();
void book();
void shoe();
void delete_elec();
void delete_books();
void delete_shoes();
void change();
void bill();
int i,n,eid,ei,ne,bid,bi,nb,sid,si,ns,delid,pos=0,chanid=0,j,id,total,totale,totalb,totals;
long long int ph_no;
char ech,bch,sch,ch,name[50];
struct elctronic_items
{
	int id;
	char item_name[50];
	char cpny_name[50];
	int price;
	int rating;
}e[10];
struct elctronic_cart
{
	int id;
	char item_name[50];
	int price;
	int no_items;
}ec[10];
struct books_cart
{
	int id;
	char item_name[50];
	int price;
	int no_items;
}bc[10];
struct shoes_cart
{
	int id;
	char brand[50];
	int price;
	int no_items;
}sc[10];
struct books
{
	int id;
	char item_name[50];
	char author_name[50];
	int price;
	int rating;
}b[10];
struct shoes{
	int id;
	char brand[50];
	int price;
	int rating;
}s[10];
FILE *fe,*fb,*fs,*fbill;
main()
{
	printf("-------------------------------****Welcome to SR Online Shopping****---------------------------------------------- ");
	int n,ch,ic,p;
	char c;
	do{
		printf("\n\n\n1.Display all kind of items available to buy\n2.Display the total no.of items added\n3.Delet any item selected\n4.Change the quantity of any item selected\n5.Bill the items selected\n");
		printf("\nenter yor choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\n1.Electronic Items\n");
			       printf("2.Books\n");
			       printf("3.Shoes\n");
			       printf("choose the kind of item you want to buy:");
			       scanf("%d",&ic);
			       switch(ic)
			       {
			       	case 1:printf("Id\tItem\t\tCompany\t\tPrice\t\tRating\n");
			       	       ele_item();
						   break;
                    case 2:printf("Id\tName\t\t\tAuthor Name\t\tPrice\t\tRating\n");
			       	       book();
			       	       break;
			       	case 3:printf("Id\tBrand\t\tPrice\tRating\n");
			       	       shoe();
				   }
				   break;
			case 2:if(ec[0].id!=0)
		        {
			        printf("---------------electronic items----------------------\n");
			        printf("Id\tName\t\tprice\tNo.of items\n");
			        displaye(ec,ei);
			    }
			    if(bc[0].id!=0)
			    {
			        printf("---------------Books----------------------\n");
			        printf("Id\tName\t\tprice\tNo.of items\n");
			        displayb(bc,bi);
			    }
			    if(sc[0].id!=0)
			    {
			        printf("---------------Shoes----------------------\n");
			        printf("Id\tName\t\tprice\tNo.of items\n");
			        displays(sc,si);
			   }
			        break;
			case 3:if(ec[0].id!=0)
		        {
			        printf("---------------electronic items----------------------\n");
			        printf("Id\tName\t\tprice\tNo.of items\n");
			        displaye(ec,ei);
			    }
			    if(bc[0].id!=0)
			    {
			        printf("---------------Books----------------------\n");
			        printf("Id\tName\t\tprice\tNo.of items\n");
			        displayb(bc,bi);
			    }
			    if(sc[0].id!=0)
			    {
			        printf("---------------Shoes----------------------\n");
			        printf("Id\tName\t\tprice\tNo.of items\n");
			        displays(sc,si);
			   }
			     do
				 {
			     printf("Enter the id of the prodect you wish to delete:");
				 scanf("%d",&delid);
				 id=delid/100;
				 switch(id)
				 {
				 	case 1:delete_elec(delid,ei);
				 	break;
				 	case 2:delete_books(delid,bi);
				 	break;
				 	case 3:delete_shoes(delid,si);
				 	break;
				 }
				 printf("\nEnter d to delete more item:");
				 scanf(" %c",&ch);
			}while(ch=='d');
			     break;
			case 4:if(ec[0].id!=0)
		        {
			        printf("---------------electronic items----------------------\n");
			        printf("Id\tName\t\tprice\tNo.of items\n");
			        displaye(ec,ei);
			    }
			    if(bc[0].id!=0)
			    {
			        printf("---------------Books----------------------\n");
			        printf("Id\tName\t\tprice\tNo.of items\n");
			        displayb(bc,bi);
			    }
			    if(sc[0].id!=0)
			    {
			        printf("---------------Shoes----------------------\n");
			        printf("Id\tName\t\tprice\tNo.of items\n");
			        displays(sc,si);
			   }
			    change();
			       break;
			case 5:bill();
			exit(0);
			break;  
	}
	printf("press y to display options:");
	scanf(" %c",&c);
}while(c=='y');
}
void ele_item()
{
	fe=fopen("C:/project/electronic.txt","r");
	while(fscanf(fe,"%d%s%s%d%d",&e[i].id,e[i].item_name,e[i].cpny_name,&e[i].price,&e[i].rating)!=EOF)
	{
		fprintf(stdout,"%d\t%s\t\t%s\t\t%d\t\t%d\n",e[i].id,e[i].item_name,e[i].cpny_name,e[i].price,e[i].rating);
		i++;
	}
	fclose(fe);
	do{
	fe=fopen("C:/project/electronic.txt","r");
	printf("Enter the Id of the product you want to add to cart(Press 0 if you don't want to add any items):");
	scanf("%d",&eid);
	if(eid!=0)
	{
	i=0;
	while(fscanf(fe,"%d%s%s%d%d",&e[i].id,e[i].item_name,e[i].cpny_name,&e[i].price,&e[i].rating)!=EOF)
	{
		if(eid==e[i].id)
		{
			printf("Enter The no.of %s you want to add:",e[i].item_name);
		    scanf("%d",&ne);
		    ec[ei].id=e[i].id;
		    strcpy(ec[ei].item_name,e[i].item_name);
		    ec[ei].price=e[i].price;
		    ec[ei].no_items=ne;
		    ei++;
		    break;
		}
		i++;
	}
	 fclose(fe);
	 printf("\n\nPress e if you want add anymore products from electronics:");
	 scanf(" %c",&ech);
}
}while(ech=='e');
}
void book()
{
    fb=fopen("C:/project/books.txt","r");
	while(fscanf(fb,"%d%s%s%d%d",&b[i].id,b[i].item_name,b[i].author_name,&b[i].price,&b[i].rating)!=EOF)
	{
		fprintf(stdout,"%d\t%s\t\t%s\t\t%d\t\t%d\n",b[i].id,b[i].item_name,b[i].author_name,b[i].price,b[i].rating);
		i++;
	}
	fclose(fb);
	do{
	fb=fopen("C:/project/books.txt","r");
	printf("Enter the Id of the product you want to add to cart(Press 0 if you don't want to add any item):");
	scanf("%d",&bid);
	i=0;
	while(fscanf(fb,"%d%s%s%d%d",&b[i].id,b[i].item_name,b[i].author_name,&b[i].price,&b[i].rating)!=EOF)
	{
		if(bid==b[i].id)
		{
			printf("Enter The no.of %s you want to add:",b[i].item_name);
		    scanf("%d",&nb);
		    bc[bi].id=b[i].id;
		    strcpy(bc[bi].item_name,b[i].item_name);
		    bc[bi].price=b[i].price;
		    bc[bi].no_items=nb;
		    bi++;
		    break;
		}
		i++;
	}
	 fclose(fb);
	 printf("\n\nPress b if you want add anymore products from books:");
	 scanf(" %c",&bch);
}while(bch=='b');
}
void shoe()
{
	fs=fopen("C:/project/shoes.txt","r");
	while(fscanf(fs,"%d%s%d%d",&s[i].id,s[i].brand,&s[i].price,&s[i].rating)!=EOF)
	{
		fprintf(stdout,"%d\t%s\t\t\t%d\t\t%d\n",s[i].id,s[i].brand,s[i].price,s[i].rating);
		i++;
	}
	fclose(fs);
	do{
	fs=fopen("C:/project/shoes.txt","r");
	printf("Enter the Id of the product you want to add to cart(Press 0 if you don't want to add any items):");
	scanf("%d",&sid);
	if(sid!=0)
	{
	i=0;
	while(fscanf(fs,"%d%s%d%d",&s[i].id,s[i].brand,&s[i].price,&s[i].rating)!=EOF)
	{
		if(sid==s[i].id)
		{
			printf("Enter The no.of %s you want to add:",s[i].brand);
		    scanf("%d",&ns);
		    sc[si].id=s[i].id;
		    strcpy(sc[si].brand,s[i].brand);
		    sc[si].price=s[i].price;
		    sc[si].no_items=ns;
		    si++;
		    break;
		}
		i++;
	}
	 fclose(fs);
	 printf("\n\nPress s if you want add anymore products from shoes:");
	 scanf(" %c",&sch);
}
}while(sch=='s');
}
displaye(struct elctronic_cart ec[],int(n))
{
	for(i=0;i<n;i++)
	printf("%d\t%s\t\t%d\t%d\n",ec[i].id,ec[i].item_name,ec[i].price,ec[i].no_items);
}
displayb(struct books_cart bc[],int(n))
{
	for(i=0;i<n;i++)
	printf("%d\t%s\t%d\t%d\n",bc[i].id,bc[i].item_name,bc[i].price,bc[i].no_items);
}
displays(struct shoes_cart sc[],int(n))
{
	for(i=0;i<n;i++)
	printf("%d\t%s\t%d\t%d\n",sc[i].id,sc[i].brand,sc[i].price,sc[i].no_items);
}
void change()
{
	do
	{
	printf("Enter the Id of the product you wish to change the quantity:");
	scanf("%d",&chanid);
	for(i=0;i<ei;i++)
	{
		if(chanid==ec[i].id)
		{
		printf("Enter the no.of quatities you want:");
		scanf("%d",&ec[i].no_items);
		break;
       	}
	}
	pos=0;
	for(i=0;i<bi;i++)
	{
	if(chanid==bc[i].id)
		{
		printf("Enter the no.of quatities you want:");
		scanf("%d",&bc[i].no_items);
		break;
       	}
  }
	pos=0;
	for(i=0;i<si;i++)
	{
	if(chanid==sc[i].id)
		{
		printf("Enter the no.of quatities you want:");
		scanf("%d",&sc[i].no_items);
		break;
       	}
	}
	printf("------------------------------Product Quantity changed Succesfully---------------------------------------\n\n");
	printf("Enter y to change the quantity of more items:");
	scanf(" %c",&ch);
}while(ch=='y');
}
void delete_elec(delid,n)
{
	pos=0;
	for(i=0;i<n;i++)
	{
		pos++;
		if(ec[i].id==delid)
		{
			for(j=pos-1;j<n;j++)
			ec[j]=ec[j+1];
			ei--;
		}
}
printf("Item deleted Sucessfully");
}
void delete_books(delid,n)
{
	pos=0;
	for(i=0;i<n;i++)
	{
		pos++;
		if(bc[i].id==delid)
		{
			for(j=pos-1;j<n;j++)
			bc[j]=bc[j+1];
			bi--;
		}
}
printf("Item deleted Sucessfully");
}
void delete_shoes(delid,n)
{
	pos=0;
	for(i=0;i<n;i++)
	{
		pos++;
		if(sc[i].id==delid)
		{
			for(j=pos-1;j<n;j++)
			sc[j]=sc[j+1];
			si--;
		}
}
printf("Item deleted Sucessfully");
}
void bill()
{
    fbill=fopen("C:/project/customer_record.txt","a");
    printf("Please Enter your Name:");
    fscanf(stdin,"%s",name);
    fprintf(fbill,"\n\n\nName:%s",name);
    printf("Enter Phone Number:");
    fscanf(stdin,"%lld",&ph_no);
    fprintf(fbill,"\nPhone Number:%lld",ph_no);
    fprintf(fbill,"\n---------------------Electronic Items----------------\n",name);
    for(i=0;i<ei;i++)
	{
		fprintf(fbill,"ID:%d\nItem_Name:%s\nPrice:%d\nNo_Items:%d\n",ec[i].id,ec[i].item_name,ec[i].price,ec[i].no_items);
		totale+=ec[i].price*ec[i].no_items;
	}
	fprintf(fbill,"-----------------------Books--------------------------\n",name);
	for(i=0;i<bi;i++)
	{
		fprintf(fbill,"ID:%d\nBook_Name:%s\nPrice:%d\nNo_Items:%d\n",bc[i].id,bc[i].item_name,bc[i].price,bc[i].no_items);
		totalb+=bc[i].price*bc[i].no_items;
	}
	fprintf(fbill,"-----------------------Shoes--------------------------\n",name);
	for(i=0;i<si;i++)
	{
		fprintf(fbill,"ID:%d\nBrand_Name:%s\nPrice:%d\nNo_Items:%d\n",sc[i].id,sc[i].brand,sc[i].price,sc[i].no_items);
		totals+=sc[i].price*sc[i].no_items;
	}
	total=totale+totalb+totals;
	fprintf(fbill,"Total_Bill:%d",total);
	fclose(fbill);
	printf("---------------------------------------------------------------\n");
	printf("Total Electronics Bill=%d\n",totale);
	printf("---------------------------------------------------------------\n");
	printf("Total Books Bill=%d\n",totalb);
	printf("---------------------------------------------------------------\n");
	printf("Total Shoes Bill=%d\n",totals);
	printf("---------------------------------------------------------------\n");
	printf("TOTAL BILL=%d\n",total);
	printf("---------------------------------------------------------------\n");
	printf("-----------**Thank You For Buying**-----------");
}
