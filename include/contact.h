/*
 * Author: Жулего Алина
 * Group: 10а группа
 *
 * Description:
 * Заголовочный файл для структуры CONTACT.
 * Содержит определение структуры и прототипы функций для работы с массивом контактов.
 */

#ifndef CONTACT_H
#define CONTACT_H

// Структура для хранения даты рождения
typedef struct {
    int year;
    int month;
    int day;
} Date;

// Структура CONTACT
typedef struct {
    char name[50];      // Фамилия и инициалы
    char phone[20];     // Номер телефона
    Date birth;         // Дата рождения
} CONTACT;

// Прототипы функций
void input_contacts(CONTACT *blocknote, int size);
void sort_by_date(CONTACT *blocknote, int size);
void search_by_phone(CONTACT *blocknote, int size, const char *phone);
void print_contact(const CONTACT *c);
int compare_dates(const Date *d1, const Date *d2);

#endif
