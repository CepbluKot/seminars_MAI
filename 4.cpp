#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <string>
#include <cstdlib>
#include <ctime>
#include <exception>

void testMap()
{
    std::map<std::string, int> myMap;
    std::string inputStr;
    std::string buff = "";
    std::cout<<"ENTER TEXT: ";
    getline(std::cin, inputStr);
    int i = 0;
    int buffNumber = 0;
    while (i < inputStr.length())
    {
        buffNumber = i;
        if (buffNumber >= inputStr.length())
        {
            if (i == 0)
                std::cout << "empty string" << std::endl;

            else
                std::cout << "string over" << std::endl;

            break;
        }
        while ((inputStr[buffNumber] != ' ') and (buffNumber != inputStr.length()))
        {
            buff.push_back(inputStr[buffNumber]);
            buffNumber++;
        }
        myMap[buff]++;
        buff.clear();
        i = buffNumber + 1;
    }
    std::map<std::string, int>::iterator it = myMap.begin();
    for (int j = 0; it != myMap.end(); it++, j++) std::cout << j + 1 << ") word " << it->first << ", repeats " << it->second << " times"<<std::endl;
    
}

void testVector()
{
    try
    {
        int length1, length2;
        std::cout << "vect1 = " << std::endl;
        std::cin >> length1;
        std::cout << "vect2 = " << std::endl;
        std::cin >> length2;
        if (length1 < 1 || length2 < 1) throw std::out_of_range("vect1 or vect2 invalid len");
        

        std::vector<int> vect1(length1);
        std::vector<int> vect2(length2);

        srand(time(NULL));
        float sum1(0), sum2(0);

        for (int i = 0; i < length1; i++)
        {
            vect1[i] = rand() % 201 - 100;
            std::cout << vect1[i] << " ";
        }
        std::cout << std::endl;

        for (int i = 0; i < length2; i++)
        {
            vect2[i] = rand() % 101 - 100;
            std::cout << vect2[i] << " ";
        }
        std::cout << std::endl;

        for (int i = 0; i < length1; i++) sum1 += vect1[i];
        
        std::cout << "average vect1 = " << sum1 / length1 << std::endl;

        for (int i = 0; i < length2; i++) sum2 += vect2[i];
        
        std::cout << "average vect2 = " << sum2 / length2 << std::endl;

        int min, max;
        if (vect1.size() < vect2.size())
        {
            min = vect1.size();
            max = vect2.size();
        }
        else if (vect1.size() != vect2.size())
        {
            min = vect2.size();
            max = vect1.size();
        }
        else
        {
            min = vect1.size();
            max = min;
        }

        if (min == vect1.size())
        {
            for (int i = 0; i < min; i++)
            {
                for (int j = i; j < max; j++)
                {
                    if (vect1[i] == vect2[j])
                    {
                        std::cout << vect1[i] << " ";
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < min; i++)
            {
                for (int j = i; j < max; j++)
                {
                    if (vect2[i] == vect1[j])
                    {
                        std::cout << vect2[i] << " ";
                    }
                }
            }
            std::cout << std::endl;
        }
    }

    catch (std::out_of_range e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
}

void printStack(int i, std::vector<std::vector<int>> &matrix)
{
    std::vector<bool> used(matrix.size(), false);
    std::stack<int> st;

    while (i != -1)
    {
        if (used[i] == false)
        {
            used[i] = true;

            for (int j = 0; j < matrix.size(); j++)
                if (matrix[i][j] == 1 && used[j] == false)
                    st.push(j);
        }

        if (!st.empty())
        {
            i = st.top();
            st.pop();
        }
        else
            i = -1;
    }

    for (bool a : used)
    {
        std::cout << a << ' ';
    }
    std::cout << std::endl;
}

void testStack()
{
    int count;
    std::cout<<"\nENTER testStack data:"<<std::endl;
    std::cin >> count;
    const int vertexCount = count;
    std::vector<std::vector<int>> matrix(vertexCount, std::vector<int>(vertexCount, 0));
    int x;
    for (int i = 0; i < vertexCount; i++)
    {
        matrix[i][i] = 1;
        do
        {
            std::cin >> x;
            if (x != 0) matrix[i][x - 1] = 1;
            
        } while (std::cin.peek() != '\n');
    }
    for (int i = 0; i < vertexCount; i++) printStack(i, matrix);
}

int main()
{
    testMap();
    testVector();
    testStack();

    return 0;
}