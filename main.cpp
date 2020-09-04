#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;


void merge(int givenArray[], int lowIndex, int firstThird,
           int secondThird, int highIndex, int dupArray[]) {

	int i = lowIndex, j = firstThird, k = secondThird, l = lowIndex;
	while((i < firstThird) && (j < secondThird) && (k < highIndex)) {
		if(givenArray[i] < givenArray[j]) {
			if(givenArray[i] < givenArray[k]) {
				dupArray[l++] = givenArray[i++];
			} else {
				dupArray[l++] = givenArray[k++];
			}
		} else {
			if(givenArray[j] < givenArray[k]) {
				dupArray[l++] = givenArray[j++];
			} else {
				dupArray[l++] = givenArray[k++];
			}
		}
	}
	while((i < firstThird) && (j < secondThird)) {
		if(givenArray[i] < givenArray[j]) {
			dupArray[l++] = givenArray[i++];
		} else {
			dupArray[l++] = givenArray[j++];
		}
	}
	while((j < secondThird) && (k < highIndex)) {
		if(givenArray[j] < givenArray[k]) {
			dupArray[l++] = givenArray[j++];
		} else {
			dupArray[l++] = givenArray[k++];
		}
	}
	while((i < firstThird) && (k < highIndex)) {
		if(givenArray[i] < givenArray[k]) {
			dupArray[l++] = givenArray[i++];
		} else {
			dupArray[l++] = givenArray[k++];
		}
	}
	while(i < firstThird)
		dupArray[l++] = givenArray[i++];
	while(j < secondThird)
		dupArray[l++] = givenArray[j++];
	while(k < highIndex)
		dupArray[l++] = givenArray[k++];
}

void mergeSortThreeWayRecursion(int givenArray[], int lowIndex,
                                int highIndex, int dupArray[]) {
	if(highIndex - lowIndex < 2)
		return;
	int firstThird = lowIndex + ((highIndex - lowIndex) / 3);
	int secondThird = lowIndex + 2 * ((highIndex - lowIndex) / 3) + 1;
	mergeSortThreeWayRecursion(dupArray, lowIndex, firstThird, givenArray);
	mergeSortThreeWayRecursion(dupArray, firstThird, secondThird, givenArray);
	mergeSortThreeWayRecursion(dupArray, secondThird, highIndex, givenArray);
	merge(dupArray, lowIndex, firstThird, secondThird, highIndex, givenArray);
}

void mergeSortThreeWay(int givenArray[], int dataSize) {
	if(dataSize == 0)
		return;
	int dupArray[dataSize];
	for(int i = 0; i < dataSize; i++)
		dupArray[i] = givenArray[i];
	mergeSortThreeWayRecursion(dupArray, 0, dataSize, givenArray);
	for(int i = 0; i < dataSize; i++)
		givenArray[i] = dupArray[i];
}

void printArray(int dataSize,int data[]) {
	cout<< "After 3 way merge sort: ";
	for(int i = 0; i < dataSize; i++) {
		cout<< data[i] << " ";
	}
}
void writeSortedArrayToTxtFile(int dataSize,int data[]) {
	ofstream myfile;
	myfile.open ("sorted.txt");
	myfile << "After 3 way merge sort: ";
	for(int i = 0; i < dataSize; i++) {
		myfile<< data[i] << " ";
	}
	myfile.close();
}
int main() {
	int data[] = {10,-19,20,-40,83,86,-96,-32,69,100,99,-87,17,29,15,0,-54};
	int dataSize = sizeof(data)/sizeof(data[0]);
	mergeSortThreeWay(data,dataSize);
	printArray(dataSize,data);
	writeSortedArrayToTxtFile(dataSize,data);
	return 0;
}

