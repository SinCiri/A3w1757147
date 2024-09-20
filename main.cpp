#include <iostream>
#include<fstream>
#include<sstream>
#include "Songcpp.h"
#include "VectorADTcpp.h"

// question can we write a functor to do adjust insert and adjust remove?
// can this be done in the LessThan functor?
// if not then here is where we can do it
// not ideal solution
void adjustInsert(VectorADT<Song> &mySongs, int index ){
  Song * temp= new Song();
for (int i=index;i<mySongs.size();i++){
  temp=mySongs.get(i);
  temp->setChartPosition(i+1);
}
}
void adjustRemove(VectorADT<Song> &mySongs, int index ){
  Song * temp= new Song();
for (int i=index;i<mySongs.size();i++){
  temp=mySongs.get(i);
  temp->setChartPosition(temp->getChartPosition()-1);
}
}



int populatedataBase(VectorADT<Song> &mySongs){
  std::ifstream input("SongsData.txt");
  std::string line;
  std::string title;
  std::string singer;
  std::string cp;//chart position in string
  int chartPosition=0;
  int dataCount=0;
  if (!input){
    throw new std::string("File Open Error ");
    exit(-1);
  }
  while (std::getline(input,line)){
   // std::getline(input,line);
    std::string token;
      std::istringstream instream(line);
      std::getline(instream,title, ',');
      std::getline(instream, singer, ',');
      std::getline(instream, cp,'\n');
     // std::cout<<cp<<std::endl;
      chartPosition = std::stoi(cp);
      Song * s = new Song(title,singer,chartPosition);
      mySongs.push_back(s);
      dataCount++;

      }  
return dataCount;
}

int main() {

VectorADT<Song> database;

int dataCount=populatedataBase(database);
//std::cout<<"DATA COUNT "<<dataCount<<std::endl;
//database.printVectorADT();
LessThan<Song> f;
ChartPos<Song> c;
// sort according to chart position
//int steps =database.sort(f);
// use radix sort

int steps = database.radixSort(c);

std::cout<<"*************************************\n";
 std::cout<<"Radix Sorting By Chart Position Steps = "<<steps<<std::endl;
 std::cout<<"*************************************\n";
  std::cout<<"Printing Database Sorted By Chart Position "<<std::endl;
 database.printVectorADT();
 Song *insertThis= new Song("music is this","BTS",dataCount+1);
 database.push_back(insertThis);
 std::cout<<"*************************************\n";
std::cout<<"After push_back, size of Data base  "<<database.size()<<std::endl;
 
//database.printVectorADT();
Song * temp =database.pop();
std::cout<<"The last song is "<<temp->toString()<<std::endl;
temp=database.pop_back();
std::cout<<"After pop_back, size of Data base  "<<database.size()<<std::endl;
//database.printVectorADT();


Song *insertThis2= new Song("fifth place","BTS",5);
//insert a new song with chart position 5 at index 6 of the database
//this will move the rest of the songs down, but not change their chart position
int insertSteps=database.insert(insertThis2, 5);//will go into 6th position
std::cout<<"inserted song at index 6 "<<insertThis2->toString()<< " Number of insert  adjust steps= "<<insertSteps<<std::endl;
//adjustInsert adjusts all the chartpositions at and after index 5 that were out of order
//due to the insert
adjustInsert(database,5);
//database.printVectorADT();

 std::cout<<"After insert, size of Data base  "<<database.size()<<std::endl;
Song * removeThis = database.get(4);
// removes the song at index 4 
std::cout<<"Going to Remove song " <<removeThis->toString()<<" at index 4 "<<std::endl;
//this will move the rest of the songs up, but not change their chart position
int removeSteps=database.remove(4);
std::cout<<"removed element at index 4 - Number of remove adjust steps= "<<removeSteps<<std::endl;
std::cout<<"After remove, size of Data base  "<<database.size()<<std::endl;
//database.printVectorADT();
//adjust remove adjusts all the chart positions that were out of order 
adjustRemove(database,4);
//database.printVectorADT();
int searchSteps=0;

// back up the database 
VectorADT<Song> backup= database;
//backup.printVectorADT();
//use a functor that compares titles to sort by title
LessThanEqual<Song> g;

//change from selection sort to mergesort backup by title
//backup.sortTitle(g);
int mergeSortSteps=backup.mergeSortByTitle(g);
std::cout<<"*************************************\n";
 std::cout<<"Merge Sorting Backup Database By Title Steps  = "<<mergeSortSteps<<std::endl;
 std::cout<<"*************************************\n";
  std::cout<<"Printing Backup Sorted By Title\n";
backup.printVectorADT();
std::cout<<"Searching for removed song by title "<<removeThis->toString()<<"\n";

int found =backup.binarySearchByTitle(searchSteps,removeThis);

if (found >=0) std::cout<<"FOUND - Took Binary Search Steps - "<<searchSteps<<"\n";
else std::cout<<"NOT FOUND - Took Binary Search Steps - "<<searchSteps<<"\n";
std::cout<<"*************************************\n";
found =backup.binarySearchByTitle(searchSteps,insertThis2);
if (found >=0) std::cout<<"FOUND - Took Binary Search Steps - "<<searchSteps<<"\n";
else std::cout<<"NOT FOUND - Took Binary Search Steps - "<<searchSteps<<"\n";
std::cout<<"*************************************\n";
// search for the last song of the database
Song * lastSong = database.pop();
found =backup.binarySearchByTitle(searchSteps,insertThis2);
if (found >=0) std::cout<<"FOUND last song of database - Took Binary Search Steps - "<<searchSteps<<"\n";
else std::cout<<"NOT FOUND - Took Binary Search Steps - "<<searchSteps<<"\n";
std::cout<<"*************************************\n";

} 
