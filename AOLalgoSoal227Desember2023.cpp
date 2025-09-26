#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Database{ // Dsini saya menggunakan struct yang berfungsi untk menyimpan database.
    char location[50];
    char city[50];
    int price;
    int rooms;
    int bathroom;
    int carpark;
    char type[50];
    char furnish[50];
}info[4000];

void Select() {
    char coloum[100];
    char string[100];
    int Int;
    printf("Choose column : ");
    scanf("%s", coloum); // Scan disini berfungsi untuk mengetahui inputan user untuk memilih kolom berapa.
    getchar(); 
    printf("What data do you want to find? ");
    if(strcmp(coloum, "Price") == 0 || strcmp(coloum, "Rooms") == 0 || strcmp(coloum, "Bathroom") == 0 || strcmp(coloum, "Carpark") == 0) {
        scanf("%d", &Int);
    }
    else{
        scanf("%s", string);
    }
    getchar(); 
    if(strcmp(coloum, "Location") != 0 && strcmp(coloum, "City") != 0 && strcmp(coloum, "Price") != 0 && strcmp(coloum, "Rooms") != 0 && strcmp(coloum, "Bathroom") != 0 && strcmp(coloum, "Carpark") != 0 && strcmp(coloum, "Type") != 0 && strcmp(coloum, "Furnish") != 0) {
        printf("Data not found!");
    }
    else{

    }
    // Fungsi-fungsi diatas banyak menggunakan strcmp yang berfungsi untuk membandingkan. Namun disini saya belum menemukan cara untuk melanjutkan void Select ini.
    getchar();
}

void Export(){ // Void export berfungsi untuk menyimpan file yang telah di proses.
    char fileName[1000];
    int size =20;
    printf("File name : ");
    scanf("%s", fileName); // Scan disini berfungsi untuk inputan nama file yang akan disimpan oleh user.
    getchar();
    strcat(fileName,".csv"); //Fungsi strcat adalah untuk menggabungkan dua string.
	FILE *fp = fopen(fileName,"w+"); // Jika biasanya untuk membaca file menggunakan "r", maka untuk export file manggunakan "w+".
    for(int i=0;i<size;i++){
        fprintf(fp,"%s,%s,%d,%d,%d,%d,%s,%s\n", info[i].location, info[i].city, info[i].price, info[i].rooms, info[i].bathroom, info[i].carpark, info[i].type, info[i].furnish);
    }
    // Loop disini berfungsi untuk mengulang data yang di export.
    printf("Data successfully saved %s\n",fileName);
    fclose(fp);
}

void BubbleSortByPrice(struct Database data[], int size) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (data[j].price > data[j + 1].price) {
                struct Database temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

void Sort() {
    int idxx = 0;
    printf("Sort Data by Price\n");
    BubbleSortByPrice(info, idxx);
    printf("Data sorted by Price!\n");
}


int main(){

    struct Database;
    int idx = 0;
    int choose = 0;
    int row;
    char border[255];

    FILE *fp = fopen("../file.csv", "r"); // Fungsi ini berfungsi untuk membuka file.
	if(fp == NULL){
        perror("Error"); // Jika file tidak ada atau rusak, maka program akan mengeprint tulisan "error".
    }
    else{
        fscanf(fp, "%[^\n]\n", border);
        while(feof(fp) == false){
        fscanf(fp, "%[^,], %[^,], %d, %d, %d, %d, %[^,], %[^\n]\n", info[idx].location, info[idx].city, &info[idx].price, &info[idx].rooms, &info[idx].bathroom, &info[idx].carpark, info[idx].type, info[idx].furnish);
        // Fungsi diatas digunakan untuk meng scan data dalam file.
        //printf("%s, %s, %d, %d, %d, %d, %s, %s\n", info[idx].location, info[idx].city, info[idx].price, info[idx].rooms, info[idx].bathroom, info[idx].carpark, info[idx].type, info[idx].furnish);
        idx++;
        }
        fclose(fp); //fclose berfungsi untuk menutup file.
    }

    do{
        system("clear"); // clear berfungsi untuk membersihkan tampilan agar lebih enak dilihat.
        printf("What do you want to do?\n");
        printf("1. Display Data\n");
        printf("2. Search Data\n");
        printf("3. Sort Data\n");
        printf("4. Export Data\n");
        printf("5. Exit\n");
        // Print-print diatas digunakan untuk display menu.

        do{
            printf("Choose : ");
            scanf("%d", &choose); // Do disini berguna untuk mengetahui user memilih menu yang mana.
            getchar();
        }
        while (choose < 1 || choose > 5); // Fungsi ini berguna agar angka yang bisa dipilih hanya 1 sampai 5.

        switch(choose){
            case 1:
            printf("Display Data\n");
            printf("Print until row : ");
            scanf("%d", &row); // Disini scanf juga berfungsi untuk mengetahui user ingin menginput sampai row berapa.
            getchar();
            while(row < 1 || row > 3940);
            puts("");
            printf("%-30s %-30s %-15s %-10s %-10s %-10s %-15s %-10s\n", "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
            // Printf diatas berfungsi untuk menampilkan border yang bertuliskan "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish".
            for(int i = 0; i < row; i++){
                printf("%-30s %-30s %-15d %-10d %-10d %-10d %-15s %-10s\n", info[i].location, info[i].city, info[i].price, info[i].rooms, info[i].bathroom, info[i].carpark, info[i].type, info[i].furnish);
            }
            // Fungsi print dalam loop tersebut adalah untuk mengeprint data dalam file sesuai urutannya. Sedangkan fungsi loop itu sendiri adalah untuk menampilkan data sesuai dengan inputan.
            break;
            case 2:
            Select();
            break;
            case 3:
            Sort();
            break;
            case 4:
            Export();
            break;

        }
        getchar();
    }
    while(choose != 5);

    return 0;
}

