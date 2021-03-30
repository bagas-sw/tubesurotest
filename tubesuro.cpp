#include <stdio.h>
#include <cmath>
#include <vector>
using namespace std;


// fungsi pergerakan dan current position robot
int Move(int *xPtr, int *yPtr, vector<vector<int>> posKecoak){
    int move;
    printf ("Pilihan bergerak 1.Right, 2.Left, 3.Forward, 4.Backward : ");
    scanf ("%d", &move);
    switch (move) {
        case 1: *xPtr += 1; break;
        case 2: 
            if (*xPtr > 0){*xPtr -= 1; break;}
            else {printf ("Tidak dapat bergerak ke kiri\n"); break;}
        case 3: *yPtr += 1; break;
        case 4:
            if (*yPtr > 0){*yPtr -= 1; break;}
            else {printf ("Tidak dapat bergerak ke belakang\n"); break;}
        default: break;
    }
    printf ("Posisi robot : [%d, %d]\n", *xPtr, *yPtr);
    return 0;
}

// fungsi jarak robot terhadap setiap kecoak
double Jarak(int x0, int y0, vector<vector<int>> posKecoak){
    int jarak_min = 1000;
    int jarak_minX = 1000;
    int jarak_minY = 1000;

    for (int i = 0; i < 3; i++){
        int jarakX = posKecoak[i][0] - x0;
        int jarakY = posKecoak[i][1] - y0;
        int jarak = abs(jarakX) + abs(jarakY);
        if (jarak < jarak_min){
            jarak_min = jarak;
            jarak_minX = jarakX;
            jarak_minY = jarakY;
        }
    }

    printf ("Posisi kecoak terdekat dari robot = <%d, %d>\n", jarak_minX, jarak_minY);
    printf ("Jarak kecoak terdekat = %d kotak\n\n", jarak_min);
    return 0;
}


int main(){

    //posisi awal robot
    int x = 0;
    int y = 0;
    int *xPtr = &x;
    int *yPtr = &y;
    //cout << "Posisi awal robot = [" << *xPtr << "," << *yPtr << "]" << endl;
    printf("Posisi awal robot = [%d, %d]\n", *xPtr, *yPtr);

    // posisi awal kecoak
    vector<vector<int>> posKecoak {{6, 5}, {5, 10}, {7, 8} , {10,7}, {4,12}};

    // pilihan yang akan dilakukan robot
    while (true){
        printf ("Opsi 1.Bergerak 2.Berhenti : ");
        int opsi;
        scanf ("%d", &opsi);
        if (opsi == 1) {
            Move(xPtr, yPtr, posKecoak);
            Jarak(*xPtr, *yPtr, posKecoak);
        }
        else if (opsi == 2){break;}
        else {break;}
    }
    return 0;
}