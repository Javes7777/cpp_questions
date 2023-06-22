#include<iostream>
#include<vector>

template <class T>
class SmarterArray
{
private:
  T *A; //The dynamic array to store the elements
  int size; //The number of elements in the array

public:
  //Constructors
  SmarterArray(); //Implemented for you
  SmarterArray(const SmarterArray<T>&); //Copy constructor. Deep copy of the argument

  //Assignment operator
  SmarterArray<T>& operator = (const SmarterArray<T>&); //Memory cleanup and deep copy of the argument

  //Destructor
  ~SmarterArray(); //Implemented for you

  //Getters, Setters, operators and other functions
  int getSize() const; //Return the number of elements in the container
  T& operator[](const int&) const; //Assert index and then return the element at the given index
  int find(const T&) const; //Return the index of the first element that is == to the argument. 
  //Return -1 if not found.
  void insert(const int &index, const T&); //Assert index >= 0 && index <= size and then insert the T
  //type argument into the calling object at the index. If index is
  //equal to size, then insert as a last element
  void append(const T&);  //Insert T as a last element
  bool remove(const int&); //If the index is valid, then remove the element at the index argument
  //from the calling object and return true. Otherwise do nothing and return 
  //false. Do not assert the index argument.
  bool operator == (const SmarterArray<T>&) const; //Return true if sizes are equal and elements at the
  //same indexes are equal. Otherwise return false
	
  template <class T1> //Those of you working with xCode, don't use the same template name T. T1 is ok.
  friend ostream& operator << (ostream&, const SmarterArray<T1>&); //Implemented for you
};

template <class T>
SmarterArray<T>::SmarterArray()
{
  this->A = nullptr;
  this->size = 0;
}

template<class T>
SmarterArray<T>::SmarterArray(const SmarterArray<T> &L) {
  // deep copy constructor
  this->size=L.getSize();
  if(this->getSize()>0) {
    this->A=new T [this->getSize()];
    for(int i=0;i<this->getSize();i++)
      this->A[i] = L[i];
  }
}

template<class T>
SmarterArray<T>& SmarterArray<T>::operator=(const SmarterArray<T> &L) {
  //assignment operator
  this->~SmarterArray();
  this->size=L.getSize();
  if(this->getSize()>0) {
    this->A = new T[this->getSize()];
    for(int i =0;i<this->getSize();i++) 
      this->A[i] = L[i];
  }
  return *this;
}

template <class T>
SmarterArray<T>::~SmarterArray() {
  // destructor
  if (this->getSize() > 0) {
    delete[] this->A;
    A = nullptr;
    this->size= 0;
  }
}

template<class T>
int SmarterArray<T>::getSize() const {
  //getter
  return this->size;
} 

template<class T>
T& SmarterArray<T>::operator[](const int& index ) const {
  // index operator
  if(index>=0  && index<this->getSize()){
    return this->A[index];
  }
  else {
    cout<<"ERROR! ARRAY INDEX OUT OF BUONDS!";
    abort();
  }
}

template<class T>
int SmarterArray<T>::find(const T &element) const {
  // finding element in SmarterArray
  for(int i=0;i<this->getSize();i++) 
    if(A[i]==element)
      return i+1;
  return -1;// not found
}

template<class T>
void SmarterArray<T>::append(const T& element) {
  // appending element at the end of SmarterArray
  T *temp=new T [this->getSize()+1];
	
  for(int i=0;i<this->getSize();i++) 
    temp[i]=this->A[i];
		
  temp[this->getSize()]=element;
  if(this->getSize()>0)
    delete[] A;

  this->size+=1;
  this->A=temp;
}

template<class T>
void SmarterArray<T>::insert(const int &index, const T &element) {
  // inserting element at index.
  if(index < 0 || index > this->getSize() )    // do nothing
    return;

  if(index == this->getSize() ) 
    this->append(element);

  T *temp=new T[this->getSize()+1];		
  int i = 0;
  for(; i<index; i++) 
    temp[i]=this->A[i];
	
  temp[i]=element;
  i++;

  for(; i<this->getSize(); i++)
    temp[i] = this->A[i-1];

  if(this->getSize()>0)
    delete[] A;
		
  this->A=temp;
  this->size+=1;
}

template<class T>
bool SmarterArray<T>::remove(const int &index) {
  // removing element at index
  if(index > this->getSize()  || index < 0) // do nothing
    return false;
       
  for(int i=0;i<this->getSize();i++) {  // to find.
    if(this->A[i] == A[index]) {
      for(int j=i;j<(this->getSize()-1);j++) {  // to copy
	this->A[j] = this->A[j+1];			
      }
      this->size = this->getSize()-1;
      return true;
    }
  }
  return false;
}

template<class T>
bool SmarterArray<T>::operator == (const SmarterArray<T>& L) const {
  // assignment operator.
  if(this->getSize() != L.getSize()) // do nothing
    return false;
	
  for(int i=0; i<this->getSize(); i++) { 
    if(this->A[i] != L[i])
      return false;
  }
  return true;
}


template <class T>
ostream& operator << (ostream& out, const SmarterArray<T>& L)
{
  if (L.getSize() == 0)
    out << "[Empty List]";
  else
    {
      cout << endl;
      for (int i = 0; i < L.getSize()-1; i++)
	out << L[i] << endl;
      out << L[L.getSize()-1] << endl;
    }
  return out;
}