#include <stdio.h>
#include <string.h>

struct SinhVien{
    int id;
    char name[100];
    int age;
    char phoneNumber[15];
};
void hienThiSinhVien(struct SinhVien danhSach[], int currentLength);
int xoaSinhVienTheoID(struct SinhVien danhSach[], int currentLength, int idCanXoa);
int main(){
    struct SinhVien danhSach[50]={
        {1, "Nguyen Van A", 11, "0123567457"},
        {2, "Nguyen Van B", 12, "0987658565"},
        {3, "Nguyen Van C", 13, "0912345646"},
        {4, "Nguyen Van D", 14, "0923489765"},
        {5, "Nguyen Van E", 15, "0934575789"}
    };
    int currentLength = 5;
    hienThiSinhVien(danhSach, currentLength);
    int idCanXoa;
    printf("\nNhap ID sinh vien can xoa: ");
    scanf("%d", &idCanXoa);
    currentLength = xoaSinhVienTheoID(danhSach, currentLength, idCanXoa);
    hienThiSinhVien(danhSach, currentLength);

    return 0;
}
void hienThiSinhVien(struct SinhVien danhSach[], int currentLength){
    printf("\nDanh sach sinh vien hien tai:\n");
    for(int i=0; i<currentLength; i++){
        printf("ID: %d, Ten: %s, Tuoi: %d, SDT: %s\n",
               danhSach[i].id, danhSach[i].name, danhSach[i].age, danhSach[i].phoneNumber);
    }
}
int xoaSinhVienTheoID(struct SinhVien danhSach[], int currentLength, int idCanXoa){
    int viTri= -1;
    for(int i=0; i<currentLength; i++){
        if (danhSach[i].id == idCanXoa){
            viTri=i;
            break;
        }
    }
    if(viTri == -1){
        printf("\nSinh vien voi ID %d khong ton tai.\n", idCanXoa);
        return currentLength;
    }
    for(int i=viTri; i<currentLength-1; i++){
        danhSach[i] = danhSach[i + 1];
    }
    return currentLength - 1;
}
