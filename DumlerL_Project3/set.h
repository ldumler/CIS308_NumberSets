/**********************************************
* Name: Lauren Dumler						  *
* Date: December 5, 2017					  *
* Assignment: Project 3: Sets				  *
***********************************************
* This program takes 2 sets of numbers and	  *
prints out the union, difference, or		  *
intersection of them.						  *
***********************************************/

#pragma once
#ifndef SET_H
#define SET_H
template <class T>
class Set {
public:
	T *stuff = new T[8];
	int length = 8;
	int place = 0;
	void add(T);
	~Set<T>(void);
	Set<T>();
	void print(void);
	void resize(void);
	void Union(Set<T> *s);
	void Intersection(Set<T> *s);
	void Difference(Set<T> *s);
	void quickSort(T arr[], int, int);
	int partition(T arr[], int, int);
};
#endif