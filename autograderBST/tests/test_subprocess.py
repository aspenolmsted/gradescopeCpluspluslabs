import unittest
from gradescope_utils.autograder_utils.decorators import weight
import subprocess


class TestDiff(unittest.TestCase):
    def setUp(self):
        pass

    @weight(2)
    def test_random_1(self):
        testsub = subprocess.Popen(["./a.out", "1"], stdout=subprocess.PIPE, stderr=subprocess.PIPE, encoding='utf8')
        output = testsub.stdout.read().strip()
        self.assertEqual(output, "Passed All Tests")
        testsub.terminate()

    @weight(2)
    def test_random_2(self):
        testsub = subprocess.Popen(["./a.out", "2"], stdout=subprocess.PIPE, stderr=subprocess.PIPE, encoding='utf8')
        output = testsub.stdout.read().strip()
        self.assertEqual(output, "Passed All Tests")
        testsub.terminate()

    @weight(2)
    def test_random_3(self):
        testsub = subprocess.Popen(["./a.out", "3"], stdout=subprocess.PIPE, stderr=subprocess.PIPE, encoding='utf8')
        output = testsub.stdout.read().strip()
        self.assertEqual(output, "Passed All Tests")
        testsub.terminate()



