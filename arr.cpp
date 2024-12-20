#include <iostream>
#define cefCap    1.2

#pragma region Hw2
class String {
protected:
    char* _str;
    size_t _size;
    size_t _capacity;
public:
    String() :_str{ nullptr }, _size{ 0 }, _capacity{ 0 } {}

    String(size_t size, size_t capacity) :_size{ size }, _capacity{ capacity }, _str{ new char[_capacity] } {}

    String(const char* str) : _size{ strlen(str) }, _capacity{ size_t(_size * cefCap) + 1 } {
        _str = new char[_capacity];
        for (int i = 0; i < _size + 1; i++) {
            _str[i] = str[i];
        }
    }

    String(const String& str) : _size{ str._size }, _capacity{ str._capacity } {
        _str = new char[_capacity];

        for (size_t i = 0; i < _size + 1; i++) {
            _str[i] = str._str[i];
        }

    }

    ~String()
    {
        delete[] _str; 
        _str      = nullptr;
        _size     = 0;
        _capacity = 0;
    }

    String& operator=(const String& str) {
        
        if (&str == this)
            return *this;

        delete[] _str;
        _str = new char[str._capacity];
        _size = str._size;

        for (size_t i = 0; i < _size+1; i++) {
            _str[i] = str._str[i];
        }

        return *this;
    }

    int Max(int one, int two) {
        return one > two ? one : two;
    }

    int Min(int one, int two) {
        return one < two ? one : two;
    }

    int GetSize() {
        return _size;
    }

    friend std::ostream& operator << (std::ostream& out, const String& str) {
        out << str._str;
        return out;
    }

    void Clear() {
        this->~String();
    }

    String& operator+(const String& str) {
        char* newStr = new char[_capacity + str._capacity];
        for (size_t i = 0; i < _size; i++)
        {
            newStr[i] = _str[i];
        }

        for (size_t i = 0; i < str._size + 1; i++)
        {
            newStr[i + _size] = str._str[i];
        }
        delete[] _str;
        _str = newStr;
        _size += str._size;
        _capacity += str._capacity;
        delete[] newStr;
        return *this;
    }

    friend String& operator+=(String& str1, const String& str2) {
        str1 = str1 + str2;
        return str1;
    }

    friend bool operator ==(const String& str1, const String& str2) {
        if (str1._size != str2._size)
            return false;

        for (size_t i = 0; i < str1._size; i++)
        {
            if (str1._str[i] != str2._str[i]) {
                return false;
            }
        }
        return true;
    }

    friend bool operator !=(const String& str1, const String& str2) {
        return !(str1 == str2);
    }
};

#pragma endregion

#pragma region Hw3
class BinaryString : public String{
public:
    BinaryString() :String(){}

    BinaryString(const char* str) : String(strlen(str), int(_size* cefCap) + 2)
    {

        for (int i = 0; i < _size + 1; i++)
        {
            if (str[i] == '0' || str[i] == '1' || str[i] == '\0')
            {
                _str[i] = str[i];
            }
            else
            {
                this->~BinaryString();
                break;
            }
        }

    }

    BinaryString(const BinaryString& str) : String(str._size, str._capacity)
    {

        for (int i = 0; i < _size + 1; i++)
        {
            if (str._str[i] == '0' || str._str[i] == '1' || str._str[i] == '\0')
            {
                _str[i] = str._str[i];
            }
            else
            {
                this->~BinaryString();
                break;
            }
        }
    }

    ~BinaryString()
    {
        delete[] _str;
        _str = nullptr;
        _size = 0;
        _capacity = 0;
    }

    BinaryString& operator=(const BinaryString& str) 
    {
        if (&str == this)
            return *this;

        delete[] _str;
        _str = new char[str._capacity];
        _size = str._size;

        for (size_t i = 0; i < _size + 1; i++) 
        {
            _str[i] = str._str[i];
        }

        return *this;
    }

    int Max(int one, int two) {
        return one > two ? one : two;
    }

    int Min(int one, int two) {
        return one < two ? one : two;
    }

    int GetSize() 
    {
        return _size;
    }

    friend std::ostream& operator << (std::ostream& out, const BinaryString& str) 
    {
        out << str._str;
        return out;
    }
    
    void Clear() 
    {
        this->~BinaryString();
    }
    
    BinaryString& operator+(const BinaryString& str) 
    {
        //"1001" + "1110"

        int maxSize = Max(_size, str._size);
        
        
        
        char* newStr = new char[maxSize];

        return *this;
    }

    friend BinaryString& operator+=(BinaryString& str1, const BinaryString& str2) 
    {
        str1 = str1 + str2;

        return str1;
    }

    static char* Tyag(const char* str, int normalSize)
    {
        char* newStr = new char[normalSize + 1];

        int size = strlen(str);

        for (size_t i = 0; i < normalSize; i++)
        {
            if (i < size)
            {
                newStr[i] = str[0];
            }
            else
            {
                newStr[i] = str[i - size - 1];
            }
        }

        newStr[normalSize] = '\0';

        return newStr;
    }
};

#pragma endregion

int main()
{
   

    std::cout << BinaryString::Tyag("011", 3, 5) << std::endl;
}
