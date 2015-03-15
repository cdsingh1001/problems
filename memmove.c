/* Write a function to implement memmove() */

#include "stdio.h"
#include "malloc.h"
#include "string.h"


void* cd_memset(void *s, int c, size_t n)
{
    void *ptr;

    ptr = s;

    while (n) {
        *((char*)s) = (char)c;
        s = ((char*)s+1);
        n--;
    }

    return ptr;
}


/* str1 = destination
 * str2 = source
 * n = number of bytes to be copied
 *
 * returns the pointer to destination
 *
 * */
void* cd_memmove(void *str1, const void *str2, size_t n)
{
    void *ptr;
    int i = 0;

    ptr = str1;
    printf("str1 %p str2 %p n %ld\n", (char*)str1, (char*)str2, n);

    /* If n is not more than 0, return */
    if (!(n>0)) {
        return ptr;
    }

    if (str1-str2 < n) {
        /* Copy backwards */
        while (n) {
            *((char*)str1+n-1) = *((char*)str2+n-1);
            n--;
        }
    } else {
        /* Copy forward */
        while (i < n) {
            *((char*)str1+i) = *((char*)str2+i);
            i++;
        }
    }

    return ptr;
}

void print_mem(void* s, size_t n)
{
    while (n) {
        printf("%x",*(char*)s);
        s = ((char*)s+1);
        n--;
    }
    printf("\n");
}

void init_region (void* region)
{
    cd_memset(region,0x0,22);
    return;
    char *src;
    char *dest;

    dest = region;
    src = region + 11;
    cd_memset(src,0xf,11);
    cd_memset(dest,0xa,11);
}

void print_region(void* region)
{
    printf("Region: %p ", region);
    print_mem(region,22);
}

int main()
{
    char *src;
    char *dest;
    char *region;
    char *cd_region;

    region = (char*) malloc(22);
    if (!region) {
        return -1;
    }

    init_region(region);
    print_region(region);

    src = region;
    dest = region;
    printf("Calling memmove\n");
    memmove((void*)dest, (void*)src, 10);
    print_region(region);

    cd_region = (char*) malloc(22);
    if (!cd_region) {
        return -1;
    }

    init_region(cd_region);
    print_region(cd_region);

    src = cd_region;
    dest = cd_region;
    printf("Calling CD memmove\n");
    cd_memmove((void*)dest, (void*)src, 10);
    print_region(cd_region);

    if (memcmp(region,cd_region,22) == 0) {
        printf("Results are equal\n");
    } else {
        printf("Results are not equal\n");
    }

    return 0;
}
