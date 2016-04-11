#include <cstdio>
#include <cstring>

#define MAXSIZE 10000010

using namespace std;

char division[] = "<td class=\"division\">";
char td[] = "<td>";
char barratd[] = "</td>";
char pe[] = "<p>";
char barrape[] = "</p>";
char const * berre[] = {"<br />", "<br/>", "</br>", "</ br>"};
char s[MAXSIZE];
int N=0;

char aux[1024];

int main() {

    char c;
    while ( (c=fgetc(stdin))!=EOF)
        s[N++] = c;
    s[N]='\0';

    // procura divisoes
    int ncasos=0;
    for (int i=0;s[i];i++) {
        if (!strncmp(s+i,division,strlen(division))) {

            /* ENTRADA */
            int ini = i+strlen(division) + 1; //inicio do bloco

            // encontra barratd
            int btd;
            for (int j=ini;s[j];j++) if (!strncmp(s+j,barratd,strlen(barratd))) {
                btd=j;
                break;
            }
            int fim = btd - 1; // fim do bloco

            // imprime caso
            sprintf(aux,"in%d",ncasos);
            FILE *f = fopen(aux,"w");
            for (int j=ini;j<=fim;j++) {
                for (int br = 0; br < 4; br++)
                    if (!strncmp(s+j,berre[br],strlen(berre[br]))) {
                        fprintf(f,"\n");
                        j += strlen(berre[br]);
                    }
                if (!strncmp(s+j,barrape,strlen(barrape))) {
                    fprintf(f,"\n");
                    j += strlen(barrape);
                } else if (!strncmp(s+j,pe,strlen(pe))) {
                    j += strlen(pe) -1;
                } else
                    fprintf(f,"%c",s[j]);
            }
            fclose(f);

            /* SAIDA */

            for (int j=fim+1;s[j];j++) if (!strncmp(s+j,td,strlen(td))) {
                ini = j+strlen(td) + 1;
                break;
            }

            // encontra barratd
            for (int j=ini;s[j];j++) if (!strncmp(s+j,barratd,strlen(barratd))) {
                btd=j;
                break;
            }
            fim = btd - 1; // fim do bloco

            // imprime caso
            sprintf(aux,"out%d",ncasos);
            f = fopen(aux,"w");
            for (int j=ini;j<=fim;j++) {
                for (int br = 0; br < 4; br++)
                    if (!strncmp(s+j,berre[br],strlen(berre[br]))) {
                        fprintf(f,"\n");
                        j += strlen(berre[br]);
                    }
                if (!strncmp(s+j,barrape,strlen(barrape))) {
                    fprintf(f,"\n");
                    j += strlen(barrape);
                } else if (!strncmp(s+j,pe,strlen(pe))) {
                    j += strlen(pe) -1;
                } else
                    fprintf(f,"%c",s[j]);
            }
            fclose(f);

            ncasos++;
        }
    }
    printf("%d\n",ncasos);

    return 0;
}
