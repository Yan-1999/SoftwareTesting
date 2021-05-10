import unittest
from phone_charge import get_charge
import pandas as pd
import numpy as np
from myddt import ddt, data

csv_cases = pd.read_csv("phoneChargeCases.csv", encoding="gbk")
csv_cases = np.array(csv_cases).tolist()

test_cases = []
for case in csv_cases:
    dic = {"input": (case[0], case[1], case[2]), "answer": case[3], "descriptor": case[4]}
    test_cases.append(dic)


@ddt()
class TestPhoneCharge(unittest.TestCase):
    """Test phone_charge.py"""

    def setUp(self):
        print("do something before test.Prepare environment.")

    def tearDown(self):
        print("do something after test.Clean up.")

    @data(*test_cases)
    def test_getDayOfWeek(self, test_case):
        print("testing phone charge")
        input1, input2, input3 = test_case["input"]
        if len(test_case["answer"])<10:
            self.assertEqual(float(test_case["answer"]), get_charge(input1, input2, input3))
        else:
            self.assertEqual(test_case["answer"], get_charge(input1, input2, input3))
