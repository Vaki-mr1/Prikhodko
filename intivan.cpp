
#include <iostream>

int main() {
    std::cout << "=== Задание 1: Побитовое представление int ===" << std::endl;
    
    int positive_int = 42;
    int negative_int = -42;
    int large_positive = 255;
    int large_negative = -255;
    
    std::cout << "Положительные числа:" << std::endl;
    std::cout << positive_int << " = ";
    for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
        std::cout << ((positive_int >> i) & 1);
        if (i % 4 == 0) std::cout << " ";
    }
    std::cout << std::endl;
    
    std::cout << large_positive << " = ";
    for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
        std::cout << ((large_positive >> i) & 1);
        if (i % 4 == 0) std::cout << " ";
    }
    std::cout << std::endl;
    
    std::cout << "\nОтрицательные числа:" << std::endl;
    std::cout << negative_int << " = ";
    for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
        std::cout << ((negative_int >> i) & 1);
        if (i % 4 == 0) std::cout << " ";
    }
    std::cout << std::endl;
    
    std::cout << large_negative << " = ";
    for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
        std::cout << ((large_negative >> i) & 1);
        if (i % 4 == 0) std::cout << " ";
    }
    std::cout << std::endl;
    
    std::cout << "\n=== Задание 2: Побитовое представление unsigned int ===" << std::endl;
    
    unsigned int positive_uint = 42;
    unsigned int large_uint = 255;
    unsigned int half_range = 2147483647;
    
    std::cout << "unsigned int " << positive_uint << " = ";
    for (int i = sizeof(unsigned int) * 8 - 1; i >= 0; i--) {
        std::cout << ((positive_uint >> i) & 1);
        if (i % 4 == 0) std::cout << " ";
    }
    std::cout << std::endl;
    
    std::cout << "int " << positive_int << " = ";
    for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
        std::cout << ((positive_int >> i) & 1);
        if (i % 4 == 0) std::cout << " ";
    }
    std::cout << std::endl;
    
    std::cout << "\nunsigned int " << large_uint << " = ";
    for (int i = sizeof(unsigned int) * 8 - 1; i >= 0; i--) {
        std::cout << ((large_uint >> i) & 1);
        if (i % 4 == 0) std::cout << " ";
    }
    std::cout << std::endl;
    
    std::cout << "int " << large_positive << " = ";
    for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
        std::cout << ((large_positive >> i) & 1);
        if (i % 4 == 0) std::cout << " ";
    }
    std::cout << std::endl;
    
    std::cout << "\nПроверка 'сдвига' на половину диапазона:" << std::endl;
    std::cout << "unsigned int " << half_range << " = ";
    for (int i = sizeof(unsigned int) * 8 - 1; i >= 0; i--) {
        std::cout << ((half_range >> i) & 1);
        if (i % 4 == 0) std::cout << " ";
    }
    std::cout << std::endl;
    
    std::cout << "int " << half_range << " = ";
    for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
        std::cout << ((half_range >> i) & 1);
        if (i % 4 == 0) std::cout << " ";
    }
    std::cout << std::endl;
    
    std::cout << "\n=== Задание 3: Эксперименты с переполнением ===" << std::endl;
    
    int int_max = 2147483647;
    std::cout << "INT_MAX = " << int_max << std::endl;
    std::cout << "Бинарное представление INT_MAX: ";
    for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
        std::cout << ((int_max >> i) & 1);
        if (i % 4 == 0) std::cout << " ";
    }
    std::cout << std::endl;
    
    int overflow_result = int_max + 1;
    std::cout << "INT_MAX + 1 = " << overflow_result << std::endl;
    std::cout << "Бинарное представление INT_MAX + 1: ";
    for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
        std::cout << ((overflow_result >> i) & 1);
        if (i % 4 == 0) std::cout << " ";
    }
    std::cout << std::endl;
    
    std::cout << "\nЭксперимент с unsigned int:" << std::endl;
    unsigned int zero = 0;
    std::cout << "0 (unsigned) = " << zero << std::endl;
    std::cout << "Бинарное представление 0: ";
    for (int i = sizeof(unsigned int) * 8 - 1; i >= 0; i--) {
        std::cout << ((zero >> i) & 1);
        if (i % 4 == 0) std::cout << " ";
    }
    std::cout << std::endl;
    
    unsigned int underflow_result = zero - 1;
    std::cout << "0 - 1 (unsigned) = " << underflow_result << std::endl;
    std::cout << "Бинарное представление 0 - 1: ";
    for (int i = sizeof(unsigned int) * 8 - 1; i >= 0; i--) {
        std::cout << ((underflow_result >> i) & 1);
        if (i % 4 == 0) std::cout << " ";
    }
    std::cout << std::endl;
    
    return 0;
}