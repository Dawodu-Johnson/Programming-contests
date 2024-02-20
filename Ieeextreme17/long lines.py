# a simple parser for python. use get_number() and get_word() to read
def parser():
    while 1:
        data = list(input().split(' '))
        for number in data:
            if len(number) > 0:
                yield (number)


input_parser = parser()


def get_word():
    global input_parser
    return next(input_parser)


def get_number():
    data = get_word()
    try:
        return int(data)
    except ValueError:
        return float(data)


# numpy and scipy are available for use
import numpy
import scipy

n = get_number()
h = get_number()
a = get_number()
c = get_number()
q = get_number()
result = 0
stack = [h]
for i in range(1, n):
    nh = (a * h + c) % q
    h = nh
    result += len(stack)
    while stack and nh >= stack[-1]:
        stack.pop()
    stack.append(nh)

print(result)
