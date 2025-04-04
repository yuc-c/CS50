# 作業4 Readability

from cs50 import get_string

text = get_string("Text: ")

letter = 0
word = 1
sentences = 0

for char in text:
    if char.isalpha():
        letter += 1
    elif char == " ":
        word += 1
    elif char in [".", "!", "?"]:
        sentences += 1

L = (letter / word) * 100
S = (sentences / word) * 100
index = 0.0588 * L - 0.296 * S - 15.8

grade = round(index)
if grade >= 16:
    print("Grade 16+")
elif grade < 1:
    print("Before Grade 1")
else:
    print(f"Grade {grade}")
