#include <bits/stdc++.h>
#define MAX 100000000
using namespace std;

void graph(int arr[100][100], int vertex, int edge){
	int a, i, j, from, to, weight, hehe;
	vector < pair <int, int > > v[vertex];
	for(i=0; i<edge; i++){
		hehe=i;
		printf("Edge %d: \n", hehe+1);
		printf("Nama Vertex asal: ");
		scanf("%d", &from);
		printf("Nama Vertex tujuan: ");
		scanf("%d", &to);
		printf("Weight Edge nya: ");
		scanf("%d", &weight);
		//scanf("%d%d%d", &from, &to, &weight); //input dari mana kemana sama weightnya
		if(from>vertex || to>vertex || from<1 || to<1)
		{
			printf("Input errorr \n");
			i--;
		}
		else
		{
			arr[from-1][to-1]=weight;
		}
		
		
		//v[from].push_back(make_pair(to, weight)); //karena array dimulai dari 0 makanya -1

	}
}


void dijkstra (int arr[100][100], int vertex, int edge){ //fungsi dijkstranya
	int i, j, pilih, temp;
	int cek[100];    //ini buat cek kalo jaraknya lebih kecil di push ke queuenya
	int hasil[100];  //ini hasil nanti diprint
	priority_queue < pair <int, pair<vector<int>, int> > > dijkstra; //buat mencari jarak terpendek
	vector< int > rute[100];	//ini hasil rute yang nanti diprint
	vector<int>hmm;  //ini untuk awal masuk ke pqueue
	vector<int>simpan; //tempat buat nyimpen rute sementara
	vector<int>sementara; //untuk nyimpen rute ke priority queue
	pair <int, pair<vector<int>, int > > wadah;  //wadah agar dipop gak ilang
	pair < vector <int>, int> tempat; //tempat buat nyimpen vector dan nilai yang dituju
	for(i=0; i<vertex; i++){
		cek[i]=MAX;		//di maxin semua ajah
	}
	for(i=0; i<vertex; i++){
		hasil[i]=MAX;   //di maxin semua ajah
	}
	printf("\nPilih titik awal : ");
	scanf("%d", &pilih);  //buat ngasi titik awal
	hasil[pilih-1]=arr[pilih-1][pilih-1];
	for (i=0; i<vertex; i++){   //ini starter pack
		if(i==pilih-1){
			cek[i]=arr[pilih-1][i];
		}
		if(arr[pilih-1][i]>0){
			cek[i]=arr[pilih-1][i];
			dijkstra.push(make_pair(arr[pilih-1][i]*-1, make_pair(hmm, i))); // dikali -1 biar yg paling kecil jd paling besar
		}													 // soalnya priority queue itu paling besar
	}
	while(!dijkstra.empty()){
		wadah = dijkstra.top();   //dimasukkin wadah biar gak ilang
		dijkstra.pop();           //baru di pop
		tempat=wadah.second;      //hanya mengcopy
		simpan=tempat.first;	  //buat menyimpan rute sementara yang udah di pop
		simpan.push_back(tempat.second); //ditambahka rute saat ini yang sudah di pop
		temp=wadah.first*-1;      //hanya mengcopy balikin lagi biar jaraknya gakminus

		if(hasil[tempat.second]>temp){    //ini kalo jarak sebelumnya lebih panjang dari jarak sesudahnya
			rute[tempat.second]=simpan; //simpan
			hasil[tempat.second]=temp;  //simpan
		}
		for (i=0; i< vertex; i++){
			if(arr[tempat.second][i]>0){
				temp=hasil[tempat.second]+arr[tempat.second][i]; //total jarak

				sementara=rute[tempat.second]; //rute saat ini yang akan dimasukkan ke pqueue
				if(cek[i]>temp){   //nah ini ceknya kalo jarak ceknya > temp dipushlah kan jarak sekarang lebih kecil dar jarak terdahulu
					cek[i]=temp;
					dijkstra.push(make_pair(temp*-1, make_pair(sementara, i)));  //sama, dikali -1
				}
			}
		}
	}
	printf("Maka hasilnya\n");
	for(i=0; i<vertex; i++){ //dari sini kebawah print jarak terdekat beserta rutenya
		if (hasil[i]==MAX){
			printf("Dari titik %d ke titik %d tidak mempunyai jarak \n", pilih, i+1);
		}
		else{
			printf("Dari titik %d ke titik %d jarak terdekatnya adalah %d \n", pilih, i+1, hasil[i]);
			printf("Dengan rute dari: %d -> ", pilih);
			int x;
			if(i+1!=pilih){
				for(x=0; x<rute[i].size(); x++){
					if(x!=rute[i].size()-1){
						printf("%d -> ", rute[i].at(x)+1);
					}
					else{
						printf("%d\n\n", rute[i].at(x)+1);
					}

				}
			}
			else{
				printf("%d\n\n", pilih);
			}
		}
	}
}

int main(){
	int vertex, edge, i, j, from, to, weight, a, start;
	printf("Welcome!\n");
	printf("1. Mulai\n2. Keluar\n");
	while(1){
		scanf("%d",&start);
		if (start==2) return 0;
		else if (start==1) break;
		else printf("Input error\n");
	}
	
	while(1)
	{
		printf("Masukkan jumlah vertex (Jumlah vertex harus lebih dari 1):\n");
		scanf("%d", &vertex);
		if (vertex<2)
		{
			printf("Jumlah vertex anda tidak valid\n");
		}
		else
		{
			break;
		}
	}
	
	while(1)
	{
		printf("Masukkan jumlah edge (Jumlah Edge harus lebih dari 0):\n");
		scanf("%d", &edge);	
		if(edge<1)
		{
			printf("Jumlah edge anda tidak valid \n");
		}
		else
		{
			break;
		}
	}
	
	int arr[100][100];
	printf("Vertex diberi nama 1 sampai jumlah vertexnya \n");
	//printf("Masukkan jarak antar vertex dengan format \"dari\" \"ke\" dan \"weight\" !\n");
	for(i=0; i<vertex; i++){
		for(j=0; j<vertex; j++){
			arr[i][j]=0;
		}
	}
	graph(arr, vertex, edge);
	dijkstra(arr, vertex, edge);
}
