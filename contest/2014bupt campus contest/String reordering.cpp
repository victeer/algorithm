#include<iostream>
#include<string>
using namespace std;


int main(){
/**

*/

string x;

    while(cin>>x){
        int a[36]={0};
        char c[37]="0123456789abcdefghijklmnopqrstuvwxyz";
        int end=0;
        for(int i=0;i<x.length() && end==0 ;i++){
            if(x[i]>='0' && x[i]<='9')//satisfy condition
            {
                a[x[i]-'0']++;
            }else if(x[i]>='a'&&x[i]<='z'){
                a[x[i]-'a'+10]++;
            }else{
                end=1;
                cout<<"<invalid input string>"<<endl;
            }
        }

        if(end==0)
        {
            int zeroCount=0;
            while(zeroCount!=36){
                zeroCount=0;
                for(int i=0;i<36;i++)
                {
                    if(a[i]>0)
                    {
                        cout<<c[i];
                        a[i]--;
                    }else{//已经没有了。
                        zeroCount++;
                    }
                }
            }
            cout<<endl;
        }
    }
}
