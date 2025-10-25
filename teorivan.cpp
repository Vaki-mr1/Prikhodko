#include <iostream>

int main() {
    std::cout << "=== Теоретические оценки ===" << std::endl;
    
    std::cout << "Для float (32 бита):" << std::endl;
    std::cout << "- Размер мантиссы: 23 бита" << std::endl;
    std::cout << "- Размер экспоненты: 8 бит" << std::endl;
    std::cout << "- Смещение экспоненты: 127" << std::endl;
    
    std::cout << "\nТеоретический расчет x0:" << std::endl;
    std::cout << "Мантисса: 23 бита → 2^23 ≈ 8.388.608" << std::endl;
    std::cout << "Когда экспонента достигает 23, расстояние между числами = 1" << std::endl;
    std::cout << "x0 = 2^23 = " << (1 << 23) << std::endl;
    
    std::cout << "\nТеоретический расчет для гармонического ряда:" << std::endl;
    std::cout << "Сумма перестает расти когда 1/k < epsilon * S" << std::endl;
    std::cout << "Машинный эпсилон для float: 1.19e-7" << std::endl;
    std::cout << "При k ≈ 1/epsilon = " << 1/1.19e-7f << std::endl;
    
    std::cout << "\nРасстояние между соседними float:" << std::endl;
    std::cout << "При x = 2^23: расстояние = 2^(e-23) = 2^(23-23) = 1" << std::endl;
    std::cout << "Первые числа с расстоянием 1: около 2^23" << std::endl;
    
    float epsilon = 1.0f;
    while (1.0f + epsilon != 1.0f) {
        epsilon /= 2.0f;
    }
    epsilon *= 2.0f;
    
    std::cout << "\nЭкспериментально найденные значения:" << std::endl;
    std::cout << "Машинный эпсилон: " << epsilon << std::endl;
    
    float x0_theory = 1.0f;
    int exponent = 0;
    while (x0_theory + 1.0f != x0_theory) {
        x0_theory *= 2.0f;
        exponent++;
    }
    x0_theory /= 2.0f;
    exponent--;
    
    std::cout << "Теоретический x0: 2^" << exponent << " = " << x0_theory << std::endl;
    
    return 0;
}