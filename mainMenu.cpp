#include "utility.cpp"
#include "RegisLogin.cpp"
#include "AddRemoveFriend.cpp"

void loginMenu();

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

//int main(){
//  pushTail("Denny","Denny123",1); //--> ini ngetest doang, kalo mau cek uncommand deh
//  menu();
//  return 0;
//}
