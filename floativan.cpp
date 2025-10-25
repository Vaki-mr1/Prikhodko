#include <iostream>

union FloatBits {
    float f;
    unsigned int i;
};

void printFloatBits(float num) {
    FloatBits fb;
    fb.f = num;
    
    std::cout << "Число: " << num << std::endl;
    std::cout << "Битовое представление: ";
    
    unsigned int mask = 1 << 31;
    for (int i = 0; i < 32; i++) {
        std::cout << ((fb.i & mask) ? '1' : '0');
        if (i == 0 || i == 8) std::cout << " ";
        mask >>= 1;
    }
    
    std::cout << std::endl;
    
    mask = 1 << 31;
    std::cout << "Знак (1 бит): ";
    std::cout << ((fb.i & mask) ? '1' : '0') << " = " << ((fb.i & mask) ? "отрицательный" : "положительный") << std::endl;
    mask >>= 1;
    
    std::cout << "Экспонента (8 бит): ";
    unsigned int exponent = 0;
    for (int i = 0; i < 8; i++) {
        std::cout << ((fb.i & mask) ? '1' : '0');
        exponent = (exponent << 1) | ((fb.i & mask) ? 1 : 0);
        mask >>= 1;
    }
    std::cout << " = " << exponent << " (смещенная)" << std::endl;
    std::cout << "Реальная экспонента: " << (int)(exponent - 127) << std::endl;
    
    std::cout << "Мантисса (23 бита): ";
    unsigned int mantissa = 0;
    for (int i = 0; i < 23; i++) {
        std::cout << ((fb.i & mask) ? '1' : '0');
        mantissa = (mantissa << 1) | ((fb.i & mask) ? 1 : 0);
        mask >>= 1;
    }
    std::cout << " = " << mantissa << std::endl;
    
    float calculated = (exponent == 0) ? 0.0f : 
                     (1.0f + (float)mantissa / (1 << 23)) * std::pow(2.0f, (float)(exponent - 127));
    if (fb.i & (1 << 31)) calculated = -calculated;
    
    std::cout << "Вычисленное значение: " << calculated << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}

void task1() {
    std::cout << "=== ЗАДАНИЕ 1: Двоичное представление float ===" << std::endl;
    std::cout << "Формат IEEE 754: 1 бит знака, 8 бит экспоненты, 23 бита мантиссы" << std::endl;
    std::cout << "Значение = (-1)^знак × (1 + мантисса) × 2^(экспонента-127)" << std::endl << std::endl;
    
    std::cout << "Пример 1: Число 2.5" << std::endl;
    std::cout << "2.5 в двоичной системе: 10.1 = 1.01 × 2^1" << std::endl;
    std::cout << "Знак: 0 (положительное)" << std::endl;
    std::cout << "Экспонента: 1 + 127 = 128 = 10000000" << std::endl;
    std::cout << "Мантисса: 01000000000000000000000 (отбрасываем ведущую 1)" << std::endl;
    printFloatBits(2.5f);
    
    std::cout << "Пример 2: Число 0.375" << std::endl;
    std::cout << "0.375 в двоичной системе: 0.011 = 1.1 × 2^(-2)" << std::endl;
    std::cout << "Знак: 0 (положительное)" << std::endl;
    std::cout << "Экспонента: -2 + 127 = 125 = 01111101" << std::endl;
    std::cout << "Мантисса: 10000000000000000000000 (отбрасываем ведущую 1)" << std::endl;
    printFloatBits(0.375f);
    
    std::cout << "Пример 3: Число -8.125" << std::endl;
    std::cout << "-8.125 в двоичной системе: -1000.001 = -1.000001 × 2^3" << std::endl;
    std::cout << "Знак: 1 (отрицательное)" << std::endl;
    std::cout << "Экспонента: 3 + 127 = 130 = 10000010" << std::endl;
    std::cout << "Мантисса: 00000100000000000000000 (отбрасываем ведущую 1)" << std::endl;
    printFloatBits(-8.125f);
}

void task2() {
    std::cout << "=== ЗАДАНИЕ 2: Поиск чисел с расстоянием 1 ===" << std::endl;
    std::cout << "Ищем первое число, для которого x + 1 == x" << std::endl;
    
    float current = 1.0f;
    float previous = 0.0f;
    float a = 0.0f, b = 0.0f;
    float x0 = 0.0f;
    
    while (true) {
        float next = current + 1.0f;
        if (next == current) {
            a = previous;
            b = current;
            x0 = current;
            break;
        }
        previous = current;
        current = next;
        
        if (current > 1e7) {
            std::cout << "Достигнут предел поиска" << std::endl;
break;
        }
    }
    
    std::cout << "Первые два числа a и b с расстоянием 1:" << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "b - a = " << (b - a) << std::endl;
    
    std::cout << "Число x0, при котором x + 1 == x: " << x0 << std::endl;
    std::cout << "Проверка: " << x0 << " + 1 = " << (x0 + 1.0f) << std::endl;
    std::cout << "Равенство: " << ((x0 + 1.0f) == x0) << std::endl;
    
    std::cout << "Объяснение: При больших значениях экспонента становится настолько большой," << std::endl;
    std::cout << "что мантисса не может представить дробную часть, и прибавление 1" << std::endl;
    std::cout << "не изменяет значение из-за округления." << std::endl;
}

void task3() {
    std::cout << "=== ЗАДАНИЕ 3: Нарушение ассоциативности ===" << std::endl;
    
    float a = 1.0e8f;
    float b = -1.0e8f;
    float c = 1.0f;
    
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl << std::endl;
    
    float res1 = (a + b) + c;
    float res2 = a + (b + c);
    
    std::cout << "(a + b) + c = (" << a << " + " << b << ") + " << c << " = " << (a + b) << " + " << c << " = " << res1 << std::endl;
    std::cout << "a + (b + c) = " << a << " + (" << b << " + " << c << ") = " << a << " + " << (b + c) << " = " << res2 << std::endl;
    std::cout << "Результаты равны: " << (res1 == res2) << std::endl;
    std::cout << "Разница: " << (res1 - res2) << std::endl;
    
    std::cout << "Объяснение: В первом случае (a + b) дает 0, затем + c = 1." << std::endl;
    std::cout << "Во втором случае (b + c) дает -99999999, который при сложении с a" << std::endl;
    std::cout << "округляется до 0 из-за потери точности." << std::endl;
}

void task4() {
    std::cout << "=== ЗАДАНИЕ 4: Сходимость гармонического ряда ===" << std::endl;
    
    float sum = 0.0f;
    int k = 1;
    int stopping_k = 0;
    
    std::cout << "Ищем первый элемент, прибавление которого не увеличивает сумму:" << std::endl;
    
    while (k <= 10000000) {
        float old_sum = sum;
        float term = 1.0f / k;
        sum += term;
        
        if (sum == old_sum) {
            stopping_k = k;
            std::cout << "Найден на k = " << k << std::endl;
            std::cout << "1/k = " << term << std::endl;
            std::cout << "Сумма до добавления: " << old_sum << std::endl;
            std::cout << "Сумма после добавления: " << sum << std::endl;
            break;
        }
        
        k++;
        
        if (k % 1000000 == 0) {
            std::cout << "k = " << k << ", сумма = " << sum << std::endl;
        }
    }
    
    if (stopping_k == 0) {
        std::cout << "Не найден за " << k << " итераций" << std::endl;
    }
    
    std::cout << "Объяснение: Когда 1/k становится меньше половины младшего разряда суммы," << std::endl;
    std::cout << "прибавление этого члена не изменяет значение суммы из-за ограниченной точности float." << std::endl;
}

void task5() {
    std::cout << "=== ЗАДАНИЕ 5: Суммирование гармонического ряда разными способами ===" << std::endl;
    
    float sum_forward = 0.0f;
    int k = 1;
    int stopping_k = 0;
    
    while (true) {
        float old_sum = sum_forward;
        sum_forward += 1.0f / k;
        
        if (sum_forward == old_sum) {
            stopping_k = k;
            break;
        }
        k++;
        if (k > 10000000) break;
    }
    
    std::cout << "Остановочный k: " << stopping_k << std::endl;
    std::cout << "Сумма до остановки: " << sum_forward << std::endl;
    
    float sum_to_end_forward = sum_forward;
    std::cout << "Прямое суммирование от k до k+100:" << std::endl;
    for (int i = 0; i < 100; i++) {
        sum_to_end_forward += 1.0f / (stopping_k + i);
        }
    std::cout << "Результат: " << sum_to_end_forward << std::endl;
    
    float sum_backward = 0.0f;
    std::cout << "Обратное суммирование от k+99 до k:" << std::endl;
    for (int i = 99; i >= 0; i--) {
        sum_backward += 1.0f / (stopping_k + i);
    }
    sum_backward += sum_forward;
    std::cout << "Результат: " << sum_backward << std::endl;
    
    std::cout << "Разница между методами: " << (sum_to_end_forward - sum_backward) << std::endl;
    std::cout << "Результаты равны: " << (sum_to_end_forward == sum_backward) << std::endl;
    
    std::cout << "Объяснение: При обратном суммировании (от меньших чисел к большим)" << std::endl;
    std::cout << "сначала складываются малые числа, которые могут быть учтены в сумме," << std::endl;
    std::cout << "тогда как при прямом суммировании малые числа теряются при сложении" << std::endl;
    std::cout << "с уже большой суммой." << std::endl;
}

void task6() {
    std::cout << "=== ЗАДАНИЕ 6: Сравнение float через == ===" << std::endl;
    
    std::cout << "Пример 1: Накопление ошибки округления" << std::endl;
    float a = 0.1f;
    float b = 0.0f;
    
    for (int i = 0; i < 10; i++) {
        b += 0.1f;
    }
    
    std::cout << "a = 0.1" << std::endl;
    std::cout << "b = 0.1 + 0.1 + ... + 0.1 (10 раз)" << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "Разница: " << (a - b) << std::endl;
    
    std::cout << "Пример 2: Операции с большими и малыми числами" << std::endl;
    float big = 1.0e8f;
    float small = 1.0f;
    float result1 = (big + small) - big;
    float result2 = small;
    
    std::cout << "big = " << big << std::endl;
    std::cout << "small = " << small << std::endl;
    std::cout << "(big + small) - big = " << result1 << std::endl;
    std::cout << "small = " << result2 << std::endl;
    std::cout << "Результаты равны: " << (result1 == result2) << std::endl;
    
    std::cout << "Пример 3: Числа без операций" << std::endl;
    float x = 2.5f;
    float y = 2.5f;
    std::cout << "x = " << x << ", y = " << y << std::endl;
    std::cout << "x == y: " << (x == y) << std::endl;
    
    std::cout << "ВЫВОД:" << std::endl;
    std::cout << "1. Сравнение через == опасно из-за ошибок округления в арифметических операциях" << std::endl;
    std::cout << "2. Для чисел без операций сравнение через == безопасно" << std::endl;
    std::cout << "3. Рекомендуется использовать сравнение с допуском: fabs(a - b) < epsilon" << std::endl;
}

int main() {
    std::cout << "ЛАБОРАТОРНАЯ РАБОТА: ИССЛЕДОВАНИЕ ТИПА FLOAT" << std::endl;
    std::cout << "=============================================" << std::endl;
    
    task1();
    task2();
    task3();
    task4();
    task5();
    task6();
    
    std::cout << "=============================================" << std::endl;
    std::cout << "ВСЕ ЗАДАНИЯ ВЫПОЛНЕНЫ" << std::endl;
    
    return 0;
}