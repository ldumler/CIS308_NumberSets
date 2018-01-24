/**********************************************
* Name: Lauren Dumler						  *
* Date: December 5, 2017					  *
* Assignment: Project 3: Sets				  *
***********************************************
* This program takes 2 sets of numbers and	  *
prints out the union, difference, or		  *
intersection of them.						  *
***********************************************/

#include "set.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <class T>
Set<T>::~Set(void) {
	delete this->stuff;
}

template <class T> 
Set<T>::Set() {
}

template <class T>
void Set<T>::add(T thing) {
	for (int i = 0; i < place; i++) {
		if (this->stuff[i] == thing) return;
	}
	if (this->place == length) resize();
	this->stuff[place] = thing;
	place++;
}

template <class T> 
void Set<T>::quickSort(T arr[], int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi+1, high);
	}
}

template <class T> int Set<T>::partition(T arr[], int low, int high) {
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		if (arr[j] <= pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

template <class T> 
void Set<T>::print(void) {
	cout << "\n";
	for (int i = 0; i < place; i++) {
		cout << stuff[i] << " ";
	}
}

template <class T> 
void Set<T>::resize(void) {
	this->length *= 2;
	int *temp = new int[this->length];
	for (int i = 0; i < (this->length / 2); i++) {
		temp[i] = this->stuff[i];
	}
	this->stuff = temp;
}

template <class T> 
void Set<T>::Intersection(Set<T> *s) {
	Set<T> *result = new Set<T>();
	//Set<T> result();
	for (int i = 0; i < place; i++) {
		T cur = stuff[i];
		for (int j = 0; j < s->place; j++) {
			if (cur == s->stuff[j]) result->add(stuff[i]);
		}
	}
	result->quickSort(result->stuff, 0, result->place-1);
	result->print();
}

template <class T> 
void Set<T>::Union(Set<T> *s) {
	Set<T> *result = new Set<T>();
	int i;
	for (i = 0; i < place; i++) {
		result->add(stuff[i]);
	}
	for (i = 0; i < s->place; i++) {
		result->add(s->stuff[i]);
	}

	result->quickSort(result->stuff, 0, place-1);
	result->print();
}

template <class T> 
void Set<T>::Difference(Set<T> *s) {
	Set<T> *result = new Set<T>();
	int taken;
	int cur;

	for (int i = 0; i < place; i++) {
		cur = stuff[i];
		taken = 0;
		for (int j = 0; j < s->place; j++) {
			if (cur == s->stuff[j]) taken = 1;
		}
		if (taken == 0) result->add(cur);
	}

	result->quickSort(result->stuff, 0, result->place - 1);
	result->print();
}