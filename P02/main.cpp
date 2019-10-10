/*
Wesley Curtis
P02 (Program 2)
October 10, 2019

This program resizes an array based on the percentage of the list that is full. Things utilized in this program are stacks
*/

#include <iostream>
#include <fstream>
using namespace std;

class Stack
{
private:
	int *Array;
	int top;
	int counter;
	int size;
	bool beenModified;

public:
 	// default constructor for Stack().
	Stack(){
		size=10;
		Array=new int[size];
		top=-1;
		counter=top+1;
		beenModified=false;
	};
	Stack(int s){
		size=s;
		Array=new int[size];
		top=-1;
		beenModified=false;
	};

	// pushes values given to the infile
	bool Push(int value){
		if(!Full()){
			top++;
			counter++;
			Array[top]=value;
			checkResize();
			return 1;
		}
		else
			return 0;
	}

	// pops the first last value added to the stack, then pops it if there is a value to pop.
	int Pop(){
		if(!Empty()){
			int temp=0;
			temp=Array[top];
			top--;
			counter--;
			checkResize();
			return temp;
		}
		return 0;
	}
	
	// checks if the stack is full.
	bool Full(){
	return top==size--;
	}

	// checks if stack is empty.
	bool Empty(){
		return top<0;
	}

	// checks to see if the array needs to be resized, then calls the appropriate function. 
	void checkResize(){
		if(counter>=int(size*.80))
			Enlarge();
		if(counter<=int(size*.20))
			if (beenModified)
				Reduce();
	}

	// enlarges the stack to a bigger size by moving the values to a temporary array then back to the stack once it is modified.
	void Enlarge(){
		int newSize=int(size*1.5);
		int *tempArray=new int[newSize];
		int *del1=NULL;
		for(int i=0; i<size; i++){
			tempArray[i]=Array[i];
		}
		size=newSize;
		del1=Array;
		Array=tempArray;
		delete[] del1;
		beenModified=true;
	}

	// reduces the stack to a smaller size by moving the values to a temporary array then back to the stack once it is modified.
	void Reduce(){
		int oldSize=int(size*.5);
		int *C=new int[oldSize];
		int *del2=NULL;
		for(int i=0; i<oldSize; i++){
			C[i]=Array[i];
		}
		size=oldSize;
		del2=Array;
		Array=C;
		delete[] del2;
	}

	// gets the size of the stack, yep.
	int GetSize(){
		return size;
	}

	// prints all the values remaining in the stack.
	void Print(ofstream& out){

		for (int i=top; i>=0; i--){
			out<<Array[i]<<", ";
		}
		out<<"\n";
	}
};

// determines whether the input is a push or pop.
// if it is a push, then it determines pushes the value then checks to see if there is room in the stack.
// if it is a pop, then it pops.
int main(){
	// opens i/o files
	ifstream fin;
	ofstream fout;
	fin.open("input.txt");
	fout.open("stack_out.dat.txt");

	Stack S;
	char plusOrMinus;
	int num;
	int max=0;

	// described above
	while(fin>>plusOrMinus>>num){
		if(plusOrMinus=='+'){
			S.Push(num);
			if(S.GetSize()>max)
			{
				max=S.GetSize();
			}
		}
		else
		{
			S.Pop();
		}
	}

	// outputs all information
	fout<<"\tWesley Curtis\n\tHomework 2\n\tOctober 8, 2019\n\n";
	fout<<"Size: \t\t\t"<<S.GetSize()<<"\n";
	fout<<"Largest Size:\t"<<max<<"\n";
	fout<<"\nRemaining Items in the Stack:\n\t";
	S.Print(fout);
	fout<<"\n";

	// closes i/o files
	fin.close();
	fout.close();
	return 0;
}
