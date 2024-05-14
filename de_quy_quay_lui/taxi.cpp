#include<bits/stdc++.h>
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
const int MAX=25;

int n;
int c[MAX][MAX];
bool visited[MAX];
int x[MAX]; // Array to store the positions visited
int disMin=1e5;
int disCur=0; // Current distance
int passenger=0; // Number of passengers currently in the vehicle
int minc=0; // Minimum cost

void inp(){
    cin>>n;
    for(int i=0;i<=2*n;i++){
        for(int j=0;j<=2*n;j++){
            cin>>c[i][j];
        }
    }
    memset(visited,false,sizeof(visited));
}

int findMin(){
    int minc=1e6;
    for(int i=0;i<=2*n;i++){
        for(int j=0;j<=2*n;j++){
            if(c[i][j] != 0) minc = min(minc, c[i][j]);            
        }
    }
    return minc;
}

void solution(){
    int disAll = disCur + c[x[2*n]][0]; // Calculate total distance for the current path
    disMin = min(disMin, disAll); // Update the minimum distance found
}

bool check(int a, int i){
    if(passenger == 1 && i <= n) return false; // Cannot pick up another passenger when one is already present
    if(i > n && !visited[i-n]) return false; // Cannot drop off a passenger who hasn't been picked up
    if(c[x[a-1]][i] == 0) return false; // No direct path
    if(visited[i]) return false; // Already visited
    return true; // Valid move
}

void Try(int a){
    for(int i=1;i<=2*n;i++){
        if(check(a, i)){
            x[a] = i;
            visited[i] = true;
            disCur += c[x[a-1]][i];
            if(i > n) passenger--; // Dropping off a passenger
            else passenger++; // Picking up a passenger

            if(a == 2*n) solution();
            else {
                if(disCur + minc * (2*n - a) < disMin) Try(a + 1);
            }

            visited[i] = false;
            disCur -= c[x[a-1]][i];
            if(i > n) passenger++;
            else passenger--;
        }
    }
}

int main(){
    faster();
    inp();
    x[0] = 0;
    minc = findMin();
    Try(1);
    cout << disMin;
    return 0;
}
