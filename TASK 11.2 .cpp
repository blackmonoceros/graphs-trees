//TASK 11.2

#include <iostream>
#include <list>
using namespace std;

int main(){
   int w,k;
   cin>>w>>k;

   
   list<int>*listS=new list<int>[w+1];

   
   for(int i=0;i<k;i++){
      int x,y;
      cin>>x>>y;
        
      listS[x].push_back(y);
        
      listS[y].push_back(x);
   }
   
   
   for(int i=1; i<=w; i++){
      listS[i].sort();
      cout<<i;
        
      for(int neighbor:listS[i]){
         cout<<"  "<<neighbor;
        }
      cout<<endl;
    }

   delete[]listS;
    
    return 0;
}

