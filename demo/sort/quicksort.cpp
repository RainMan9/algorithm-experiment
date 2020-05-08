#include <iostream>
#include <vector>
using namespace std;

/*
实现思路是这样的：
1.当只有一个元素时，它总是已经排好序的直接返回。
2.取最后一个为pivot，比pivot小的元素存储在[0,lessend)[0,lessend)中。
3.遍历[begin,end−1)[begin,end−1)，如果它小于pivot就把它添加到[0,lessend)[0,lessend)中，同时让less_end++。
4.将pivot放到[0,lessend)[0,lessend)的结尾。
5.为[begin,lessend)[begin,lessend)排序，此时less_end处的元素是pivot；同样为右边的[lessend+1,end)[lessend+1,end)也排序。
*/
void quicksort(vector<int>& v, int begin, int end){
    if(end - begin<=1) return;
    int pivot = v[end-1], less_end = begin;

    for(int i=begin; i<end-1; i++)
        if(v[i]<pivot) swap(v[i], v[less_end++]);

    swap(v[end-1], v[less_end]);
    quicksort(v, begin, less_end);
    quicksort(v, less_end + 1, end);
}

int main()
{
	vector<int> vec = {7, 5, 16, 8};
	vec.push_back(26);
	quicksort(vec, 0, vec.size());
	for (int n : vec){
		cout << n << '\n';
	}
}

