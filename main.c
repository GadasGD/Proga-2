#include <stdio.h>
#include "IntVector.h"
#include "IntVector.c"

int main()
{
    IntVector* test_vector = int_vector_new(1);

    printf("Содержимое массива №1:");
    int_vector_print(test_vector);

    int_vector_set_item(test_vector, 0, 12);

    printf("Содержимое массива №1:");
    int_vector_print(test_vector);
    printf("Индекс: %d\n", int_vector_get_item(test_vector, 0));
    printf("Размер массива: %d\n", int_vector_get_size(test_vector));
    printf("Ёмкость массива: %d\n\n", int_vector_get_capacity(test_vector));

    int_vector_push_back(test_vector, 11);

    printf("Содержимое массива №1:");
    int_vector_print(test_vector);
    printf("Индекс: %d\n", int_vector_get_item(test_vector, 1));
    printf("Размер массива: %d\n", int_vector_get_size(test_vector));
    printf("Ёмкость массива: %d\n\n", int_vector_get_capacity(test_vector));

    int_vector_push_back(test_vector, 35);

    printf("Содержимое массива №1:");
    int_vector_print(test_vector);
    printf("Размер массива: %d\n", int_vector_get_size(test_vector));
    printf("Индекс: %d\n", int_vector_get_item(test_vector, 1));
    printf("Ёмкость массива: %d\n\n", int_vector_get_capacity(test_vector));


    int_vector_pop_back(test_vector);
    int_vector_shrink_to_fit(test_vector);

    printf("Содержимое массива №1:");
    int_vector_print(test_vector);
    printf("Размер массива: %d\n", int_vector_get_size(test_vector));
    printf("Ёмкость массива: %d\n\n", int_vector_get_capacity(test_vector));

    int_vector_resize(test_vector, 10);

    printf("Содержимое массива №1:");
    int_vector_print(test_vector);
    printf("Размер массива: %d\n", int_vector_get_size(test_vector));
    printf("Ёмкость массива: %d\n\n", int_vector_get_capacity(test_vector));

    int_vector_reserve(test_vector, 15);

    printf("Содержимое массива №1:");
    int_vector_print(test_vector);
    printf("Размер массива: %d\n", int_vector_get_size(test_vector));
    printf("Ёмкость массива: %d\n\n", int_vector_get_capacity(test_vector));

    IntVector *copy = int_vector_copy(test_vector);
    printf("Содержимое массива №1:");
    int_vector_print(test_vector);

    printf("Размер массива: %d\n", int_vector_get_size(test_vector));
    printf("Ёмкость массива: %d\n\n", int_vector_get_capacity(test_vector));

    printf("Содержимое массива №2:");
    int_vector_print(copy);

    int_vector_free(test_vector);
    int_vector_free(copy);
    return 0;
}
