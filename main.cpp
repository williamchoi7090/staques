#include <bits/stdc++.h>
using namespace std;
  
class Stack{
  queue<int> a, b;
  int curr_size;
  public:
  Stack(){
    curr_size= 0;
  }
  void pop(){
    if (a.empty())
    return;
    while (a.size()!= 1){
      b.push(a.front());
      a.pop();
    }
    a.pop();
    curr_size--;
    queue<int>c = a;
    a= b;
    b= c;
  }
  void push(int x){
    a.push(x);
    curr_size++;
  }
  int top(){
    if (a.empty())
    return -1;
    while (a.size()!= 1) {
      b.push(a.front());
      a.pop();
    }
    int temp= a.front();
    a.pop();
    b.push(temp);
    queue<int>c= a;
    a= b;
    b= c;
    return temp;
  }
  int size(){
    return curr_size;
  }
};

int main(){
  Stack s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);
  cout<< "The size is: "<< s.size()<< endl;
  cout<< s.top()<< endl;
  s.pop();
  cout<< s.top()<< endl;
  s.pop();
  cout<< s.top()<< endl;
  s.pop();
  cout<< s.top()<< endl;
  cout<< "The new size is: "<< s.size();
  return 0;
}