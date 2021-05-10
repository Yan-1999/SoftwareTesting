# -*- coding: utf-8 -*-

import unittest
from test_calendar import TestCalendar
from BeautifulReport import BeautifulReport

if __name__ == '__main__':

    suite = unittest.TestSuite()
    load = unittest.TestLoader()
    suite.addTest(load.loadTestsFromTestCase(TestCalendar))

    runner = BeautifulReport(suite)

    runner.report(
        description="万年历问题，已知某年某月某日，生成当日是星期几",
        filename="BeautifulReport"  # 生成测试报告的文件名
    )
