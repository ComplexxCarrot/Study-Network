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
