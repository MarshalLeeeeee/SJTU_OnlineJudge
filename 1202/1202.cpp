#include <iostream>

using namespace std;
struct Digit
{
    int digit;
    Digit *rear;
    Digit *prev;
};
class bigInt
{
    friend const bigInt operator+(const bigInt &, const bigInt &);
    friend istream &operator>>(istream &, bigInt &);
    friend ostream &operator<<(ostream &, const bigInt &);

    private:
        Digit *head;
        Digit *tail;
        long len;

    public:
        bigInt(void);
        ~bigInt(void);
        void delete_zero(void);
        bigInt &operator=(const bigInt &);
};

long max_of_two(const long, const long);
long min_of_two(const long, const long);

int main()
{
    bigInt x, y, z;
    cin >> x;
    cin >> y;
    z = x+y;
    cout << z << endl;
    return 0;
}
long max_of_two(const long a, const long b)
{
    return a > b ? a : b;
}
long min_of_two(const long a, const long b)
{
    return a < b ? a : b;
}
bigInt::bigInt(void)
{
    head = NULL;
    tail = NULL;
    len = 0;
}
bigInt::~bigInt(void)
{
    Digit *ptr, *rcd;
    ptr = head;
    while(ptr)
    {
        rcd = ptr -> rear;
        delete ptr;
        ptr = rcd;
    }
}
void bigInt::delete_zero(void)
{
    Digit *tmp;
    while(tail->digit == 0)
    {
        if(len == 1) break;
        tmp = tail->prev;
        delete tail;
        tail = tmp;
        len--;
    }
}
istream &operator>>(istream &is, bigInt &x)
{
    char ch;
    Digit *ptr;
    while((ch = is.get()) != '\n')
    {
        ptr = new Digit;
        ptr->digit = ch - '0' + 0;
        ptr->prev = NULL;
        ptr->rear = x.head;
        if(!x.len)
        {
            x.head = ptr;
            x.tail = ptr;
        }
        else
        {
            x.head->prev = ptr;
            x.head = ptr;
        }
        x.len++;
    }
    x.delete_zero();
}
ostream &operator<<(ostream &os, const bigInt &x)
{
    if(!x.len) os << "NAN";
    else
    {
        Digit *ptr = x.tail;
        while(ptr)
        {
            os << ptr->digit;
            ptr = ptr->prev;
        }
    }
    return os;
}
const bigInt operator+(const bigInt &a, const bigInt &b)
{
    bigInt ans;
    Digit *ptra, *ptrb, *ptrans;
    long index;
    int add_flag = 0;
    ptra = a.head; ptrb = b.head;
    for(index = 0; index < max_of_two(a.len, b.len); index++)
    {
        if(index < min_of_two(a.len, b.len))
        {
            ptrans = new Digit;
            ptrans->digit = ptra->digit + ptrb->digit + add_flag;
            ptrans->prev = ans.tail;
            ptrans->rear = NULL;
            ans.len++;
            if(ptrans->digit > 9)
            {
                ptrans->digit %= 10;
                add_flag = 1;
            }
            else
            {
                add_flag = 0;
            }
            if(index == 0)
            {
                ans.head = ptrans;
                ans.tail = ptrans;
            }
            else
            {
                ans.tail->rear = ptrans;
                ans.tail = ptrans;
            }
            ptra = ptra->rear;
            ptrb = ptrb->rear;
        }
        else
        {
            if(a.len > b.len)
            {
                ptrans = new Digit;
                ptrans->digit = ptra->digit + add_flag;
                ptrans->prev = ans.tail;
                ptrans->rear = NULL;
                ans.len++;
                if(ptrans->digit > 9)
                {
                    ptrans->digit %= 10;
                    add_flag = 1;
                }
                else
                {
                    add_flag = 0;
                }
                ans.tail->rear = ptrans;
                ans.tail = ptrans;
                ptra = ptra->rear;
            }
            else
            {
                ptrans = new Digit;
                ptrans->digit = ptrb->digit + add_flag;
                ptrans->prev = ans.tail;
                ptrans->rear = NULL;
                ans.len++;
                if(ptrans->digit > 9)
                {
                    ptrans->digit %= 10;
                    add_flag = 1;
                }
                else
                {
                    add_flag = 0;
                }
                ans.tail->rear = ptrans;
                ans.tail = ptrans;
                ptrb = ptrb->rear;
            }
        }
    }
    if(add_flag)
    {
        ptrans = new Digit;
        ptrans->digit = 1;
        ptrans->prev = ans.tail;
        ptrans->rear = NULL;
        ans.len++;
        ans.tail->rear = ptrans;
        ans.tail = ptrans;
    }
    return ans;
}
bigInt &bigInt::operator=(const bigInt &x)
{
    if(this->head == x.head && this->tail == x.tail && this->len == x.len) return *this;
    Digit *ptr, *rcd;
    ptr = head;
    while(ptr)
    {
        rcd = ptr -> rear;
        delete ptr;
        ptr = rcd;
    }
    len = x.len;
    head = NULL;
    tail = NULL;
    ptr = x.head;
    while(ptr)
    {
        rcd = new Digit;
        rcd->digit = ptr->digit;
        rcd->prev = tail;
        rcd->rear = NULL;
        if(ptr->prev == NULL)
        {
            head = rcd;
            tail = rcd;
        }
        else
        {
            tail->rear = rcd;
            tail = rcd;
        }
        ptr = ptr->rear;
    }
    return *this;
}
