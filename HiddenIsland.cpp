#include <iostream>

using namespace std;

int ar[1005][1005];
int p[1005][1005];
int rk[1005][1005];

void init(){
	for(int i = 0; i < 1005; i++){
		for(int j = 0; j < 1005; j++){
			ar[i][j] = 0;
			p[i][j] = 1005 * i + j;
			rk[i][j] = 1;
		}
	}
}

void pr(int n){
	cout << "parent : \n"
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << p[i][j] << "  ";
		}
		cout << "\n";
	}
	cout << "\nrank : \n";
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << rk[i][j] << "  ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int find(int x){
	return x == p[x] ? x : (p[x] = find(x));
}

bool uni(int i, int j){
	int x = find(i);
	int y = find(j);
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
	cin >> n;
	while(n--){
		cin >> x >> y;
		pr(5);
		if(ar[x][y] == 0){
			ar[x][y] = 1; islands++;
			for(int i = 0; i < 4; i++){
				int nx = x + ofs[0][i];
				int ny = y + ofs[1][i];
				int nv = x * 1005 + ny;
				if(ar[nx][ny] == 1){
					if(uni(x * 1005 + y, nv)) islands--;
				}
			}
		}
		cout << islands << "\n";
	}
	return 0;
}