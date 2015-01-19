#include<graphics.h> 
#include<alloca.h>
#include<math.h>
void k_means(int x[], int y[], int k,int m,int iter);
int main()
{
   int gd = DETECT,gm,left=100,top=100,right=200,bottom=200,radius=50;
   initgraph(&gd,&gm,NULL);
   int midY = (getmaxy())/2;
   int midX = (getmaxx())/2;
   int x[50];
   int y[50],i=0;
   line(midX,0,midX,getmaxy());
   line(0,midY,getmaxx(),midY);
   while(i<50){
   x[i] = rand()%getmaxx();
   y[i]=  rand()%getmaxy();
   outtextxy(x[i],y[i],"X");
   i++;
   };
   k_means(x,y,4,50,20);
   getch();
   closegraph();
   return 0;
}

float dist(int x1, int y1, int x2, int y2){
	float dist_ = pow(x2-x1,2)+pow(y2-y1,2); 
	return sqrt(dist_);
}
void k_means(int x[], int y[], int k,int m, int iter){
  int i = 0,j=0;
  int* ux = (int*)malloc(sizeof(int)*k);
  int* uy = (int*)malloc(sizeof(int)*k);
  int* c = (int*)malloc(sizeof(int)*m);
  int t = 0;
  while(t<iter){
	while(i<k){
		ux[i]= x[rand()%50];
		uy[i]= y[rand()%50];
		i++;
	}
	i=0;
	while(i<m){
		int j =0;
		float minDist = 1000;
		int min = 0;
		while(j<k){
			float _dist = dist(x[i],y[i],ux[j],uy[j]); 
			if(_dist<minDist){
				minDist = _dist;
				min = j; 
			}
			j++;
		}
		c[i] = min;
		i++;
	}
	j=0;
	while(j<k){
		float sumX = 0;
		float sumY = 0;
		int count = 0;
		i = 0;
		while(i<m){
			if(c[i]==j){
				sumX+=x[i];
				sumY+=y[i];
				count++;
			}
			i++;
		}
		ux[j] = sumX/count;
		uy[j] = sumY/count;
		j++;
	}
	t++;
 }
 cleardevice();
 i = 0;
 while(i<m){
 	char p[2];
 	sprintf(p,"%d",c[i]);
 	outtextxy(x[i],y[i],p);
 	i++;
 }
}
