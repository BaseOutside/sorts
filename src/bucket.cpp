#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

int init_vec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        vec.at(i) = i;
    }
    random_device rd;
    mt19937 shuffle_engine(rd());
    shuffle(vec.begin(), vec.end(), shuffle_engine);
    return 0;
}

int bucket_sort(vector<int> &vec)
{
    vector<int> bucket(*max_element(vec.begin(), vec.end()) + 1);
    for (int i = 0; i < vec.size(); ++i)
    {
        ++bucket.at(vec.at(i));
    }
    int k = 0;
    for (int i = 0; i < bucket.size(); ++i)
    {
        for (int j = 0; j < bucket.at(i); ++j)
        {
            vec.at(k) = i;
            ++k;
        }
    }
    return 0;
}

int main()
{
    vector<int> vec(100);
    init_vec(vec);

    bucket_sort(vec);

    for (int &i : vec)
    {
        cout << i << endl;
    }
    return 0;
}
