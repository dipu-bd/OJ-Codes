/*==================================
Author : Sudipto Chandra (Dipu)
Email  : dipu.sudipta@gmail.com
University : SUST
===================================*/

#include <stdio.h>
int res[] = 
{
    1,2,3,1,2,3,4,2,1,2,3,3,2,3,4,1,2,2,3,2,3,3,4,3,1,2,3,4,2,3,4,2,3,2,3,1,2,3,4,2,2,3,3,3,2,3,4,3,1,2,3,2,2,3,4,3,3,2,3,4,2,3,4,1,2,3,3,2,3,3,4,2,2,2,3,3,3,3,4,2,1,2,3,3,2,3,4,3,2,2,3,4,3,3,4,3,2,2,3,1,2,3,4,2,3,2,3,3,2,3,4,4,2,3,3,2,2,3,4,3,1,2,3,4,2,3,4,2,3,2,3,3,3,3,4,2,2,3,3,3,3,3,4,1,2,2,3,2,2,3,4,3,2,3,3,4,2,3,4,2,3,2,3,2,3,3,4,3,1,2,3,3,2,3,4,3,3,2,3,2,2,3,4,3,2,3,3,4,3,3,4,3,2,2,3,1,2,3,4,2,3,2,3,3,2,3,4,2,3,3,3,2,3,3,4,3,3,2,3,4,2,3,4,3,1,2,3,3,2,3,4,2,2,2,3,3,3,3,4,4,2,2,3,2,2,3,4,3,3,2,3,4,3,3,4,1,2,3,3,2,2,3,4,3,2,3,3,3,2,3,4,2,3,2,3,3,2,3,4,3,2,3,3,4,3,3,4,2,1,2,3,2,2,3,4,2,3,2,3,3,3,3,4,3,2,2,3,3,3,3,4,3,2,2,3,4,2,3,4,2,3,3,3,1,2,3,4,2,3,3,3,3,2,3,4,3,2,2,3,2,3,3,4,3,3,2,3,4,2,3,4,3,2,3,3,2,3,3,4,2,1,2,3,3,2,3,4,4,2,2,3,3,2,3,4,3,2,3,3,4,3,3,4,3,3,2,3,2,2,3,4,2,3,2,3,3,2,3,4,1,2,3,3,2,2,3,4,3,2,2,3,4,3,3,4,2,3,3,3,3,2,3,4,2,2,3,3,3,3,3,4,3,2,3,3,2,3,3,4,3,1,2,3,4,2,3,4,4,2,2,3,2,3,3,4,3,2,2,3,3,2,3,4,2,3,2,3,2,3,3,4,3,3,3,3,4,2,3,4,3,2,2,3,1,2,3,4,2,3,2,3,3,2,3,4,4,3,3,3,2,
    3,3,4,3,2,3,3,4,2,3,4,2,3,2,3,3,3,3,4,2,2,2,3,3,3,3,4,3,1,2,3,3,2,3,4,3,3,2,3,4,2,3,4,2,2,3,3,2,2,3,4,3,3,2,3,3,2,3,4,3,3,2,3,3,2,3,4,3,2,3,3,4,3,3,4,1,2,2,3,2,3,3,4,2,2,2,3,3,3,3,4,2,2,3,3,2,3,3,4,3,2,3,3,4,2,3,4,3,3,2,3,2,2,3,4,3,2,3,3,3,3,3,4,4,1,2,3,2,2,3,4,3,3,2,3,4,2,3,4,2,2,3,3,3,3,3,4,2,3,2,3,3,2,3,4,2,2,3,3,3,2,3,4,3,3,2,3,4,3,3,4,3,2,2,3,1,2,3,4,2,3,3,3,3,2,3,4,3,2,3,3,2,3,3,4,3,2,2,3,4,2,3,4,3,3,2,3,3,2,3,4,2,3,3,3,3,3,3,4,2,3,2,3,2,2,3,4,3,1,2,3,4,2,3,4,3,3,2,3,2,3,3,4,3,2,2,3,3,3,3,4,4,3,2,3,3,2,3,4,3,2,3,3,4,2,3,4,3,2,3,3,2,2,3,4,2,3,2,3,3,3,3,4,1,2,3,3,2,3,3,4,3,2,2,3,4,2,3,4,2,2,2,3,3,3,3,4,2,2,2,3,3,3,3,4,3,3,2,3,2,2,3,4,3,3,3,3,4,2,3,4,2,2,3,3,3,3,3,4,3,1,2,3,3,2,3,4,2,3,2,3,3,2,3,4,3,2,3,3,4,3,3,4,3,2,2,3,3,3,3,4,2,2,3,3,3,2,3,4,4,2,2,3,2,3,3,4,3,3,2,3,4,3,3,4,3,3,2,3,1,2,3,4,2,2,3,3,3,2,3,4,3,3,2,3,2,3,3,4,3,3,2,3,4,2,3,4,2,2,3,3,2,3,3,4,2,2,3,3,3,2,3,4,3,3,3,3,3,2,3,4,3,2,2,3,4,3,3,4,4,1,2,3,2,2,3,4,2,3,2,3,3,3,3,4,2,2,3,3,2,2,3,4,3,2,2,3,4,3,3,4,3,3,3,3,3,2,3,4,2,
    3,3,3,3,3,3,4,4,2,2,3,3,2,3,4,3,2,2,3,4,2,3,4,1,2,3,3,2,3,3,4,3,2,3,3,3,2,3,4,2,3,2,3,2,3,3,4,3,2,3,3,4,2,3,4,3,3,2,3,2,2,3,4,3,3,2,3,3,2,3,4,3,2,3,3,2,3,3,4,3,3,2,3,4,3,3,4,2,1,2,3,3,2,3,4,2,2,2,3,3,3,3,4,3,2,3,3,2,2,3,4,3,3,2,3,4,2,3,4,3,3,3,3,2,2,3,4,3,2,2,3,3,3,3,4,4,3,2,3,3,3,3,4,3,2,3,3,4,3,3,4,2,2,2,3,1,2,3,4,2,3,3,3,3,2,3,4,2,3,2,3,2,3,3,4,3,3,3,3,4,2,3,4,2,3,2,3,3,2,3,4,2,2,3,3,3,3,3,4,3,2,2,3,3,2,3,4,3,3,2,3,4,2,3,4,3,2,3,3,2,3,3,4,2,1,2,3,3,2,3,4,3,2,2,3,3,2,3,4,3,2,3,3,4,3,3,4,3,2,2,3,2,3,3,4,2,3,2,3,3,2,3,4,4,3,3,3,2,3,3,4,3,3,2,3,4,2,3,4,2,3,2,3,3,2,3,4,3,2,3,3,3,3,3,4,1,2,3,3,2,2,3,4,3,2,2,3,4,3,3,4,2,2,2,3,3,3,3,4,3,2,2,3,3,2,3,4,3,3,3,3,2,3,3,4,3,3,3,3,4,2,3,4,3,2,2,3,2,3,3,4,2,3,2,3,3,3,3,4,2,2,3,3,3,3,3,4,3,1,2,3,4,2,3,4,3,2,2,3,3,2,3,4,2,2,3,3,3,3,3,4,4,3,2,3,2,3,3,4,3,3,2,3,4,2,3,4,3,2,3,3,2,2,3,4,3,2,2,3,3,2,3,4,2,3,3,3,3,2,3,4,3,2,3,3,4,3,3,4,2,3,3,3,1,2,3,4,2,3,2,3,3,2,3,4,3,3,2,3,2,3,3,4,3,2,2,3,4,2,3,4,4,3,3,3,2,3,3,4,2,2,3,3,3,3,3,4,3,2,2,3,2,2,3,4,3,3,3,3,4,
    3,3,4,3,3,3,3,2,3,3,4,3,2,2,3,3,2,3,4,4,1,2,3,3,2,3,4,3,3,2,3,4,3,3,4,3,2,2,3,3,3,3,4,2,3,2,3,3,2,3,4,2,2,3,3,2,2,3,4,3,3,3,3,4,2,3,4,2,3,2,3,3,2,3,4,2,3,3,3,3,3,3,4,3,2,2,3,2,3,3,4,3,3,2,3,4,2,3,4,1,2,2,3,2,3,3,4,3,2,3,3,3,2,3,4,2,3,2,3,2,2,3,4,3,2,3,3,4,2,3,4,3,3,3,3,2,2,3,4,2,3,2,3,3,3,3,4,4,2,3,3,3,3,3,4,3,2,2,3,4,3,3,4,2,2,2,3,3,2,3,4,3,3,3,3,3,3,3,4,3,1,2,3,2,2,3,4,3,3,2,3,4,2,3,4,2,2,3,3,2,3,3,4,3,3,2,3,3,2,3,4,3,3,2,3,3,2,3,4,3,2,3,3,4,3,3,4,3,3,2,3,2,2,3,4,3,2,3,3,3,2,3,4,2,2,2,3,3,3,3,4,3,2,2,3,4,3,3,4,3,3,2,3,1,2,3,4,2,2,3,3,3,2,3,4,4,2,3,3,2,2,3,4,3,3,3,3,4,2,3,4,4,3,3,3,2,3,3,4,2,2,2,3,3,2,3,4,2,3,2,3,3,2,3,4,3,3,2,3,4,3,3,4,3,2,3,3,2,3,3,4,2,3,3,3,3,3,3,4,3,3,3,3,2,2,3,4,3,1,2,3,4,2,3,4,2,3,2,3,3,2,3,4,2,2,3,3,3,3,3,4,2,2,2,3,3,2,3,4,3,3,2,3,4,2,3,4,3,2,3,3,3,3,3,4,3,3,2,3,3,2,3,4,4,3,2,3,2,3,3,4,3,2,3,3,4,3,3,4,3,2,2,3,2,3,3,4,2,3,2,3,3,2,3,4,1,2,3,3,2,3,3,4,3,2,3,3,4,2,3,4,2,3,2,3,3,3,3,4,2,2,2,3,3,3,3,4,3,3,2,3,2,2,3,4,3,3,3,3,4,3,3,4,4,2,3,3,3,2,3,4,3,2,2,3,3,2,3,4,2,
    3,3,3,3,2,3,4,3,2,3,3,4,3,3,4,3,2,2,3,2,3,3,4,3,1,2,3,3,2,3,4,4,3,2,3,2,3,3,4,3,2,2,3,4,2,3,4,2,3,2,3,3,2,3,4,2,2,3,3,3,2,3,4,3,3,2,3,3,2,3,4,3,3,2,3,4,3,3,4,2,2,3,3,2,3,3,4,2,2,3,3,3,3,3,4,3,2,2,3,3,3,3,4,3,2,2,3,4,3,3,4,3,2,3,3,1,2,3,4,2,3,2,3,3,2,3,4,3,2,3,3,2,3,3,4,3,2,2,3,4,2,3,4,3,3,2,3,3,3,3,4,2,2,3,3,3,3,3,4,4,2,3,3,2,2,3,4,3,2,3,3,4,2,3,4,2,3,2,3,2,3,3,4,3,3,2,3,3,3,3,4,2,3,2,3,2,2,3,4,3,3,3,3,4,2,3,4,3,1,2,3,3,2,3,4,2,3,2,3,3,2,3,4,3,2,3,3,2,3,3,4,3,3,2,3,4,2,3,4,3,3,3,3,3,2,3,4,2,2,2,3,3,3,3,4,3,2,2,3,2,3,3,4,3,3,3,3,4,2,3,4,3,2,3,3,2,3,3,4,3,2,3,3,3,2,3,4,4,3,2,3,3,2,3,4,3,2,3,3,4,3,3,4,1,2,2,3,2,2,3,4,2,2,2,3,3,3,3,4,2,3,3,3,3,3,3,4,3,2,2,3,4,2,3,4,2,3,3,3,2,2,3,4,2,3,3,3,3,2,3,4,3,2,3,3,3,2,3,4,3,3,2,3,4,3,3,4,2,3,3,3,2,3,3,4,3,2,2,3,3,2,3,4,2,2,2,3,3,2,3,4,3,2,3,3,4,3,3,4,3,1,2,3,2,2,3,4,3,3,2,3,3,3,3,4,4,2,3,3,2,2,3,4,3,2,2,3,4,3,3,4,3,3,2,3,3,2,3,4,2,2,3,3,3,3,3,4,2,3,2,3,2,3,3,4,3,3,2,3,4,3,3,4,3,2,2,3,2,3,3,4,3,2,2,3,3,2,3,4,3,3,2,3,3,3,3,4,3,3,3,3,4,2,3,4,4,3,2,3,1,
    2,3,4,2,3,3,3,3,2,3,4,2,3,3,3,2,3,3,4,3,2,2,3,4,2,3,4,3,2,3,3,3,2,3,4,2,3,3,3,3,3,3,4,4,2,3,3,2,2,3,4,3,3,2,3,4,2,3,4,2,2,3,3,2,3,3,4,3,3,2,3,3,3,3,4,3,3,2,3,3,2,3,4,3,3,3,3,4,3,3,4,2,2,2,3,3,2,3,4,2,1,2,3,3,2,3,4,3,2,2,3,2,3,3,4,3,2,3,3,4,2,3,4,2,3,2,3,2,3,3,4,3,2,3,3,3,2,3,4,3,3,2,3,2,2,3,4,3,3,2,3,4,3,3,4,3,2,3,3,3,3,3,4,2,2,3,3,3,2,3,4,4,3,3,3,3,2,3,4,3,3,2,3,4,3,3,4,3,2,2,3,2,2,3,4,2,3,3,3,3,2,3,4,1,2,3,3,2,3,3,4,3,2,3,3,4,3,3,4,2,3,2,3,3,2,3,4,3,2,3,3,3,3,3,4,3,3,2,3,2,2,3,4,3,2,2,3,4,2,3,4,3,2,2,3,2,3,3,4,3,3,2,3,3,3,3,4,2,3,2,3,3,3,3,4,3,2,3,3,4,3,3,4,3,2,3,3,2,2,3,4,2,3,3,3,3,2,3,4,4,2,3,3,2,3,3,4,3,1,2,3,4,2,3,4,3,2,2,3,3,3,3,4,2,2,2,3,3,3,3,4,3,2,2,3,2,2,3,4,3,3,2,3,4,2,3,4,2,3,3,3,3,2,3,4,3,2,2,3,3,2,3,4,3,3,2,3,3,3,3,4,3,2,3,3,4,3,3,4,2,3,3,3,3,2,3,4,2,3,2,3,3,3,3,4,2,2,3,3,2,3,3,4,3,3,2,3,4,2,3,4,3,3,3,3,1,2,3,4,2,3,3,3,3,2,3,4,4,2,2,3,2,3,3,4,3,3,2,3,4,2,3,4,3,3,3,3,3,3,3,4,2,2,3,3,3,2,3,4,2,3,2,3,3,2,3,4,3,2,3,3,4,3,3,4,3,2,2,3,2,3,3,4,2,3,2,3,3,2,3,4,3,2,3,3,3,2,3,4,3,
    2,3,3,4,2,3,4,4,3,3,3,3,3,3,4,2,3,3,3,3,3,3,4,3,1,2,3,2,2,3,4,3,2,2,3,4,2,3,4,3,2,2,3,2,3,3,4,3,2,2,3,3,3,3,4,4,3,3,3,2,2,3,4,3,2,3,3,4,3,3,4,3,3,2,3,2,2,3,4,3,3,3,3,3,2,3,4,2,2,3,3,2,3,3,4,3,3,2,3,4,3,3,4,2,3,2,3,3,2,3,4,2,3,2,3,3,3,3,4,3,2,3,3,3,2,3,4,3,3,2,3,4,2,3,4,1,2,3,3,2,2,3,4,3,2,2,3,3,3,3,4,2,3,3,3,3,3,3,4,3,2,3,3,4,3,3,4,3,2,2,3,2,3,3,4,2,2,3,3,3,2,3,4,4,2,3,3,2,3,3,4,3,3,2,3,4,3,3,4,2,3,2,3,2,2,3,4,2,2,3,3,3,3,3,4,3,2,2,3,3,2,3,4,3,3,2,3,4,2,3,4,2,2,3,3,2,3,3,4,2,3,2,3,3,3,3,4,3,1,2,3,3,2,3,4,3,2,2,3,4,3,3,4,3,2,3,3,3,3,3,4,2,3,2,3,3,2,3,4,2,2,3,3,2,2,3,4,3,3,3,3,4,2,3,4,3,3,2,3,3,2,3,4,3,2,3,3,3,3,3,4,4,2,2,3,2,3,3,4,3,2,3,3,4,3,3,4,2,2,2,3,2,3,3,4,3,3,2,3,3,2,3,4,3,3,3,3,3,2,3,4,3,3,3,3,4,2,3,4,3,2,2,3,1,2,3,4,2,3,2,3,3,2,3,4,3,3,3,3,2,3,3,4,3,2,2,3,4,2,3,4,2,2,2,3,3,3,3,4,2,3,3,3,3,3,3,4,3,3,3,3,2,2,3,4,3,3,2,3,4,3,3,4,3,2,3,3,2,3,3,4,3,2,2,3,3,3,3,4,4,3,2,3,3,2,3,4,3,2,3,3,4,3,3,4,3,2,3,3,2,2,3,4,2,3,2,3,3,2,3,4,3,3,2,3,3,3,3,4,3,1,2,3,4,2,3,4,2,3,2,3,2,3,3,4,3,2,3,3,3,
    2,3,4,3,2,2,3,2,2,3,4,3,3,3,3,4,2,3,4,4,3,3,3,2,3,3,4,2,2,2,3,3,2,3,4,2,3,2,3,3,2,3,4,3,2,2,3,4,3,3,4,3,3,2,3,3,2,3,4,2,3,2,3,3,3,3,4,4,3,3,3,3,2,3,4,3,2,2,3,4,2,3,4,3,3,3,3,3,2,3,4,2,2,3,3,3,3,3,4,1,2,2,3,2,3,3,4,3,2,2,3,4,2,3,4,2,2,3,3,2,3,3,4,3,2,2,3,3,3,3,4,3,3,3,3,2,2,3,4,3,3,3,3,4,2,3,4,3,2,2,3,3,2,3,4,2,3,3,3,3,3,3,4,2,2,3,3,3,3,3,4,3,2,3,3,4,2,3,4,3,2,3,3,3,3,3,4,2,3,2,3,3,3,3,4,4,2,2,3,2,2,3,4,3,3,2,3,4,2,3,4,2,3,3,3,2,3,3,4,3,1,2,3,3,2,3,4,2,3,2,3,3,2,3,4,3,2,3,3,4,3,3,4,2,3,2,3,2,3,3,4,3,3,2,3,3,2,3,4,3,2,3,3,2,3,3,4,3,2,2,3,4,3,3,4,3,3,2,3,3,3,3,4,3,2,3,3,3,2,3,4,3,2,3,3,2,2,3,4,3,3,2,3,4,2,3,4,3,2,3,3,2,3,3,4,2,3,3,3,3,2,3,4,4,2,2,3,3,3,3,4,3,2,3,3,4,3,3,4,4,3,2,3,1,2,3,4,2,3,3,3,3,2,3,4,2,3,3,3,2,3,3,4,3,2,2,3,4,2,3,4,2,3,2,3,3,2,3,4,2,2,3,3,3,3,3,4,3,2,2,3,3,2,3,4,3,2,2,3,4,3,3,4,2,3,3,3,2,3,3,4,3,3,3,3,3,2,3,4,2,3,2,3,2,2,3,4,3,2,3,3,4,3,3,4,3,3,3,3,2,3,3,4,2,3,2,3,3,3,3,4,4,3,3,3,3,3,3,4,3,2,3,3,4,2,3,4,3,1,2,3,3,2,3,4,3,2,2,3,3,3,3,4,3,2,2,3,2,2,3,4,3,3,2,3,4,3,3,4,2,
    2,3,3,3,2,3,4,3,3,2,3,3,2,3,4,3,3,2,3,3,2,3,4,3,3,3,3,4,3,3,4,4,2,2,3,2,3,3,4,2,2,3,3,3,2,3,4,3,2,2,3,2,3,3,4,3,2,2,3,4,3,3,4,3,3,3,3,2,2,3,4,2,2,3,3,3,3,3,4,4,3,2,3,2,3,3,4,3,3,2,3,4,2,3,4,1,2,3,3,2,3,3,4,3,2,2,3,3,3,3,4,2,2,2,3,3,3,3,4,3,2,2,3,4,3,3,4,3,2,3,3,2,2,3,4,3,3,2,3,3,2,3,4,3,2,3,3,2,2,3,4,3,2,3,3,4,2,3,4,2,3,2,3,3,2,3,4,2,3,3,3,3,3,3,4,2,2,2,3,3,2,3,4,3,3,3,3,4,3,3,4,3,3,2,3,2,3,3,4,3,2,3,3,3,2,3,4,4,3,2,3,2,3,3,4,3,2,3,3,4,3,3,4,3,1,2,3,3,2,3,4,2,3,2,3,3,3,3,4,2,2,3,3,2,3,3,4,3,3,2,3,4,2,3,4,3,3,2,3,3,2,3,4,2,2,3,3,3,3,3,4,3,2,2,3,2,3,3,4,3,3,2,3,4,2,3,4,3,2,3,3,2,2,3,4,3,2,3,3,3,3,3,4,2,3,2,3,3,3,3,4,3,3,3,3,4,3,3,4,3,2,2,3,3,2,3,4,2,2,2,3,3,3,3,4,4,2,2,3,3,3,3,4,3,3,2,3,4,2,3,4,2,3,3,3,1,2,3,4,2,2,3,3,3,2,3,4,3,2,3,3,2,2,3,4,3,3,3,3,4,2,3,4,2,2,3,3,2,3,3,4,2,3,2,3,3,2,3,4,3,3,3,3,3,2,3,4,3,2,2,3,4,3,3,4,3,3,2,3,2,2,3,4,3,3,2,3,3,3,3,4,2,3,3,3,2,2,3,4,3,2,2,3,4,3,3,4,3,3,2,3,3,2,3,4,2,2,3,3,3,3,3,4,4,3,3,3,2,2,3,4,3,3,2,3,4,2,3,4,3,2,3,3,3,3,3,4,3,1,2,3,3,2,3,4,2,3,2,3,2,
    3,3,4,3,2,3,3,4,3,3,4,3,2,2,3,2,2,3,4,2,3,3,3,3,2,3,4,3,3,3,3,3,3,3,4,3,2,2,3,4,3,3,4,4,2,2,3,3,2,3,4,2,2,3,3,3,3,3,4,3,2,2,3,3,3,3,4,3,3,2,3,4,2,3,4,3,3,3,3,2,2,3,4,3,3,2,3,3,2,3,4,4,3,2,3,3,2,3,4,3,3,3,3,4,3,3,4,2,3,2,3,2,3,3,4,2,3,2,3,3,2,3,4,1,2,2,3,2,3,3,4,3,2,3,3,4,2,3,4,2,3,3,3,3,2,3,4,3,2,3,3,3,3,3,4,3,2,2,3,2,3,3,4,3,3,2,3,4,3,3,4,2,2,3,3,3,3,3,4,2,3,2,3,3,2,3,4,2,2,3,3,3,2,3,4,3,3,2,3,4,3,3,4,3,2,2,3,3,2,3,4,3,3,2,3,3,2,3,4,4,2,3,3,2,3,3,4,3,2,3,3,4,2,3,4,2,3,3,3,3,3,3,4,2,2,3,3,3,3,3,4,3,2,2,3,2,3,3,4,3,1,2,3,4,2,3,4,2,3,2,3,2,3,3,4,3,2,2,3,3,3,3,4,3,3,2,3,3,2,3,4,3,2,3,3,4,2,3,4,3,2,2,3,2,2,3,4,2,3,2,3,3,2,3,4,3,2,3,3,2,3,3,4,3,2,3,3,4,3,3,4,3,3,2,3,3,3,3,4,2,3,2,3,3,3,3,4,4,2,2,3,2,3,3,4,3,3,3,3,4,2,3,4,3,3,3,3,2,2,3,4,3,3,2,3,3,2,3,4,2,3,2,3,3,2,3,4,3,2,3,3,4,3,3,4,2,3,3,3,1,2,3,4,2,2,3,3,3,2,3,4,3,2,3,3,2,3,3,4,3,3,3,3,4,2,3,4,3,3,2,3,2,2,3,4,2,2,3,3,3,2,3,4,3,3,2,3,2,2,3,4,3,3,2,3,4,2,3,4,3,2,3,3,2,3,3,4,3,2,3,3,3,2,3,4,4,3,3,3,3,2,3,4,3,2,2,3,4,3,3,4,3,2,3,3,2,3,3,4,2,
    3,2,3,3,3,3,4,2,2,3,3,3,2,3,4,3,2,2,3,4,2,3,4,2,3,3,3,3,3,3,4,2,3,3,3,3,3,3,4,3,1,2,3,2,2,3,4,3,3,2,3,4,3,3,4,4,2,2,3,3,3,3,4,3,2,2,3,3,2,3,4,2,3,3,3,3,2,3,4,3,2,3,3,4,2,3,4,3,3,2,3,3,3,3,4,2,3,2,3,3,2,3,4,4,2,3,3,2,3,3,4,3,2,2,3,4,3,3,4,2,2,2,3,3,2,3,4,2,3,3,3,3,3,3,4,3,3,3,3,2,2,3,4,3,3,3,3,4,3,3,4,3,2,3,3,2,3,3,4,3,2,2,3,3,2,3,4,3,3,3,3,3,3,3,4,3,3,3,3,4,3,3,4,1,2,2,3,2,2,3,4,3,2,2,3,3,2,3,4,2,3,2,3,2,3,3,4,3,2,2,3,4,2,3,4,3,3,2,3,2,3,3,4,2,3,3,3,3,3,3,4,4,2,2,3,3,2,3,4,3,3,2,3,4,2,3,4,2,2,3,3,2,3,3,4,2,3,3,3,3,2,3,4,3,2,2,3,3,3,3,4,3,2,2,3,4,3,3,4,3,2,3,3,2,3,3,4,2,3,2,3,3,3,3,4,3,2,3,3,2,3,3,4,3,2,3,3,4,2,3,4,3,3,2,3,3,2,3,4,3,2,3,3,3,3,3,4,2,1,2,3,3,2,3,4,3,2,2,3,4,2,3,4,3,2,3,3,3,3,3,4,3,2,2,3,3,3,3,4,4,3,3,3,2,2,3,4,3,3,3,3,4,3,3,4,3,3,2,3,2,2,3,4,2,3,2,3,3,2,3,4,2,2,3,3,3,3,3,4,3,3,2,3,4,3,3,4,2,2,2,3,3,2,3,4,2,2,3,3,3,3,3,4,3,3,2,3,3,2,3,4,3,3,3,3,4,2,3,4,2,2,3,3,2,2,3,4,3,2,2,3,3,3,3,4,3,3,2,3,3,3,3,4,3,2,3,3,4,3,3,4,3,2,3,3,1,2,3,4,2,3,2,3,3,2,3,4,4,3,2,3,2,3,3,4,3,3,2,3,4,
    2,3,4,3,3,2,3,2,3,3,4,2,2,3,3,3,2,3,4,3,2,3,3,2,2,3,4,3,3,3,3,4,3,3,4,2,2,3,3,2,3,3,4,3,2,3,3,3,3,3,4,3,2,2,3,3,2,3,4,3,3,3,3,4,3,3,4,4,2,2,3,3,2,3,4,2,3,2,3,3,2,3,4,2,2,3,3,3,3,3,4,3,3,2,3,4,2,3,4,3,3,2,3,3,3,3,4,2,3,3,3,3,3,3,4,4,2,2,3,2,3,3,4,3,1,2,3,4,2,3,4,3,3,2,3,2,3,3,4,3,2,3,3,3,2,3,4,2,3,2,3,2,2,3,4,3,2,3,3,4,2,3,4,3,3,2,3,2,2,3,4,2,3,2,3,3,3,3,4,3,3,3,3,2,3,3,4,3,2,2,3,4,2,3,4,2,3,3,3,3,2,3,4,3,3,2,3,3,3,3,4,3,2,2,3,2,2,3,4,3,3,2,3,4,2,3,4,3,2,3,3,2,2,3,4,3,2,3,3,3,2,3,4,4,3,2,3,3,2,3,4,3,3,3,3,4,3,3,4,2,3,3,3,3,2,3,4,3,2,2,3,3,3,3,4,1,2,3,3,2,3,3,4,3,2,3,3,4,3,3,4,2,3,2,3,3,3,3,4,2,2,3,3,3,3,3,4,3,2,3,3,2,2,3,4,3,3,2,3,4,2,3,4,3,2,3,3,3,3,3,4,2,3,2,3,3,2,3,4,2,3,3,3,3,3,3,4,3,2,2,3,4,3,3,4,3,2,2,3,2,2,3,4,2,3,3,3,3,2,3,4,4,3,3,3,2,2,3,4,3,2,2,3,4,3,3,4,4,3,3,3,3,3,3,4,3,2,3,3,3,3,3,4,2,2,2,3,3,3,3,4,3,2,2,3,4,2,3,4,2,3,3,3,2,3,3,4,3,1,2,3,3,2,3,4,3,3,2,3,3,2,3,4,3,2,3,3,4,2,3,4,3,2,2,3,2,3,3,4,2,3,3,3,3,2,3,4,2,3,3,3,2,3,3,4,3,3,2,3,4,2,3,4,3,3,2,3,3,2,3,4,3,2,2,3,3,3,3,4,4,
    2,2,3,3,2,3,4,3,3,2,3,4,3,3,4,3,3,3,3,3,3,3,4,3,2,3,3,3,2,3,4,2,3,3,3,3,2,3,4,3,3,3,3,4,3,3,4,3,3,2,3,2,2,3,4,2,2,2,3,3,3,3,4,3,2,2,3,2,3,3,4,3,2,2,3,4,3,3,4,4,3,2,3,1,2,3,4,2,2,3,3,3,2,3,4,3,3,2,3,2,2,3,4,3,3,3,3,4,2,3,4,3,2,3,3,3,3,3,4,2,2,2,3,3,2,3,4,4,3,2,3,3,2,3,4,3,2,3,3,4,3,3,4,3,2,3,3,2,3,3,4,2,3,2,3,3,3,3,4,3,2,3,3,3,2,3,4,3,3,2,3,4,2,3,4,2,3,2,3,3,3,3,4,2,2,3,3,3,3,3,4,3,3,3,3,2,2,3,4,3,2,3,3,4,2,3,4,2,3,3,3,2,3,3,4,3,2,2,3,3,2,3,4,2,3,3,3,2,2,3,4,3,3,3,3,4,3,3,4,3,1,2,3,3,2,3,4,3,3,2,3,3,2,3,4,4,2,3,3,2,3,3,4,3,3,2,3,4,2,3,4,2,2,2,3,3,2,3,4,2,3,2,3,3,3,3,4,3,3,2,3,2,3,3,4,3,3,3,3,4,2,3,4,2,2,3,3,3,2,3,4,3,3,3,3,3,2,3,4,3,3,2,3,3,3,3,4,3,2,3,3,4,3,3,4,3,2,2,3,2,2,3,4,2,3,3,3,3,3,3,4,2,2,2,3,3,3,3,4,3,2,2,3,4,3,3,4,3,3,2,3,3,2,3,4,2,3,3,3,3,2,3,4,4,2,3,3,2,2,3,4,3,3,3,3,4,2,3,4,1,2,3,3,2,3,3,4,2,2,2,3,3,2,3,4,2,3,2,3,3,2,3,4,3,2,3,3,4,3,3,4,3,3,2,3,2,2,3,4,3,3,2,3,3,2,3,4,3,2,3,3,2,3,3,4,3,3,2,3,4,3,3,4,2,3,2,3,3,2,3,4,2,2,3,3,3,3,3,4,2,2,3,3,2,2,3,4,3,3,3,3,4,3,3,4,3,2,2,3,2,
    3,3,4,3,2,2,3,3,3,3,4,4,3,2,3,2,3,3,4,3,2,3,3,4,2,3,4,3,2,2,3,3,3,3,4,3,3,3,3,3,3,3,4,2,3,3,3,2,3,3,4,3,2,2,3,4,3,3,4,2,1,2,3,3,2,3,4,2,2,2,3,3,3,3,4,3,2,3,3,3,2,3,4,3,3,2,3,4,3,3,4,4,3,3,3,2,2,3,4,3,3,2,3,3,2,3,4,3,3,2,3,3,2,3,4,3,2,3,3,4,3,3,4,3,2,2,3,2,3,3,4,2,3,3,3,3,2,3,4,4,2,2,3,3,3,3,4,3,2,3,3,4,2,3,4,2,3,2,3,2,2,3,4,2,3,3,3,3,3,3,4,3,2,3,3,2,3,3,4,3,3,2,3,4,3,3,4,3,2,3,3,3,3,3,4,3,2,2,3,3,2,3,4,3,2,3,3,3,2,3,4,3,2,2,3,4,3,3,4,3,3,2,3,1,2,3,4,2,3,2,3,3,2,3,4,2,2,3,3,2,3,3,4,3,3,2,3,4,2,3,4,3,3,3,3,3,2,3,4,2,2,3,3,3,3,3,4,4,3,2,3,2,2,3,4,3,3,2,3,4,2,3,4,2,3,2,3,2,3,3,4,3,2,3,3,3,3,3,4,2,3,3,3,3,2,3,4,3,3,3,3,4,2,3,4,3,2,3,3,3,3,3,4,2,3,2,3,3,2,3,4,3,2,3,3,2,3,3,4,3,2,3,3,4,2,3,4,3,2,2,3,3,3,3,4,2,2,3,3,3,3,3,4,3,2,2,3,2,2,3,4,3,3,3,3,4,2,3,4,3,3,3,3,2,2,3,4,3,1,2,3,3,2,3,4,4,3,2,3,3,3,3,4,3,2,3,3,4,3,3,4,3,3,2,3,3,2,3,4,2,2,2,3,3,2,3,4,2,2,3,3,2,3,3,4,3,3,2,3,4,3,3,4,3,3,3,3,2,2,3,4,3,2,3,3,3,2,3,4,3,2,2,3,2,3,3,4,3,3,2,3,4,3,3,4,2,2,3,3,2,3,3,4,2,3,3,3,3,2,3,4,3,3,2,3,3,2,3,4,3,
    2,2,3,4,3,3,4,3,3,2,3,2,2,3,4,2,3,2,3,3,3,3,4,4,2,3,3,3,3,3,4,3,2,2,3,4,3,3,4,3,3,3,3,3,2,3,4,2,3,3,3,3,3,3,4,1,2,2,3,2,3,3,4,3,2,2,3,4,2,3,4,2,3,3,3,2,3,3,4,3,2,2,3,3,2,3,4,3,3,2,3,2,2,3,4,3,3,3,3,4,3,3,4,4,2,3,3,2,2,3,4,3,3,2,3,3,3,3,4,2,2,3,3,2,3,3,4,3,2,3,3,4,3,3,4,3,2,3,3,3,2,3,4,3,2,2,3,3,3,3,4,4,3,2,3,2,2,3,4,3,3,2,3,4,2,3,4,4,3,3,3,3,2,3,4,3,2,2,3,3,3,3,4,2,3,2,3,3,3,3,4,3,2,3,3,4,3,3,4,2,3,2,3,2,3,3,4,2,2,3,3,3,2,3,4,3,3,2,3,2,3,3,4,3,1,2,3,4,2,3,4,2,3,2,3,3,2,3,4,2,2,3,3,3,3,3,4,3,3,2,3,2,2,3,4,3,3,3,3,4,2,3,4,3,2,3,3,3,3,3,4,2,3,2,3,3,3,3,4,4,2,3,3,3,3,3,4,3,2,2,3,4,3,3,4,3,2,2,3,2,2,3,4,3,3,2,3,3,2,3,4,2,3,3,3,3,3,3,4,3,2,3,3,4,2,3,4,2,3,2,3,3,2,3,4,3,3,3,3,3,3,3,4,3,2,2,3,3,2,3,4,3,3,2,3,4,3,3,4,3,2,2,3,3,3,3,4,3,2,3,3,3,2,3,4,2,3,3,3,2,2,3,4,3,3,3,3,4,2,3,4,3,2,2,3,1,2,3,4,2,3,2,3,3,2,3,4,4,3,3,3,2,3,3,4,3,2,2,3,4,2,3,4,2,3,3,3,3,3,3,4,2,2,3,3,3,3,3,4,3,3,2,3,2,2,3,4,3,3,2,3,4,2,3,4,2,2,3,3,2,2,3,4,3,2,2,3,3,3,3,4,3,3,2,3,3,2,3,4,3,2,3,3,4,3,3,4,2,2,3,3,2,3,3,4,2,2,3,3,3,
    2,3,4,3,3,3,3,2,3,3,4,3,3,2,3,4,2,3,4,3,3,2,3,3,3,3,4,2,2,3,3,3,3,3,4,4,2,2,3,2,2,3,4,3,3,3,3,4,2,3,4,3,3,3,3,2,3,3,4,3,2,3,3,3,2,3,4,3,1,2,3,3,2,3,4,3,2,2,3,4,3,3,4,3,2,2,3,3,2,3,4,2,3,2,3,3,3,3,4,3,3,3,3,2,2,3,4,3,3,2,3,4,3,3,4,4,3,2,3,3,2,3,4,2,2,3,3,3,3,3,4,2,2,3,3,3,3,3,4,3,3,2,3,4,3,3,4,3,2,2,3,2,3,3,4,3,3,3,3,3,3,3,4,4,3,2,3,3,2,3,4,3,2,3,3,4,2,3,4,3,2,3,3,2,2,3,4,2,3,2,3,3,2,3,4,2,3,3,3,3,3,3,4,3,3,2,3,4,2,3,4,2,2,3,3,3,2,3,4,2,3,3,3,3,3,3,4,3,3,2,3,2,3,3,4,3,3,2,3,4,2,3,4,1,2,3,3,2,3,3,4,3,2,2,3,3,2,3,4,2,3,2,3,3,2,3,4,3,2,3,3,4,3,3,4,3,3,2,3,2,3,3,4,3,2,2,3,3,2,3,4,4,2,2,3,2,3,3,4,3,2,3,3,4,3,3,4,2,3,3,3,3,2,3,4,2,2,3,3,3,3,3,4,3,2,3,3,3,2,3,4,3,3,2,3,4,2,3,4,2,2,3,3,2,3,3,4,2,3,2,3,3,2,3,4,3,2,2,3,3,3,3,4,3,2,3,3,4,3,3,4,3,2,3,3,3,2,3,4,2,3,3,3,3,3,3,4,2,3,3,3,2,2,3,4,3,2,3,3,4,2,3,4,3,3,3,3,3,3,3,4,3,2,3,3,3,3,3,4,4,1,2,3,3,2,3,4,3,2,2,3,4,2,3,4,4,2,2,3,2,3,3,4,3,3,2,3,3,2,3,4,3,3,2,3,2,2,3,4,3,3,3,3,4,3,3,4,3,2,2,3,2,3,3,4,2,3,2,3,3,3,3,4,3,2,3,3,2,3,3,4,3,2,3,3,4,3,3,4,2,
    3,2,3,3,2,3,4,3,2,2,3,3,3,3,4,3,2,3,3,2,2,3,4,3,3,2,3,4,3,3,4,3,2,3,3,2,3,3,4,3,3,2,3,3,2,3,4,4,3,3,3,3,2,3,4,3,3,3,3,4,3,3,4,3,2,2,3,2,2,3,4,2,3,3,3,3,2,3,4,2,2,2,3,3,3,3,4,3,2,2,3,4,2,3,4,3,3,2,3,1,2,3,4,2,2,3,3,3,2,3,4,3,3,2,3,2,2,3,4,3,3,3,3,4,2,3,4,4,3,3,3,3,3,3,4,2,3,2,3,3,3,3,4,2,2,2,3,3,2,3,4,3,3,3,3,4,3,3,4,3,2,3,3,2,3,3,4,2,3,3,3,3,3,3,4,4,2,3,3,2,2,3,4,3,2,2,3,4,3,3,4,2,3,2,3,3,3,3,4,2,3,3,3,3,3,3,4,3,2,2,3,2,3,3,4,3,3,3,3,4,2,3,4,2,3,2,3,2,3,3,4,3,2,3,3,3,2,3,4,3,3,2,3,2,2,3,4,3,2,3,3,4,3,3,4,3,3,2,3,3,3,3,4,2,3,2,3,3,2,3,4,3,2,3,3,2,3,3,4,3,1,2,3,4,2,3,4,3,3,2,3,3,2,3,4,2,2,2,3,3,3,3,4,4,3,2,3,3,3,3,4,3,3,2,3,4,2,3,4,2,2,3,3,2,2,3,4,3,2,2,3,3,2,3,4,2,3,3,3,3,3,3,4,3,2,3,3,4,3,3,4,2,2,2,3,2,2,3,4,3,2,2,3,3,3,3,4,3,2,3,3,3,3,3,4,3,2,3,3,4,2,3,4,3,3,3,3,2,2,3,4,2,3,3,3,3,3,3,4,3,3,2,3,3,2,3,4,3,3,2,3,4,3,3,4,3,3,3,3,2,3,3,4,2,2,3,3,3,2,3,4,4,2,2,3,3,3,3,4,3,3,3,3,4,3,3,4,3,3,2,3,2,3,3,4,3,3,2,3,3,2,3,4,1,2,3,3,2,2,3,4,3,2,3,3,4,2,3,4,2,3,2,3,3,2,3,4,2,2,3,3,3,3,3,4,3,2,3,3,2,
    2,3,4,3,3,2,3,4,3,3,4,3,2,3,3,2,3,3,4,3,2,2,3,3,3,3,4,2,3,2,3,3,3,3,4,3,2,3,3,4,2,3,4,3,2,2,3,2,3,3,4,2,3,3,3,3,3,3,4,4,3,3,3,2,3,3,4,3,3,2,3,4,2,3,4,3,2,2,3,3,2,3,4,2,2,2,3,3,3,3,4,3,2,2,3,3,2,3,4,3,3,3,3,4,2,3,4,2,2,3,3,2,3,3,4,3,3,3,3,3,2,3,4,3,3,3,3,3,2,3,4,3,2,3,3,4,3,3,4,4,2,2,3,2,3,3,4,3,1,2,3,3,2,3,4,2,3,2,3,2,3,3,4,3,2,3,3,4,2,3,4,3,3,2,3,2,2,3,4,3,2,3,3,3,2,3,4,4,2,3,3,2,2,3,4,3,3,2,3,4,3,3,4,2,2,3,3,3,3,3,4,2,2,2,3,3,3,3,4,2,3,2,3,3,2,3,4,3,3,2,3,4,3,3,4,3,2,2,3,3,2,3,4,2,3,2,3,3,2,3,4,3,2,3,3,3,3,3,4,3,2,2,3,4,2,3,4,2,3,2,3,3,3,3,4,2,3,3,3,3,3,3,4,2,3,3,3,2,3,3,4,3,2,2,3,4,3,3,4,3,2,3,3,3,3,3,4,3,3,2,3,3,3,3,4,4,3,2,3,2,2,3,4,3,2,3,3,4,2,3,4,3,2,3,3,1,2,3,4,2,3,2,3,3,2,3,4,3,2,3,3,2,3,3,4,3,2,3,3,4,2,3,4,2,2,3,3,3,2,3,4,2,3,2,3,3,3,3,4,3,3,2,3,2,2,3,4,3,3,3,3,4,2,3,4,3,3,3,3,2,3,3,4,3,2,2,3,3,3,3,4,2,3,2,3,3,2,3,4,3,3,3,3,4,3,3,4,3,2,3,3,3,2,3,4,2,3,2,3,3,2,3,4,4,2,3,3,2,3,3,4,3,3,2,3,4,2,3,4,3,3,2,3,3,3,3,4,3,2,3,3,3,2,3,4,3,3,2,3,2,3,3,4,3,3,2,3,4,2,3,4,2,2,3,3,2,3,3,4,2,
    2,3,3,3,2,3,4,3,3,2,3,3,2,3,4,3,3,3,3,4,3,3,4,3,1,2,3,2,2,3,4,2,3,2,3,3,3,3,4,2,2,3,3,3,3,3,4,3,2,2,3,4,3,3,4,3,3,3,3,3,2,3,4,3,2,3,3,3,3,3,4,4,3,2,3,2,2,3,4,3,2,3,3,4,3,3,4,3,2,2,3,2,3,3,4,3,3,2,3,3,3,3,4,2,3,2,3,3,2,3,4,3,2,3,3,4,2,3,4,3,3,2,3,2,2,3,4,3,3,3,3,3,2,3,4,3,2,3,3,2,3,3,4,3,3,2,3,4,3,3,4,4,2,3,3,3,2,3,4,2,2,2,3,3,3,3,4,3,2,3,3,2,2,3,4,3,3,2,3,4,2,3,4,3,3,3,3,2,2,3,4,3,2,2,3,3,2,3,4,4,3,3,3,3,3,3,4,3,2,3,3,4,3,3,4,1,2,3,3,2,2,3,4,2,2,3,3,3,3,3,4,2,3,3,3,2,3,3,4,3,2,2,3,4,2,3,4,2,3,2,3,2,3,3,4,2,2,3,3,3,3,3,4,3,2,2,3,3,3,3,4,3,3,2,3,4,2,3,4,2,2,3,3,3,3,3,4,3,3,2,3,3,2,3,4,3,2,2,3,3,3,3,4,3,2,3,3,4,3,3,4,3,3,2,3,2,3,3,4,2,3,3,3,3,2,3,4,4,3,3,3,2,2,3,4,3,2,3,3,4,2,3,4,2,3,2,3,3,2,3,4,3,3,3,3,3,3,3,4,2,3,3,3,2,2,3,4,3,3,2,3,4,3,3,4,2,2,2,3,3,3,3,4,3,2,2,3,3,2,3,4,3,3,3,3,2,2,3,4,3,3,3,3,4,3,3,4,3,1,2,3,2,2,3,4,3,3,2,3,3,2,3,4,3,2,3,3,2,3,3,4,3,2,2,3,4,2,3,4,3,2,2,3,3,2,3,4,2,3,3,3,3,3,3,4,4,2,2,3,3,2,3,4,3,3,2,3,4,2,3,4,2,2,3,3,3,2,3,4,3,3,3,3,3,3,3,4,2,3,2,3,3,3,3,4,3,2,3,3,4,
    3,3,4,3,2,2,3,2,2,3,4,2,3,3,3,3,3,3,4,3,2,2,3,2,3,3,4,3,2,2,3,4,2,3,4,2,3,3,3,2,3,3,4,2,3,3,3,3,2,3,4,3,2,2,3,2,3,3,4,3,3,3,3,4,2,3,4,3,3,3,3,2,3,3,4,3,2,2,3,3,3,3,4,4,3,2,3,3,3,3,4,3,2,2,3,4,3,3,4,3,2,2,3,1,2,3,4,2,3,2,3,3,2,3,4,2,3,3,3,2,2,3,4,3,3,2,3,4,2,3,4,3,3,2,3,3,3,3,4,2,3,3,3,3,3,3,4,3,2,2,3,3,2,3,4,3,2,3,3,4,2,3,4,4,2,3,3,2,3,3,4,3,2,3,3,3,2,3,4,2,3,3,3,2,2,3,4,3,2,3,3,4,3,3,4,3,2,2,3,2,2,3,4,2,3,3,3,3,3,3,4,4,3,3,3,3,3,3,4,3,2,2,3,4,2,3,4,3,3,3,3,3,2,3,4,2,3,2,3,3,3,3,4,3,2,3,3,2,2,3,4,3,3,2,3,4,3,3,4,2,3,3,3,2,3,3,4,3,2,2,3,3,2,3,4,3,3,2,3,3,2,3,4,3,3,3,3,4,3,3,4,2,3,3,3,3,2,3,4,2,1,2,3,3,2,3,4,2,2,2,3,3,3,3,4,3,2,2,3,4,3,3,4,3,3,2,3,3,2,3,4,2,2,3,3,3,2,3,4,4,2,3,3,3,3,3,4,3,3,2,3,4,3,3,4,3,2,3,3,2,3,3,4,2,2,2,3,3,3,3,4,2,2,2,3,3,3,3,4,3,2,2,3,4,3,3,4,3,3,3,3,2,2,3,4,2,3,2,3,3,2,3,4,3,3,3,3,2,3,3,4,3,3,2,3,4,3,3,4,3,3,2,3,3,2,3,4,2,2,3,3,3,3,3,4,3,3,2,3,3,2,3,4,3,2,2,3,4,2,3,4,3,2,3,3,3,3,3,4,3,3,2,3,3,2,3,4,4,3,2,3,2,2,3,4,3,3,3,3,4,2,3,4,4,2,2,3,3,3,3,4,2,3,3,3,3,2,3,4,1,
};

int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n); 
        printf("%d\n", res[n - 1]);
    }
    
    return 0;
}
