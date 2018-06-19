#include <bits/stdc++.h>
#include "unistd.h"
using namespace std;

#define H 50
#define W 50

//typedef vector<vector<bool> > VV;
//VV cell;

const int dx[]={-1,-1,-1,0,1,1,1,0},dy[]={-1,0,1,1,1,0,-1,-1};

bool cell[H][W];

void draw(){
    for(int i = 0;i < H; i++){
        for(int j = 0;j < W; j++){
            cell[i][j]=false;
        }
    }

    random_device rnd;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(rnd()%2 > 0)cell[i][j] = true;
        }
    }
}

int count(bool sub[H][W], int y, int x){
    int cou=0;
    for(int i = 0; i < 8; i++){
        if(y+dy[i]>=0&&y+dy[i]<H&&x+dx[i]>=0&&x+dx[i]<W){
            if(sub[y + dy[i]][x + dx[i]]) cou++;
        }
    }
    return cou;
}

bool check(bool sub[H][W],int y,int x){
    int cou = count(sub,y,x);
    if(!sub[y][x] && cou==3){
        return true;
    }else if(sub[y][x] && cou==2||cou==3){
        return true;
    }else{
        return false;
    }
}

void update(bool sub[H][W]){
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(check(sub,i,j)) cell[i][j] = true;
            else cell[i][j] = false;
        }
    }
}

void print(){
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(cell[i][j])cout << "o";
            else cout << " ";
        }
        cout << endl;
    }
}

int main(){
    draw();
//    print();
    while(1){
        cout.flush();
        system("clear");
        bool sub[H][W];
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                sub[i][j] = cell[i][j];
            }
        }
        update(sub);
        print();
        usleep(0.5 * 1e6);
 //       system("clear");
    }
}
