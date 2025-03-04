#include <iostream>
#include <vector>

std::vector<int> quickSort(std::vector<int>& arr, 
        const int n, std::vector<int>& result);
void printArr(const std::vector<int> arr, const int n);
std::vector<int> getArray();

int main()
{
    setlocale(LC_ALL, "Russian");
    std::vector<int> arr = getArray();
    printArr(arr, arr.size());
    std::vector<int> resultArr;
    quickSort(arr, arr.size(), resultArr);
    printArr(resultArr, resultArr.size());
    return 0;
}

std::vector<int> quickSort(std::vector<int>& arr,
    const int n, std::vector<int>& result)
{
    int refElIndex = (n - 1) / 2;
    int refEl = arr[refElIndex];
    int i = 0;
    int nLeft = 0;
    int nRight = 0;
    std::vector<int> leftArr;
    std::vector<int> rightArr;
    do
    {
        if (i == refElIndex)
        {
            i++;
            continue;
        }
        if (arr[i] <= refEl)
        {
            leftArr.push_back(arr[i]);
            nLeft++;
        }
        else
        {
            rightArr.push_back(arr[i]);
            nRight++;
        }
        i++;
    }
    while (i < n);
    if (nLeft > 1)
    {
        quickSort(leftArr, nLeft, result);
    }
    else if (nLeft == 1)
    {
        result.push_back(leftArr[nLeft - 1]);
        
        
    }
    result.push_back(refEl);
    if (nRight > 1)
    {
        quickSort(rightArr, nRight, result);
    }
    else if (nRight == 1)
    {

        result.push_back(rightArr[nRight - 1]);
        
    }
    
    return result;
}

void printArr(const std::vector<int> arr, const int n)
{
    for (size_t i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

std::vector<int> getArray()
{
    std::vector<int> arr;
    std::cout << "Введите размер массива: ";
    int size = 0;
    std::cin >> size;
    for (size_t i = 0; i < size; i++)
    {
        std::cout << "Введите " << i + 1
            << " элемент массива : ";
        int element = 0;
        std::cin >> element;
        arr.push_back(element);
    }
    return arr;
}
