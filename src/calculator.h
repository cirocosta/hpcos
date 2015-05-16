#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator {
private:
    int m_Value;
public:
    Calculator();
    Calculator(int);
    void accumulate(const int);

    inline int getInternalValue() const {
        return m_Value;
    }
};


#endif /* CALCULATOR_H */
