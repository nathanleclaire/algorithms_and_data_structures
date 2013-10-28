#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>

using namespace std;

static const int LOWERBOUND = -100000000;
static const int UPPERBOUND = 100000000;

static string NAIVE = "Naive";
static string SUAVE = "Suave";
static string SUAVE_BSEARCH = "SuaveBsearch";

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
    int i;
	for (i = 0; i < n - 1; i++)
	{
		cout << v.at(i) << ", ";
	}
    if (n > 0)
    {
        cout << v.at(n-1);
    }
	cout << "}";
}

vector<int> three_vec(int i, int j, int k)
{
	int arr[] = {i, j, k};
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
				cout << "The elements: " << value_index_vec.at(i).value << " " << value_index_vec.at(j).value << " " << value_index_vec.at(k).value << endl;
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


vector<int> three_indices_that_sum_to_zero_suave_bsearch(vector<int> v) {
    typedef vector<index_value_pair>::iterator IVP_It;

    int n = static_cast<int>(v.size());

	vector<index_value_pair> value_index_vec;
    value_index_vec.reserve(n);
	for (int i = 0; i < n; i++) {
		value_index_vec.push_back(make_index_value_pair(i, v.at(i)));
	}
	sort(value_index_vec.begin(), value_index_vec.end(), suave_comp);

    IVP_It i_it, j_it, k_it;
    for (i_it = value_index_vec.begin(); i_it < value_index_vec.end() - 2; ++i_it) {
        j_it = i_it + 1;
        k_it = value_index_vec.end();

        while (j_it != k_it) {
            int sum = (*i_it).value + (*j_it).value;
            k_it = lower_bound(j_it + 1, k_it, -sum,
                    [](const index_value_pair& a, const int& val){ return a.value < val; });

            //printf("[%d]:%d [%d]:%d [%d]:%d\n",
            //        (*i_it).index, (*i_it).value,
            //        (*j_it).index, (*j_it).value,
            //        (*k_it).index, (*k_it).value);

            if (sum + (*k_it).value == 0) {
                return { (*i_it).index , (*j_it).index, (*k_it).index };
            }

            j_it++;
        }
    }

    return {-1, -1, -1};
}


void print_performance(const clock_t& begin_time)
{
	cout << "Performance: " << clock() - begin_time << " ticks" << endl;
}

void print_and_benchmark_indices_version(string which, const vector<int>& problem_vector)
{
	vector<int> indices;
	const clock_t begin_time = clock();
	if (which == NAIVE)
	{
		cout << "Using naive..." << endl;
		indices = three_indices_that_sum_to_zero_naive(problem_vector);
	} else if (which == SUAVE) {
		cout << "Using suave..." << endl;
		indices = three_indices_that_sum_to_zero_suave(problem_vector);
    } else if (which == SUAVE_BSEARCH) {
		cout << "Using suave bsearch..." << endl;
		indices = three_indices_that_sum_to_zero_suave_bsearch(problem_vector);
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
	vector<int> problem_vector = {-1, 6, 8, 9, 10, -100, 78, 0, 1};
    if (argc > 1) {
        problem_vector = generate_vector_with_random_integers(atoi(argv[1]));
    }

	//print_my_vector(problem_vector);
	cout << endl;

	print_and_benchmark_indices_version(NAIVE, problem_vector);
	print_and_benchmark_indices_version(SUAVE, problem_vector);
	print_and_benchmark_indices_version(SUAVE_BSEARCH, problem_vector);

	cout << endl;
	return 0;
}
