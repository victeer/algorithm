#include<iostream>
#include<vector>
using namespace std;
vector<long long> budai;
/**
data:
2147383649  2147483647
*/



void getPrim(int max)
{
    int isPrim=0;
    budai.push_back(2);
    for(int st=3;st<=max;st+=2){
        isPrim=0;
        for(int i=0;isPrim==0;i++){
            if(st%budai[i]!=0){
                if(budai[i]*budai[i]>st){
                    budai.push_back(st);
                    isPrim=1;
                }
            }else{
                break;
            }
        }
    }
    cout<<"budai��С��"<<budai.size()<<endl;
	cout<<"���һ��"<<budai[budai.size()-1]<<"ƽ��Ϊ"<<budai[budai.size()-1]*budai[budai.size()-1]<<endl;
	if(budai[budai.size()-1]*budai[budai.size()-1]<2147383649 ){
		cout<<"�򲻹���"<<endl;
	}

}

bool checkPrim(int num){
    for(int i=1;budai[i]*budai[i]<num && i<budai.size();i++)
    {
        if(num%budai[i]==0){
            return false;
        }
    }
    return true;
}
int main(){
    //˼·:�����1-2^16���ڵ�����������Ȼ�����α�����L-H�����ݣ�
    //�ó������ڵ���������������ֵ����Сֵ��
    int low,high,minArray[2],maxArray[2],min=-1,max=0;
    int pre=-1,cur=-1;
    cin>>low>>high;
    cout<<low <<" "<<high<<endl;
    if(low%2==0){//low �������
        if(low==2)  pre=2;
        low=low+1;
    }
    getPrim(65535);
    for(long i=low;i<=high;i+=2){
        if(checkPrim(i))//is prim
        {
            cur=i;
            if(pre!=-1)//֮ǰ�Ѿ���һ��������
            {
                int now=cur-pre;
                if(min==-1){
                    min=max=now;
                    minArray[0]=pre;
                    minArray[1]=cur;
                    maxArray[0]=pre;
                    maxArray[1]=cur;
                }else if(now>max){
                    max=now;
                    maxArray[0]=pre;
                    maxArray[1]=cur;
                }else if(now<min){
                    min=now;
                    minArray[0]=pre;
                    minArray[1]=cur;
                }
            }
            pre=cur;
        }
    }

    if(min==-1){
        cout<<"-1"<<endl;
    }else{
        cout<<minArray[0]<<" "<<minArray[1]<<" "<<maxArray[0]<<" "<<maxArray[1]<<endl;
    }


}

