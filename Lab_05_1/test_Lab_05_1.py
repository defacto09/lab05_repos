import unittest
from Lab_05_1 import h

class TestH(unittest.TestCase):

    def test_h(self):
        self.assertAlmostEqual(h(1,2,1), 0.8)
        