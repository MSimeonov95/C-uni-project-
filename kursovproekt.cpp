#include<iostream>
#include<algorithm>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

int arrSize = 0;
int ordArrSize = 0;


void readFromKeyboard(int arr[], int &size);
void readFromFile(int arr[], int &size);
void filterArrayMinNumber(int arr[],int arr1[]);
void sortData(int arr[]);
void printOrdArray(int arr[]);
void avgNegNumsOrdArr(int arr[]);

int main(){
    int *array1= new int[arrSize];
    int size = 0;
    int *ordArr= new int[ordArrSize];
    

    cout<<
    "Choose where to get your array: " <<endl<<
    "0.Prompt"<<endl<<
    "1.Text file"<<endl;

    int choice;
    cin>>choice;

    switch(choice){
        case 0:{
            readFromKeyboard(array1,size);
            filterArrayMinNumber(array1,ordArr);
            sortData(ordArr);
            printOrdArray(ordArr);
            avgNegNumsOrdArr(ordArr);
            break;
        }
        case 1:{
            readFromFile(array1,size);
            filterArrayMinNumber(array1,ordArr);
            sortData(ordArr);
            printOrdArray(ordArr);
            avgNegNumsOrdArr(ordArr);
            break;
        }
    }
    return 0;
}





void readFromKeyboard(int arr[], int &size) {
    cout << "Enter the size of the array: ";
    cin >> size;
    while (size>100 ||size <1)
    {
        cout<< "You must enter array size up to 100"<<endl;
        cin >> size;
    }
   
    for (int i = 0; i < size; i++) {
        cout << "Enter the element of the array "<< i << " :" << endl;
        cin >> arr[i];
        arrSize++;
    }
    
    cout<<
    "Do you want to save your array : " <<endl<<
    "0.Yes"<<endl<<
    "1.No"<<endl;

    int choiceyn;
    cin>>choiceyn;
    switch(choiceyn){
        case 0:{
            string fileName;
            cout << "Enter the name of the file in which to store the array : ";
            cin >> fileName;
            ofstream myfile (fileName);
            if (myfile.is_open()) {
                for(int i = 0;i<arrSize; i++){
                    myfile << arr[i] << endl;
                }
            }
            break;
        }
        case 1:{
            cout<<"Array will not be stored"<<endl;
            break;
        }
    }
    
}

void readFromFile(int arr[], int &size) {
    string fileName;
    askUser:
    cout << "Enter the name of the file: ";
    cin >> fileName;
    ifstream myfile (fileName);
    if (myfile.is_open()) {
        int i = 0;
        while(!myfile.eof()){
            int x; 
			myfile >> x; 
			if (myfile.eof()) 
				break; 
			arr[arrSize++] = x; 
    }
    myfile.close();
    }
    else {
        cout << "Unable to open file"<<endl;
        goto askUser;
    }
} 

void filterArrayMinNumber(int arr[],int arr1[]){
    int min_num;
    int count = 0;
    cout<<"Enter minimal number: "<< endl;
            cin >> min_num;

            for(int i = 0;i<arrSize; i++){
                if(min_num < arr[i]){
                    ordArrSize++;
                }
            }
            
            for(int i = 0;i<arrSize; i++){
                if(min_num < arr[i]){
                arr1[count] = arr[i];
                count++;
                }
            }

}

void sortData(int arr[]){
    int temp;
    if(ordArrSize > 1){
        for (int i = 0; i < ordArrSize; i++) {
                for (int j = i + 1; j < ordArrSize; j++) {
                    if (arr[i] < arr[j]) {
                        temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
    }
    
}
void printOrdArray(int arr[]){
    if(ordArrSize > 0){
    cout << "Array  has these numbers" << endl; 
    for (int i = 0; i < ordArrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    }else{
        cout<< "Array is empty" << endl; 
    }
    
}
void avgNegNumsOrdArr(int arr[]){
     int negCount = 0;
     int sum = 0;
     for (int i = 0; i < ordArrSize; i++){
        if(arr[i] < 0){
            sum = sum + arr[i];
            negCount++;
        }
     }
     
     if(negCount > 1){
        float avgNeg = 0;
        avgNeg = sum/negCount;
        cout <<"The average of the negatives is : "<< avgNeg <<endl;
     }else{
        cout<<"There are no negative numbers in this array"<<endl;
        
     }
     
}
