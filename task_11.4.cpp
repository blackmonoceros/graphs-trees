// TASK 11.4

 #include <iostream>
 
 #include <list>

using namespace std;

void PrzegladDFS(int f,bool wglab[],list<int>*adj){
   wglab[f]=true;
   cout<<f<<" ";

   
   for(auto i=adj[f].begin();i!=adj[f].end();++i){
      if (!wglab[*i]){
      PrzegladDFS(*i,wglab,adj);
      }
   }
}

void DFS(int poczatek,list<int>*adj,int a){
    
   bool*wglab=new bool[a];
   for (int i=0; i<a; i++){
      wglab[i]=false;
   }

    
   PrzegladDFS(poczatek,wglab,adj);

    
   delete[]wglab;
}

int main(){
   int a,e;
   cout<<"Wpisz ilosc (wierzcholki SPACJA krawedzie: ";
   cin>>a>>e;

   list<int>*adj=new list<int>[a];

   cout <<"Dodaj krawedzie (FORMAT k1 SPACJA k2):\n\n";
   for(int i=0;i<e;i++){
      int k1,k2;
      cin>>k1>>k2;
      adj[k1].push_back(k2);
      adj[k2].push_back(k1); 
   }

   cout<<"Przegladanie grafu DFS:\n\n";
   DFS(0,adj,a);

   delete[]adj;

    return 0;
}
