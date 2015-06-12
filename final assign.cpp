#include<iostream>
using namespace std;
template<class T> 

class MyList{
    template <class T1> friend MyList<T1> operator + (const MyList<T1> &l1, const MyList<T1> &l2); 
    template <class T1> friend MyList<T1> operator + (const MyList<T1> &l1, const T1 &item); 
    template <class T1> friend ostream & operator<<(ostream &os, const MyList<T1> &obj);
private:
    T *element;
	int total_size;int real_size;
	void double_space();
public:
	//constructors
	MyList(){
		real_size = 0;
		total_size = 100;
		element= new T [total_size];
	}
	MyList(int num, const T &item);
	MyList(const MyList &l);//copy_constructor
    MyList(T* arr, int len);
    
    void push(const T &item);
    T pop();
    void insert(int index, const T &item);
    void clean();
    int get_size();
    void erase(int start, int end);
    T get_item(int index);
    MyList<T> get_item(int start, int end);
    int count(const T &item);
    void remove(const T &item);
    
    MyList<T> &operator = (const MyList &l);
    MyList<T> &operator += (const T &item);
    MyList<T> &operator += (const MyList &l);
    T &operator [](int index);
    
    void sort(bool less);
    void reverse();
	
	
	//destructor
	~MyList(){delete [] element;}	
};
template <class T>
void MyList<T>:: double_space(){
		total_size = total_size * 2;
		T *elem;
		elem = new T [total_size];
		for (int i=0;i<total_size/2;++i) elem[i] = element[i];
		for (int i=total_size/2;i<total_size;++i) elem[i] = 0;
		delete [] element;
		element =elem;}
		//The total_size will be double if it is not enough
		
		
template <class T>
MyList<T>::MyList(int num, const T &item){
        element = new T [num];
	    total_size = num;
	    real_size=num;
	    for (int i=0; i<real_size; ++i) 
		element[i] = item;	}
		// repeat item num times and fill it in element[]
		
		
template <class T>
MyList<T>::MyList(const MyList &l){
		total_size = l.total_size;
		real_size=l.real_size;
	    element = new T [total_size];
	    for (int i=0; i<real_size; ++i) 
		element[i] = l.element[i];}
		//Copy another list
		
		
template <class T>
MyList<T>::MyList(T* arr, int len){
	    element = new T [len];
	    total_size =len;
	    real_size=len;
	    for (int i=0; i <real_size; ++i)
        element[i] = arr[i];}
		//construct another list with the first len elements in this list


template <class T>
	void MyList<T>::push(const T &item){
	if (real_size>=total_size) double_space();
		element[real_size] = item;
		++real_size;
}//add item to the list
template <class T>
T  MyList<T>:: pop(){
	 try{
		if (real_size > 0){
			T tmp = element[real_size-1];
			--real_size; 
			return tmp;
		}
		else throw 1;
	}
	catch(int err){
		cout << "The list you pop is empty!" << endl; 
	}
}
//pop the top element out of list

template <class T>
void MyList<T>::insert(int index, const T &item){
		try{
	    	if (index>=0 && index <=real_size){
	    		if(real_size+1>total_size){
	    			double_space();
				}
			for (int i=real_size; i>index; i--)
			 element[i] = element[i-1];
			 element[index] = item;

			real_size++;
		}
		else throw 2;
	}
	catch(int err){
		cout << "The index you insert is nonexist!" << endl;
	}
}
//insert an item at assigned index

template <class T>
void  MyList<T>::clean(){
	real_size=0;
	delete[] element;
	element = new T [0]; }
	//clean up the whole list
	
	
template <class T>
int MyList<T>:: get_size(){
	return real_size;}
	
template <class T>
void MyList<T>::erase(int start, int end){
	try{
		if (start>=0 && end<=real_size && start<=end){
		   int i;
		   for (i=start;i<real_size-end+start-1;++i) element[i] =element[i+end-start+1];
		   int tmp = i;
		   real_size = real_size - end + start - 1;
		}
		else throw 3;
	}
	catch(int err){
		cout << "The range you erase is wrong£¡" << endl;
	}
}
	  
	  
	  
template <class T>
T MyList<T>:: get_item(int index){
	return element[index];	
	}


template <class T>
MyList<T>MyList<T>::get_item(int start, int end){
	if (start < 0) start = start + real_size;
	if (end < 0) end = end + real_size;
	try{
		if (start>=0 && start<=real_size-1 && end>=0 && end<=real_size-1){
			if (start > end){
				T tmp[0];
			    MyList tmpp(tmp,0);
			    return tmpp;
			}
			else{
				T *arr = new T [end-start+1];
				for (int i=start; i<=end; ++i) arr[i-start] = element[i];
				MyList<T> tmppp(arr, end-start+1);
				return tmppp;
			}
		}
		else throw 1;
	}

	catch(int ex){
		cout << "Error! In function get_item: The range which you want to get is invalid!" << endl;
	}
}
//get item from index"start" to index "end"


template <class T>
int MyList<T>::count(const T &item){
		int counter;
		for (int i=0;i<real_size;++i)
		{if (element[i] == item) ++counter;}
		return counter;}
		
		
template <class T>
void MyList<T>::remove(const T &item){
	for (int i=0; i<real_size; ++i){
		if (element[i] == item) {
		erase(i, i);
		 break;}
}
}
//remove the first element that equals to "item"


	 
template <class T>
MyList<T>&MyList<T>::operator = (const MyList &l){
	if (this == &l) return *this; 
	delete [] element;
	total_size = l.total_size;
	real_size = l.real_size;
	element = new T [total_size]; 
	for (int i=0; i<real_size; ++i) element[i] = l.element[i];
	return *this; 
}//override the operator =


template <class T>
     MyList<T>&MyList<T>::operator += (const T &item){
		if (real_size>=total_size) double_space();
		element[real_size] = item;
		++real_size;
		return *this;
	}//override the operator +=



template <class T>
     MyList<T>&MyList<T>::operator += (const MyList &l){
		int addlen=real_size;
		real_size = l.real_size +addlen;
		for (int i=addlen;i<real_size;++i) 
		{	if (total_size <= real_size) double_space();
			element[i] = l.element[i-addlen];
		}
		return *this;}
//override the operator += for another list

template <class T>
     T &MyList<T>::operator [](int index){
		try{
		if (index >= 0 && index <= real_size-1){
			return element[index];
		}
		else throw 4;
	}
	catch(int err){
		cout << "In operator [] you take a invalid index!" << endl;
	}
}//define the operator []

template<class T>
ostream & operator<<(ostream &os, const MyList<T> &obj){
     int i;
	 os << '[';
	 if (obj.real_size > 0){
		for (i=0; i<obj.real_size - 1; ++i) os << obj.element[i] << ", " ;
		os << obj.element[obj.real_size - 1];
	}
	cout << ']' ;
	return os;
}//override the operator <<


template<class T>MyList<T> operator + (const MyList<T> &l1, const MyList<T> &l2){
	MyList<T> tmp(l1);
	for (int i=0;i<l2.real_size;++i)
		tmp.push(l2.element[i]);
	return tmp;}
//override the operator + for another list


template<class T> 
MyList<T> operator + (const MyList<T> &l1, const T &item){
	MyList<T> tmp(l1);
	tmp.push(item);
	return tmp;
}
	
	//override the operator +
	
template <class T>
void quicksort(T*element ,int left,int right) 
  { 
    int i,j,t; 
    if(left>right) 
       return; 
                                
    T temp=element[left]; 
    i=left; 
    j=right; 
    while(i!=j) 
    {
        while(element[j]>=temp && i<j) 
            j--; 
        while(element[i]<=temp && i<j) 
            i++;         
        if(i<j) 
        {  t=element[i]; 
           element[i]=element[j];          
           element[j]=t;                    
                   } 
    } 
    element[left]=element[i]; 
    element[i]=temp;                  
    quicksort(element,left,i-1);
    quicksort(element,i+1,right);
} 
//quicksort for the "sort" function

template <class T> 
void  MyList<T>::sort(bool less=true){
		quicksort(element,0,real_size-1);
      if(!less){reverse();
	   } 
   }	
   
template <class T>
void  MyList<T>::reverse(){
	T *tmp;
	tmp = new T [real_size];
	for (int i=real_size-1; i>=0; --i) tmp[real_size-1-i] = element[i];
	element= tmp;}
	//reverse the order



int main(){
	MyList<int> a, b;
	int i;
	for (i=0; i<5; ++i)
		a.push(i);
    // a = [0, 1, 2, 3, 4]
	a[3] = 15; // a = [0, 1, 2, 15, 4]
	a.sort(); // a = [0, 1, 2, 4, 15]
	a.reverse(); // a = [15, 4, 2, 1, 0]
	a += 12; // a = [15, 4, 2, 1, 0, 12]
	for (i=0; i<a.get_size(); ++i)
		cout<<a[i]<<endl;
    b = a.get_item(4, -3); // b = [] *if start>end, return a empty array
	b = a.get_item(3, -1); // b = [1, 0, 12] 
	a += b; // a = [15, 4, 2, 1, 0, 12, 1, 0, 12]
	for (i=0; i<a.get_size(); ++i)
		cout<<a.get_item(i)<<endl;
	cout<<a.count(5)<<endl;
	b.clean(); // b = []
	cout<<b.get_size()<<endl;
	a.erase(2, 5); // a = [15, 4, 0, 12]
	b = a + a; // b = [15, 4, 0, 12, 15, 4, 0, 12]
	b.insert(3, 116); // b = [15, 4, 0, 116, 12, 15, 4, 0, 12]
	b.remove(4); // b = [15, 0, 116, ...]
	cout<<b<<endl;
	MyList<double> c(10, 3.14);
	for (i=0; i<100; ++i)
		c.push(1.1*i);
	cout<<c.get_item(100, 105)<<endl;
	
	return 0;
}


