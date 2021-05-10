def check_fails_valid(fail_times, month):
    if fail_times >= month or fail_times < 0:
        return False
    return True


def check_input(inputs):
    for i in inputs:
        try:
            if int(i) - float(i) != 0:
                return False
        except ValueError:
            return False
        except TypeError:
            return False

    return True


def get_charge(fail_times, phone_call_time, month):
    inputs = [fail_times, phone_call_time, month]
    for i in inputs:
        try:
            if int(i) - float(i) != 0:
                return "invalid input"
        except ValueError:
            return "invalid input"
        except TypeError:
            return "invalid input"

    fail_times = int(fail_times)
    phone_call_time = int(phone_call_time)
    month = int(month)
    # if not check_input([fail_times, phone_call_time, month]):
    #     return "invalid input"
    if month < 1 or month > 12:
        return "invalid month"
    if not phone_call_time > 0:
        return "invalid time"
    if not check_fails_valid(fail_times, month):
        return "invalid fails"

    if phone_call_time <= 60:
        max_fail = 1
        discount = 0.01
    elif phone_call_time <= 120:
        max_fail = 2
        discount = 0.015
    elif phone_call_time <= 180:
        max_fail = 3
        discount = 0.02
    elif phone_call_time <= 300:
        max_fail = 3
        discount = 0.025
    else:
        max_fail = 6
        discount = 0.03

    if fail_times <= max_fail:
        fee = 25 + (1 - discount) * phone_call_time * 0.15
    else:
        fee = 25 + phone_call_time * 0.15

    return str(fee)
