#include <stdio.h>
#include <stdlib.h>

int mod(int x,int y);
int iden(char c);
char rev(int i);
double occurence(int d,char * text,char n,double taille, int l);
double coincidence(int d,char * text, double taille,int l);
double moyennecoincidence(char * text,double taille,int l);

/*int main(){
	double m;
	int i;
	char message[]="elhkfznuxrzyuobdsuufybmuwmxoohjtvkbdsyyjjpfkgvbfuwikyyqzuxgbocyxgchllzzblkhlbutrehlxwqllgwelgkhoyuogpynghjtvkiiiiaeplnjscvodjzynkhylvxityykbasyaf";
	for(i=1;i<145;i++){
		m=moyennecoincidence(message,145,i);
		printf("%.4f \n",m);
	}
	return 0;
}*/

int iden(char c){
	int i;
	char alpha[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	for(i=0;i<26;i++)
		if(alpha[i]==c)
			return i;
	return 0;
}

char rev(int i){
	char alpha[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	return alpha[i];
}

int mod(int x,int y){
	return (x>=0)? x%y : y-1-((-x-1)%y);
}

double occurence(int d,char * text,char n,double taille, int l){
	int j=d,cp=0;
	for(j=d;j<taille;j+=l){
		if(text[j]==n)
			cp++;
	}
	return cp;
}

double coincidence(int d,char * text, double taille,int l){
	double s=0;
	double i,o;
	for(i=0;i<26;i++){
		o=occurence(d,text,rev(i),taille,l);
		if(o)
			s+=(o*(o-1))/(taille*(taille-1));
	}
	return s;
}

double moyennecoincidence(char * text,double taille,int l){
	int j;
	double aux,moy=0;
	for(j=0;j<l;j++){
		aux=coincidence(j,text,taille,l);
		moy+=aux;
	}
	moy/=l;
	return moy;
}

/*
taille 337
gqrnvvplvhibjsyvrliyifzrlmjnzcesariydbnbaiomzeciiwinmwlvdirndrgzuzekvxemractsfznnbvplizociwlmavitsxurlimmpmfttvremrtkfqxmyamjtciacmvwedvotvremiimerptnnczxdwanmcesmhrmcidrbuzjwlmavwexumqeuvycmcaajiybyeaasfzfebgedarnbcidarmizrpaaibvqaacaajrttrsidsfzfrmmmpvaevkwzcflmgsybzizrfpihcwlpptnsmzrpdveveiwiauqkwzvaetrlpceetvwuwhrajepviovknplrmmlvp
*/
