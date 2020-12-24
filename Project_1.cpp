#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

//Structs
//mainMenu struct
struct Node{
  char name[255];
  char password[255];
  int no;
  Node *next,*prev;
}*head,*tail,*curr;
//gw buat struct buat nampilin username yang udah ada

//struct user friends
struct Friends {
  char name[255];
  Friends *nextfriends;
};

//RegisLogin struct
struct UserNode{
  char name[255];
  char password[255];
  int no;
  UserNode *next,*prev;
  Friends *friends;
}*userhead,*usertail,*usercurr;

//mainMenu function
Node *createNode (const char *name, const char *password, int no){
  Node *newNode = (Node*)malloc(sizeof(Node));
  strcpy(newNode->name,name);
  strcpy(newNode->password,password);
  newNode->no = no;
  newNode->next = newNode->prev = NULL;
  return newNode;
}

void pushHead(const char *name,const char *pass,int no){
  Node *temp = createNode(name,pass,no);
  if(!head){
    head = tail = temp;
  } else {
    temp->next = head;
    head->prev = temp;
    head = temp;
  }
}

void pushTail(const char *name,const char *pass, int no){
  Node *temp = createNode(name,pass,no);
  if(!head){
    head = tail = temp;
  } else {
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
  }
}

void pushMid(const char *name,const char *pass, int no){
  Node *temp = createNode(name,pass,no);
  if(!head){
    head = tail = temp;
  } else if (strcmp(name,head->name) < 0){
    pushHead(name,pass,no);
  } else if (strcmp(name,tail->name) > 0){
    pushTail(name,pass,no);
  } else {
    Node *curr = head;
    while(strcmp(name, curr->name) > 0){
      curr = curr->next;
    }
    temp->prev = curr->prev;
    temp->next = curr;
    temp->prev->next = temp;
    curr->prev = temp;
  }
}

void cls(){
  for(int i = 0 ; i < 32 ; i++){
    puts("");
  }
}

void exitMenu(){
  exit(0);
}

//RegisLogin function
UserNode *createUserNode (const char *name, const char *password, int no){
  UserNode *newNode = (UserNode*)malloc(sizeof(UserNode));
  strcpy(newNode->name,name);
  strcpy(newNode->password,password);
  newNode->no = no;
  newNode->next = newNode->prev = NULL;
  newNode->friends = NULL;
  return newNode;
}

void pushUserHead(const char *name,const char *pass,int no){
  UserNode *temp = createUserNode(name,pass,no);
  if(!userhead){
    userhead = usertail = temp;
  } else {
    temp->next = userhead;
    userhead->prev = temp;
    userhead = temp;
  }
}

void pushUserTail(const char *name,const char *pass, int no){
  UserNode *temp = createUserNode(name,pass,no);
  if(!userhead){
    userhead = usertail = temp;
  } else {
    temp->prev = usertail;
    usertail->next = temp;
    usertail = temp;
  }
}

void pushUserMid(const char *name,const char *pass, int no){
  UserNode *temp = createUserNode(name,pass,no);
  if(!userhead){
    userhead = usertail = temp;
  } else if (strcmp(name,userhead->name) < 0){
    pushUserHead(name,pass,no);
  } else if (strcmp(name,usertail->name) > 0){
    pushUserTail(name,pass,no);
  } else {
    UserNode *usercurr = userhead;
    while(strcmp(name, usercurr->name) > 0){
      usercurr = usercurr->next;
    }
    temp->prev = usercurr->prev;
    temp->next = usercurr;
    temp->prev->next = temp;
    usercurr->prev = temp;
  }
}

void loginMenu();

void allUser(){
	int count=1;
	printf("[All User]\n");
	printf("No.\tUsername\n");
	UserNode *store = userhead;
	while(store!=NULL){
		if(strcmp(store->name,usercurr->name)!=0){
			printf("%d\t%s\n",count++,store->name);
		}
	}
}
void allFriends(){
	printf ("[All Friends of %s\n",usercurr->name);
    printf("No.\tUsername\n");
	int count=1;
    Friends *mainFriends = usercurr->friends;
    while(mainFriends!=NULL){
    	printf("%d\t%s\n",count++,mainFriends->name);
    	mainFriends = mainFriends->nextfriends;
	}
	printf("\n");
}
//create friends
Friends *newUserFriend(const char *name) {
  Friends *temp = (Friends*)malloc(sizeof(Friends));
  strcpy(temp->name, name);
  temp->nextfriends = NULL;
  return temp;
}

// add friend
void addFriend(){
  allUser();
  printf("Which user do you want to add?\n");
  printf(">> ");char name[255];
  scanf("%[^\n]",name);getchar();
  Friends *temp = newUserFriend(name);
  Friends *temp2 = usercurr->friends;
  if(!usercurr->friends) {
    usercurr->friends = temp;
  } else {
  	while(temp2->nextfriends!=NULL){
  		temp2 = temp2->nextfriends;
	}
    temp2->nextfriends = temp;
  }
}


// remove friend
void removeFriend() {
  allFriends();
  printf("Which user do you want to remove?\n");
  printf(">> ");char nama[255];
  scanf("%[^\n]",nama);getchar();
  if(!usercurr->friends){
    puts("No friends!");
    printf("press anything to continue...");
		getchar();loginMenu();;
  }
  else {
  	Friends *store = usercurr->friends;
  	bool flag=true;
  	while(!store->nextfriends!=NULL){
  		if(strcmp(store->nextfriends->name, nama)==0){
  			Friends *temp3 = store->nextfriends->nextfriends;
  			store->nextfriends = NULL;
  			free(store->nextfriends);
  			store->nextfriends = temp3;
  			flag=false;break;
		}else{
			store = store->nextfriends;
		}
	}
	if(flag){
		puts("User not found!");
		printf("press anything to continue...");
		getchar();
		loginMenu();
	}
 }
}

int filter(char str[]){
	int len = strlen(str);
	for ( int i = 0; i < len; i++){
		if (!isalnum(str[i])){
			return 1;
		}
	}
	return -1;
}

void menu();
void loginMenu();
//Fungsi Validasi Registrasi
void Regis(){
  char tempusername[255];
  char temppassword[255];
  int flagregis = 1;
  int flagada = 0;
  int flagabort = 0;
  int flagpassword = 1;
  int tempno = 1;
  while ( flagregis == 1){
    puts("Username (lowercase 1-24char): ");
    scanf("%[^\n]", tempusername);
    getchar();
    if (strcmp(tempusername, "0") == 0){//0 to abort
      flagregis = 0;
      flagabort = 1;
        menu();//return ke menu
    }
    if (flagabort == 0){
      UserNode *checknode = userhead;
      while (checknode){
       if (strcmp(tempusername, checknode->name)==0){
       	//printf("check: %s vs %s\n",tempusername,checknode->name);
          puts("[X] Sorry, Username taken!");
         flagada = 1;
          break;
        }
        checknode = checknode->next;
        tempno++;
      }
    }
    if (flagabort == 0 && flagada == 0 && strlen(tempusername)<=24 && filter(tempusername) == -1){
      flagregis = 0;
      puts("[V] Username OK, Insert Password!");
    }else{
      puts("[X] Username TooLong and/or Contains Non AlphaNum");
    }
  }   
  while (flagpassword == 1 && flagregis == 0){
      printf("Password: ");
      scanf("%[^\n]", temppassword);
      getchar();
      if (strcmp(temppassword, "0")==0){
        flagabort = 1;
        flagpassword = 0;
        menu();//return ke  menu();
      }
      if (flagabort == 0 && strlen(temppassword)<= 24 && filter(temppassword)== -1){
        flagpassword = 0;
      }else{
        puts("[X] Please re-enter Password (1-24 Char) Alphanumeric");
      }
  }
  if (flagpassword == 0 & flagregis == 0){//No Kesalahan baru masukkan
    pushUserMid(tempusername, temppassword, tempno);
    puts("[V] Username & Password Registered");
    int any;
    puts("Enter any number to return to menu!");
    scanf("%d", &any);
    getchar();
    menu();
  }

}

//Fungsi Validasi Login
void Login(){
  char tempname[255];
  char temppass[255];
  char targetpass[255];
  int flaglogin = 1;
  int flagada = 0;
  int flagabort = 0;
  int flagpassword = 1;
  UserNode *testlogin = userhead;
  while(flaglogin == 1){
    printf("Username: ");
    scanf("%[^\n]", tempname);
    getchar();
    if (strcmp(tempname, "0")==0){//Checking Abort
      flagabort = 1;
      flaglogin = 0;//printf("baka\n");for(int ijk=0;ijk<1000000000;ijk++);
      menu();
    }
    if (flagabort == 0){
      testlogin = userhead;
      while (testlogin){
        if (strcmp (testlogin->name, tempname)== 0){//Checking Username
          flagada = 1;strcpy(targetpass,testlogin->password);
          break;
        }
       testlogin = testlogin->next;
      }
    }
    if (flagabort = 0 && flagada == 0){
      puts("[X] Invalid Username, Try Again!");
    }
    if(flagada==1){
    	flaglogin=0;
    	//break;	
	}
  }
  if (flagabort == 0 && flagada == 1 && flaglogin == 0){
      while(flagpassword = 1){
        printf("Password: ");
        scanf("%[^\n]",temppass);
        getchar();
        if (strcmp(temppass, "0")==0){//Checking abort
          flagabort = 1;
          menu();
        }
		//printf("check: %s vs %s\n",temppass,targetpass);
        if (strcmp(temppass, targetpass)==0){
          flagpassword = 0;//password benar!
          break;
        }else{
          puts("[X] Wrong Password, try Again!");
        }
      }
  }
  if (flaglogin == 0 && flagpassword == 0){//Jadikan CurrUser
    usercurr = testlogin;
    loginMenu();
  }
}


void menu(){
  int totalalluserinmainmenu=1;
  while(1){
    cls();// ini cls buat clear screen doang kok, functionny ada diatas
    puts("Oo==========================================oO");
    puts("                   STUDY NETWORK              ");
    puts("Oo==========================================oO");
    puts("");
    puts("[All User]");
    puts("");
    printf ("No.  ");
    printf ("Username\n");// dibagian sini butuh data jadi gw sedian struct dl aja ya, kalo salah ganti aja oke? wkwkw
    usercurr = userhead;
    while(usercurr){
      printf ("%-4d %-10s\n",totalalluserinmainmenu++,usercurr->name);
      usercurr = usercurr->next;
    }
    puts("");
    puts("---------------------------");
    puts("[1] Register");
    puts("[2] Login");
    puts("[3] Exit");
    puts("---------------------------");
    puts("Press 0 and enter to abort an operation");
    puts("---------------------------");
    printf (">> ");
    int choose;
    scanf ("%d", &choose);
    getchar();
    puts("---------------------------");
    if(choose == 1){
    Regis();
    } else if(choose == 2){ // lanjutin dari sini aja functionnya
    Login();
    } else if(choose == 3){
      exitMenu();
    } else if(choose == 0){
      exitMenu();
    } 
  }
}

void loginMenu(){
  clock_t begin = clock();
  time_t t;
  time(&t);
  while(1){
    cls();
    puts   ("Oo==========================================oO");
    printf ("Welcome,              \n",usercurr->name);// ini gw blm bisa lanjutin soalnya perlu nama setelah login
    puts   ("Oo==========================================oO");
    printf ("Logged in: %s\n",ctime(&t));
    puts("---------------------------");
    puts("");
    allFriends();
	puts("---------------------------");
    puts("          >>Menu<<         ");
    puts("---------------------------");
    puts("[1] Add Friend");
    puts("[2] Remove Friend");
    puts("[3] View Inbox");
    puts("[4] View Sent Requests");
    puts("[5] Add Edit, Announce, Delete Note");
    puts("[6] Logout");
    puts("---------------------------");
    printf (">> ");
    int c;
    scanf ("%d", &c);
    if(c == 1){
		addFriend();
    } else if( c == 2 ){
		removeFriend();
    } else if( c == 3 ){
		printf("coming soon\n");
		printf("press anything to continue...");
		getchar();loginMenu();
    } else if ( c == 4 ){
		printf("coming soon\n");
		printf("press anything to continue...");
		getchar();loginMenu();
    } else if ( c == 5 ){
		printf("coming soon\n");
		printf("press anything to continue...");
		getchar();loginMenu();
    } else if ( c == 6 ){
       clock_t end = clock();
       double timeUsed = (double) (end-begin)/CLOCKS_PER_SEC;
       printf ("You Have Used Our Application for %.2lf second\n",timeUsed*3600);
	   printf("Press Any Key to Return...");
       char c;
       scanf ("%c", &c);
       getchar();
      menu();
    }

    puts("---------------------------");
  }
}

int main(){
  menu();
  return 0;
}
