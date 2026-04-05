#include <stdio.h>
#include <string.h>

struct StructData {
    char  c;    // 1바이트
    int   n;    // 4바이트
};
int EqualData(const struct StructData* ptr1, const struct StructData* ptr2);

int main(void)
{
    struct StructData a1 = {'A', 0x1234};
    struct StructData a2 = {'A', 0x1234};

    int resunt = EqualData(&a1, &a2);

    return 0;
}

int EqualData(const struct StructData* ptr1, const struct StructData* ptr2)
{
    // padding이 존재하기 때문에 memcmp로 비교하면 안됨.
    // return (0 == memcmp(ptr1, ptr2, sizeof(struct PaddingCN)));
    return (ptr1->c == ptr2->c && ptr1->n == ptr2->n);
}
