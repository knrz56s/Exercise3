#include <iostream>
#include <string.h>

using namespace std;

bool ar[1005][1005];
int p[1006010];//1005 * 1000 = 1005000
int rk[1006010];//1005000 + 1000 = 1006000
int ofs[2][4] = {{-1, 0, 1, 0},
						{0, 1, 0, -1}};

void init(){
	memset(ar, false, sizeof(ar));
	for(int i = 0; i < 1006010; i++){
		p[i] = i; rk[i] = 1;
	}
}

void pr(int n){
	cout << "island : \n";
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++)
			cout << ar[i][j] << "  ";
		cout << "\n";
	}
	cout << "\nparent : \n";
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << p[i*1005 + j] << "  ";
		}
		cout << "\n";
	}
	cout << "\nrank : \n";
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << rk[i*1005 + j] << "  ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int find(int x){
	return x == p[x] ? x : (p[x] = find(p[x]));
}

bool uni(int i, int j){
	//cout << "i = " << i << ", j = " << j << "\n";
	int x = find(i);
	int y = find(j);
	//cout << "find x = " << x << ", find y = " << y << "\n";
	if(x == y) return true;
	else{
		if(rk[x] <= rk[y]){
			p[x] = y;
			rk[y] += rk[x];
		}else{
			p[y] = x;
			rk[x] +=rk[y];
		}
		return false;
	}
}

int main(void){
	int n, x, y, islands = 0;
	init();
	cin >> n;
	while(n--){
		cin >> x >> y;
		x--; y--;
		if(ar[x][y] == false){
			ar[x][y] = true; islands++;
			for(int i = 0; i < 4; i++){
				int nx = x + ofs[0][i];
				int ny = y + ofs[1][i];
				if(nx < 0 || nx >= 1000) continue;
				if(ny < 0 || ny >= 1000) continue;
				int nv = nx * 1005 + ny;
				if(ar[nx][ny] == 1){
					//cout<< nx  << " nx = ny " << ny << "\n";
					islands--;
					if(uni(x * 1005 + y, nv)) islands++;
				}
			}
		}
		//pr(5);
		cout << islands << "\n";
	}
	return 0;
}