# coding: utf-8
"""
Ex1.2: Решение задачи связности методом быстрого объединения.
"""
import sys

from template import Connectivity, make_connect_table

__author__     = "Vladimir Gerasimenko"
__copyright__  = "Copyright (C) 2018, Vladimir Gerasimenko"
__version__    = "0.0.1"
__maintainer__ = "Vladimir Gerasimenko"
__email__      = "vladworldss@yandex.ru"


def pure_quick_union(N=10):
    """
    Исходный листинг программы 1.2 адаптированный пот Python.

    :return:
    """
    _id = list(range(0, N))
    while True:
        try:
            p, q = tuple(map(int, input('Get int pair (p, q): \n').split()))

            i = p
            while (i < N) and (_id[i] != i):
                i = _id[i]

            j = q
            while (j < N) and (_id[j] != j):
                j = _id[j]

            if _id[p] == _id[q]:
                continue

            _id[i] = j
            print(p, q)
        except ValueError:
            continue
        except (KeyboardInterrupt, EOFError):
            print("Result: ", _id)
            return _id


class QuickUnion(Connectivity):
    """
    Класс быстрого объединения
    Сложность = (худший) O(M*N/2) -> O(M*N)
    """
    def union(self, p, q):
        founded = self.find(p, q)
        if founded is None:
            return

        p_root, q_root = founded
        self.arr[p_root] = q_root
        return p, q

    def find(self, p, q):
        p_root, q_root = self._get_root(self.arr[p]), self._get_root(self.arr[q])
        if p_root != q_root:
            return p_root, q_root

    def _get_root(self, i):
        """
        Метод возвращает корень дерева
        :param i:
        :return:
        """
        parent = self.arr[i]
        if parent == i:
            return i
        else:
            return self._get_root(parent)


class WeightedQuickUnion(QuickUnion):
    """
    Класс взвешенного быстрого объединения
    Сложность = O(M*log(N))
    """
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.sz = [1 for _ in range(self.size)]

    def union(self, p, q):

        founded = self.find(p, q)
        if founded is None:
            return
        p_root, q_root = founded
        if self.sz[p_root] < self.sz[q_root]:
            self.arr[p_root] = q_root
            self.sz[q_root] += self.sz[p_root]
        else:
            self.arr[q_root] = p_root
            self.sz[p_root] += self.sz[q_root]
        return p, q


input_pairs = (
        (3, 4),
        (4, 9),
        (8, 0),
        (2, 3),
        (5, 6),
        (2, 9),
        (5, 9),
        (7, 3),
        (4, 8),
        (5, 6),
        (0, 2),
        (6, 1)
    )
etalon_res = [1, 1, 9, 4, 9, 6, 9, 9, 0, 0]
weighted_etalon_res = [8, 3, 3, 3, 3, 3, 5, 3, 3, 3]


def test_custom(Cls=QuickUnion, etalon_res=etalon_res):
    c = Cls()
    for pair in input_pairs:
        c.union(*pair)
    assert c.arr == etalon_res
    return c.arr


def test_custom_weighted():
    return test_custom(WeightedQuickUnion, weighted_etalon_res)


if __name__ == '__main__':
    args = sys.argv
    if len(args) > 1:
        if "pure" in args[1]:
            print("PURE CONNECTIVITY")
            pure_quick_union()
        elif "test" in args[1]:
            pure_res = pure_quick_union()
            custom_res = test_custom()
            assert pure_res == custom_res
    else:
        print("CUSTOM CONNECTIVITY")
        res = make_connect_table(QuickUnion)
        print(res)
