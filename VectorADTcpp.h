
#include <iostream>
#include "VectorADT.h"


template <class T>
 VectorADT<T>::VectorADT
 (){
    dataArray= new  T*[SIZE];
    count=0;
  }
//TODO Copy constructor that is called when a new vectorADT ic created and  equated with the "other" ADT vector object
 template <class T>
   VectorADT<T>::VectorADT(const VectorADT<T> &other){
    //TODO
  }
  //destructor
//template <class T>
//TODO
 

template <class T>
  void VectorADT<T>::resizeADT(){
      size_t newSize=2*count;
      SIZE=SIZE*2;
      T ** tempADT = new T*[newSize];
      for (int i=0;i<count;i++)
        tempADT[i]= dataArray[i];
      delete [] dataArray;
      dataArray=tempADT;
      
  }
  template <class T>
  void VectorADT<T>::push_back(T *v){
    //std::cout<<song->toString();
    
    if (count>=SIZE)
       resizeADT();
    
    dataArray[count]= v;
    count++;
   
    
  }
  template <class T>
   T * VectorADT<T>::pop(){
     if (!empty())
       return dataArray[count-1];
    else{
      throw new std::string("No such element exception");
      exit(-1);
    }
   }
  template <class T>
   T * VectorADT<T>::pop_back() {
     T * v = new T();
     if (!empty()){
      v= dataArray[count-1];
      count--;
      return v;}
     else {
      throw new std::string("No such element exception");
      exit(-1);
    }
   }
  template <class T>
  void VectorADT<T>::printVectorADT(){
    for (int i=0;i<count;i++)
         std::cout<<dataArray[i]<<"\n";
  }
  template <class T>
   int VectorADT<T>::size() const
   { return count;}

template <class T>
int  VectorADT<T>::sortTitle(LessThanEqual<T> less){
//TODO
}
  template <class T>
int VectorADT<T>::sort(LessThan<T> less){
  int steps=0;
  T * minValue= new T();
   int minIndex=0;
   for (int i=0;i<count;i++){
      minValue=dataArray[i];
      minIndex=i;
  for (int j=i+1;j<count;j++){
    if (less(*dataArray[j],*minValue)){
     
      minValue=dataArray[j];
      minIndex=j;
    }
     steps++;
  }
    dataArray[minIndex]=dataArray[i];
    dataArray[i]=minValue;
   
  }
  return steps;
  }
 
template <class T>
   bool VectorADT<T>:: empty(){
     return (count<=0);
   }
template <class T>
   T* VectorADT<T>:: get(int i) const{
     if (i>=0 && i<count)
       return dataArray[i];
    else 
      {
      throw new std::string("No such element exception");
      exit(-1);
    }
   }
  template <class T>
  void VectorADT<T>::set(int i, T * t){
    if (i>=0 && i<count)
       dataArray[i]=t;
    else 
      {
      throw new std::string("No such element exception");
      exit(-1);
    }
  }
 
  template <class T>
  int VectorADT<T>::insert(T * v, int pos){  
    // USe from Assignment 1
     return 0; // change this
  }
  template <class T>
  int VectorADT<T>::remove(int pos){
    //Use from Assignment 1
    return 0;//change this
  }
  template <class T>
   
int VectorADT<T>::binarySearchByTitle(int& steps, T * v, int first, int last){
   return 0;//change this
   //TODO
}
template <class T>
int  VectorADT<T>::binarySearchByTitle(int& steps, T * v){
  return binarySearchByTitle( steps, v, 0, count-1);
}

//TODO
  template <class T>
  void  VectorADT<T>::Merge(LessThanEqual<T> le,int &steps, int i, int j, int k)
 { //TODO
  //Merge the partitions
}


 template <class T>
void   VectorADT<T>::mergeSortByTitle(LessThanEqual<T> le,int &steps,int i,int k) {
//TODO
   //call merge with the functor, steps and partition indices
      //Merge(le,steps, i, j, k);
   
}

//GIVEN CODE Starter Recursive Function for Merge Sort
 template <class T>
int   VectorADT<T>::mergeSortByTitle(LessThanEqual<T> le){
int steps=0;
mergeSortByTitle(le,steps,0,size()-1);
return steps;
}
template <class T>


//TODO
int VectorADT<T>::radixSort(ChartPos<T> c){
  int steps=0;
  //we know that max number will be max chart position 
  //calculate maximum digits of count//this will give maxDigits
  int maxDigits= 0;
  //calculate ;
  //create 10 vectors to act as buckets
  
  std::vector<int> * buckets = new std::vector<int> [10];

  

  
  // Start with the least significant digit
   int pow10 = 1;
   for (int digitIndex = 0; digitIndex < maxDigits; digitIndex++) {
     std::vector<T *> * buckets = new std::vector<T *> [10];
    //COMPLETE THE CODE  
      pow10 = 10 * pow10;
    //  delete [] buckets;
   }
   
    return steps;
   
}
    
  