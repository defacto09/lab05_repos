import unittest
import math
from Lab_05_2 import A
from Lab_05_2 import Sum

class TestA(unittest.TestCase):

    def test_h(self):
        self.assertAlmostEqual(A(0.5, 1, 0.5),  0.041666666666666664)

    def test_Sum(self):
        s, n = Sum(0.5, 1e-9)
        self.assertAlmostEqual(s, math.log(3))