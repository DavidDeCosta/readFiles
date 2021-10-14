//Name: David DeCosta
//Date:
//File name:
/* Program Description:
*/

#include <iostream>
#include <fstream>
using namespace std;

//prototypes
void readCommaSeparated(int arr[][4]);
void readTabSeparated(int arr[][4]);
void readContiguous(int arr[][4]);
void accumulate(int tempArr[][4], int accumArr[][4]);
void print(int accumArr[][4]);

int main(){

    int tempArr[4][4];
    int accArr[4][4] = {0};

    readTabSeparated(tempArr);
    accumulate(tempArr,accArr);
    readCommaSeparated(tempArr);
    accumulate(tempArr,accArr);
    readContiguous(tempArr);
    accumulate(tempArr,accArr);
    print(accArr);

    return 0;
}

void readCommaSeparated(int arr[][4]){
        fstream i_stream("comma.csv");
        char c[2];
        int x;
        int i, j;
        for(i = 0; i < 4; i++){
            for(j = 0; j < 3; j++){
                i_stream.getline(c,2,',');
                x = c[j] - 48;
                arr[i][j] = x;
            }
            i_stream.getline(c,2,'\n');
            x = c[j] - 48;
            arr[i][j] = x;
        }
}

void readTabSeparated(int arr[][4]){
    fstream i_stream("tabs.txt");
    int x;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            i_stream >> x;
            arr[i][j] = x;
            }
        }
}

void readContiguous(int arr[][4]){
    fstream i_stream("contiguous.txt");
    char c[5];
    int x;

    for(int i = 0; i < 4; i++){
        i_stream.getline(c,5);
        for(int j = 0; j < 4;j++){
            x = c[j] - 48;
            arr[i][j] = x;
        }
    }
}

void accumulate(int tempArr[][4], int accumArr[][4]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            accumArr[i][j] += tempArr[i][j]; 
        }
    }
}

void print(int accumArr[][4]){
    for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                cout << accumArr[i][j] << " ";
                }
            }
}