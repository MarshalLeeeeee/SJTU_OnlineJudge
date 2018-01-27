#include <iostream>
#include <cstring>
#define ENLARGE_PROPORTION 2

using namespace std;

template <class T>
class sequential_list
{
    template <class TT> friend ostream &operator<<(ostream &, const sequential_list<TT> &);
    template <class TT> friend istream &operator>>(istream &, sequential_list<TT> &);
    template <class TT> friend sequential_list<TT> operator+(const sequential_list<TT> &, const sequential_list<TT> &);

    private:
        T *ptr;
        int max_len;
        int current_len;
    public:
        sequential_list(int = 10);
        ~sequential_list(void);
        void clear(void);
        int length(void);
        int capacity(void);
        void insert(int, T);
        void remove(int);
        int search(T);
        T &visit(int);
        void resize(void);
        sequential_list<T> &operator=(const sequential_list<T> &);
};
class range_error{};

int main()
{
    char type[10];
    int len1, len2;
    int index;
    cin.getline(type, 10);
    cin >> len1 >> len2;
    if(!strcmp(type, "int"))
    {
        sequential_list<int> arr1(len1);
        sequential_list<int> arr2(len2);
        for(index = 0; index < len1; index++)
            cin >> arr1;
        for(index = 0; index < len2; index++)
            cin >> arr2;
        cout << arr1 + arr2 << endl;
    }
    if(!strcmp(type, "char"))
    {
        sequential_list<char> arr1(len1);
        sequential_list<char> arr2(len2);
        for(index = 0; index < len1; index++)
            cin >> arr1;
        for(index = 0; index < len2; index++)
            cin >> arr2;
        cout << arr1 + arr2 << endl;
    }
    if(!strcmp(type, "double"))
    {
        sequential_list<double> arr1(len1);
        sequential_list<double> arr2(len2);
        for(index = 0; index < len1; index++)
            cin >> arr1;
        for(index = 0; index < len2; index++)
            cin >> arr2;
        cout << arr1 + arr2 << endl;
    }
    return 0;
}
template <class T>
sequential_list<T>::sequential_list(int n):max_len(n)
{
    ptr = new T[max_len];
    current_len = 0;
}
template <class T>
sequential_list<T>::~sequential_list(void)
{
    delete []ptr;
}
template <class T>
void sequential_list<T>::clear(void)
{
    current_len = 0;
}
template <class T>
int sequential_list<T>::length(void)
{
    return current_len;
}
template <class T>
int sequential_list<T>::capacity(void)
{
    return max_len;
}
template <class T>
void sequential_list<T>::insert(int index, T element)
{

    if(index > current_len || index < 0)
    {
        cout << "The index is out of range" << endl;;
    }
    else if(index == current_len)
    {
        *(ptr + current_len++) = element;
    }
    else
    {
        if(current_len == max_len)
        {
            this->resize();
        }
        current_len++;
        int i;
        for(i = current_len - 1; i > index; i--)
        {
            *(ptr + i) = *(ptr + i - 1);
        }
        *(ptr + index) = element;
    }
}
template <class T>
void sequential_list<T>::remove(int index)
{
    if(index >= current_len || index < 0)
    {
        cout << "The index is out of range" << endl;
    }
    else
    {
        current_len--;
        int i;
        for(i = index; i < current_len; i++)
        {
            *(ptr + i) = *(ptr + i + 1);
        }
    }
}
template <class T>
int sequential_list<T>::search(T element)
{
    int i;
    for(i = 0; i < current_len; i++)
    {
        if(ptr[i] == element)
        {
            return i;
        }
    }
    return -1;
}
template <class T>
T &sequential_list<T>::visit(int index)
{
    if(index < 0 || index >= current_len)
    {
        throw range_error();
    }
    else
    {
        return ptr[index];
    }
}
template <class T>
sequential_list<T> &sequential_list<T>::operator=(const sequential_list &ans)
{
    if(this == &ans) return *this;
    max_len = ans.max_len;
    current_len = ans.current_len;
    delete []ptr;
    ptr = new T[max_len];
    int index;
    for(index = 0; index < current_len; index++)
    {
        ptr[index] = ans.ptr[index];
    }
    return *this;
}
template <class T>
void sequential_list<T>::resize(void)
{
    T *ptr_tmp;
    ptr_tmp = new T[ENLARGE_PROPORTION * max_len];
    int index;
    for(index = 0; index < current_len; index++)
    {
        ptr_tmp[index] = ptr[index];
    }
    delete []ptr;
    ptr = ptr_tmp;
    max_len = ENLARGE_PROPORTION * max_len;
}
template <class TT>
istream &operator>>(istream &is, sequential_list<TT> &arr)
{
    if(arr.current_len == arr.max_len) arr.resize();
    is >> *(arr.ptr + arr.current_len++);
    return is;
}
template <class TT>
ostream &operator<<(ostream &os, const sequential_list<TT> &arr)
{
    int index;
    for(index = 0; index < arr.current_len; index++)
    {
        os << arr.ptr[index] << " ";
    }
    return os;
}
template <class TT>
sequential_list<TT> operator+(const sequential_list<TT> &arr1, const sequential_list<TT> &arr2)
{
    sequential_list<TT> ans(arr1.max_len + arr2.max_len);
    ans.current_len = arr1.current_len + arr2.current_len;
    int index;
    for(index = 0; index < ans.current_len; index++)
    {
        if(index < arr1.current_len)
        {
            ans.ptr[index] = arr1.ptr[index];
        }
        else
        {
            ans.ptr[index] = arr2.ptr[index - arr1.current_len];
        }
    }
    return ans;
}





