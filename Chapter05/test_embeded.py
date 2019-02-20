# coding: utf-8
import os
import ctypes


def unsigned_fact_args(func):
    def wrap(*args, **kw):
        load = func(*args, **kw)
        load.argtypes = [ctypes.c_uint]
        load.restype = ctypes.c_ulonglong
        return load
    return wrap


def uint_arg(func):
    def wrap(*args):
        args = tuple(ctypes.c_uint(val) for val in args if not isinstance(val, ctypes.c_uint) or val)
        return func(*args)
    return wrap


libc = ctypes.CDLL("./libex5_1.so")


@unsigned_fact_args
@uint_arg
def get_simple_factorial():
    return libc.simpleFactorial


@unsigned_fact_args
@uint_arg
def get_tree_factorial():
    return libc.treeFactorial

@unsigned_fact_args
@uint_arg
def get_fact_factorial():
	libc = ctypes.CDLL("./libex5_1_1.so")
	return libc.factFactorial
	

# TESTS
def test_simple_factorial():
    func = get_simple_factorial()
    return func(10)


def test_tree_factorial():
    func = get_tree_factorial()
    return func(10)

	
def test_fact_factorial():
    func = get_fact_factorial()
    return func(10)
	

def navi_fact(N):
    if N < 0:
        return 0
    elif N == 0:
        return 1
    elif (N == 1) or (N ==2):
        return N
    return N*navi_fact(N-1)


if __name__ == "__main__":
	print(test_simple_factorial())
	print(test_tree_factorial())
	print(test_fact_factorial())
