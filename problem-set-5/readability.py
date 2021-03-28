import re
text = input("Text: ")
sentence = 0
letters = 0
words = 1
for n in text:
    if chr(33) == n or chr(46) == n or chr(63) == n:
        sentence += 1
for k in text:
    if ord(k.lower()) >= 97 and ord(k.lower()) <= 122:
        letters += 1
for l in text:
    if l.isspace():
        words += 1
L = (letters * 100) / words
S = (sentence * 100) / words

# index = 0.0588 * L - 0.296 * S - 15.8
index = round(0.0588 * L - 0.296 * S - 15.8)
if index >= 16:
    print('Grade: 16+')
elif index < 1:
    print('Before Grade 1')
else:
    print(f'Grade: {index}')
