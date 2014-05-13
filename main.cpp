#include<iostream>
using namespace std;
/**
*data set:
8
1 1
9 6
4 6
1 5
6 4
3 3
5 3
5 1

*/
int main()
{
    int count;
    cin>>count;
    int* array=new int[count*2];
    for(int i=0;i<count;i++){
        cin>>array[i*2]>>array[i*2+1];
    }
    //begin process data

    int * msg=new int[count*4];

    for(int i=0;i<count*4;i++){

        msg[i]=1;
    }

    int flag=0;
    for(int i=0;i<count-1 && flag==0;i++){
        for(int j=i+1;j<count&&flag==0;j++)
        {
            if(array[i*2+1]==array[j*2+1]){//纵坐标相等
                msg[i*4]++;
                msg[j*4]++;
                cout<<"diagonal:"<<array[i*2]<<" "<<array[i*2+1]<<"+"<<array[j*2]<<" "<<array[j*2+1]<<endl;
                if(msg[i*4]>2||msg[j*4]>2){
                    flag=1;
                    cout<<array[i*2]<<" "<<array[i*2+1]<<endl;
                    cout<<"Yummy!Thanks, study brothers memeda!"<<endl;
                }
            }else if((array[i*2+1]-array[j*2+1])== (array[i*2]-array[j*2])){//斜率为1
                msg[i*4+1]++;
                msg[j*4+1]++;
                cout<<"diagonal:"<<array[i*2]<<" "<<array[i*2+1]<<"+"<<array[j*2]<<" "<<array[j*2+1]<<endl;
                if(msg[i*4+1]>2||msg[j*4+1]>2)
                {
                    cout<<"flag changed"<<msg[i*4+1]<<" "<<msg[j*4+1]<<endl;
                    flag=1;
                    cout<<array[i*2]<<array[i*2+1]<<endl;
                    cout<<"Yummy!Thanks, study brothers memeda!"<<endl;
                }
            }else if(array[i*2]==array[j*2]){//横坐标相同
                msg[i*4+2]++;
                msg[j*4+2]++;
                cout<<"diagonal:"<<array[i*2]<<" "<<array[i*2+1]<<"+"<<array[j*2]<<" "<<array[j*2+1]<<endl;
                if(msg[i*4+2]>2||msg[j*4+2]>2)
                {
                    flag=1;
                    cout<<array[i*2]<<array[i*2+1]<<endl;
                    cout<<"Yummy!Thanks, study brothers memeda!"<<endl;
                }
            }else if((array[j*2+1]-array[i*2+1])== (array[i*2]-array[j*2])){//斜率为-1
                msg[i*4+3]++;
                msg[j*4+3]++;
                cout<<"diagonal:"<<array[i*2]<<" "<<array[i*2+1]<<"+"<<array[j*2]<<" "<<array[j*2+1]<<endl;
                if(msg[i*4+3]>2||msg[j*4+3]>2)
                {
                    flag=1;
                    cout<<array[i*2]<<array[i*2+1]<<endl;
                    cout<<"Yummy!Thanks, study brothers memeda!"<<endl;
                }
            }
        }
    }

    if(flag==0){
        cout<<"T_T, long live my slim figure!";
    }

    delete [] array;
    delete [] msg;
}
