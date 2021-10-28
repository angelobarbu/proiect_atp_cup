//Barbu Angelo 311AB
struct Player
{
    char *last_name;
    char *first_name;
    int score;
};

struct Country
{
    char *name;
    int nr_players;
    int global_score;
    struct Player *players;
};

struct CountryPair
{
    struct Country country1;
    struct Country country2;
};

struct List
{
    struct Country country;
    struct List *next;
    struct List *prev;
};

struct Stack
{
    struct Country country;
    struct Stack *next;
};

struct QueueElem
{
    struct CountryPair countries;
    struct QueueElem *next;
};

struct Queue
{
    struct QueueElem *front;
    struct QueueElem *rear;
};

struct BST
{
    struct Player player;
    struct BST *left;
    struct BST *right;
};

void fileOpenCheck(FILE *file);
void listAllocCheck(struct List *node);
void charAllocCheck(char *string);
void countryAllocCheck(struct Country *country);
void playerAllocCheck(struct Player *player);
void stackAllocCheck(struct Stack *node);
void queueAllocCheck(struct Queue *q);
void qelemAllocCheck(struct QueueElem *node);
void bstAllocCheck(struct BST *node);

void Read(struct List **head, int nr_countries, FILE *fin);

void writeCountry(struct List *head, FILE *fout);
void writeList(struct List *head, int nr_countries, FILE *fout);

void deleteNode(struct List *head, int pos);
void pushStack(struct Stack **top, struct Country country);
struct Country popStack(struct Stack **top);
struct Queue *createQueue();
void enQueue(struct Queue *q, struct CountryPair countries);
struct CountryPair deQueue(struct Queue *q);

int Power(int i, int nr_countries);
void deleteCountry(struct List *head, int *nr_countries);

void Task3(struct List *head, int nr_countries, struct Country **last_teams, FILE *fout);

struct BST *newBSTnode(struct Player player);
struct BST *insertBST(struct BST **node, struct Player player);
void printBST(struct BST *root, FILE *fout);
void Task4(struct BST **root, struct Country *last_teams, FILE *fout);

int checkBST(struct BST *root, char *player_firstname, char *player_lastname);
void countBST(struct BST *root, struct Player player1, struct Player player2, int *count);
void Task5(struct BST *root, FILE *freq, FILE *fout);

void freeBST(struct BST *root);
void freeList(struct List **head);