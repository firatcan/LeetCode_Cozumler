#include<iostream>
#include<vector>
using namespace std;

int calculateCombination(int top, int bottom) {

    if (bottom == 0) return 1;
    if (top - bottom == 1) return top;
    std::vector<int> topElements;
    std::vector<int> bottomElements;

    for (int i = 1; i <= bottom; i++) {
        topElements.push_back(top--);
        bottomElements.push_back(i);
    }

    for (int i = 0; i < topElements.size(); i++) {
        for (int j = 0; j < bottomElements.size(); j++) {
            if (topElements[i] % bottomElements[j] == 0) {
                topElements[i] /= bottomElements[j];
                bottomElements[j] = 1;
                if (topElements[i] == 1) {
                    break;
                }
            }
        }
    }
    unsigned long sumTop = 1;
    unsigned long sumBottom = 1;
    for (auto i : topElements) sumTop *= i;
    for (auto i : bottomElements) sumBottom *= i;

    return (sumTop / sumBottom);
}


int climbStairs(int n) {
    int top = n;
    unsigned int sum = 0;
    for (int i = 0; i < ((n / 2) + 1); i++) {
        sum += calculateCombination(top--, i);
    }
    return sum;
}

int main()
{

	cout << climbStairs(7) << endl;
	return 0;
}