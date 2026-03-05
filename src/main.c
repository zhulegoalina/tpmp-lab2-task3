/*
 * Author: Жулего Алина
 * Group: 10а группа
 *
 * Description:
 * Главный файл программы. Реализует интерфейс с пользователем:
 * - ввод 10 контактов
 * - сортировка по дате рождения
 * - поиск по номеру телефона
 */

#include <stdio.h>
#include <string.h>
#include "contact.h"

#define SIZE 10

int main() {
    CONTACT blocknote[SIZE];
    char search_phone[20];
    
    printf("   Программа 'БЛОКНОТ КОНТАКТОВ'\n");
    printf("   Вариант 37, группа 10а\n");
     
    // 1. Ввод данных
    input_contacts(blocknote, SIZE);
    
    // 2. Вывод введенных данных
    printf("\n Введенные контакты \n");
    for (int i = 0; i < SIZE; i++) {
        print_contact(&blocknote[i]);
    }
    
    // 3. Сортировка по дате рождения
    sort_by_date(blocknote, SIZE);
    
    // 4. Вывод после сортировки
    printf("\n Контакты после сортировки по дате рождения \n");
    for (int i = 0; i < SIZE; i++) {
        print_contact(&blocknote[i]);
    }
    
    // 5. Поиск по номеру телефона
    printf("Введите номер телефона для поиска: ");
    fgets(search_phone, sizeof(search_phone), stdin);
    search_phone[strcspn(search_phone, "\n")] = '\0';
    
    search_by_phone(blocknote, SIZE, search_phone);
    
    printf("\nПрограмма завершена.\n");
    return 0;
}
