#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>

#define LOWERBOUND -100
#define UPPERBOUND 100

#define NAIVE "Naive"
#define SUAVE "Suave"

using namespace std;

typedef struct index_value_pair {
	int index;
	int value;
} index_value_pair;

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

bool suave_comp(index_value_pair a, index_value_pair b)
{
	return a.value < b.value;	
}

int sum_from_value_index_vec(const vector<index_value_pair>& v, int i, int j, int k)
{
	return v.at(i).value + v.at(j).value + v.at(k).value;
}

void print_value_index_vec(const vector<index_value_pair>& v)
{
	index_value_pair t;
	int n = v.size();
	cout << "{" << endl;
	for (int i = 0; i < n; i++)
	{
		t = v.at(i);
		cout << "\t(" << t.value << ", " << t.index << ")" << endl;
	}
	cout << "}" << endl;
}

index_value_pair make_index_value_pair(int index, int value)
{
	index_value_pair ivp;
	ivp.index = index;
	ivp.value = value;
	return ivp;
}

vector<int> three_indices_that_sum_to_zero_suave(vector<int> v)
{
	int i, j, k, n, sum;
	n = v.size();
	vector<index_value_pair> value_index_vec;
	for (i = 0; i < n; i++) 
	{
		value_index_vec.push_back(make_index_value_pair(i, v.at(i)));
	}
	// print_value_index_vec(value_index_vec);
	sort(value_index_vec.begin(), value_index_vec.end(), suave_comp);
	for (i = 0; i < n-2; i++)
	{
		j = i+1;
		k = n-1;
		while (k > j)
		{
			sum = sum_from_value_index_vec(value_index_vec, i, j, k);
			if (sum == 0)
			{
				return three_vec(value_index_vec.at(i).index, value_index_vec.at(j).index, value_index_vec.at(k).index);   
			}

			if (sum > 0)
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

void print_performance(const clock_t& begin_time)
{
	cout << "Performance: " << clock() - begin_time << " ticks" << endl;
}

void print_and_benchmark_indices_version(char* which, const vector<int>& problem_vector)
{
	vector<int> indices;
	const clock_t begin_time = clock();
	if (strcmp(which, NAIVE) == 0)
	{
		cout << "Using naive..." << endl;
		indices = three_indices_that_sum_to_zero_naive(problem_vector);
	}
	else
	{
		cout << "Using suave..." << endl;
		indices = three_indices_that_sum_to_zero_suave(problem_vector);
	}
	print_performance(begin_time);
	cout << which << " : ";
	print_my_vector(indices);
	cout << endl;
}

int main(int argc, char* argv[])
{
	srand(time(0));
	cout << "Initializing..." << endl;
	vector<int> problem_vector = generate_vector_with_random_integers(atoi(argv[1]));

	// print_my_vector(problem_vector);
	cout << endl;

	print_and_benchmark_indices_version(NAIVE, problem_vector);
	print_and_benchmark_indices_version(SUAVE, problem_vector);

	cout << endl;
	return 0;
}
