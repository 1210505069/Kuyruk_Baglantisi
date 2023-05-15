#include <stdio.h>
#include <stdlib.h>

struct dugum {
    int veri;
    struct dugum* sonraki;
};
// struct tanimliyoruz
struct kuyruk {
    struct dugum* bas;
    struct dugum* son;
};
//ikinci struct tanimliyoruz
void ekle(struct kuyruk* k, int veri) {
    struct dugum* yeni_dugum = (struct dugum*) malloc(sizeof(struct dugum));
    yeni_dugum->veri = veri;
    yeni_dugum->sonraki = NULL;
    if (k->son == NULL) {
        k->bas = yeni_dugum;
        k->son = yeni_dugum;
    }
    else {
        k->son->sonraki = yeni_dugum;
        k->son = yeni_dugum;
    }
}
//ekleme komutunu tanimliyoruz
void sil(struct kuyruk* k) {
    if (k->bas == NULL) {
        printf("Kuyruk bos\n");
    }
    else {
        struct dugum* temp = k->bas;
        k->bas = k->bas->sonraki;
        if (k->bas == NULL) {
            k->son = NULL;
        }
        free(temp);
    }
}
//silme komutunu tanimliyoruz
void goruntule(struct kuyruk* k) {
    if (k->bas == NULL) {
        printf("Kuyruk bos\n");
    }
    else {
        struct dugum* gecerli = k->bas;
        while (gecerli != NULL) {
            printf("%d ", gecerli->veri);
            gecerli = gecerli->sonraki;
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
	
    struct kuyruk k = {NULL, NULL};
    //struct tanimliyoruz
    int secim, veri;
    do {
        printf("1. Ekleme\n");
        printf("2. Silme\n");
        printf("3. Goruntuleme\n");
        printf("4. Cikis\n");
        printf("Seciminiz: ");
        scanf("%d", &secim);
        //ana ekrani yaziyoruz
        switch (secim) {
            case 1:
                printf("Eklenecek veri: ");
                scanf("%d", &veri);
                ekle(&k, veri);
                break;
            case 2:
                sil(&k);
                break;
            case 3:
                goruntule(&k);
                break;
            case 4:
                break;
            default:
                printf("Gecersiz secim\n");
        }
        //switch caseleri tanimliyoruz
    } while (secim != 4);
    return 0;
}
