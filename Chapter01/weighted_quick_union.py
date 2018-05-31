# coding: utf-8
"""
Ex1.3: Взвешенная версия быстрого объединения.
"""
from template import make_connect_table, test_connectivity
from quick_union import Connectivity as QuickUnionConnectivity

__author__     = "Vladimir Gerasimenko"
__copyright__  = "Copyright (C) 2018, Vladimir Gerasimenko"
__version__    = "0.0.1"
__maintainer__ = "Vladimir Gerasimenko"
__email__      = "vladworldss@yandex.ru"


class Connectivity(QuickUnionConnectivity):
    """
    Класс взвешенного быстрого объединения
    Сложность = O(M*log(N))
    """
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.sz = [1 for _ in range(self.size)]

    def union(self, p, q):
        """
        Метод объединения, модифицирующая QuickUnion.
        Поддерживает для каждого объекта массив sz, представляющий собой
        массив количества узлов в соответствующем ему дереве, для того, чтобы
        union могла связать меньшее из 2-х заданных деревьев с большим, тем
        самым предотвращая разрастание длинных путей в деревьях.

        :param p:
        :param q:
        :return:
        """
        founded = self.find(p, q)
        if founded is None:
            return
        p_root, q_root = founded

        if self.sz[p_root] < self.sz[q_root]:
            self.arr[p_root] = q_root
            # увеличиваем счетчик узлов на величину присоединяемого малого дерева
            self.sz[q_root] += self.sz[p_root]
        else:
            self.arr[q_root] = p_root
            # увеличиваем счетчик узлов на величину присоединяемого малого дерева
            self.sz[p_root] += self.sz[q_root]
        return p, q


# --------------------------------
#           TESTS
# --------------------------------
def test_custom_weighted():
    ETALON_RES = [8, 3, 3, 3, 3, 3, 5, 3, 3, 3]
    return test_connectivity(Connectivity, ETALON_RES)
# --------------------------------


if __name__ == '__main__':
    print("CUSTOM CONNECTIVITY")
    res = make_connect_table(Connectivity)
    print(res)
