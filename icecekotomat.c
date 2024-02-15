#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

struct Node{
    char name[32];
    char password[32];
    struct Node *next;
    float bakiye;
};

char icecekler[][32] =  {"Su", "Kola", "Fanta", "Gazoz", "Soda", "Meyve Suyu", "Þalgam", "Ayran", "Redbull"};
float fiyatlar[] =        { 8,    15,     14,      13,      12,   11,           13,       10,      21};

struct Node *head = NULL;
struct Node *log = NULL;
int giris = 0;
int endofprogram = 0;

void delay(int x){
	int i, j;
	for(i=0; i<20000*x; i++)
		for(j=0; j<100000; j++)
			j = j;
}

void addNode(char name[], char password[]){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    strcpy(newNode->password, password);
    newNode->bakiye = 0;
    newNode->next = NULL;
	if(head==NULL)
		head = newNode;
	else{
    	struct Node *temp = head;
    	while(temp->next != NULL)
			temp = temp->next;
		temp->next = newNode;
	}	
}

void login(){
	char name[32];
	char password[32];
    printf("Ýsim: \n");
    scanf("%s", name);
    printf("Þifre: \n");
    scanf("%s", password);
    struct Node *temp = head;
    while(temp != NULL) {
    	if(!strcmp(temp->name, name))
            if(!strcmp(temp->password,password)) {
            	giris = 1;
            	log = temp;
            	break;
           	}
        temp = temp->next;
	}
}

void kayit(){
    char name[25];
    char password[25];
    char passwordt[25];
    printf("Ýsminizi giriniz: \n");
    scanf("%s", name);
    printf("Þifre oluþtur: \n");
    scanf("%s", password);
    printf("Þifrenizi tekrar girin: \n");
    scanf("%s", passwordt);
    if(!strcmp(password,passwordt)){
    	addNode(name, password);
        printf("Kayýt tamamlandý.");
    }
    else
        printf("Þifreler uyuþmuyor.");
    delay(2);
}

void menu(){
    int i;
    float tutar;
    if(!giris){
	    printf("1- Kayýt ol: \n");
	    printf("2- Giriþ yap: \n");
	    printf("3- Kapat: \n");
	    scanf("%d",&i);
	    switch(i){
	    	case 1: 
	    		kayit();
	    		break;
	    	case 2:
	    		login();
	    		break;
	    	case 3:
	    		endofprogram = 1;
		}
	}
	else{
		printf("Bakiyeniz: %.2f \n", log->bakiye);
		printf("1- Bakiye yükle \n");
		printf("2- Ýçecek al \n");
		printf("3- Çýkýþ \n");
		scanf("%d", &i);
		switch(i){
			case 1:
				printf("Yüklenecek tutarý girin: ");
				scanf("%f", &tutar);
				log->bakiye += tutar;
				break;
			case 2:
				printf("Ýçecek seçin: \n");
				for(i=0; i<sizeof(fiyatlar)/sizeof(float); i++)
					printf("%d-%s: %.2f \n", i, icecekler[i], fiyatlar[i]);
				scanf("%d", &i);
				if(sizeof(fiyatlar)/sizeof(float) >= i+1){
					if(log->bakiye >= fiyatlar[i])
						log->bakiye -= fiyatlar[i];
					else{
						printf("Bakiye yetersiz! \n");
						delay(2);
					}
				}
				break;
			case 3:
				giris = 0;
				break;
		}
	}
    system("cls");
}

int main(){
	setlocale(LC_ALL,"turkish");
    while(!endofprogram){
    	menu();
	}
}
