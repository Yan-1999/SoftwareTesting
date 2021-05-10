# 平瑞年
def leap_year(year):
    if year % 4 == 0 and year % 100 != 0 or year % 400 == 0:
        return True
    else:
        return False


# 月份的天数
def getMonthDays(year, month):
    days = 31
    if month == 2:  # 确定2月天数
        if leap_year(year):
            days = 29
        else:
            days = 28
    elif month == 4 or month == 6 or month == 9 or month == 11:  # 4 6 9 11这些月份均为30天
        days = 30
    return days


# 星期
def getTotalDays(start_year, year, month):
    totalDays = 0
    for i in range(start_year, year):  # 计算从第一年到查询年份的前一年的总天数
        if leap_year(i):
            totalDays += 366
        else:
            totalDays += 365
    for i in range(1, month):  # 再计算查询年份从一月到查询月份的前一个月的天数相加，得到总天数
        totalDays += getMonthDays(year, i)

    return totalDays


def date_check(year, month, day):
    if year < 1900 or year > 2050:
        return False
    elif month < 1 or month > 12:
        return False
    else:
        max_days = getMonthDays(year, month)
        if day < 1 or day > max_days:
            return False
        return True


def getDayOfWeek(input_date, start_year=1900):
    try:
        if len(input_date) != 8:
            return "bad input format"
        year = int(input_date[:4])
        month = int(input_date[4:6])
        day = int(input_date[6:])
    except ValueError:
        return "bad input format"
    else:
        # print(year, month, day)
        if not date_check(year, month, day):
            return "bad date"

    pre_total_days = getTotalDays(start_year, year, month) + day
    dayOfWeek = pre_total_days % 7
    weekDays = ["sun", "mon", "tue", "wed", "thu", "fri", "sat"]

    return weekDays[dayOfWeek]
