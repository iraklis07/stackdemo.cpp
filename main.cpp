#include <iostream>
using namespace std;

template <typename T>
class stack {
public: 
  stack (int size) {
    data=new T[size];
    for(int i=0;i<size;i++) {
      data[i]=0;    
    }
    top=0;
  }
  stack (const stack &s) { 
    data=new T[s.top];
    for(int i=0;i<s.top;i++) {
      data[i]=s.data[i];
      top=s.top;
    }
  }
  ~stack () {
    delete [] data;
  }
  const stack & operator = (const stack &s) {  
    for(int i=0;i<top;i++) {
      data[i]=s.data[i];
    }
  }

  bool empty () {
    return top==0;
  }
  void push (const T &x) {
    data[top++]=x;
  }
  T pop () {
    return data[--top];
  }
  int size () {
    return top;
  }

  friend ostream & operator << (ostream &out, const stack &s) {
    out << "[";
    for (int i=0;i<s.top-1;i++){
       out << s.data[i] <<", " ; 
    }
    if (s.top!=0) out << s.data[s.top-1] << "]";
    else out << "]";
    return out; 
  }

private:  
  T *data;
  int top;
}; 

