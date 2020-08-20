#include<iostream>
#include<climits>    
using namespace std;
#define Ver_tex 7      
int mini_Dist(int Dist[], bool Dist_set[])  
{
	int MIN=INT_MAX,index;                
	for(int a=0;a<Ver_tex;a++)
	{
		if(Dist_set[a]==false && Dist[a]<=MIN)      
		{
			MIN=Dist[a];
			index = a;
		}
	}
	return index;
}
void dij_k(int Graph[Ver_tex][Ver_tex],int abc)
{
	int dist[Ver_tex];                             
	bool Dset[Ver_tex];
	for(int i=0;i<Ver_tex;i++)                  
	{
		dist[i]=INT_MAX;
		Dset[i]=false;	
	}
	dist[abc]=0;                                  
	for(int c=0;c<Ver_tex;c++)                           
	{
		int x=mini_Dist(dist,Dset);            
		Dset[x]=true;                             
		for(int y=0;y<Ver_tex;y++)                  
	
		{
			if(!Dset[y] && Graph[x][y] && dist[x]!=INT_MAX && dist[x]+Graph[x][y]<dist[y])
			dist[y]=dist[x]+Graph[x][y];
		}
	}
	cout<<"=> Vertex\t=> Distance from source"<<endl;
	for(int i=0;i<Ver_tex;i++)                       
	{
		char c=65+i;
		cout<<" \t"<<c<<"\t\t\t\t\t\t"<<dist[i]<<endl;
	}
}
int main()
{
	int Graph[Ver_tex][Ver_tex]={{0,5,3,0,0,0,0},{0,0,2,0,3,0,1},{0,0,0,7,7,0,0},{2,0,0,0,0,6,0},{0,0,0,2,0,1,0},{0,0,0,0,0,0,0},
		                        {0,0,0,0,1,0,0}};
	dij_k(Graph,0);
	return 0;	                        
}