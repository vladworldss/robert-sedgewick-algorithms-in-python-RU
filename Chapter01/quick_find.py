# coding: utf-8
"""
Ex 1.1 Решение задачи связности методом быстрого поиска.

Идея:
    1) для быстрого поиска мы используем прямое обращение к массиву.
    Т.к. в каждой ячейке хранится индекс root-ячейки, то
    Сложность - O(1)

    2) Для того, чтобы переставить ссылку на новый root-объект, необходимо
    пройти по всему массиву, с целью замены на новый root-объект.
    Сложность - O(N) для 1 элемента вставки.

Пример.

Имеем исходный массив на 4 элемента:
_id = [0, 1, 2, 3]
Каждый объект указывает сам на себя, т.е. является root-объектом.

p и q - это LEAF (лист) и ROOT (корень) объекты соотвественно.
Необъходимо, чтобы при объединении LEAF содержал ссылку (индекс) на ROOT,
к примеру, [2, 1, 2, 3] - LEAF - 0, ROOT - 2

Псевдокод объединения:
    - получить
    - получить значения ссылок p, q - P_ROOT, Q_ROOT
    - проверить их на равенство.
        --Если они равны - это значит, что они указывают
            на один и тот же объект. Continue.
        --Если не равны - мы должны пройти по всему массиву
            и те объекты, которые указывают на P_ROOT - заменить их на Q_ROOT.
            Вернуть пару - p, q


Сложность: O(N*M)
N - число объектов;
M - число операций объединений.
"""
import sys

from template import Connectivity, make_connect_table

__author__     = "Vladimir Gerasimenko"
__copyright__  = "Copyright (C) 2018, Vladimir Gerasimenko"
__version__    = "0.0.1"
__maintainer__ = "Vladimir Gerasimenko"
__email__      = "vladworldss@yandex.ru"


def pure_quick_find(N=10):
    """
    Исходный листинг программы 1.1 адаптированный пот Python.

    :param int N: константа размера массива
    :return:
    """
    _id = list(range(0, N))
    while True:
        try:
            p, q = tuple(map(int, input('Get int pair (p, q): \n').split()))
            if _id[p] == _id[q]:
                continue
            t = _id[p]
            for i, val in enumerate(_id):
                if val == t:
                    _id[i] = _id[q]
            print(p, q)
        except ValueError:
            continue
        except (KeyboardInterrupt, EOFError):
            print("Result: ", _id)
            return _id


class QuickFind(Connectivity):
    """
    Класс, реализующий логику быстрого поиска.
    """
    def __init__(self, size):
        super().__init__(size)

    def find(self, p, q):
        """
        Метод поиска связанных элементов.
        Элементы считаются связанными, если в их ячейках лежат одинаковые значениях, e.g.
        arr[1] == 9
        arr[4] == 9
        => элементы 1 и 4 - связанные

        :param p:
        :param q:
        :return: None (если указывают на один объект), иначе кортеж (p, q)
        """
        p_root, q_root = self.arr[p], self.arr[q]
        if p_root != q_root:
            return p_root, q_root

    def union(self, p, q):
        """
        Метод объединения пары элементов.

        :param p:
        :param q:
        :return:
        """
        founded = self.find(p, q)
        if founded is None:
            return
        p_root, q_root = founded
        for i, val in enumerate(self.arr):
            if val == p_root:
                self.arr[i] = q_root
        return p, q


def test_custom():
    c = QuickFind(N)
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
    for pair in input_pairs:
        c.union(*pair)
    assert all(x is 1 for x in c.arr)
    return c.arr


if __name__ == '__main__':
    """
    В файле input.txt находятся связываемые пары.

    Для запуска pure_quick_find:
    $ python quick_find.py pure < input.txt 

    Для запуска автотеста test_custom:
    $ pytest -v quick_find.py

    Для сравнения результата реализаций:
    $ python quick_find.py test < input.txt
    """

    args = sys.argv
    if len(args) > 1:
        if "pure" in args[1]:
            print("PURE CONNECTIVITY")
            pure_quick_find()
        elif "test" in args[1]:
            pure_res = pure_quick_find()
            custom_res = test_custom()
            assert pure_res == custom_res
    else:
        print("CUSTOM CONNECTIVITY")
        res = make_connect_table(QuickFind)
        print(res)
