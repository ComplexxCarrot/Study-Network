
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
