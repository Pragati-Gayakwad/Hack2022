// This is a greedy solution to the Fractional Knapsack problem, implemented in C++

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// structure to represent each item 
struct item
{
    int item_no;
    int profit;
    int weight;
    float ratio;
};

// compare function to be used with std::sort to sort the array
// of items on the basis of profit to weight ratio
bool compareByRatio(const item &a, const item &b)
{
    return a.ratio > b.ratio;
}

int main()
{
    vector<item> list;
    int bag_capacity, total_items;

    cout << "Enter capacity of bag: ";
    cin >> bag_capacity;

    cout << "Enter total number of items available: ";
    cin >> total_items;

    for (int i = 1; i <= total_items; i++)
    {
        int p, w;
        float r;

        // taking the profit and weight of each item as input
        cout << "Enter details of item " << i << ":\n";
        cout << "Enter profit: ";
        cin >> p;
        cout << "Enter weight: ";
        cin >> w;

        // 'r' is profit to weight ratio
        r = (p / (float)w);

        // pushing each item into the list
        item temp = {i, p, w, r};
        list.push_back(temp);
    }

    // each item is sorted on the basis of profit to weight ratio
    sort(list.begin(), list.end(), compareByRatio);

    // knapsack[i] stores the ratio of item 'i' that is included in the knapsack vs total amount of item 'i' available
    // knapsack[i] is (-1) if the item doesn't exist
    vector<float> knapsack(total_items + 1, (-1));

    for (int i = 1; i <= total_items && bag_capacity >= 0; i++)
    {
        item temp = list.at(i - 1);
        if (temp.weight <= bag_capacity)
        {
            knapsack.at(temp.item_no) = (1);
            bag_capacity -= temp.weight;
        }
        else if (temp.weight > bag_capacity)
        {
            knapsack.at(temp.item_no) = ((float)bag_capacity / temp.weight);
            bag_capacity = 0;
        }
    }

    cout << "\nThe solution vector is: ";
    for (int i = 1; i <= total_items; i++)
    {
        cout << "\nItem no: " << i << ", inclusion: " << knapsack.at(i);
    }

    float max_profit = 0;

    // calculating the maximum profit that can be earned from the given list of items that can
    // be included in the knapsack
    for (int i = 1; i <= total_items; i++)
    {
        if (knapsack.at(i) > 0)
        {
            for (int j = 1; j <= total_items; j++)
            {
                if (list.at(j - 1).item_no == i)
                    max_profit += knapsack.at(i) * list.at(j - 1).profit;
            }
        }
    }

    cout << "\n\nThe maximum profit is: " << max_profit << "\n";

    return 0;
}