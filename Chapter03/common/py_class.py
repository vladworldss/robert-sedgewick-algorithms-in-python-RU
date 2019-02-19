# py_class.py - исходник Python, служащий для
# демонстрации применения встраивания python

class Multiply:
    def __init__(self):
        self.a = 6
        self.b = 5

    def multiply(self):
        c = self.a*self.b
        print('The result of {} x {}: {}'.format(self.a, self.b, c))
        return c


def multiply2(self, a, b):
    c = a*b
    print('The result of {} x {}: {}'.format(a, b, c))
    return c
