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
