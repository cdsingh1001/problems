#include "stdio.h"
#include "stdbool.h"

/* Write a function to determine
 * endianess of the machine.
 *
 * Least Significant Byte on lowest address - Little Endian
 * Most Significant Byte on lowest address - Big Endian
 *
 * returns 0 if little endian
 * returns 1 if big endian
 *
 * */
bool find_endianess()
{
    int a = 1;
    char *p;

    p = (char*)&a;

    if (*p == 1) {
        return 0;
    } else {
        return 1;
    }
}

void store_bytes(int *data)
{
    int i = 0;

    for (i=0; i<sizeof(*data); i++) {
        *((char*)data + i) = 0x1+i;
    }
}

void print_bytes(int data)
{
    size_t size = sizeof(data);
    char* ptr = (char*)&data;
    int i = 0;

    for (i=0; i<size; i++) {
        printf("%d ",*(ptr+i));
    }
    printf("\n");
}

/* Convert Network to Host order
 * Network order is always Big endian.
 * */
int cd_ntohl(int data)
{
    int temp = 0;
    char *ptr;
    char *ptr1;
    bool endian = find_endianess();
    if (endian) {
        return data;
    }

    temp = ((data >> 24) |
        ((data >> 8) & 0xff00) |
        ((data << 8) & 0xff0000) |
        ((data << 24)));

    print_bytes(temp);
    printf("Number %d\n", temp);

    temp = 0;

#if 1
    ptr = (char*)&temp;
    ptr1 = (char*)&data;

    *ptr = *(ptr1+3);
    *(ptr+1) = *(ptr1+2);
    *(ptr+2) = *(ptr1+1);
    *(ptr+3) = *(ptr1+0);
#endif

    print_bytes(temp);
    printf("Number %d\n", temp);
    return temp;
}


int main()
{
    int number;
    store_bytes(&number);
    print_bytes(number);
    printf("Number %d\n", number);

    number = cd_ntohl(number);
    //print_bytes(number);
    //printf("Number %d\n", number);


    return 0;

}
