import unittest
from Lab_05_3 import z
from Lab_05_3 import summary

class TestA(unittest.TestCase):

    def test_z(self):
        self.assertAlmostEqual(z(2), 0.011994150103530233)
        self.assertAlmostEqual(z(0.5), 1.2534314381334395)

    def test_summary(self):
        self.assertAlmostEqual(summary(0.5), 0.7602445970756299)