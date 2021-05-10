# -*- coding: utf-8 -*-

import unittest
from test_phone_charge import TestPhoneCharge
from BeautifulReport import BeautifulReport

if __name__ == '__main__':

    suite = unittest.TestSuite()
    load = unittest.TestLoader()
    suite.addTest(load.loadTestsFromTestCase(TestPhoneCharge))

    runner = BeautifulReport(suite)

    runner.report(
        description="电信收费系统测试",
        filename="testReport"  # 生成测试报告的文件名
    )
