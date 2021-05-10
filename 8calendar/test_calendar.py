import unittest
from calend import getDayOfWeek
import pandas as pd
import numpy as np
from myddt import ddt, data

csv_cases = pd.read_csv("calendarTestCases.csv", encoding="gbk", dtype={"input": str})
csv_cases = np.array(csv_cases).tolist()

test_cases = []
for case in csv_cases:
    dic = {"input": case[0], "answer": case[1], "descriptor": case[2]}
    test_cases.append(dic)


@ddt()
class TestCalendar(unittest.TestCase):
    """Test calend.py"""

    def setUp(self):
        print("do something before test.Prepare environment.")

    def tearDown(self):
        print("do something after test.Clean up.")

    @data(*test_cases)
    def test_getDayOfWeek(self, test_case):
        print("testing calendar")
        self.assertEqual(test_case["answer"], getDayOfWeek(test_case["input"]))


if __name__ == '__main__':
    unittest.main()
