#!/usr/bin/python3
"""
This is the 0-minoperations.py module.
"""


def minOperations(n):
    """
    find the prime factorization of n
    """

    if (n <= 0):
        return 0

    prime_fact = []
    while n % 2 == 0:
        prime_fact.append(2)
        n = n / 2
    for num in range(3, int(n ** 0.5) + 1, 2):
        while n % num == 0:
            prime_fact.append(num)
            n = n / num
    if n > 2:
        prime_fact.append(n)
    return int(sum(prime_fact))
