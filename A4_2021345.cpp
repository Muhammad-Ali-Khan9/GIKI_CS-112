#include <iostream>

using namespace std;

class CMYstring
{
    private:
    int size;//size of dynamic array
    char *c;//dynamic array pointer

    public:
    CMYstring()//default constructor
    {
        size = 50;//default size is 50 bytes
        c = new char[size+1];//creating dynamic array  (extra space for '\0')
        c[size] = '\0'; //added to end to make a string like in default data type
    }

    CMYstring(string s)// Constructor for a character array (NOTE: A string is used here to bypass all the unneccesary pointer and size of a character array so user may only send a single character array e.g(a("ABCDEFG")) )  
    {
        char *b=&s[0];//string addres of first element

        int num = 0;//variable for size

        while (*b != '\0')//calculating size
        {
            b++;
            num++;
        }

        b=b-num;//resetting the pointer to the first position

        size = num;//setting size of class
        
        c = new char[size+1];//creating a dynamic array

        for(int i=0;i<size;i++)//copyning all elements to the array
        {
            c[i]=*b;
            b++;
        }
        c[size]='\0';//adding '\0' to the end like a default string

    }

    CMYstring(int s)//constructor for a character array with specified size;
    {
        size = s;//updating size
        c = new char[s+1];//creating dynamic array (extra space for '\0')
        c[s] = '\0';//adding '\0' to end
    }

    ~CMYstring()//detructor 
    {
        delete[] c;
    }

    int size_char_array()//function to get size of whole array
    {
        return size;
    }

    int size_string()//function to get size of only the characters entered leaving empty slots
    {
        char *p = &c[0];//storing address of first member
        int num = 0;//variable for size

        for (int j = 0; j < size; j++)//calculating size
        {
            for (int i = 33; i < 127; i++)//using ASCII values(33-127) and type-casting to find if slot has a value
            {
                if (*p == (char)i)
                {
                    num++;
                }
            }
            p++;
        }

        return num;
    }
    
    CMYstring operator + (const CMYstring &a)
    {   
        CMYstring temp(size + a.size);//creating a new instance
        
        for(int i=0;i<size;i++)//copying elements of first array
        {
            temp.c[i]=this->c[i];
        }

        for(int j=0; j<a.size;j++)//copying elemenst of second array
        {
            temp.c[size+j]=a.c[j];
        }

        return temp;//returining the created instance
    }

    void operator += (const CMYstring &a)
    {
        char *temp = new char[size+a.size];//creating a new array

        for(int i=0;i<size;i++)//copying the original elements
        {
            temp[i]=c[i];
        }

        for(int i=0;i<a.size;i++)//copying the other arrays elements
        {
            temp[size+i]=a.c[i];
        }
        
        delete []c;//deleting original array

        c=temp;//pointing to a new array pointer

        temp=NULL;
    }

    char & operator [] (int index)
    {
        return c[index];//returning address of value as well
    }

    bool operator == (CMYstring &a)
    {
        char *p = &a.c[0];//storing address of first element of argument array 
        char *q = &c[0];//storing address of second element of this->array

        while (*p != '\0' || *q != '\0')//checking both arrays
        {
            if (*p != *q)//if a single element of both arrays don't match return false
                return false;
            
            p++;
            q++;
        }

        return true;//otherwise return true 
    }

    bool operator != (CMYstring &a)
    {
        char *p = &a.c[0];//storing address of first element of argument array
        char *q = &c[0];//storing address of second element of this->array


        while (*p != '\0' || *q != '\0')//checking both arrays
        {
            if (*p != *q)
                return true;//if a single element of both arrays don't match return true
            
            p++;
            q++;
        }

        return false;//otherwise return false
    }

    bool operator < (CMYstring &a)
    {
        char *p = &a.c[0];//storing address of first element of argument array
        char *q = &c[0];//storing address of second element of this->array
        int num = 0;

        while (*p != '\0' && *q != '\0')//checking both arrays
        {
            if (*p < *q)
                num++;

            else
                num--;

            p++;
            q++;    
        }

        if (num > 0)
            return false;

        else 
            return true;
    }

    bool operator > (CMYstring &a)
    {
        char *p = &a.c[0];//storing address of first element of argument array
        char *q = &c[0];//storing address of second element of this->array
        int num = 0;

        while (*p != '\0' && *q != '\0')//checking both arrays
        {
            if (*p > *q)
                num++;

            else
                num--;

            p++;
            q++;
        }

        if (num > 0)
            return true;

        else 
            return false;
    }

    CMYstring operator () (int f_pos, int l_pos)
    {
        int sz = l_pos - f_pos+1;//calculating size of the resultant array
        CMYstring temp(sz);//creating the resultant array

        for (int i = 0; i < sz; i++)//copying elements from main to resultant array
            temp.c[i] = this->c[f_pos + i];

        temp.c[sz]='\0'; //adding '\0' at th end

        return temp;
    }

    friend ostream & operator << (ostream &out, const CMYstring &a)
    {
        out << a.c;
        return out;
    }

    friend istream & operator >> (istream &in, CMYstring &a)
    {
        cout << "Enter " << a.size << " Elements: ";
        in >> a.c;
        return in;
    }

    CMYstring & operator = (const CMYstring &a)
    {
        if(a.size==size)
        {  
            size=a.size;
            for(int i=0;i<a.size;i++)
            {
                c[i]=a.c[i];
            }   
            c[size]='\0';

            return *this;
        }
        else
        {  
            size=a.size;

            delete [] c;

            c = new char[a.size+1];

            for(int i=0;i<a.size;i++)
            {
                c[i]=a.c[i];
            } 

                c[a.size]='\0';

                return *this;
        }
    }

    CMYstring operator << (int num)
    {
        CMYstring temp(num);
        for(int i = 0; i < num; i++)
            temp.c[i] = this->c[i];

        int sz2 = size - num;

        this->size = sz2;

        char *nArr = new char[sz2+1];

        for(int i = 0; i < sz2; i++)
            nArr[i] = this->c[num + i];

        nArr[sz2]='\0';

        delete []c;

        c = nArr;

        nArr = NULL;

        return temp;
    }

    CMYstring operator >> (int num)
    {
        CMYstring temp(num);

        for(int i=0;i<num;i++)
            temp.c[i]=this->c[size-1-i];

        int sz=size-num;

        char *nArr= new char[sz];

        nArr[sz]='\0';

        for(int i=0;i<sz;i++)
            nArr[i]=c[i];

            delete []c;
            c=nArr;
            nArr=NULL;

            return temp;
    }

};

int main()
{
    CMYstring b("1234567");
    CMYstring a("ABCDEFG");

    CMYstring s("a");
    CMYstring s1("b");




    // b=a;            // = operator checked and working
    // cout<<b<<endl<<a;

    //a[3]='5';      // [] overloaded check and complete (fully working)
    //cout<<a;

    //s=a+b;         // + operator checked and working 
    //cout<<a+b;

    /*if(b==a)       // == operator checked and worikng
    {
        cout<<"true";
    }
    else 
        cout<<"false";*/

    /*if(a!=b)     // != operator checked and worikng
    {
        cout<<"true";
    }
    else 
        cout<<"false";*/

    /*if(s<s1)     // < operator checked and worikng
    {
        cout<<"true";
    }
    else 
        cout<<"false";*/

    /*if(a>b)     // > operator checked and worikng
    {
        cout<<"true";
    }
    else 
        cout<<"false";*/

    /*s=a(2,5); // () operator checked and working
    cout<<s; */    

    //s=(b>>2); // >>(left shift) operator checked and working  
    //cout<<s<<endl<<b;   
     
    //s=(b<<4);   // <<(right shift) operator checked and working
    //cout<<s<<endl<<b;

    /*a+=b;     // += operator checked and working
    cout<<a;*/
                
    //cout<<"Enter a string ";
    //cin>>s;     // >>(insertion) operator checked and working
    //cout<<s;

    /*cout<<"Character array size: "<<s.size_char_array()<<endl;
    cout<<"String size: "<<s.size_string()<<endl;*/ 
               //both size functions checked and working

    return 0;
}