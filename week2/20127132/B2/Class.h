#pragma once
#include "Student.h"

class Class
{
	vector<Student> lophoc;
private:
	//Phương thức phụ
//kiểm ra trùng tên
	bool checkSame(string m, string n)
	{
		int size1 = m.size();
		int size2 = n.size();
		if (size1 != size2)
			return false;
		else
			for (int i = 0; i < size1; i++)
			{
				if (m[i] != n[i])
					return false;
			}
		return true;
	}
	//kiểm ra tên có trong lớp học hay chưa
	int checkExist(string s, vector<Student> a, int n)
	{
		for (int i = 0; i < n; i++)
		{
			if (checkSame(a[i].Name(), s))
				return i;
		}
		return -1;
	}

	// Quick Sort
	int partition(vector<Student>& a, int l, int r)
	{
		int i = l - 1, j = r;
		float v = a[r].Mean();
		for (;;)
		{
			while (a[++i].Mean() > v)
				;
			while (v > a[--j].Mean())
				if (j == l)
					break;
			if (i >= j)
				break;
			swap(a[i], a[j]);
		}
		swap(a[i], a[r]);
		return i;
	}
	void quicksort(vector<Student>& a, int l, int r)
	{
		if (r <= l)
			return;
		int i = partition(a, l, r);
		quicksort(a, l, i - 1);
		quicksort(a, i + 1, r);
	}
public:
	Class(int&);
	void add(int&);
	void deleteStudent(int&);
	void sortMean(int&);
	void display(int&);
};