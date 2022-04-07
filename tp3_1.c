#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char * buff;
    char ** nombres;

    buff = (char *) malloc(100*sizeof(char));
    nombres = (char **) malloc(5*sizeof(char*));

    for (int i = 0; i < 5; i++)
    {
        printf("Ingresar el nombre: ");
        gets(buff);

        nombres[i] = (char *)malloc((strlen(buff)+1)*sizeof(char));

        strcpy(nombres[i],buff);
    }

    for (int i = 0; i < 5; i++)
    {
        printf ("\n%d: %s",i+1, nombres[i]);
        free(nombres[i]);
    }

    printf("\n\n");

    free(nombres);
    free(buff);

    system("pause");
    return 0;
}