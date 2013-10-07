#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <tuple>
#include <vector>
#include <algorithm>

#define LOWERBOUND -100
#define UPPERBOUND 100

#define PROBLEM_ARRAY_SIZE 100

using namespace std;

int biased_randint(int min, int max)
{
	// see: http://stackoverflow.com/questions/5008804/generating-random-integer-from-a-range
	return  min + (rand() % (max - min + 1));
}

vector<int> generate_vector_with_random_integers(int n)
{
	vector<int> rand_int_vector;
	for (int i = 0; i < n; i++)
	{
		rand_int_vector.push_back(biased_randint(LOWERBOUND, UPPERBOUND));
	}
	return rand_int_vector;
}

void print_my_vector(const vector<int>& v)
{
	cout << "{";
	int n = v.size();
	for (int i = 0; i < n; i++)
	{
		cout << v.at(i);
		if (i+1 != n)
		{
			cout << ", ";
		}
	}
	cout << "}";
}

vector<int> three_vec(int i, int j, int k)
{
	static const int arr[] = {i, j, k};
	vector<int> indices (arr, arr + sizeof(arr) / sizeof(arr[0]));
	return indices;
}

vector<int> three_indices_that_sum_to_zero_naive(vector<int> v)
{
	// O(n ** 3) time complexity in average case
	int i, j, k, n;
	n = v.size();
	for(i = 0; i < n-2; i++)
	{
		for(j = i+1; j < n-1; j++)
		{
			for(k = j+1; k < n; k++)
			{
				if ((v.at(i) + v.at(j) + v.at(k)) == 0)
				{
					return three_vec(i, j, k);
				}
			}
		}	
	}
	return three_vec(-1, -1, -1); 
}

bool suave_comp(tuple<int, int> a, tuple<int, int> b)
{
	// tuples are format <value, index> so we compare <0> element
	return get<0>(a) < get<0>(b);	
}

int sum_from_value_index_vec(const vector<tuple<int, int>>& v, int i, int j, int k)
{
	return get<0>(v.at(i)) + get<0>(v.at(i)) + get<0>(v.at(i));
}

void print_value_index_vec(const vector<tuple<int, int>>& v)
{
	cout << "{" << endl;
	int n = v.size();
	for (int i = 0; i < n; i++)
	{
		tuple<int, int> t = v.at(i);
		cout << "\t(" << get<0>(t) << ", " << get<1>(t) << ")" << endl;
	}
	cout << "}" << endl;
	
}

vector<int> three_indices_that_sum_to_zero_suave(vector<int> v)
{
	int i, j, k, n;
	n = v.size();
	vector<tuple<int, int>> value_index_vec;
	for (i = 0; i < n; i++) 
	{
		value_index_vec.push_back(make_tuple(v.at(i), i));
	}
	print_value_index_vec(value_index_vec);
	sort(value_index_vec.begin(), value_index_vec.end(), suave_comp);
	for (i = 0; i < n-2; i++)
	{
		j = i+1;
		k = n-1;
		while (k > j)
		{
			if (sum_from_value_index_vec(value_index_vec, i, j, k) == 0)
			{
				return three_vec(get<1>(value_index_vec.at(i)), get<1>(value_index_vec.at(j)), get<1>(value_index_vec.at(k)));   
			}

			if (sum_from_value_index_vec(value_index_vec, i, j, k) > 0)
			{
				k--;
			}
			else
			{
				j++;
			}

		}
	}
	return three_vec(-1, -1, -1);
}

int main()
{
	srand(time(0));
	cout << "Initializing..." << endl;
	vector<int> problem_vector = generate_vector_with_random_integers(PROBLEM_ARRAY_SIZE);
	vector<int> indices_naive = three_indices_that_sum_to_zero_naive(problem_vector);
	vector<int> indices_suave = three_indices_that_sum_to_zero_suave(problem_vector);
	print_my_vector(problem_vector);
	cout << endl;

	cout << "Naive : ";
	print_my_vector(indices_naive);
	cout << endl;

	cout << "Suave : ";
	print_my_vector(indices_suave);
	cout << endl;

	cout << endl;
	return 0;
}
