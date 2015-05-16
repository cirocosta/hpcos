#include <iostream>
#include "calculator.h"

using std::cout;
using std::endl;

int main() {
    Calculator a (10);
    a.accumulate(20);

    cout << a.getInternalValue() << endl;

    return 0;
}
