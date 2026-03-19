#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t  BYTE;
int main(int argc, char *argv[])
{
    if(argc!=2)
    {
        printf("Nu s-au citit bine datele\n");
        return 1;
    }
    FILE* fis;
    fis=fopen(argv[1],"r");
    if(fis==NULL)
    {
        printf("Nu s-a putut deschide fisierul\n");
        return 1;
    }
    BYTE v[512];
    int nrfile=0;
    FILE* fis2=NULL;
    while(fread(v,sizeof(BYTE),512,fis)==512)
{

    if(v[0]==255 && v[1]==216 && v[2]==255 && v[3]>=224 && v[3]<=240)
    {
        char nume[9];
        sprintf(nume, "%d", nrfile);
        if(fis2!=NULL)
        {
            fclose(fis2);
        }
        sprintf(nume, "%03d.jpg", nrfile++);
        fis2=fopen(nume,"w");
      
        if(fis2==NULL)
        {
            printf("Nu s-a putut deschide fisierul\n");
            return 1;
        }
    }
    if(fis2!=NULL)
    {
        fwrite(v,sizeof(BYTE),512,fis2);
    }

}

    if(fis2!=NULL)
    {
        fclose(fis2);

    }
    fclose(fis);
}
