#include<stdio.h>
#include<string.h>

void reverse(char str[]){ // Void reverse berfungsi untuk membalikan string-nya.
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) { // Fungsi loop adalah untuk terus mengulangi menyusun string sesuai dengan panjang stringnya.
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

void convert(char str[]){ // Void conver berfungsi untuk mengonfersi huruf besar menjadi huruf kecil dan sebaliknya.
    int i = 0;
    while (str[i] != '\0') { //While disini untuk melakukan perintah mengkonfersi string.
        if (str[i] >= 'a' && str[i] <= 'z') { // Char a sampai z (Jika hurufnya kecil) maka akan dikurangi 32 sesuai ASCII-nya agar menjadi huruf besar.
            str[i] = str[i] - 32;
        } else if (str[i] >= 'A' && str[i] <= 'Z') { // Sama halnya demikian, char A - Z akan ditambahkan 32 supaya menjadi huruf kecil sesuai ASCII-nya.
            str[i] = str[i] + 32;
        }
        i++;
    }
}

int main(){

    char inputString[30];

    printf("Input Your String : "); // Fungsi printf disini hanya untuk melengkapi output agar terlihat rapih.

    scanf("%s", inputString); // Scanf disini berfungsi untuk meminta inputan string dari user.

    reverse(inputString); // Memanggil fungsi pembalik yang sudah kita buat diatas.
    printf("Reversed : %s\n", inputString); // Print string yang sudah dibalik.
    convert(inputString); // Memanggil fungsi pengonversi yang sudah kita buat diatas.
    printf("Revered and Converted : %s\n", inputString); // Print string yang sudah dibalik dan juga sudah di konversi.

    return 0;
}