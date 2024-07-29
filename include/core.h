#ifndef CORE_H
#define CORE_H

void swap(int *lhs, int *rhs)
{
    int temp = *lhs;
    *lhs = *rhs;
    *rhs = temp;
    return;
}

void swap_ptr(void **lhs, void **rhs)
{
    void *temp = *lhs;
    *lhs = *rhs;
    *rhs = temp;
    return;
}

#endif // CORE_H
