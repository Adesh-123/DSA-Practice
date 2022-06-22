int Solution::solve(vector<int> &A, int B) {
    int cxor=0;
    int count=0;
    map<int,int> m;
    for(int i=0;i<A.size();i++){
       cxor^=A[i];
       if(cxor==B) count++;
       int y=cxor^B;
       if(m.find(y)!=m.end()){
           count+=m[y];
       }
       m[cxor]++;
    }
    return count;
}
