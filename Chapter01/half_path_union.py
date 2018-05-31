# coding: utf-8
"""
Ex1.4: Сжатие пути делением пополам.
"""
from weighted_quick_union import Connectivity as WeightedQuickUnionConnectivity
from template import make_connect_table, test_connectivity

__author__     = "Vladimir Gerasimenko"
__copyright__  = "Copyright (C) 2018, Vladimir Gerasimenko"
__version__    = "0.0.1"
__maintainer__ = "Vladimir Gerasimenko"
__email__      = "vladworldss@yandex.ru"


class Connectivity(WeightedQuickUnionConnectivity):

    def find(self, p, q):
        p_root = self._get_root(p)
        q_root = self._get_root(q)
        if p_root != q_root:
            return p_root, q_root

    def _get_root(self, val):
        i = val
        while (-1 < i < self.size):
            if i == self.arr[i]:
                break
            self.arr[i] = self.arr[self.arr[i]]
            i = self.arr[i]
        return i


# --------------------------------
#           TESTS
# --------------------------------
def test_custom_weighted():
    ETALON_RES = [3, 3, 3, 3, 3, 3, 3, 3, 3, 3]
    return test_connectivity(Connectivity, ETALON_RES)
# --------------------------------


if __name__ == '__main__':
    print("CUSTOM CONNECTIVITY")
    res = make_connect_table(Connectivity)
    print(res)
