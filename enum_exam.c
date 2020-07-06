/* DATE : 2020.07.06 */
/* NAME : BOKDONGJIN */
/* ENUM_EXAM         */
#include<stdio.h>

typedef enum {
	korean1 = 10,
    korean2,
    korean3,
    korean4,
    china1 = 20,
    china2,
    china3,
    china4,
    usa1 = 50,
    usa2,
    usa3,
    usa4
}enum_exam;

void main()
{
    printf("k1 = [%d]", korean1);
    printf("k2 = [%d]", korean2);
    printf("k3 = [%d]", korean3);
    printf("k4 = [%d]", korean4);
    printf("c1 = [%d]", china1);
    printf("c2 = [%d]", china2);
    printf("c3 = [%d]", china3);
    printf("c4 = [%d]", china4);
    printf("u1 = [%d]", usa1);
    printf("u2 = [%d]", usa2);
    printf("u3 = [%d]", usa3);
}