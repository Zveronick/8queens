#include <iostream>

using namespace std;

int const n = 8;
int Iter = 0;
int Xqueens[n] = {-9856, -9856, -9856, -9856, -9856, -9856, -9856, -9856};
int Yqueens[n] = {-9856, -9856, -9856, -9856, -9856, -9856, -9856, -9856};

/*bool existsInArray(int x, int (&a)[n]){ /*Проверка на существование числа в массиве (понадобится дальше)*/
/*for (int i = 0; i<n; i++){
    if (a[i]==x){
        return true;
    }
}
return false;
}
*/


bool isSafeOnStraight(int x, int y){    /*Проверка безопасности прямых линий (+)*/

//cout<<x<<" "<<y<<"\t";
for (int i = 0; i<=7; i++){
    if ((Xqueens[i] == x) or (Yqueens[i] == y)){ /*Если среди массива ответов есть совпадение с*/ 
//       cout<<"+ unsafe\n";
        return false;                            /*Введенными координатами, значит позиция опасна*/
    } /*↑ опасность!*/
}
/*Если прошел цикл проверки, а опасности не обнаружено, значит все нормально*/
//cout<<"+ safe\n";
return true;
} 

bool isSafeOnX(int x, int y){   /*Проверка безопасности диагоналей (х)*/
//cout<<x<<" "<<y<<"\t";
for (int i = 0; i<=7; i++){
    if ( ( abs(Xqueens[i] - x) == abs(Yqueens[i] - y) ) ){
//        cout<<"X unsafe\n\n";
        return false;
    }
}
//cout<<"X safe\n\n";
return true;
}

bool PlaceQueen(int x, int y){

if (Iter>0){
    if (not(isSafeOnStraight(x, y) and isSafeOnX(x, y))){
        return false;
    }
}

Xqueens[Iter] = x;
Yqueens[Iter] = y;
Iter++;

if (Iter==8){
    return true;
}

for (int i = 0; i<=7; i++){
    for (int j = 0; j<=7; j++){
        if (PlaceQueen(i, j)){
            return true;

        }
    }
}

::Xqueens[Iter] = -9856;
::Yqueens[Iter] = -9856;
::Iter--;

return false;
}

void DrawDesk(){
cout<<"  1 2 3 4 5 6 7 8\n";

for (int i = 0; i<n; i++){
    cout<<i+1<<" ";
    for (int j = 0; j<n; j++){
        if ((Xqueens[0]==i) and (Yqueens[0]==j)){
            cout<<"Q ";
        }
        else if ((Xqueens[1]==i) and (Yqueens[1]==j)){
            cout<<"Q ";
        }
        else if ((Xqueens[2]==i) and (Yqueens[2]==j)){
            cout<<"Q ";
        }
        else if ((Xqueens[3]==i) and (Yqueens[3]==j)){
            cout<<"Q ";
        }
        else if ((Xqueens[4]==i) and (Yqueens[4]==j)){
            cout<<"Q ";
        }
        else if ((Xqueens[5]==i) and (Yqueens[5]==j)){
            cout<<"Q ";
        }
        else if ((Xqueens[6]==i) and (Yqueens[6]==j)){
            cout<<"Q ";
        }
        else if ((Xqueens[7]==i) and (Yqueens[7]==j)){
            cout<<"Q ";
        } else{
            cout<<"* ";
        } 
    }
    cout<<"\n";
}

}

int main ()
{

PlaceQueen(4, 6);
cout<<"\n";
cout<<"\n";
DrawDesk();
cout<<"\n";
for (int g = 0; g<n; g++){
            cout<<Xqueens[g]<<" "<<Yqueens[g]<<"\n";
        }

}