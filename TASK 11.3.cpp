//TASK 11.3

 #include <iostream>
 #include <queue>
 #include <list>

using namespace std;

void przegladBFS(int poczatek,list<int>*adj,int a){
   bool*wszerz=new bool[a];
   for(int i=0;i<a;i++)
      wszerz[i]=false;

   queue<int>u;

   wszerz[poczatek]=true;
   u.push(poczatek);

   while(!u.empty()){
      int f=u.front();
      u.pop();
      cout<<f<<" ";

      for(auto i=adj[f].begin();i!= adj[f].end();++i){
         if (!wszerz[*i]){
               wszerz[*i]=true;
               u.push(*i);
          }
      }
  }

      delete[]wszerz;
}


int main(){
   int a,e;
   cout<<"Wpisz ilosc (wierzcholki SPACJA krawedzie: ";
   cin>>a>>e;

   list<int>*adj=new list<int>[a];

   cout<<"Dodaj krawedzie (FORMAT k1 SPACJA k2):\n\n";
   for (int i=0;i<e;i++){
        int k1,k2;
        cin>>k1>> k2;
        adj[k1].push_back(k2);
        adj[k2].push_back(k1); 
   }

   cout<<"Przegladanie grafu BFS:\n\n";
   
   przegladBFS(0,adj,a);

   delete[]adj;

    return 0;
}