/*
 * Author: Жулего Алина
 * Group: 10а группа
 *
 * Description:
 * Реализация функций для работы со структурой CONTACT.
 * Содержит ввод данных, сортировку по дате, поиск по номеру телефона.
 */

#include <stdio.h>
#include <string.h>
#include "contact.h"

// Ввод контактов с клавиатуры
void input_contacts(CONTACT *blocknote, int size) {
    printf("Введите данные о %d контактах:\n", size);
    for (int i = 0; i < size; i++) {
        printf("\nКонтакт #%d:\n", i + 1);
        
        printf("  Фамилия и инициалы: ");
        fgets(blocknote[i].name, sizeof(blocknote[i].name), stdin);
        blocknote[i].name[strcspn(blocknote[i].name, "\n")] = '\0'; // Удаляем символ новой строки
        
        printf("  Номер телефона: ");
        fgets(blocknote[i].phone, sizeof(blocknote[i].phone), stdin);
        blocknote[i].phone[strcspn(blocknote[i].phone, "\n")] = '\0';
        
        printf("  Дата рождения (год месяц число): ");
        scanf("%d %d %d", 
              &blocknote[i].birth.year, 
              &blocknote[i].birth.month, 
              &blocknote[i].birth.day);
        getchar(); // Очищаем буфер после scanf
    }
}

// Сравнение двух дат (для сортировки)
int compare_dates(const Date *d1, const Date *d2) {
    if (d1->year != d2->year) {
        return d1->year - d2->year;
    }
    if (d1->month != d2->month) {
        return d1->month - d2->month;
    }
    return d1->day - d2->day;
}

// Сортировка контактов по возрастанию даты рождения (пузырьковая сортировка)
void sort_by_date(CONTACT *blocknote, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (compare_dates(&blocknote[j].birth, &blocknote[j + 1].birth) > 0) {
                // Меняем местами
                CONTACT temp = blocknote[j];
                blocknote[j] = blocknote[j + 1];
                blocknote[j + 1] = temp;
            }
        }
    }
    printf("\nЗаписи отсортированы по возрастанию даты рождения.\n");
}

// Вывод одного контакта
void print_contact(const CONTACT *c) {
    printf("  %-30s | %-15s | %04d-%02d-%02d\n", 
           c->name, 
           c->phone, 
           c->birth.year, 
           c->birth.month, 
           c->birth.day);
}

// Поиск контакта по номеру телефона
void search_by_phone(CONTACT *blocknote, int size, const char *phone) {
    int found = 0;
    printf("\nРезультат поиска по номеру телефона '%s':\n", phone);
    
    for (int i = 0; i < size; i++) {
        if (strcmp(blocknote[i].phone, phone) == 0) {
            print_contact(&blocknote[i]);
            found = 1;
        }
    }
    
    if (!found) {
        printf("  Человек с таким номером телефона не найден.\n");
    }
}
