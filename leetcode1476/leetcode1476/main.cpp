#include<iostream>
#include<vector>
using namespace std;

class SubrectangleQueries {
private:
    vector<vector<int>> rectangle;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        this->rectangle = rectangle;
    }

    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for (int i = row1; i <= row2; i++)
        {
            for (int j = col1; j <= col2; j++)
            {
                this->rectangle[i][j] = newValue;

            }
        }
    }

    int getValue(int row, int col) {
        return this->rectangle[row][col];
    }
    void printMatr()
    {
        for (int i = 0; i < this->rectangle.size(); i++)
        {
            for (int j = 0; j < this->rectangle[i].size(); j++)
            {
                cout << this->rectangle[i][j] << " , ";
            }
            cout << endl;
        }
    }
};
int main()
{
    /*
    {"SubrectangleQueries","getValue","updateSubrectangle","getValue","getValue","updateSubrectangle","getValue","getValue"}
{{{{1,2,1},{4,3,4},{3,2,1},{1,1,1}}},{0,2},{0,0,3,2,5},{0,2},{3,1},{3,0,3,2,10},{3,1},{0,2}}
    */
    
    vector<vector<int>> matr = {{{1,2,1},{4,3,4},{3,2,1},{1,1,1}}};
    SubrectangleQueries* rect = new SubrectangleQueries(matr);
    rect->printMatr();
    int getVal = rect->getValue(0, 2);
    cout << "getValue: " << getVal << endl;
    rect->updateSubrectangle(0, 0, 3, 2, 5);
    rect->printMatr();
    getVal = rect->getValue(3, 1);
    cout << "getValue: " << getVal << endl;
    rect->updateSubrectangle(3, 0, 3, 2, 10);
    rect->printMatr();
    getVal = rect->getValue(3, 1);
    cout << "getValue: " << getVal << endl;
    getVal = rect->getValue(0, 2);
    cout << "getValue: " << getVal << endl;

	system("pause");
	return 0;
}