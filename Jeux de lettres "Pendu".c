#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char lirecaracter();
void ecrirelalettre(char* motS , int malettre , int trouve, char * motproposer,int * coups);


 int main(int argc, char* argv[])

{
    char motsecret[]="FADWA";
    int coups=10;
    int trouve=0;
    int malettre = 0;
    char motproposer[]= "*****";

  printf("bienvenue dans le pendu !\n");
  printf("il vous reste %d coups a jouer\n",coups);
  printf("quel est le mot secret?*****\n");

do{
  printf("\n proposez une lettre : ");
  malettre=lirecaracter();//, pour récupérer une lettre dans votre code, vous n'utiliserez pas scanf("%c", &maLettre);

   trouve=0;

   for(int i=0;i<=4;i++)
   {
     if(malettre == motsecret[i])
        trouve=1;
   }


ecrirelalettre( motsecret ,  malettre , trouve, motproposer,&coups);

printf("%s",motproposer);

 } while( (coups)!= 0 && strcmp(motsecret,motproposer)!=0 );

printf("\n\nGagne ! Le mot secret etait bien : %s",motproposer);

     return 0;
}


char lirecaracter()
{

char caracter=0;
caracter=getchar();//on lit le premier caracter
caracter=toupper(caracter);//on met la lettre en majuscule si elle ne l'est pas

 // On lit les autres caractères mémorisés un à un jusqu'au \n (pour les effacer)
while (getchar() !='\n'); /*: j'appelle la fonction getchar en boucle jusqu'à tomber sur le caractère\n.
La boucle s'arrête alors, ce qui signifie qu'on a « lu » tous les autres caractères,
ils ont donc été vidés de la mémoire. On dit qu'on vide le buffer.*/

return caracter;

}

void ecrirelalettre(char* motsecret , int malettre , int trouve,char * motproposer, int * coups)
{

  if(trouve==1)
  {

    printf("il vous reste %d coups a jouer\n", *coups);
    printf("quel est le mot secret?");
    for(int i=0 ;i<=4 ;i++)
     {
        if(malettre == motsecret[i])

          {
              //printf("%c",malettre);

            motproposer[i] = malettre;
            // printf("%s",motproposer);

          }

       //else
          //printf("*");

     }
  }

if(trouve==0)

{
   *coups = *coups - 1;
   printf("il vous reste %d coups a jouer\n",*coups);
   printf("quel est le mot secret?");

  // printf("%s",motproposer);

    //for(i=0 ;i<=4 ;i++ )
     //{

          //printf("*");

     //}

}

}
