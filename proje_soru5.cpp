#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAKS_BOYUT 100

int main()
{
    char kuyruk[MAKS_BOYUT];
    int on = -1, arka = -1;

    printf("Metin Giriniz: ");
    fgets(kuyruk, MAKS_BOYUT, stdin);

    int uzunluk = strlen(kuyruk);

    
    if (kuyruk[uzunluk - 1] == '\n')
    {
        kuyruk[uzunluk - 1] = '\0';
        uzunluk--;
    }


    while (1)
    {
        int i = 0;
        int tekrarlayan_bulundu = 0;

        while (i < uzunluk)
        {
            
            if (kuyruk[i] == kuyruk[i + 1])
            {
                tekrarlayan_bulundu = 1;
                i += 2;
            }
            else
            {
                
                if (on == -1)
                {
                    on = 0;
                }

                arka++;
                kuyruk[arka] = kuyruk[i];
                i++;
            }
        }

        kuyruk[arka + 1] = '\0';
        uzunluk = strlen(kuyruk);

        
        if (!tekrarlayan_bulundu)
        {
            break;
        }

        
        on = -1;
        arka = -1;
    }

    printf("Sonuç: %s", kuyruk);

    return 0;
}

