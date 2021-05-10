# -*- coding: utf-8 -*-

import unittest
# from test_phone_charge import TestPhoneCharge
from test_calendar import TestCalendar
from BeautifulReport import BeautifulReport

if __name__ == '__main__':

    suite = unittest.TestSuite()
    load = unittest.TestLoader()
    suite.addTest(load.loadTestsFromTestCase(TestCalendar))

    runner = BeautifulReport(suite)

    runner.report(
        description="万年历，输入年月日得到星期几",
        filename=" CalendarTestReport"  # 生成测试报告的文件名
    )
