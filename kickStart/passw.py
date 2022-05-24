import random
import array

MIN_LEN = 7

DIGITS = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
LOCASE_CHARACTERS = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
                     'i', 'j', 'k', 'm', 'n', 'o', 'p', 'q',
                     'r', 's', 't', 'u', 'v', 'w', 'x', 'y',
                     'z']

UPCASE_CHARACTERS = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                     'I', 'J', 'K', 'M', 'N', 'O', 'P', 'Q',
                     'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y',
                     'Z']

SYMBOLS = ['@', '#', '*', '&']
COMBINED_LIST = DIGITS + UPCASE_CHARACTERS + LOCASE_CHARACTERS + SYMBOLS
rand_digit = random.choice(DIGITS)
rand_upper = random.choice(UPCASE_CHARACTERS)
rand_lower = random.choice(LOCASE_CHARACTERS)
rand_symbol = random.choice(SYMBOLS)
temp_pass = rand_digit + rand_upper + rand_lower + rand_symbol
try:
    t = int(input())
    o = 1
    while t > 0:
        length = int(input())
        password = str(input())
        l = 0
        d = 0
        u = 0
        s = 0

        for z in password:
            if z in DIGITS:
                d += 1
            if z in LOCASE_CHARACTERS:
                l += 1
            if z in UPCASE_CHARACTERS:
                u += 1
            if z in SYMBOLS:
                s += 1
        if(not l):
            password += random.choice(LOCASE_CHARACTERS)
        if(not d):
            password += (random.choice(DIGITS))
        if(not u):
            password += (random.choice(UPCASE_CHARACTERS))
        if(not s):
            password += random.choice(SYMBOLS)
        b = MIN_LEN-int(length)
        temp_pass_list = []
        for x in range(l):
            temp_pass = temp_pass + random.choice(COMBINED_LIST)
            temp_pass_list = array.array('u', temp_pass)
            random.shuffle(temp_pass_list)
        for x in temp_pass_list:
            password = password + x

        # print out password
        print(f"Case #{o}: {password}")
        o += 1
except:
    pass
