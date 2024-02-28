#include <stddef.h>
#include <stdlib.h>
#include "IntVector.h"

IntVector *int_vector_new(size_t initial_capacity) // Создает массив нулевого размера.
{
    IntVector *struc = (IntVector *)malloc(sizeof(IntVector)); // Динамическое выделяет память
    if (!struc)
    {
        return NULL;
    }
    struc->data = (int *)malloc(initial_capacity * sizeof(int));
    struc->capacity = initial_capacity;
    struc->size = 0;
    if (!struc->data)
    {
        free(struc);
        return NULL;
    }
    return struc;
}

void int_vector_free(IntVector *v) // Освобождает память, выделенную под вектор
{
    free(v->data);
    free(v);
}

int int_vector_get_item(const IntVector *v, size_t index) // Выводит элемент под номером index
{
    return v->data[index];
}

void int_vector_set_item(IntVector *v, size_t index, int item) // Присваивает элементу под номером index значение item
{
    v->data[index] = item;
}

int int_vector_get_size(const IntVector *v) // Возвращает размер вектора
{
    return v->size;
}

int int_vector_get_capacity(const IntVector *v) // Возвращает ёмкость вектора
{
    return v->capacity;
}

int int_vector_push_back(IntVector *v, int item) // Добавляет элемент в конец массива
{
    if (v->size < v->capacity) // Если размер меньше ёмкости добавление элемента в конце массива
    {
        v->size++;
        v->data[v->size] = item;
    }
    else // Иначе ёмкость увеличивается в 2 раза
    {
        v->capacity *= 2;
        int *t = (int *)realloc(v->data, (size_t)v->capacity * sizeof(int));
        if (t == NULL) // Если произошла ошибка возвращает значение -1. 0 в случае успеха
        {
            return -1;
        }
        v->data = t;
        v->data[v->size] = item;
        v->size++;
    }
    return 0;
}

void int_vector_pop_back(IntVector *v) // Удаляет последний элемент из массива
{
    if (v->size != 0)
        v->size--;
}

int int_vector_shrink_to_fit(IntVector *v) // Уменьшает емкость массива до его размера
{
    if (v->size < v->capacity)
    {
        v->capacity = v->size;
        int *t = (int *)realloc(v->data, v->size * sizeof(int));
        if (t == NULL)
            return -1;
        v->data = t;
        return 0;
    }
    return -1;
}

int int_vector_resize(IntVector *v, size_t new_size) // Изменяет размер массива
{
    if (new_size == v->size)
    {
        return 0;
    }
    if (new_size > v->size)
    {
        int *t = (int *)realloc(v->data, new_size * sizeof(int));
        if (t == NULL)
            return -1;
        v->data = t;
        for (size_t i = new_size - v->size; i < new_size; i++)
            v->data[i] = 0;
    }
    v->size = new_size;
    v->capacity = new_size;
    return 0;
}

int int_vector_reserve(IntVector *v, size_t new_capacity) // Изменяет емкость массива
{
    if (new_capacity > v->capacity)
    {
        v->capacity = new_capacity;
        int *t = (int *)realloc(v->data, new_capacity * sizeof(int));
        if (t == NULL)
            return -1;
        v->data = t;
        return 0;
    }
    return -1;
}

IntVector *int_vector_copy(const IntVector *v) // Копирует вектор
{   
    IntVector *v_copy = int_vector_new(v->capacity);;
    if (v_copy == NULL) // проверяем, успешно ли создана копия
    { 
        return NULL;
    }
    v_copy->size = v->size;
    for (size_t i = 0; i < v->size; i++)
    {
        v_copy->data[i] = v->data[i];
    }
    return v_copy;
}

void int_vector_print(IntVector *v, size_t size)
{   
    printf("[");
    for (int i = 0; i < size; i++)
    {   
        if (i != size - 1)
        {
            printf("%3d |", int_vector_get_item(v, i));
        }
        else
        {
            printf("%3d ", int_vector_get_item(v, i));
        }
    }
    printf("]\n");
}

