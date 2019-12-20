
#include <iostream>
using namespace std;

template <typename T>
class Singleton {
private:
    static T *member;

    Singleton();
    Singleton(const T&);
    T& operator=(const T&);

public:
    static T* getInstance() {
        if (member == NULL) {
            member = new T();
        }
        return member;
    }
};

template<typename T>
T* Singleton<T>::member = NULL;


int main() {
    int *elem = Singleton<int>::getInstance();

    *elem = 100;

    cout << *elem << endl;

    cout << *(Singleton<int>::getInstance()) << endl;
    cout << *(Singleton<double>::getInstance()) << endl;

    return 0;
}



