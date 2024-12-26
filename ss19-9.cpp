#include <stdio.h>
#include <string.h>

struct SinhVien{
    int id;
    char name[100];
    int age;
    char phoneNumber[15];
};
void hienThiSinhVien(struct SinhVien danhSach[], int soLuong);
void themSinhVien(struct SinhVien danhSach[], int *soLuong);
void suaSinhVien(struct SinhVien danhSach[], int soLuong);
int xoaSinhVien(struct SinhVien danhSach[], int soLuong);
void timKiemSinhVien(struct SinhVien danhSach[], int soLuong);
void sapXepSinhVien(struct SinhVien danhSach[], int soLuong);

int main(){
    struct SinhVien danhSach[50]={
      {1, "Nguyen Van A", 11, "0123567457"},
        {2, "Nguyen Van B", 12, "0987658565"},
        {3, "Nguyen Van C", 13, "0912345646"},
        {4, "Nguyen Van D", 14, "0923489765"},
        {5, "Nguyen Van E", 15, "0934575789"}
    };
    int soLuong=5;
    int choice;
    do {
        printf("\nMENU\n");
        printf("1. Hien thi danh sach sinh vien\n");
        printf("2. Them sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Xoa sinh vien\n");
        printf("5. Tim kiem sinh vien\n");
        printf("6. Sap xep danh sach sinh vien\n");
        printf("7. Thoat\n");
        printf("\nLua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                hienThiSinhVien(danhSach, soLuong);
                break;
            case 2:
                themSinhVien(danhSach, &soLuong);
                hienThiSinhVien(danhSach, soLuong);
                break;
            case 3:
                suaSinhVien(danhSach, soLuong);
                hienThiSinhVien(danhSach, soLuong);
                break;
            case 4:
                soLuong = xoaSinhVien(danhSach, soLuong);
                hienThiSinhVien(danhSach, soLuong);
                break;
            case 5:
                timKiemSinhVien(danhSach, soLuong);
                break;
            case 6:
                sapXepSinhVien(danhSach, soLuong);
                hienThiSinhVien(danhSach, soLuong);
                break;
            case 7:
                printf("\nThoat chuong trinh\n");
                break;
            default:
                printf("\nLua chon khong hop le\n");
        }
    }while(choice!=7);

    return 0;
}
void hienThiSinhVien(struct SinhVien danhSach[], int soLuong){
    printf("\nDanh sach sinh vien hien tai:\n");
    for(int i=0; i<soLuong; i++){
        printf("ID: %d, Ten: %s, Tuoi: %d, SDT: %s\n",
               danhSach[i].id, danhSach[i].name, danhSach[i].age, danhSach[i].phoneNumber);
    }
}
void themSinhVien(struct SinhVien danhSach[], int *soLuong){
    struct SinhVien sv;
    printf("\nNhap ID: ");
    scanf("%d", &sv.id);
    printf("Nhap ten: ");
    getchar();
    fgets(sv.name, sizeof(sv.name), stdin);
    sv.name[strcspn(sv.name, "\n")] = 0;
    printf("Nhap tuoi: ");
    scanf("%d", &sv.age);
    printf("Nhap SDT: ");
    scanf("%s", sv.phoneNumber);
    danhSach[*soLuong] = sv;
    (*soLuong)++;
}
void suaSinhVien(struct SinhVien danhSach[], int soLuong){
    int id;
    printf("\nNhap ID sinh vien can sua: ");
    scanf("%d", &id);
    for(int i=0; i<soLuong; i++){
        if (danhSach[i].id == id){
            printf("Nhap ten moi: ");
            getchar();
            fgets(danhSach[i].name, sizeof(danhSach[i].name), stdin);
            danhSach[i].name[strcspn(danhSach[i].name, "\n")] = 0;
            printf("Nhap tuoi moi: ");
            scanf("%d", &danhSach[i].age);
            printf("Nhap SDT moi: ");
            scanf("%s", danhSach[i].phoneNumber);
            return;
        }
    }
    printf("\nKhong tim thay sinh vien voi ID da cho\n");
}
int xoaSinhVien(struct SinhVien danhSach[], int soLuong){
    int id;
    printf("\nNhap ID sinh vien can xoa: ");
    scanf("%d", &id);
    for (int i = 0; i < soLuong; i++){
        if (danhSach[i].id == id) {
            for (int j = i; j < soLuong - 1; j++){
                danhSach[j] = danhSach[j + 1];
            }
            return soLuong - 1;
        }
    }
    printf("\nKhong tim thay sinh vien voi ID da cho\n");
    return soLuong;
}
void timKiemSinhVien(struct SinhVien danhSach[], int soLuong){
    int id;
    printf("\nNhap ID sinh vien can tim: ");
    scanf("%d", &id);
    for(int i=0; i<soLuong; i++){
        if (danhSach[i].id == id){
            printf("\nThong tin sinh vien:\n");
            printf("ID: %d, Ten: %s, Tuoi: %d, SDT: %s\n",
                   danhSach[i].id, danhSach[i].name, danhSach[i].age, danhSach[i].phoneNumber);
            return;
        }
    }
    printf("\nKhong tim thay sinh vien voi ID da cho\n");
}
void sapXepSinhVien(struct SinhVien danhSach[], int soLuong){
    for(int i=0; i<soLuong-1; i++){
        for(int j=0; j<soLuong-i-1; j++){
            if (strcmp(danhSach[j].name, danhSach[j + 1].name) > 0){
                struct SinhVien temp=danhSach[j];
                danhSach[j] = danhSach[j+1];
                danhSach[j+1] = temp;
            }
        }
    }
}


