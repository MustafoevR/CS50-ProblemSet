import re
from cs50 import get_int
from sys import exit
# American Express uses 15-digit numbers || start with 34 or 37
# MasterCard uses 16-digit numbers || start with 51, 52, 53, 54, or 55
# and Visa uses 13- and 16-digit numbers || start with 4
#       Luhn's Algorithm
# 1. Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
# 2. Add the sum to the sum of the digits that weren’t multiplied by 2.
# 3. If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!

while True:
    credit = get_int("Number: ")
    if credit > 0:
        break
pos = 0
total_sum = 0
credit_cpy = credit
credit_str = str(credit)
while credit_cpy != 0:
    if pos % 2 != 0:
        temp = 2 * (credit_cpy % 10)
        if temp >= 10:
            total_sum += temp // 10 + temp % 10
        else:
            total_sum += temp
    else:
        total_sum += credit_cpy % 10
    credit_cpy = credit_cpy // 10
    pos += 1
if total_sum % 10 == 0:
    if len(credit_str) == 15 and re.match(r'34 | 37', credit_str):
        print('AMEX')
        exit(0)
    if len(credit_str) == 16 and re.match(r'51 | 52 | 53 | 54 | 55', credit_str):
        print('MASTERCARD')
        exit(0)
    if len(credit_str) == 13 or len(credit_str) == 16 and re.match(r'\b\w.', credit_str) == 4:
        print('VISA')
        exit(0)
    print('INVALID')
    exit(1)
else:
    print('INVALID')
