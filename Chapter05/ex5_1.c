/* ex5_1.c
 * Factorial implementations
 * */

unsigned long long simpleFactorial(unsigned N)
{
    if (N < 0)
    {
        return 0;
    }

    if (N == 0)
    {
        return 1;
    }

    return N*simpleFactorial(N-1);
}


unsigned long long _prodTree(unsigned left, unsigned right)
{
    if (left > right)
    {
        return 1;
    }

    if (left == right)
    {
        return left;
    }

    if ( right - left == 1)
    {
        return left*right;
    }

    unsigned middle = (left + right)/2;
    return _prodTree(left, middle) * _prodTree(middle+1, right);
}

unsigned long long treeFactorial(unsigned N)
{
    if (N < 0)
    {
        return 0;
    }

    if (N == 0)
    {
        return 1;
    }

    if (N == 1 || N == 2)
        return N;

    return _prodTree(2, N);
}
