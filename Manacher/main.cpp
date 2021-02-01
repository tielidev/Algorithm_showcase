#include <iostream>
#include <vector>
using namespace std;
void mana(const  string& s){
    cout << "输入的字符串是：\n" << s << "\n";
    cout << "现在执行manacher算法\n";

    int sz = s.size();
    vector<char> processed_s(2*sz+1,'#');
    for(int i=0;i<sz;++i){
        processed_s[2*i+1] = s[i];
    }
    sz = 2*sz + 1;


    int C =0,R = 0,mirror;
    vector<int> len(sz,0);
    for(int i=1;i<sz;++i){
        mirror = 2*C-i;

        if(i < R){
            len[i] = min(len[mirror],R-i);
        }

        while (i - len[i] - 1 >=0 && i + len[i] + 1 < sz && processed_s[i-len[i]-1] == processed_s[i+len[i]+1]){
            len[i]+=1;
        }

        if(i + len[i] > R){
            C = i;
            R = i + len[i];
        }
    }

    for(int i=0;i<sz;++i){
        cout << len[i] << " ";
    }




}




int main() {
    mana("ABABABA");


    return 0;
}
