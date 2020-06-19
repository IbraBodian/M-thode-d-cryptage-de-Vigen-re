#include <stdio.h>
#include <stdlib.h>
#include "coincidence.c"
void decalage(char * s,int dec);
double occurence2(char * s,char n,int taille);
double coincidence2(char * s1,char * s2,double t1,double t2);
void resolution(char * tab);

int main(){
	int i;
	double m;
	//char s1[]="ezzdymjdjvizoczleqeopjipczyta";
	//char s2[]="lnysbxtspbkuchbbhllyytilvylys";
	//char s3[]="huuumovyffyxyllullgunvinonvyy";
	//char s4[]="kxouuokykuygxlktxgkogkajdkxka";
	//char s5[]="frbfwhbjgwqbgzhrwwhghiesjhibf";
	char message[]="elhkfznuxrzyuobdsuufybmuwmxoohjtvkbdsyyjjpfkgvbfuwikyyqzuxgbocyxgchllzzblkhlbutrehlxwqllgwelgkhoyuogpynghjtvkiiiiaeplnjscvodjzynkhylvxityykbasyaf";
	resolution(message);
	printf("%s\n",message);
	/*for(i=0;i<26;i++){
		m=coincidence2(s1,s4,29,29);
		printf("Decalage de %d avec un ICM valant %.4f\n",i,m);
		decalage(s4,1);
	}*/
	return 0;
}

void decalage(char * s,int dec){
	int i=0,j;
	while(s[i]!='\0'){
		s[i]=mod(iden(s[i])+dec,26);
		i++;
	}
	for(j=0;j<=i;j++)
		s[j]=rev(s[j]);
}

double occurence2(char * s,char n,int taille){
	int i=0,cp=0;
	for(i=0;i<taille;i++){
		if(s[i]==n)
			cp++;
	}
	return cp;
}

double coincidence2(char * s1,char * s2,double t1,double t2){
	double s=0;
	double i,o1,o2;
	for(i=0;i<26;i++){
		o1=occurence2(s1,rev(i),t1);
		o2=occurence2(s2,rev(i),t2);
		if((o1) && (o2))
			s+=(o1*o2)/(t1*t2);
	}
	return s;
}


void resolution(char * tab){
	int i=0,j;
	while(tab[i]!='\0'){
		tab[i]=mod(iden(tab[i])-iden('v'),26);
		i++;
		if(tab[i]!='\0'){
			tab[i]=mod(iden(tab[i])-iden('h'),26);
			i++;
			if(tab[i]!='\0'){
				tab[i]=mod(iden(tab[i])-iden('u'),26);
				i++;
				if(tab[i]!='\0'){
					tab[i]=mod(iden(tab[i])-iden('g'),26);
					i++;
					if(tab[i]!='\0'){
						tab[i]=mod(iden(tab[i])-iden('o'),26);
						i++;
					}
				}
			}
		}
	}
	for(j=0;j<=i;j++)
		tab[j]=rev(tab[j]);
}
