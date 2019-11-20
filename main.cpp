#include <winbgim.h> 
#include <stdio.h>

const int n = 3;			           // so O
int level = 3;				   // muc Win
int * checkWin(int, int, int);  // kiem tra thang hay chua
int arrLoca[n][n];   		   // mang chua cac o da danh


int main()
{
	// now, you can run project
	initwindow(500, 500);		   // init window graphics
	setbkcolor(0);				   // set background
   	cleardevice();				   // xoa man hinh
	setcolor(14);				   // set text color
	
	int margin = 40;    		   // can le
	int size = 40;      		   // kich thuoc o = 20
	int x, y;           		   // toa do chuot
	int *p;						   // con tro p nhan mang tra ve Win
	
	while(true){
		int choose = 0;
		delay(0.0001);
		outtextxy(100, 100, "Welcome to TicTacToe Game !");
		outtextxy(100, 150, "       New Game");
		outtextxy(100, 200, "         Exit");
		
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if((x >= 80 && x <= 250) && (y >= 140 && y <= 160)) choose = 1;
			if((x >= 80 && x <= 250) && (y >= 190 && y <= 210)) choose = 2;
		}
		
		if(choose == 1){
			cleardevice();                 // xoa man hinh
			
			int win = 0;				   // nguoi thang
			int sl = 0;                    // so lan danh
			bool turn = true;    		   // luot danh
			
			for(int i = 0; i < n; i++){    // gan gia tri ban dau = 0
				for(int j = 0; j < n; j++){
					arrLoca[i][j] = 0;
				}
			}
			
			while(true){
			for(int i = 0; i <= n; i++){
				line(margin * i + size, margin, margin * i + size, margin + n * size);    //ve hang doc
			}
	
			for(int i = 0; i <= n; i++){
				line(margin, margin * i + size, margin + n * size, margin * i + size);    //ve hang ngang
			}
		
		
		
			delay(0.0001);
			if(ismouseclick(WM_LBUTTONDOWN)){
				getmouseclick(WM_LBUTTONDOWN, x, y);
			
				if(x >= margin && x <= margin * (n + 1) && y >= margin && y <= margin * (n + 1)){
					int xAr = (x-margin)/size;
					int yAr = (y-margin)/size;
					if(turn){            // player 1
						if(arrLoca[xAr][yAr] == 0){
							arrLoca[xAr][yAr] = 1;
							turn = !turn;
							/*if(checkWin(arrLoca[xAr][yAr], xAr, yAr)){
								win = 1;
							}*/
							p = checkWin(arrLoca[xAr][yAr], xAr, yAr);
							if(*(p + 4) == 1){         // neu ar[4] != 0 thi la dung
								win = 1;
							}
							sl++;
						}
					
					}else{               // player 2
						if(arrLoca[xAr][yAr] == 0){
							arrLoca[xAr][yAr] = 2;
							turn = !turn;
							/*if(checkWin(arrLoca[xAr][yAr], xAr, yAr)){
								win = 2;
							}*/
							p = checkWin(arrLoca[xAr][yAr], xAr, yAr);
							if(*(p+4) == 1){
								win = 2;
							}
							sl++;
						}
					}
				
					//printf("%d %d", (x-margin)/size, (y-margin)/size);
				}
			}
		
		
		// In ki tu X -- O
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					if(arrLoca[i][j] == 1){
						int xPi = i * size + margin + size / 2;
						int yPi = j * size + margin + size / 2;
						outtextxy(xPi, yPi, "X");
					}else if(arrLoca[i][j] == 2){
						int xPi = i * size + margin + size / 2;
						int yPi = j * size + margin + size / 2;
						outtextxy(xPi, yPi, "O");
					}
				}
			}
		
		
		// In ra nguoi choi chien thang
		
			if(win == 1){
				int x1 = p[0] * size + margin + size / 2;
				int x2 = p[1] * size + margin + size / 2;
				int y1 = p[2] * size + margin + size / 2;
				int y2 = p[3] * size + margin + size / 2;
				printf("%d %d %d %d", p[0], p[1], p[2], p[3]); 
				outtextxy(200, n * size + margin + 10, "player 1 win!");
				line(x1, y1, x2, y2);
				
				Sleep(2000);
				cleardevice();
				break;
			}
			if(win == 2){
				int x1 = p[0] * size + margin + size / 2;
				int x2 = p[1] * size + margin + size / 2;
				int y1 = p[2] * size + margin + size / 2;
				int y2 = p[3] * size + margin + size / 2;
				printf("%d %d %d %d", p[0], p[1], p[2], p[3]);
				outtextxy(200, n * size + margin + 10, "player 2 win!");
				line(x1, y1, x2, y2);
				
				Sleep(2000);
				cleardevice();
				break;
			}
			if(win == 0 && sl >= n*n){
				outtextxy(200, n * size + margin + 10, "HOA!!!!");
				Sleep(2000);
				cleardevice();
				break;
			}
		}
	}
	
	if(choose == 2) break;
		
	}
	
	
	system("pause");
	closegraph();
		
	return 0;
}

int * checkWin(int p, int x, int y){
	static int ar[5];
	for(int i = 0; i < 5; i++)
		ar[i] = 0;
	
	//while(true){
		// kiem tra hang ngang
		int xt1 = x;
		int xt2 = x;
		int yt1 = y;
		int yt2 = y;
		int count = 1;
		
		while(true){
			if(xt1 > 0){
				xt1--;
			//	ar[0] = xt1;    	 // luu gia tri x1
			//	ar[1] = y;       	 // luu gia tri y1
				if(arrLoca[xt1][y] == p){
					count++;
				}else{ 
					xt1 = 0;         // Gan = 0 de thoat if
				}
			}
			if(xt2 < n - 1){
				xt2++;
			//	ar[2] = xt2;    	 // luu gia tri x2
			//	ar[3] = y;     	     // luu gia tri y2
				if(arrLoca[xt2][y] == p){
					count++;
				}else{
					xt2 = n - 1;     // Gan = n - 1 de thoat if
				}
			}
			if(count == level) {
				ar[0] = xt1;
				ar[1] = yt1;
				ar[2] = xt2;
				ar[3] = yt2;
				ar[4] = 1;
				return ar;
			}
			if(xt1 == 0 && xt2 == n - 1) break;
		}
		
		// kiem tra hang doc
		xt1 = x;
		xt2 = x;
		yt1 = y;
		yt2 = y;
		count = 1;
		
		while(true){
			if(yt1 > 0){
				yt1--;
			//	ar[0] = x;			 // luu x1;
			//	ar[1] = yt1;		 // luu y1
				if(arrLoca[x][yt1] == p){
					count++;
				}else{
					yt1 = 0;         // Gan = 0 de thoat if
				}
			}
			if(yt2 < n - 1){
				yt2++;
			//	ar[2] = x;           // luu x2
			//	ar[3] = yt2;		 // luu y2
				if(arrLoca[x][yt2] == p){
					count++;
				}else{
					yt2 = n - 1;     // Gan = n - 1 de thoat if
				}
			}
			if(count == level) {
				ar[0] = xt1;
				ar[1] = yt1;
				ar[2] = xt2;
				ar[3] = yt2;
				ar[4] = 1;
				return ar;
			}
			if(yt1 == 0 && yt2 == n - 1) break;
		}
		
		// kiem tra duong cheo 1 
		xt1 = x;
		xt2 = x;
		yt1 = y;
		yt2 = y;
		
		count = 1;
		while(true){
			if(xt1 > 0 && yt1 > 0){
				xt1--;
				yt1--;
			//	ar[0] = xt1;       // luu x1
			//	ar[1] = yt1;       // luu y1
				if(arrLoca[xt1][yt1] == p){
					count++;
				}else{
					xt1 = 0;
					yt1 = 0;
				}
			}
			if(xt2 < n - 1 && yt2 < n - 1){
				xt2++;
				yt2++;
			//	ar[2] = xt2;        // luu x2
			//	ar[3] = yt2;		// luu y2
				if(arrLoca[xt2][yt2] == p){
					count++;
				}else{
					xt2 = n - 1;
					yt2 = n - 1;
				}
			}
			if(count == level) {
				ar[0] = xt1;
				ar[1] = yt1;
				ar[2] = xt2;
				ar[3] = yt2;
				ar[4] = 1;
				return ar;
			}
			if((xt1 == 0 || yt1 == 0) && (xt2 == n - 1 || yt2 == n - 1)) break;
		}
		
		// kiem tra duong cheo 2 
		xt1 = x;
		xt2 = x;
		yt1 = y;
		yt2 = y;
		count = 1;
		while(true){
			if(xt1 < n - 1 && yt1 > 0){
				xt1++;
				yt1--;
			//	ar[0] = xt1;         // luu x1
			//	ar[1] = yt1;         // luu y1
				if(arrLoca[xt1][yt1] == p){
					count++;
				}else{
					xt1 = n - 1;			// thoat if
					yt1 = 0;				
				}
			}
			if(xt2 > 0 && yt2 < n - 1){
				xt2--;
				yt2++;
			//	ar[2] = xt2;  		 // luu x2;
			//	ar[3] = yt2; 		 // luu y2;
				if(arrLoca[xt2][yt2] == p){
					count++;
				}else{
					xt2 = 0;
					yt2 = n - 1;
				}
			}
			if(count == level) {
				ar[0] = xt1;
				ar[1] = yt1;
				ar[2] = xt2;
				ar[3] = yt2;
				ar[4] = 1;
				return ar;
			}
			if((xt1 == n - 1 || yt1 == 0) && (xt2 == 0 || yt2 == n - 1)) break;
		}
		
//	}
	
	
	
	
	return ar;
}
