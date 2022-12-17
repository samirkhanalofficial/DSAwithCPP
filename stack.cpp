#include "iostream"
#define MAXSIZE 5
using namespace std;
class stack{
    private:
        int i , top , stackbox[MAXSIZE];
    public:
        stack(){
            top=-1;
        }
        void push(int item){
            if(top==-1){
                top++;
            }
            if(top>=MAXSIZE){
                cout<<"Stack overflow"<<endl;
            }
            else{
                stackbox[top] = item;
                top++;

            }
        }
        void pop(){
            if(top<=0){
                cout<<"stack underflow"<<endl;
            }else{
                top--;
            }
        }
        void display(){
            cout<<"stack = [";
            for(i=0;i<top;i++){
                cout<<stackbox[i]<<" , ";
            }
            cout<<"]"<<endl;
        }
};

int main(){
    int input=1;
    stack s;
    while(input!=0){

        s.display();
        cout<<"Enter the value to perform task:"<<endl<<"0) end \n1) push \n2) pop \n";
        cin>>input;

            system("clear");
            s.display();

        if(input==1){
            int inputToPush;
            cout<<"enter the value to push : ";
            cin>>inputToPush;
            s.push(inputToPush);
        }
        else if (input == 2){
            
            s.pop();
        }
        else{
            cout<<"exited";
        }
    
    }
   
    return 0;
}